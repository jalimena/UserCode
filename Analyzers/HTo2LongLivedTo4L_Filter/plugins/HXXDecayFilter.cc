// -*- C++ -*-
//
// Package:    TriggerStudies/HXXDecayFilter
// Class:      HXXDecayFilter
// 
/**\class HXXDecayFilter HXXDecayFilter.cc TriggerStudies/HXXDecayFilter/plugins/HXXDecayFilter.cc

Description: Filter to select various HXX decay types from generator information.

Implementation:
Uses the information in GenParticles to select the different X values, and then sees if they decay
to the desired particles.
*/
//
// Original Author:  Paul Lujan
//         Created:  Fri, 20 Jun 2014 15:05:12 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "FWCore/Utilities/interface/Exception.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"

//
// constants, enums and typedefs
//

enum DecayMode {decay_any, decay_ll, decay_ee, decay_mumu, decay_qq, decay_bb};
enum LifetimeMode {life_any, life_0p1, life_nominal, life_10};

//
// class declaration
//

class HXXDecayFilter : public edm::EDFilter {
public:
  explicit HXXDecayFilter(const edm::ParameterSet&);
  ~HXXDecayFilter();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  
private:
  virtual void beginJob() override;
  virtual bool filter(edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;
  
  //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;

  // ----------member data ---------------------------

  edm::InputTag genParticlesTag_;

  // Decay selectors.
  std::string decayModeName_;
  std::string lifetimeName_;
  int numRequired_;
  bool acceptMore_;
  DecayMode targetDecay_;
  LifetimeMode targetLifetime_;

};

//
// static data member definitions
//

//
// constructors and destructor
//
HXXDecayFilter::HXXDecayFilter(const edm::ParameterSet& iConfig):
  genParticlesTag_( iConfig.getUntrackedParameter<edm::InputTag>("genParticlesTag")),
  decayModeName_( iConfig.getUntrackedParameter<std::string>("decayMode")),
  lifetimeName_( iConfig.getUntrackedParameter<std::string>("lifetime")),
  numRequired_( iConfig.getUntrackedParameter<int>("numRequired")),
  acceptMore_( iConfig.getUntrackedParameter<bool>("acceptMore"))
{
  if (lifetimeName_ == "any" || decayModeName_ == "Any")
    targetLifetime_ = life_any;
  else if (lifetimeName_ == "0.1")
    targetLifetime_ = life_0p1;
  else if (lifetimeName_ == "1" || lifetimeName_ == "nominal" || lifetimeName_ == "Nominal")
    targetLifetime_ = life_nominal;
  else if (lifetimeName_ == "10")
    targetLifetime_ = life_10;
  else
    throw cms::Exception("HXXDecayFilter", 
			 "Unrecognized value for lifetime: allowed values are any, 0.1, 1 aka nominal, or 10");

  if (decayModeName_ == "any" || decayModeName_ == "Any")
    targetDecay_ = decay_any;
  else if (decayModeName_ == "ll")
    targetDecay_ = decay_ll;
  else if (decayModeName_ == "ee")
    targetDecay_ = decay_ee;
  else if (decayModeName_ == "mumu" || decayModeName_ == "mm")
    targetDecay_ = decay_mumu;
  else if (decayModeName_ == "qq")
    targetDecay_ = decay_qq;
  else if (decayModeName_ == "bb")
    targetDecay_ = decay_bb;
  else
    throw cms::Exception("HXXDecayFilter", 
			 "Unrecognized value for lifetime: allowed values are any, ll, ee, mumu, qq, or bb");

}


HXXDecayFilter::~HXXDecayFilter()
{
 
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called on each new Event  ------------
bool
HXXDecayFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  edm::Handle<reco::GenParticleCollection> genParticles;

  iEvent.getByLabel(genParticlesTag_, genParticles);

  int nXFound = 0;
  int nXPass = 0;
  
  for (unsigned int i=0; i<genParticles->size() && false; i++) {
    reco::GenParticleRef part(genParticles, i);
    
    std::cout << i << " " <<  part->pdgId() << " " << part->status() << " " << part->pt() << " // " <<
      part->numberOfDaughters() << "dau: ";
    for (unsigned int idau=0; idau<part->numberOfDaughters(); idau++) {
      std::cout << (part->daughterRef(idau))->pdgId() << " ";
    }
    if (part->numberOfMothers() > 0)
      std::cout << (part->numberOfMothers())  <<"mothers, first mother: " << part->motherRef(0)->pdgId() << std::endl;
    else 
      std::cout << std::endl;
  } // particle loop

  for (unsigned int i=0; i<genParticles->size(); i++) {
    reco::GenParticleRef part(genParticles, i);
    
    int id = abs(part->pdgId());
    
    // The Xs appear twice in the Pythia record: the first has the leptons (or other decay products) and
    // another copy of the X as daughters, while the second has the first X as a mother and no decay
    // products of its own. Skip this second one.
    if (part->numberOfMothers() > 0 && part->motherRef(0)->pdgId() == part->pdgId())
      continue;

    LifetimeMode thisLifetime;

    // look to see if it's an X
    // the X particle IDs are 600x11y, where x is the lifetime (1=0.1, 2=nominal, 3=10)
    // and y is the decay mode (1=uds, 2=b, 3=emu, 4=udscb)
    // also support old 2011 samples where there is no lifetime variance, so x=0 for those

    if (id == 6001111 || id == 6001112 || id == 6001113 || id == 6001114) {
      thisLifetime = life_0p1;
    } else if (id == 6002111 || id == 6002112 || id == 6002113 || id == 6002114 ||
	       id == 6000111 || id == 6000112 || id == 6000113) {
      thisLifetime = life_nominal;
    } else if (id == 6003111 || id == 6003112 || id == 6003113 || id == 6003114) {
      thisLifetime = life_10;
    } else {
      // not an X that we know about
      continue;
    }

    nXFound++;
    int whichType = (id % 10);

    bool passLifetime = false;
    if (targetLifetime_ == life_any || targetLifetime_ == thisLifetime)
      passLifetime = true;

    bool passDecay = false;
    if (targetDecay_ == decay_any)
      passDecay = true;
    // don't bother distinguishing between 600x111 and 600x114 -- there aren't any samples
    // which have both of these anyway so the ambiguity doesn't matter
    else if (targetDecay_ == decay_qq && (whichType == 1 || whichType == 4))
      passDecay = true;
    else if (targetDecay_ == decay_bb && whichType == 2)
      passDecay = true;
    else if (targetDecay_ == decay_ll && whichType == 3)
      passDecay = true;
    else if ((targetDecay_ == decay_ee || targetDecay_ == decay_mumu) && whichType == 3) {
      // This is the tricky part; we need to look at the actual decay products of the 
      // X to figure out if it's ee or mumu

      int nele = 0;
      int nmu = 0;
      for (unsigned int j=0; j<part->numberOfDaughters(); j++) {
	reco::GenParticleRef dau = part->daughterRef(j);
	int pdgIdDau = dau->pdgId();
	
	if (abs(pdgIdDau) == 11) {
	  nele++;
	}
	else if (abs(pdgIdDau) == 13) {
	  nmu++;
	}
      } // daughter loop
      
      if (!((nele == 2 && nmu ==0) || (nele == 0 && nmu == 2))) {
	edm::LogWarning("BadXDecay") << "Unexpected X->ll decay: found " << nele << " electrons and " << nmu
				     << " muons";
      }

      if (targetDecay_ == decay_ee && nele == 2)
	passDecay = true;
      if (targetDecay_ == decay_mumu && nmu == 2)
	passDecay = true;
    }

    // whew, now see if the X overall passes
    if (passLifetime && passDecay) {
      nXPass++;
      edm::LogInfo("XResult") << "Found X with id " << id << "; passed";
    } else {
      edm::LogInfo("XResult") << "Found X with id " << id << "; failed";
    }
  } // loop over genparticle bank

  // Now to see the final result.

  if (nXPass == numRequired_ || (nXPass > numRequired_ && acceptMore_)) {
    edm::LogInfo("FilterResult") << "Found " << nXPass << " passing X, event accepted";
    return true;
  } else {
    edm::LogInfo("FilterResult") << "Found " << nXPass << " passing X, event rejected";
    return false;
  }

}

// ------------ method called once each job just before starting event loop  ------------
void 
HXXDecayFilter::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
HXXDecayFilter::endJob() {
}

// ------------ method called when starting to processes a run  ------------
/*
  void
  HXXDecayFilter::beginRun(edm::Run const&, edm::EventSetup const&)
  { 
  }
*/
 
// ------------ method called when ending the processing of a run  ------------
/*
  void
  HXXDecayFilter::endRun(edm::Run const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when starting to processes a luminosity block  ------------
/*
  void
  HXXDecayFilter::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method called when ending the processing of a luminosity block  ------------
/*
  void
  HXXDecayFilter::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
  {
  }
*/
 
// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
HXXDecayFilter::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.addUntracked<edm::InputTag>("genParticlesTag", edm::InputTag("genParticles"));
  desc.addUntracked<std::string>("decayMode", "any");
  desc.addUntracked<std::string>("lifetime", "any");
  desc.addUntracked<int>("numRequired", 0);
  desc.addUntracked<bool>("acceptMore", true);
  descriptions.add("HXXDecayFilter", desc);
}
//define this as a plug-in
DEFINE_FWK_MODULE(HXXDecayFilter);
