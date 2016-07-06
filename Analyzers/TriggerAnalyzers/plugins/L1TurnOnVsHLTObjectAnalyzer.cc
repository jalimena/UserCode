// -*- C++ -*-
//
// Package:    TriggerAnalyzer/L1TurnOnVsHLTObjectAnalyzer
// Class:      L1TurnOnVsHLTObjectAnalyzer
// 
/**\class L1TurnOnVsHLTObjectAnalyzer L1TurnOnVsHLTObjectAnalyzer.cc TriggerAnalyzer/L1TurnOnVsHLTObjectAnalyzer/plugins/L1TurnOnVsHLTObjectAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Juliette Alimena
//         Created:  Tues, 28 June, 2016
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
#include "TMath.h"
#include "TClass.h"
#include "TFile.h"
#include "TF1.h"
#include "TGraphAsymmErrors.h"
#include "TROOT.h"

// HLT
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"

//tracks
#include "DataFormats/JetReco/interface/CaloJet.h"

//deltaR
#include "DataFormats/Math/interface/deltaR.h"

//
// class declaration
//

using namespace reco;

class L1TurnOnVsHLTObjectAnalyzer : public edm::EDAnalyzer {
public:
  explicit L1TurnOnVsHLTObjectAnalyzer(const edm::ParameterSet&);
  ~L1TurnOnVsHLTObjectAnalyzer();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  
  struct caloJet_et : public std::binary_function<reco::CaloJet, reco::CaloJet, bool> {
    bool operator()(const reco::CaloJet& x, const reco::CaloJet& y) {
      return ( x.et() > y.et() ) ;
    }
  };
  
private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void hltCaloJets(const edm::Event&, double&, double&, double&, double&, int&);
  virtual void triggerObjects(double&, double&, double&, double&, const trigger::Keys&,  const trigger::TriggerObjectCollection&, double&, double&);
  virtual void endJob() ;
  
  //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  
  // ----------member data ---------------------------
  edm::Service<TFileService> fileService;
  std::map< std::string, TH1D* > histos1D_;
  
  HLTConfigProvider hltConfig;
  //int triggerBit_Mu40;

  edm::InputTag hltResultsTag_;
  edm::EDGetTokenT<edm::TriggerResults> hltResultsToken_;
  edm::InputTag hltEventTag_;
  edm::EDGetTokenT<trigger::TriggerEvent> hltEventToken_;
  edm::InputTag hltCaloJetsTag_;
  edm::EDGetTokenT<reco::CaloJetCollection> hltCaloJetsToken_;
  edm::InputTag hltFilterTag_L1SingleJetC36NotBptxOR3BX_;
  edm::InputTag hltFilterTag_L1SingleJetC20NotBptxOR3BX_;
  //edm::InputTag hltFilterTag_L3Mu40_;
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
L1TurnOnVsHLTObjectAnalyzer::L1TurnOnVsHLTObjectAnalyzer(const edm::ParameterSet& iConfig):
  hltResultsTag_(iConfig.getUntrackedParameter<edm::InputTag>("hltResultsTag",edm::InputTag("TriggerResults","","HLT"))),
  hltResultsToken_(consumes<edm::TriggerResults>(hltResultsTag_)),
  hltEventTag_(iConfig.getUntrackedParameter<edm::InputTag>("hltEventTag",edm::InputTag("hltTriggerSummaryAOD","","HLT"))),
  hltEventToken_(consumes<trigger::TriggerEvent>(hltEventTag_)),
  hltCaloJetsTag_(iConfig.getUntrackedParameter<edm::InputTag>("hltCaloJetsTag",edm::InputTag("hltStoppedHSCPIterativeCone4CaloJets"))),
  hltCaloJetsToken_(consumes<reco::CaloJetCollection>(hltCaloJetsTag_)),

  hltFilterTag_L1SingleJetC36NotBptxOR3BX_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L1SingleJetC36NotBptxOR3BX",edm::InputTag("hltL1sSingleJetC36NotBptxOR3BX","","HLT"))),
  hltFilterTag_L1SingleJetC20NotBptxOR3BX_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L1SingleJetC20NotBptxOR3BX",edm::InputTag("hltL1sSingleJetC20NotBptxOR3BX","","HLT")))

  //hltFilterTag_L3Mu40_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L3Mu40",edm::InputTag("hltL3fL1sMu16orMu25L1f0L2f16QL3Filtered40Q","","HLT")))
{
   //now do what ever initialization is needed
  std::cout<<"doing constructor"<<std::endl;
  std::cout<<"iConfig is: "<<iConfig<<std::endl;
}


L1TurnOnVsHLTObjectAnalyzer::~L1TurnOnVsHLTObjectAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
L1TurnOnVsHLTObjectAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;

   cout<<"starting analyze"<<endl;

   //get trigger results
   edm::Handle<edm::TriggerResults> triggerResults;
   iEvent.getByLabel(hltResultsTag_, triggerResults);
   
   edm::Handle<trigger::TriggerEvent> trgEvent;
   iEvent.getByLabel(hltEventTag_, trgEvent);

   /*
   //find trigger names from hltConfigProvider
   bool changedConfig = false;
   if (!hltConfig.init(iEvent.getRun(), iSetup, "TEST", changedConfig)) {
     cout << "Initialization of HLTConfigProvider failed!!" << endl;
     return;
   }
   if (changedConfig){
     cout << "the curent menu is " << hltConfig.tableName() << endl;
     triggerBit_Mu40 = -1;
     
     for (size_t j = 0; j < hltConfig.triggerNames().size(); j++) {
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_Mu40")) triggerBit_Mu40 = j;
     }
     if (triggerBit_Mu40 == -1) cout << "HLT path Mu40 not found" << endl;
   }

   cout<<"triggerBit_Mu40 is: "<<triggerBit_Mu40<<endl;
   */
   //find last run trigger filters and if accepted by the trigger bit, fill histos
   if (trgEvent.isValid()) {
     cout<<"trgEvent is valid"<<endl;

     const trigger::TriggerObjectCollection& TOC(trgEvent->getObjects());

     const unsigned int filterIndexL1SingleJetC36NotBptxOR3BX (trgEvent->filterIndex(hltFilterTag_L1SingleJetC36NotBptxOR3BX_) );
     const unsigned int filterIndexL1SingleJetC20NotBptxOR3BX (trgEvent->filterIndex(hltFilterTag_L1SingleJetC20NotBptxOR3BX_) );

     //const unsigned int filterIndexL3Mu40 (trgEvent->filterIndex(hltFilterTag_L3Mu40_) );

     cout<<"trgEvent->sizeFilters is: "<<trgEvent->sizeFilters()<<endl;
     cout<<"filterIndexL1SingleJetC36NotBptxOR3BX is: "<<filterIndexL1SingleJetC36NotBptxOR3BX<<endl;
     //cout<<"filterIndexL3Mu40 is: "<<filterIndexL3Mu40<<endl;
     
     //pass L1 filters?
     if (filterIndexL1SingleJetC20NotBptxOR3BX < trgEvent->sizeFilters()) {
       const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL1SingleJetC20NotBptxOR3BX) );
       cout << "Found " << keys.size() << " L1 jets from L1SingleJetC20NotBptxOR3BX" << endl;

       //find hltCaloJets, without trigger requirement
       double hltCaloJetEt0, hltCaloJetEta0, hltCaloJetPhi0, hltCaloJetLxy0;
       int nHltCaloJet;
       hltCaloJets(iEvent, hltCaloJetEt0, hltCaloJetEta0, hltCaloJetPhi0, hltCaloJetLxy0, nHltCaloJet);
 
       double E;
       double et;
       double eta;
       double phi;
       triggerObjects(E, et, eta, phi, keys, TOC, hltCaloJetEta0, hltCaloJetPhi0);	 

       if(E>20){
	 std::cout<<"trigger jet et is:"<<et<<", eta is:"<<eta<<", phi is:"<<phi<<std::endl;
	 std::cout<<"calo jet et is: "<<hltCaloJetEt0<<", eta is: "<<hltCaloJetEta0<<", phi is: "<<hltCaloJetPhi0<<std::endl;

	 //fill histos with leading trig obj info
	 histos1D_[ "nTriggerJets_L1SingleJetC20NotBptxOR3BX" ]->Fill(keys.size());
	 histos1D_[ "eTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->Fill(E);
	 histos1D_[ "etTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->Fill(et);
	 histos1D_[ "etaTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->Fill(eta);
	 histos1D_[ "phiTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->Fill(phi);
       
	 histos1D_[ "nHltCaloJets" ]->Fill(nHltCaloJet);
	 if(hltCaloJetEt0!=-1.){
	   histos1D_[ "etHltCaloJet" ]->Fill(hltCaloJetEt0);
	   histos1D_[ "etaHltCaloJet" ]->Fill(hltCaloJetEta0);
	   histos1D_[ "phiHltCaloJet" ]->Fill(hltCaloJetPhi0);
	   histos1D_[ "lxyHltCaloJet" ]->Fill(hltCaloJetLxy0);
	 }
       
	 if (filterIndexL1SingleJetC36NotBptxOR3BX < trgEvent->sizeFilters()) {
	   const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL1SingleJetC36NotBptxOR3BX) );
	   cout << "Found " << keys.size() << " L1 jets from L1SingleJetC36NotBptxOR3BX" << endl;
	   
	   triggerObjects(E, et, eta, phi, keys, TOC, hltCaloJetEta0, hltCaloJetPhi0);	 
	   
	   if(E>36){
	     std::cout<<"trigger jet et is:"<<et<<", eta is:"<<eta<<", phi is:"<<phi<<std::endl;
	     std::cout<<"calo jet et is: "<<hltCaloJetEt0<<", eta is: "<<hltCaloJetEta0<<", phi is: "<<hltCaloJetPhi0<<std::endl;

	     //fill histos with leading trig obj info
	     histos1D_[ "nTriggerJets_L1SingleJetC36NotBptxOR3BX" ]->Fill(keys.size());
	     histos1D_[ "eTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->Fill(E);
	     histos1D_[ "etTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->Fill(et);
	     histos1D_[ "etaTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->Fill(eta);
	     histos1D_[ "phiTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->Fill(phi);
	     
	     if(hltCaloJetEt0!=-1.){
	       histos1D_[ "etHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->Fill(hltCaloJetEt0);
	       histos1D_[ "etaHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->Fill(hltCaloJetEta0);
	       histos1D_[ "phiHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->Fill(hltCaloJetPhi0);
	       histos1D_[ "lxyHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->Fill(hltCaloJetLxy0);
	     }
	   }//end of if E>36
	   
	 }//end of index< sizeFilters
       }//end of if E>20
     }//end of if pass L1 20
     cout<<endl;	
       
       /*
       //pass HLT filters?
       if (triggerBit_Mu40 != -1 && triggerResults->accept(triggerBit_Mu40)) {
       cout<<"passed Mu40"<<endl;
       if (filterIndexL3Mu40 < trgEvent->sizeFilters()) {
       const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL3Mu40) );
       cout << "Found " << keys.size() << " HLT jets from L3Mu40" << endl;
       
       double et0, et1;
       double eta0, eta1;
       double phi0, phi1;
     triggerObjects(et0, eta0, phi0, et1, eta1, phi1, keys, TOC);	 
     
     //fill histos with leading trig obj info
     histos1D_[ "nTriggerJets_Mu40" ]->Fill(keys.size());
     histos1D_[ "etTriggerJet_Mu40" ]->Fill(et0);
     histos1D_[ "etaTriggerJet_Mu40" ]->Fill(eta0);
     histos1D_[ "phiTriggerJet_Mu40" ]->Fill(phi0);
     
     
     //find hltCaloJets, for events passing trigger
     double hltCaloJetEt0_t, hltCaloJetEta0_t, hltCaloJetPhi0_t, hltCaloJetLxy0_t;
     int nHltCaloJet_t;
     hltCaloJets(iEvent, hltCaloJetEt0_t, hltCaloJetEta0_t, hltCaloJetPhi0_t, hltCaloJetLxy0_t, nHltCaloJet_t);	 
     histos1D_[ "nHltCaloJets_Mu40" ]->Fill(nHltCaloJet_t);
     if(hltCaloJetEt0_t!=-1.){
     histos1D_[ "etHltCaloJet_Mu40" ]->Fill(hltCaloJetEt0_t);
     histos1D_[ "etaHltCaloJet_Mu40" ]->Fill(hltCaloJetEta0_t);
     histos1D_[ "phiHltCaloJet_Mu40" ]->Fill(hltCaloJetPhi0_t);
     histos1D_[ "lxyHltCaloJet_Mu40" ]->Fill(hltCaloJetLxy0_t);
     }	 	 
     
     }//end of index< sizeFilters
     cout<<endl;
     }//end of pass trigger
     */

   }//end of if trgEvent valid
}//end of analyze()



void L1TurnOnVsHLTObjectAnalyzer::hltCaloJets(const edm::Event& iEvent, double& hltCaloJetEt0, double& hltCaloJetEta0, double& hltCaloJetPhi0, double& hltCaloJetLxy0, int& nHltCaloJet){

   //find hltCaloJets
  using namespace std;

  edm::Handle<reco::CaloJetCollection> hltCaloJets;
  iEvent.getByLabel(hltCaloJetsTag_, hltCaloJets);
  
  hltCaloJetEt0 = -1.;
  hltCaloJetEta0 = -1.;
  hltCaloJetPhi0 = -1.;
  hltCaloJetLxy0 = -1.;
  nHltCaloJet = 0;
  
  if (hltCaloJets.isValid()) {
    std::cout<<"hltCaloJets is Valid"<<std::endl;
    std::vector<CaloJet> hltCaloJets_;
    hltCaloJets_.insert(hltCaloJets_.end(), hltCaloJets->begin(), hltCaloJets->end());
    std::sort(hltCaloJets_.begin(), hltCaloJets_.end(), caloJet_et());
        
    //for(size_t i=0; i<hltCaloJets_.size(); i++){
    //const reco::CaloJet & p = hltCaloJets_.at(i);
    for(reco::CaloJetCollection::const_iterator it = hltCaloJets_.begin(); it!=hltCaloJets_.end(); it++){
      nHltCaloJet++;
      if (it->et()> hltCaloJetEt0){
	hltCaloJetEt0 = it->et();
	hltCaloJetEta0 = it->eta();
	hltCaloJetPhi0 = it->phi();
	hltCaloJetLxy0 = it->vx()*it->vx()+it->vy()*it->vy();
	hltCaloJetLxy0 = sqrt(hltCaloJetLxy0);
      }//end if hltL2 jet et greater than saved highest hltL2 jet et
    }//end of loop over hltL2 particles
  }//end of if hltCaloJets is valid
}//end of hltCaloJets


void L1TurnOnVsHLTObjectAnalyzer::triggerObjects(double& E, double& et, double& eta, double& phi, const trigger::Keys& keys,  const trigger::TriggerObjectCollection& TOC, double& hltCaloJetEta0, double& hltCaloJetPhi0){
  E= -1.;
  et = -1.;
  eta = -1.;
  phi = -1.;

  for ( unsigned hlto = 0; hlto < keys.size(); hlto++) {
    trigger::size_type hltf = keys[hlto];
    const trigger::TriggerObject& obj(TOC[hltf]);
    double dR=deltaR(hltCaloJetEta0,hltCaloJetPhi0,obj.eta(),obj.phi());
    
    if (dR < 0.2){
      std::cout<<"dR < 0.5"<<std::endl;
      E = obj.energy();
      et = obj.et();
      eta = obj.eta();
      phi = obj.phi();
    }//end of if obj.et> et
  }//end of loop over keys

}//end of triggerObjects



// ------------ method called once each job just before starting event loop  ------------
void 
L1TurnOnVsHLTObjectAnalyzer::beginJob()
{
  std::cout<<"beginJob!!!!"<<std::endl;

  histos1D_[ "nHltCaloJets" ] = fileService->make< TH1D >( "nHltCaloJets", "Number of HLT Calorimeter Jets", 10, 0., 10);
  histos1D_[ "nHltCaloJets" ]->SetXTitle( "Number of HLT Calorimeter Jets" );
  histos1D_[ "nHltCaloJets" ]->SetYTitle( "Events" );

  histos1D_[ "etHltCaloJet" ] = fileService->make< TH1D >( "etHltCaloJet", "HLT Calorimeter Jet et", 500, 0., 1000);
  histos1D_[ "etHltCaloJet" ]->SetXTitle( "HLT Calorimeter Jet E_{T} [GeV]" );
  histos1D_[ "etHltCaloJet" ]->SetYTitle( "Events" );

  histos1D_[ "etaHltCaloJet" ] = fileService->make< TH1D >( "etaHltCaloJet", "HLT Calorimeter Jet eta", 120,-6,6);
  histos1D_[ "etaHltCaloJet" ]->SetXTitle( "HLT Calorimeter Jet #eta" );
  histos1D_[ "etaHltCaloJet" ]->SetYTitle( "Events" );

  histos1D_[ "phiHltCaloJet" ] = fileService->make< TH1D >( "phiHltCaloJet", "HLT Calorimeter Jet phi", 64,-3.2,3.2);
  histos1D_[ "phiHltCaloJet" ]->SetXTitle( "HLT Calorimeter Jet #phi" );
  histos1D_[ "phiHltCaloJet" ]->SetYTitle( "Events" );

  histos1D_[ "lxyHltCaloJet" ] = fileService->make< TH1D >( "lxyHltCaloJet", "HLT Calorimeter Jet lxy", 500, 0, 1000);
  histos1D_[ "lxyHltCaloJet" ]->SetXTitle( "HLT Calorimeter Jet L_{xy}" );
  histos1D_[ "lxyHltCaloJet" ]->SetYTitle( "Events" );


  histos1D_[ "nTriggerJets_L1SingleJetC20NotBptxOR3BX" ] = fileService->make< TH1D >( "nTriggerJets_L1SingleJetC20NotBptxOR3BX", "Number of L1 jets", 10, 0., 10);
  histos1D_[ "nTriggerJets_L1SingleJetC20NotBptxOR3BX" ]->SetXTitle( "Number of L1 Jets" );
  histos1D_[ "nTriggerJets_L1SingleJetC20NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "eTriggerJet_L1SingleJetC20NotBptxOR3BX" ] = fileService->make< TH1D >( "eTriggerJet_L1SingleJetC20NotBptxOR3BX", "L1 Jet E", 500, 0., 500);
  histos1D_[ "eTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->SetXTitle( "L1 Jet E [GeV]" );
  histos1D_[ "eTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "etTriggerJet_L1SingleJetC20NotBptxOR3BX" ] = fileService->make< TH1D >( "etTriggerJet_L1SingleJetC20NotBptxOR3BX", "L1 Jet Et", 500, 0., 500);
  histos1D_[ "etTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->SetXTitle( "L1 Jet E_{T} [GeV]" );
  histos1D_[ "etTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "etaTriggerJet_L1SingleJetC20NotBptxOR3BX" ] = fileService->make< TH1D >( "etaTriggerJet_L1SingleJetC20NotBptxOR3BX", "L1 Jet eta", 120,-6,6);
  histos1D_[ "etaTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->SetXTitle( "L1 Jet #eta" );
  histos1D_[ "etaTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "phiTriggerJet_L1SingleJetC20NotBptxOR3BX" ] = fileService->make< TH1D >( "phiTriggerJet_L1SingleJetC20NotBptxOR3BX", "L1 Jet phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->SetXTitle( "L1 Jet #phi" );
  histos1D_[ "phiTriggerJet_L1SingleJetC20NotBptxOR3BX" ]->SetYTitle( "Events" );



  histos1D_[ "nTriggerJets_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "nTriggerJets_L1SingleJetC36NotBptxOR3BX", "Number of L1 jets", 10, 0., 10);
  histos1D_[ "nTriggerJets_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "Number of L1 Jets" );
  histos1D_[ "nTriggerJets_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "eTriggerJet_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "eTriggerJet_L1SingleJetC36NotBptxOR3BX", "L1 Jet E", 500, 0., 500);
  histos1D_[ "eTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "L1 Jet E [GeV]" );
  histos1D_[ "eTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "etTriggerJet_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "etTriggerJet_L1SingleJetC36NotBptxOR3BX", "L1 Jet Et", 500, 0., 500);
  histos1D_[ "etTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "L1 Jet E_{T} [GeV]" );
  histos1D_[ "etTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "etaTriggerJet_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "etaTriggerJet_L1SingleJetC36NotBptxOR3BX", "L1 Jet eta", 120,-6,6);
  histos1D_[ "etaTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "L1 Jet #eta" );
  histos1D_[ "etaTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "phiTriggerJet_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "phiTriggerJet_L1SingleJetC36NotBptxOR3BX", "L1 Jet phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "L1 Jet #phi" );
  histos1D_[ "phiTriggerJet_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "nHltCaloJets_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "nHltCaloJets_L1SingleJetC36NotBptxOR3BX", "Number of HLT Calorimeter Jets", 10, 0., 10);
  histos1D_[ "nHltCaloJets_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "Number of HLT Calorimeter Jets" );
  histos1D_[ "nHltCaloJets_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "etHltCaloJet_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "etHltCaloJet_L1SingleJetC36NotBptxOR3BX", "HLT Calorimeter Jet et", 500, 0., 1000);
  histos1D_[ "etHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "HLT Calorimeter Jet E_{T} [GeV]" );
  histos1D_[ "etHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "etaHltCaloJet_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "etaHltCaloJet_L1SingleJetC36NotBptxOR3BX", "HLT Calorimeter Jet eta", 120,-6,6);
  histos1D_[ "etaHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "HLT Calorimeter Jet #eta" );
  histos1D_[ "etaHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "phiHltCaloJet_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "phiHltCaloJet_L1SingleJetC36NotBptxOR3BX", "HLT Calorimeter Jet phi", 64,-3.2,3.2);
  histos1D_[ "phiHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "HLT Calorimeter Jet #phi" );
  histos1D_[ "phiHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );

  histos1D_[ "lxyHltCaloJet_L1SingleJetC36NotBptxOR3BX" ] = fileService->make< TH1D >( "lxyHltCaloJet_L1SingleJetC36NotBptxOR3BX", "HLT Calorimeter Jet lxy", 500, 0, 1000);
  histos1D_[ "lxyHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->SetXTitle( "HLT Calorimeter Jet L_{xy}" );
  histos1D_[ "lxyHltCaloJet_L1SingleJetC36NotBptxOR3BX" ]->SetYTitle( "Events" );


  /*
  histos1D_[ "nTriggerJets_Mu40" ] = fileService->make< TH1D >( "nTriggerJets_Mu40", "Number of jets", 10, 0., 10);
  histos1D_[ "nTriggerJets_Mu40" ]->SetXTitle( "Number of HLT Jets" );
  histos1D_[ "nTriggerJets_Mu40" ]->SetYTitle( "Events" );

  histos1D_[ "etTriggerJet_Mu40" ] = fileService->make< TH1D >( "etTriggerJet_Mu40", "HLT Jet et", 100, 0., 1000);
  histos1D_[ "etTriggerJet_Mu40" ]->SetXTitle( "HLT Jet p_{T} [GeV]" );
  histos1D_[ "etTriggerJet_Mu40" ]->SetYTitle( "Events" );

  histos1D_[ "etaTriggerJet_Mu40" ] = fileService->make< TH1D >( "etaTriggerJet_Mu40", "HLT Jet eta", 120,-6,6);
  histos1D_[ "etaTriggerJet_Mu40" ]->SetXTitle( "HLT Jet #eta" );
  histos1D_[ "etaTriggerJet_Mu40" ]->SetYTitle( "Events" );

  histos1D_[ "phiTriggerJet_Mu40" ] = fileService->make< TH1D >( "phiTriggerJet_Mu40", "HLT Jet phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerJet_Mu40" ]->SetXTitle( "HLT Jet #phi" );
  histos1D_[ "phiTriggerJet_Mu40" ]->SetYTitle( "Events" );

  std::cout<<"beginJob1"<<std::endl;

  histos1D_[ "nHltCaloJets_Mu40" ] = fileService->make< TH1D >( "nHltCaloJets_Mu40", "Number of HLT Calorimeter Jets", 10, 0., 10);
  histos1D_[ "nHltCaloJets_Mu40" ]->SetXTitle( "Number of HLT Calorimeter Jets" );
  histos1D_[ "nHltCaloJets_Mu40" ]->SetYTitle( "Events" );

  std::cout<<"beginJob5"<<std::endl;

  histos1D_[ "etHltCaloJet_Mu40" ] = fileService->make< TH1D >( "etHltCaloJet_Mu40", "HLT Calorimeter Jet et", 100, 0., 1000);
  histos1D_[ "etHltCaloJet_Mu40" ]->SetXTitle( "HLT Calorimeter Jet p_{T} [GeV]" );
  histos1D_[ "etHltCaloJet_Mu40" ]->SetYTitle( "Events" );

  std::cout<<"beginJob6"<<std::endl;

  histos1D_[ "etaHltCaloJet_Mu40" ] = fileService->make< TH1D >( "etaHltCaloJet_Mu40", "HLT Calorimeter Jet eta", 120,-6,6);
  histos1D_[ "etaHltCaloJet_Mu40" ]->SetXTitle( "HLT Calorimeter Jet #eta" );
  histos1D_[ "etaHltCaloJet_Mu40" ]->SetYTitle( "Events" );

  std::cout<<"beginJob7"<<std::endl;

  histos1D_[ "phiHltCaloJet_Mu40" ] = fileService->make< TH1D >( "phiHltCaloJet_Mu40", "HLT Calorimeter Jet phi", 64,-3.2,3.2);
  histos1D_[ "phiHltCaloJet_Mu40" ]->SetXTitle( "HLT Calorimeter Jet #phi" );
  histos1D_[ "phiHltCaloJet_Mu40" ]->SetYTitle( "Events" );

  std::cout<<"beginJob8"<<std::endl;

  histos1D_[ "lxyHltCaloJet_Mu40" ] = fileService->make< TH1D >( "lxyHltCaloJet_Mu40", "HLT Calorimeter Jet lxy", 500, 0, 1000);
  histos1D_[ "lxyHltCaloJet_Mu40" ]->SetXTitle( "HLT Calorimeter Jet L_{xy}" );
  histos1D_[ "lxyHltCaloJet_Mu40" ]->SetYTitle( "Events" );
  */
  std::cout<<"ending beginJob!!!!"<<std::endl;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
L1TurnOnVsHLTObjectAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
L1TurnOnVsHLTObjectAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
L1TurnOnVsHLTObjectAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
L1TurnOnVsHLTObjectAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
L1TurnOnVsHLTObjectAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
L1TurnOnVsHLTObjectAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  std::cout<<"starting fillDescriptions"<<std::endl;
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
  std::cout<<"finishing fillDescriptions"<<std::endl;
}

//define this as a plug-in
DEFINE_FWK_MODULE(L1TurnOnVsHLTObjectAnalyzer);
