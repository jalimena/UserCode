//makes histograms from ntuples

#include "iostream"
#include "string"
#include "sstream"
#include "cmath"
#include "vector"
#include "math.h"
#include "TROOT.h"
#include "TRint.h"
#include "TSystem.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TObject.h"
#include "TString.h"
#include "Riostream.h"
#include "StoppedHSCPMuonEvent.h"

using namespace std;

int main(int argc, char* argv[]){
  if(argc!=5){
    cout<<"ERROR, need more arguments!"<<endl;
    return 1;
  }

  cout<<"started function"<<endl;

  gSystem->Load("libStoppedHSCPMuonNtuples");
  cout<<"loaded library"<<endl;

  string file_dataset = "NoBPTX_Run2012B";
  string castor = "false";
  string bx_cut = "with_bx_cut";
  string other_cut = "with_other_cut";
  if(argc==5){
    cout<<"castor at first is: "<<castor<<endl;
    file_dataset = argv[1];
    castor = argv[2];
    bx_cut = argv[3];
    other_cut = argv[4];
    cout<<"castor is: "<<castor<<", file_dataset is: "<<file_dataset<<", bx_cut is: "<<bx_cut<<", phi_cut is: "<<other_cut<<endl;
  }
  

  TString file = "blah";
  if (castor=="true") file = "rfio:/castor/cern.ch/user/j/jalimena/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";
  if (castor=="false") file = "root://eoscms//eos/cms/store/user/jalimena/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";
  //file = "root://eoscms//eos/cms/store/user/jalimena/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";

  bool do_bx_cut = false;
  if (bx_cut=="with_bx_cut") do_bx_cut = true;
  if (bx_cut=="without_bx_cut") do_bx_cut = false;
  cout<<"do_bx_cut is: "<<do_bx_cut<<endl;

  bool do_other_cut = false;
  if (other_cut=="with_other_cut") do_other_cut = true;
  if (other_cut=="without_other_cut") do_other_cut = false;
  cout<<"do_other_cut is: "<<do_other_cut<<endl;

  cout<<"file is: "<<file<<endl;
  TFile* f1 = TFile::Open(file);
  cout<<"opened input file"<<endl;

  TString new_file = "blah2";
  if ((bx_cut=="with_bx_cut" || bx_cut=="without_bx_cut") && (other_cut=="with_other_cut" || other_cut=="without_other_cut")) new_file = "/afs/cern.ch/user/j/jalimena/public/histos/stoppedHSCPMuonHistos_" + file_dataset + "_" + bx_cut + "_" + other_cut + ".root";
  //if ((bx_cut=="with_bx_cut" || bx_cut=="without_bx_cut") && (other_cut=="with_other_cut" || other_cut=="without_other_cut")) new_file = "/afs/cern.ch/user/j/jalimena/public/histos/stoppedHSCPMuonHistos_" + file_dataset + "_" + bx_cut + "_" + other_cut + "_TEST.root";
  if (bx_cut!="with_bx_cut" && bx_cut!="without_bx_cut") cout<<"problem with bx_cut assignment!!!"<<endl;
  if (other_cut!="with_other_cut" && other_cut!="without_other_cut") cout<<"problem with other_cut assignment!!!"<<endl;

  TFile* fnew = new TFile(new_file, "recreate");
  cout<<"opened output file"<<endl;


  //get tree
  TTree* tree = (TTree*)f1->Get("stoppedHSCPMuonTree/StoppedHSCPMuonTree");
  //tree->Print();
  //tree->Show(0);

  //StoppedHSCPMuonEvent* events = new StoppedHSCPMuonEvent();
  StoppedHSCPMuonEvent* events = 0;

  // Declaration of leaf types
  UInt_t          rHadPdgId;
  Double_t        rHadVtxX;
  Double_t        rHadVtxY;
  Double_t        rHadVtxZ;
  Double_t        rHadVtxR;
  Double_t        rHadVtxT;
  Double_t        rHadE;
  Double_t        rHadPx;
  Double_t        rHadPy;
  Double_t        rHadPz;
  Double_t        rHadPt;
  UInt_t          mc_N;
  vector<UInt_t>  mcPDGid;
  vector<Double_t> mcVtxX;
  vector<Double_t> mcVtxY;
  vector<Double_t> mcVtxZ;
  vector<Double_t> mcVtxR;
  vector<Double_t> mcVtxT;
  vector<Double_t> mcE;
  vector<Double_t> mcPx;
  vector<Double_t> mcPy;
  vector<Double_t> mcPz;
  vector<Double_t> mcPt;
  ULong_t         id;
  ULong_t         bx;
  ULong_t         orbit;
  ULong_t         lb;
  ULong_t         run;
  ULong_t         fill;
  ULong_t         fillFromL1;
  ULong64_t       time;
  ULong64_t       time2;
  ULong64_t       time3;
  Long_t          bxAfterCollision;
  Long_t          bxBeforeCollision;
  Long_t          bxWrtCollision;
  Long_t          bxAfterBunch;
  Long_t          bxBeforeBunch;
  Long_t          bxWrtBunch;
  ULong64_t       gtAlgoWord0;
  ULong64_t       gtAlgoWord1;
  ULong64_t       gtTechWord;
  vector<UInt_t>  l1JetNoBptx;
  vector<UInt_t>  l1JetNoBptxNoHalo;
  vector<UInt_t>  l1Bptx;
  vector<UInt_t>  l1MuBeamHalo;
  Bool_t          hltJetNoBptx;
  Bool_t          hltJetNoBptxNoHalo;
  Bool_t          hltJetNoBptx3BXNoHalo;
  Bool_t          hltJetE50NoBptx3BXNoHalo;
  Bool_t          hltL2Mu20eta2p1NoVertex;
  Bool_t          hltL2Mu10NoVertexNoBptx3BX;
  Bool_t          hltL2Mu20NoVertexNoBptx3BX;
  Bool_t          hltL2Mu30NoVertexNoBptx3BX;
  Bool_t          hltL2Mu10NoVertexNoBptx3BXNoHalo;
  Bool_t          hltL2Mu20NoVertexNoBptx3BXNoHalo;
  Bool_t          hltL2Mu30NoVertexNoBptx3BXNoHalo;
  Bool_t          hltL2Mu20NoVertex2ChaNoBptx3BXNoHalo;
  Bool_t          hltL2Mu30NoVertex2ChaNoBptx3BXNoHalo;
  UInt_t          l1Jet_N;
  vector<UInt_t>  l1JetType;
  vector<Double_t> l1JetE;
  vector<Double_t> l1JetEt;
  vector<Double_t> l1JetEta;
  vector<Double_t> l1JetPhi;
  UInt_t          hltJet_N;
  vector<UInt_t>  hltJetType;
  vector<Double_t> hltJetE;
  vector<Double_t> hltJetEt;
  vector<Double_t> hltJetEta;
  vector<Double_t> hltJetPhi;
  UInt_t          jet_N;
  vector<Double_t> jetE;
  vector<Double_t> jetEt;
  vector<Double_t> jetEta;
  vector<Double_t> jetPhi;
  vector<Double_t> jetEHad;
  vector<Double_t> jetEEm;
  vector<Double_t> jetEMaxEcalTow;
  vector<Double_t> jetEMaxHcalTow;
  vector<UInt_t>  jetN60;
  vector<UInt_t>  jetN90;
  vector<Double_t> jetFHPD;
  vector<UInt_t>  jetN90Hits;
  UInt_t          jetAK5_N;
  vector<Double_t> jetAK5E;
  vector<Double_t> jetAK5Et;
  vector<Double_t> jetAK5Eta;
  vector<Double_t> jetAK5Phi;
  vector<Double_t> jetAK5EHad;
  vector<Double_t> jetAK5EEm;
  vector<Double_t> jetAK5EMaxEcalTow;
  vector<Double_t> jetAK5EMaxHcalTow;
  vector<UInt_t>  jetAK5N60;
  vector<UInt_t>  jetAK5N90;
  vector<Double_t> jetAK5FHPD;
  vector<UInt_t>  jetAK5N90Hits;
  UInt_t          mu_N;
  vector<UInt_t>  muType;
  vector<Double_t> muPt;
  vector<Double_t> muEta;
  vector<Double_t> muPhi;
  vector<Double_t> muHcalEta;
  vector<Double_t> muHcalPhi;
  vector<Double_t> muSumChargedHadronPt;
  vector<Double_t> muSumChargedParticlePt;
  vector<Double_t> muSumNeutralHadronEt;
  vector<Double_t> muSumPhotonEt;
  vector<Double_t> muSumNeutralHadronEtHighThreshold;
  vector<Double_t> muSumPhotonEtHighThreshold;
  vector<Double_t> muSumPUPt;
  vector<Double_t> muIso;
  UInt_t diMu_N;
  vector<Double_t> diMuMass;
  UInt_t mu_Cosmic_N;
  vector<UInt_t> muCosmicType;        // type of muon (standalone/global/cosmic/regular)
  vector<Double_t> muCosmicPt;
  vector<Double_t> muCosmicEta;
  vector<Double_t> muCosmicPhi;
  vector<Double_t> muCosmicHcalEta;     // track intersection with HCAL front-face (?)
  vector<Double_t> muCosmicHcalPhi;
  UInt_t mu_StandAlone_N;
  vector<Double_t> muStandAlonePt;
  vector<Double_t> muStandAloneEta;
  vector<Double_t> muStandAlonePhi;
  vector<Double_t> muStandAloneHcalEta;     // track intersection with HCAL front-face (?)
  vector<Double_t> muStandAloneHcalPhi;
  vector<Double_t> muStandAloneTrackChi2;
  vector<Double_t> muStandAloneTrackNdof;
  vector<Double_t> muStandAloneTrackNormalizedChi2;
  vector<Double_t> muStandAloneTrackDxy;
  vector<Double_t> muStandAloneTrackDz;
  vector<Int_t> muStandAloneTrackNHits;
  vector<Int_t> muStandAloneTrackNLost;
  vector<Int_t> muStandAloneTrackNHitsMuon;
  vector<Int_t> muStandAloneTrackNHitsCsc;
  vector<Int_t> muStandAloneTrackNHitsDt;
  vector<Int_t> muStandAloneTrackNHitsRpc;
  vector<Int_t> muStandAloneTrackNStations;
  vector<Int_t> muStandAloneTrackNChambersCsc;
  vector<Int_t> muStandAloneTrackNChambersDt;
  vector<Int_t> muStandAloneTrackNChambersRpc;
  vector<Double_t> muStandAloneTrackP;
  vector<Int_t> muStandAloneTrackQuality;
  vector< vector<Int_t> > muStandAloneTrackCscSegEndcap;
  vector< vector<Int_t> > muStandAloneTrackCscSegRing;
  vector< vector<Int_t> > muStandAloneTrackCscSegStation;
  vector< vector<Int_t> > muStandAloneTrackCscSegChamber;
  vector< vector<Int_t> > muStandAloneTrackCscSegNHits;
  vector< vector<Double_t> > muStandAloneTrackCscSegPhi;
  vector< vector<Double_t> > muStandAloneTrackCscSegZ;
  vector< vector<Double_t> > muStandAloneTrackCscSegR;
  vector< vector<Double_t> > muStandAloneTrackCscSegDirPhi;
  vector< vector<Double_t> > muStandAloneTrackCscSegDirTheta;
  vector< vector<Double_t> > muStandAloneTrackCscSegTime;
  vector< vector<Double_t> > muStandAloneTrackRpcHitZ;
  vector< vector<Double_t> > muStandAloneTrackRpcHitRho;
  vector< vector<Double_t> > muStandAloneTrackRpcHitPhi;
  vector< vector<Int_t> > muStandAloneTrackRpcHitRegion;
  vector< vector<Int_t> > muStandAloneTrackRpcHitBx;
  UInt_t mu_RefittedStandAlone_N;
  vector<Double_t> muRefittedStandAlonePt;
  vector<Double_t> muRefittedStandAloneEta;
  vector<Double_t> muRefittedStandAlonePhi;
  vector<Double_t> muRefittedStandAloneHcalEta;     // track intersection with HCAL front-face (?)
  vector<Double_t> muRefittedStandAloneHcalPhi;
  vector<Double_t> muRefittedStandAloneTrackChi2;
  vector<Double_t> muRefittedStandAloneTrackNdof;
  vector<Int_t> muRefittedStandAloneTrackNHits;
  vector<Int_t> muRefittedStandAloneTrackNLost;
  vector<Double_t> muRefittedStandAloneTrackP;
  vector<Int_t> muRefittedStandAloneTrackQuality;
  UInt_t          nVtx;
  UInt_t          vtx_N;
  vector<UInt_t>  vtxNDOF;
  vector<Double_t> vtxZ;
  vector<Double_t> vtxRho;
  UInt_t          track_N;
  Int_t muStandAloneTof_N;
  vector<Int_t>    muStandAloneTofDirection;
  vector<Double_t> muStandAloneTofNDof;
  vector<Double_t> muStandAloneTofInverseBeta;
  vector<Double_t> muStandAloneTofInverseBetaErr;
  vector<Double_t> muStandAloneTofFreeInverseBeta;
  vector<Double_t> muStandAloneTofFreeInverseBetaErr;
  vector<Double_t> muStandAloneTofTimeAtIpInOut;
  vector<Double_t> muStandAloneTofTimeAtIpInOutErr;
  vector<Double_t> muStandAloneTofTimeAtIpOutIn;
  vector<Double_t> muStandAloneTofTimeAtIpOutInErr;
  Int_t muStandAloneDTTof_N;
  vector<Int_t>    muStandAloneDTTofDirection;
  vector<Double_t> muStandAloneDTTofNDof;
  vector<Double_t> muStandAloneDTTofInverseBeta;
  vector<Double_t> muStandAloneDTTofInverseBetaErr;
  vector<Double_t> muStandAloneDTTofFreeInverseBeta;
  vector<Double_t> muStandAloneDTTofFreeInverseBetaErr;
  vector<Double_t> muStandAloneDTTofTimeAtIpInOut;
  vector<Double_t> muStandAloneDTTofTimeAtIpInOutErr;
  vector<Double_t> muStandAloneDTTofTimeAtIpOutIn;
  vector<Double_t> muStandAloneDTTofTimeAtIpOutInErr;
  Int_t muStandAloneCSCTof_N;
  vector<Int_t>    muStandAloneCSCTofDirection;
  vector<Double_t> muStandAloneCSCTofNDof;
  vector<Double_t> muStandAloneCSCTofInverseBeta;
  vector<Double_t> muStandAloneCSCTofInverseBetaErr;
  vector<Double_t> muStandAloneCSCTofFreeInverseBeta;
  vector<Double_t> muStandAloneCSCTofFreeInverseBetaErr;
  vector<Double_t> muStandAloneCSCTofTimeAtIpInOut;
  vector<Double_t> muStandAloneCSCTofTimeAtIpInOutErr;
  vector<Double_t> muStandAloneCSCTofTimeAtIpOutIn;
  vector<Double_t> muStandAloneCSCTofTimeAtIpOutInErr;
  Int_t refitMuStandAloneTof_N;
  vector<Int_t>    refitMuStandAloneTofDirection;
  vector<Double_t> refitMuStandAloneTofNDof;
  vector<Double_t> refitMuStandAloneTofInverseBeta;
  vector<Double_t> refitMuStandAloneTofInverseBetaErr;
  vector<Double_t> refitMuStandAloneTofFreeInverseBeta;
  vector<Double_t> refitMuStandAloneTofFreeInverseBetaErr;
  vector<Double_t> refitMuStandAloneTofTimeAtIpInOut;
  vector<Double_t> refitMuStandAloneTofTimeAtIpInOutErr;
  vector<Double_t> refitMuStandAloneTofTimeAtIpOutIn;
  vector<Double_t> refitMuStandAloneTofTimeAtIpOutInErr;
  Int_t refitMuStandAloneDTTof_N;
  vector<Int_t>    refitMuStandAloneDTTofDirection;
  vector<Double_t> refitMuStandAloneDTTofNDof;
  vector<Double_t> refitMuStandAloneDTTofInverseBeta;
  vector<Double_t> refitMuStandAloneDTTofInverseBetaErr;
  vector<Double_t> refitMuStandAloneDTTofFreeInverseBeta;
  vector<Double_t> refitMuStandAloneDTTofFreeInverseBetaErr;
  vector<Double_t> refitMuStandAloneDTTofTimeAtIpInOut;
  vector<Double_t> refitMuStandAloneDTTofTimeAtIpInOutErr;
  vector<Double_t> refitMuStandAloneDTTofTimeAtIpOutIn;
  vector<Double_t> refitMuStandAloneDTTofTimeAtIpOutInErr;
  Int_t refitMuStandAloneCSCTof_N;
  vector<Int_t>    refitMuStandAloneCSCTofDirection;
  vector<Double_t> refitMuStandAloneCSCTofNDof;
  vector<Double_t> refitMuStandAloneCSCTofInverseBeta;
  vector<Double_t> refitMuStandAloneCSCTofInverseBetaErr;
  vector<Double_t> refitMuStandAloneCSCTofFreeInverseBeta;
  vector<Double_t> refitMuStandAloneCSCTofFreeInverseBetaErr;
  vector<Double_t> refitMuStandAloneCSCTofTimeAtIpInOut;
  vector<Double_t> refitMuStandAloneCSCTofTimeAtIpInOutErr;
  vector<Double_t> refitMuStandAloneCSCTofTimeAtIpOutIn;
  vector<Double_t> refitMuStandAloneCSCTofTimeAtIpOutInErr;
  Bool_t          beamHalo_CSCTight;
  Bool_t          beamHalo_CSCLoose;
  Bool_t          beamHalo_HcalTight;
  Bool_t          beamHalo_HcalLoose;
  UInt_t          nTowerSameiPhi;
  UInt_t          nTowerLeadingIPhi;
  Double_t        eHadLeadingIPhi;
  Double_t        hfPlusTotalE;
  Double_t        hfMinusTotalE;
  Double_t        noiseMinE2Over10TS;
  Double_t        noiseMaxE2Over10TS;
  Int_t           noiseMaxHPDHits;
  Int_t           noiseMaxRBXHits;
  Int_t           noiseMaxHPDNoOtherHits;
  Int_t           noiseMaxZeros;
  Double_t        noiseMin25GeVHitTime;
  Double_t        noiseMax25GeVHitTime;
  Double_t        noiseMinRBXEMF;
  Bool_t          noiseFilterResult;
  Float_t         noiseEventEMEnergy;
  Float_t         noiseEventHadEnergy;
  Float_t         noiseEventTrackEnergy;
  Int_t           noiseNumProblematicRBXs;
  vector<double>  topHPD5TimeSamples;
  UInt_t          topHPD5PeakSample;
  Double_t        topHPD5Total;
  Double_t        topHPD5R1;
  Double_t        topHPD5R2;
  Double_t        topHPD5RPeak;
  Double_t        topHPD5ROuter;
  UInt_t          hpd_N;
  vector<UInt_t>  hpdId;
  vector<Double_t> hpdEta;
  vector<Double_t> hpdPhi;
  vector<UInt_t>  hpdTotalZeros;
  vector<UInt_t>  hpdMaxZeros;
  vector<UInt_t>  hpdNJet;
  vector<Double_t> hpdFc0;
  vector<Double_t> hpdFc1;
  vector<Double_t> hpdFc2;
  vector<Double_t> hpdFc3;
  vector<Double_t> hpdFc4;
  vector<Double_t> hpdFc5;
  vector<Double_t> hpdFc6;
  vector<Double_t> hpdFc7;
  vector<Double_t> hpdFc8;
  vector<Double_t> hpdFc9;
  vector<Double_t> hpdFc5_0;
  vector<Double_t> hpdFc5_1;
  vector<Double_t> hpdFc5_2;
  vector<Double_t> hpdFc5_3;
  vector<Double_t> hpdFc5_4;
  vector<Double_t> hpdFc5_5;
  vector<Double_t> hpdFc5_6;
  vector<Double_t> hpdFc5_7;
  vector<Double_t> hpdFc5_8;
  vector<Double_t> hpdFc5_9;
  UInt_t          tower_N;
  vector<Double_t> towerE;
  vector<Double_t> towerEt;
  vector<Double_t> towerEta;
  vector<Double_t> towerPhi;
  vector<Int_t>   towerIEta;
  vector<Int_t>   towerIPhi;
  vector<UInt_t>  towerNJet;
  vector<Double_t> towerEHad;
  vector<Double_t> towerEtHad;
  vector<Double_t> towerEEm;
  vector<Double_t> towerEtEm;
  UInt_t          recHit_N;
  vector<Double_t> recHitE;
  vector<Double_t> recHitTime;
  vector<UInt_t>  recHitFlags;
  vector<UInt_t>  recHitAux;
  vector<Double_t> recHitEta;
  vector<Double_t> recHitPhi;
  vector<Int_t>   recHitIEta;
  vector<Int_t>   recHitIPhi;
  vector<Int_t>   recHitDepth;
  vector<Int_t>   recHitRBXindex;
  vector<Int_t>   recHitRMindex;
  UInt_t          hfRecHit_N;
  vector<Double_t> hfRecHitE;
  UInt_t          cscSeg_N;
  vector<Int_t>   cscSegEndcap;
  vector<Int_t>   cscSegRing;
  vector<Int_t>   cscSegStation;
  vector<Int_t>   cscSegChamber;
  vector<UInt_t>  cscSegNHits;
  vector<Double_t> cscSegPhi;
  vector<Double_t> cscSegZ;
  vector<Double_t> cscSegR;
  vector<Double_t> cscSegDirPhi;
  vector<Double_t> cscSegDirTheta;
  UInt_t          DTSegment_N;
  vector<Int_t> DTSegWheel;
  vector<Int_t> DTSegStation;
  vector<Int_t> DTSegSector;
  vector<Double_t> DTSegLocalX;
  vector<Double_t> DTSegLocalY;
  vector<Double_t> DTSegZ;
  vector<Double_t> DTSegRho;
  vector<Double_t> DTSegPhi;
  Int_t           leadingDigiIEta;
  Int_t           leadingDigiIPhi;
  vector<double>  leadingDigiTimeSamples;
  UInt_t          leadingDigiPeakSample;
  Double_t        leadingDigiTotal;
  Double_t        leadingDigiR1;
  Double_t        leadingDigiR2;
  Double_t        leadingDigiRPeak;
  Double_t        leadingDigiROuter;
  vector<double>  top5DigiTimeSamples;
  UInt_t          top5DigiPeakSample;
  Double_t        top5DigiTotal;
  Double_t        top5DigiR1;
  Double_t        top5DigiR2;
  Double_t        top5DigiRPeak;
  Double_t        top5DigiROuter;

  //set old branch address
  tree->SetBranchAddress("events",&events);

  //define histograms
  TH1D* id_hist = new TH1D("id_hist","Event Number",100000,0,100000);
  TH1D* run_hist = new TH1D("run_hist","Run Number",8000,192000,200000);
  TH1D* bx_hist = new TH1D("bx_hist","BX",8000,0,4000);
  TH1D* bxWrtCollision_hist = new TH1D("bxWrtCollision_hist","BX w.r.t. Collision",4000,-1000,1000);
  TH1D* bxWrtBunch_hist = new TH1D("bxWrtBunch_hist","BX w.r.t. Bunch",4000,-1000,1000);

  TH1D* mu_N_hist = new TH1D("mu_N_hist","Number of Muons",100,0,100);
  TH1D* muPt_hist = new TH1D("muPt_hist","Reco Muon p_{T}",200,0,200);
  TH1D* muEta_hist = new TH1D("muEta_hist","Reco Muon #eta",120,-6,6);
  TH1D* muPhi_hist = new TH1D("muPhi_hist","Reco Muon #phi",64,-6.2832,6.2832);
  TH1D* muType_hist = new TH1D("muType_hist","Reco Muon Type",4000,0,4000);
  TH1D* muIso_hist = new TH1D("muIso_hist","Reco Muon Isolation",1000,0,1000);
  TH2D* muEta_muPhi_hist = new TH2D("muEta_muPhi_hist","Reco Muon #eta vs #phi",120,-6,6,64,-6.2832,6.2832);

  TH1D* diMu_N_hist = new TH1D("diMu_N_hist","Number of DiMuons",100,0,100);
  TH1D* diMuMass_hist = new TH1D("diMuMass_hist","Reco Muon Invaraint Mass",1000,0,1000);

  TH1D* muCosmic_N_hist = new TH1D("muCosmic_N_hist","Number of Cosmic Muons",100,0,100);
  TH1D* muCosmicPt_hist = new TH1D("muCosmicPt_hist","Cosmic Muon p_{T}",200,0,200);
  TH1D* muCosmicEta_hist = new TH1D("muCosmicEta_hist","Cosmic Muon #eta",120,-6,6);
  TH1D* muCosmicPhi_hist = new TH1D("muCosmicPhi_hist","Cosmic Muon #phi",64,-6.2832,6.2832);
  TH1D* muCosmicType_hist = new TH1D("muCosmicType_hist","Cosmic Muon Type",4000,0,4000);
  TH2D* muCosmicEta_muCosmicPhi_hist = new TH2D("muCosmicEta_muCosmicPhi_hist","Cosmic Muon #eta vs #phi",120,-6,6,64,-6.2832,6.2832);

  TH1D* muStandAlone_N_other_cut_hist = new TH1D("muStandAlone_N_other_cut_hist","Number of StandAlone Muons with #phi>0 and >1 stations",100,0,100);

  TH1D* muStandAlone_N_hist = new TH1D("muStandAlone_N_hist","Number of StandAlone Muons",100,0,100);
  TH1D* muStandAlonePt_hist = new TH1D("muStandAlonePt_hist","StandAlone Muon p_{T}",200,0,200);
  TH1D* muStandAloneEta_hist = new TH1D("muStandAloneEta_hist","StandAlone Muon #eta",120,-6,6);
  TH1D* muStandAlonePhi_hist = new TH1D("muStandAlonePhi_hist","StandAlone Muon #phi",64,-6.2832,6.2832);
  TH1D* muStandAloneTrackNormalizedChi2_hist = new TH1D("muStandAloneTrackNormalizedChi2_hist","StandAlone Muon Track #chi^{2}/dof",1000,0,100);
  TH1D* muStandAloneTrackDxy_hist = new TH1D("muStandAloneTrackDxy_hist","StandAlone Muon Dxy",200,-100,100);
  TH1D* muStandAloneTrackDz_hist = new TH1D("muStandAloneTrackDz_hist","StandAlone Muon Dz",200,-100,100);
  TH1D* muStandAloneTrackNHitsMuon_hist = new TH1D("muStandAloneTrackNHitsMuon_hist","Hits in StandAlone Muon Track",100,0,100);
  TH1D* muStandAloneTrackNHitsCsc_hist = new TH1D("muStandAloneTrackNHitsCsc_hist","CSC Hits in StandAlone Muon Track",100,0,100);
  TH1D* muStandAloneTrackNHitsDt_hist = new TH1D("muStandAloneTrackNHitsDt_hist","DT Hits in StandAlone Muon Track",100,0,100);
  TH1D* muStandAloneTrackNHitsRpc_hist = new TH1D("muStandAloneTrackNHitsRpc_hist","RPC Hits in StandAlone Muon Track",10,0,10);
  TH1D* muStandAloneTrackNStations_hist = new TH1D("muStandAloneTrackNStations_hist","Muon Stations in StandAlone Muon Track",10,0,10);
  TH1D* muStandAloneTrackNChambersCsc_hist = new TH1D("muStandAloneTrackNChambersCsc_hist","CSC Chambers in StandAlone Muon Track",10,0,10);
  TH1D* muStandAloneTrackNChambersDt_hist = new TH1D("muStandAloneTrackNChambersDt_hist","DT Chambers in StandAlone Muon Track",10,0,10);
  TH1D* muStandAloneTrackNChambersRpc_hist = new TH1D("muStandAloneTrackNChambersRpc_hist","RPC Chambers in StandAlone Muon Track",10,0,10);
  //vector< vector<Int_t> > muStandAloneTrackCscSegEndcap;
  //vector< vector<Int_t> > muStandAloneTrackCscSegRing;
  //vector< vector<Int_t> > muStandAloneTrackCscSegStation;
  //vector< vector<Int_t> > muStandAloneTrackCscSegChamber;
  //vector< vector<Int_t> > muStandAloneTrackCscSegNHits;
  //vector< vector<Double_t> > muStandAloneTrackCscSegPhi;
  //vector< vector<Double_t> > muStandAloneTrackCscSegZ;
  //vector< vector<Double_t> > muStandAloneTrackCscSegR;
  //vector< vector<Double_t> > muStandAloneTrackCscSegDirPhi;
  //vector< vector<Double_t> > muStandAloneTrackCscSegDirTheta;
  //vector< vector<Int_t> > muStandAloneTrackCscSegNHits;
  //vector< vector<Double_t> > muStandAloneTrackCscSegPhi;
  //vector< vector<Double_t> > muStandAloneTrackCscSegZ;
  //vector< vector<Double_t> > muStandAloneTrackCscSegR;
  //vector< vector<Double_t> > muStandAloneTrackCscSegDirPhi;
  //vector< vector<Double_t> > muStandAloneTrackCscSegDirTheta;
  //vector< vector<Double_t> > muStandAloneTrackCscSegTime;
  //vector< vector<Double_t> > muStandAloneTrackRpcHitZ;
  //vector< vector<Double_t> > muStandAloneTrackRpcHitRho;
  //vector< vector<Double_t> > muStandAloneTrackRpcHitPhi;
  //vector< vector<Int_t> > muStandAloneTrackRpcHitRegion;
  //vector< vector<Int_t> > muStandAloneTrackRpcHitBx;
  TH2D* muStandAloneEta_muStandAlonePhi_hist = new TH2D("muStandAloneEta_muStandAlonePhi_hist","StandAlone Muon #eta vs #phi",120,-6,6,64,-6.2832,6.2832);
  TH2D* muStandAloneTrackNHitsRpc_muStandAloneTrackNormalizedChi2_hist = new TH2D("muStandAloneTrackNHitsRpc_muStandAloneTrackNormalizedChi2_hist","RPC Hits vs Track #chi^{2}/dof",10,0,10,100,0,100);
  TH2D* muStandAloneTrackNHitsRpc_muStandAloneTrackNHitsDt_hist = new TH2D("muStandAloneTrackNHitsRpc_muStandAloneTrackNHitsDt_hist","RPC Hits vs DT Hits",10,0,10,100,0,100);

  TH1D* mu0_StandAlone_N_hist = new TH1D("mu0_StandAlone_N_hist","Number of StandAlone Muons",100,0,100);
  TH1D* mu0_StandAlonePt_hist = new TH1D("mu0_StandAlonePt_hist","StandAlone Muon p_{T}",200,0,200);
  TH1D* mu0_StandAloneEta_hist = new TH1D("mu0_StandAloneEta_hist","StandAlone Muon #eta",120,-6,6);
  TH1D* mu0_StandAlonePhi_hist = new TH1D("mu0_StandAlonePhi_hist","StandAlone Muon #phi",64,-6.2832,6.2832);
  TH1D* mu0_StandAloneTrackNormalizedChi2_hist = new TH1D("mu0_StandAloneTrackNormalizedChi2_hist","StandAlone Muon Track #chi^{2}/dof",1000,0,100);
  TH1D* mu0_StandAloneTrackDxy_hist = new TH1D("mu0_StandAloneTrackDxy_hist","StandAlone Muon Dxy",200,-100,100);
  TH1D* mu0_StandAloneTrackDz_hist = new TH1D("mu0_StandAloneTrackDz_hist","StandAlone Muon Dz",200,-100,100);
  TH1D* mu0_StandAloneTrackNHitsMuon_hist = new TH1D("mu0_StandAloneTrackNHitsMuon_hist","Hits in StandAlone Muon Track",100,0,100);
  TH1D* mu0_StandAloneTrackNHitsCsc_hist = new TH1D("mu0_StandAloneTrackNHitsCsc_hist","CSC Hits in StandAlone Muon Track",100,0,100);
  TH1D* mu0_StandAloneTrackNHitsDt_hist = new TH1D("mu0_StandAloneTrackNHitsDt_hist","DT Hits in StandAlone Muon Track",100,0,100);
  TH1D* mu0_StandAloneTrackNHitsRpc_hist = new TH1D("mu0_StandAloneTrackNHitsRpc_hist","RPC Hits in StandAlone Muon Track",10,0,10);
  TH1D* mu0_StandAloneTrackNStations_hist = new TH1D("mu0_StandAloneTrackNStations_hist","Muon Stations in StandAlone Muon Track",10,0,10);
  TH1D* mu0_StandAloneTrackNChambersCsc_hist = new TH1D("mu0_StandAloneTrackNChambersCsc_hist","CSC Chambers in StandAlone Muon Track",10,0,10);
  TH1D* mu0_StandAloneTrackNChambersDt_hist = new TH1D("mu0_StandAloneTrackNChambersDt_hist","DT Chambers in StandAlone Muon Track",10,0,10);
  TH1D* mu0_StandAloneTrackNChambersRpc_hist = new TH1D("mu0_StandAloneTrackNChambersRpc_hist","RPC Chambers in StandAlone Muon Track",10,0,10);
  TH2D* mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNormalizedChi2_hist = new TH2D("mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNormalizedChi2_hist","RPC Hits vs Track #chi^{2}/dof",10,0,10,100,0,100);
  TH2D* mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNHitsDt_hist = new TH2D("mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNHitsDt_hist","RPC Hits vs DT Hits",10,0,10,100,0,100);

  TH1D* mu1_StandAlone_N_hist = new TH1D("mu1_StandAlone_N_hist","Number of StandAlone Muons",100,0,100);
  TH1D* mu1_StandAlonePt_hist = new TH1D("mu1_StandAlonePt_hist","StandAlone Muon p_{T}",200,0,200);
  TH1D* mu1_StandAloneEta_hist = new TH1D("mu1_StandAloneEta_hist","StandAlone Muon #eta",120,-6,6);
  TH1D* mu1_StandAlonePhi_hist = new TH1D("mu1_StandAlonePhi_hist","StandAlone Muon #phi",64,-6.2832,6.2832);
  TH1D* mu1_StandAloneTrackNormalizedChi2_hist = new TH1D("mu1_StandAloneTrackNormalizedChi2_hist","StandAlone Muon Track #chi^{2}/dof",1000,0,100);
  TH1D* mu1_StandAloneTrackDxy_hist = new TH1D("mu1_StandAloneTrackDxy_hist","StandAlone Muon Dxy",200,-100,100);
  TH1D* mu1_StandAloneTrackDz_hist = new TH1D("mu1_StandAloneTrackDz_hist","StandAlone Muon Dz",200,-100,100);
  TH1D* mu1_StandAloneTrackNHitsMuon_hist = new TH1D("mu1_StandAloneTrackNHitsMuon_hist","Hits in StandAlone Muon Track",100,0,100);
  TH1D* mu1_StandAloneTrackNHitsCsc_hist = new TH1D("mu1_StandAloneTrackNHitsCsc_hist","CSC Hits in StandAlone Muon Track",100,0,100);
  TH1D* mu1_StandAloneTrackNHitsDt_hist = new TH1D("mu1_StandAloneTrackNHitsDt_hist","DT Hits in StandAlone Muon Track",100,0,100);
  TH1D* mu1_StandAloneTrackNHitsRpc_hist = new TH1D("mu1_StandAloneTrackNHitsRpc_hist","RPC Hits in StandAlone Muon Track",10,0,10);
  TH1D* mu1_StandAloneTrackNStations_hist = new TH1D("mu1_StandAloneTrackNStations_hist","Muon Stations in StandAlone Muon Track",10,0,10);
  TH1D* mu1_StandAloneTrackNChambersCsc_hist = new TH1D("mu1_StandAloneTrackNChambersCsc_hist","CSC Chambers in StandAlone Muon Track",10,0,10);
  TH1D* mu1_StandAloneTrackNChambersDt_hist = new TH1D("mu1_StandAloneTrackNChambersDt_hist","DT Chambers in StandAlone Muon Track",10,0,10);
  TH1D* mu1_StandAloneTrackNChambersRpc_hist = new TH1D("mu1_StandAloneTrackNChambersRpc_hist","RPC Chambers in StandAlone Muon Track",10,0,10);
  TH2D* mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNormalizedChi2_hist = new TH2D("mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNormalizedChi2_hist","RPC Hits vs Track #chi^{2}/dof",10,0,10,100,0,100);
  TH2D* mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNHitsDt_hist = new TH2D("mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNHitsDt_hist","RPC Hits vs DT Hits",10,0,10,100,0,100);

  TH1D* muRefittedStandAlone_N_hist = new TH1D("muRefittedStandAlone_N_hist","Number of Refitted StandAlone Muons",100,0,100);
  TH1D* muRefittedStandAlonePt_hist = new TH1D("muRefittedStandAlonePt_hist","Refitted StandAlone Muon p_{T}",200,0,200);
  TH1D* muRefittedStandAloneEta_hist = new TH1D("muRefittedStandAloneEta_hist","Refitted StandAlone Muon #eta",120,-6,6);
  TH1D* muRefittedStandAlonePhi_hist = new TH1D("muRefittedStandAlonePhi_hist","Refitted StandAlone Muon #phi",64,-6.2832,6.2832);
  TH2D* muRefittedStandAloneEta_muRefittedStandAlonePhi_hist = new TH2D("muRefittedStandAloneEta_muRefittedStandAlonePhi_hist","Refitted StandAlone Muon #eta vs #phi",120,-6,6,64,-6.2832,6.2832);

  TH1D* muStandAloneTof_N_hist = new TH1D("muStandAloneTof_N_hist","Number of StandAlone Muons in TOF Calculation",100,0,100);
  TH1D* muStandAloneTofDirection_hist = new TH1D("muStandAloneTofDirection_hist","Direction of StandAlone Muons",3,-1,2);
  TH1D* muStandAloneTofNDof_hist = new TH1D("muStandAloneTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom",200,0,200);
  TH1D* muStandAloneTofInverseBeta_hist = new TH1D("muStandAloneTofInverseBeta_hist","#beta^{-1} of StandAlone Muons",1000,-5,5);
  TH1D* muStandAloneTofInverseBetaErr_hist = new TH1D("muStandAloneTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneTofFreeInverseBeta_hist = new TH1D("muStandAloneTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons",1000,-50,50);
  TH1D* muStandAloneTofFreeInverseBetaErr_hist = new TH1D("muStandAloneTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneTofTimeAtIpInOut_hist = new TH1D("muStandAloneTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons",300,-50,100);
  TH1D* muStandAloneTofTimeAtIpInOutErr_hist = new TH1D("muStandAloneTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons",100,0,20);
  TH1D* muStandAloneTofTimeAtIpOutIn_hist = new TH1D("muStandAloneTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons",300,0,150);
  TH1D* muStandAloneTofTimeAtIpOutInErr_hist = new TH1D("muStandAloneTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons",100,0,20);

  TH1D* muStandAloneDTTof_N_hist = new TH1D("muStandAloneDTTof_N_hist","Number of StandAlone Muons in TOF Calculation",100,0,100);
  TH1D* muStandAloneDTTofDirection_hist = new TH1D("muStandAloneDTTofDirection_hist","Direction of StandAlone Muons",3,-1,2);
  TH1D* muStandAloneDTTofNDof_hist = new TH1D("muStandAloneDTTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom",200,0,200);
  TH1D* muStandAloneDTTofInverseBeta_hist = new TH1D("muStandAloneDTTofInverseBeta_hist","#beta^{-1} of StandAlone Muons",1000,-5,5);
  TH1D* muStandAloneDTTofInverseBetaErr_hist = new TH1D("muStandAloneDTTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneDTTofFreeInverseBeta_hist = new TH1D("muStandAloneDTTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons",1000,-50,50);
  TH1D* muStandAloneDTTofFreeInverseBetaErr_hist = new TH1D("muStandAloneDTTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneDTTofTimeAtIpInOut_hist = new TH1D("muStandAloneDTTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons",300,-50,100);
  TH1D* muStandAloneDTTofTimeAtIpInOutErr_hist = new TH1D("muStandAloneDTTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons",100,0,20);
  TH1D* muStandAloneDTTofTimeAtIpOutIn_hist = new TH1D("muStandAloneDTTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons",300,0,150);
  TH1D* muStandAloneDTTofTimeAtIpOutInErr_hist = new TH1D("muStandAloneDTTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons",100,0,20);

  TH1D* muStandAloneCSCTof_N_hist = new TH1D("muStandAloneCSCTof_N_hist","Number of StandAlone Muons in TOF Calculation",100,0,100);
  TH1D* muStandAloneCSCTofDirection_hist = new TH1D("muStandAloneCSCTofDirection_hist","Direction of StandAlone Muons",3,-1,2);
  TH1D* muStandAloneCSCTofNDof_hist = new TH1D("muStandAloneCSCTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom",200,0,200);
  TH1D* muStandAloneCSCTofInverseBeta_hist = new TH1D("muStandAloneCSCTofInverseBeta_hist","#beta^{-1} of StandAlone Muons",1000,-5,5);
  TH1D* muStandAloneCSCTofInverseBetaErr_hist = new TH1D("muStandAloneCSCTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneCSCTofFreeInverseBeta_hist = new TH1D("muStandAloneCSCTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons",1000,-50,50);
  TH1D* muStandAloneCSCTofFreeInverseBetaErr_hist = new TH1D("muStandAloneCSCTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneCSCTofTimeAtIpInOut_hist = new TH1D("muStandAloneCSCTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons",300,-50,100);
  TH1D* muStandAloneCSCTofTimeAtIpInOutErr_hist = new TH1D("muStandAloneCSCTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons",100,0,20);
  TH1D* muStandAloneCSCTofTimeAtIpOutIn_hist = new TH1D("muStandAloneCSCTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons",300,0,150);
  TH1D* muStandAloneCSCTofTimeAtIpOutInErr_hist = new TH1D("muStandAloneCSCTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons",100,0,20);

  TH1D* refitMuStandAloneTof_N_hist = new TH1D("refitMuStandAloneTof_N_hist","Number of StandAlone Muons in TOF Calculation with recoed DTs",100,0,100);
  TH1D* refitMuStandAloneTofDirection_hist = new TH1D("refitMuStandAloneTofDirection_hist","Direction of StandAlone Muons with recoed DTs",3,-1,2);
  TH1D* refitMuStandAloneTofNDof_hist = new TH1D("refitMuStandAloneTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom with recoed DTs",200,0,200);
  TH1D* refitMuStandAloneTofInverseBeta_hist = new TH1D("refitMuStandAloneTofInverseBeta_hist","#beta^{-1} of StandAlone Muons with recoed DTs",1000,-5,5);
  TH1D* refitMuStandAloneTofInverseBetaErr_hist = new TH1D("refitMuStandAloneTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneTofFreeInverseBeta_hist = new TH1D("refitMuStandAloneTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons with recoed DTs",1000,-50,50);
  TH1D* refitMuStandAloneTofFreeInverseBetaErr_hist = new TH1D("refitMuStandAloneTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneTofTimeAtIpInOut_hist = new TH1D("refitMuStandAloneTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons with recoed DTs",300,-50,100);
  TH1D* refitMuStandAloneTofTimeAtIpInOutErr_hist = new TH1D("refitMuStandAloneTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons with recoed DTs",100,0,20);
  TH1D* refitMuStandAloneTofTimeAtIpOutIn_hist = new TH1D("refitMuStandAloneTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons with recoed DTs",300,0,150);
  TH1D* refitMuStandAloneTofTimeAtIpOutInErr_hist = new TH1D("refitMuStandAloneTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons with recoed DTs",100,0,20);

  TH1D* refitMuStandAloneDTTof_N_hist = new TH1D("refitMuStandAloneDTTof_N_hist","Number of StandAlone Muons in TOF Calculation with recoed DTs",100,0,100);
  TH1D* refitMuStandAloneDTTofDirection_hist = new TH1D("refitMuStandAloneDTTofDirection_hist","Direction of StandAlone Muons with recoed DTs",3,-1,2);
  TH1D* refitMuStandAloneDTTofNDof_hist = new TH1D("refitMuStandAloneDTTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom with recoed DTs",200,0,200);
  TH1D* refitMuStandAloneDTTofInverseBeta_hist = new TH1D("refitMuStandAloneDTTofInverseBeta_hist","#beta^{-1} of StandAlone Muons with recoed DTs",1000,-5,5);
  TH1D* refitMuStandAloneDTTofInverseBetaErr_hist = new TH1D("refitMuStandAloneDTTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneDTTofFreeInverseBeta_hist = new TH1D("refitMuStandAloneDTTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons with recoed DTs",1000,-50,50);
  TH1D* refitMuStandAloneDTTofFreeInverseBetaErr_hist = new TH1D("refitMuStandAloneDTTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneDTTofTimeAtIpInOut_hist = new TH1D("refitMuStandAloneDTTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons with recoed DTs",300,-50,100);
  TH1D* refitMuStandAloneDTTofTimeAtIpInOutErr_hist = new TH1D("refitMuStandAloneDTTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons with recoed DTs",100,0,20);
  TH1D* refitMuStandAloneDTTofTimeAtIpOutIn_hist = new TH1D("refitMuStandAloneDTTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons with recoed DTs",300,0,150);
  TH1D* refitMuStandAloneDTTofTimeAtIpOutInErr_hist = new TH1D("refitMuStandAloneDTTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons with recoed DTs",100,0,20);

  TH1D* refitMuStandAloneCSCTof_N_hist = new TH1D("refitMuStandAloneCSCTof_N_hist","Number of StandAlone Muons in TOF Calculation with recoed DTs",100,0,100);
  TH1D* refitMuStandAloneCSCTofDirection_hist = new TH1D("refitMuStandAloneCSCTofDirection_hist","Direction of StandAlone Muons with recoed DTs",3,-1,2);
  TH1D* refitMuStandAloneCSCTofNDof_hist = new TH1D("refitMuStandAloneCSCTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom with recoed DTs",200,0,200);
  TH1D* refitMuStandAloneCSCTofInverseBeta_hist = new TH1D("refitMuStandAloneCSCTofInverseBeta_hist","#beta^{-1} of StandAlone Muons with recoed DTs",1000,-5,5);
  TH1D* refitMuStandAloneCSCTofInverseBetaErr_hist = new TH1D("refitMuStandAloneCSCTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneCSCTofFreeInverseBeta_hist = new TH1D("refitMuStandAloneCSCTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons with recoed DTs",1000,-50,50);
  TH1D* refitMuStandAloneCSCTofFreeInverseBetaErr_hist = new TH1D("refitMuStandAloneCSCTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneCSCTofTimeAtIpInOut_hist = new TH1D("refitMuStandAloneCSCTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons with recoed DTs",300,-50,100);
  TH1D* refitMuStandAloneCSCTofTimeAtIpInOutErr_hist = new TH1D("refitMuStandAloneCSCTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons with recoed DTs",100,0,20);
  TH1D* refitMuStandAloneCSCTofTimeAtIpOutIn_hist = new TH1D("refitMuStandAloneCSCTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons with recoed DTs",300,0,150);
  TH1D* refitMuStandAloneCSCTofTimeAtIpOutInErr_hist = new TH1D("refitMuStandAloneCSCTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons with recoed DTs",100,0,20);

  TH1D* DTSegment_N_hist = new TH1D("DTSegment_N_hist","Number of DT Segments",100,0,100);

  TH1D* mu0_StandAloneTofTimeAtIpInOut_hist = new TH1D("mu0_StandAloneTofTimeAtIpInOut_hist","Time at IP InOut of First StandAlone Muon",300,-50,100);
  TH1D* mu0_StandAloneTofTimeAtIpOutIn_hist = new TH1D("mu0_StandAloneTofTimeAtIpOutIn_hist","Time at IP OutIn of First StandAlone Muon",300,0,150);
  TH1D* mu1_StandAloneTofTimeAtIpInOut_hist = new TH1D("mu1_StandAloneTofTimeAtIpInOut_hist","Time at IP InOut of Second StandAlone Muon",300,-50,100);
  TH1D* mu1_StandAloneTofTimeAtIpOutIn_hist = new TH1D("mu1_StandAloneTofTimeAtIpOutIn_hist","Time at IP OutIn of Second StandAlone Muon",300,0,150);
  TH1D* mudiff_StandAloneTofTimeAtIpInOut_hist = new TH1D("mudiff_StandAloneTofTimeAtIpInOut_hist","Time at IP InOut of First minus Second StandAlone Muon",300,-50,100);
  TH1D* mudiff_StandAloneTofTimeAtIpOutIn_hist = new TH1D("mudiff_StandAloneTofTimeAtIpOutIn_hist","Time at IP OutIn of First minus Second StandAlone Muon",300,0,150);
  TH2D* mu0_mu1_StandAloneTofTimeAtIpInOut_hist = new TH2D("mu0_mu1_StandAloneTofTimeAtIpInOut_hist","Time at IP InOut of First vs Second StandAlone Muon",300,-50,100,300,-50,100);
  TH2D* mu0_mu1_StandAloneTofTimeAtIpOutIn_hist = new TH2D("mu0_mu1_StandAloneTofTimeAtIpOutIn_hist","Time at IP OutIn of First vs Second StandAlone Muon",300,0,150,300,0,150);

  //get entries for data_tree (read in the old tree), set new variables, fill new tree
  Int_t nentries = tree->GetEntriesFast();
  //Int_t nentries = tree->GetEntries();
  cout<<"number of entries is: "<<nentries<<endl;
  
  int pass_bx_cut = 0;
  int pass_trigger_cut = 0;

  int pass_atleast1SA_cut = 0;
  int pass_pt30_cut = 0;
  int pass_eta2p1_cut = 0;
  int pass_eta1p0_cut = 0;

  int events_pass_other_cut = 0;
  int events_1muon_pass_other_cut_with_rpcs = 0;
  int events_2muon_muon0_pass_other_cut_with_rpcs = 0;
  int events_2muon_muon1_pass_other_cut_with_rpcs = 0;

  int singlemuon_0BX = 0;
  int singlemuon_positiveConstantBX = 0;
  int singlemuon_positiveOr0IncreasingBX = 0;
  int singlemuon_positiveOr0DecreasingBX = 0;
  int singlemuon_positiveOr0StrangeBX = 0;
  int singlemuon_negativeConstantBX = 0;
  int singlemuon_negativeOr0IncreasingBX = 0;
  int singlemuon_negativeOr0DecreasingBX = 0;
  int singlemuon_negativeOr0StrangeBX = 0;

  int rpchitsIs0 = 0;
  int rpchitsIs1 = 0;
  int rpchitsIs2 = 0;
  int rpchitsIs3 = 0;
  int rpchitsIs4 = 0;
  int rpchitsIs5 = 0;
  int rpchitsIs6 = 0;
  int rpchitsIs7 = 0;

  int doublemuon_muon0_0BX = 0;
  int doublemuon_muon0_positiveConstantBX = 0;
  int doublemuon_muon0_positiveOr0IncreasingBX = 0;
  int doublemuon_muon0_positiveOr0DecreasingBX = 0;
  int doublemuon_muon0_positiveOr0StrangeBX = 0;
  int doublemuon_muon0_negativeConstantBX = 0;
  int doublemuon_muon0_negativeOr0IncreasingBX = 0;
  int doublemuon_muon0_negativeOr0DecreasingBX = 0;
  int doublemuon_muon0_negativeOr0StrangeBX = 0;

  int doublemuon_muon1_0BX = 0;
  int doublemuon_muon1_positiveConstantBX = 0;
  int doublemuon_muon1_positiveOr0IncreasingBX = 0;
  int doublemuon_muon1_positiveOr0DecreasingBX = 0;
  int doublemuon_muon1_positiveOr0StrangeBX = 0;
  int doublemuon_muon1_negativeConstantBX = 0;
  int doublemuon_muon1_negativeOr0IncreasingBX = 0;
  int doublemuon_muon1_negativeOr0DecreasingBX = 0;
  int doublemuon_muon1_negativeOr0StrangeBX = 0;

  int rpchitsDoubleMuonMuon0Is0 = 0;
  int rpchitsDoubleMuonMuon0Is1 = 0;
  int rpchitsDoubleMuonMuon0Is2 = 0;
  int rpchitsDoubleMuonMuon0Is3 = 0;
  int rpchitsDoubleMuonMuon0Is4 = 0;
  int rpchitsDoubleMuonMuon0Is5 = 0;
  int rpchitsDoubleMuonMuon0Is6 = 0;
  int rpchitsDoubleMuonMuon0Is7 = 0;

  int rpchitsDoubleMuonMuon1Is0 = 0;
  int rpchitsDoubleMuonMuon1Is1 = 0;
  int rpchitsDoubleMuonMuon1Is2 = 0;
  int rpchitsDoubleMuonMuon1Is3 = 0;
  int rpchitsDoubleMuonMuon1Is4 = 0;
  int rpchitsDoubleMuonMuon1Is5 = 0;
  int rpchitsDoubleMuonMuon1Is6 = 0;
  int rpchitsDoubleMuonMuon1Is7 = 0;

  int bad = 0;

  vector<int> x;

  for (Int_t i=0; i<nentries; i++) {
  //for (Int_t i=0; i<2000; i++) {    
  //for (Int_t i=0; i<100; i++) {
    tree->GetEntry(i);

    if ( (do_bx_cut && TMath::Abs(events->bxWrtCollision)>=2. && TMath::Abs(events->bxWrtBunch)>=2.) || (!do_bx_cut) ){
      pass_bx_cut++;
      //pass trigger
      if ( (do_other_cut && (events->hltL2Mu20NoVertexNoBptx3BX || events->hltL2Mu30NoVertexNoBptx3BX || events->hltL2Mu20NoVertexNoBptx3BXNoHalo || events->hltL2Mu30NoVertexNoBptx3BXNoHalo || events->hltL2Mu20NoVertex2ChaNoBptx3BXNoHalo || events->hltL2Mu30NoVertex2ChaNoBptx3BXNoHalo ) ) || (!do_other_cut) ){
	pass_trigger_cut++;

	if ( (do_other_cut && events->mu_StandAlone_N>0) || (!do_other_cut) ){
	  pass_atleast1SA_cut++;
	  if ( (do_other_cut && events->muStandAlonePt[0]>30.) || (!do_other_cut) ){
	    pass_pt30_cut++;
	    if ( (do_other_cut && TMath::Abs(events->muStandAloneEta[0])<2.1) || (!do_other_cut) ){
	      pass_eta2p1_cut++;	      
	      if ( (do_other_cut && TMath::Abs(events->muStandAloneEta[0])<1.0) || (!do_other_cut) ){
		pass_eta1p0_cut++;
	      } //end of eta[0]<2.1
	    }//end of eta[0]<1.0
	  } //end of pt[0]>30
	} //end of at least one SA	
	



      if ( (do_other_cut && events->mu_StandAlone_N<3) || (!do_other_cut) ){
	
	//cout<<"______________________"<<endl;
	//cout<<endl<<"For event "<<i<<", event # is: "<<events->id<<", run # is: "<<events->run<<", mu_StandAlone_N is: "<<events->mu_StandAlone_N<<", mu_RefittedStandAlone_N is: "<<events->mu_RefittedStandAlone_N<<", muStandAloneTof_N is: "<<events->muStandAloneTof_N<<", refitMuStandAloneTof_N is: "<<events->refitMuStandAloneTof_N<<endl;
	
	id_hist->Fill(events->id,1.0);
	run_hist->Fill(events->run,1.0);
	bx_hist->Fill(events->bx,1.0);
	bxWrtCollision_hist->Fill(events->bxWrtCollision,1.0);
	bxWrtBunch_hist->Fill(events->bxWrtBunch,1.0);
	
	//DTSegment_N_hist->Fill(events->DTSegment_N,1.0);
	
	//cout<<"For event "<<i<<", event # is: "<<events->id<<", run # is: "<<events->run<<", bx is: "<<events->bx<<", mu_N is: "<<events->mu_N<<", mu_Cosmic_N is: "<<events->mu_Cosmic_N<<", mu_StandAlone_N is: "<<events->mu_StandAlone_N<<", mu_RefittedStandAlone_N is: "<<events->mu_RefittedStandAlone_N<<endl;
	
	mu_N_hist->Fill(events->mu_N,1.0);
	for (UInt_t j=0; j<events->mu_N; j++) {
	  //cout<<"mu number "<<j<<endl;
	  muPt_hist->Fill(events->muPt[j],1.0);
	  muEta_hist->Fill(events->muEta[j],1.0);
	  muPhi_hist->Fill(events->muPhi[j],1.0);
	  muType_hist->Fill(events->muType[j],1.0);
	  muIso_hist->Fill(events->muIso[j],1.0);
	  muEta_muPhi_hist->Fill(events->muEta[j],events->muPhi[j],1.0);
	}

	bool pass_diMuMass = false;
	//cout<<"number of dimuon candidates is: "<<events->diMuMass.size()<<endl;
	diMu_N_hist->Fill(events->diMuMass.size(),1.0);
	for (UInt_t j=0; j<events->diMuMass.size(); j++) {
	  //cout<<"diMuMass is: "<<events->diMuMass[j]<<endl;
	  diMuMass_hist->Fill(events->diMuMass[j],1.0);
	  if(events->diMuMass[j] >80. && events->diMuMass[j]<100.) pass_diMuMass = true;
	}
	
	muCosmic_N_hist->Fill(events->mu_Cosmic_N,1.0);
	for (UInt_t j=0; j<events->mu_Cosmic_N; j++) {
	  //cout<<"cosmic mu number "<<j<<endl;
	  muCosmicPt_hist->Fill(events->muCosmicPt[j],1.0);
	  muCosmicEta_hist->Fill(events->muCosmicEta[j],1.0);
	  muCosmicPhi_hist->Fill(events->muCosmicPhi[j],1.0);
	  muCosmicType_hist->Fill(events->muCosmicType[j],1.0);
	  muCosmicEta_muCosmicPhi_hist->Fill(events->muCosmicEta[j],events->muCosmicPhi[j],1.0);
	}
	
	
	muStandAlone_N_hist->Fill(events->mu_StandAlone_N,1.0);
	muRefittedStandAlone_N_hist->Fill(events->mu_RefittedStandAlone_N,1.0);
	muStandAloneTof_N_hist->Fill(events->muStandAloneTof_N,1.0);
	refitMuStandAloneTof_N_hist->Fill(events->refitMuStandAloneTof_N,1.0);
	
	int pass_other_cut = 0;	

	//for (UInt_t j=0; j<events->mu_StandAlone_N; j++) {
	//cout<<"For standalone mu number "<<j<<", before the cuts pt is: "<<events->muStandAlonePt[j]<<", eta is: "<<events->muStandAloneEta[j]<<", phi is: "<<events->muStandAlonePhi[j]<<", direction is: "<<events->muStandAloneTofDirection[j]<<", ndof is: "<<events->muStandAloneTofNDof[j]<<", number of DT segments is: "<<events->DTSegment_N<<endl;
	//}

	bool pass_pt_cut[2];
	pass_pt_cut[0]= false;
	pass_pt_cut[1]= false;

	if (do_other_cut){
	  if(events->mu_StandAlone_N==2){
	    if( events->muStandAlonePt[0] > events->muStandAlonePt[1]) {
	      if( events->muStandAlonePt[0]>20. ) pass_pt_cut[0] = true;
	      if( events->muStandAlonePt[1]>10. ) pass_pt_cut[1] = true;
	    }
	    else {
	      if( events->muStandAlonePt[1]>20. ) pass_pt_cut[1] = true;
	      if( events->muStandAlonePt[0]>10.) pass_pt_cut[0] = true;
	    }
	  }// end of 2 standalone muons
	  if(events->mu_StandAlone_N==1){
	    if( events->muStandAlonePt[0]>20.) pass_pt_cut[0] = true;
	  }//end of 1 standalone muon
	}

	if (events->mu_StandAlone_N==1){
	  for (UInt_t j=0; j<events->mu_StandAlone_N; j++) {
	    if ( (do_other_cut && TMath::Abs(events->muStandAloneEta[j])<1.0 && events->muStandAlonePhi[j]>0.5 && events->muStandAlonePhi[j]<(TMath::Pi()-0.5) && events->muStandAloneTofDirection[j]!=0 && (events->muStandAloneTrackNChambersDt[j] + events->muStandAloneTrackNChambersCsc[j])>1 && pass_pt_cut[j] && TMath::Abs(events->muStandAloneTofTimeAtIpInOut[j])<50.) || (!do_other_cut) ){
	      //if ( (do_other_cut && TMath::Abs(events->muStandAloneEta[j])<1.0 && events->muStandAlonePhi[j]<-0.5 && events->muStandAlonePhi[j]>(-(TMath::Pi()-0.5)) && events->muStandAloneTofDirection[j]!=0 && (events->muStandAloneTrackNChambersDt[j] + events->muStandAloneTrackNChambersCsc[j])>1 && pass_pt_cut[j] && TMath::Abs(events->muStandAloneTofTimeAtIpInOut[j])<50.) || (!do_other_cut) ){
	      pass_other_cut++;
	      
	      //for (UInt_t j=0; j<events->mu_StandAlone_N; j++) {
	      //cout<<"______________________"<<endl;
	      /*
	      cout<<endl<<"For event "<<i<<", event # is: "<<events->id<<", run # is: "<<events->run<<", mu_StandAlone_N is: "<<events->mu_StandAlone_N<<", mu_RefittedStandAlone_N is: "<<events->mu_RefittedStandAlone_N<<", muStandAloneTof_N is: "<<events->muStandAloneTof_N<<", refitMuStandAloneTof_N is: "<<events->refitMuStandAloneTof_N<<endl;
	      cout<<"For standalone mu number "<<j<<", after the cuts pt is: "<<events->muStandAlonePt[j]<<", eta is: "<<events->muStandAloneEta[j]<<", phi is: "<<events->muStandAlonePhi[j]<<", track chi2/dof is: "<<events->muStandAloneTrackNormalizedChi2[j]<<", dxy is: "<<events->muStandAloneTrackDxy[j]<<", dz is: "<<events->muStandAloneTrackDz[j]<<endl;
	      cout<<"  , number of overall muon hits is: "<<events->muStandAloneTrackNHitsMuon[j]<<", number of Csc hits is: "<<events->muStandAloneTrackNHitsCsc[j]<<", number of Dt hits is: "<<events->muStandAloneTrackNHitsDt[j]<<", number of Rpc hits is: "<<events->muStandAloneTrackNHitsRpc[j]<<endl;
	      cout<<"  , number of overall muon stations is: "<<events->muStandAloneTrackNStations[j]<<", number of Csc chambers is: "<<events->muStandAloneTrackNChambersCsc[j]<<", number of Dt chambers is: "<<events->muStandAloneTrackNChambersDt[j]<<", number of Rpc Chambers is: "<<events->muStandAloneTrackNChambersRpc[j]<<endl;
	      cout<<"  , TOF direction is: "<<events->muStandAloneTofDirection[j]<<", TOF ndof is: "<<events->muStandAloneTofNDof[j]<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[j]<<endl;

	      */
	      
	      muStandAlonePt_hist->Fill(events->muStandAlonePt[j],1.0);
	      muStandAloneEta_hist->Fill(events->muStandAloneEta[j],1.0);
	      muStandAlonePhi_hist->Fill(events->muStandAlonePhi[j],1.0);
	      muStandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNormalizedChi2[j],1.0);
	      muStandAloneTrackDxy_hist->Fill(events->muStandAloneTrackDxy[j],1.0);
	      muStandAloneTrackDz_hist->Fill(events->muStandAloneTrackDz[j],1.0);
	      muStandAloneTrackNHitsMuon_hist->Fill(events->muStandAloneTrackNHitsMuon[j],1.0);
	      muStandAloneTrackNHitsCsc_hist->Fill(events->muStandAloneTrackNHitsCsc[j],1.0);
	      muStandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsDt[j],1.0);
	      muStandAloneTrackNHitsRpc_hist->Fill(events->muStandAloneTrackNHitsRpc[j],1.0);
	      muStandAloneTrackNStations_hist->Fill(events->muStandAloneTrackNStations[j],1.0);
	      muStandAloneTrackNChambersCsc_hist->Fill(events->muStandAloneTrackNChambersCsc[j],1.0);
	      muStandAloneTrackNChambersDt_hist->Fill(events->muStandAloneTrackNChambersDt[j],1.0);
	      muStandAloneTrackNChambersRpc_hist->Fill(events->muStandAloneTrackNChambersRpc[j],1.0);
	      muStandAloneEta_muStandAlonePhi_hist->Fill(events->muStandAloneEta[j],events->muStandAlonePhi[j],1.0);
	      muStandAloneTrackNHitsRpc_muStandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNHitsRpc[j],events->muStandAloneTrackNormalizedChi2[j],1.0);
	      muStandAloneTrackNHitsRpc_muStandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsRpc[j],events->muStandAloneTrackNHitsDt[j],1.0);
	     
	      //cout<<endl<<"number of Csc segments is: "<<events->muStandAloneTrackCscSegEndcap.at(j).size()<<endl;
	      //loop over Csc segments
	      for (UInt_t k=0; k<events->muStandAloneTrackCscSegEndcap.at(j).size(); k++) {
		//cout<<"  , for Csc segment number "<<k<<", endcap is: "<<events->muStandAloneTrackCscSegEndcap.at(j).at(k)<<", ring is: "<<events->muStandAloneTrackCscSegRing.at(j).at(k)<<", station is: "<<events->muStandAloneTrackCscSegStation.at(j).at(k)<<", chamber is: "<<events->muStandAloneTrackCscSegChamber.at(j).at(k)<<", number of hits is: "<<events->muStandAloneTrackCscSegNHits.at(j).at(k)<<", phi is: "<<events->muStandAloneTrackCscSegPhi.at(j).at(k)<<", z is: "<<events->muStandAloneTrackCscSegZ.at(j).at(k)<<", R is: "<<events->muStandAloneTrackCscSegR.at(j).at(k)<<", dir phi is: "<<events->muStandAloneTrackCscSegDirPhi.at(j).at(k)<<", dir theta is: "<<events->muStandAloneTrackCscSegDirTheta.at(j).at(k)<<", segment time is: "<<events->muStandAloneTrackCscSegTime.at(j).at(k)<<endl;
	      }
	      
	      //cout<<endl<<"number of rpc hits is: "<<events->muStandAloneTrackRpcHitZ.at(j).size()<<endl;
	      bool all_bx_0 = true;
	      bool all_bx_positive = true;
	      bool all_bx_negative = true;
	      bool all_bx_positiveOr0 = true;
	      bool all_bx_negativeOr0 = true;
	      bool all_bx_constant = true;
	      bool all_bx_increasing = true;
	      bool all_bx_decreasing = true;
	      if(events->muStandAloneTrackRpcHitZ.at(j).size()==0){
		all_bx_0 = false;
		all_bx_positive = false;
		all_bx_negative = false;
		all_bx_positiveOr0 = false;
		all_bx_negativeOr0 = false;
		all_bx_constant = false;
		all_bx_increasing = false;
		all_bx_decreasing = false;
	      }
	      if(events->muStandAloneTrackRpcHitZ.at(j).size()>0) events_1muon_pass_other_cut_with_rpcs++;
	      //loop over Rpc hits
	      for (UInt_t k=0; k<events->muStandAloneTrackRpcHitZ.at(j).size(); k++) {
		//cout<<"  , for Rpc hit number "<<k<<", Z is: "<<events->muStandAloneTrackRpcHitZ.at(j).at(k)<<", Rho is: "<<events->muStandAloneTrackRpcHitRho.at(j).at(k)<<", phi is: "<<events->muStandAloneTrackRpcHitPhi.at(j).at(k)<<", region is: "<<events->muStandAloneTrackRpcHitRegion.at(j).at(k)<<", Bx is: "<<events->muStandAloneTrackRpcHitBx.at(j).at(k)<<endl;
		if(events->muStandAloneTrackRpcHitBx.at(j).at(k) != 0) all_bx_0 = false;
		if(events->muStandAloneTrackRpcHitBx.at(j).at(k) <= 0) all_bx_positive = false;
		if(events->muStandAloneTrackRpcHitBx.at(j).at(k) >= 0) all_bx_negative = false;
		if(events->muStandAloneTrackRpcHitBx.at(j).at(k) < 0) all_bx_positiveOr0 = false;
		if(events->muStandAloneTrackRpcHitBx.at(j).at(k) > 0) all_bx_negativeOr0 = false;
		UInt_t l=k+1;
		if(l<events->muStandAloneTrackRpcHitZ.at(j).size()){
		  if(events->muStandAloneTrackRpcHitBx.at(j).at(l) != events->muStandAloneTrackRpcHitBx.at(j).at(k)) all_bx_constant = false;
		  if(events->muStandAloneTrackRpcHitBx.at(j).at(l) < events->muStandAloneTrackRpcHitBx.at(j).at(k)) all_bx_increasing = false;
		  if(events->muStandAloneTrackRpcHitBx.at(j).at(l) > events->muStandAloneTrackRpcHitBx.at(j).at(k)) all_bx_decreasing = false;
		  //cout<<"events->muStandAloneTrackRpcHitBx.at(j).at(l) is: "<<events->muStandAloneTrackRpcHitBx.at(j).at(l)<<", events->muStandAloneTrackRpcHitBx.at(j).at(k) is: "<<events->muStandAloneTrackRpcHitBx.at(j).at(k)<<", all_bx_increasing is: "<<all_bx_increasing<<", all_bx_decreasing is: "<<all_bx_decreasing<<endl;
		}
	      }
	      if(all_bx_constant) {
		all_bx_increasing = false;
		all_bx_decreasing = false;
	      }
	      /*
	      cout<<"all_bx_0 is: "<<all_bx_0<<endl;
	      cout<<"all_bx_positive is: "<<all_bx_positive<<endl;
	      cout<<"all_bx_negative is: "<<all_bx_negative<<endl;
	      cout<<"all_bx_positiveOr0 is: "<<all_bx_positiveOr0<<endl;
	      cout<<"all_bx_negativeOr0 is: "<<all_bx_negativeOr0<<endl;
	      cout<<"all_bx_constant is: "<<all_bx_constant<<endl;
	      cout<<"all_bx_increasing is: "<<all_bx_increasing<<endl;
	      cout<<"all_bx_decreasing is: "<<all_bx_decreasing<<endl;
	      */

	      if(all_bx_0 && all_bx_constant){
		singlemuon_0BX++;
		//cout<<"singlemuon_0BX"<<endl;
		if (events->muStandAloneTrackRpcHitZ.at(j).size()==0) rpchitsIs0++;
		if (events->muStandAloneTrackRpcHitZ.at(j).size()==1) rpchitsIs1++;
		if (events->muStandAloneTrackRpcHitZ.at(j).size()==2) rpchitsIs2++;
		if (events->muStandAloneTrackRpcHitZ.at(j).size()==3) rpchitsIs3++;
		if (events->muStandAloneTrackRpcHitZ.at(j).size()==4) rpchitsIs4++;
		if (events->muStandAloneTrackRpcHitZ.at(j).size()==5) rpchitsIs5++;
		if (events->muStandAloneTrackRpcHitZ.at(j).size()==6) rpchitsIs6++;
		if (events->muStandAloneTrackRpcHitZ.at(j).size()==7) rpchitsIs7++;
	      }
	      if(all_bx_positive && all_bx_constant){
		singlemuon_positiveConstantBX++;
		//cout<<"singlemuon_positiveConstantBX"<<endl;
	      }
	      if(all_bx_positiveOr0 && all_bx_increasing){
		singlemuon_positiveOr0IncreasingBX++;
		//cout<<"singlemuon_positiveOr0IncreasingBX"<<endl;
	      }
	      if(all_bx_positiveOr0 && all_bx_decreasing){
		singlemuon_positiveOr0DecreasingBX++;
		//cout<<"singlemuon_positiveOr0DecreasingBX"<<endl;
	      }
	      if(all_bx_positiveOr0 && !all_bx_decreasing && !all_bx_increasing && !all_bx_constant){
		singlemuon_positiveOr0StrangeBX++;
		//cout<<"singlemuon_positiveOr0StrangeBX"<<endl;
	      }
	      if(all_bx_negative && all_bx_constant){
		singlemuon_negativeConstantBX++;
		//cout<<"singlemuon_negativeConstantBX"<<endl;
	      }
	      if(all_bx_negativeOr0 && all_bx_increasing){
		singlemuon_negativeOr0IncreasingBX++;
		//cout<<"singlemuon_negativeOr0IncreasingBX"<<endl;
	      }
	      if(all_bx_negativeOr0 && all_bx_decreasing){
		singlemuon_negativeOr0DecreasingBX++;
		//cout<<"singlemuon_negativeOr0DecreasingBX"<<endl;
	      }
	      if(all_bx_negativeOr0 && !all_bx_decreasing && !all_bx_increasing && !all_bx_constant){
		singlemuon_negativeOr0StrangeBX++;
		//cout<<"singlemuon_negativeOr0StrangeBX"<<endl;
	      }
	      
	    //for (UInt_t j=0; j<events->mu_RefittedStandAlone_N; j++) {
	    //cout<<"refitted standalone mu number "<<j<<endl;
	      muRefittedStandAlonePt_hist->Fill(events->muRefittedStandAlonePt[j],1.0);
	      muRefittedStandAloneEta_hist->Fill(events->muRefittedStandAloneEta[j],1.0);
	      muRefittedStandAlonePhi_hist->Fill(events->muRefittedStandAlonePhi[j],1.0);
	      muRefittedStandAloneEta_muRefittedStandAlonePhi_hist->Fill(events->muRefittedStandAloneEta[j],events->muRefittedStandAlonePhi[j],1.0);
	      //}
	      
	      //for (UInt_t j=0; j<events->muStandAloneTof_N; j++) {
	      //cout<<"TOF mu number "<<j<<endl;
	      muStandAloneTofDirection_hist->Fill(events->muStandAloneTofDirection[j],1.0);
	      muStandAloneTofNDof_hist->Fill(events->muStandAloneTofNDof[j],1.0);
	      muStandAloneTofInverseBeta_hist->Fill(events->muStandAloneTofInverseBeta[j],1.0);
	      muStandAloneTofInverseBetaErr_hist->Fill(events->muStandAloneTofInverseBetaErr[j],1.0);
	      muStandAloneTofFreeInverseBeta_hist->Fill(events->muStandAloneTofFreeInverseBeta[j],1.0);
	      muStandAloneTofFreeInverseBetaErr_hist->Fill(events->muStandAloneTofFreeInverseBetaErr[j],1.0);
	      muStandAloneTofTimeAtIpInOut_hist->Fill(events->muStandAloneTofTimeAtIpInOut[j],1.0);
	      muStandAloneTofTimeAtIpInOutErr_hist->Fill(events->muStandAloneTofTimeAtIpInOutErr[j],1.0);
	      muStandAloneTofTimeAtIpOutIn_hist->Fill(events->muStandAloneTofTimeAtIpOutIn[j],1.0);
	      muStandAloneTofTimeAtIpOutInErr_hist->Fill(events->muStandAloneTofTimeAtIpOutInErr[j],1.0);
	      //}
	      
	      //for (UInt_t j=0; j<events->refitMuStandAloneTof_N; j++) {
	      //cout<<"DT re-reco TOF mu number "<<j<<endl;
	      refitMuStandAloneTofDirection_hist->Fill(events->refitMuStandAloneTofDirection[j],1.0);
	      refitMuStandAloneTofNDof_hist->Fill(events->refitMuStandAloneTofNDof[j],1.0);
	      refitMuStandAloneTofInverseBeta_hist->Fill(events->refitMuStandAloneTofInverseBeta[j],1.0);
	      refitMuStandAloneTofInverseBetaErr_hist->Fill(events->refitMuStandAloneTofInverseBetaErr[j],1.0);
	      refitMuStandAloneTofFreeInverseBeta_hist->Fill(events->refitMuStandAloneTofFreeInverseBeta[j],1.0);
	      refitMuStandAloneTofFreeInverseBetaErr_hist->Fill(events->refitMuStandAloneTofFreeInverseBetaErr[j],1.0);
	      refitMuStandAloneTofTimeAtIpInOut_hist->Fill(events->refitMuStandAloneTofTimeAtIpInOut[j],1.0);
	      refitMuStandAloneTofTimeAtIpInOutErr_hist->Fill(events->refitMuStandAloneTofTimeAtIpInOutErr[j],1.0);
	      refitMuStandAloneTofTimeAtIpOutIn_hist->Fill(events->refitMuStandAloneTofTimeAtIpOutIn[j],1.0);
	      refitMuStandAloneTofTimeAtIpOutInErr_hist->Fill(events->refitMuStandAloneTofTimeAtIpOutInErr[j],1.0);
	      //}
	      
	    }//end of other cut
	  }//end of loop over standalone muons
	  muStandAlone_N_other_cut_hist->Fill(pass_other_cut,1.0);
	}//end of if 1 standalone muon
      
	if(events->mu_StandAlone_N==2){
	  if((file_dataset=="Zmumu_Run2012B" && pass_diMuMass) || (file_dataset!="Zmumu_Run2012B")){
	    if (  ((events->muStandAlonePhi[0]>0.5 && events->muStandAlonePhi[0]<(TMath::Pi()-0.5) && 
		    events->muStandAlonePhi[1] < (-0.5) && events->muStandAlonePhi[1]>(-1.0*TMath::Pi()+0.5) )
		   || 
		   (events->muStandAlonePhi[1]>0.5 && events->muStandAlonePhi[1]<(TMath::Pi()-0.5) &&  
		    events->muStandAlonePhi[0]< (-0.5) && events->muStandAlonePhi[0]>(-1.0*TMath::Pi()+0.5)  ))){
	      if ( (do_other_cut && TMath::Abs(events->muStandAloneEta[0])<1.0 && TMath::Abs(events->muStandAloneEta[1])<1.0 && events->muStandAloneTofDirection[0]!=0 && events->muStandAloneTofDirection[1]!=0 && (events->muStandAloneTrackNChambersDt[0] + events->muStandAloneTrackNChambersCsc[0])>1 && (events->muStandAloneTrackNChambersDt[1] + events->muStandAloneTrackNChambersCsc[1])>1 && pass_pt_cut[0] && pass_pt_cut[1] && TMath::Abs(events->muStandAloneTofTimeAtIpInOut[0])<50. && TMath::Abs(events->muStandAloneTofTimeAtIpInOut[1])<50.) || (!do_other_cut) ){

		//cout<<"______________________"<<endl;
		//cout<<endl<<"For event "<<i<<", event # is: "<<events->id<<", run # is: "<<events->run<<", mu_StandAlone_N is: "<<events->mu_StandAlone_N<<", mu_RefittedStandAlone_N is: "<<events->mu_RefittedStandAlone_N<<", muStandAloneTof_N is: "<<events->muStandAloneTof_N<<", refitMuStandAloneTof_N is: "<<events->refitMuStandAloneTof_N<<endl;
		//cout<<"number of dimuon candidates is: "<<events->diMuMass.size()<<endl;
		//for (UInt_t j=0; j<events->diMuMass.size(); j++) {
		//cout<<"diMuMass for candidate "<<j<<" is: "<<events->diMuMass[j]<<endl;
		//}

		if (events->muStandAlonePhi[0]<0. && events->muStandAlonePhi[1]>0.) {
		  /*
		cout<<"For standalone mu number "<<0<<", after the cuts pt is: "<<events->muStandAlonePt[0]<<", eta is: "<<events->muStandAloneEta[0]<<", phi is: "<<events->muStandAlonePhi[0]<<", track chi2/dof is: "<<events->muStandAloneTrackNormalizedChi2[0]<<", dxy is: "<<events->muStandAloneTrackDxy[0]<<", dz is: "<<events->muStandAloneTrackDz[0]<<endl;
		cout<<"  , number of overall muon hits is: "<<events->muStandAloneTrackNHitsMuon[0]<<", number of Csc hits is: "<<events->muStandAloneTrackNHitsCsc[0]<<", number of Dt hits is: "<<events->muStandAloneTrackNHitsDt[0]<<", number of Rpc hits is: "<<events->muStandAloneTrackNHitsRpc[0]<<endl;
		cout<<"  , number of overall muon stations is: "<<events->muStandAloneTrackNStations[0]<<", number of Csc chambers is: "<<events->muStandAloneTrackNChambersCsc[0]<<", number of Dt chambers is: "<<events->muStandAloneTrackNChambersDt[0]<<", number of Rpc Chambers is: "<<events->muStandAloneTrackNChambersRpc[0]<<endl;
		cout<<"  , TOF direction is: "<<events->muStandAloneTofDirection[0]<<", TOF ndof is: "<<events->muStandAloneTofNDof[0]<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[0]<<endl;
		cout<<endl<<"number of Csc segments is: "<<events->muStandAloneTrackCscSegEndcap.at(0).size()<<endl;
		//loop over Csc segments
		for (UInt_t k=0; k<events->muStandAloneTrackCscSegEndcap.at(0).size(); k++) {
		  cout<<"  , for Csc segment number "<<k<<", endcap is: "<<events->muStandAloneTrackCscSegEndcap.at(0).at(k)<<", ring is: "<<events->muStandAloneTrackCscSegRing.at(0).at(k)<<", station is: "<<events->muStandAloneTrackCscSegStation.at(0).at(k)<<", chamber is: "<<events->muStandAloneTrackCscSegChamber.at(0).at(k)<<", number of hits is: "<<events->muStandAloneTrackCscSegNHits.at(0).at(k)<<", phi is: "<<events->muStandAloneTrackCscSegPhi.at(0).at(k)<<", z is: "<<events->muStandAloneTrackCscSegZ.at(0).at(k)<<", R is: "<<events->muStandAloneTrackCscSegR.at(0).at(k)<<", dir phi is: "<<events->muStandAloneTrackCscSegDirPhi.at(0).at(k)<<", dir theta is: "<<events->muStandAloneTrackCscSegDirTheta.at(0).at(k)<<", segment time is: "<<events->muStandAloneTrackCscSegTime.at(0).at(k)<<endl;
		}
		*/
		
		bool muon0_all_bx_0 = true;
		bool muon0_all_bx_positive = true;
		bool muon0_all_bx_negative = true;
		bool muon0_all_bx_positiveOr0 = true;
		bool muon0_all_bx_negativeOr0 = true;
		bool muon0_all_bx_constant = true;
		bool muon0_all_bx_increasing = true;
		bool muon0_all_bx_decreasing = true;
		if(events->muStandAloneTrackRpcHitZ.at(0).size()==0){
		  muon0_all_bx_0 = false;
		  muon0_all_bx_positive = false;
		  muon0_all_bx_negative = false;
		  muon0_all_bx_positiveOr0 = false;
		  muon0_all_bx_negativeOr0 = false;
		  muon0_all_bx_constant = false;
		  muon0_all_bx_increasing = false;
		  muon0_all_bx_decreasing = false;
		}
		//cout<<endl<<"number of rpc hits is: "<<events->muStandAloneTrackRpcHitZ.at(0).size()<<endl;
		if(events->muStandAloneTrackRpcHitZ.at(0).size()>0) events_2muon_muon0_pass_other_cut_with_rpcs++;
		//loop over Rpc hits
		for (UInt_t k=0; k<events->muStandAloneTrackRpcHitZ.at(0).size(); k++) {
		  //cout<<"  , for Rpc hit number "<<k<<", Z is: "<<events->muStandAloneTrackRpcHitZ.at(0).at(k)<<", Rho is: "<<events->muStandAloneTrackRpcHitRho.at(0).at(k)<<", phi is: "<<events->muStandAloneTrackRpcHitPhi.at(0).at(k)<<", region is: "<<events->muStandAloneTrackRpcHitRegion.at(0).at(k)<<", Bx is: "<<events->muStandAloneTrackRpcHitBx.at(0).at(k)<<endl;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) != 0) muon0_all_bx_0 = false;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) <= 0) muon0_all_bx_positive = false;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) >= 0) muon0_all_bx_negative = false;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) < 0) muon0_all_bx_positiveOr0 = false;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) > 0) muon0_all_bx_negativeOr0 = false;
		  UInt_t l=k+1;
		  if(l<events->muStandAloneTrackRpcHitZ.at(0).size()){
		    if(events->muStandAloneTrackRpcHitBx.at(0).at(l) != events->muStandAloneTrackRpcHitBx.at(0).at(k)) muon0_all_bx_constant = false;
		    if(events->muStandAloneTrackRpcHitBx.at(0).at(l) < events->muStandAloneTrackRpcHitBx.at(0).at(k)) muon0_all_bx_increasing = false;
		    if(events->muStandAloneTrackRpcHitBx.at(0).at(l) > events->muStandAloneTrackRpcHitBx.at(0).at(k)) muon0_all_bx_decreasing = false;
		  }
		}
		if(muon0_all_bx_constant) {
		  muon0_all_bx_increasing = false;
		  muon0_all_bx_decreasing = false;
		}
		/*
		cout<<"muon0_all_bx_0 is: "<<muon0_all_bx_0<<endl;
		cout<<"muon0_all_bx_positive is: "<<muon0_all_bx_positive<<endl;
		cout<<"muon0_all_bx_negative is: "<<muon0_all_bx_negative<<endl;
		cout<<"muon0_all_bx_positiveOr0 is: "<<muon0_all_bx_positiveOr0<<endl;
		cout<<"muon0_all_bx_negativeOr0 is: "<<muon0_all_bx_negativeOr0<<endl;
		cout<<"muon0_all_bx_constant is: "<<muon0_all_bx_constant<<endl;
		cout<<"muon0_all_bx_increasing is: "<<muon0_all_bx_increasing<<endl;
		cout<<"muon0_all_bx_decreasing is: "<<muon0_all_bx_decreasing<<endl;
		*/

		if(muon0_all_bx_0 && muon0_all_bx_constant){
		  doublemuon_muon0_0BX++;
		  //cout<<"doublemuon_muon0_0BX"<<endl;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==0) rpchitsDoubleMuonMuon0Is0++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==1) rpchitsDoubleMuonMuon0Is1++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==2) rpchitsDoubleMuonMuon0Is2++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==3) rpchitsDoubleMuonMuon0Is3++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==4) rpchitsDoubleMuonMuon0Is4++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==5) rpchitsDoubleMuonMuon0Is5++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==6) rpchitsDoubleMuonMuon0Is6++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==7) rpchitsDoubleMuonMuon0Is7++;
		  		  
		}
		if(muon0_all_bx_positive && muon0_all_bx_constant){
		  doublemuon_muon0_positiveConstantBX++;
		  //cout<<"doublemuon_muon0_positiveConstantBX"<<endl;
		}
		if(muon0_all_bx_positiveOr0 && muon0_all_bx_increasing){
		  doublemuon_muon0_positiveOr0IncreasingBX++;
		  //cout<<"doublemuon_muon0_positiveOr0IncreasingBX"<<endl;
		}
		if(muon0_all_bx_positiveOr0 && muon0_all_bx_decreasing){
		  doublemuon_muon0_positiveOr0DecreasingBX++;
		  //cout<<"doublemuon_muon0_positiveOr0DecreasingBX"<<endl;
		}
		if(muon0_all_bx_positiveOr0 && !muon0_all_bx_decreasing && !muon0_all_bx_increasing && !muon0_all_bx_constant){
		  doublemuon_muon0_positiveOr0StrangeBX++;
		  //cout<<"doublemuon_muon0_positiveOr0StrangeBX"<<endl;
		}
		if(muon0_all_bx_negative && muon0_all_bx_constant){
		  doublemuon_muon0_negativeConstantBX++;
		  //cout<<"doublemuon_muon0_negativeConstantBX"<<endl;
		}
		if(muon0_all_bx_negativeOr0 && muon0_all_bx_increasing){
		  doublemuon_muon0_negativeOr0IncreasingBX++;
		  //cout<<"doublemuon_muon0_negativeOr0IncreasingBX"<<endl;
		}
		if(muon0_all_bx_negativeOr0 && muon0_all_bx_decreasing){
		  doublemuon_muon0_negativeOr0DecreasingBX++;
		  //cout<<"doublemuon_muon0_negativeOr0DecreasingBX"<<endl;
		}
		if(muon0_all_bx_negativeOr0 && !muon0_all_bx_decreasing && !muon0_all_bx_increasing && !muon0_all_bx_constant){
		  doublemuon_muon0_negativeOr0StrangeBX++;
		  //cout<<"doublemuon_muon0_negativeOr0StrangeBX"<<endl;
		}

		/*
		cout<<endl;
		cout<<"For standalone mu number "<<1<<", after the cuts pt is: "<<events->muStandAlonePt[1]<<", eta is: "<<events->muStandAloneEta[1]<<", phi is: "<<events->muStandAlonePhi[1]<<", track chi2/dof is: "<<events->muStandAloneTrackNormalizedChi2[1]<<", dxy is: "<<events->muStandAloneTrackDxy[1]<<", dz is: "<<events->muStandAloneTrackDz[1]<<endl;
		cout<<"  , number of overall muon hits is: "<<events->muStandAloneTrackNHitsMuon[1]<<", number of Csc hits is: "<<events->muStandAloneTrackNHitsCsc[1]<<", number of Dt hits is: "<<events->muStandAloneTrackNHitsDt[1]<<", number of Rpc hits is: "<<events->muStandAloneTrackNHitsRpc[1]<<endl;
		cout<<"  , number of overall muon stations is: "<<events->muStandAloneTrackNStations[1]<<", number of Csc chambers is: "<<events->muStandAloneTrackNChambersCsc[1]<<", number of Dt chambers is: "<<events->muStandAloneTrackNChambersDt[1]<<", number of Rpc Chambers is: "<<events->muStandAloneTrackNChambersRpc[1]<<endl;
		cout<<"  , TOF direction is: "<<events->muStandAloneTofDirection[1]<<", TOF ndof is: "<<events->muStandAloneTofNDof[1]<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[1]<<endl;
		cout<<endl<<"number of Csc segments is: "<<events->muStandAloneTrackCscSegEndcap.at(1).size()<<endl;
		//loop over Csc segments
		for (UInt_t k=0; k<events->muStandAloneTrackCscSegEndcap.at(1).size(); k++) {
		  cout<<"  , for Csc segment number "<<k<<", endcap is: "<<events->muStandAloneTrackCscSegEndcap.at(1).at(k)<<", ring is: "<<events->muStandAloneTrackCscSegRing.at(1).at(k)<<", station is: "<<events->muStandAloneTrackCscSegStation.at(1).at(k)<<", chamber is: "<<events->muStandAloneTrackCscSegChamber.at(1).at(k)<<", number of hits is: "<<events->muStandAloneTrackCscSegNHits.at(1).at(k)<<", phi is: "<<events->muStandAloneTrackCscSegPhi.at(1).at(k)<<", z is: "<<events->muStandAloneTrackCscSegZ.at(1).at(k)<<", R is: "<<events->muStandAloneTrackCscSegR.at(1).at(k)<<", dir phi is: "<<events->muStandAloneTrackCscSegDirPhi.at(1).at(k)<<", dir theta is: "<<events->muStandAloneTrackCscSegDirTheta.at(1).at(k)<<", segment time is: "<<events->muStandAloneTrackCscSegTime.at(1).at(k)<<endl;
		}
		*/

		bool muon1_all_bx_0 = true;
		bool muon1_all_bx_positive = true;
		bool muon1_all_bx_negative = true;
		bool muon1_all_bx_positiveOr0 = true;
		bool muon1_all_bx_negativeOr0 = true;
		bool muon1_all_bx_constant = true;
		bool muon1_all_bx_increasing = true;
		bool muon1_all_bx_decreasing = true;
		if(events->muStandAloneTrackRpcHitZ.at(1).size()==0){
		  muon1_all_bx_0 = false;
		  muon1_all_bx_positive = false;
		  muon1_all_bx_negative = false;
		  muon1_all_bx_positiveOr0 = false;
		  muon1_all_bx_negativeOr0 = false;
		  muon1_all_bx_constant = false;
		  muon1_all_bx_increasing = false;
		  muon1_all_bx_decreasing = false;
		}
		//cout<<endl<<"number of rpc hits is: "<<events->muStandAloneTrackRpcHitZ.at(1).size()<<endl;
		if(events->muStandAloneTrackRpcHitZ.at(1).size()>0) events_2muon_muon1_pass_other_cut_with_rpcs++;
		//loop over Rpc hits
		for (UInt_t k=0; k<events->muStandAloneTrackRpcHitZ.at(1).size(); k++) {
		  //cout<<"  , for Rpc hit number "<<k<<", Z is: "<<events->muStandAloneTrackRpcHitZ.at(1).at(k)<<", Rho is: "<<events->muStandAloneTrackRpcHitRho.at(1).at(k)<<", phi is: "<<events->muStandAloneTrackRpcHitPhi.at(1).at(k)<<", region is: "<<events->muStandAloneTrackRpcHitRegion.at(1).at(k)<<", Bx is: "<<events->muStandAloneTrackRpcHitBx.at(1).at(k)<<endl;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) != 0) muon1_all_bx_0 = false;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) <= 0) muon1_all_bx_positive = false;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) >= 0) muon1_all_bx_negative = false;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) < 0) muon1_all_bx_positiveOr0 = false;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) > 0) muon1_all_bx_negativeOr0 = false;
		  UInt_t l=k+1;
		  if(l<events->muStandAloneTrackRpcHitZ.at(1).size()){
		    if(events->muStandAloneTrackRpcHitBx.at(1).at(l) != events->muStandAloneTrackRpcHitBx.at(1).at(k)) muon1_all_bx_constant = false;
		    if(events->muStandAloneTrackRpcHitBx.at(1).at(l) < events->muStandAloneTrackRpcHitBx.at(1).at(k)) muon1_all_bx_increasing = false;
		    if(events->muStandAloneTrackRpcHitBx.at(1).at(l) > events->muStandAloneTrackRpcHitBx.at(1).at(k)) muon1_all_bx_decreasing = false;
		  }
		}
		if(muon1_all_bx_constant) {
		  muon1_all_bx_increasing = false;
		  muon1_all_bx_decreasing = false;
		}
		/*
		cout<<"muon1_all_bx_0 is: "<<muon1_all_bx_0<<endl;
		cout<<"muon1_all_bx_positive is: "<<muon1_all_bx_positive<<endl;
		cout<<"muon1_all_bx_negative is: "<<muon1_all_bx_negative<<endl;
		cout<<"muon1_all_bx_positiveOr0 is: "<<muon1_all_bx_positiveOr0<<endl;
		cout<<"muon1_all_bx_negativeOr0 is: "<<muon1_all_bx_negativeOr0<<endl;
		cout<<"muon1_all_bx_constant is: "<<muon1_all_bx_constant<<endl;
		cout<<"muon1_all_bx_increasing is: "<<muon1_all_bx_increasing<<endl;
		cout<<"muon1_all_bx_decreasing is: "<<muon1_all_bx_decreasing<<endl;
		*/

		if(muon1_all_bx_0 && muon1_all_bx_constant){

		  doublemuon_muon1_0BX++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==0) rpchitsDoubleMuonMuon1Is0++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==1) rpchitsDoubleMuonMuon1Is1++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==2) rpchitsDoubleMuonMuon1Is2++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==3) rpchitsDoubleMuonMuon1Is3++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==4) rpchitsDoubleMuonMuon1Is4++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==5) rpchitsDoubleMuonMuon1Is5++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==6) rpchitsDoubleMuonMuon1Is6++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==7) rpchitsDoubleMuonMuon1Is7++;
		}
		if(muon1_all_bx_positive && muon1_all_bx_constant){
		  doublemuon_muon1_positiveConstantBX++;
		  //cout<<"doublemuon_muon1_positiveConstantBX"<<endl;
		}
		if(muon1_all_bx_positiveOr0 && muon1_all_bx_increasing){
		  doublemuon_muon1_positiveOr0IncreasingBX++;
		  //cout<<"doublemuon_muon1_positiveOr0IncreasingBX"<<endl;
		}
		if(muon1_all_bx_positiveOr0 && muon1_all_bx_decreasing){
		  doublemuon_muon1_positiveOr0DecreasingBX++;
		  //cout<<"doublemuon_muon1_positiveOr0DecreasingBX"<<endl;
		}
		if(muon1_all_bx_positiveOr0 && !muon1_all_bx_decreasing && !muon1_all_bx_increasing && !muon1_all_bx_constant){
		  doublemuon_muon1_positiveOr0StrangeBX++;
		  //cout<<"doublemuon_muon1_positiveOr0StrangeBX"<<endl;
		}
		if(muon1_all_bx_negative && muon1_all_bx_constant){
		  doublemuon_muon1_negativeConstantBX++;
		  //cout<<"doublemuon_muon1_negativeConstantBX"<<endl;
		}
		if(muon1_all_bx_negativeOr0 && muon1_all_bx_increasing){
		  doublemuon_muon1_negativeOr0IncreasingBX++;
		  //cout<<"doublemuon_muon1_negativeOr0IncreasingBX"<<endl;
		}
		if(muon1_all_bx_negativeOr0 && muon1_all_bx_decreasing){
		  doublemuon_muon1_negativeOr0DecreasingBX++;
		  //cout<<"doublemuon_muon1_negativeOr0DecreasingBX"<<endl;

		  /*
		  cout<<endl;
		  cout<<"______________________"<<endl;
		  //cout<<endl<<events->id<<", "<<events->run<<endl;
		  cout<<endl<<"For event "<<i<<", event # is: "<<events->id<<", run # is: "<<events->run<<", mu_StandAlone_N is: "<<events->mu_StandAlone_N<<", mu_RefittedStandAlone_N is: "<<events->mu_RefittedStandAlone_N<<", muStandAloneTof_N is: "<<events->muStandAloneTof_N<<", refitMuStandAloneTof_N is: "<<events->refitMuStandAloneTof_N<<endl;
		  //cout<<"doublemuon_muon1_0BX"<<endl;
		  cout<<"For standalone mu number "<<1<<", after the cuts pt is: "<<events->muStandAlonePt[1]<<", eta is: "<<events->muStandAloneEta[1]<<", phi is: "<<events->muStandAlonePhi[1]<<", track chi2/dof is: "<<events->muStandAloneTrackNormalizedChi2[1]<<", dxy is: "<<events->muStandAloneTrackDxy[1]<<", dz is: "<<events->muStandAloneTrackDz[1]<<endl;
		  cout<<"  number of overall muon hits is: "<<events->muStandAloneTrackNHitsMuon[1]<<", number of Csc hits is: "<<events->muStandAloneTrackNHitsCsc[1]<<", number of Dt hits is: "<<events->muStandAloneTrackNHitsDt[1]<<", number of Rpc hits is: "<<events->muStandAloneTrackNHitsRpc[1]<<endl;
		  cout<<"  number of overall muon stations is: "<<events->muStandAloneTrackNStations[1]<<", number of Csc chambers is: "<<events->muStandAloneTrackNChambersCsc[1]<<", number of Dt chambers is: "<<events->muStandAloneTrackNChambersDt[1]<<", number of Rpc Chambers is: "<<events->muStandAloneTrackNChambersRpc[1]<<endl;
		  cout<<"  TOF direction is: "<<events->muStandAloneTofDirection[1]<<", TOF ndof is: "<<events->muStandAloneTofNDof[1]<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[1]<<endl;
		  cout<<endl<<"number of Csc segments is: "<<events->muStandAloneTrackCscSegEndcap.at(1).size()<<endl;
		  */
		//loop over Csc segments
		for (UInt_t k=0; k<events->muStandAloneTrackCscSegEndcap.at(1).size(); k++) {
		  //cout<<"  , for Csc segment number "<<k<<", endcap is: "<<events->muStandAloneTrackCscSegEndcap.at(1).at(k)<<", ring is: "<<events->muStandAloneTrackCscSegRing.at(1).at(k)<<", station is: "<<events->muStandAloneTrackCscSegStation.at(1).at(k)<<", chamber is: "<<events->muStandAloneTrackCscSegChamber.at(1).at(k)<<", number of hits is: "<<events->muStandAloneTrackCscSegNHits.at(1).at(k)<<", phi is: "<<events->muStandAloneTrackCscSegPhi.at(1).at(k)<<", z is: "<<events->muStandAloneTrackCscSegZ.at(1).at(k)<<", R is: "<<events->muStandAloneTrackCscSegR.at(1).at(k)<<", dir phi is: "<<events->muStandAloneTrackCscSegDirPhi.at(1).at(k)<<", dir theta is: "<<events->muStandAloneTrackCscSegDirTheta.at(1).at(k)<<", segment time is: "<<events->muStandAloneTrackCscSegTime.at(1).at(k)<<endl;
		  }
		//loop over RPC hits
		//cout<<endl<<"number of rpc hits is: "<<events->muStandAloneTrackRpcHitZ.at(1).size()<<endl;
		for (UInt_t k=0; k<events->muStandAloneTrackRpcHitZ.at(1).size(); k++) {
		  //cout<<"  , for Rpc hit number "<<k<<", Z is: "<<events->muStandAloneTrackRpcHitZ.at(1).at(k)<<", Rho is: "<<events->muStandAloneTrackRpcHitRho.at(1).at(k)<<", phi is: "<<events->muStandAloneTrackRpcHitPhi.at(1).at(k)<<", region is: "<<events->muStandAloneTrackRpcHitRegion.at(1).at(k)<<", Bx is: "<<events->muStandAloneTrackRpcHitBx.at(1).at(k)<<endl;
		  }

		}
		if(muon1_all_bx_negativeOr0 && !muon1_all_bx_decreasing && !muon1_all_bx_increasing && !muon1_all_bx_constant){
		  doublemuon_muon1_negativeOr0StrangeBX++;
		  //cout<<"doublemuon_muon1_negativeOr0StrangeBX"<<endl;
		}
		}




		if (events->muStandAlonePhi[1]<0. && events->muStandAlonePhi[0]>0.) {

		  /*
		  cout<<"For standalone mu number "<<0<<", after the cuts pt is: "<<events->muStandAlonePt[1]<<", eta is: "<<events->muStandAloneEta[1]<<", phi is: "<<events->muStandAlonePhi[1]<<", track chi2/dof is: "<<events->muStandAloneTrackNormalizedChi2[1]<<", dxy is: "<<events->muStandAloneTrackDxy[1]<<", dz is: "<<events->muStandAloneTrackDz[1]<<endl;
		cout<<"  , number of overall muon hits is: "<<events->muStandAloneTrackNHitsMuon[1]<<", number of Csc hits is: "<<events->muStandAloneTrackNHitsCsc[1]<<", number of Dt hits is: "<<events->muStandAloneTrackNHitsDt[1]<<", number of Rpc hits is: "<<events->muStandAloneTrackNHitsRpc[1]<<endl;
		cout<<"  , number of overall muon stations is: "<<events->muStandAloneTrackNStations[1]<<", number of Csc chambers is: "<<events->muStandAloneTrackNChambersCsc[1]<<", number of Dt chambers is: "<<events->muStandAloneTrackNChambersDt[1]<<", number of Rpc Chambers is: "<<events->muStandAloneTrackNChambersRpc[1]<<endl;
		cout<<"  , TOF direction is: "<<events->muStandAloneTofDirection[1]<<", TOF ndof is: "<<events->muStandAloneTofNDof[1]<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[1]<<endl;
		cout<<endl<<"number of Csc segments is: "<<events->muStandAloneTrackCscSegEndcap.at(1).size()<<endl;
		//loop over Csc segments
		for (UInt_t k=0; k<events->muStandAloneTrackCscSegEndcap.at(1).size(); k++) {
		  cout<<"  , for Csc segment number "<<k<<", endcap is: "<<events->muStandAloneTrackCscSegEndcap.at(1).at(k)<<", ring is: "<<events->muStandAloneTrackCscSegRing.at(1).at(k)<<", station is: "<<events->muStandAloneTrackCscSegStation.at(1).at(k)<<", chamber is: "<<events->muStandAloneTrackCscSegChamber.at(1).at(k)<<", number of hits is: "<<events->muStandAloneTrackCscSegNHits.at(1).at(k)<<", phi is: "<<events->muStandAloneTrackCscSegPhi.at(1).at(k)<<", z is: "<<events->muStandAloneTrackCscSegZ.at(1).at(k)<<", R is: "<<events->muStandAloneTrackCscSegR.at(1).at(k)<<", dir phi is: "<<events->muStandAloneTrackCscSegDirPhi.at(1).at(k)<<", dir theta is: "<<events->muStandAloneTrackCscSegDirTheta.at(1).at(k)<<", segment time is: "<<events->muStandAloneTrackCscSegTime.at(1).at(k)<<endl;
		}
		*/

		bool muon0_all_bx_0 = true;
		bool muon0_all_bx_positive = true;
		bool muon0_all_bx_negative = true;
		bool muon0_all_bx_positiveOr0 = true;
		bool muon0_all_bx_negativeOr0 = true;
		bool muon0_all_bx_constant = true;
		bool muon0_all_bx_increasing = true;
		bool muon0_all_bx_decreasing = true;
		if(events->muStandAloneTrackRpcHitZ.at(1).size()==0){
		  muon0_all_bx_0 = false;
		  muon0_all_bx_positive = false;
		  muon0_all_bx_negative = false;
		  muon0_all_bx_positiveOr0 = false;
		  muon0_all_bx_negativeOr0 = false;
		  muon0_all_bx_constant = false;
		  muon0_all_bx_increasing = false;
		  muon0_all_bx_decreasing = false;
		}
		//cout<<endl<<"number of rpc hits is: "<<events->muStandAloneTrackRpcHitZ.at(1).size()<<endl;
		if(events->muStandAloneTrackRpcHitZ.at(1).size()>0) events_2muon_muon0_pass_other_cut_with_rpcs++;
		//loop over Rpc hits
		for (UInt_t k=0; k<events->muStandAloneTrackRpcHitZ.at(1).size(); k++) {
		  //cout<<"  , for Rpc hit number "<<k<<", Z is: "<<events->muStandAloneTrackRpcHitZ.at(1).at(k)<<", Rho is: "<<events->muStandAloneTrackRpcHitRho.at(1).at(k)<<", phi is: "<<events->muStandAloneTrackRpcHitPhi.at(1).at(k)<<", region is: "<<events->muStandAloneTrackRpcHitRegion.at(1).at(k)<<", Bx is: "<<events->muStandAloneTrackRpcHitBx.at(1).at(k)<<endl;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) != 0) muon0_all_bx_0 = false;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) <= 0) muon0_all_bx_positive = false;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) >= 0) muon0_all_bx_negative = false;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) < 0) muon0_all_bx_positiveOr0 = false;
		  if(events->muStandAloneTrackRpcHitBx.at(1).at(k) > 0) muon0_all_bx_negativeOr0 = false;
		  UInt_t l=k+1;
		  if(l<events->muStandAloneTrackRpcHitZ.at(1).size()){
		    if(events->muStandAloneTrackRpcHitBx.at(1).at(l) != events->muStandAloneTrackRpcHitBx.at(1).at(k)) muon0_all_bx_constant = false;
		    if(events->muStandAloneTrackRpcHitBx.at(1).at(l) < events->muStandAloneTrackRpcHitBx.at(1).at(k)) muon0_all_bx_increasing = false;
		    if(events->muStandAloneTrackRpcHitBx.at(1).at(l) > events->muStandAloneTrackRpcHitBx.at(1).at(k)) muon0_all_bx_decreasing = false;
		  }
		}
		if(muon0_all_bx_constant) {
		  muon0_all_bx_increasing = false;
		  muon0_all_bx_decreasing = false;
		}
		/*
		cout<<"muon0_all_bx_0 is: "<<muon0_all_bx_0<<endl;
		cout<<"muon0_all_bx_positive is: "<<muon0_all_bx_positive<<endl;
		cout<<"muon0_all_bx_negative is: "<<muon0_all_bx_negative<<endl;
		cout<<"muon0_all_bx_positiveOr0 is: "<<muon0_all_bx_positiveOr0<<endl;
		cout<<"muon0_all_bx_negativeOr0 is: "<<muon0_all_bx_negativeOr0<<endl;
		cout<<"muon0_all_bx_constant is: "<<muon0_all_bx_constant<<endl;
		cout<<"muon0_all_bx_increasing is: "<<muon0_all_bx_increasing<<endl;
		cout<<"muon0_all_bx_decreasing is: "<<muon0_all_bx_decreasing<<endl;
		*/

		if(muon0_all_bx_0 && muon0_all_bx_constant){
		  doublemuon_muon0_0BX++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==0) rpchitsDoubleMuonMuon0Is0++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==1) rpchitsDoubleMuonMuon0Is1++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==2) rpchitsDoubleMuonMuon0Is2++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==3) rpchitsDoubleMuonMuon0Is3++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==4) rpchitsDoubleMuonMuon0Is4++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==5) rpchitsDoubleMuonMuon0Is5++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==6) rpchitsDoubleMuonMuon0Is6++;
		  if (events->muStandAloneTrackRpcHitZ.at(1).size()==7) rpchitsDoubleMuonMuon0Is7++;

		}
		if(muon0_all_bx_positive && muon0_all_bx_constant){
		  doublemuon_muon0_positiveConstantBX++;
		  //cout<<"doublemuon_muon0_positiveConstantBX"<<endl;
		}
		if(muon0_all_bx_positiveOr0 && muon0_all_bx_increasing){
		  doublemuon_muon0_positiveOr0IncreasingBX++;
		  //cout<<"doublemuon_muon0_positiveOr0IncreasingBX"<<endl;
		}
		if(muon0_all_bx_positiveOr0 && muon0_all_bx_decreasing){
		  doublemuon_muon0_positiveOr0DecreasingBX++;
		  //cout<<"doublemuon_muon0_positiveOr0DecreasingBX"<<endl;
		}
		if(muon0_all_bx_positiveOr0 && !muon0_all_bx_decreasing && !muon0_all_bx_increasing && !muon0_all_bx_constant){
		  doublemuon_muon0_positiveOr0StrangeBX++;
		  //cout<<"doublemuon_muon0_positiveOr0StrangeBX"<<endl;
		}
		if(muon0_all_bx_negative && muon0_all_bx_constant){
		  doublemuon_muon0_negativeConstantBX++;
		  //cout<<"doublemuon_muon0_negativeConstantBX"<<endl;
		}
		if(muon0_all_bx_negativeOr0 && muon0_all_bx_increasing){
		  doublemuon_muon0_negativeOr0IncreasingBX++;
		  //cout<<"doublemuon_muon0_negativeOr0IncreasingBX"<<endl;
		}
		if(muon0_all_bx_negativeOr0 && muon0_all_bx_decreasing){
		  doublemuon_muon0_negativeOr0DecreasingBX++;
		  //cout<<"doublemuon_muon0_negativeOr0DecreasingBX"<<endl;
		}
		if(muon0_all_bx_negativeOr0 && !muon0_all_bx_decreasing && !muon0_all_bx_increasing && !muon0_all_bx_constant){
		  doublemuon_muon0_negativeOr0StrangeBX++;
		  //cout<<"doublemuon_muon0_negativeOr0StrangeBX"<<endl;
		}

		/*
		cout<<endl;
		cout<<"For standalone mu number "<<1<<", after the cuts pt is: "<<events->muStandAlonePt[0]<<", eta is: "<<events->muStandAloneEta[0]<<", phi is: "<<events->muStandAlonePhi[0]<<", track chi2/dof is: "<<events->muStandAloneTrackNormalizedChi2[0]<<", dxy is: "<<events->muStandAloneTrackDxy[0]<<", dz is: "<<events->muStandAloneTrackDz[0]<<endl;
		cout<<"  , number of overall muon hits is: "<<events->muStandAloneTrackNHitsMuon[0]<<", number of Csc hits is: "<<events->muStandAloneTrackNHitsCsc[0]<<", number of Dt hits is: "<<events->muStandAloneTrackNHitsDt[0]<<", number of Rpc hits is: "<<events->muStandAloneTrackNHitsRpc[0]<<endl;
		cout<<"  , number of overall muon stations is: "<<events->muStandAloneTrackNStations[0]<<", number of Csc chambers is: "<<events->muStandAloneTrackNChambersCsc[0]<<", number of Dt chambers is: "<<events->muStandAloneTrackNChambersDt[0]<<", number of Rpc Chambers is: "<<events->muStandAloneTrackNChambersRpc[0]<<endl;
		cout<<"  , TOF direction is: "<<events->muStandAloneTofDirection[0]<<", TOF ndof is: "<<events->muStandAloneTofNDof[0]<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[0]<<endl;
		cout<<endl<<"number of Csc segments is: "<<events->muStandAloneTrackCscSegEndcap.at(0).size()<<endl;
		//loop over Csc segments
		for (UInt_t k=0; k<events->muStandAloneTrackCscSegEndcap.at(0).size(); k++) {
		  cout<<"  , for Csc segment number "<<k<<", endcap is: "<<events->muStandAloneTrackCscSegEndcap.at(0).at(k)<<", ring is: "<<events->muStandAloneTrackCscSegRing.at(0).at(k)<<", station is: "<<events->muStandAloneTrackCscSegStation.at(0).at(k)<<", chamber is: "<<events->muStandAloneTrackCscSegChamber.at(0).at(k)<<", number of hits is: "<<events->muStandAloneTrackCscSegNHits.at(0).at(k)<<", phi is: "<<events->muStandAloneTrackCscSegPhi.at(0).at(k)<<", z is: "<<events->muStandAloneTrackCscSegZ.at(0).at(k)<<", R is: "<<events->muStandAloneTrackCscSegR.at(0).at(k)<<", dir phi is: "<<events->muStandAloneTrackCscSegDirPhi.at(0).at(k)<<", dir theta is: "<<events->muStandAloneTrackCscSegDirTheta.at(0).at(k)<<", segment time is: "<<events->muStandAloneTrackCscSegTime.at(0).at(k)<<endl;
		}
		*/

		bool muon1_all_bx_0 = true;
		bool muon1_all_bx_positive = true;
		bool muon1_all_bx_negative = true;
		bool muon1_all_bx_positiveOr0 = true;
		bool muon1_all_bx_negativeOr0 = true;
		bool muon1_all_bx_constant = true;
		bool muon1_all_bx_increasing = true;
		bool muon1_all_bx_decreasing = true;
		if(events->muStandAloneTrackRpcHitZ.at(0).size()==0){
		  muon1_all_bx_0 = false;
		  muon1_all_bx_positive = false;
		  muon1_all_bx_negative = false;
		  muon1_all_bx_positiveOr0 = false;
		  muon1_all_bx_negativeOr0 = false;
		  muon1_all_bx_constant = false;
		  muon1_all_bx_increasing = false;
		  muon1_all_bx_decreasing = false;
		}
		//cout<<endl<<"number of rpc hits is: "<<events->muStandAloneTrackRpcHitZ.at(0).size()<<endl;
		if(events->muStandAloneTrackRpcHitZ.at(0).size()>0) events_2muon_muon1_pass_other_cut_with_rpcs++;
		//loop over Rpc hits
		for (UInt_t k=0; k<events->muStandAloneTrackRpcHitZ.at(0).size(); k++) {
		  //cout<<"  , for Rpc hit number "<<k<<", Z is: "<<events->muStandAloneTrackRpcHitZ.at(0).at(k)<<", Rho is: "<<events->muStandAloneTrackRpcHitRho.at(0).at(k)<<", phi is: "<<events->muStandAloneTrackRpcHitPhi.at(0).at(k)<<", region is: "<<events->muStandAloneTrackRpcHitRegion.at(0).at(k)<<", Bx is: "<<events->muStandAloneTrackRpcHitBx.at(0).at(k)<<endl;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) != 0) muon1_all_bx_0 = false;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) <= 0) muon1_all_bx_positive = false;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) >= 0) muon1_all_bx_negative = false;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) < 0) muon1_all_bx_positiveOr0 = false;
		  if(events->muStandAloneTrackRpcHitBx.at(0).at(k) > 0) muon1_all_bx_negativeOr0 = false;
		  UInt_t l=k+1;
		  if(l<events->muStandAloneTrackRpcHitZ.at(0).size()){
		    if(events->muStandAloneTrackRpcHitBx.at(0).at(l) != events->muStandAloneTrackRpcHitBx.at(0).at(k)) muon1_all_bx_constant = false;
		    if(events->muStandAloneTrackRpcHitBx.at(0).at(l) < events->muStandAloneTrackRpcHitBx.at(0).at(k)) muon1_all_bx_increasing = false;
		    if(events->muStandAloneTrackRpcHitBx.at(0).at(l) > events->muStandAloneTrackRpcHitBx.at(0).at(k)) muon1_all_bx_decreasing = false;
		  }
		}
		if(muon1_all_bx_constant) {
		  muon1_all_bx_increasing = false;
		  muon1_all_bx_decreasing = false;
		}
		/*
		cout<<"muon1_all_bx_0 is: "<<muon1_all_bx_0<<endl;
		cout<<"muon1_all_bx_positive is: "<<muon1_all_bx_positive<<endl;
		cout<<"muon1_all_bx_negative is: "<<muon1_all_bx_negative<<endl;
		cout<<"muon1_all_bx_positiveOr0 is: "<<muon1_all_bx_positiveOr0<<endl;
		cout<<"muon1_all_bx_negativeOr0 is: "<<muon1_all_bx_negativeOr0<<endl;
		cout<<"muon1_all_bx_constant is: "<<muon1_all_bx_constant<<endl;
		cout<<"muon1_all_bx_increasing is: "<<muon1_all_bx_increasing<<endl;
		cout<<"muon1_all_bx_decreasing is: "<<muon1_all_bx_decreasing<<endl;
		*/

		if(muon1_all_bx_0 && muon1_all_bx_constant){
		  doublemuon_muon1_0BX++;
		  //cout<<"doublemuon_muon1_0BX"<<endl;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==0) rpchitsDoubleMuonMuon1Is0++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==1) rpchitsDoubleMuonMuon1Is1++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==2) rpchitsDoubleMuonMuon1Is2++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==3) rpchitsDoubleMuonMuon1Is3++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==4) rpchitsDoubleMuonMuon1Is4++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==5) rpchitsDoubleMuonMuon1Is5++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==6) rpchitsDoubleMuonMuon1Is6++;
		  if (events->muStandAloneTrackRpcHitZ.at(0).size()==7) rpchitsDoubleMuonMuon1Is7++;
	      
		}
		if(muon1_all_bx_positive && muon1_all_bx_constant){
		  doublemuon_muon1_positiveConstantBX++;
		  //cout<<"doublemuon_muon1_positiveConstantBX"<<endl;
		}
		if(muon1_all_bx_positiveOr0 && muon1_all_bx_increasing){
		  doublemuon_muon1_positiveOr0IncreasingBX++;
		  //cout<<"doublemuon_muon1_positiveOr0IncreasingBX"<<endl;
		}
		if(muon1_all_bx_positiveOr0 && muon1_all_bx_decreasing){
		  doublemuon_muon1_positiveOr0DecreasingBX++;
		  //cout<<"doublemuon_muon1_positiveOr0DecreasingBX"<<endl;
		}
		if(muon1_all_bx_positiveOr0 && !muon1_all_bx_decreasing && !muon1_all_bx_increasing && !muon1_all_bx_constant){
		  doublemuon_muon1_positiveOr0StrangeBX++;
		  //cout<<"doublemuon_muon1_positiveOr0StrangeBX"<<endl;
		}
		if(muon1_all_bx_negative && muon1_all_bx_constant){
		  doublemuon_muon1_negativeConstantBX++;
		  //cout<<"doublemuon_muon1_negativeConstantBX"<<endl;
		}
		if(muon1_all_bx_negativeOr0 && muon1_all_bx_increasing){
		  doublemuon_muon1_negativeOr0IncreasingBX++;
		  //cout<<"doublemuon_muon1_negativeOr0IncreasingBX"<<endl;
		}
		if(muon1_all_bx_negativeOr0 && muon1_all_bx_decreasing){
		  doublemuon_muon1_negativeOr0DecreasingBX++;
		  //cout<<"doublemuon_muon1_negativeOr0DecreasingBX"<<endl;
		  /*
		  cout<<endl;
		  cout<<"______________________"<<endl;
		  //cout<<endl<<events->id<<", "<<events->run<<endl;
		  cout<<endl<<"For event "<<i<<", event # is: "<<events->id<<", run # is: "<<events->run<<", mu_StandAlone_N is: "<<events->mu_StandAlone_N<<", mu_RefittedStandAlone_N is: "<<events->mu_RefittedStandAlone_N<<", muStandAloneTof_N is: "<<events->muStandAloneTof_N<<", refitMuStandAloneTof_N is: "<<events->refitMuStandAloneTof_N<<endl;
		  //cout<<"doublemuon_muon1_0BX"<<endl;
		  cout<<"For standalone mu number "<<0<<", after the cuts pt is: "<<events->muStandAlonePt[0]<<", eta is: "<<events->muStandAloneEta[0]<<", phi is: "<<events->muStandAlonePhi[0]<<", track chi2/dof is: "<<events->muStandAloneTrackNormalizedChi2[0]<<", dxy is: "<<events->muStandAloneTrackDxy[0]<<", dz is: "<<events->muStandAloneTrackDz[0]<<endl;
		  cout<<"  number of overall muon hits is: "<<events->muStandAloneTrackNHitsMuon[0]<<", number of Csc hits is: "<<events->muStandAloneTrackNHitsCsc[0]<<", number of Dt hits is: "<<events->muStandAloneTrackNHitsDt[0]<<", number of Rpc hits is: "<<events->muStandAloneTrackNHitsRpc[0]<<endl;
		  cout<<"  number of overall muon stations is: "<<events->muStandAloneTrackNStations[0]<<", number of Csc chambers is: "<<events->muStandAloneTrackNChambersCsc[0]<<", number of Dt chambers is: "<<events->muStandAloneTrackNChambersDt[0]<<", number of Rpc Chambers is: "<<events->muStandAloneTrackNChambersRpc[0]<<endl;
		  cout<<"  TOF direction is: "<<events->muStandAloneTofDirection[0]<<", TOF ndof is: "<<events->muStandAloneTofNDof[0]<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[0]<<endl;
		  cout<<endl<<"number of Csc segments is: "<<events->muStandAloneTrackCscSegEndcap.at(0).size()<<endl;
		  */
		//loop over Csc segments
		for (UInt_t k=0; k<events->muStandAloneTrackCscSegEndcap.at(0).size(); k++) {
		  //cout<<"  , for Csc segment number "<<k<<", endcap is: "<<events->muStandAloneTrackCscSegEndcap.at(0).at(k)<<", ring is: "<<events->muStandAloneTrackCscSegRing.at(0).at(k)<<", station is: "<<events->muStandAloneTrackCscSegStation.at(0).at(k)<<", chamber is: "<<events->muStandAloneTrackCscSegChamber.at(0).at(k)<<", number of hits is: "<<events->muStandAloneTrackCscSegNHits.at(0).at(k)<<", phi is: "<<events->muStandAloneTrackCscSegPhi.at(0).at(k)<<", z is: "<<events->muStandAloneTrackCscSegZ.at(0).at(k)<<", R is: "<<events->muStandAloneTrackCscSegR.at(0).at(k)<<", dir phi is: "<<events->muStandAloneTrackCscSegDirPhi.at(0).at(k)<<", dir theta is: "<<events->muStandAloneTrackCscSegDirTheta.at(0).at(k)<<", segment time is: "<<events->muStandAloneTrackCscSegTime.at(0).at(k)<<endl;
		  }
		//loop over RPC hits
		//cout<<endl<<"number of rpc hits is: "<<events->muStandAloneTrackRpcHitZ.at(0).size()<<endl;
		for (UInt_t k=0; k<events->muStandAloneTrackRpcHitZ.at(0).size(); k++) {
		  //cout<<"  , for Rpc hit number "<<k<<", Z is: "<<events->muStandAloneTrackRpcHitZ.at(0).at(k)<<", Rho is: "<<events->muStandAloneTrackRpcHitRho.at(0).at(k)<<", phi is: "<<events->muStandAloneTrackRpcHitPhi.at(0).at(k)<<", region is: "<<events->muStandAloneTrackRpcHitRegion.at(0).at(k)<<", Bx is: "<<events->muStandAloneTrackRpcHitBx.at(0).at(k)<<endl;
		}
		}
		if(muon1_all_bx_negativeOr0 && !muon1_all_bx_decreasing && !muon1_all_bx_increasing && !muon1_all_bx_constant){
		  doublemuon_muon1_negativeOr0StrangeBX++;
		  //cout<<"doublemuon_muon1_negativeOr0StrangeBX"<<endl;
		}
		}
		
		if (events->muStandAlonePhi[0]<0. && events->muStandAlonePhi[1]>0.) {
		  mu0_StandAloneTofTimeAtIpInOut_hist->Fill(events->muStandAloneTofTimeAtIpInOut[0],1.0);
		  mu0_StandAloneTofTimeAtIpOutIn_hist->Fill(events->muStandAloneTofTimeAtIpOutIn[0],1.0);
		  mu1_StandAloneTofTimeAtIpInOut_hist->Fill(events->muStandAloneTofTimeAtIpInOut[1],1.0);
		  mu1_StandAloneTofTimeAtIpOutIn_hist->Fill(events->muStandAloneTofTimeAtIpOutIn[1],1.0);
		  mudiff_StandAloneTofTimeAtIpInOut_hist->Fill(events->muStandAloneTofTimeAtIpInOut[0] - events->muStandAloneTofTimeAtIpInOut[1],1.0);
		  mudiff_StandAloneTofTimeAtIpOutIn_hist->Fill(events->muStandAloneTofTimeAtIpOutIn[0] - events->muStandAloneTofTimeAtIpOutIn[1],1.0);
		  mu0_mu1_StandAloneTofTimeAtIpInOut_hist->Fill(events->muStandAloneTofTimeAtIpInOut[0],events->muStandAloneTofTimeAtIpInOut[1],1.0);
		  mu0_mu1_StandAloneTofTimeAtIpOutIn_hist->Fill(events->muStandAloneTofTimeAtIpOutIn[0],events->muStandAloneTofTimeAtIpOutIn[1],1.0);

		  mu0_StandAlonePt_hist->Fill(events->muStandAlonePt[0],1.0);
		  mu0_StandAloneEta_hist->Fill(events->muStandAloneEta[0],1.0);
		  mu0_StandAlonePhi_hist->Fill(events->muStandAlonePhi[0],1.0);
		  mu0_StandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNormalizedChi2[0],1.0);
		  mu0_StandAloneTrackDxy_hist->Fill(events->muStandAloneTrackDxy[0],1.0);
		  mu0_StandAloneTrackDz_hist->Fill(events->muStandAloneTrackDz[0],1.0);
		  mu0_StandAloneTrackNHitsMuon_hist->Fill(events->muStandAloneTrackNHitsMuon[0],1.0);
		  mu0_StandAloneTrackNHitsCsc_hist->Fill(events->muStandAloneTrackNHitsCsc[0],1.0);
		  mu0_StandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsDt[0],1.0);
		  mu0_StandAloneTrackNHitsRpc_hist->Fill(events->muStandAloneTrackNHitsRpc[0],1.0);
		  mu0_StandAloneTrackNStations_hist->Fill(events->muStandAloneTrackNStations[0],1.0);
		  mu0_StandAloneTrackNChambersCsc_hist->Fill(events->muStandAloneTrackNChambersCsc[0],1.0);
		  mu0_StandAloneTrackNChambersDt_hist->Fill(events->muStandAloneTrackNChambersDt[0],1.0);
		  mu0_StandAloneTrackNChambersRpc_hist->Fill(events->muStandAloneTrackNChambersRpc[0],1.0);
		  mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNHitsRpc[0],events->muStandAloneTrackNormalizedChi2[0],1.0);
		  mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsRpc[0],events->muStandAloneTrackNHitsDt[0],1.0);

		  mu1_StandAlonePt_hist->Fill(events->muStandAlonePt[1],1.0);
		  mu1_StandAloneEta_hist->Fill(events->muStandAloneEta[1],1.0);
		  mu1_StandAlonePhi_hist->Fill(events->muStandAlonePhi[1],1.0);
		  mu1_StandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNormalizedChi2[1],1.0);
		  mu1_StandAloneTrackDxy_hist->Fill(events->muStandAloneTrackDxy[1],1.0);
		  mu1_StandAloneTrackDz_hist->Fill(events->muStandAloneTrackDz[1],1.0);
		  mu1_StandAloneTrackNHitsMuon_hist->Fill(events->muStandAloneTrackNHitsMuon[1],1.0);
		  mu1_StandAloneTrackNHitsCsc_hist->Fill(events->muStandAloneTrackNHitsCsc[1],1.0);
		  mu1_StandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsDt[1],1.0);
		  mu1_StandAloneTrackNHitsRpc_hist->Fill(events->muStandAloneTrackNHitsRpc[1],1.0);
		  mu1_StandAloneTrackNStations_hist->Fill(events->muStandAloneTrackNStations[1],1.0);
		  mu1_StandAloneTrackNChambersCsc_hist->Fill(events->muStandAloneTrackNChambersCsc[1],1.0);
		  mu1_StandAloneTrackNChambersDt_hist->Fill(events->muStandAloneTrackNChambersDt[1],1.0);
		  mu1_StandAloneTrackNChambersRpc_hist->Fill(events->muStandAloneTrackNChambersRpc[1],1.0);
		  mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNHitsRpc[1],events->muStandAloneTrackNormalizedChi2[1],1.0);
		  mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsRpc[1],events->muStandAloneTrackNHitsDt[1],1.0);
		}
		if (events->muStandAlonePhi[1]<0. && events->muStandAlonePhi[0]>0.) {
		  mu0_StandAloneTofTimeAtIpInOut_hist->Fill(events->muStandAloneTofTimeAtIpInOut[1],1.0);
		  mu0_StandAloneTofTimeAtIpOutIn_hist->Fill(events->muStandAloneTofTimeAtIpOutIn[1],1.0);
		  mu1_StandAloneTofTimeAtIpInOut_hist->Fill(events->muStandAloneTofTimeAtIpInOut[0],1.0);
		  mu1_StandAloneTofTimeAtIpOutIn_hist->Fill(events->muStandAloneTofTimeAtIpOutIn[0],1.0);
		  mudiff_StandAloneTofTimeAtIpInOut_hist->Fill(events->muStandAloneTofTimeAtIpInOut[1] - events->muStandAloneTofTimeAtIpInOut[0],1.0);
		  mudiff_StandAloneTofTimeAtIpOutIn_hist->Fill(events->muStandAloneTofTimeAtIpOutIn[1] - events->muStandAloneTofTimeAtIpOutIn[0],1.0);
		  mu0_mu1_StandAloneTofTimeAtIpInOut_hist->Fill(events->muStandAloneTofTimeAtIpInOut[1],events->muStandAloneTofTimeAtIpInOut[0],1.0);
		  mu0_mu1_StandAloneTofTimeAtIpOutIn_hist->Fill(events->muStandAloneTofTimeAtIpOutIn[1],events->muStandAloneTofTimeAtIpOutIn[0],1.0);

		  mu0_StandAlonePt_hist->Fill(events->muStandAlonePt[1],1.0);
		  mu0_StandAloneEta_hist->Fill(events->muStandAloneEta[1],1.0);
		  mu0_StandAlonePhi_hist->Fill(events->muStandAlonePhi[1],1.0);
		  mu0_StandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNormalizedChi2[1],1.0);
		  mu0_StandAloneTrackDxy_hist->Fill(events->muStandAloneTrackDxy[1],1.0);
		  mu0_StandAloneTrackDz_hist->Fill(events->muStandAloneTrackDz[1],1.0);
		  mu0_StandAloneTrackNHitsMuon_hist->Fill(events->muStandAloneTrackNHitsMuon[1],1.0);
		  mu0_StandAloneTrackNHitsCsc_hist->Fill(events->muStandAloneTrackNHitsCsc[1],1.0);
		  mu0_StandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsDt[1],1.0);
		  mu0_StandAloneTrackNHitsRpc_hist->Fill(events->muStandAloneTrackNHitsRpc[1],1.0);
		  mu0_StandAloneTrackNStations_hist->Fill(events->muStandAloneTrackNStations[1],1.0);
		  mu0_StandAloneTrackNChambersCsc_hist->Fill(events->muStandAloneTrackNChambersCsc[1],1.0);
		  mu0_StandAloneTrackNChambersDt_hist->Fill(events->muStandAloneTrackNChambersDt[1],1.0);
		  mu0_StandAloneTrackNChambersRpc_hist->Fill(events->muStandAloneTrackNChambersRpc[1],1.0);
		  mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNHitsRpc[1],events->muStandAloneTrackNormalizedChi2[1],1.0);
		  mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsRpc[1],events->muStandAloneTrackNHitsDt[1],1.0);

		  mu1_StandAlonePt_hist->Fill(events->muStandAlonePt[0],1.0);
		  mu1_StandAloneEta_hist->Fill(events->muStandAloneEta[0],1.0);
		  mu1_StandAlonePhi_hist->Fill(events->muStandAlonePhi[0],1.0);
		  mu1_StandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNormalizedChi2[0],1.0);
		  mu1_StandAloneTrackDxy_hist->Fill(events->muStandAloneTrackDxy[0],1.0);
		  mu1_StandAloneTrackDz_hist->Fill(events->muStandAloneTrackDz[0],1.0);
		  mu1_StandAloneTrackNHitsMuon_hist->Fill(events->muStandAloneTrackNHitsMuon[0],1.0);
		  mu1_StandAloneTrackNHitsCsc_hist->Fill(events->muStandAloneTrackNHitsCsc[0],1.0);
		  mu1_StandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsDt[0],1.0);
		  mu1_StandAloneTrackNHitsRpc_hist->Fill(events->muStandAloneTrackNHitsRpc[0],1.0);
		  mu1_StandAloneTrackNStations_hist->Fill(events->muStandAloneTrackNStations[0],1.0);
		  mu1_StandAloneTrackNChambersCsc_hist->Fill(events->muStandAloneTrackNChambersCsc[0],1.0);
		  mu1_StandAloneTrackNChambersDt_hist->Fill(events->muStandAloneTrackNChambersDt[0],1.0);
		  mu1_StandAloneTrackNChambersRpc_hist->Fill(events->muStandAloneTrackNChambersRpc[0],1.0);
		  mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNormalizedChi2_hist->Fill(events->muStandAloneTrackNHitsRpc[0],events->muStandAloneTrackNormalizedChi2[0],1.0);
		  mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNHitsDt_hist->Fill(events->muStandAloneTrackNHitsRpc[0],events->muStandAloneTrackNHitsDt[0],1.0);
		}

	      } //end of other cuts
	    } //end of if one muon in upper half and other muon in lower half
	  }// end of Zmumu
	}//end of if 2 standalone muons

	if (pass_other_cut > 0) events_pass_other_cut++;
	if (pass_other_cut > 9) cout<<"For "<<pass_other_cut<<" 'good' standalone muons, the run number is: "<<events->run<<", event number is: "<<events->id<<endl;
	
	muStandAloneDTTof_N_hist->Fill(events->muStandAloneDTTof_N,1.0);
	for (UInt_t j=0; j<events->muStandAloneDTTof_N; j++) {
	  //cout<<"TOF DT mu number "<<j<<endl;
	  muStandAloneDTTofDirection_hist->Fill(events->muStandAloneDTTofDirection[j],1.0);
	  muStandAloneDTTofNDof_hist->Fill(events->muStandAloneDTTofNDof[j],1.0);
	  muStandAloneDTTofInverseBeta_hist->Fill(events->muStandAloneDTTofInverseBeta[j],1.0);
	  muStandAloneDTTofInverseBetaErr_hist->Fill(events->muStandAloneDTTofInverseBetaErr[j],1.0);
	  muStandAloneDTTofFreeInverseBeta_hist->Fill(events->muStandAloneDTTofFreeInverseBeta[j],1.0);
	  muStandAloneDTTofFreeInverseBetaErr_hist->Fill(events->muStandAloneDTTofFreeInverseBetaErr[j],1.0);
	  muStandAloneDTTofTimeAtIpInOut_hist->Fill(events->muStandAloneDTTofTimeAtIpInOut[j],1.0);
	  muStandAloneDTTofTimeAtIpInOutErr_hist->Fill(events->muStandAloneDTTofTimeAtIpInOutErr[j],1.0);
	  muStandAloneDTTofTimeAtIpOutIn_hist->Fill(events->muStandAloneDTTofTimeAtIpOutIn[j],1.0);
	  muStandAloneDTTofTimeAtIpOutInErr_hist->Fill(events->muStandAloneDTTofTimeAtIpOutInErr[j],1.0);
	}
	
	muStandAloneCSCTof_N_hist->Fill(events->muStandAloneCSCTof_N,1.0);
	for (UInt_t j=0; j<events->muStandAloneCSCTof_N; j++) {
	  //cout<<"TOF CSC mu number "<<j<<endl;
	  muStandAloneCSCTofDirection_hist->Fill(events->muStandAloneCSCTofDirection[j],1.0);
	  muStandAloneCSCTofNDof_hist->Fill(events->muStandAloneCSCTofNDof[j],1.0);
	  muStandAloneCSCTofInverseBeta_hist->Fill(events->muStandAloneCSCTofInverseBeta[j],1.0);
	  muStandAloneCSCTofInverseBetaErr_hist->Fill(events->muStandAloneCSCTofInverseBetaErr[j],1.0);
	  muStandAloneCSCTofFreeInverseBeta_hist->Fill(events->muStandAloneCSCTofFreeInverseBeta[j],1.0);
	  muStandAloneCSCTofFreeInverseBetaErr_hist->Fill(events->muStandAloneCSCTofFreeInverseBetaErr[j],1.0);
	  muStandAloneCSCTofTimeAtIpInOut_hist->Fill(events->muStandAloneCSCTofTimeAtIpInOut[j],1.0);
	  muStandAloneCSCTofTimeAtIpInOutErr_hist->Fill(events->muStandAloneCSCTofTimeAtIpInOutErr[j],1.0);
	  muStandAloneCSCTofTimeAtIpOutIn_hist->Fill(events->muStandAloneCSCTofTimeAtIpOutIn[j],1.0);
	  muStandAloneCSCTofTimeAtIpOutInErr_hist->Fill(events->muStandAloneCSCTofTimeAtIpOutInErr[j],1.0);
	}
	
	refitMuStandAloneDTTof_N_hist->Fill(events->refitMuStandAloneDTTof_N,1.0);
	for (UInt_t j=0; j<events->refitMuStandAloneDTTof_N; j++) {
	  //cout<<"DT re-reco TOF DT mu number "<<j<<endl;
	  refitMuStandAloneDTTofDirection_hist->Fill(events->refitMuStandAloneDTTofDirection[j],1.0);
	  refitMuStandAloneDTTofNDof_hist->Fill(events->refitMuStandAloneDTTofNDof[j],1.0);
	  refitMuStandAloneDTTofInverseBeta_hist->Fill(events->refitMuStandAloneDTTofInverseBeta[j],1.0);
	  refitMuStandAloneDTTofInverseBetaErr_hist->Fill(events->refitMuStandAloneDTTofInverseBetaErr[j],1.0);
	  refitMuStandAloneDTTofFreeInverseBeta_hist->Fill(events->refitMuStandAloneDTTofFreeInverseBeta[j],1.0);
	  refitMuStandAloneDTTofFreeInverseBetaErr_hist->Fill(events->refitMuStandAloneDTTofFreeInverseBetaErr[j],1.0);
	  refitMuStandAloneDTTofTimeAtIpInOut_hist->Fill(events->refitMuStandAloneDTTofTimeAtIpInOut[j],1.0);
	  refitMuStandAloneDTTofTimeAtIpInOutErr_hist->Fill(events->refitMuStandAloneDTTofTimeAtIpInOutErr[j],1.0);
	  refitMuStandAloneDTTofTimeAtIpOutIn_hist->Fill(events->refitMuStandAloneDTTofTimeAtIpOutIn[j],1.0);
	  refitMuStandAloneDTTofTimeAtIpOutInErr_hist->Fill(events->refitMuStandAloneDTTofTimeAtIpOutInErr[j],1.0);
	}
	
	refitMuStandAloneCSCTof_N_hist->Fill(events->refitMuStandAloneCSCTof_N,1.0);
	for (UInt_t j=0; j<events->refitMuStandAloneCSCTof_N; j++) {
	  //cout<<"DT re-reco TOF CSC mu number "<<j<<endl;
	  refitMuStandAloneCSCTofDirection_hist->Fill(events->refitMuStandAloneCSCTofDirection[j],1.0);
	  refitMuStandAloneCSCTofNDof_hist->Fill(events->refitMuStandAloneCSCTofNDof[j],1.0);
	  refitMuStandAloneCSCTofInverseBeta_hist->Fill(events->refitMuStandAloneCSCTofInverseBeta[j],1.0);
	  refitMuStandAloneCSCTofInverseBetaErr_hist->Fill(events->refitMuStandAloneCSCTofInverseBetaErr[j],1.0);
	  refitMuStandAloneCSCTofFreeInverseBeta_hist->Fill(events->refitMuStandAloneCSCTofFreeInverseBeta[j],1.0);
	  refitMuStandAloneCSCTofFreeInverseBetaErr_hist->Fill(events->refitMuStandAloneCSCTofFreeInverseBetaErr[j],1.0);
	  refitMuStandAloneCSCTofTimeAtIpInOut_hist->Fill(events->refitMuStandAloneCSCTofTimeAtIpInOut[j],1.0);
	  refitMuStandAloneCSCTofTimeAtIpInOutErr_hist->Fill(events->refitMuStandAloneCSCTofTimeAtIpInOutErr[j],1.0);
	  refitMuStandAloneCSCTofTimeAtIpOutIn_hist->Fill(events->refitMuStandAloneCSCTofTimeAtIpOutIn[j],1.0);
	  refitMuStandAloneCSCTofTimeAtIpOutInErr_hist->Fill(events->refitMuStandAloneCSCTofTimeAtIpOutInErr[j],1.0);
	}
	
      }// end of less than 3 standalone muons per event
      } //end of pass trigger
    }//end of bx_cut
  }//end of loop over entries


  cout<<endl;
  cout<<"number of events passing bx cut is: "<<pass_bx_cut<<endl;
  cout<<"number of events passing trigger cut is: "<<pass_trigger_cut<<endl;
  cout<<"number of events passing at least one SA cut is: "<<pass_atleast1SA_cut<<endl;
  cout<<"number of events passing pt[0]>30 cut is: "<<pass_pt30_cut<<endl;
  cout<<"number of events passing |eta[0]|<2.1 cut is: "<<pass_eta2p1_cut<<endl;
  cout<<"number of events passing |eta[0]|<1.0 cut is: "<<pass_eta1p0_cut<<endl;

  cout<<"number of events passing other cut is: "<<events_pass_other_cut<<endl;
  cout<<"number of events with one muon passing other cut with rpc hits is: "<<events_1muon_pass_other_cut_with_rpcs<<endl;
  cout<<"number of muon0 with two muons passing other cut with rpc hits is: "<<events_2muon_muon0_pass_other_cut_with_rpcs<<endl;
  cout<<"number of muon1 with two muons passing other cut with rpc hits is: "<<events_2muon_muon1_pass_other_cut_with_rpcs<<endl;

  cout<<endl;
  cout<<"number of single muon events with 0BX is: "<< singlemuon_0BX<<endl;
  cout<<"number of single muon events with positive constant BX is: "<< singlemuon_positiveConstantBX<<endl;
  cout<<"number of single muon events with positive or 0 increasing BX is: "<< singlemuon_positiveOr0IncreasingBX<<endl;
  cout<<"number of single muon events with positive or 0 decreasing BX is: "<< singlemuon_positiveOr0DecreasingBX<<endl;
  cout<<"number of single muon events with positive or 0 strange BX is: "<< singlemuon_positiveOr0StrangeBX<<endl;
  cout<<"number of single muon events with negative constant BX is: "<< singlemuon_negativeConstantBX<<endl;
  cout<<"number of single muon events with negative or 0 increasing BX is: "<< singlemuon_negativeOr0IncreasingBX<<endl;
  cout<<"number of single muon events with negative or 0 decreasing BX is: "<< singlemuon_negativeOr0DecreasingBX<<endl;
  cout<<"number of single muon events with negative or 0 strange BX is: "<< singlemuon_negativeOr0StrangeBX<<endl;

  cout<<endl;
  cout<<"percentage of single muon events with 0BX is: "<< 100.0*singlemuon_0BX/events_1muon_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of single muon events with positive constant BX is: "<< 100.0*singlemuon_positiveConstantBX/events_1muon_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of single muon events with positive or 0 increasing BX is: "<< 100.0*singlemuon_positiveOr0IncreasingBX/events_1muon_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of single muon events with positive or 0 decreasing BX is: "<< 100.0*singlemuon_positiveOr0DecreasingBX/events_1muon_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of single muon events with positive or 0 strange BX is: "<< 100.0*singlemuon_positiveOr0StrangeBX/events_1muon_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of single muon events with negative constant BX is: "<< 100.0*singlemuon_negativeConstantBX/events_1muon_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of single muon events with negative or 0 increasing BX is: "<< 100.0*singlemuon_negativeOr0IncreasingBX/events_1muon_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of single muon events with negative or 0 decreasing BX is: "<< 100.0*singlemuon_negativeOr0DecreasingBX/events_1muon_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of single muon events with negative or 0 strange BX is: "<< 100.0*singlemuon_negativeOr0StrangeBX/events_1muon_pass_other_cut_with_rpcs<<endl;

  cout<<endl;
  cout<<"number with 0 rpc hits is: "<<rpchitsIs0<<endl;
  cout<<"number with 1 rpc hits is: "<<rpchitsIs1<<endl;
  cout<<"number with 2 rpc hits is: "<<rpchitsIs2<<endl;
  cout<<"number with 3 rpc hits is: "<<rpchitsIs3<<endl;
  cout<<"number with 4 rpc hits is: "<<rpchitsIs4<<endl;
  cout<<"number with 5 rpc hits is: "<<rpchitsIs5<<endl;
  cout<<"number with 6 rpc hits is: "<<rpchitsIs6<<endl;
  cout<<"number with 7 rpc hits is: "<<rpchitsIs7<<endl;

  cout<<endl;
  cout<<"percentage with 0 rpc hits is: "<<100.0*rpchitsIs0/singlemuon_0BX<<endl;
  cout<<"percentage with 1 rpc hits is: "<<100.0*rpchitsIs1/singlemuon_0BX<<endl;
  cout<<"percentage with 2 rpc hits is: "<<100.0*rpchitsIs2/singlemuon_0BX<<endl;
  cout<<"percentage with 3 rpc hits is: "<<100.0*rpchitsIs3/singlemuon_0BX<<endl;
  cout<<"percentage with 4 rpc hits is: "<<100.0*rpchitsIs4/singlemuon_0BX<<endl;
  cout<<"percentage with 5 rpc hits is: "<<100.0*rpchitsIs5/singlemuon_0BX<<endl;
  cout<<"percentage with 6 rpc hits is: "<<100.0*rpchitsIs6/singlemuon_0BX<<endl;
  cout<<"percentage with 7 rpc hits is: "<<100.0*rpchitsIs7/singlemuon_0BX<<endl;

  cout<<endl;
  cout<<"number of double muon events for muon0 with 0BX is: "<< doublemuon_muon0_0BX<<endl;
  cout<<"number of double muon events for muon0 with positive constant BX is: "<< doublemuon_muon0_positiveConstantBX<<endl;
  cout<<"number of double muon events for muon0 with positive or 0 increasing BX is: "<< doublemuon_muon0_positiveOr0IncreasingBX<<endl;
  cout<<"number of double muon events for muon0 with positive or 0 decreasing BX is: "<< doublemuon_muon0_positiveOr0DecreasingBX<<endl;
  cout<<"number of double muon events for muon0 with positive or 0 strange BX is: "<< doublemuon_muon0_positiveOr0StrangeBX<<endl;
  cout<<"number of double muon events for muon0 with negative constant BX is: "<< doublemuon_muon0_negativeConstantBX<<endl;
  cout<<"number of double muon events for muon0 with negative or 0 increasing BX is: "<< doublemuon_muon0_negativeOr0IncreasingBX<<endl;
  cout<<"number of double muon events for muon0 with negative or 0 decreasing BX is: "<< doublemuon_muon0_negativeOr0DecreasingBX<<endl;
  cout<<"number of double muon events for muon0 with negative or 0 strange BX is: "<< doublemuon_muon0_negativeOr0StrangeBX<<endl;

  cout<<endl;
  cout<<"percentage of double muon events for muon0 with 0BX is: "<< 100.0*doublemuon_muon0_0BX/events_2muon_muon0_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon0 with positive constant BX is: "<< 100.0*doublemuon_muon0_positiveConstantBX/events_2muon_muon0_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon0 with positive or 0 increasing BX is: "<< 100.0*doublemuon_muon0_positiveOr0IncreasingBX/events_2muon_muon0_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon0 with positive or 0 decreasing BX is: "<< 100.0*doublemuon_muon0_positiveOr0DecreasingBX/events_2muon_muon0_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon0 with positive or 0 strange BX is: "<< 100.0*doublemuon_muon0_positiveOr0StrangeBX/events_2muon_muon0_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon0 with negative constant BX is: "<< 100.0*doublemuon_muon0_negativeConstantBX/events_2muon_muon0_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon0 with negative or 0 increasing BX is: "<< 100.0*doublemuon_muon0_negativeOr0IncreasingBX/events_2muon_muon0_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon0 with negative or 0 decreasing BX is: "<< 100.0*doublemuon_muon0_negativeOr0DecreasingBX/events_2muon_muon0_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon0 with negative or 0 strange BX is: "<< 100.0*doublemuon_muon0_negativeOr0StrangeBX/events_2muon_muon0_pass_other_cut_with_rpcs<<endl;

  cout<<endl;
  cout<<"number of double muon events for muon1 with 0BX is: "<< doublemuon_muon1_0BX<<endl;
  cout<<"number of double muon events for muon1 with positive constant BX is: "<< doublemuon_muon1_positiveConstantBX<<endl;
  cout<<"number of double muon events for muon1 with positive or 0 increasing BX is: "<< doublemuon_muon1_positiveOr0IncreasingBX<<endl;
  cout<<"number of double muon events for muon1 with positive or 0 decreasing BX is: "<< doublemuon_muon1_positiveOr0DecreasingBX<<endl;
  cout<<"number of double muon events for muon1 with positive or 0 strange BX is: "<< doublemuon_muon1_positiveOr0StrangeBX<<endl;
  cout<<"number of double muon events for muon1 with negative constant BX is: "<< doublemuon_muon1_negativeConstantBX<<endl;
  cout<<"number of double muon events for muon1 with negative or 0 increasing BX is: "<< doublemuon_muon1_negativeOr0IncreasingBX<<endl;
  cout<<"number of double muon events for muon1 with negative or 0 decreasing BX is: "<< doublemuon_muon1_negativeOr0DecreasingBX<<endl;
  cout<<"number of double muon events for muon1 with negative or 0 strange BX is: "<< doublemuon_muon1_negativeOr0StrangeBX<<endl;

  cout<<endl;
  cout<<"percentage of double muon events for muon1 with 0BX is: "<< 100.0*doublemuon_muon1_0BX/events_2muon_muon1_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon1 with positive constant BX is: "<< 100.0*doublemuon_muon1_positiveConstantBX/events_2muon_muon1_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon1 with positive or 0 increasing BX is: "<< 100.0*doublemuon_muon1_positiveOr0IncreasingBX/events_2muon_muon1_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon1 with positive or 0 decreasing BX is: "<< 100.0*doublemuon_muon1_positiveOr0DecreasingBX/events_2muon_muon1_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon1 with positive or 0 strange BX is: "<< 100.0*doublemuon_muon1_positiveOr0StrangeBX/events_2muon_muon1_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon1 with negative constant BX is: "<< 100.0*doublemuon_muon1_negativeConstantBX/events_2muon_muon1_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon1 with negative or 0 increasing BX is: "<< 100.0*doublemuon_muon1_negativeOr0IncreasingBX/events_2muon_muon1_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon1 with negative or 0 decreasing BX is: "<< 100.0*doublemuon_muon1_negativeOr0DecreasingBX/events_2muon_muon1_pass_other_cut_with_rpcs<<endl;
  cout<<"percentage of double muon events for muon1 with negative or 0 strange BX is: "<< 100.0*doublemuon_muon1_negativeOr0StrangeBX/events_2muon_muon1_pass_other_cut_with_rpcs<<endl;

  cout<<endl;
  cout<<"percentage of double muon events for muon0 with 0 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon0Is0/doublemuon_muon0_0BX<<endl;
  cout<<"percentage of double muon events for muon0 with 1 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon0Is1/doublemuon_muon0_0BX<<endl;
  cout<<"percentage of double muon events for muon0 with 2 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon0Is2/doublemuon_muon0_0BX<<endl;
  cout<<"percentage of double muon events for muon0 with 3 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon0Is3/doublemuon_muon0_0BX<<endl;
  cout<<"percentage of double muon events for muon0 with 4 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon0Is4/doublemuon_muon0_0BX<<endl;
  cout<<"percentage of double muon events for muon0 with 5 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon0Is5/doublemuon_muon0_0BX<<endl;
  cout<<"percentage of double muon events for muon0 with 6 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon0Is6/doublemuon_muon0_0BX<<endl;
  cout<<"percentage of double muon events for muon0 with 7 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon0Is7/doublemuon_muon0_0BX<<endl;

  cout<<endl;
  cout<<"percentage of double muon events for muon1 with 0 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon1Is0/doublemuon_muon1_0BX<<endl;
  cout<<"percentage of double muon events for muon1 with 1 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon1Is1/doublemuon_muon1_0BX<<endl;
  cout<<"percentage of double muon events for muon1 with 2 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon1Is2/doublemuon_muon1_0BX<<endl;
  cout<<"percentage of double muon events for muon1 with 3 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon1Is3/doublemuon_muon1_0BX<<endl;
  cout<<"percentage of double muon events for muon1 with 4 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon1Is4/doublemuon_muon1_0BX<<endl;
  cout<<"percentage of double muon events for muon1 with 5 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon1Is5/doublemuon_muon1_0BX<<endl;
  cout<<"percentage of double muon events for muon1 with 6 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon1Is6/doublemuon_muon1_0BX<<endl;
  cout<<"percentage of double muon events for muon1 with 7 rpc hits is: "<<100.0*rpchitsDoubleMuonMuon1Is7/doublemuon_muon1_0BX<<endl;

  cout<<"bad is: "<<bad<<endl;  

  fnew->Write();
  
  return(0);
}


