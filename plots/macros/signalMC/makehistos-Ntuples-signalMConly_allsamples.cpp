{
  //overlays histograms, saves eps files

  using namespace std;
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  gROOT->LoadMacro("../style.cpp");
  global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  //gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  //bool save_plots = false;
  bool save_plots = true;

  const int NumFiles = 5;
  
  //TFile f1("/afs/cern.ch/user/j/jalimena/public/histos/stoppedHSCPMuonHistos_stop600_neutralino200_without_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_withNoiseCut_noPU_matchedtoany.root");
  TFile f1("/home/alimena/histos/stoppedHSCPMuonHistos_stop500_neutralino316_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f2("/home/alimena/histos/stoppedHSCPMuonHistos_gluino500_neutralino387_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f3("/home/alimena/histos/stoppedHSCPMuonHistos_mchamp500_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f4("/home/alimena/histos/stoppedHSCPMuonHistos_gmstau494_gravitinop0001_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f5("/home/alimena/histos/stoppedHSCPMuonHistos_ppstau494_gravitinop0001_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  //const int Num1DHists = 95;a
  //const int Num1DHists = 45;
  const int Num1DHists = 15;
  //const int Num1DHists = 16;
  char* plot1D[Num1DHists] = {
    /*
    "bx_", //0
    "bxWrtCollision_", //1
    "bxWrtBunch_", //2
    "mu_N_", //3
    "muPt_", //4
    "muEta_", //5
    "muPhi_", //6
    "muType_", //7
    "muCosmic_N_", //8
    "muCosmicPt_", //9
    "muCosmicEta_", //10
    "muCosmicPhi_", //11
    "muCosmicType_", //12
    "muStandAlone_N_other_cut_", //13
    */

    /*
    "mcMuon_N_",
    "mcMuonPt_",
    "mcMuonEta_",
    "mcMuonPhi_"
    "mcMuonCharge_",
    "mcMuonMass_"
    */

    
    "muStandAlone_N_", //14
    "muStandAlonePt_", //15
    "muStandAloneEta_", //16
    "muStandAlonePhi_", //17
    "muStandAloneTrackNormalizedChi2_", //17
    "muStandAloneTrackDxy_", //17
    "muStandAloneTrackDz_", //17
    "muStandAloneTrackNHitsMuon_", //17
    "muStandAloneTrackNHitsCsc_", //17
    "muStandAloneTrackNHitsDt_", //17
    "muStandAloneTrackNHitsRpc_", //17
    "muStandAloneTrackNStations_", //17
    "muStandAloneTrackNChambersCsc_", //17
    "muStandAloneTrackNChambersDt_", //17
    "muStandAloneTrackNChambersRpc_" //17
    

    /*
    "mu0_StandAlone_N_", //14
    "mu0_StandAlonePt_", //15
    "mu0_StandAloneEta_", //16
    "mu0_StandAlonePhi_", //17
    "mu0_StandAloneTrackNormalizedChi2_", //17
    "mu0_StandAloneTrackDxy_", //17
    "mu0_StandAloneTrackDz_", //17
    "mu0_StandAloneTrackNHitsMuon_", //17
    "mu0_StandAloneTrackNHitsCsc_", //17
    "mu0_StandAloneTrackNHitsDt_", //17
    "mu0_StandAloneTrackNHitsRpc_", //17
    "mu0_StandAloneTrackNStations_", //17
    "mu0_StandAloneTrackNChambersCsc_", //17
    "mu0_StandAloneTrackNChambersDt_", //17
    "mu0_StandAloneTrackNChambersRpc_", //17
    */
    /*
    "mu1_StandAlone_N_", //14
    "mu1_StandAlonePt_", //15
    "mu1_StandAloneEta_", //16
    "mu1_StandAlonePhi_", //17
    "mu1_StandAloneTrackNormalizedChi2_", //17
    "mu1_StandAloneTrackDxy_", //17
    "mu1_StandAloneTrackDz_", //17
    "mu1_StandAloneTrackNHitsMuon_", //17
    "mu1_StandAloneTrackNHitsCsc_", //17
    "mu1_StandAloneTrackNHitsDt_", //17
    "mu1_StandAloneTrackNHitsRpc_", //17
    "mu1_StandAloneTrackNStations_", //17
    "mu1_StandAloneTrackNChambersCsc_", //17
    "mu1_StandAloneTrackNChambersDt_", //17
    "mu1_StandAloneTrackNChambersRpc_" //17
    */
    /*
    "muRefittedStandAlone_N_", //18
    "muRefittedStandAlonePt_", //19
    "muRefittedStandAloneEta_", //20
    "muRefittedStandAlonePhi_", //21
    "muStandAloneTof_N_", //22
    "muStandAloneTofDirection_", //23
    "muStandAloneTofNDof_", //24
    "muStandAloneTofInverseBeta_", //25
    "muStandAloneTofInverseBetaErr_", //26
    "muStandAloneTofFreeInverseBeta_", //27
    "muStandAloneTofFreeInverseBetaErr_", //28
    "muStandAloneTofTimeAtIpInOut_", //29
    "muStandAloneTofTimeAtIpInOutErr_", //30
    "muStandAloneTofTimeAtIpOutIn_", //31
    "muStandAloneTofTimeAtIpOutInErr_", //32
    "muStandAloneDTTof_N_", //33
    "muStandAloneDTTofDirection_", //34
    "muStandAloneDTTofNDof_", //35
    "muStandAloneDTTofInverseBeta_", //36
    "muStandAloneDTTofInverseBetaErr_", //37
    "muStandAloneDTTofFreeInverseBeta_", //38
    "muStandAloneDTTofFreeInverseBetaErr_", //39
    "muStandAloneDTTofTimeAtIpInOut_", //40
    "muStandAloneDTTofTimeAtIpInOutErr_", //41
    "muStandAloneDTTofTimeAtIpOutIn_", //42
    "muStandAloneDTTofTimeAtIpOutInErr_", //43
    "muStandAloneCSCTof_N_", //44
    "muStandAloneCSCTofDirection_", //45
    "muStandAloneCSCTofNDof_", //46
    "muStandAloneCSCTofInverseBeta_", //47
    "muStandAloneCSCTofInverseBetaErr_", //48
    "muStandAloneCSCTofFreeInverseBeta_", //49
    "muStandAloneCSCTofFreeInverseBetaErr_", //50
    "muStandAloneCSCTofTimeAtIpInOut_", //51
    "muStandAloneCSCTofTimeAtIpInOutErr_", //52
    "muStandAloneCSCTofTimeAtIpOutIn_", //53
    "muStandAloneCSCTofTimeAtIpOutInErr_", //54
    "refitMuStandAloneTof_N_", //55
    "refitMuStandAloneTofDirection_", //56
    "refitMuStandAloneTofNDof_", //57
    "refitMuStandAloneTofInverseBeta_", //58
    "refitMuStandAloneTofInverseBetaErr_", //59
    "refitMuStandAloneTofFreeInverseBeta_", //60
    "refitMuStandAloneTofFreeInverseBetaErr_", //61
    "refitMuStandAloneTofTimeAtIpInOut_", //62
    "refitMuStandAloneTofTimeAtIpInOutErr_", //63
    "refitMuStandAloneTofTimeAtIpOutIn_", //64
    "refitMuStandAloneTofTimeAtIpOutInErr_", //65
    "refitMuStandAloneDTTof_N_", //66
    "refitMuStandAloneDTTofDirection_", //67
    "refitMuStandAloneDTTofNDof_", //68
    "refitMuStandAloneDTTofInverseBeta_", //69
    "refitMuStandAloneDTTofInverseBetaErr_", //70
    "refitMuStandAloneDTTofFreeInverseBeta_", //71
    "refitMuStandAloneDTTofFreeInverseBetaErr_", //72
    "refitMuStandAloneDTTofTimeAtIpInOut_", //73
    "refitMuStandAloneDTTofTimeAtIpInOutErr_", //74
    "refitMuStandAloneDTTofTimeAtIpOutIn_", //75
    "refitMuStandAloneDTTofTimeAtIpOutInErr_", //76
    "refitMuStandAloneCSCTof_N_", //77
    "refitMuStandAloneCSCTofDirection_", //78
    "refitMuStandAloneCSCTofNDof_", //79
    "refitMuStandAloneCSCTofInverseBeta_", //80
    "refitMuStandAloneCSCTofInverseBetaErr_", //81
    "refitMuStandAloneCSCTofFreeInverseBeta_", //82
    "refitMuStandAloneCSCTofFreeInverseBetaErr_", //83
    "refitMuStandAloneCSCTofTimeAtIpInOut_", //84
    "refitMuStandAloneCSCTofTimeAtIpInOutErr_", //85
    "refitMuStandAloneCSCTofTimeAtIpOutIn_", //86
    "refitMuStandAloneCSCTofTimeAtIpOutInErr_", //87
    "DTSegment_N_", //88
    "mu0_StandAloneTofTimeAtIpInOut_", //89
    "mu0_StandAloneTofTimeAtIpOutIn_", //90
    "mu1_StandAloneTofTimeAtIpInOut_", //91
    "mu1_StandAloneTofTimeAtIpOutIn_", //92 
    "mudiff_StandAloneTofTimeAtIpInOut_", //93
    "mudiff_StandAloneTofTimeAtIpOutIn_", //94 
    */
  };

  char* xtitle1D[Num1DHists] = {
    /*
    "BX",
    "BX w.r.t. Collision",
    "BX w.r.t. Bunch",
    "Number of Reco Muons",
    "Reco Muon p_{T} [GeV]",
    "Reco Muon #eta",
    "Reco Muon #phi",
    "Reco Muon Type",
    "Number of Cosmic Muons",
    "Cosmic Muon p_{T} [GeV]",
    "Cosmic Muon #eta",
    "Cosmic Muon #phi",
    "Cosmic Muon Type",
    "Number of StandAlone Muons with cuts applied",
    */
    /*
    "Number of Generated Muons",
    "Generated Muon p_{T} [GeV]",
    "Generated Muon #eta",
    "Generated Muon #phi",
    "Generated Muon Charge",
    "Generated Muon Mass [GeV]"
    */
    
    "Number of StandAlone Muons",
    "StandAlone Muon p_{T} [GeV]",
    "StandAlone Muon #eta",
    "StandAlone Muon #phi",
    "StandAlone Muon Track #chi^{2}/dof",
    "StandAlone Muon Dxy",
    "StandAlone Muon Dz",
    "Hits in StandAlone Muon Track",
    "CSC Hits in StandAlone Muon Track",
    "DT Hits in StandAlone Muon Track",
    "RPC Hits in StandAlone Muon Track",
    "Muon Stations in StandAlone Muon Track",
    "CSC Chambers in StandAlone Muon Track",
    "DT Chambers in StandAlone Muon Track",
    "RPC Chambers in StandAlone Muon Track"


    /*
    "Number of Lower StandAlone Muons",
    "Lower StandAlone Muon p_{T} [GeV]",
    "Lower StandAlone Muon #eta",
    "Lower StandAlone Muon #phi",
    "Lower StandAlone Muon Track #chi^{2}/dof",
    "Lower StandAlone Muon Dxy",
    "Lower StandAlone Muon Dz",
    "Hits in Lower StandAlone Muon Track",
    "CSC Hits in Lower StandAlone Muon Track",
    "DT Hits in Lower StandAlone Muon Track",
    "RPC Hits in Lower StandAlone Muon Track",
    "Muon Stations in Lower StandAlone Muon Track",
    "CSC Chambers in Lower StandAlone Muon Track",
    "DT Chambers in Lower StandAlone Muon Track",
    "RPC Chambers in Lower StandAlone Muon Track",
    */
    /*
    "Number of Upper StandAlone Muons",
    "Upper StandAlone Muon p_{T} [GeV]",
    "Upper StandAlone Muon #eta",
    "Upper StandAlone Muon #phi",
    "Upper StandAlone Muon Track #chi^{2}/dof",
    "Upper StandAlone Muon Dxy",
    "Upper StandAlone Muon Dz",
    "Hits in Upper StandAlone Muon Track",
    "CSC Hits in Upper StandAlone Muon Track",
    "DT Hits in Upper StandAlone Muon Track",
    "RPC Hits in Upper StandAlone Muon Track",
    "Muon Stations in Upper StandAlone Muon Track",
    "CSC Chambers in Upper StandAlone Muon Track",
    "DT Chambers in Upper StandAlone Muon Track",
    "RPC Chambers in Upper StandAlone Muon Track"
    */
    /*
    "Number of Refitted StandAlone Muons",
    "Refitted StandAlone Muon p_{T} [GeV]",
    "Refitted StandAlone Muon #eta",
    "Refitted StandAlone Muon #phi",
    "Number of StandAlone Muons in TOF Calculation",
    "Direction of StandAlone Muons",
    "StandAlone Muons TOF DOF",
    "#beta^{-1} of StandAlone Muons",
    "Error of #beta^{-1} of StandAlone Muons",
    "Free #beta^{-1} of StandAlone Muons",
    "Error of Free #beta^{-1} of StandAlone Muons",
    "Time at IP InOut of StandAlone Muons",
    "Error of Time at IP for In-Out StandAlone Muons",
    "Time at IP for Out-In StandAlone Muons",
    "Error of Time at IP for Out-In StandAlone Muons",
    "Number of StandAlone Muons in DT TOF Calculation",
    "Direction of StandAlone Muons for DTs",
    "StandAlone Muons TOF DOF for DTs",
    "#beta^{-1} of StandAlone Muons for DTs",
    "Error of #beta^{-1} of StandAlone Muons for DTs",
    "Free #beta^{-1} of StandAlone Muons for DTs",
    "Error of Free #beta^{-1} of StandAlone Muons for DTs",
    "Time at IP for In-Out StandAlone Muons for DTs",
    "Error of Time at IP for In-Out StandAlone Muons for DTs",
    "Time at IP for Out-In StandAlone Muons for DTs",
    "Error of Time at IP for Out-In StandAlone Muons for DTs",
    "Number of StandAlone Muons in CSC TOF Calculation",
    "Direction of StandAlone Muons for CSCs",
    "StandAlone Muons TOF DOF for CSCs",
    "#beta^{-1} of StandAlone Muons for CSCs",
    "Error of #beta^{-1} of StandAlone Muons for CSCs",
    "Free #beta^{-1} of StandAlone Muons for CSCs",
    "Error of Free #beta^{-1} of StandAlone Muons for CSCs",
    "Time at IP for In-Out StandAlone Muons for CSCs",
    "Error of Time at IP for In-Out StandAlone Muons for CSCs",
    "Time at IP for Out-In StandAlone Muons for CSCs",
    "Error of Time at IP for Out-In StandAlone Muons for CSCs",
    "Number of StandAlone Muons in Refitted TOF Calculation",
    "Refitted Direction of StandAlone Muons",
    "StandAlone Muons Refitted TOF DOF",
    "Refitted #beta^{-1} of StandAlone Muons",
    "Error of Refitted #beta^{-1} of StandAlone Muons",
    "Refitted Free #beta^{-1} of StandAlone Muons",
    "Error of Refitted Free #beta^{-1} of StandAlone Muons",
    "Refitted Time at IP InOut of StandAlone Muons",
    "Error of Refitted Time at IP for In-Out StandAlone Muons",
    "Refitted Time at IP for Out-In StandAlone Muons",
    "Error of Refitted Time at IP for Out-In StandAlone Muons",
    "Number of StandAlone Muons in Refitted DT TOF Calculation",
    "Refitted Direction of StandAlone Muons for DTs",
    "StandAlone Muons Refitted TOF DOF for DTs",
    "Refitted #beta^{-1} of StandAlone Muons for DTs",
    "Error of Refitted #beta^{-1} of StandAlone Muons for DTs",
    "Refitted Free #beta^{-1} of StandAlone Muons for DTs",
    "Error of Refitted Free #beta^{-1} of StandAlone Muons for DTs",
    "Refitted Time at IP for In-Out StandAlone Muons for DTs",
    "Error of Refitted Time at IP for In-Out StandAlone Muons for DTs",
    "Refitted Time at IP for Out-In StandAlone Muons for DTs",
    "Error of Refitted Time at IP for Out-In StandAlone Muons for DTs",
    "Number of StandAlone Muons in Refitted CSC TOF Calculation",
    "Refitted Direction of StandAlone Muons for CSCs",
    "StandAlone Muons Refitted TOF DOF for CSCs",
    "Refitted #beta^{-1} of StandAlone Muons for CSCs",
    "Error of Refitted #beta^{-1} of StandAlone Muons for CSCs",
    "Refitted Free #beta^{-1} of StandAlone Muons for CSCs",
    "Error of Refitted Free #beta^{-1} of StandAlone Muons for CSCs",
    "Refitted Time at IP for In-Out StandAlone Muons for CSCs",
    "Error of Refitted Time at IP for In-Out StandAlone Muons for CSCs",
    "Refitted Time at IP for Out-In StandAlone Muons for CSCs",
    "Error of Refitted Time at IP for Out-In StandAlone Muons for CSCs",
    "Number of DT Segments",
    "Time at IP for InOut for #phi<0 StandAlone Muon",
    "Time at IP for OutIn for #phi<0 StandAlone Muon",
    "Time at IP for InOut for #phi>0 StandAlone Muon",
    "Time at IP for OutIn for #phi>0 StandAlone Muon",
    "Difference in #phi<0 and #phi>0 StandAlone Muon Time at IP for InOut",
    "Difference in #phi<0 and #phi>0 StandAlone Muon Time at IP for OutIn",
    */
  };
  cout<<"ready for 1D hists"<<endl;

  //info for each 2D plot
  const int Num2DHists = 3;
  /*
  char* plot2D[Num2DHists] = {"muEta_muPhi_","muCosmicEta_muCosmicPhi_","muStandAloneEta_muStandAlonePhi_","muRefittedStandAloneEta_muRefittedStandAlonePhi_", "mu0_mu1_StandAloneTofTimeAtIpInOut_", "mu0_mu1_StandAloneTofTimeAtIpOutIn_"};
  char* xtitle2D[Num2DHists] = {"Reco Muon #eta","Cosmic Muon #eta","StandAlone Muon #eta","Refitted StandAlone Muon #eta","Time At IP for InOut for #phi<0 StandAlone Muon","Time At IP for OutIn for #phi<0 StandAlone Muon"};
  char* ytitle2D[Num2DHists] = {"Reco Muon #phi","Cosmic Muon #phi","StandAlone Muon #phi","Refitted StandAlone Muon #phi","Time At IP for InOut for #phi>0 StandAlone Muon","Time At IP for OutIn for #phi>0 StandAlone Muon"};
  */
  char* plot2D[Num2DHists] = {"muStandAloneTrackNHitsRpc_muStandAloneTrackNormalizedChi2_","mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNormalizedChi2_","mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNormalizedChi2_"};
  char* xtitle2D[Num2DHists] = {"RPC Hits in SA Muon Track","RPC Hits in 1st SA Muon Track","RPC Hits in 2nd SA Muon Track"};
  char* ytitle2D[Num2DHists] = {"#chi^{2}/dof of SA Muon Track","#chi^{2}/dof of 1st SA Muon Track","#chi^{2}/dof of 2nd SA Muon Track"};
  cout<<"ready for 2D hists"<<endl;

  //set up canvases
  char Cname1D[200], Ctitle1D[500];
  TCanvas* canvases1D[Num1DHists];
  //TCanvas* canvases1D[17];
  for (int i=0; i<Num1DHists; i++){
    sprintf(Cname1D,"canvases1D[%i]",i);
    sprintf(Ctitle1D,"%s",plot1D[i]);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,10,700,500);
    if (i<89) canvases1D[i]->SetLogy();
    canvas_style(canvases1D[i]);
  }
  cout<<"made 1D canvases"<<endl;

  /*
  char Cname2D[200], Ctitle2D[500];
  TCanvas* canvases2D[1.0*NumFiles*Num2DHists];
  for (int i=0; i<Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012A",plot2D[i]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=Num2DHists; i<2*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012Bperiod1",plot2D[i-Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=2*Num2DHists; i<3*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012Bperiod2",plot2D[i-2*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=3*Num2DHists; i<4*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012Cv1",plot2D[i-3*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=4*Num2DHists; i<1.0*5*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012Cv2",plot2D[i-4*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=5*Num2DHists; i<1.0*NumFiles*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scosmicdata",plot2D[i-5*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  cout<<"made 2D canvases"<<endl;
  */

  //get histograms
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  for(int i=0; i<Num1DHists; i++){
    sprintf(oldH1Dname,"%shist",plot1D[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1Dname);
    HAll1D[1][i] = (TH1D*) f2.Get(oldH1Dname);
    HAll1D[2][i] = (TH1D*) f3.Get(oldH1Dname);
    HAll1D[3][i] = (TH1D*) f4.Get(oldH1Dname);
    HAll1D[4][i] = (TH1D*) f5.Get(oldH1Dname);
  }

  /*
  TH2D* HAll2D[NumFiles][Num2DHists];
  char oldH2Dname[100];
  for(int i=0; i<Num2DHists; i++){
    sprintf(oldH2Dname,"%shist",plot2D[i]);
    HAll2D[0][i] = (TH2D*) f1.Get(oldH2Dname);
    HAll2D[1][i] = (TH2D*) f2.Get(oldH2Dname);
    //HAll2D[2][i] = (TH2D*) f3.Get(oldH2Dname);
  }
  */
  cout<<"got histograms"<<endl;

  //put in histogram specifications
  int color[NumFiles] = {1,2,4,6,8};//,11};
  int style[NumFiles] = {1,2,3,4,5};//,6};
  int marker[NumFiles] = {20,21,22,23,24};//,25};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      sprintf(axistitles,";%s;Events",xtitle1D[i]);
      //cout<<"sprintf axis title"<<endl;
      HAll1D[a][i]->SetTitle(axistitles);
      //cout<<"set axis titles"<<endl;
      //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
      h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //cout<<"h1_style"<<endl;
      cout<<"xtitle1D[i] is: "<<xtitle1D[i]<<endl;
    }
    /*
    for(int i=0; i<Num2DHists; i++){
      sprintf(axistitles,";%s;%s",xtitle2D[i],ytitle2D[i]);
      HAll2D[a][i]->SetTitle(axistitles);
      //HAll2D[a][i]->GetYaxis()->SetTitle("Events");
      h2_style(HAll2D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //cout<<"xtitle2D[i] is: "<<xtitle2D[i]<<endl;
    }
    */
  }

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


  for (int a=0; a<NumFiles; a++){
    HAll1D[a][1]->Rebin(10);
    HAll1D[a][4]->Rebin(2);

    HAll1D[a][0]->GetXaxis()->SetRangeUser(0,10);
    HAll1D[a][1]->GetXaxis()->SetRangeUser(0,500);
    HAll1D[a][4]->GetXaxis()->SetRangeUser(0,20);
    /*
    if (version1){
      //bx plots
      HAll1D[a][0]->Rebin(50);
      HAll1D[a][1]->Rebin(50);
      HAll1D[a][2]->Rebin(50);
    }
    HAll1D[a][89]->Rebin(10);
    HAll1D[a][90]->Rebin(10);
    HAll1D[a][91]->Rebin(10);
    HAll1D[a][92]->Rebin(10);
    HAll1D[a][93]->Rebin(10);
    HAll1D[a][94]->Rebin(10);

    HAll1D[a][89]->GetXaxis()->SetRangeUser(-50,50);
    HAll1D[a][91]->GetXaxis()->SetRangeUser(-50,50);
    HAll1D[a][93]->GetXaxis()->SetRangeUser(-50,50);

    //eta plots
    HAll1D[a][5]->Rebin(4);
    HAll1D[a][10]->Rebin(4);
    HAll1D[a][16]->Rebin(4);
    HAll1D[a][20]->Rebin(4);

    //inverse beta plots
    HAll1D[a][25]->Rebin(10);
    HAll1D[a][36]->Rebin(10);
    HAll1D[a][47]->Rebin(10);
    HAll1D[a][58]->Rebin(10);
    HAll1D[a][69]->Rebin(10);
    HAll1D[a][80]->Rebin(10);
    //free inverse beta plots
    HAll1D[a][27]->Rebin(10);
    HAll1D[a][38]->Rebin(10);
    HAll1D[a][49]->Rebin(10);
    HAll1D[a][60]->Rebin(10);
    HAll1D[a][71]->Rebin(10);
    HAll1D[a][82]->Rebin(10);
    */
    /*
    for(int i=0; i<Num2DHists-2; i++){
      //eta plots
      HAll2D[a][i]->RebinX(4);
    }
    //2D timing plots
    HAll2D[a][4]->RebinX(10);
    HAll2D[a][5]->RebinX(10);
    HAll2D[a][4]->RebinY(10);
    HAll2D[a][5]->RebinY(10);

    HAll2D[a][4]->GetXaxis()->SetRangeUser(-50,50);
    HAll2D[a][4]->GetYaxis()->SetRangeUser(-50,50);
    */

    //HAll1D[a][6]->Rebin(5);
    //HAll1D[a][7]->Rebin(5);
    //HAll1D[a][8]->Rebin(5);
    /*
    if (version2){
      HAll1D[a][1]->GetXaxis()->SetRangeUser(-5,5);
      HAll1D[a][2]->GetXaxis()->SetRangeUser(-5,5);
    }
    HAll1D[a][3]->GetXaxis()->SetRangeUser(0,60);
    HAll1D[a][8]->GetXaxis()->SetRangeUser(0,60);
    HAll1D[a][13]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][14]->GetXaxis()->SetRangeUser(0,60);
    HAll1D[a][18]->GetXaxis()->SetRangeUser(0,60);
    HAll1D[a][22]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][33]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][44]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][55]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][66]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][77]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][24]->GetXaxis()->SetRangeUser(0,100);
    HAll1D[a][36]->GetXaxis()->SetRangeUser(0,100);
    HAll1D[a][46]->GetXaxis()->SetRangeUser(0,100);
    HAll1D[a][57]->GetXaxis()->SetRangeUser(0,100);
    HAll1D[a][68]->GetXaxis()->SetRangeUser(0,100);
    HAll1D[a][79]->GetXaxis()->SetRangeUser(0,100);
    HAll1D[a][28]->GetXaxis()->SetRangeUser(0,400);
    HAll1D[a][39]->GetXaxis()->SetRangeUser(0,400);
    HAll1D[a][50]->GetXaxis()->SetRangeUser(0,200);
    HAll1D[a][61]->GetXaxis()->SetRangeUser(0,400);
    HAll1D[a][72]->GetXaxis()->SetRangeUser(0,400);
    HAll1D[a][83]->GetXaxis()->SetRangeUser(0,200);
    HAll1D[a][26]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][37]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][59]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][70]->GetXaxis()->SetRangeUser(0,20);
    HAll1D[a][48]->GetXaxis()->SetRangeUser(0,1);
    HAll1D[a][81]->GetXaxis()->SetRangeUser(0,1);

    //HAll1D[a][2]->GetXaxis()->SetRangeUser(0,100);
    //HAll1D[a][7]->GetXaxis()->SetRangeUser(0,100);
    //HAll1D[a][12]->GetXaxis()->SetRangeUser(0,100);
    //HAll1D[a][16]->GetXaxis()->SetRangeUser(0,100);

    //HAll1D[a][1]->GetXaxis()->SetRangeUser(-20,120);
    //HAll1D[a][1]->GetXaxis()->SetRangeUser(1000000,1000030);
    //HAll1D[a][3]->GetXaxis()->SetRangeUser(0,100);
    //HAll1D[a][4]->GetXaxis()->SetRangeUser(-4.5,4.5);
    //HAll1D[a][5]->GetXaxis()->SetRangeUser(-3.5,3.5);
    //HAll1D[a][6]->GetXaxis()->SetRangeUser(-3000,3000);
    //HAll1D[a][7]->GetXaxis()->SetRangeUser(-3000,3000);
    //HAll1D[a][8]->GetXaxis()->SetRangeUser(-6000,6000);
    */
  }    
  cout<<"put in histogram specs"<<endl;

  
  //Set up legends
  //char* LegFile[NumFiles] = {"Without trigger cut","With trigger cut"};//,"With trigger and other cuts"};
  char* LegFile[NumFiles] = {"#tilde{t_{1}} 500 GeV","#tilde{g} 500 GeV","H^{++} 500 GeV","GMSB #tilde{#tau_{1}} 494 GeV","PP #tilde{#tau_{1}} 494 GeV"};
  char LegEntry[100];
  Leg1 = new TLegend(0.60,0.8,0.95,0.98);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);

  Leg2 = new TLegend(0.60,0.8,0.95,0.98);
  //Leg2->AddEntry(HAll1D[a][0],"Without trigger cut, with ,"l");
  Leg2->SetBorderSize(0);
  Leg2->SetTextSize(0.03);
  Leg2->SetFillColor(0);
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


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    Simulation","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);

  //scale to gmstaus
  Double_t scalestop[Num1DHists];
  Double_t scalegluino[Num1DHists];
  Double_t scalemchamp[Num1DHists];
  Double_t scaleppstau[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
    scalestop[i] = (1.0*(Double_t)HAll1D[3][i]->GetSumOfWeights())/((Double_t)HAll1D[0][i]->GetSumOfWeights());
    scalegluino[i] = (1.0*(Double_t)HAll1D[3][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    scalemchamp[i] = (1.0*(Double_t)HAll1D[3][i]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scaleppstau[i] = (1.0*(Double_t)HAll1D[3][i]->GetSumOfWeights())/((Double_t)HAll1D[4][i]->GetSumOfWeights());

    HAll1D[0][i]->Scale(scalestop[i]);
    HAll1D[1][i]->Scale(scalegluino[i]);
    HAll1D[2][i]->Scale(scalemchamp[i]);
    HAll1D[4][i]->Scale(scaleppstau[i]);
  }
  cout<<"scaled histograms"<<endl;


  for (int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      //if(i==1 || i==2 || i==3 || i==4) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,1000);
      //else HAll1D[a][i]->GetYaxis()->SetRangeUser(1,10000);
      HAll1D[a][i]->GetYaxis()->SetRangeUser(.1,1000);
      /*
    if (version2){
      HAll1D[a][0]->GetYaxis()->SetRangeUser(1,50000);
      HAll1D[a][1]->GetYaxis()->SetRangeUser(1,10000000);
      HAll1D[a][2]->GetYaxis()->SetRangeUser(1,10000000);
    }
      */
    }
    //HAll1D[a][4]->GetYaxis()->SetRangeUser(1,400);
  }

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists];//, *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
  //for(int i=1; i<Num1DHists; i++){
  //for(int i=0; i<17; i++){
    canvases1D[i]->cd();
    cout<<"drawing canvas "<<i<<endl;
    HAll1D[1][i]->Draw("hists");
    HAll1D[0][i]->Draw("sameshist");
    HAll1D[2][i]->Draw("sameshist");
    HAll1D[3][i]->Draw("sameshist");
    HAll1D[4][i]->Draw("sameshist");
    /*
    else if (i==8 || i==9 || i==89 || i==90 || i==91 || i==92 || i==93 || i==94){
      HAll1D[4][i]->Draw();
      HAll1D[3][i]->Draw("sames");
      HAll1D[2][i]->Draw("sames");
      HAll1D[1][i]->Draw("sames");
      HAll1D[0][i]->Draw("sames");
    }
    else {
    */
    //HAll1D[0][i]->Draw("hists");
    //HAll1D[1][i]->Draw("sameshist");
      //HAll1D[2][i]->Draw("sameshist");
      //}
    Leg1->Draw();
      /*
      gPad->Update();
      stats0[i] = (TPaveStats*)HAll1D[0][i]->GetListOfFunctions()->FindObject("stats");
      stats0[i]->SetY1NDC(.7); //move stats box
      stats0[i]->SetY2NDC(.8);
      stats0[i]->SetX1NDC(.75);
      stats0[i]->SetBorderSize(0);
      stats1[i] = (TPaveStats*)HAll1D[1][i]->GetListOfFunctions()->FindObject("stats");
      stats1[i]->SetY1NDC(.6); //move stats box
      stats1[i]->SetY2NDC(.7);
      stats1[i]->SetX1NDC(.75);
      stats1[i]->SetTextColor(2);
      stats1[i]->SetBorderSize(0);
      */
      /*
      stats2[i] = (TPaveStats*)HAll1D[2][i]->GetListOfFunctions()->FindObject("stats");
      stats2[i]->SetY1NDC(.5); //move stats box
      stats2[i]->SetY2NDC(.6);
      stats2[i]->SetX1NDC(.75);
      stats2[i]->SetTextColor(4);
      stats2[i]->SetBorderSize(0);
      */
    /*
    stats3[i] = (TPaveStats*)HAll1D[3][i]->GetListOfFunctions()->FindObject("stats");
    stats3[i]->SetY1NDC(.4); //move stats box
    stats3[i]->SetY2NDC(.5);
    stats3[i]->SetX1NDC(.75);
    stats3[i]->SetTextColor(6);
    stats3[i]->SetBorderSize(0);
    stats4[i] = (TPaveStats*)HAll1D[4][i]->GetListOfFunctions()->FindObject("stats");
    stats4[i]->SetY1NDC(.3); //move stats box
    stats4[i]->SetY2NDC(.4);
    stats4[i]->SetX1NDC(.75);
    stats4[i]->SetTextColor(8);
    stats4[i]->SetBorderSize(0);
      */

    text1->Draw();


    sprintf(canvasesEPS,"../../plots/StoppedHSCPMuon/RecoData/signalMC/allsamples/%s.eps",plot1D[i]);
    if (save_plots) canvases1D[i]->SaveAs(canvasesEPS);

  }

  /*
  for(int i=0; i<Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[0][i]->Draw("colz");
    Leg2a->Draw();
    text1->Draw();
    if (bx_cut && other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_with_bx_cut_with_other_cut.eps",plot2D[i]);
    if (bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_with_bx_cut_without_other_cut.eps",plot2D[i]);
    if (!bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_without_bx_cut_without_other_cut.eps",plot2D[i]);
    //else sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_without_bx_cut.eps",plot2D[i]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=Num2DHists; i<2*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[1][i-Num2DHists]->Draw("colz");
    Leg2b->Draw();
    text1->Draw();
    if (bx_cut && other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Bperiod1_with_bx_cut_with_other_cut.eps",plot2D[i-Num2DHists]);
    if (bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Bperiod1_with_bx_cut_without_other_cut.eps",plot2D[i-Num2DHists]);
    if (!bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Bperiod1_without_bx_cut_without_other_cut.eps",plot2D[i-Num2DHists]);
    //else sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Bperiod1_without_bx_cut.eps",plot2D[i-Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=2*Num2DHists; i<3*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[2][i-2*Num2DHists]->Draw("colz");
    Leg2c->Draw();
    text1->Draw();
    if (bx_cut && other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Bperiod2_with_bx_cut_with_other_cut.eps",plot2D[i-2*Num2DHists]);
    if (bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Bperiod2_with_bx_cut_without_other_cut.eps",plot2D[i-2*Num2DHists]);
    if (!bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Bperiod2_without_bx_cut_without_other_cut.eps",plot2D[i-2*Num2DHists]);
    //else sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Bperiod2_without_bx_cut.eps",plot2D[i-2*Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=3*Num2DHists; i<4*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[3][i-3*Num2DHists]->Draw("colz");
    Leg2d->Draw();
    text1->Draw();
    if (bx_cut && other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Cv1_with_bx_cut_with_other_cut.eps",plot2D[i-3*Num2DHists]);
    if (bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Cv1_with_bx_cut_without_other_cut.eps",plot2D[i-3*Num2DHists]);
    if (!bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Cv1_without_bx_cut_without_other_cut.eps",plot2D[i-3*Num2DHists]);
    //else sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Cv1_without_bx_cut.eps",plot2D[i-3*Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=4*Num2DHists; i<5*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[4][i-4*Num2DHists]->Draw("colz");
    Leg2e->Draw();
    text1->Draw();
    if (bx_cut && other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Cv2_with_bx_cut_with_other_cut.eps",plot2D[i-4*Num2DHists]);
    if (bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Cv2_with_bx_cut_without_other_cut.eps",plot2D[i-4*Num2DHists]);
    if (!bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Cv2_without_bx_cut_without_other_cut.eps",plot2D[i-4*Num2DHists]);
    //else sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012Cv2_without_bx_cut.eps",plot2D[i-3*Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=5*Num2DHists; i<1.0*NumFiles*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[5][i-5*Num2DHists]->Draw("colz");
    Leg2f->Draw();
    text1->Draw();
    if (bx_cut && other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scosmicdata_with_bx_cut_with_other_cut.eps",plot2D[i-5*Num2DHists]);
    if (bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scosmicdata_with_bx_cut_without_other_cut.eps",plot2D[i-5*Num2DHists]);
    if (!bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scosmicdata_without_bx_cut_without_other_cut.eps",plot2D[i-5*Num2DHists]);
    //else sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scosmicdata_without_bx_cut.eps",plot2D[i-4*Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  */

}
