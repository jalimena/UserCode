// -*- C++ -*-
//
// Package:    TriggerAnalyzer/HLTMeanTimerAnalyzer
// Class:      HLTMeanTimerAnalyzer
// 
/**\class HLTMeanTimerAnalyzer HLTMeanTimerAnalyzer.cc TriggerAnalyzer/HLTMeanTimerAnalyzer/plugins/HLTMeanTimerAnalyzer.cc

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

// HLT
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"

//
// class declaration
//

class HLTMeanTimerAnalyzer : public edm::EDAnalyzer {
public:
  explicit HLTMeanTimerAnalyzer(const edm::ParameterSet&);
  ~HLTMeanTimerAnalyzer();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  
  
private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void triggerObjects(double&, double&, double&, const trigger::Keys&,  const trigger::TriggerObjectCollection&);
  virtual void endJob() ;
  
  //virtual void beginRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void endRun(edm::Run const&, edm::EventSetup const&) override;
  //virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  //virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&) override;
  
  // ----------member data ---------------------------
  std::map< std::string, TH1D* > histos1D_;

  HLTConfigProvider hltConfig;
  int triggerBit_Mu40;
  int triggerBit_IsoMu24_IterTrk02;
  int triggerBit_IsoTkMu24_IterTrk02;
  int triggerBit_Mu17_Mu8;
  int triggerBit_Mu17_TkMu8;
  int triggerBit_Mu30_TkMu11;
  int triggerBit_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
  int triggerBit_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL;
  int triggerBit_DoubleMu33NoFiltersNoVtx;
  int triggerBit_DoubleMu23NoFiltersNoVtxDisplaced;
  int triggerBit_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10;
  int triggerBit_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo;
  int triggerBit_Mu38NoFiltersNoVtx_Photon38_CaloIdL;
  int triggerBit_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL;

  edm::InputTag hltResultsTag_;
  //edm::EDGetTokenT<edm::TriggerResults> hltResultsToken_;
  edm::InputTag hltEventTag_;
  //edm::EDGetTokenT<trigger::TriggerEvent> hltEventToken_;
  edm::InputTag hltFilterTag_L3Mu40_;
  edm::InputTag hltFilterTag_L3Mu24Iso_;
  edm::InputTag hltFilterTag_L3TrkMu24Iso_;
  edm::InputTag hltFilterTag_DiMuonGlb17Glb8_;
  edm::InputTag hltFilterTag_DiMuonGlb17Trk8_;
  edm::InputTag hltFilterTag_DiMuonGlb30Trk11_;
  edm::InputTag hltFilterTag_DiMuonGlb17Glb8Iso_;
  edm::InputTag hltFilterTag_DiMuonGlb17Trk8Iso_;
  edm::InputTag hltFilterTag_DiMuonL3NoFilters33_;
  edm::InputTag hltFilterTag_DiMuonL3NoFilters23Displaced_;
  edm::InputTag hltFilterTag_L2DoubleMu28_;
  edm::InputTag hltFilterTag_L2MuNoBptx20_;
  edm::InputTag hltFilterTag_Mu38NoVtx_Photon38_;
  edm::InputTag hltFilterTag_Mu28NoVtxDisplaced_Photon28_;
  bool BarrelOnly_;

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
HLTMeanTimerAnalyzer::HLTMeanTimerAnalyzer(const edm::ParameterSet& iConfig):
  hltResultsTag_(iConfig.getUntrackedParameter<edm::InputTag>("hltResultsTag",edm::InputTag("TriggerResults","","HLT"))),
  //hltResultsToken_(consumes<edm::TriggerResults>(hltResultsTag_)),
  hltEventTag_(iConfig.getUntrackedParameter<edm::InputTag>("hltEventTag",edm::InputTag("hltTriggerSummaryAOD","","HLT"))),
  //hltEventToken_(consumes<trigger::TriggerEvent>(hltEventTag_)),

  hltFilterTag_L3Mu40_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L3Mu40",edm::InputTag("hltL3fL1sMu16orMu25L1f0L2f16QL3Filtered40Q","","HLT"))),
  hltFilterTag_L3Mu24Iso_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L3Mu24Iso",edm::InputTag("hltL3crIsoL1sMu16L1f0L2f16QL3f24QL3crIsoRhoFiltered0p15IterTrk02","","HLT"))),
  hltFilterTag_L3TrkMu24Iso_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L3TrkMu24Iso",edm::InputTag("hltL3fL1sMu16L1f0TkFiltered24QL3crIsoRhoFiltered0p15IterTrk02","","HLT"))),
  hltFilterTag_DiMuonGlb17Glb8_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_DiMuonGlb17Glb8",edm::InputTag("hltDiMuonGlb17Glb8DzFiltered0p2","","HLT"))),
  hltFilterTag_DiMuonGlb17Trk8_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_DiMuonGlb17Trk8",edm::InputTag("hltDiMuonGlb17Trk8DzFiltered0p2","","HLT"))),
  hltFilterTag_DiMuonGlb30Trk11_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_DiMuonGlb30Trk11",edm::InputTag("hltDiMuonGlb30Trk11DzFiltered0p2","","HLT"))),
  hltFilterTag_DiMuonGlb17Glb8Iso_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_DiMuonGlb17Glb8Iso",edm::InputTag("hltDiMuonGlb17Glb8DzFiltered0p2RelTrkIsoFiltered0p4","","HLT"))),
  hltFilterTag_DiMuonGlb17Trk8Iso_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_DiMuonGlb17Trk8Iso",edm::InputTag("hltDiMuonGlb17Trk8DzFiltered0p2RelTrkIsoFiltered0p4","","HLT"))),
  hltFilterTag_DiMuonL3NoFilters33_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_DiMuonL3NoFilters33",edm::InputTag("hltL3fDimuonL1f0L2NVf10L3NoFiltersNoVtxFiltered33","","HLT"))),
  hltFilterTag_DiMuonL3NoFilters23Displaced_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_DiMuonL3NoFilters23Displaced",edm::InputTag("hltL3fDimuonL1f0L2NVf10L3NoFiltersNoVtxDisplacedFiltered23","","HLT"))),
  hltFilterTag_L2DoubleMu28_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L2DoubleMu28",edm::InputTag("hltL2DoubleMu28NoVertexL2Filtered2ChaAngle2p5Mass10","","HLT"))),
  hltFilterTag_L2MuNoBptx20_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L2MuNoBptx20",edm::InputTag("hltL2fL1sMu6NotBptxORL1f0L2Filtered20Sta3","","HLT"))),
  hltFilterTag_Mu38NoVtx_Photon38_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_Mu38NoVtx_Photon38",edm::InputTag("hltMu38NoFiltersNoVtxPhoton38CaloIdLHEFilter","","HLT"))),
  hltFilterTag_Mu28NoVtxDisplaced_Photon28_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_Mu38NoVtx_Photon38",edm::InputTag("hltMu28NoFiltersNoVtxDisplacedPhoton28CaloIdLHEFilter","","HLT"))),

  BarrelOnly_(iConfig.getUntrackedParameter<bool>("BarrelOnly",bool("false")))

{
   //now do what ever initialization is needed
  std::cout<<"doing constructor"<<std::endl;
  std::cout<<"iConfig is: "<<iConfig<<std::endl;
}


HLTMeanTimerAnalyzer::~HLTMeanTimerAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
HLTMeanTimerAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;

   cout<<"starting analyze"<<endl;

   edm::Handle<edm::TriggerResults> triggerResults;
   iEvent.getByLabel(hltResultsTag_, triggerResults);

   edm::Handle<trigger::TriggerEvent> trgEvent;
   iEvent.getByLabel(hltEventTag_, trgEvent);

   //find trigger names from hltConfigProvider
   bool changedConfig = false;
   if (!hltConfig.init(iEvent.getRun(), iSetup, "TEST", changedConfig)) {
     cout << "Initialization of HLTConfigProvider failed!!" << endl;
     return;
   }
   if (changedConfig){
     cout << "the curent menu is " << hltConfig.tableName() << endl;
     triggerBit_Mu40 = -1;
     triggerBit_IsoMu24_IterTrk02 = -1;
     triggerBit_IsoTkMu24_IterTrk02 = -1;
     triggerBit_Mu17_Mu8 = -1;
     triggerBit_Mu17_TkMu8 = -1;
     triggerBit_Mu30_TkMu11 = -1;
     triggerBit_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = -1;
     triggerBit_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL = -1;
     triggerBit_DoubleMu33NoFiltersNoVtx = -1;
     triggerBit_DoubleMu23NoFiltersNoVtxDisplaced = -1;
     triggerBit_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 = -1;
     triggerBit_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo = -1;
     triggerBit_Mu38NoFiltersNoVtx_Photon38_CaloIdL = -1;
     triggerBit_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL = -1;

     
     for (size_t j = 0; j < hltConfig.triggerNames().size(); j++) {
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_Mu40")) triggerBit_Mu40 = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_IsoMu24_IterTrk02")) triggerBit_IsoMu24_IterTrk02 = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_IsoTkMu24_IterTrk02")) triggerBit_IsoTkMu24_IterTrk02 = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_Mu17_Mu8")) triggerBit_Mu17_Mu8 = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_Mu17_TkMu8")) triggerBit_Mu17_TkMu8 = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_Mu30_TkMu11")) triggerBit_Mu30_TkMu11 = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL")) triggerBit_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL")) triggerBit_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_DoubleMu33NoFiltersNoVtx")) triggerBit_DoubleMu33NoFiltersNoVtx = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_DoubleMu23NoFiltersNoVtxDisplaced")) triggerBit_DoubleMu23NoFiltersNoVtxDisplaced = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10")) triggerBit_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo")) triggerBit_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_Mu38NoFiltersNoVtx_Photon38_CaloIdL")) triggerBit_Mu38NoFiltersNoVtx_Photon38_CaloIdL = j;
       if (TString(hltConfig.triggerNames()[j]).Contains("HLT_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL")) triggerBit_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL = j;

     }
     if (triggerBit_Mu40 == -1) cout << "HLT path Mu40 not found" << endl;
     if (triggerBit_IsoMu24_IterTrk02 == -1) cout << "HLT path IsoMu24_IterTrk02 not found" << endl;
     if (triggerBit_IsoTkMu24_IterTrk02 == -1) cout << "HLT path IsoTkMu24_IterTrk02 not found" << endl;
     if (triggerBit_Mu17_Mu8 == -1) cout << "HLT path Mu17_Mu8 not found" << endl;
     if (triggerBit_Mu17_TkMu8 == -1) cout << "HLT path Mu17_TkMu8 not found" << endl;
     if (triggerBit_Mu30_TkMu11 == -1) cout << "HLT path Mu30_TkMu11 not found" << endl;
     if (triggerBit_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL == -1) cout << "HLT path Mu17_TrkIsoVVL_Mu8_TrkIsoVVL not found" << endl;
     if (triggerBit_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL == -1) cout << "HLT path Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL not found" << endl;
     if (triggerBit_DoubleMu33NoFiltersNoVtx == -1) cout << "HLT path DoubleMu33NoFiltersNoVtx not found" << endl;
     if (triggerBit_DoubleMu23NoFiltersNoVtxDisplaced == -1) cout << "HLT path DoubleMu23NoFiltersNoVtxDisplaced not found" << endl;
     if (triggerBit_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 == -1) cout << "HLT path L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 not found" << endl;
     if (triggerBit_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo == -1) cout << "HLT path L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo not found" << endl;
     if (triggerBit_Mu38NoFiltersNoVtx_Photon38_CaloIdL == -1) cout << "HLT path Mu38NoFiltersNoVtx_Photon38_CaloIdL not found" << endl;
     if (triggerBit_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL == -1) cout << "HLT path Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL not found" << endl;
   }

   cout<<"triggerBit_Mu40 is: "<<triggerBit_Mu40<<endl;
   cout<<"triggerBit_IsoMu24_IterTrk02 is: "<<triggerBit_IsoMu24_IterTrk02<<endl;
   cout<<"triggerBit_IsoTkMu24_IterTrk02 is: "<<triggerBit_IsoTkMu24_IterTrk02<<endl;
   cout<<"triggerBit_Mu17_Mu8 is: "<<triggerBit_Mu17_Mu8<<endl;
   cout<<"triggerBit_Mu18_TkMu8 is: "<<triggerBit_Mu17_TkMu8<<endl;
   cout<<"triggerBit_Mu30_TkMu11 is: "<<triggerBit_Mu30_TkMu11<<endl;
   cout<<"triggerBit_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL is: "<<triggerBit_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL<<endl;
   cout<<"triggerBit_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL is: "<<triggerBit_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL<<endl;
   cout<<"triggerBit_DoubleMu33NoFiltersNoVtx is: "<<triggerBit_DoubleMu33NoFiltersNoVtx<<endl;
   cout<<"triggerBit_DoubleMu23NoFiltersNoVtxDisplaced is: "<<triggerBit_DoubleMu23NoFiltersNoVtxDisplaced<<endl;
   cout<<"triggerBit_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 is: "<<triggerBit_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10<<endl<<endl;
   cout<<"triggerBit_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo is: "<<triggerBit_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo<<endl;
   cout<<"triggerBit_Mu38NoFiltersNoVtx_Photon38_CaloId is: "<<triggerBit_Mu38NoFiltersNoVtx_Photon38_CaloIdL<<endl;
   cout<<"triggerBit_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloId is: "<<triggerBit_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL<<endl;

   //find last run trigger filters and if accepted by the trigger bit, fill histos
   if (trgEvent.isValid()) {
     cout<<"trgEvent is valid"<<endl;

     const trigger::TriggerObjectCollection& TOC(trgEvent->getObjects());

     const unsigned int filterIndexL3Mu40 (trgEvent->filterIndex(hltFilterTag_L3Mu40_) );
     const unsigned int filterIndexL3Mu24Iso (trgEvent->filterIndex(hltFilterTag_L3Mu24Iso_) );
     const unsigned int filterIndexL3TrkMu24Iso (trgEvent->filterIndex(hltFilterTag_L3TrkMu24Iso_) );
     const unsigned int filterIndexDiMuonGlb17Glb8 (trgEvent->filterIndex(hltFilterTag_DiMuonGlb17Glb8_) );
     const unsigned int filterIndexDiMuonGlb17Trk8 (trgEvent->filterIndex(hltFilterTag_DiMuonGlb17Trk8_) );
     const unsigned int filterIndexDiMuonGlb30Trk11 (trgEvent->filterIndex(hltFilterTag_DiMuonGlb30Trk11_) );
     const unsigned int filterIndexDiMuonGlb17Glb8Iso (trgEvent->filterIndex(hltFilterTag_DiMuonGlb17Glb8Iso_) );
     const unsigned int filterIndexDiMuonGlb17Trk8Iso (trgEvent->filterIndex(hltFilterTag_DiMuonGlb17Trk8Iso_) );
     const unsigned int filterIndexDiMuonL3NoFilters33 (trgEvent->filterIndex(hltFilterTag_DiMuonL3NoFilters33_) );
     const unsigned int filterIndexDiMuonL3NoFilters23Displaced (trgEvent->filterIndex(hltFilterTag_DiMuonL3NoFilters23Displaced_) );
     const unsigned int filterIndexL2DoubleMu28 (trgEvent->filterIndex(hltFilterTag_L2DoubleMu28_) );
     const unsigned int filterIndexL2MuNoBptx20 (trgEvent->filterIndex(hltFilterTag_L2MuNoBptx20_) );
     const unsigned int filterIndexMu38NoVtxPhoton38 (trgEvent->filterIndex(hltFilterTag_Mu38NoVtx_Photon38_) );
     const unsigned int filterIndexMu28NoVtxDisplacedPhoton28 (trgEvent->filterIndex(hltFilterTag_Mu28NoVtxDisplaced_Photon28_) );

     cout<<"trgEvent->sizeFilters is: "<<trgEvent->sizeFilters()<<endl;
     cout<<"filterIndexL3Mu40 is: "<<filterIndexL3Mu40<<endl;
     cout<<"filterIndexL3Mu24Iso is: "<<filterIndexL3Mu24Iso<<endl;
     cout<<"filterIndexL3TrkMu24Iso is: "<<filterIndexL3TrkMu24Iso<<endl;
     cout<<"filterIndexDiMuonGlb17Glb8 is: "<<filterIndexDiMuonGlb17Glb8<<endl;
     cout<<"filterIndexDiMuonGlb17Trk8 is: "<<filterIndexDiMuonGlb17Trk8<<endl;
     cout<<"filterIndexDiMuonGlb30Trk11 is: "<<filterIndexDiMuonGlb30Trk11<<endl;
     cout<<"filterIndexDiMuonGlb17Glb8Iso is: "<<filterIndexDiMuonGlb17Glb8Iso<<endl;
     cout<<"filterIndexDiMuonGlb17Trk8Iso is: "<<filterIndexDiMuonGlb17Trk8Iso<<endl;
     cout<<"filterIndexDiMuonL3NoFilters33 is: "<<filterIndexDiMuonL3NoFilters33<<endl;
     cout<<"filterIndexDiMuonL3NoFilters23Displaced is: "<<filterIndexDiMuonL3NoFilters23Displaced<<endl;
     cout<<"filterIndexL2DoubleMu28 is: "<<filterIndexL2DoubleMu28<<endl<<endl;
     cout<<"filterIndexL2MuNoBptx20 is: "<<filterIndexL2MuNoBptx20<<endl;
     cout<<"filterIndexMu38NoVtxPhoton38 is: "<<filterIndexMu38NoVtxPhoton38<<endl;
     cout<<"filterIndexMu28NoVtxDisplacedPhoton28 is: "<<filterIndexMu28NoVtxDisplacedPhoton28<<endl;


     if (triggerResults->accept(triggerBit_Mu40)) {
       cout<<"passed Mu40"<<endl;
       if (filterIndexL3Mu40 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL3Mu40) );
	 cout << "Found " << keys.size() << " HLT muons from L3Mu40" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_Mu40" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_Mu40" ]->Fill(pt0);
	   histos1D_[ "etaMuon_Mu40" ]->Fill(eta0);
	   histos1D_[ "phiMuon_Mu40" ]->Fill(phi0);
	 }
	 
       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_IsoMu24_IterTrk02)) {
       cout<<"passed IsoMu24"<<endl;
       if (filterIndexL3Mu24Iso < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL3Mu24Iso) );
	 cout << "Found " << keys.size() << " HLT muons from L3Mu24Iso" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_IsoMu24_IterTrk02" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_IsoMu24_IterTrk02" ]->Fill(pt0);
	   histos1D_[ "etaMuon_IsoMu24_IterTrk02" ]->Fill(eta0);
	   histos1D_[ "phiMuon_IsoMu24_IterTrk02" ]->Fill(phi0);
	 }
	 
       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_IsoTkMu24_IterTrk02)) {
       cout<<"passed IsoTkMu24"<<endl;
       if (filterIndexL3TrkMu24Iso < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL3TrkMu24Iso) );
	 cout << "Found " << keys.size() << " HLT muons from L3TrkMu24Iso" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_IsoTkMu24_IterTrk02" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_IsoTkMu24_IterTrk02" ]->Fill(pt0);
	   histos1D_[ "etaMuon_IsoTkMu24_IterTrk02" ]->Fill(eta0);
	   histos1D_[ "phiMuon_IsoTkMu24_IterTrk02" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_Mu17_Mu8)) {
       cout<<"passed Mu17_Mu8"<<endl;
       if (filterIndexDiMuonGlb17Glb8 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb17Glb8) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb17Glb8" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_Mu17_Mu8" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_Mu17_Mu8" ]->Fill(pt0);
	   histos1D_[ "etaMuon_Mu17_Mu8" ]->Fill(eta0);
	   histos1D_[ "phiMuon_Mu17_Mu8" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_Mu17_TkMu8)) {
       cout<<"passed Mu17_TkMu8"<<endl;
       if (filterIndexDiMuonGlb17Trk8 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb17Trk8) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb17Trk8" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_Mu17_TkMu8" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_Mu17_TkMu8" ]->Fill(pt0);
	   histos1D_[ "etaMuon_Mu17_TkMu8" ]->Fill(eta0);
	   histos1D_[ "phiMuon_Mu17_TkMu8" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_Mu30_TkMu11)) {
       cout<<"passed Mu30_TkMu11"<<endl;
       if (filterIndexDiMuonGlb30Trk11 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb30Trk11) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb30Trk11" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_Mu30_TkMu11" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_Mu30_TkMu11" ]->Fill(pt0);
	   histos1D_[ "etaMuon_Mu30_TkMu11" ]->Fill(eta0);
	   histos1D_[ "phiMuon_Mu30_TkMu11" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL)) {
       cout<<"passed Mu17_TkIso_Mu8_TkIso"<<endl;
       if (filterIndexDiMuonGlb17Glb8Iso < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb17Glb8Iso) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb17Glb8Iso" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(pt0);
	   histos1D_[ "etaMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(eta0);
	   histos1D_[ "phiMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL)) {
       cout<<"passed Mu17_TkIso_TkMu8_TrkIso"<<endl;
       if (filterIndexDiMuonGlb17Trk8Iso < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb17Trk8Iso) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb17Trk8Iso" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(pt0);
	   histos1D_[ "etaMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(eta0);
	   histos1D_[ "phiMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_DoubleMu33NoFiltersNoVtx)) {
       cout<<"passed triggerBit_DoubleMu33NoFiltersNoVtx"<<endl;
       if (filterIndexDiMuonL3NoFilters33 < trgEvent->sizeFilters()) {
	 //cout<<"L3NoFilters33 is less than sizeFilters"<<endl;
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonL3NoFilters33) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonL3NoFilters33" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_DoubleMu33NoFiltersNoVtx" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(pt0);
	   histos1D_[ "etaMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(eta0);
	   histos1D_[ "phiMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_DoubleMu23NoFiltersNoVtxDisplaced)) {
       cout<<"passed triggerBit_DoubleMu23NoFiltersNoVtxDisplaced"<<endl;
       if (filterIndexDiMuonL3NoFilters23Displaced < trgEvent->sizeFilters()) {
	 //cout<<"L3NoFilters33 is less than sizeFilters"<<endl;
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonL3NoFilters23Displaced) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonL3NoFilters23Displaced" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(pt0);
	   histos1D_[ "etaMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(eta0);
	   histos1D_[ "phiMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10)) {
       cout<<"passed L2DoubleMu28_NoVertex"<<endl;
       if (filterIndexL2DoubleMu28 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL2DoubleMu28) );
	 cout << "Found " << keys.size() << " HLT muons from L2DoubleMu28" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(pt0);
	   histos1D_[ "etaMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(eta0);
	   histos1D_[ "phiMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo)) {
       cout<<"passed L2Mu20_NoBPTX"<<endl;
       if (filterIndexL2MuNoBptx20 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL2MuNoBptx20) );
	 cout << "Found " << keys.size() << " HLT muons from L2MuNoBptx20" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(pt0);
	   histos1D_[ "etaMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(eta0);
	   histos1D_[ "phiMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_Mu38NoFiltersNoVtx_Photon38_CaloIdL)) {
       cout<<"passed Mu38NoFiltersNoVtx_Photon38_CaloIdL"<<endl;
       if (filterIndexMu38NoVtxPhoton38 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexMu38NoVtxPhoton38) );
	 cout << "Found " << keys.size() << " HLT muons from Mu38NoVtxPhoton38" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(pt0);
	   histos1D_[ "etaMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(eta0);
	   histos1D_[ "phiMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerResults->accept(triggerBit_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL)) {
       cout<<"passed Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL"<<endl;
       if (filterIndexMu28NoVtxDisplacedPhoton28 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexMu28NoVtxDisplacedPhoton28) );
	 cout << "Found " << keys.size() << " HLT muons from Mu28NoVtxDisplacedPhoton28" << endl;
	 
	 double pt0;
	 double eta0;
	 double phi0;
	 triggerObjects(pt0, eta0, phi0, keys, TOC);
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(keys.size());
	   histos1D_[ "ptMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(pt0);
	   histos1D_[ "etaMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(eta0);
	   histos1D_[ "phiMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(phi0);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

   }//end of if trgEvent valid
}//end of analyze()


void HLTMeanTimerAnalyzer::triggerObjects(double& pt0, double& eta0, double& phi0, const trigger::Keys& keys,  const trigger::TriggerObjectCollection& TOC){
  pt0 = 0.;
  eta0 = 0.;
  phi0 = 0.;
  for ( unsigned hlto = 0; hlto < keys.size(); hlto++) {
    trigger::size_type hltf = keys[hlto];
    const trigger::TriggerObject& obj(TOC[hltf]);
    //cout<<"HLT muon pt is:"<<obj.pt()<<", eta is:"<<obj.eta()<<", phi is:"<<obj.phi()<<endl;
    if (obj.pt()> pt0){
      pt0 = obj.pt();
      eta0 = obj.eta();
      phi0 = obj.phi();
    }//end of if obj.pt> pt0
  }//end of loop over keys
}//end of triggerObjects



// ------------ method called once each job just before starting event loop  ------------
void 
HLTMeanTimerAnalyzer::beginJob()
{
  std::cout<<"beginJob!!!!"<<std::endl;
  edm::Service<TFileService> fileService;

  histos1D_[ "nMuons_Mu40" ] = fileService->make< TH1D >( "nMuons_Mu40", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "nMuons_IsoMu24_IterTrk02", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "nMuons_IsoTkMu24_IterTrk02", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_Mu17_Mu8" ] = fileService->make< TH1D >( "nMuons_Mu17_Mu8", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_Mu17_TkMu8" ] = fileService->make< TH1D >( "nMuons_Mu17_TkMu8", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_Mu30_TkMu11" ] = fileService->make< TH1D >( "nMuons_Mu30_TkMu11", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "nMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "nMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "nMuons_DoubleMu33NoFiltersNoVtx", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "nMuons_DoubleMu23NoFiltersNoVtxDisplaced", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "nMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "nMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "nMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "Number of muons", 10, 0., 10);
  histos1D_[ "nMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "nMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "Number of muons", 10, 0., 10);

  histos1D_[ "nMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_Mu17_TkMu8" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_Mu30_TkMu11" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_Mu17_Mu8" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_IsoMu24_IterTrk02" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_IsoTkMu24_IterTrk02" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_Mu40" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "Number of HLT Muons" );

  histos1D_[ "nMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "nMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  histos1D_[ "ptMuon_Mu40" ] = fileService->make< TH1D >( "ptMuon_Mu40", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "ptMuon_IsoMu24_IterTrk02", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "ptMuon_IsoTkMu24_IterTrk02", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "ptMuon_Mu17_Mu8", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "ptMuon_Mu17_TkMu8", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "ptMuon_Mu30_TkMu11", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "ptMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "ptMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "ptMuon_DoubleMu33NoFiltersNoVtx", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "ptMuon_DoubleMu23NoFiltersNoVtxDisplaced", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "ptMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "ptMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "ptMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "ptMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT Muon pt", 100, 0., 1000);

  histos1D_[ "ptMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_Mu17_TkMu8" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_Mu30_TkMu11" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_Mu17_Mu8" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_IsoMu24_IterTrk02" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_Mu40" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );

  histos1D_[ "ptMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "ptMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  histos1D_[ "etaMuon_Mu40" ] = fileService->make< TH1D >( "etaMuon_Mu40", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "etaMuon_IsoMu24_IterTrk02", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "etaMuon_IsoTkMu24_IterTrk02", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "etaMuon_Mu17_Mu8", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "etaMuon_Mu17_TkMu8", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "etaMuon_Mu30_TkMu11", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "etaMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "etaMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "etaMuon_DoubleMu33NoFiltersNoVtx", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "etaMuon_DoubleMu23NoFiltersNoVtxDisplaced", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "etaMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "etaMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "etaMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "etaMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT Muon eta", 120,-6,6);

  histos1D_[ "etaMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_Mu17_TkMu8" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_Mu30_TkMu11" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_Mu17_Mu8" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_IsoMu24_IterTrk02" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_Mu40" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT Muon #eta" );

  histos1D_[ "etaMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "etaMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  histos1D_[ "phiMuon_Mu40" ] = fileService->make< TH1D >( "phiMuon_Mu40", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "phiMuon_IsoMu24_IterTrk02", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "phiMuon_IsoTkMu24_IterTrk02", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "phiMuon_Mu17_Mu8", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "phiMuon_Mu17_TkMu8", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "phiMuon_Mu30_TkMu11", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "phiMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "phiMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "phiMuon_DoubleMu33NoFiltersNoVtx", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "phiMuon_DoubleMu23NoFiltersNoVtxDisplaced", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "phiMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "phiMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "phiMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "phiMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT Muon phi", 64,-3.2,3.2);

  histos1D_[ "phiMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_Mu17_TkMu8" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_Mu30_TkMu11" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_Mu17_Mu8" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_IsoMu24_IterTrk02" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_Mu40" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT Muon #phi" );

  histos1D_[ "phiMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "phiMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"ending beginJob!!!!"<<std::endl;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
HLTMeanTimerAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
HLTMeanTimerAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
HLTMeanTimerAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
HLTMeanTimerAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
HLTMeanTimerAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
HLTMeanTimerAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  std::cout<<"starting fillDescriptions"<<std::endl;
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
  std::cout<<"finishing fillDescriptions"<<std::endl;
}

//define this as a plug-in
DEFINE_FWK_MODULE(HLTMeanTimerAnalyzer);
