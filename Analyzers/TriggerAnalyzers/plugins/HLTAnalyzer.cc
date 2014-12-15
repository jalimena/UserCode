// -*- C++ -*-
//
// Package:    TriggerAnalyzer/HLTAnalyzer
// Class:      HLTAnalyzer
// 
/**\class HLTAnalyzer HLTAnalyzer.cc TriggerAnalyzer/HLTAnalyzer/plugins/HLTAnalyzer.cc

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
#include "TMath.h"
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

//gen particles
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

//tracks
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"

//
// class declaration
//

using namespace reco;

class HLTAnalyzer : public edm::EDAnalyzer {
public:
  explicit HLTAnalyzer(const edm::ParameterSet&);
  ~HLTAnalyzer();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  

  struct genParticle_pt : public std::binary_function<reco::GenParticle, reco::GenParticle, bool> {
    bool operator()(const reco::GenParticle& x, const reco::GenParticle& y) {
      return ( x.pt() > y.pt() ) ;
    }
  };

  struct track_pt : public std::binary_function<reco::Track, reco::Track, bool> {
    bool operator()(const reco::Track& x, const reco::Track& y) {
      return ( x.pt() > y.pt() ) ;
    }
  };
  
private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void genMuons(const edm::Event&, double&, double&, double&, double&, double&, int&);
  virtual void hltL2Muons(const edm::Event&, double&, double&, double&, double&, double&, int&);
  double D0BeamSpot(double vx, double vy, double px, double py, double pt, double refx, double refy);
  virtual void triggerObjects(double&, double&, double&, double&, double&, double&, const trigger::Keys&,  const trigger::TriggerObjectCollection&);
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
  edm::InputTag genParticlesTag_;
  edm::InputTag beamSpotTag_;
  edm::InputTag hltL2MuonsTag_;
  edm::InputTag hltFilterTag_L1Mu6NotBptxOR_;
  edm::InputTag hltFilterTag_L1DoubleMu125_;
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
  bool subLeading_;
  bool lookForMother_;
  bool useMotherInLxyCalc_;
  int motherId_;
  double genMuonPt_;

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
HLTAnalyzer::HLTAnalyzer(const edm::ParameterSet& iConfig):
  hltResultsTag_(iConfig.getUntrackedParameter<edm::InputTag>("hltResultsTag",edm::InputTag("TriggerResults","","HLT"))),
  //hltResultsToken_(consumes<edm::TriggerResults>(hltResultsTag_)),
  hltEventTag_(iConfig.getUntrackedParameter<edm::InputTag>("hltEventTag",edm::InputTag("hltTriggerSummaryAOD","","HLT"))),
  //hltEventToken_(consumes<trigger::TriggerEvent>(hltEventTag_)),
  genParticlesTag_(iConfig.getUntrackedParameter<edm::InputTag>("genParticlesTag",edm::InputTag("genParticles"))),
  beamSpotTag_ (iConfig.getUntrackedParameter<edm::InputTag>("beamSpotTag",edm::InputTag("hltOnlineBeamSpot","","HLT"))),
  hltL2MuonsTag_(iConfig.getUntrackedParameter<edm::InputTag>("hltL2MuonsTag",edm::InputTag("hltL2Muons"))),

  hltFilterTag_L1Mu6NotBptxOR_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L1Mu6NotBptxOR",edm::InputTag("hltL1sMu6NotBptxOR","","HLT"))),
  hltFilterTag_L1DoubleMu125_(iConfig.getUntrackedParameter<edm::InputTag>("hltFilterTag_L1DoubleMu125",edm::InputTag("hltL1sL1DoubleMu103p5ORDoubleMu125","","HLT"))),

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

  BarrelOnly_(iConfig.getUntrackedParameter<bool>("BarrelOnly",bool("False"))),
  subLeading_(iConfig.getUntrackedParameter<bool>("subLeading",bool("False"))),
  lookForMother_(iConfig.getUntrackedParameter<bool>("lookForMother",bool("False"))),
  useMotherInLxyCalc_(iConfig.getUntrackedParameter<bool>("useMotherInLxyCalc",bool("False"))),
  motherId_(iConfig.getUntrackedParameter<int>("motherId",int(13))),
  genMuonPt_(iConfig.getUntrackedParameter<double>("genMuonPt",double(0.)))

{
   //now do what ever initialization is needed
  std::cout<<"doing constructor"<<std::endl;
  std::cout<<"iConfig is: "<<iConfig<<std::endl;
}


HLTAnalyzer::~HLTAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
HLTAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;

   cout<<"starting analyze"<<endl;

   //find gen muons, without trigger requirement
   double genMuonPt0, genMuonEta0, genMuonPhi0, genMuonDxy0, genMuonLxy0;
   int nGenMuon;
   genMuons(iEvent, genMuonPt0, genMuonEta0, genMuonPhi0, genMuonDxy0, genMuonLxy0, nGenMuon);
   cout<<"genMuon pt is (2nd time): "<<genMuonPt0<<endl;

   histos1D_[ "nGenMuons" ]->Fill(nGenMuon);
   if(genMuonPt0!=-1.){
     histos1D_[ "ptGenMuon" ]->Fill(genMuonPt0);
     histos1D_[ "etaGenMuon" ]->Fill(genMuonEta0);
     histos1D_[ "phiGenMuon" ]->Fill(genMuonPhi0);
     histos1D_[ "dxyGenMuon" ]->Fill(genMuonDxy0);
     histos1D_[ "lxyGenMuon" ]->Fill(genMuonLxy0);
   }
     

   //find hltL2Muons, without trigger requirement
   double hltL2MuonPt0, hltL2MuonEta0, hltL2MuonPhi0, hltL2MuonDxy0, hltL2MuonLxy0;
   int nHltL2Muon;
   hltL2Muons(iEvent, hltL2MuonPt0, hltL2MuonEta0, hltL2MuonPhi0, hltL2MuonDxy0, hltL2MuonLxy0, nHltL2Muon);

   histos1D_[ "nHltL2MuonTracks" ]->Fill(nHltL2Muon);
   if(hltL2MuonPt0!=-1.){
     histos1D_[ "ptHltL2MuonTrack" ]->Fill(hltL2MuonPt0);
     histos1D_[ "etaHltL2MuonTrack" ]->Fill(hltL2MuonEta0);
     histos1D_[ "phiHltL2MuonTrack" ]->Fill(hltL2MuonPhi0);
     histos1D_[ "dxyHltL2MuonTrack" ]->Fill(hltL2MuonDxy0);
     histos1D_[ "lxyHltL2MuonTrack" ]->Fill(hltL2MuonLxy0);
   }

   //get trigger results
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

     const unsigned int filterIndexL1Mu6NotBptxOR (trgEvent->filterIndex(hltFilterTag_L1Mu6NotBptxOR_) );
     const unsigned int filterIndexL1DoubleMu125 (trgEvent->filterIndex(hltFilterTag_L1DoubleMu125_) );

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
     cout<<"filterIndexL1Mu6NotBptxOR is: "<<filterIndexL1Mu6NotBptxOR<<endl;
     cout<<"filterIndexL1DoubleMu125 is: "<<filterIndexL1DoubleMu125<<endl;
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


     //pass L1 filters?
       if (filterIndexL1Mu6NotBptxOR < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL1Mu6NotBptxOR) );
	 cout << "Found " << keys.size() << " L1 muons from L1Mu6NotBptxOR" << endl;
	 
	 double pt_, pt0, pt1;
	 double eta_, eta0, eta1;
	 double phi_, phi0, phi1;
	 triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);	 

	 if(subLeading_){
	   pt_=pt1;
	   eta_=eta1;
	   phi_=phi1;
	 }
	 else{
	   pt_=pt0;
	   eta_=eta0;
	   phi_=phi0;
	 }
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_L1Mu6NotBptxOR" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_L1Mu6NotBptxOR" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_L1Mu6NotBptxOR" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_L1Mu6NotBptxOR" ]->Fill(phi_);
	 }
	 
       }//end of index< sizeFilters
       cout<<endl;

       if (filterIndexL1DoubleMu125 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL1DoubleMu125) );
	 cout << "Found " << keys.size() << " L1 muons from L1DoubleMu125" << endl;
	 
	 double pt_, pt0, pt1;
	 double eta_, eta0, eta1;
	 double phi_, phi0, phi1;
	 triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);	 

	 if(subLeading_){
	   pt_=pt1;
	   eta_=eta1;
	   phi_=phi1;
	 }
	 else{
	   pt_=pt0;
	   eta_=eta0;
	   phi_=phi0;
	 }
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_L1DoubleMu125" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_L1DoubleMu125" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_L1DoubleMu125" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_L1DoubleMu125" ]->Fill(phi_);
	 }
	 
       }//end of index< sizeFilters
       cout<<endl;



     //pass HLT filters?
     if (triggerBit_Mu40 != -1 && triggerResults->accept(triggerBit_Mu40)) {
       cout<<"passed Mu40"<<endl;
       if (filterIndexL3Mu40 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL3Mu40) );
	 cout << "Found " << keys.size() << " HLT muons from L3Mu40" << endl;
	 
	 double pt_, pt0, pt1;
	 double eta_, eta0, eta1;
	 double phi_, phi0, phi1;
	 triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);	 

	 if(subLeading_){
	   pt_=pt1;
	   eta_=eta1;
	   phi_=phi1;
	 }
	 else{
	   pt_=pt0;
	   eta_=eta0;
	   phi_=phi0;
	 }
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_Mu40" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_Mu40" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_Mu40" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_Mu40" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_Mu40" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_Mu40" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_Mu40" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_Mu40" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_Mu40" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_Mu40" ]->Fill(genMuonLxy0_t);
	 }
	 	 
	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_Mu40" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_Mu40" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_Mu40" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_Mu40" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_Mu40" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_Mu40" ]->Fill(hltL2MuonLxy0_t);
	 }	 	 

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger
     
     if (triggerBit_IsoMu24_IterTrk02 != -1 && triggerResults->accept(triggerBit_IsoMu24_IterTrk02)) {
       cout<<"passed IsoMu24"<<endl;
       if (filterIndexL3Mu24Iso < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL3Mu24Iso) );
	 cout << "Found " << keys.size() << " HLT muons from L3Mu24Iso" << endl;
	 
	 double pt_, pt0, pt1;
	 double eta_, eta0, eta1;
	 double phi_, phi0, phi1;
	 triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);

         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_IsoMu24_IterTrk02" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_IsoMu24_IterTrk02" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_IsoMu24_IterTrk02" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_IsoMu24_IterTrk02" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_IsoMu24_IterTrk02" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_IsoMu24_IterTrk02" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_IsoMu24_IterTrk02" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_IsoMu24_IterTrk02" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_IsoMu24_IterTrk02" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_IsoMu24_IterTrk02" ]->Fill(genMuonLxy0_t);
	 }

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_IsoMu24_IterTrk02" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_IsoMu24_IterTrk02" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_IsoMu24_IterTrk02" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_IsoMu24_IterTrk02" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_IsoMu24_IterTrk02" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_IsoMu24_IterTrk02" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_IsoTkMu24_IterTrk02 != -1 && triggerResults->accept(triggerBit_IsoTkMu24_IterTrk02)) {
       cout<<"passed IsoTkMu24"<<endl;
       if (filterIndexL3TrkMu24Iso < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL3TrkMu24Iso) );
	 cout << "Found " << keys.size() << " HLT muons from L3TrkMu24Iso" << endl;

	 double pt_, pt0, pt1;
	 double eta_, eta0, eta1;
	 double phi_, phi0, phi1;
	 triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);

         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_IsoTkMu24_IterTrk02" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_IsoTkMu24_IterTrk02" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_IsoTkMu24_IterTrk02" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_IsoTkMu24_IterTrk02" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_IsoTkMu24_IterTrk02" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_IsoTkMu24_IterTrk02" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_IsoTkMu24_IterTrk02" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_IsoTkMu24_IterTrk02" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_IsoTkMu24_IterTrk02" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_IsoTkMu24_IterTrk02" ]->Fill(genMuonLxy0_t);
	 }

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_IsoTkMu24_IterTrk02" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_Mu17_Mu8 != -1 && triggerResults->accept(triggerBit_Mu17_Mu8)) {
       cout<<"passed Mu17_Mu8"<<endl;
       if (filterIndexDiMuonGlb17Glb8 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb17Glb8) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb17Glb8" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_Mu17_Mu8" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_Mu17_Mu8" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_Mu17_Mu8" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_Mu17_Mu8" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_Mu17_Mu8" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_Mu17_Mu8" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_Mu17_Mu8" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_Mu17_Mu8" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_Mu17_Mu8" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_Mu17_Mu8" ]->Fill(genMuonLxy0_t);
	 }	 	 

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_Mu17_Mu8" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_Mu17_Mu8" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_Mu17_Mu8" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_Mu17_Mu8" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_Mu17_Mu8" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_Mu17_Mu8" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_Mu17_TkMu8 != -1 && triggerResults->accept(triggerBit_Mu17_TkMu8)) {
       cout<<"passed Mu17_TkMu8"<<endl;
       if (filterIndexDiMuonGlb17Trk8 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb17Trk8) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb17Trk8" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_Mu17_TkMu8" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_Mu17_TkMu8" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_Mu17_TkMu8" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_Mu17_TkMu8" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_Mu17_TkMu8" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_Mu17_TkMu8" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_Mu17_TkMu8" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_Mu17_TkMu8" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_Mu17_TkMu8" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_Mu17_TkMu8" ]->Fill(genMuonLxy0_t);
	 }	 	 

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_Mu17_TkMu8" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_Mu17_TkMu8" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_Mu17_TkMu8" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_Mu17_TkMu8" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_Mu17_TkMu8" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_Mu17_TkMu8" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_Mu30_TkMu11 != -1 && triggerResults->accept(triggerBit_Mu30_TkMu11)) {
       cout<<"passed Mu30_TkMu11"<<endl;
       if (filterIndexDiMuonGlb30Trk11 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb30Trk11) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb30Trk11" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_Mu30_TkMu11" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_Mu30_TkMu11" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_Mu30_TkMu11" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_Mu30_TkMu11" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_Mu30_TkMu11" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_Mu30_TkMu11" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_Mu30_TkMu11" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_Mu30_TkMu11" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_Mu30_TkMu11" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_Mu30_TkMu11" ]->Fill(genMuonLxy0_t);
	 }

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_Mu30_TkMu11" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_Mu30_TkMu11" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_Mu30_TkMu11" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_Mu30_TkMu11" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_Mu30_TkMu11" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_Mu30_TkMu11" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL != -1 && triggerResults->accept(triggerBit_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL)) {
       cout<<"passed Mu17_TkIso_Mu8_TkIso"<<endl;
       if (filterIndexDiMuonGlb17Glb8Iso < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb17Glb8Iso) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb17Glb8Iso" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(genMuonLxy0_t);
	 }

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL != -1 && triggerResults->accept(triggerBit_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL)) {
       cout<<"passed Mu17_TkIso_TkMu8_TrkIso"<<endl;
       if (filterIndexDiMuonGlb17Trk8Iso < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonGlb17Trk8Iso) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonGlb17Trk8Iso" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);

         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }
	 
	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(genMuonLxy0_t);
	 }	 	 

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_DoubleMu33NoFiltersNoVtx != -1 && triggerResults->accept(triggerBit_DoubleMu33NoFiltersNoVtx)) {
       cout<<"passed triggerBit_DoubleMu33NoFiltersNoVtx"<<endl;
       if (filterIndexDiMuonL3NoFilters33 < trgEvent->sizeFilters()) {
	 //cout<<"L3NoFilters33 is less than sizeFilters"<<endl;
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonL3NoFilters33) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonL3NoFilters33" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_DoubleMu33NoFiltersNoVtx" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_DoubleMu33NoFiltersNoVtx" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_DoubleMu33NoFiltersNoVtx" ]->Fill(genMuonLxy0_t);
	 }	 	 

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_DoubleMu33NoFiltersNoVtx" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_DoubleMu23NoFiltersNoVtxDisplaced != -1 && triggerResults->accept(triggerBit_DoubleMu23NoFiltersNoVtxDisplaced)) {
       cout<<"passed triggerBit_DoubleMu23NoFiltersNoVtxDisplaced"<<endl;
       if (filterIndexDiMuonL3NoFilters23Displaced < trgEvent->sizeFilters()) {
	 //cout<<"L3NoFilters33 is less than sizeFilters"<<endl;
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexDiMuonL3NoFilters23Displaced) );
	 cout << "Found " << keys.size() << " HLT muons from DiMuonL3NoFilters23Displaced" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(genMuonLxy0_t);
	 }	 	 

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10 != -1 && triggerResults->accept(triggerBit_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10)) {
       cout<<"passed L2DoubleMu28_NoVertex"<<endl;
       if (filterIndexL2DoubleMu28 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL2DoubleMu28) );
	 cout << "Found " << keys.size() << " HLT muons from L2DoubleMu28" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 cout<<"pt0 is: "<<pt0<<", pt1 is: "<<pt1<<endl;

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(genMuonLxy0_t);
	 }

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo != -1 && triggerResults->accept(triggerBit_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo)) {
       cout<<"passed L2Mu20_NoBPTX"<<endl;
       if (filterIndexL2MuNoBptx20 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexL2MuNoBptx20) );
	 cout << "Found " << keys.size() << " HLT muons from L2MuNoBptx20" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(genMuonLxy0_t);
	 }

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_Mu38NoFiltersNoVtx_Photon38_CaloIdL != -1 && triggerResults->accept(triggerBit_Mu38NoFiltersNoVtx_Photon38_CaloIdL)) {
       cout<<"passed Mu38NoFiltersNoVtx_Photon38_CaloIdL"<<endl;
       if (filterIndexMu38NoVtxPhoton38 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexMu38NoVtxPhoton38) );
	 cout << "Found " << keys.size() << " HLT muons from Mu38NoVtxPhoton38" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(genMuonLxy0_t);
	 }

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

     if (triggerBit_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL != -1 && triggerResults->accept(triggerBit_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL)) {
       cout<<"passed Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL"<<endl;
       if (filterIndexMu28NoVtxDisplacedPhoton28 < trgEvent->sizeFilters()) {
	 const trigger::Keys& keys( trgEvent->filterKeys(filterIndexMu28NoVtxDisplacedPhoton28) );
	 cout << "Found " << keys.size() << " HLT muons from Mu28NoVtxDisplacedPhoton28" << endl;
	 
         double pt_, pt0, pt1;
         double eta_, eta0, eta1;
         double phi_, phi0, phi1;
         triggerObjects(pt0, eta0, phi0, pt1, eta1, phi1, keys, TOC);
	 
         if(subLeading_){
           pt_=pt1;
           eta_=eta1;
           phi_=phi1;
         }
         else{
           pt_=pt0;
           eta_=eta0;
           phi_=phi0;
         }

	 //fill histos with leading trig obj info
	 if( (BarrelOnly_ && TMath::Abs(eta0)<0.9) || (!BarrelOnly_)){
	   histos1D_[ "nTriggerMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(keys.size());
	   histos1D_[ "ptTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(pt_);
	   histos1D_[ "etaTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(eta_);
	   histos1D_[ "phiTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(phi_);
	 }

	 //find gen muons, for events passing trigger
	 double genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t;
	 int nGenMuon_t;
	 genMuons(iEvent, genMuonPt0_t, genMuonEta0_t, genMuonPhi0_t, genMuonDxy0_t, genMuonLxy0_t, nGenMuon_t);	 
	 histos1D_[ "nGenMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(nGenMuon_t);
	 if(genMuonPt0_t!=-1.){
	   histos1D_[ "ptGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(genMuonPt0_t);
	   histos1D_[ "etaGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(genMuonEta0_t);
	   histos1D_[ "phiGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(genMuonPhi0_t);
	   histos1D_[ "dxyGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(genMuonDxy0_t);
	   histos1D_[ "lxyGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(genMuonLxy0_t);
	 }

	 //find hltL2Muons, for events passing trigger
	 double hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t;
	 int nHltL2Muon_t;
	 hltL2Muons(iEvent, hltL2MuonPt0_t, hltL2MuonEta0_t, hltL2MuonPhi0_t, hltL2MuonDxy0_t, hltL2MuonLxy0_t, nHltL2Muon_t);	 
	 histos1D_[ "nHltL2MuonTracks_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(nHltL2Muon_t);
	 if(hltL2MuonPt0_t!=-1.){
	   histos1D_[ "ptHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(hltL2MuonPt0_t);
	   histos1D_[ "etaHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(hltL2MuonEta0_t);
	   histos1D_[ "phiHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(hltL2MuonPhi0_t);
	   histos1D_[ "dxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(hltL2MuonDxy0_t);
	   histos1D_[ "lxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->Fill(hltL2MuonLxy0_t);
	 }

       }//end of index< sizeFilters
       cout<<endl;
     }//end of pass trigger

   }//end of if trgEvent valid
}//end of analyze()



void HLTAnalyzer::hltL2Muons(const edm::Event& iEvent, double& hltL2MuonPt0, double& hltL2MuonEta0, double& hltL2MuonPhi0, double& hltL2MuonDxy0, double& hltL2MuonLxy0, int& nHltL2Muon){

   //find hltL2Muons
  using namespace std;

  edm::Handle<reco::TrackCollection> hltL2Muons;
  iEvent.getByLabel(hltL2MuonsTag_, hltL2Muons);
  
  if (hltL2Muons.isValid()) {
    std::cout<<"hltL2Muons is Valid"<<std::endl;
    std::vector<Track> hltL2Muons_;
    hltL2Muons_.insert(hltL2Muons_.end(), hltL2Muons->begin(), hltL2Muons->end());
    std::sort(hltL2Muons_.begin(), hltL2Muons_.end(), track_pt());
    
    hltL2MuonPt0 = -1.;
    hltL2MuonEta0 = -1.;
    hltL2MuonPhi0 = -1.;
    hltL2MuonDxy0 = -1.;
    hltL2MuonLxy0 = -1.;
    nHltL2Muon = 0;
    
    //for(size_t i=0; i<hltL2Muons_.size(); i++){
    //const reco::Track & p = hltL2Muons_.at(i);
    for(reco::TrackCollection::const_iterator it = hltL2Muons_.begin(); it!=hltL2Muons_.end(); it++){
      nHltL2Muon++;
      if (it->pt()> hltL2MuonPt0){
	hltL2MuonPt0 = it->pt();
	hltL2MuonEta0 = it->eta();
	hltL2MuonPhi0 = it->phi();
	hltL2MuonDxy0 = it->dxy();
	hltL2MuonLxy0 = it->vx()*it->vx()+it->vy()*it->vy();
	hltL2MuonLxy0 = sqrt(hltL2MuonLxy0);
      }//end if hltL2 muon pt greater than saved highest hltL2 muon pt
    }//end of loop over hltL2 particles
  }//end of if hltL2Muons is valid
}//end of hltL2Muons


void HLTAnalyzer::genMuons(const edm::Event& iEvent, double& genMuonPt0, double& genMuonEta0, double& genMuonPhi0, double& genMuonDxy0, double& genMuonLxy0, int& nGenMuon){

  //find gen muons
  using namespace std;
  
  edm::Handle<reco::GenParticleCollection> genParticles;
  iEvent.getByLabel(genParticlesTag_, genParticles);
  
  edm::Handle<reco::BeamSpot> BeamSpot;
  iEvent.getByLabel(beamSpotTag_, BeamSpot);  
  
  
  if (genParticles.isValid()) {
    std::vector<GenParticle> genParticles_;
    genParticles_.insert(genParticles_.end(), genParticles->begin(), genParticles->end());
    std::sort(genParticles_.begin(), genParticles_.end(), genParticle_pt());
    
    genMuonPt0 = -1.;
    genMuonEta0 = -1.;
    genMuonPhi0 = -1.;
    genMuonDxy0 = -1.;
    genMuonLxy0 = -1.;
    nGenMuon = 0;
    
    for(size_t i=0; i<genParticles_.size(); i++){
      const reco::GenParticle & p = genParticles_.at(i);
      if (fabs(p.pdgId()) == 13 && p.status()==1 && p.pt()>genMuonPt_) {
	if((lookForMother_ && fabs(p.mother()->pdgId()) == motherId_) || !lookForMother_){
	  nGenMuon++;
	  if (p.pt()> genMuonPt0){
	    genMuonPt0 = p.pt();
	    genMuonEta0 = p.eta();
	    genMuonPhi0 = p.phi();
	    cout<<"genMuon pt is (1st time): "<<p.pt()<<endl;
	    if (BeamSpot.isValid()) genMuonDxy0 = D0BeamSpot(p.vx(),p.vy(),p.px(),p.py(),p.pt(),BeamSpot->x0(),BeamSpot->y0());
	    else{
	      cout<<"beamSpot is not valid!!!!"<<endl;
	      genMuonDxy0 = D0BeamSpot(p.vx(),p.vy(),p.px(),p.py(),p.pt(),0.,0.);
	    }
	    if(useMotherInLxyCalc_) {
	      genMuonLxy0 = (p.mother()->vx() - p.vx())*(p.mother()->vx() - p.vx()) + (p.mother()->vy() - p.vy())*(p.mother()->vy() - p.vy());
	      cout<<"mother vertex is: "<<p.mother()->vx()<<", "<<p.mother()->vy()<<endl;
	    }
	    else genMuonLxy0 = p.vx()*p.vx()+p.vy()*p.vy();
	    genMuonLxy0 = sqrt(genMuonLxy0);
	    cout<<"genMuon vertex is: "<<p.vx()<<", "<<p.vy()<<endl;
	    cout<<"genMuonLxy0 is: "<<genMuonLxy0<<endl;
	  }//end if gen muon pt greater than saved highest gen muon pt
	}//end of look for mother
      }//end of if status 1 gen muon with eta<2.4
    }//end of loop over gen particles
  }//end of if gen collection is valid
}//end of genMuons


void HLTAnalyzer::triggerObjects(double& pt0, double& eta0, double& phi0, double& pt1, double& eta1, double& phi1, const trigger::Keys& keys,  const trigger::TriggerObjectCollection& TOC){
  pt0 = -1.;
  eta0 = -1.;
  phi0 = -1.;

  pt1 = -1.;
  eta1 = -1.;
  phi1 = -1.;

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

  for ( unsigned hlto = 0; hlto < keys.size(); hlto++) {
    trigger::size_type hltf = keys[hlto];
    const trigger::TriggerObject& obj(TOC[hltf]);
    //cout<<"HLT muon pt is:"<<obj.pt()<<", eta is:"<<obj.eta()<<", phi is:"<<obj.phi()<<endl;
    if (obj.pt()> pt1 && obj.pt()<pt0){
      pt1 = obj.pt();
      eta1 = obj.eta();
      phi1 = obj.phi();
    }//end of if obj.pt> pt0
  }//end of loop over keys

}//end of triggerObjects


double HLTAnalyzer::D0BeamSpot(double vx, double vy, double px, double py, double pt, double refx, double refy)
{
  return -(-(vx-refx) * py + (vy-refy) * px)/pt;
}


// ------------ method called once each job just before starting event loop  ------------
void 
HLTAnalyzer::beginJob()
{
  std::cout<<"beginJob!!!!"<<std::endl;
  edm::Service<TFileService> fileService;

  histos1D_[ "nGenMuons" ] = fileService->make< TH1D >( "nGenMuons", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons" ]->SetYTitle( "Events" );

  histos1D_[ "ptGenMuon" ] = fileService->make< TH1D >( "ptGenMuon", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon" ]->SetYTitle( "Events" );

  histos1D_[ "etaGenMuon" ] = fileService->make< TH1D >( "etaGenMuon", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon" ]->SetYTitle( "Events" );

  histos1D_[ "phiGenMuon" ] = fileService->make< TH1D >( "phiGenMuon", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon" ]->SetYTitle( "Events" );

  //histos1D_[ "dxyGenMuon" ] = fileService->make< TH1D >( "dxyGenMuon", "Generator Muon dxy", 400, -200, 200);
  histos1D_[ "dxyGenMuon" ] = fileService->make< TH1D >( "dxyGenMuon", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon" ]->SetYTitle( "Events" );

  histos1D_[ "lxyGenMuon" ] = fileService->make< TH1D >( "lxyGenMuon", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon" ]->SetYTitle( "Events" );


  histos1D_[ "nHltL2MuonTracks" ] = fileService->make< TH1D >( "nHltL2MuonTracks", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks" ]->SetYTitle( "Events" );

  histos1D_[ "ptHltL2MuonTrack" ] = fileService->make< TH1D >( "ptHltL2MuonTrack", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack" ]->SetYTitle( "Events" );

  histos1D_[ "etaHltL2MuonTrack" ] = fileService->make< TH1D >( "etaHltL2MuonTrack", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack" ]->SetYTitle( "Events" );

  histos1D_[ "phiHltL2MuonTrack" ] = fileService->make< TH1D >( "phiHltL2MuonTrack", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack" ]->SetYTitle( "Events" );

  histos1D_[ "dxyHltL2MuonTrack" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack" ]->SetYTitle( "Events" );

  histos1D_[ "lxyHltL2MuonTrack" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack" ]->SetYTitle( "Events" );



  histos1D_[ "nTriggerMuons_L1Mu6NotBptxOR" ] = fileService->make< TH1D >( "nTriggerMuons_L1Mu6NotBptxOR", "Number of L1 muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_L1Mu6NotBptxOR" ]->SetXTitle( "Number of L1 Muons" );
  histos1D_[ "nTriggerMuons_L1Mu6NotBptxOR" ]->SetYTitle( "Events" );

  histos1D_[ "ptTriggerMuon_L1Mu6NotBptxOR" ] = fileService->make< TH1D >( "ptTriggerMuon_L1Mu6NotBptxOR", "L1 Muon pt", 500, 0., 500);
  histos1D_[ "ptTriggerMuon_L1Mu6NotBptxOR" ]->SetXTitle( "L1 Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_L1Mu6NotBptxOR" ]->SetYTitle( "Events" );

  histos1D_[ "etaTriggerMuon_L1Mu6NotBptxOR" ] = fileService->make< TH1D >( "etaTriggerMuon_L1Mu6NotBptxOR", "L1 Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_L1Mu6NotBptxOR" ]->SetXTitle( "L1 Muon #eta" );
  histos1D_[ "etaTriggerMuon_L1Mu6NotBptxOR" ]->SetYTitle( "Events" );

  histos1D_[ "phiTriggerMuon_L1Mu6NotBptxOR" ] = fileService->make< TH1D >( "phiTriggerMuon_L1Mu6NotBptxOR", "L1 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_L1Mu6NotBptxOR" ]->SetXTitle( "L1 Muon #phi" );
  histos1D_[ "phiTriggerMuon_L1Mu6NotBptxOR" ]->SetYTitle( "Events" );


  histos1D_[ "nTriggerMuons_L1DoubleMu125" ] = fileService->make< TH1D >( "nTriggerMuons_L1DoubleMu125", "Number of L1 muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_L1DoubleMu125" ]->SetXTitle( "Number of L1 Muons" );
  histos1D_[ "nTriggerMuons_L1DoubleMu125" ]->SetYTitle( "Events" );

  histos1D_[ "ptTriggerMuon_L1DoubleMu125" ] = fileService->make< TH1D >( "ptTriggerMuon_L1DoubleMu125", "L1 Muon pt", 500, 0., 500);
  histos1D_[ "ptTriggerMuon_L1DoubleMu125" ]->SetXTitle( "L1 Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_L1DoubleMu125" ]->SetYTitle( "Events" );

  histos1D_[ "etaTriggerMuon_L1DoubleMu125" ] = fileService->make< TH1D >( "etaTriggerMuon_L1DoubleMu125", "L1 Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_L1DoubleMu125" ]->SetXTitle( "L1 Muon #eta" );
  histos1D_[ "etaTriggerMuon_L1DoubleMu125" ]->SetYTitle( "Events" );

  histos1D_[ "phiTriggerMuon_L1DoubleMu125" ] = fileService->make< TH1D >( "phiTriggerMuon_L1DoubleMu125", "L1 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_L1DoubleMu125" ]->SetXTitle( "L1 Muon #phi" );
  histos1D_[ "phiTriggerMuon_L1DoubleMu125" ]->SetYTitle( "Events" );


  histos1D_[ "nTriggerMuons_Mu40" ] = fileService->make< TH1D >( "nTriggerMuons_Mu40", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "nTriggerMuons_IsoMu24_IterTrk02", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "nTriggerMuons_IsoTkMu24_IterTrk02", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_Mu17_Mu8" ] = fileService->make< TH1D >( "nTriggerMuons_Mu17_Mu8", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_Mu17_TkMu8" ] = fileService->make< TH1D >( "nTriggerMuons_Mu17_TkMu8", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_Mu30_TkMu11" ] = fileService->make< TH1D >( "nTriggerMuons_Mu30_TkMu11", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "nTriggerMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "nTriggerMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "nTriggerMuons_DoubleMu33NoFiltersNoVtx", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "nTriggerMuons_DoubleMu23NoFiltersNoVtxDisplaced", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "nTriggerMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "nTriggerMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "nTriggerMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "Number of muons", 10, 0., 10);
  histos1D_[ "nTriggerMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "nTriggerMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "Number of muons", 10, 0., 10);

  histos1D_[ "nTriggerMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_Mu17_TkMu8" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_Mu30_TkMu11" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_Mu17_Mu8" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_IsoMu24_IterTrk02" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_IsoTkMu24_IterTrk02" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_Mu40" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "Number of HLT Muons" );
  histos1D_[ "nTriggerMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "Number of HLT Muons" );

  histos1D_[ "nTriggerMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "nTriggerMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  histos1D_[ "ptTriggerMuon_Mu40" ] = fileService->make< TH1D >( "ptTriggerMuon_Mu40", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "ptTriggerMuon_IsoMu24_IterTrk02", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "ptTriggerMuon_IsoTkMu24_IterTrk02", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "ptTriggerMuon_Mu17_Mu8", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "ptTriggerMuon_Mu17_TkMu8", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "ptTriggerMuon_Mu30_TkMu11", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "ptTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "ptTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "ptTriggerMuon_DoubleMu33NoFiltersNoVtx", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "ptTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "ptTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "ptTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "ptTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT Muon pt", 100, 0., 1000);
  histos1D_[ "ptTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "ptTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT Muon pt", 100, 0., 1000);

  histos1D_[ "ptTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_Mu17_TkMu8" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_Mu30_TkMu11" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_Mu17_Mu8" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_IsoMu24_IterTrk02" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_Mu40" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );
  histos1D_[ "ptTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT Muon p_{T} [GeV]" );

  histos1D_[ "ptTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "ptTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  histos1D_[ "etaTriggerMuon_Mu40" ] = fileService->make< TH1D >( "etaTriggerMuon_Mu40", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "etaTriggerMuon_IsoMu24_IterTrk02", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "etaTriggerMuon_IsoTkMu24_IterTrk02", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "etaTriggerMuon_Mu17_Mu8", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "etaTriggerMuon_Mu17_TkMu8", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "etaTriggerMuon_Mu30_TkMu11", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "etaTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "etaTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "etaTriggerMuon_DoubleMu33NoFiltersNoVtx", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "etaTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "etaTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "etaTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "etaTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT Muon eta", 120,-6,6);
  histos1D_[ "etaTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "etaTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT Muon eta", 120,-6,6);

  histos1D_[ "etaTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_Mu17_TkMu8" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_Mu30_TkMu11" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_Mu17_Mu8" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_IsoMu24_IterTrk02" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_Mu40" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT Muon #eta" );
  histos1D_[ "etaTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT Muon #eta" );

  histos1D_[ "etaTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "etaTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  histos1D_[ "phiTriggerMuon_Mu40" ] = fileService->make< TH1D >( "phiTriggerMuon_Mu40", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "phiTriggerMuon_IsoMu24_IterTrk02", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "phiTriggerMuon_IsoTkMu24_IterTrk02", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "phiTriggerMuon_Mu17_Mu8", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "phiTriggerMuon_Mu17_TkMu8", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "phiTriggerMuon_Mu30_TkMu11", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "phiTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "phiTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "phiTriggerMuon_DoubleMu33NoFiltersNoVtx", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "phiTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "phiTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "phiTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "phiTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "phiTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT Muon phi", 64,-3.2,3.2);

  histos1D_[ "phiTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_Mu17_TkMu8" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_Mu30_TkMu11" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_Mu17_Mu8" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_IsoMu24_IterTrk02" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_Mu40" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT Muon #phi" );
  histos1D_[ "phiTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT Muon #phi" );

  histos1D_[ "phiTriggerMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "phiTriggerMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"beginJob1"<<std::endl;

  histos1D_[ "nGenMuons_Mu40" ] = fileService->make< TH1D >( "nGenMuons_Mu40", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "nGenMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "nGenMuons_DoubleMu33NoFiltersNoVtx", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "nGenMuons_DoubleMu23NoFiltersNoVtxDisplaced", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "nGenMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "nGenMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_Mu17_TkMu8" ] = fileService->make< TH1D >( "nGenMuons_Mu17_TkMu8", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_Mu30_TkMu11" ] = fileService->make< TH1D >( "nGenMuons_Mu30_TkMu11", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "nGenMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_Mu17_Mu8" ] = fileService->make< TH1D >( "nGenMuons_Mu17_Mu8", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "nGenMuons_IsoMu24_IterTrk02", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "nGenMuons_IsoTkMu24_IterTrk02", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "nGenMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "Number of generator muons", 10, 0., 10);
  histos1D_[ "nGenMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "nGenMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "Number of generator muons", 10, 0., 10);

  std::cout<<"beginJob1a"<<std::endl;

  histos1D_[ "nGenMuons_Mu40" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_Mu17_TkMu8" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_Mu30_TkMu11" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_Mu17_Mu8" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_IsoMu24_IterTrk02" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_IsoTkMu24_IterTrk02" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "Number of Generator Muons" );
  histos1D_[ "nGenMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "Number of Generator Muons" );

  std::cout<<"beginJob1b"<<std::endl;

  histos1D_[ "nGenMuons_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "nGenMuons_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"beginJob2"<<std::endl;

  histos1D_[ "ptGenMuon_Mu40" ] = fileService->make< TH1D >( "ptGenMuon_Mu40", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "ptGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "ptGenMuon_DoubleMu33NoFiltersNoVtx", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "ptGenMuon_DoubleMu23NoFiltersNoVtxDisplaced", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "ptGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "ptGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "ptGenMuon_Mu17_TkMu8", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "ptGenMuon_Mu30_TkMu11", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "ptGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "ptGenMuon_Mu17_Mu8", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "ptGenMuon_IsoMu24_IterTrk02", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "ptGenMuon_IsoTkMu24_IterTrk02", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "ptGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "Generator Muon pt", 100, 0., 1000);
  histos1D_[ "ptGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "ptGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "Generator Muon pt", 100, 0., 1000);

  histos1D_[ "ptGenMuon_Mu40" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_Mu17_TkMu8" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_Mu30_TkMu11" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_Mu17_Mu8" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_IsoMu24_IterTrk02" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );
  histos1D_[ "ptGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "Generator Muon p_{T} [GeV]" );

  histos1D_[ "ptGenMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "ptGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"beginJob3"<<std::endl;

  histos1D_[ "etaGenMuon_Mu40" ] = fileService->make< TH1D >( "etaGenMuon_Mu40", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >("etaGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >("etaGenMuon_DoubleMu33NoFiltersNoVtx", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "etaGenMuon_DoubleMu23NoFiltersNoVtxDisplaced", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "etaGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >("etaGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_Mu17_TkMu8" ] = fileService->make< TH1D >("etaGenMuon_Mu17_TkMu8", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "etaGenMuon_Mu30_TkMu11", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >("etaGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_Mu17_Mu8" ] = fileService->make< TH1D >("etaGenMuon_Mu17_Mu8", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "etaGenMuon_IsoMu24_IterTrk02", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "etaGenMuon_IsoTkMu24_IterTrk02", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "etaGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "Generator Muon eta", 120,-6,6);
  histos1D_[ "etaGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >("etaGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "Generator Muon eta", 120,-6,6);

  histos1D_[ "etaGenMuon_Mu40" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_Mu17_TkMu8" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_Mu30_TkMu11" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_Mu17_Mu8" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_IsoMu24_IterTrk02" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "Generator Muon #eta" );
  histos1D_[ "etaGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "Generator Muon #eta" );

  histos1D_[ "etaGenMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "etaGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  histos1D_[ "phiGenMuon_Mu40" ] = fileService->make< TH1D >( "phiGenMuon_Mu40", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "phiGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "phiGenMuon_DoubleMu33NoFiltersNoVtx", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "phiGenMuon_DoubleMu23NoFiltersNoVtxDisplaced", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "phiGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "phiGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "phiGenMuon_Mu17_TkMu8", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "phiGenMuon_Mu30_TkMu11", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "phiGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "phiGenMuon_Mu17_Mu8", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "phiGenMuon_IsoMu24_IterTrk02", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "phiGenMuon_IsoTkMu24_IterTrk02", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "phiGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "Generator Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "phiGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "Generator Muon phi", 64,-3.2,3.2);

  histos1D_[ "phiGenMuon_Mu40" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_Mu17_TkMu8" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_Mu30_TkMu11" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_Mu17_Mu8" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_IsoMu24_IterTrk02" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "Generator Muon #phi" );
  histos1D_[ "phiGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "Generator Muon #phi" );

  histos1D_[ "phiGenMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "phiGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  histos1D_[ "dxyGenMuon_Mu40" ] = fileService->make< TH1D >( "dxyGenMuon_Mu40", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "dxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "dxyGenMuon_DoubleMu33NoFiltersNoVtx", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "dxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "dxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "dxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "dxyGenMuon_Mu17_TkMu8", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "dxyGenMuon_Mu30_TkMu11", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "dxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "dxyGenMuon_Mu17_Mu8", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "dxyGenMuon_IsoMu24_IterTrk02", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "dxyGenMuon_IsoTkMu24_IterTrk02", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "dxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "Generator Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "dxyGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "Generator Muon dxy", 500, -1000, 1000);

  histos1D_[ "dxyGenMuon_Mu40" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_Mu17_TkMu8" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_Mu30_TkMu11" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_Mu17_Mu8" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_IsoMu24_IterTrk02" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "Generator Muon D_{xy}" );
  histos1D_[ "dxyGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "Generator Muon D_{xy}" );

  histos1D_[ "dxyGenMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "dxyGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  histos1D_[ "lxyGenMuon_Mu40" ] = fileService->make< TH1D >( "lxyGenMuon_Mu40", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "lxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "lxyGenMuon_DoubleMu33NoFiltersNoVtx", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "lxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "lxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "lxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_Mu17_TkMu8" ] = fileService->make< TH1D >( "lxyGenMuon_Mu17_TkMu8", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_Mu30_TkMu11" ] = fileService->make< TH1D >( "lxyGenMuon_Mu30_TkMu11", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "lxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_Mu17_Mu8" ] = fileService->make< TH1D >( "lxyGenMuon_Mu17_Mu8", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "lxyGenMuon_IsoMu24_IterTrk02", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "lxyGenMuon_IsoTkMu24_IterTrk02", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "lxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "Generator Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "lxyGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "Generator Muon lxy", 100, 0, 1000);

  histos1D_[ "lxyGenMuon_Mu40" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_Mu17_TkMu8" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_Mu30_TkMu11" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_Mu17_Mu8" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_IsoMu24_IterTrk02" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_IsoTkMu24_IterTrk02" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "Generator Muon L_{xy}" );
  histos1D_[ "lxyGenMuon_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "Generator Muon L_{xy}" );

  histos1D_[ "lxyGenMuon_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "lxyGenMuon_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"beginJob4"<<std::endl;

  histos1D_[ "nHltL2MuonTracks_Mu40" ] = fileService->make< TH1D >( "nHltL2MuonTracks_Mu40", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "nHltL2MuonTracks_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "nHltL2MuonTracks_DoubleMu33NoFiltersNoVtx", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "nHltL2MuonTracks_DoubleMu23NoFiltersNoVtxDisplaced", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "nHltL2MuonTracks_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "nHltL2MuonTracks_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_Mu17_TkMu8" ] = fileService->make< TH1D >( "nHltL2MuonTracks_Mu17_TkMu8", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_Mu30_TkMu11" ] = fileService->make< TH1D >( "nHltL2MuonTracks_Mu30_TkMu11", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "nHltL2MuonTracks_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_Mu17_Mu8" ] = fileService->make< TH1D >( "nHltL2MuonTracks_Mu17_Mu8", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "nHltL2MuonTracks_IsoMu24_IterTrk02", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "nHltL2MuonTracks_IsoTkMu24_IterTrk02", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "nHltL2MuonTracks_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "Number of HLT L2 muons", 10, 0., 10);
  histos1D_[ "nHltL2MuonTracks_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "nHltL2MuonTracks_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "Number of HLT L2 muons", 10, 0., 10);

  histos1D_[ "nHltL2MuonTracks_Mu40" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_Mu17_TkMu8" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_Mu30_TkMu11" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_Mu17_Mu8" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_IsoMu24_IterTrk02" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_IsoTkMu24_IterTrk02" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "Number of HLT L2 Muons" );
  histos1D_[ "nHltL2MuonTracks_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "Number of HLT L2 Muons" );

  histos1D_[ "nHltL2MuonTracks_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "nHltL2MuonTracks_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"beginJob5"<<std::endl;

  histos1D_[ "ptHltL2MuonTrack_Mu40" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_Mu40", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_DoubleMu33NoFiltersNoVtx", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_Mu17_TkMu8" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_Mu17_TkMu8", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_Mu30_TkMu11" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_Mu30_TkMu11", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_Mu17_Mu8" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_Mu17_Mu8", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_IsoMu24_IterTrk02", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_IsoTkMu24_IterTrk02", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT L2 Muon pt", 100, 0., 1000);
  histos1D_[ "ptHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "ptHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT L2 Muon pt", 100, 0., 1000);

  histos1D_[ "ptHltL2MuonTrack_Mu40" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_Mu17_TkMu8" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_Mu30_TkMu11" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_Mu17_Mu8" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );
  histos1D_[ "ptHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT L2 Muon p_{T} [GeV]" );

  histos1D_[ "ptHltL2MuonTrack_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "ptHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"beginJob6"<<std::endl;

  histos1D_[ "etaHltL2MuonTrack_Mu40" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_Mu40", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_DoubleMu33NoFiltersNoVtx", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_Mu17_TkMu8" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_Mu17_TkMu8", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_Mu30_TkMu11" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_Mu30_TkMu11", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_Mu17_Mu8" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_Mu17_Mu8", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_IsoMu24_IterTrk02", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_IsoTkMu24_IterTrk02", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT L2 Muon eta", 120,-6,6);
  histos1D_[ "etaHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "etaHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT L2 Muon eta", 120,-6,6);

  histos1D_[ "etaHltL2MuonTrack_Mu40" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_Mu17_TkMu8" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_Mu30_TkMu11" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_Mu17_Mu8" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT L2 Muon #eta" );
  histos1D_[ "etaHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT L2 Muon #eta" );

  histos1D_[ "etaHltL2MuonTrack_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "etaHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"beginJob7"<<std::endl;

  histos1D_[ "phiHltL2MuonTrack_Mu40" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_Mu40", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_DoubleMu33NoFiltersNoVtx", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_Mu17_TkMu8" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_Mu17_TkMu8", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_Mu30_TkMu11" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_Mu30_TkMu11", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_Mu17_Mu8" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_Mu17_Mu8", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_IsoMu24_IterTrk02", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_IsoTkMu24_IterTrk02", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT L2 Muon phi", 64,-3.2,3.2);
  histos1D_[ "phiHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "phiHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT L2 Muon phi", 64,-3.2,3.2);

  histos1D_[ "phiHltL2MuonTrack_Mu40" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_Mu17_TkMu8" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_Mu30_TkMu11" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_Mu17_Mu8" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT L2 Muon #phi" );
  histos1D_[ "phiHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT L2 Muon #phi" );

  histos1D_[ "phiHltL2MuonTrack_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "phiHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"beginJob8"<<std::endl;

  histos1D_[ "dxyHltL2MuonTrack_Mu40" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_Mu40", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_Mu17_TkMu8" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_Mu17_TkMu8", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_Mu30_TkMu11" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_Mu30_TkMu11", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_Mu17_Mu8" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_Mu17_Mu8", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_IsoMu24_IterTrk02", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_IsoTkMu24_IterTrk02", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT L2 Muon dxy", 500, -1000, 1000);
  histos1D_[ "dxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "dxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT L2 Muon dxy", 500, -1000, 1000);

  histos1D_[ "dxyHltL2MuonTrack_Mu40" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_Mu17_TkMu8" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_Mu30_TkMu11" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_Mu17_Mu8" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT L2 Muon D_{xy}" );
  histos1D_[ "dxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT L2 Muon D_{xy}" );

  histos1D_[ "dxyHltL2MuonTrack_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "dxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"beginJob9"<<std::endl;

  histos1D_[ "lxyHltL2MuonTrack_Mu40" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_Mu40", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_Mu17_TkMu8" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_Mu17_TkMu8", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_Mu30_TkMu11" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_Mu30_TkMu11", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_Mu17_Mu8" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_Mu17_Mu8", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_IsoMu24_IterTrk02" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_IsoMu24_IterTrk02", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_IsoTkMu24_IterTrk02" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_IsoTkMu24_IterTrk02", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL", "HLT L2 Muon lxy", 100, 0, 1000);
  histos1D_[ "lxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ] = fileService->make< TH1D >( "lxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL", "HLT L2 Muon lxy", 100, 0, 1000);

  histos1D_[ "lxyHltL2MuonTrack_Mu40" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_Mu17_TkMu8" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_Mu30_TkMu11" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_Mu17_Mu8" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetXTitle( "HLT L2 Muon L_{xy}" );
  histos1D_[ "lxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetXTitle( "HLT L2 Muon L_{xy}" );

  histos1D_[ "lxyHltL2MuonTrack_Mu40" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_DoubleMu23NoFiltersNoVtxDisplaced" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_Mu17_TkMu8" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_Mu30_TkMu11" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_Mu17_Mu8" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_IsoMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_IsoTkMu24_IterTrk02" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_Mu38NoFiltersNoVtx_Photon38_CaloIdL" ]->SetYTitle( "Events" );
  histos1D_[ "lxyHltL2MuonTrack_Mu28NoFiltersNoVtxDisplaced_Photon28_CaloIdL" ]->SetYTitle( "Events" );

  std::cout<<"ending beginJob!!!!"<<std::endl;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
HLTAnalyzer::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
/*
void 
HLTAnalyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a run  ------------
/*
void 
HLTAnalyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when starting to processes a luminosity block  ------------
/*
void 
HLTAnalyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method called when ending the processing of a luminosity block  ------------
/*
void 
HLTAnalyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}
*/

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
HLTAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  std::cout<<"starting fillDescriptions"<<std::endl;
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
  std::cout<<"finishing fillDescriptions"<<std::endl;
}

//define this as a plug-in
DEFINE_FWK_MODULE(HLTAnalyzer);
