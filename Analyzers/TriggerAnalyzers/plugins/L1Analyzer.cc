// -*- C++ -*-
//
// Package:    TriggerAnalyzer/L1Analyzer
// Class:      L1Analyzer
// 
/**\class L1Analyzer L1Analyzer.cc TriggerAnalyzer/L1Analyzer/plugins/L1Analyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Juliette Alimena
//         Created:  Mon, 22 Sep 2014 14:19:56 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

// ROOT output stuff
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TH1.h"
#include "TTree.h"
#include "TClass.h"
#include "TFile.h"
#include "TF1.h"
#include "TROOT.h"

//L1
#include "CondFormats/L1TObjects/interface/L1GtTriggerMenu.h"
#include "CondFormats/DataRecord/interface/L1GtTriggerMenuRcd.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutSetupFwd.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutSetup.h"
#include "DataFormats/L1GlobalTrigger/interface/L1GlobalTriggerReadoutRecord.h"
#include "DataFormats/L1Trigger/interface/L1JetParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1JetParticle.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticleFwd.h"
#include "DataFormats/L1Trigger/interface/L1MuonParticle.h"
#include "L1Trigger/GlobalTriggerAnalyzer/interface/L1GtUtils.h"

//
// class declaration
//

class L1Analyzer : public edm::EDAnalyzer {
public:
  explicit L1Analyzer(const edm::ParameterSet&);
  ~L1Analyzer();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  
  struct l1muon_pt : public std::binary_function<l1extra::L1MuonParticle, l1extra::L1MuonParticle, bool> {
    bool operator()(const l1extra::L1MuonParticle& x, const l1extra::L1MuonParticle& y) {
      return ( x.pt() > y.pt() ) ;
    }
  };
  
private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  
  // ----------member data ---------------------------
  std::map< std::string, TH1D* > histos1D_;
  
  //std::string l1CollectionsTag_;
  edm::InputTag l1CollectionsTag_;
  //edm::EDGetTokenT<l1extra::L1MuonParticle> l1CollectionsToken_;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
L1Analyzer::L1Analyzer(const edm::ParameterSet& iConfig):
  //l1CollectionsTag_(iConfig.getUntrackedParameter< std::string > ("l1CollectionsTag",std::string("l1extraParticles"))),
  l1CollectionsTag_(iConfig.getUntrackedParameter< edm::InputTag > ("l1CollectionsTag",edm::InputTag("l1extraParticles","","L1TEMULATION")))
  //l1CollectionsToken_(consumes<l1extra::L1MuonParticle>(l1CollectionsTag_))

{
   //now do what ever initialization is needed
  std::cout<<"doing constructor"<<std::endl;
}


L1Analyzer::~L1Analyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
L1Analyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;

   cout<<"starting analyze"<<endl;

   // L1 muons
   edm::Handle<l1extra::L1MuonParticleCollection> l1Muons;
   //iEvent.getByLabel(l1CollectionsTag_, "", l1Muons);
   iEvent.getByLabel(l1CollectionsTag_, l1Muons);
   cout<<"got L1 collection"<<endl;

   if (l1Muons.isValid() ){
     cout<<"l1Muons is valid"<<endl;

     std::vector<l1extra::L1MuonParticle> l1muons;
     l1muons.insert(l1muons.end(), l1Muons->begin(), l1Muons->end());
     std::sort(l1muons.begin(), l1muons.end(), l1muon_pt());
     cout<<"sorted l1 muons by pt"<<endl;

     int count = 0;
     for (std::vector<l1extra::L1MuonParticle>::const_iterator muon=l1muons.begin(); muon!=l1muons.end(); ++muon) {

       //fill histos with leading trig obj info
       if(count==0){
	 histos1D_[ "ptMuon" ]->Fill(muon->pt());
	 histos1D_[ "etaMuon" ]->Fill(muon->eta());
	 histos1D_[ "phiMuon" ]->Fill(muon->phi());
       }
       count++;
     }
     histos1D_[ "nMuons" ]->Fill(count);

   }//end of if l1Muons valid
}//end of analyze()



// ------------ method called once each job just before starting event loop  ------------
void 
L1Analyzer::beginJob()
{
  std::cout<<"beginJob!!!!"<<std::endl;
  edm::Service<TFileService> fileService;

  histos1D_[ "nMuons" ] = fileService->make< TH1D >( "nMuons", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons" ]->SetXTitle( "Number of L1 Muons" );
  histos1D_[ "nMuons" ]->SetYTitle( "Events" );

  histos1D_[ "ptMuon" ] = fileService->make< TH1D >( "ptMuon", "L1 Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon" ]->SetXTitle( "L1 Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon" ]->SetYTitle( "Events" );

  histos1D_[ "etaMuon" ] = fileService->make< TH1D >( "etaMuon", "L1 Muon eta", 120,-6,6);
  histos1D_[ "etaMuon" ]->SetXTitle( "L1 Muon #eta" );
  histos1D_[ "etaMuon" ]->SetYTitle( "Events" );

  histos1D_[ "phiMuon" ] = fileService->make< TH1D >( "phiMuon", "L1 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon" ]->SetXTitle( "L1 Muon #phi" );
  histos1D_[ "phiMuon" ]->SetYTitle( "Events" );

  std::cout<<"ending beginJob!!!!"<<std::endl;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
L1Analyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
L1Analyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
L1Analyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
L1Analyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
L1Analyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
L1Analyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  std::cout<<"starting fillDescriptions"<<std::endl;
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
  std::cout<<"finishing fillDescriptions"<<std::endl;
}

//define this as a plug-in
DEFINE_FWK_MODULE(L1Analyzer);
