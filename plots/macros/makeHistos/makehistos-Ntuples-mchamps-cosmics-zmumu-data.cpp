{
  //overlays histograms, saves eps files

  using namespace std;
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  //gROOT->LoadMacro("style.cpp");
  //global_style();
  int color_plot=1;   // 1/0 for color/black&white plots

  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("CMS_lumi.C");

  setTDRStyle();
  //tdrGrid(false, tdrStyle);
  gStyle->SetPalette(1);

  writeExtraText = true;
  //extraText  = "Preliminary Simulation";
  //lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV                                                                                                                                    
  //int iPos=0;
  int iPos=11;
  //int iPos=22;

  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  //gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  bool save_plots = false;
  //bool save_plots = true;


  const int NumFiles = 4;
  //const int NumFiles = 2;

  /*
  //TFile f1 ("/home/alimena/histos/mchamp100_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f2 ("/home/alimena/histos/mchamp500_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f3 ("/home/alimena/histos/mchamp1000_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f1 ("/home/alimena/histos/mchamp500_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f2 ("/home/alimena/histos/Zmumu_Run2012A_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f3 ("/home/alimena/histos/cosmicMC/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f4 ("/home/alimena/histos/NoBPTX_Run2012D_cosmics_allphi_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f7 ("/home/alimena/histos/NoBPTX_Run2012D_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  */
  /*
  //TFile f1 ("/home/alimena/histos/mchamp100_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f2 ("/home/alimena/histos/mchamp500_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f3 ("/home/alimena/histos/mchamp1000_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f1 ("/home/alimena/histos/mchamp500_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f2 ("/home/alimena/histos/Zmumu_Run2012A_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f3 ("/home/alimena/histos/cosmicMC/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f4 ("/home/alimena/histos/NoBPTX_Run2012D_cosmics_allphi_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f7 ("/home/alimena/histos/NoBPTX_Run2012D_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  */

  
  //preselection
  
  //ndsa, pt (plot highest pt DSA)
  //eta, phi, time in out, free inv beta, rpc bx pattern, rpc bx average (plot 2 highest pt, one in upper, one in lower [BOTH histograms])
  TFile f1 ("/home/alimena/histos/mchamp500_separateEvents_725_updatedSim_fixedMatching/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f2 ("/home/alimena/histos/cosmics_allphi_NoBPTX_Run2012D_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f3 ("/home/alimena/histos/cosmicMC_Plus125_take2_updatedSim/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f3("/home/alimena/histos/NoBPTX_Run2012C_ControlTriggers_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f4 ("/home/alimena/histos/Zmumu_Run2012A_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  
  

  //only with pt cut
  //#dt chambers, tof dof, rpc hits with bx measurements, valid csc hits, free inv beta error, time in out error
  /*
  TFile f1 ("/home/alimena/histos/mchamp500_separateEvents_725_updatedSim/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f2 ("/home/alimena/histos/NoBPTX_Run2012D_cosmics_allphi_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f3 ("/home/alimena/histos/cosmicMC_Plus125_take2_updatedSim/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f4 ("/home/alimena/histos/Zmumu_Run2012A_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  */

  //1 DSA selection
  /*  
  TFile f1 ("/home/alimena/histos/mchamp100_separateEvents_725_updatedSim_fixedMatching/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_wUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f1 ("/home/alimena/histos/mchamp500_separateEvents_725_updatedSim_fixedMatching/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_wUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f2 ("/home/alimena/histos/NoBPTX_Run2012D_cosmics_allphi_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_wUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f3 ("/home/alimena/histos/cosmicMC_Plus125_take2_updatedSim/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_wUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f4 ("/home/alimena/histos/Zmumu_Run2012A_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_wUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  */

  //(mostly) 2DSA selection
  /*
  TFile f1 ("/home/alimena/histos/mchamp500_separateEvents_725_updatedSim_fixedMatching/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f2 ("/home/alimena/histos/cosmics_allphi_NoBPTX_Run2012D_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f3 ("/home/alimena/histos/cosmicMC_Plus125_take2_updatedSim/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f4 ("/home/alimena/histos/Zmumu_Run2012A_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  */

  //regionD
  
  //TFile f1 ("/home/alimena/histos/mchamp500_separateEvents_725_updatedSim/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_wUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f2 ("/home/alimena/histos/NoBPTX_Run2012D_cosmics_allphi_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_wUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_wTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  

  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  //const int Num1DHists = 27;
  const int Num1DHists = 35;
  char* plot1D[Num1DHists] = {
    /*
    "muDisplacedStandAlone_N_", //0
    //"muDisplacedStandAloneP_", //1
    "muDisplacedStandAlonePt_", //1
    "muDisplacedStandAloneEta_", //2
    "muDisplacedStandAlonePhi_", //3
    "muDisplacedStandAloneCharge_", //4
    "muDisplacedStandAloneTrackNormalizedChi2_", //5
    "muDisplacedStandAloneTrackDxy_", //6
    "muDisplacedStandAloneTrackDz_", //7
    "muDisplacedStandAloneTrackNHitsMuon_", //8
    "muDisplacedStandAloneTrackNHitsCsc_", //9
    "muDisplacedStandAloneTrackNHitsDt_", //10
    "muDisplacedStandAloneTrackNHitsRpc_", //11
    "muDisplacedStandAloneTrackNStations_", //12
    "muDisplacedStandAloneTrackNChambersCsc_", //13
    "muDisplacedStandAloneTrackNChambersDt_", //14
    "muDisplacedStandAloneTrackNChambersRpc_", //15
    "muDisplacedStandAloneBxPattern_", //16
    "muDisplacedStandAloneDTTofFreeInverseBeta_", //17
    "muDisplacedStandAloneDTTofTimeAtIpInOut_",//18
    "muDisplacedStandAloneDTTofDirection_",//19
    "muDisplacedStandAloneDTTofNDof_", //20
    "muDisplacedStandAloneTrackDtTofChi2Dof_", //21
    "muDisplacedStandAloneTrackNRpcDof_", //22
    "muDisplacedStandAloneDTTofTimeAtIpInOutErr_", //23
    "muDisplacedStandAloneDTTofFreeInverseBetaErr_", //24
    "DTSegment_N_", //25
    "CSCSegment_N_" //26
    */
        
    "muDisplacedStandAlone_N_", //0
    "Both_muDisplacedStandAlonePt_", //1
    "Both_muDisplacedStandAloneEta_", //2
    "Both_muDisplacedStandAlonePhi_", //3
    "Both_muDisplacedStandAloneTrackCharge_", //4
    "Both_muDisplacedStandAloneTrackNormalizedChi2_", //5
    "Both_muDisplacedStandAloneTrackDxy_", //6
    "Both_muDisplacedStandAloneTrackDz_", //7
    "Both_muDisplacedStandAloneTrackNHitsMuon_", //8
    "Both_muDisplacedStandAloneTrackNHitsCsc_", //9
    "Both_muDisplacedStandAloneTrackNHitsDt_", //10
    "Both_muDisplacedStandAloneTrackNHitsRpc_", //11
    "Both_muDisplacedStandAloneTrackNStations_", //12
    "Both_muDisplacedStandAloneTrackNChambersCsc_", //13
    "Both_muDisplacedStandAloneTrackNChambersDt_", //14
    "Both_muDisplacedStandAloneTrackNChambersRpc_", //15
    "Both_muDisplacedStandAloneBxPattern_", //16
    "Both_muDisplacedStandAloneTrackDtTofFreeInverseBeta_", //17
    "Both_muDisplacedStandAloneTrackDtTofTimeAtIpInOut_",//18
    "Both_muDisplacedStandAloneTrackDtTofDirection_",//19
    "Both_muDisplacedStandAloneTrackDtTofNDof_", //20
    "Both_muDisplacedStandAloneTrackNRpcDof_", //21
    "Both_muDisplacedStandAloneTrackDtTofFreeInverseBetaErr_", //22
    "Both_muDisplacedStandAloneTrackDtTofErrDiff_", //23
    "Upper_Lower_muDisplacedStandAlone_deltaPhi_", //24
    "Upper_Lower_muDisplacedStandAlone_chargeMultiply_", //25
    "Upper_Lower_muDisplacedStandAlone_directionMultiply_",//26
    "CSCSegment_N_", //27
    "mudiff_muDisplacedStandAloneTofTimeAtIpInOut_", //28
    "mudiff_muDisplacedStandAloneTofTimeAtIpOutIn_", //29
    "mudiff_muDisplacedStandAloneTofFreeInverseBeta_", //30
    "mudiff_muDisplacedStandAloneTofDirection_", //31
    "mudiff_muDisplacedStandAloneTrackDtTofErrDiff_", //32
    "mudiff_muDisplacedStandAloneBxAverage_", //33
    "Upper_Lower_muDisplacedStandAloneBxAverage_" //34

    /*
    "regionD_muDisplacedStandAlone_N_", //0
    "regionD_muDisplacedStandAlonePt_", //1
    "regionD_muDisplacedStandAloneEta_", //2
    "regionD_muDisplacedStandAlonePhi_", //3
    "regionD_muDisplacedStandAloneCharge_", //4
    "regionD_muDisplacedStandAloneTrackNormalizedChi2_", //5
    "regionD_muDisplacedStandAloneTrackDxy_", //6
    "regionD_muDisplacedStandAloneTrackDz_", //7
    "regionD_muDisplacedStandAloneTrackNHitsMuon_", //8
    "regionD_muDisplacedStandAloneTrackNHitsCsc_", //9
    "regionD_muDisplacedStandAloneTrackNHitsDt_", //10
    "regionD_muDisplacedStandAloneTrackNHitsRpc_", //11
    "regionD_muDisplacedStandAloneTrackNStations_", //12
    "regionD_muDisplacedStandAloneTrackNChambersCsc_", //13
    "regionD_muDisplacedStandAloneTrackNChambersDt_", //14
    "regionD_muDisplacedStandAloneTrackNChambersRpc_", //15
    "regionD_muDisplacedStandAloneBxPattern_", //16
    "regionD_muDisplacedStandAloneTrackDtTofFreeInverseBeta_", //17
    "regionD_muDisplacedStandAloneTrackDtTofTimeAtIpInOut_", //18
    "regionD_muDisplacedStandAloneTrackDtTofTimeAtIpInOutErr_", //219
    "regionD_muDisplacedStandAloneTrackDtTofNDof_", //20
    "regionD_muDisplacedStandAloneTrackDtTofChi2Dof_", //21
    "regionD_muDisplacedStandAloneTrackNRpcDof_", //22
    "regionD_muDisplacedStandAloneTrackDtTofFreeInverseBetaErr_" //23
    */
  };

  char* xtitle1D[Num1DHists] = {
    "Number of DSA Tracks", //0
    //"Displaced SA p [GeV]", //1
    "DSA Track p_{T} [GeV]", //1
    "DSA Track #eta", //2
    "DSA Track #phi", //3
    "DSA Track Charge", //4
    "DSA Normalized Track #chi^{2}", //5
    "DSA Track d_{xy}", //6
    "DSA Track d_{z}", //7
    "Number of Muon Hits in DSA Track", //8
    "Number of CSC Hits in DSA Track", //9
    "Number of DT Hits in DSA Track", //10
    "Number of RPC Hits in DSA Track", //11
    "Number of Muon Stations in DSA Track", //12
    "Number of CSC Chambers in DSA Track", //13
    "Number of DT Chambers in DSA Track", //14
    "Number of RPC Chambers in DSA Track", //15
    "RPC BX Pattern for DSA Track", //16
    "DSA Track #beta^{-1}_{Free}", //17
    "DSA Track TimeInOut [ns]", //18
    "DSA Track TOF Direction", ///19
    //"DSA DT Time at IP InOut Error", ///
    "DSA Track TOF nDOF", //20
    //"DSA Track TOF #chi^{2}/DOF", ///21
    "DSA Track RPC BX Pattern nDOF", //22
    //"DSA Track TimeInOut Error", //23
    "DSA Track #beta^{-1}_{Free} Error", //24
    //"Total Number of DT Segments in Event", ///25
    "DSA Track Err(TimeInOut)-Err(TimeOutIn)",
    "#Delta#phi Between Upper and Lower DSA Tracks", ///
    "Charge_{upper}*Charge_{lower}", ///
    "Direction_{upper}*Direction_{lower}", ///    
    "Total Number of CSC Segments", ///26
    "#Delta DSA Track TimeInOut [ns]",
    "#Delta DSA Track TimeOutIn [ns]",
    "#Delta DSA Track #beta^{-1}_{Free}",
    "#Delta DSA Track TOF Direction",
    "#Delta DSA Track Err(TimeInOut)-Err(TimeOutIn)",
    "#Delta DSA Track Average RPC BX",
    "Upper + Lower DSA Tracks Average RPC BX"
  };
  cout<<"ready for 1D hists"<<endl;

  //info for each 2D plot
  const int Num2DHists = 1;
  /*
  char* plot2D[Num2DHists] = {"muEta_muPhi_","muCosmicEta_muCosmicPhi_","muStandAloneEta_muStandAlonePhi_","muRefittedStandAloneEta_muRefittedStandAlonePhi_", "mu0_mu1_StandAloneTofTimeAtIpInOut_", "mu0_mu1_StandAloneTofTimeAtIpOutIn_"};
  char* xtitle2D[Num2DHists] = {"Reco Muon #eta","Cosmic Muon #eta","StandAlone Muon #eta","Refitted StandAlone Muon #eta","Time At IP for InOut for #phi<0 StandAlone Muon","Time At IP for OutIn for #phi<0 StandAlone Muon"};
  char* ytitle2D[Num2DHists] = {"Reco Muon #phi","Cosmic Muon #phi","StandAlone Muon #phi","Refitted StandAlone Muon #phi","Time At IP for InOut for #phi>0 StandAlone Muon","Time At IP for OutIn for #phi>0 StandAlone Muon"};
  */
  //char* plot2D[Num2DHists] = {"Upper_muDisplacedStandAloneP_Upper_muDisplacedStandAloneTrackDtTofFreeInverseBeta_hist","mudiff_muDisplacedStandAloneTofTimeAtIpInOut_muDisplacedStandAloneTofFreeInverseBeta_hist"};    
  //char* xtitle2D[Num2DHists] = {"DSA Track p [GeV]", "#Delta DSA Track TimeInOut [ns]"};
  //char* ytitle2D[Num2DHists] = {"DSA Track #beta^{-1}_{Free}", "#Delta DSA Track #beta^{-1}_{Free}"};

  char* plot2D[Num2DHists] = {"mudiff_muDisplacedStandAloneTofTimeAtIpInOut_muDisplacedStandAloneTofFreeInverseBeta_"};    
  char* xtitle2D[Num2DHists] = {"#Delta DSA Track TimeInOut [ns]"};
  char* ytitle2D[Num2DHists] = {"#Delta DSA Track #beta^{-1}_{Free}"};
  cout<<"ready for 2D hists"<<endl;

  //set up canvases
  char Cname1D[200], Ctitle1D[500];
  TCanvas* canvases1D[Num1DHists];
  //TCanvas* canvases1D[17];
  for (int i=0; i<Num1DHists; i++){
    sprintf(Cname1D,"canvases1D[%i]",i);
    sprintf(Ctitle1D,"%s",plot1D[i]);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,10,575,500);
    if (i!=0 && i!=4 && i!=16 && i!=19) canvases1D[i]->SetLogy();
    if(i==16){
      canvases1D[i]->SetBottomMargin(0.20);
      canvases1D[i]->SetRightMargin(0.15);
    }
    //canvas_style(canvases1D[i]);
  }
  cout<<"made 1D canvases"<<endl;


  char Cname2D[200], Ctitle2D[500];
  TCanvas* canvases2D[1.0*NumFiles*Num2DHists];
  for (int i=0; i<Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%imchamp500",plot2D[i]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,575,500);
    canvases2D[i]->SetLogz();
    canvases2D[i]->SetRightMargin(0.13);
    //canvas_style(canvases2D[i]);
  }
  for (int i=Num2DHists; i<2*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%iCosmicData",plot2D[i-Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,575,500);
    canvases2D[i]->SetLogz();
    canvases2D[i]->SetRightMargin(0.13);
    //canvas_style(canvases2D[i]);
  }
  for (int i=2*Num2DHists; i<3*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%iCosmicMC",plot2D[i-2*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,575,500);
    canvases2D[i]->SetLogz();
    canvases2D[i]->SetRightMargin(0.13);
    //canvas_style(canvases2D[i]);
  }
  for (int i=3*Num2DHists; i<4*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%iZmumuData",plot2D[i-3*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,575,500);
    canvases2D[i]->SetLogz();
    canvases2D[i]->SetRightMargin(0.13);
    //canvas_style(canvases2D[i]);
  }
  /*
  for (int i=4*Num2DHists; i<1.0*5*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012Cv2",plot2D[i-4*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,575,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=5*Num2DHists; i<1.0*NumFiles*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scosmicdata",plot2D[i-5*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,575,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  cout<<"made 2D canvases"<<endl;
  */

  //TH1D* mcMuonPt_hist = (TH1D*) f1.Get("mcMuonPt_hist");

  //get histograms
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  for(int i=0; i<Num1DHists; i++){
    sprintf(oldH1Dname,"%shist",plot1D[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1Dname);
    HAll1D[1][i] = (TH1D*) f2.Get(oldH1Dname);
    HAll1D[2][i] = (TH1D*) f3.Get(oldH1Dname);
    HAll1D[3][i] = (TH1D*) f4.Get(oldH1Dname);
    /*
    //HAll1D[4][i] = (TH1D*) f5.Get(oldH1Dname);
    //HAll1D[5][i] = (TH1D*) f6.Get(oldH1Dname);
    //HAll1D[6][i] = (TH1D*) f7.Get(oldH1Dname);
    HAll1D[7][i] = (TH1D*) f8.Get(oldH1Dname);
    HAll1D[8][i] = (TH1D*) f9.Get(oldH1Dname);
    HAll1D[9][i] = (TH1D*) f10.Get(oldH1Dname);
    HAll1D[10][i] = (TH1D*) f11.Get(oldH1Dname);
    HAll1D[11][i] = (TH1D*) f12.Get(oldH1Dname);
    HAll1D[12][i] = (TH1D*) f13.Get(oldH1Dname);
    HAll1D[13][i] = (TH1D*) f14.Get(oldH1Dname);
    HAll1D[14][i] = (TH1D*) f15.Get(oldH1Dname);
    HAll1D[15][i] = (TH1D*) f16.Get(oldH1Dname);
    */
  }

  TH2D* HAll2D[NumFiles][Num2DHists];
  char oldH2Dname[100];
  for(int i=0; i<Num2DHists; i++){
    sprintf(oldH2Dname,"%shist",plot2D[i]);
    HAll2D[0][i] = (TH2D*) f1.Get(oldH2Dname);
    HAll2D[1][i] = (TH2D*) f2.Get(oldH2Dname);
    HAll2D[2][i] = (TH2D*) f3.Get(oldH2Dname);
    HAll2D[3][i] = (TH2D*) f4.Get(oldH2Dname);
  }

  cout<<"got histograms"<<endl;

  /*
  for(int a=0; a<NumFiles; a++){
    UInt_t nx = HAll1D[a][17]->GetNbinsX()+1;
    Double_t *xbins= new Double_t[nx+1];
    for (UInt_t b=0;b<nx;b++) xbins[b]=HAll1D[a][17]->GetBinLowEdge(b+1);
    xbins[nx]=xbins[nx-1]+HAll1D[a][17]->GetBinWidth(nx);
    char *tempName= new char[strlen(HAll1D[a][17]->GetName())+10];
    sprintf(tempName,"%swtOverFlow",HAll1D[a][17]->GetName());
    // Book a temporary histogram having ab extra bin for overflows
    HAll1D[a][19] = new TH1D(tempName, HAll1D[a][17]->GetTitle(), nx, xbins);
    // Fill the new hitogram including the extra bin for overflows
    for (UInt_t b=1; b<=nx; b++) HAll1D[a][19]->Fill(HAll1D[a][19]->GetBinCenter(b), HAll1D[a][17]->GetBinContent(b));
    // Fill the underflows
    HAll1D[a][19]->Fill(HAll1D[a][17]->GetBinLowEdge(1)-1, HAll1D[a][17]->GetBinContent(0));
    // Restore the number of entries
    HAll1D[a][19]->SetEntries(HAll1D[a][17]->GetEntries());
  }
  cout<<"replaced histo to plot overflow bin"<<endl;
  */

  HAll1D[0][17]->Fit("gaus");

  //put in histogram specifications
  int color[NumFiles] = {1,2,4,8};//,6,11};//,12};//,13,14};
  int style[NumFiles] = {1,2,3,4};//,5,6};//,7};//,8,9};
  int marker[NumFiles] = {20,21,22,23};//,24,25};//,26};//,27,28};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
    cout<<"file: "<<a<<endl;
    for(int i=0; i<Num1DHists; i++){
      sprintf(axistitles,";%s;Events",xtitle1D[i]);
      //cout<<"sprintf axis title"<<endl;
      HAll1D[a][i]->SetTitle(axistitles);
      //cout<<"set axis titles"<<endl;
      //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
      //h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //h1_style(HAll1D[a][i],3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
      HAll1D[a][i]->SetLineWidth(3);
      HAll1D[a][i]->SetLineColor(color[a]);
      HAll1D[a][i]->SetLineStyle(style[a]);
      if(i==16) HAll1D[a][i]->SetTitleOffset(1.5,"X");
      //cout<<"h1_style"<<endl;
      cout<<"xtitle1D[i] is: "<<xtitle1D[i]<<endl;
    }   
    for(int i=0; i<Num2DHists; i++){
      sprintf(axistitles,";%s;%s",xtitle2D[i],ytitle2D[i]);
      HAll2D[a][i]->SetTitle(axistitles);
      //HAll2D[a][i]->GetYaxis()->SetTitle("Events");
      //h2_style(HAll2D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //cout<<"xtitle2D[i] is: "<<xtitle2D[i]<<endl;
    }    
  }

  //h1_style(mcMuonPt_hist,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  //mcMuonPt_hist->SetTitle(";Generator Muon p_{T} [GeV];Events");
  //mcMuonPt_hist->Sumw2();
  //sumw2 for correct error bars
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      HAll1D[a][i]->Sumw2();
    }
    /*
    for(int i=0; i<Num2DHists; i++){
      HAll2D[a][i]->Sumw2();
    }
    */
  }

  /*
  //KS test
  for (int a=0; a<NumFiles; a++){
    double ks = mcMuonPt_hist->KolmogorovTest(HAll1D[a][4]);
    cout<<"KS prob for RSA pt and gen pt, for file "<<a<<" is: "<<ks<<endl;
  }  

  //mcMuonPt_hist->Rebin(20);
  mcMuonPt_hist->GetXaxis()->SetRangeUser(0,150);
  */
  for (int a=0; a<NumFiles; a++){
    //HAll1D[a][1]->Rebin(20);
    HAll1D[a][1]->Rebin(20);
    HAll1D[a][6]->Rebin(20);
    HAll1D[a][7]->Rebin(20);
    HAll1D[a][18]->Rebin(10);
    HAll1D[a][24]->Rebin(5);
    HAll1D[a][25]->Rebin(5);
    HAll1D[a][28]->Rebin(5);
    HAll1D[a][29]->Rebin(5);

    HAll1D[a][0]->GetXaxis()->SetRangeUser(0,7);
    HAll1D[a][2]->GetXaxis()->SetRangeUser(-3.5,3.5);
    HAll1D[a][4]->GetXaxis()->SetRangeUser(-2,2);
    HAll1D[a][5]->GetXaxis()->SetRangeUser(0,5);
    HAll1D[a][8]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][9]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][10]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][11]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][14]->GetXaxis()->SetRangeUser(0,9);
    HAll1D[a][17]->GetXaxis()->SetRangeUser(-6,6);
    HAll1D[a][20]->GetXaxis()->SetRangeUser(0,40);
    HAll1D[a][24]->GetXaxis()->SetRangeUser(0,30);
    HAll1D[a][25]->GetXaxis()->SetRangeUser(0,30);
    HAll1D[a][27]->GetXaxis()->SetRangeUser(0,30);
    HAll1D[a][30]->GetXaxis()->SetRangeUser(-6,6);
    HAll1D[a][32]->GetXaxis()->SetRangeUser(-15,15);
    HAll1D[a][33]->GetXaxis()->SetRangeUser(-3,3);
    HAll1D[a][34]->GetXaxis()->SetRangeUser(-3,3);

    HAll2D[a][0]->GetYaxis()->SetRangeUser(-6,6);
    /*
    HAll1D[a][4]->GetXaxis()->SetRangeUser(0,150);
    HAll1D[a][8]->GetXaxis()->SetRangeUser(0,150);

    HAll1D[a][3]->GetXaxis()->SetRangeUser(-5,1);
    HAll1D[a][7]->GetXaxis()->SetRangeUser(-5,1);
    HAll1D[a][11]->GetXaxis()->SetRangeUser(-5,1);
    HAll1D[a][12]->GetXaxis()->SetRangeUser(0,150);
    */
  }    
  cout<<"put in histogram specs"<<endl;

  
  //Set up legends
  //char* LegFile[NumFiles] = {"Without trigger cut","With trigger cut"};//,"With trigger and other cuts"};
  //char* LegFile[NumFiles] = {"#tilde{t_{1}} 500 GeV","#tilde{g} 500 GeV","H^{++} 500 GeV","GMSB #tilde{#tau_{1}} 494 GeV","PP #tilde{#tau_{1}} 494 GeV"};
  //char* LegFile[NumFiles] = {"#tilde{t_{1}} 200 GeV","#tilde{t_{1}} 600 GeV","#tilde{t_{1}} 1000 GeV"};
  //char* LegFile[NumFiles] = {"#tilde{g} 300 GeV","#tilde{g} 900 GeV","#tilde{g} 1500 GeV"};
  //char* LegFile[NumFiles] = {"H^{++} 100 GeV","H^{++} 500 GeV","H^{++} 1000 GeV"};
  //char* LegFile[NumFiles] = {"GMSB #tilde{#tau_{1}} 100 GeV","GMSB #tilde{#tau_{1}} 247 GeV","GMSB #tilde{#tau_{1}} 494 GeV"};
  //char* LegFile[NumFiles] = {"PP #tilde{#tau_{1}} 100 GeV","PP #tilde{#tau_{1}} 247 GeV","PP #tilde{#tau_{1}} 494 GeV"};
  //char* LegFile[NumFiles] = {"#tilde{t_{1}} 200 GeV","#tilde{t_{1}} 600 GeV","#tilde{t_{1}} 1000 GeV","Cosmic All-Phi Data"};
  //////char* LegFile[NumFiles] = {"53X, no cuts","71X, no cuts","71X, loose cuts","71X, medium cuts","71X, tight cuts","71X, loose + dist stations cuts"};
  //char* LegFile[NumFiles] = {"53X, no cuts","71X, no cuts","53X, loose cuts","53X, medium cuts","53X, tight cuts"};
  //char* LegFile[NumFiles] = {"53X, no cuts","71X, no cuts","71X, loose cuts","71X, medium cuts","71X, tight cuts","71X, cosSeed, no cuts","71X, cosSeed, loose cuts","71X, cosSeed, medium cuts","71X, cosSeed, tight cuts"};
  //char* LegFile[NumFiles] = {"72X, cosSeed, SA traj, no cuts","53X, no cuts"};
  //char* LegFile[NumFiles] = {"72X, cosSeed, SA traj, Standard Nav","72X, cosSeed, SA traj, Direct Nav"};
  //char* LegFile[NumFiles] = {"H^{++} 100 GeV","H^{++} 500 GeV","H^{++} 1000 GeV"};
  //char* LegFile[NumFiles] = {"H^{++} 100 GeV","H^{++} 500 GeV","H^{++} 1000 GeV","Zmumu Data","Cosmic MC","Cosmic All-Phi Data","Run2012D Data"};
  //char* LegFile[NumFiles] = {"H^{++} 100 GeV","H^{++} 500 GeV","H^{++} 1000 GeV","Zmumu Data","Cosmic MC","Cosmic All-Phi Data"};
  char* LegFile[NumFiles] = {"500 GeV mchamps","Cosmic Data","Cosmic MC","Z#rightarrow#mu#mu Data"};
  //char* LegFile[NumFiles] = {"500 GeV mchamps","Cosmic Data","Control Trigger Data","Z#rightarrow#mu#mu Data"};

  char LegEntry[100];
  Leg1 = new TLegend(0.66,0.75,0.92,0.90);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);
  

  Leg2 = new TLegend(0.55,0.75,0.81,0.90);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg2->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg2->SetBorderSize(0);
  Leg2->SetTextSize(0.03);
  Leg2->SetFillColor(0);

  /*
  Leg2 = new TLegend(0.60,0.8,0.95,0.98);
  //Leg2->AddEntry(HAll1D[a][0],"Without trigger cut, with ,"l");
  Leg2->SetBorderSize(0);
  Leg2->SetTextSize(0.03);
  Leg2->SetFillColor(0);
  */
  /*
  TPaveLabel *Leg2a = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012A Data","NDC");
  Leg2a->SetBorderSize(0);
  Leg2a->SetTextSize(0.7);
  Leg2a->SetFillColor(0);

  TPaveLabel *Leg2b = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012B period 1 Data","NDC");
  Leg2b->SetBorderSize(0);
  Leg2b->SetTextSize(0.7);
  Leg2b->SetFillColor(0);

  TPaveLabel *Leg2c = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012B period 2 Data","NDC");
  Leg2c->SetBorderSize(0);
  Leg2c->SetTextSize(0.7);
  Leg2c->SetFillColor(0);

  TPaveLabel *Leg2d = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012C-v1 Data","NDC");
  Leg2d->SetBorderSize(0);
  Leg2d->SetTextSize(0.7);
  Leg2d->SetFillColor(0);

  TPaveLabel *Leg2e = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012C-v2 Data","NDC");
  Leg2e->SetBorderSize(0);
  Leg2e->SetTextSize(0.7);
  Leg2e->SetFillColor(0);

  TPaveLabel *Leg2f = new TPaveLabel(.19,.92,.39,.99,"Cosmic Data, Run 195155","NDC");
  Leg2f->SetBorderSize(0);
  Leg2f->SetTextSize(0.7);
  Leg2f->SetFillColor(0);
  */


  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    Simulation","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);

  //scale to guest's
  Double_t scalef0[Num1DHists];
  Double_t scalef1[Num1DHists];
  Double_t scalef2[Num1DHists];
  Double_t scalef3[Num1DHists];
  Double_t scalef4[Num1DHists];
  Double_t scalef5[Num1DHists];
  Double_t scalef6[Num1DHists];
  Double_t scalef7[Num1DHists];
  Double_t scalef8[Num1DHists];

  for (int a=0; a<NumFiles; a++){
    cout<<"sum of weights for file "<<a<<" is: "<<((Double_t)HAll1D[a][0]->GetSumOfWeights())<<endl;
  }

  for(int i=0; i<Num1DHists; i++){

    /*
    scalef0[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[0][i]->GetSumOfWeights());
    scalef1[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    */
    
    scalef0[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[0][i]->GetSumOfWeights());
    scalef1[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    scalef2[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scalef3[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[3][i]->GetSumOfWeights());
    
    //scalef4[i] = (1.0*(Double_t)HAll1D[4][i]->GetSumOfWeights())/((Double_t)HAll1D[4][i]->GetSumOfWeights());
    //scalef5[i] = (1.0*(Double_t)HAll1D[4][i]->GetSumOfWeights())/((Double_t)HAll1D[5][i]->GetSumOfWeights());
    //scalef6[i] = (1.0*(Double_t)HAll1D[4][i]->GetSumOfWeights())/((Double_t)HAll1D[6][i]->GetSumOfWeights());
    /*
    scalef7[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[7][i]->GetSumOfWeights());
    scalef8[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[8][i]->GetSumOfWeights());
    */


    HAll1D[0][i]->Scale(scalef0[i]);
    HAll1D[1][i]->Scale(scalef1[i]);
    HAll1D[2][i]->Scale(scalef2[i]);
    HAll1D[3][i]->Scale(scalef3[i]);

    //HAll1D[4][i]->Scale(scalef4[i]);
    //HAll1D[5][i]->Scale(scalef5[i]);
    //HAll1D[6][i]->Scale(scalef6[i]);
    /*
    HAll1D[7][i]->Scale(scalef7[i]);
    HAll1D[8][i]->Scale(scalef8[i]);
    */
  }

  
  

  cout<<"scaled histograms"<<endl;


  for (int a=0; a<NumFiles; a++){
    //HAll1D[a][0]->GetYaxis()->SetRangeUser(.1,1000);
    HAll1D[a][1]->GetYaxis()->SetRangeUser(.1,10000);
    //HAll1D[a][2]->GetYaxis()->SetRangeUser(.0001,3);
    HAll1D[a][3]->GetYaxis()->SetRangeUser(.03,3000);
    HAll1D[a][14]->GetYaxis()->SetRangeUser(1,30000);
    HAll1D[a][16]->GetYaxis()->SetRangeUser(0,2100);
    HAll1D[a][18]->GetYaxis()->SetRangeUser(.01,30000);
    HAll1D[a][20]->GetYaxis()->SetRangeUser(.01,30000);
    HAll1D[a][23]->GetYaxis()->SetRangeUser(.01,30000);
    HAll1D[a][24]->GetYaxis()->SetRangeUser(.01,30000);
    HAll1D[a][27]->GetYaxis()->SetRangeUser(.05,1000);
    /*
    HAll1D[a][4]->GetYaxis()->SetRangeUser(.1,1000);

    HAll1D[a][8]->GetYaxis()->SetRangeUser(.1,1000);
    HAll1D[a][3]->GetYaxis()->SetRangeUser(.1,8000);
    HAll1D[a][7]->GetYaxis()->SetRangeUser(.1,8000);
    HAll1D[a][11]->GetYaxis()->SetRangeUser(.1,8000);
    */
  }


  /*
  float sum53SA = 0.;
  float sum53RSA = 0.;
  float sum53cos = 0.;
  float sum71cosSeedSA = 0.;
  float sum71cosSeedRSA = 0.;
  float sum71cos = 0.;
  for(i=50;i<=HAll1D[0][0]->GetNbinsX();i++){
    sum53SA += HAll1D[0][0]->GetBinContent(i);
    sum53RSA += HAll1D[0][4]->GetBinContent(i);
    sum53cos += HAll1D[0][8]->GetBinContent(i);
    sum71cosSeedSA += HAll1D[2][0]->GetBinContent(i);
    sum71cosSeedRSA += HAll1D[2][4]->GetBinContent(i);
    sum71cos += HAll1D[1][8]->GetBinContent(i);
  }
  float fraction53SA = (1.0*sum53SA)/((Double_t)HAll1D[0][0]->GetSumOfWeights());
  float fraction53RSA = (1.0*sum53RSA)/((Double_t)HAll1D[0][4]->GetSumOfWeights());
  float fraction53cos = (1.0*sum53cos)/((Double_t)HAll1D[0][8]->GetSumOfWeights());
  float fraction71cosSeedSA = (1.0*sum71cosSeedSA)/((Double_t)HAll1D[2][0]->GetSumOfWeights());
  float fraction71cosSeedRSA = (1.0*sum71cosSeedRSA)/((Double_t)HAll1D[2][4]->GetSumOfWeights());
  float fraction71cos = (1.0*sum71cos)/((Double_t)HAll1D[1][8]->GetSumOfWeights());

  cout<<"fraction53SA is: "<<fraction53SA<<endl;
  cout<<"fraction53RSA is: "<<fraction53RSA<<endl;
  cout<<"fraction53cos is: "<<fraction53cos<<endl;
  cout<<"fraction71cosSeedSA is: "<<fraction71cosSeedSA<<endl;
  cout<<"fraction71cosSeedRSA  is: "<<fraction71cosSeedRSA<<endl;
  cout<<"fraction71cos is: "<<fraction71cos<<endl;
  */


  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists];//, *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];
  
  for(int i=0; i<Num1DHists; i++){
  //for(int i=1; i<Num1DHists; i++){
  //for(int i=0; i<17; i++){
    canvases1D[i]->cd();
    cout<<"drawing canvas "<<i<<endl;

    /*
    stats1[i] = (TPaveStats*)HAll1D[1][i]->GetListOfFunctions()->FindObject("stats");
    stats1[i]->SetY1NDC(.5); //move stats box
    stats1[i]->SetY2NDC(.6);
    stats1[i]->SetX1NDC(.75);
    stats1[i]->SetTextColor(2);
    stats1[i]->SetBorderSize(0);
    */
    //mcMuonPt_hist->Draw("hists");

    if(i==0 || i==4 || i==17){
      HAll1D[0][i]->Draw("hists");
      HAll1D[1][i]->Draw("sameshist");
      HAll1D[2][i]->Draw("histsames");
      HAll1D[3][i]->Draw("histsames");
    }
    else if(i==6 || i==7 || i==10 || i==16 || i==18 || i==19 || i==20 || i==33 || i==34){
      HAll1D[3][i]->Draw("hists");
      HAll1D[0][i]->Draw("sameshist");
      HAll1D[1][i]->Draw("histsames");
      HAll1D[2][i]->Draw("histsames");
    }
    else if (i==3){
      HAll1D[2][i]->Draw("hists");
      HAll1D[0][i]->Draw("histsames");
      HAll1D[1][i]->Draw("histsames");
      HAll1D[3][i]->Draw("histsames");
    }
    else{
      HAll1D[1][i]->Draw("hists");
      HAll1D[0][i]->Draw("histssames");
      HAll1D[2][i]->Draw("histsames");
      HAll1D[3][i]->Draw("histsames");
    }
    //HAll1D[4][i]->Draw("sameshist");
    //HAll1D[5][i]->Draw("sameshist");
    //HAll1D[6][i]->Draw("sameshist");

    if (i==16) Leg2->Draw();
    else Leg1->Draw();


    //text1->Draw();

    CMS_lumi( canvases1D[i], iPeriod, iPos );

    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/mchamp500/53Xcheck/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/mchamp500/DisStcheck/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/mchamp500/%s.eps",plot1D[i]);
    if (save_plots) canvases1D[i]->SaveAs(canvasesEPS);

  }
  
  /*
  canvases1D[0]->cd();

  //HAll1D[0][0]->Draw("s"); //SA pt, 53X
  //HAll1D[0][4]->Draw("sames"); //RSA pt, 53X
  //HAll1D[0][8]->Draw("sameshist"); //cosmic pt, 53X
  
  //HAll1D[1][0]->Draw("sames"); //SA pt, 71X //not good
  //HAll1D[1][4]->Draw("sames"); //RSA pt, 71X //second best 3
  
  HAll1D[1][8]->Draw("shist"); //cosmic pt, 71X //best 3
  HAll1D[2][0]->Draw("sameshist"); //SA pt, 71X cosSeed + SA traj //best 3// absolute best
  HAll1D[2][4]->Draw("sameshist"); //RSA pt, 71X cosSeed + SA traj //best 3

  //HAll1D[3][0]->Draw("sames"); //SA pt, 71X cosSeed + SA Exhaustive traj //second best 3 //best of second best
  //HAll1D[3][4]->Draw("sames"); //RSA pt, 71X cosSeed + SA Exhaustive traj //second best 3

  Leg1->Draw();
  text1->Draw();
  */
  

  for(int i=0; i<Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[0][i]->Draw("colz");
    CMS_lumi( canvases2D[i], iPeriod, iPos );
    //Leg2a->Draw();
    //text1->Draw();
    //if (bx_cut && other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_with_bx_cut_with_other_cut.eps",plot2D[i]);
    //if (bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_with_bx_cut_without_other_cut.eps",plot2D[i]);
    //if (!bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_without_bx_cut_without_other_cut.eps",plot2D[i]);
    //else sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_without_bx_cut.eps",plot2D[i]);
    //if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=Num2DHists; i<2*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[1][i-Num2DHists]->Draw("colz");
    CMS_lumi( canvases2D[i], iPeriod, iPos );
  }
  for(int i=2*Num2DHists; i<3*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[2][i-2*Num2DHists]->Draw("colz");
    CMS_lumi( canvases2D[i], iPeriod, iPos );
  }
  for(int i=3*Num2DHists; i<4*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[3][i-3*Num2DHists]->Draw("colz");
    CMS_lumi( canvases2D[i], iPeriod, iPos );
  }


}
