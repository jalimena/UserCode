//void findTreeValues_makehistos_Ntuples(const string file_dataset, bool castor){
{
  cout<<"started function"<<endl;
  //makes histograms from ntuples

  using namespace std;  
  cout<<"namespace"<<endl;
  gSystem->Load("libStoppedHSCPMuonNtuples");
  cout<<"loaded library"<<endl;

  //if (castor==true) TString file = "rfio:/castor/cern.ch/user/j/jalimena/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";
  //else TString file = "root://eoscms//eos/cms/store/user/jalimena/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";
  TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_5_3_2_patch1/src/StoppedHSCPMuon/Ntuples/test/stoppedHSCPMuonTree.root";
  f1 = TFile::Open(file);

  //TString new_file = "/afs/cern.ch/user/j/jalimena/public/histos/stoppedHSCPMuonHistos_" + file_dataset + ".root";
  //TFile fnew(new_file, "recreate");
  cout<<"opened files"<<endl;

  //get tree
  TTree* tree = (TTree*)f1->Get("stoppedHSCPMuonTree/StoppedHSCPMuonTree");
  //tree->Print();
  //tree->Show(0);

  StoppedHSCPMuonEvent* events = new StoppedHSCPMuonEvent();


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
  UInt_t muStandAloneTof_N;
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
  UInt_t muStandAloneDTTof_N;
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
  UInt_t muStandAloneCSCTof_N;
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
  UInt_t refitMuStandAloneTof_N;
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
  UInt_t refitMuStandAloneDTTof_N;
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
  UInt_t refitMuStandAloneCSCTof_N;
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
  vector<Double_t> hfRecHitTime;
  vector<Double_t> hfRecHitEta;
  vector<Double_t> hfRecHitPhi;
  vector<Int_t>   hfRecHitIEta;
  vector<Int_t>   hfRecHitIPhi;
  vector<Int_t>   hfRecHitDepth;
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

  TH1D* mu_N_hist = new TH1D("mu_N_hist","Number of Muons",100,0,100);
  TH1D* muPt_hist = new TH1D("muPt_hist","Reco Muon p_{T}",1000,0,1000);
  TH1D* muEta_hist = new TH1D("muEta_hist","Reco Muon #eta",120,-6,6);
  TH1D* muPhi_hist = new TH1D("muPhi_hist","Reco Muon #phi",64,-6.2832,6.2832);
  TH1D* muType_hist = new TH1D("muType_hist","Reco Muon Type",4000,0,4000);
  TH2D* muEta_muPhi_hist = new TH2D("muEta_muPhi_hist","Reco Muon #eta vs #phi",120,-6,6,64,-6.2832,6.2832);

  TH1D* muCosmic_N_hist = new TH1D("muCosmic_N_hist","Number of Cosmic Muons",100,0,100);
  TH1D* muCosmicPt_hist = new TH1D("muCosmicPt_hist","Cosmic Muon p_{T}",1000,0,1000);
  TH1D* muCosmicEta_hist = new TH1D("muCosmicEta_hist","Cosmic Muon #eta",120,-6,6);
  TH1D* muCosmicPhi_hist = new TH1D("muCosmicPhi_hist","Cosmic Muon #phi",64,-6.2832,6.2832);
  TH1D* muCosmicType_hist = new TH1D("muCosmicType_hist","Cosmic Muon Type",4000,0,4000);
  TH2D* muCosmicEta_muCosmicPhi_hist = new TH2D("muCosmicEta_muCosmicPhi_hist","Cosmic Muon #eta vs #phi",120,-6,6,64,-6.2832,6.2832);

  TH1D* muStandAlone_N_hist = new TH1D("muStandAlone_N_hist","Number of StandAlone Muons",100,0,100);
  TH1D* muStandAlonePt_hist = new TH1D("muStandAlonePt_hist","StandAlone Muon p_{T}",1000,0,1000);
  TH1D* muStandAloneEta_hist = new TH1D("muStandAloneEta_hist","StandAlone Muon #eta",120,-6,6);
  TH1D* muStandAlonePhi_hist = new TH1D("muStandAlonePhi_hist","StandAlone Muon #phi",64,-6.2832,6.2832);
  TH2D* muStandAloneEta_muStandAlonePhi_hist = new TH2D("muStandAloneEta_muStandAlonePhi_hist","StandAlone Muon #eta vs #phi",120,-6,6,64,-6.2832,6.2832);

  TH1D* muRefittedStandAlone_N_hist = new TH1D("muRefittedStandAlone_N_hist","Number of Refitted StandAlone Muons",100,0,100);
  TH1D* muRefittedStandAlonePt_hist = new TH1D("muRefittedStandAlonePt_hist","Refitted StandAlone Muon p_{T}",1000,0,1000);
  TH1D* muRefittedStandAloneEta_hist = new TH1D("muRefittedStandAloneEta_hist","Refitted StandAlone Muon #eta",120,-6,6);
  TH1D* muRefittedStandAlonePhi_hist = new TH1D("muRefittedStandAlonePhi_hist","Refitted StandAlone Muon #phi",64,-6.2832,6.2832);
  TH2D* muRefittedStandAloneEta_muRefittedStandAlonePhi_hist = new TH2D("muRefittedStandAloneEta_muRefittedStandAlonePhi_hist","Refitted StandAlone Muon #eta vs #phi",120,-6,6,64,-6.2832,6.2832);

  TH1D* muStandAloneTof_N_hist = new TH1D("muStandAloneTof_N_hist","Number of StandAlone Muons in TOF Calculation",100,0,100);
  TH1D* muStandAloneTofDirection_hist = new TH1D("muStandAloneTofDirection_hist","Direction of StandAlone Muons",3,-1,2);
  TH1D* muStandAloneTofNDof_hist = new TH1D("muStandAloneTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom",200,0,200);
  TH1D* muStandAloneTofInverseBeta_hist = new TH1D("muStandAloneTofInverseBeta_hist","#beta^{-1} of StandAlone Muons",1000,0,50);
  TH1D* muStandAloneTofInverseBetaErr_hist = new TH1D("muStandAloneTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneTofFreeInverseBeta_hist = new TH1D("muStandAloneTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons",8000,-2000,2000);
  TH1D* muStandAloneTofFreeInverseBetaErr_hist = new TH1D("muStandAloneTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneTofTimeAtIpInOut_hist = new TH1D("muStandAloneTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons",500,-200,300);
  TH1D* muStandAloneTofTimeAtIpInOutErr_hist = new TH1D("muStandAloneTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons",100,0,20);
  TH1D* muStandAloneTofTimeAtIpOutIn_hist = new TH1D("muStandAloneTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons",500,-200,300);
  TH1D* muStandAloneTofTimeAtIpOutInErr_hist = new TH1D("muStandAloneTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons",100,0,20);

  TH1D* muStandAloneDTTof_N_hist = new TH1D("muStandAloneDTTof_N_hist","Number of StandAlone Muons in TOF Calculation",100,0,100);
  TH1D* muStandAloneDTTofDirection_hist = new TH1D("muStandAloneDTTofDirection_hist","Direction of StandAlone Muons",3,-1,2);
  TH1D* muStandAloneDTTofNDof_hist = new TH1D("muStandAloneDTTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom",200,0,200);
  TH1D* muStandAloneDTTofInverseBeta_hist = new TH1D("muStandAloneDTTofInverseBeta_hist","#beta^{-1} of StandAlone Muons",1000,0,50);
  TH1D* muStandAloneDTTofInverseBetaErr_hist = new TH1D("muStandAloneDTTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneDTTofFreeInverseBeta_hist = new TH1D("muStandAloneDTTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons",8000,-2000,2000);
  TH1D* muStandAloneDTTofFreeInverseBetaErr_hist = new TH1D("muStandAloneDTTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneDTTofTimeAtIpInOut_hist = new TH1D("muStandAloneDTTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons",500,-200,300);
  TH1D* muStandAloneDTTofTimeAtIpInOutErr_hist = new TH1D("muStandAloneDTTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons",100,0,20);
  TH1D* muStandAloneDTTofTimeAtIpOutIn_hist = new TH1D("muStandAloneDTTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons",500,-200,300);
  TH1D* muStandAloneDTTofTimeAtIpOutInErr_hist = new TH1D("muStandAloneDTTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons",100,0,20);

  TH1D* muStandAloneCSCTof_N_hist = new TH1D("muStandAloneCSCTof_N_hist","Number of StandAlone Muons in TOF Calculation",100,0,100);
  TH1D* muStandAloneCSCTofDirection_hist = new TH1D("muStandAloneCSCTofDirection_hist","Direction of StandAlone Muons",3,-1,2);
  TH1D* muStandAloneCSCTofNDof_hist = new TH1D("muStandAloneCSCTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom",200,0,200);
  TH1D* muStandAloneCSCTofInverseBeta_hist = new TH1D("muStandAloneCSCTofInverseBeta_hist","#beta^{-1} of StandAlone Muons",1000,0,50);
  TH1D* muStandAloneCSCTofInverseBetaErr_hist = new TH1D("muStandAloneCSCTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneCSCTofFreeInverseBeta_hist = new TH1D("muStandAloneCSCTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons",8000,-2000,2000);
  TH1D* muStandAloneCSCTofFreeInverseBetaErr_hist = new TH1D("muStandAloneCSCTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons",10000,0,1000);
  TH1D* muStandAloneCSCTofTimeAtIpInOut_hist = new TH1D("muStandAloneCSCTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons",500,-200,300);
  TH1D* muStandAloneCSCTofTimeAtIpInOutErr_hist = new TH1D("muStandAloneCSCTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons",100,0,20);
  TH1D* muStandAloneCSCTofTimeAtIpOutIn_hist = new TH1D("muStandAloneCSCTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons",500,-200,300);
  TH1D* muStandAloneCSCTofTimeAtIpOutInErr_hist = new TH1D("muStandAloneCSCTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons",100,0,20);

  TH1D* refitMuStandAloneTof_N_hist = new TH1D("refitMuStandAloneTof_N_hist","Number of StandAlone Muons in TOF Calculation with recoed DTs",100,0,100);
  TH1D* refitMuStandAloneTofDirection_hist = new TH1D("refitMuStandAloneTofDirection_hist","Direction of StandAlone Muons with recoed DTs",3,-1,2);
  TH1D* refitMuStandAloneTofNDof_hist = new TH1D("refitMuStandAloneTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom with recoed DTs",200,0,200);
  TH1D* refitMuStandAloneTofInverseBeta_hist = new TH1D("refitMuStandAloneTofInverseBeta_hist","#beta^{-1} of StandAlone Muons with recoed DTs",1000,0,50);
  TH1D* refitMuStandAloneTofInverseBetaErr_hist = new TH1D("refitMuStandAloneTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneTofFreeInverseBeta_hist = new TH1D("refitMuStandAloneTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons with recoed DTs",8000,-2000,2000);
  TH1D* refitMuStandAloneTofFreeInverseBetaErr_hist = new TH1D("refitMuStandAloneTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneTofTimeAtIpInOut_hist = new TH1D("refitMuStandAloneTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons with recoed DTs",500,-200,300);
  TH1D* refitMuStandAloneTofTimeAtIpInOutErr_hist = new TH1D("refitMuStandAloneTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons with recoed DTs",100,0,20);
  TH1D* refitMuStandAloneTofTimeAtIpOutIn_hist = new TH1D("refitMuStandAloneTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons with recoed DTs",500,-200,300);
  TH1D* refitMuStandAloneTofTimeAtIpOutInErr_hist = new TH1D("refitMuStandAloneTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons with recoed DTs",100,0,20);

  TH1D* refitMuStandAloneDTTof_N_hist = new TH1D("refitMuStandAloneDTTof_N_hist","Number of StandAlone Muons in TOF Calculation with recoed DTs",100,0,100);
  TH1D* refitMuStandAloneDTTofDirection_hist = new TH1D("refitMuStandAloneDTTofDirection_hist","Direction of StandAlone Muons with recoed DTs",3,-1,2);
  TH1D* refitMuStandAloneDTTofNDof_hist = new TH1D("refitMuStandAloneDTTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom with recoed DTs",200,0,200);
  TH1D* refitMuStandAloneDTTofInverseBeta_hist = new TH1D("refitMuStandAloneDTTofInverseBeta_hist","#beta^{-1} of StandAlone Muons with recoed DTs",1000,0,50);
  TH1D* refitMuStandAloneDTTofInverseBetaErr_hist = new TH1D("refitMuStandAloneDTTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneDTTofFreeInverseBeta_hist = new TH1D("refitMuStandAloneDTTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons with recoed DTs",8000,-2000,2000);
  TH1D* refitMuStandAloneDTTofFreeInverseBetaErr_hist = new TH1D("refitMuStandAloneDTTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneDTTofTimeAtIpInOut_hist = new TH1D("refitMuStandAloneDTTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons with recoed DTs",500,-200,300);
  TH1D* refitMuStandAloneDTTofTimeAtIpInOutErr_hist = new TH1D("refitMuStandAloneDTTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons with recoed DTs",100,0,20);
  TH1D* refitMuStandAloneDTTofTimeAtIpOutIn_hist = new TH1D("refitMuStandAloneDTTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons with recoed DTs",500,-200,300);
  TH1D* refitMuStandAloneDTTofTimeAtIpOutInErr_hist = new TH1D("refitMuStandAloneDTTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons with recoed DTs",100,0,20);

  TH1D* refitMuStandAloneCSCTof_N_hist = new TH1D("refitMuStandAloneCSCTof_N_hist","Number of StandAlone Muons in TOF Calculation with recoed DTs",100,0,100);
  TH1D* refitMuStandAloneCSCTofDirection_hist = new TH1D("refitMuStandAloneCSCTofDirection_hist","Direction of StandAlone Muons with recoed DTs",3,-1,2);
  TH1D* refitMuStandAloneCSCTofNDof_hist = new TH1D("refitMuStandAloneCSCTofNDof_hist","StandAlone Muons TOF Number of Degrees of Freedom with recoed DTs",200,0,200);
  TH1D* refitMuStandAloneCSCTofInverseBeta_hist = new TH1D("refitMuStandAloneCSCTofInverseBeta_hist","#beta^{-1} of StandAlone Muons with recoed DTs",1000,0,50);
  TH1D* refitMuStandAloneCSCTofInverseBetaErr_hist = new TH1D("refitMuStandAloneCSCTofInverseBetaErr_hist","Error of #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneCSCTofFreeInverseBeta_hist = new TH1D("refitMuStandAloneCSCTofFreeInverseBeta_hist","Free #beta^{-1} of StandAlone Muons with recoed DTs",8000,-2000,2000);
  TH1D* refitMuStandAloneCSCTofFreeInverseBetaErr_hist = new TH1D("refitMuStandAloneCSCTofFreeInverseBetaErr_hist","Error of Free #beta^{-1} of StandAlone Muons with recoed DTs",10000,0,1000);
  TH1D* refitMuStandAloneCSCTofTimeAtIpInOut_hist = new TH1D("refitMuStandAloneCSCTofTimeAtIpInOut_hist","Time at IP InOut of StandAlone Muons with recoed DTs",500,-200,300);
  TH1D* refitMuStandAloneCSCTofTimeAtIpInOutErr_hist = new TH1D("refitMuStandAloneCSCTofTimeAtIpInOutErr_hist","Error of Time at IP InOut of StandAlone Muons with recoed DTs",100,0,20);
  TH1D* refitMuStandAloneCSCTofTimeAtIpOutIn_hist = new TH1D("refitMuStandAloneCSCTofTimeAtIpOutIn_hist","Time at IP OutIn of StandAlone Muons with recoed DTs",500,-200,300);
  TH1D* refitMuStandAloneCSCTofTimeAtIpOutInErr_hist = new TH1D("refitMuStandAloneCSCTofTimeAtIpOutInErr_hist","Error of Time at IP OutIn of StandAlone Muons with recoed DTs",100,0,20);

  //get entries for data_tree (read in the old tree), set new variables, fill new tree
  Int_t nentries = tree->GetEntriesFast();
  cout<<"number of entries is: "<<nentries<<endl;
  
  //for (Int_t i=0; i<nentries; i++) {
  for (Int_t i=0; i<100; i++) {
    tree->GetEntry(i);

    cout<<"For event "<<i<<", event # is: "<<events->id<<", run # is: "<<events->run<<", bx is: "<<events->bx<<", mu_N is: "<<events->mu_N<<", mu_Cosmic_N is: "<<events->mu_Cosmic_N<<", mu_StandAlone_N is: "<<events->mu_StandAlone_N<<", mu_RefittedStandAlone_N is: "<<events->mu_RefittedStandAlone_N<<endl;

    
    id_hist->Fill(events->id,1.0);
    run_hist->Fill(events->run,1.0);
    bx_hist->Fill(events->bx,1.0);

    mu_N_hist->Fill(events->mu_N,1.0);
    for (Int_t j=0; j<events->mu_N; j++) {
      cout<<"for mu # "<<j<<", pt is: "<<events->muPt[j]<<endl;
	muPt_hist->Fill(events->muPt[j],1.0);
	muEta_hist->Fill(events->muEta[j],1.0);
	muPhi_hist->Fill(events->muPhi[j],1.0);
	muType_hist->Fill(events->muType[j],1.0);
	muEta_muPhi_hist->Fill(events->muEta[j],events->muPhi[j],1.0);
    }

    muCosmic_N_hist->Fill(events->mu_Cosmic_N,1.0);
    for (Int_t j=0; j<events->mu_Cosmic_N; j++) {
	muCosmicPt_hist->Fill(events->muCosmicPt[j],1.0);
	muCosmicEta_hist->Fill(events->muCosmicEta[j],1.0);
	muCosmicPhi_hist->Fill(events->muCosmicPhi[j],1.0);
	muCosmicType_hist->Fill(events->muCosmicType[j],1.0);
	muCosmicEta_muCosmicPhi_hist->Fill(events->muCosmicEta[j],events->muCosmicPhi[j],1.0);
    }

    muStandAlone_N_hist->Fill(events->mu_StandAlone_N,1.0);
    for (Int_t j=0; j<events->mu_StandAlone_N; j++) {
      cout<<"for standalone mu # "<<j<<", pt is: "<<events->muPt[j]<<endl;
	muStandAlonePt_hist->Fill(events->muStandAlonePt[j],1.0);
	muStandAloneEta_hist->Fill(events->muStandAloneEta[j],1.0);
	muStandAlonePhi_hist->Fill(events->muStandAlonePhi[j],1.0);
	muStandAloneEta_muStandAlonePhi_hist->Fill(events->muStandAloneEta[j],events->muStandAlonePhi[j],1.0);
    }

    muRefittedStandAlone_N_hist->Fill(events->mu_RefittedStandAlone_N,1.0);
    for (Int_t j=0; j<events->mu_RefittedStandAlone_N; j++) {
	muRefittedStandAlonePt_hist->Fill(events->muRefittedStandAlonePt[j],1.0);
	muRefittedStandAloneEta_hist->Fill(events->muRefittedStandAloneEta[j],1.0);
	muRefittedStandAlonePhi_hist->Fill(events->muRefittedStandAlonePhi[j],1.0);
	muRefittedStandAloneEta_muRefittedStandAlonePhi_hist->Fill(events->muRefittedStandAloneEta[j],events->muRefittedStandAlonePhi[j],1.0);
    }

    muStandAloneTof_N_hist->Fill(events->muStandAloneTof_N,1.0);
    for (Int_t j=0; j<events->muStandAloneTof_N; j++) {
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
    }

    muStandAloneDTTof_N_hist->Fill(events->muStandAloneDTTof_N,1.0);
    for (Int_t j=0; j<events->muStandAloneDTTof_N; j++) {
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
    for (Int_t j=0; j<events->muStandAloneCSCTof_N; j++) {
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

    refitMuStandAloneTof_N_hist->Fill(events->refitMuStandAloneTof_N,1.0);
    for (Int_t j=0; j<events->refitMuStandAloneTof_N; j++) {
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
    }

    refitMuStandAloneDTTof_N_hist->Fill(events->refitMuStandAloneDTTof_N,1.0);
    for (Int_t j=0; j<events->refitMuStandAloneDTTof_N; j++) {
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
    for (Int_t j=0; j<events->refitMuStandAloneCSCTof_N; j++) {
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




  }
  
  //fnew.Write();

}
