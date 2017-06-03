//makes reduced ntuples with analysis cuts

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
  if ((bx_cut=="with_bx_cut" || bx_cut=="without_bx_cut") && (other_cut=="with_other_cut" || other_cut=="without_other_cut")) new_file = "root://eoscms//eos/cms/store/user/jalimena/reducedNtuples/" + file_dataset + "/stoppedHSCPMuonTree.root";
  if (bx_cut!="with_bx_cut" && bx_cut!="without_bx_cut") cout<<"problem with bx_cut assignment!!!"<<endl;
  if (other_cut!="with_other_cut" && other_cut!="without_other_cut") cout<<"problem with other_cut assignment!!!"<<endl;

  TFile* fnew = new TFile(new_file, "recreate");
  cout<<"opened output file"<<endl;


  //get tree, create new tree
  TTree* tree = (TTree*)f1->Get("stoppedHSCPMuonTree/StoppedHSCPMuonTree");
  tree->Print();
  tree->Show(0);
  TTree* tree_new = new TTree("stoppedHSCPMuonTree/StoppedHSCPMuonTree","tree");

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
  vector<Int_t> muStandAloneTrackNHits;
  vector<Int_t> muStandAloneTrackNLost;
  vector<Double_t> muStandAloneTrackP;
  vector<Int_t> muStandAloneTrackQuality;
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

  //set new branch address
  tree_new->Branch("events",&events);


  //get entries for data_tree (read in the old tree), set new variables, fill new tree
  Int_t nentries = tree->GetEntriesFast();
  //Int_t nentries = tree->GetEntries();
  cout<<"number of entries is: "<<nentries<<endl;
  
  int pass_bx_cut = 0;
  int events_pass_other_cut = 0;

  vector<int> x;

  for (Int_t i=0; i<nentries; i++) {
    //for (Int_t i=0; i<2000; i++) {    
    //for (Int_t i=0; i<100; i++) {
    tree->GetEntry(i);
    
    if ( (do_bx_cut && TMath::Abs(events->bxWrtCollision)>=2. && TMath::Abs(events->bxWrtBunch)>=2.) || (!do_bx_cut) ){
      pass_bx_cut++;
      if ( (do_other_cut && events->mu_StandAlone_N<3) || (!do_other_cut) ){
	
	//cout<<endl<<"For event "<<i<<", event # is: "<<events->id<<", run # is: "<<events->run<<", mu_StandAlone_N is: "<<events->mu_StandAlone_N<<", mu_RefittedStandAlone_N is: "<<events->mu_RefittedStandAlone_N<<", muStandAloneTof_N is: "<<events->muStandAloneTof_N<<", refitMuStandAloneTof_N is: "<<events->refitMuStandAloneTof_N<<endl;
	
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
	    if ( (do_other_cut && TMath::Abs(events->muStandAloneEta[j])<1.0 && events->muStandAlonePhi[j]>0.5 && events->muStandAlonePhi[j]<(TMath::Pi()-0.5) && events->muStandAloneTofDirection[j]!=0 && events->muStandAloneTofNDof[j]>6 && events->DTSegment_N>3 && pass_pt_cut[j] && TMath::Abs(events->muStandAloneTofTimeAtIpInOut[j])<50.) || (!do_other_cut) ){
	      //if ( (do_other_cut && TMath::Abs(events->muStandAloneEta[j])<1.0 && events->muStandAlonePhi[j]<-0.5 && events->muStandAlonePhi[j]>(-(TMath::Pi()-0.5)) && events->muStandAloneTofDirection[j]!=0 && events->muStandAloneTofNDof[j]>6 && events->DTSegment_N>3 && pass_pt_cut[j] && TMath::Abs(events->muStandAloneTofTimeAtIpInOut[j])<50.) || (!do_other_cut) ){
	      pass_other_cut++;
	      
	      //for (UInt_t j=0; j<events->mu_StandAlone_N; j++) {
	      cout<<endl<<"For event "<<i<<", event # is: "<<events->id<<", run # is: "<<events->run<<", mu_StandAlone_N is: "<<events->mu_StandAlone_N<<", mu_RefittedStandAlone_N is: "<<events->mu_RefittedStandAlone_N<<", muStandAloneTof_N is: "<<events->muStandAloneTof_N<<", refitMuStandAloneTof_N is: "<<events->refitMuStandAloneTof_N<<endl;
	      cout<<"For standalone mu number "<<j<<", after the cuts pt is: "<<events->muStandAlonePt[j]<<", eta is: "<<events->muStandAloneEta[j]<<", phi is: "<<events->muStandAlonePhi[j]<<", direction is: "<<events->muStandAloneTofDirection[j]<<", ndof is: "<<events->muStandAloneTofNDof[j]<<", number of DT segments is: "<<events->DTSegment_N<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[j]<<endl;

	      
	    }//end of other cut
	  }//end of loop over standalone muons
	  muStandAlone_N_other_cut_hist->Fill(pass_other_cut,1.0);
	}//end of if 1 standalone muon
      
	if(events->mu_StandAlone_N==2){
	  if ( 
	      (events->muStandAlonePhi[0]>0.5 && events->muStandAlonePhi[0]<(TMath::Pi()-0.5) && 
	       events->muStandAlonePhi[1] < (-0.5) && events->muStandAlonePhi[1]>(-1.0*TMath::Pi()+0.5) )
	      || 
	      (events->muStandAlonePhi[1]>0.5 && events->muStandAlonePhi[1]<(TMath::Pi()-0.5) &&  
	       events->muStandAlonePhi[0]< (-0.5) && events->muStandAlonePhi[0]>(-1.0*TMath::Pi()+0.5)  ) ){
	    if ( (do_other_cut && TMath::Abs(events->muStandAloneEta[0])<1.0 && TMath::Abs(events->muStandAloneEta[1])<1.0 && events->muStandAloneTofDirection[0]!=0 && events->muStandAloneTofDirection[1]!=0 && events->muStandAloneTofNDof[0]>6 && events->muStandAloneTofNDof[1]>6 && events->DTSegment_N>3 && pass_pt_cut[0] && pass_pt_cut[1] && TMath::Abs(events->muStandAloneTofTimeAtIpInOut[0])<50. && TMath::Abs(events->muStandAloneTofTimeAtIpInOut[1])<50.) || (!do_other_cut) ){
	      //cout<<"For standalone mu number "<<0<<", after the cuts pt is: "<<events->muStandAlonePt[0]<<", eta is: "<<events->muStandAloneEta[0]<<", phi is: "<<events->muStandAlonePhi[0]<<", direction is: "<<events->muStandAloneTofDirection[0]<<", ndof is: "<<events->muStandAloneTofNDof[0]<<", number of DT segments is: "<<events->DTSegment_N<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[0]<<endl;
	      //cout<<"For standalone mu number "<<1<<", after the cuts pt is: "<<events->muStandAlonePt[1]<<", eta is: "<<events->muStandAloneEta[1]<<", phi is: "<<events->muStandAlonePhi[1]<<", direction is: "<<events->muStandAloneTofDirection[1]<<", ndof is: "<<events->muStandAloneTofNDof[1]<<", number of DT segments is: "<<events->DTSegment_N<<", TimeAtIpInOut is: "<<events->muStandAloneTofTimeAtIpInOut[1]<<endl;

	      if (events->muStandAlonePhi[0]<0. && events->muStandAlonePhi[1]>0.) {
	      }
	      if (events->muStandAlonePhi[1]<0. && events->muStandAlonePhi[0]>0.) {
	      }

	    } //end of other cuts
	  } //end of if one muon in upper half and other muon in lower half
	}//end of if 2 standalone muons

	if (pass_other_cut > 0) events_pass_other_cut++;
	if (pass_other_cut > 9) cout<<"For "<<pass_other_cut<<" 'good' standalone muons, the run number is: "<<events->run<<", event number is: "<<events->id<<endl;
	
	tree_new->Fill();
      }// end of less than 3 standalone muons per event
    }//end of bx_cut
  }//end of loop over entries
  
  cout<<"number of events passing bx cut is: "<<pass_bx_cut<<endl;
  cout<<"number of events passing other cut is: "<<events_pass_other_cut<<endl;
  
  fnew->Write();
  
  return(0);
}


