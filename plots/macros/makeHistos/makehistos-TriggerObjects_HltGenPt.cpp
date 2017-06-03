{
  //overlays histograms, saves eps files

  using namespace std;
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  //gROOT->LoadMacro("style.cpp");
  //global_style();
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("CMS_lumi.C");

  setTDRStyle();
  tdrGrid(false, tdrStyle);

  writeExtraText = true;
  extraText  = "Preliminary Simulation";
  lumi_8TeV = "2015";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV 
  int iPos=11;

  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  //gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  //gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  //bool save_plots = false;
  bool save_plots = true;

  //const int NumFiles = 5;
  //const int NumFiles = 4;
  //const int NumFiles = 6;
  //const int NumFiles = 2;
  const int NumFiles = 3;
  //const int NumFiles = 4;

  TFile f1 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_mchamp500_wotriggers.root");  
  TFile f2 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_mchamp500_wocsmt.root");  
  //TFile f3 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_mchamp500_csmt.root");
  TFile f3 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_mchamp500_csmt_L1MuOpenSeeds.root");

  //TFile f1 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_DisplacedSUSY200_wotriggers.root");  
  //TFile f2 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_DisplacedSUSY200_wocsmt.root");  
  //TFile f3 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_DisplacedSUSY200_csmt.root");

  //TFile f1 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_DisplacedSUSY200_p2d0_wotriggers.root");  
  //TFile f2 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_DisplacedSUSY200_p2d0_wocsmt.root");  
  //TFile f3 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_DisplacedSUSY200_p2d0_csmt.root");

  //TFile f1 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10_wotriggers.root");
  //TFile f2 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10_wocsmt.root");
  //TFile f3 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10_csmt.root");

  //TFile f1 ("/home/alimena/histos/Triggers_csmt/HTo2LongLivedTo4L_MH_125_MFF_20_CTau1300_wocsmt.root");
  //TFile f2 ("/home/alimena/histos/Triggers_csmt/HTo2LongLivedTo4L_MH_125_MFF_20_CTau1300_csmt.root");

  //TFile f1 ("/home/alimena/histos/Triggers_csmt/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau1000_wocsmt_subLeading.root");
  //TFile f2 ("/home/alimena/histos/Triggers_csmt/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau1000_csmt_subLeading.root");

  //TFile f1 ("/home/alimena/histos/Triggers_csmt/histosHltAnalyzer_mchamp500_wocsmt.root");  
  //TFile f2 ("/home/alimena/histos/Triggers_L1MuOpenSeeds/histosHltAnalyzer_mchamp500_L1MuOpenSeeds.root");
  //TFile f3 ("/home/alimena/histos/Triggers_L1MuOpenSeeds/histosHltAnalyzer_mchamp500_csmt_L1MuOpenSeeds.root");

  //TFile f1 ("/home/alimena/histos/Triggers_L1MuOpenSeeds/histosHltAnalyzer_DisplacedSUSY_L1MuOpenSeeds.root");

  //TFile f1 ("/home/alimena/histos/Triggers_L1MuOpenSeeds/histosHltAnalyzer_HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10_L1MuOpenSeeds.root");
  //TFile f2 ("/home/alimena/histos/Triggers_L1MuOpenSeeds/histosHltAnalyzer_HTo2LongLivedTo4L_MH_1000_MFF_150_CTau100_L1MuOpenSeeds.root");
  //TFile f3 ("/home/alimena/histos/Triggers_L1MuOpenSeeds/histosHltAnalyzer_HTo2LongLivedTo4L_MH_1000_MFF_150_CTau1000_L1MuOpenSeeds.root");
  //cout<<"Loaded file: "<<file<<endl;


  //info for each 1D plot
  //const int Num1DHists = 14;
  //const int Num1DHists = 3;
  const int Num1DHists = 4;
  //const int Num1DHists = 10;

  char* plot1D[Num1DHists] = {
    //"ptTriggerMuon_L1Mu6NotBptxOR",
    //"etaTriggerMuon_L1Mu6NotBptxOR",
    //"phiTriggerMuon_L1Mu6NotBptxOR",

    "ptTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //1
    "etaTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //2
    "phiTriggerMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //3
    //"ptResolution_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo" //4

    //"ptTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //1
    //"etaTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //2
    //"phiTriggerMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10"//, //3

    //"ptTriggerMuon_DoubleMu33NoFiltersNoVtx", //1
    //"etaTriggerMuon_DoubleMu33NoFiltersNoVtx", //2
    //"phiTriggerMuon_DoubleMu33NoFiltersNoVtx"//, //3

    //"ptHltL2MuonTrack", //1
    //"etaHltL2MuonTrack", //2
    //"phiHltL2MuonTrack", //3
    //"dxyHltL2MuonTrack", //4
    //"lxyHltL2MuonTrack", //5
      
    //"ptHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //1
    //"etaHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //2
    //"phiHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //3
    //"dxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //4
    //"lxyHltL2MuonTrack_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo"//, //5

    //"ptHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //1
    //"etaHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //2
    //"phiHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //3
    //"dxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //4
    //"lxyHltL2MuonTrack_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10"//, //5

    //"ptHltL2MuonTrack_DoubleMu33NoFiltersNoVtx", //1
    //"etaHltL2MuonTrack_DoubleMu33NoFiltersNoVtx", //2
    //"phiHltL2MuonTrack_DoubleMu33NoFiltersNoVtx", //3
    //"dxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx", //4
    //"lxyHltL2MuonTrack_DoubleMu33NoFiltersNoVtx"//, //5


    "ptGenMuon" //1
    //"etaGenMuon", //2
    //"phiGenMuon", //3
    //"dxyGenMuon", //4
    //"lxyGenMuon", //5
    
    //"ptGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //1
    //"etaGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //2
    //"phiGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //3
    //"dxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo", //4
    //"lxyGenMuon_L2Mu20_NoVertex_3Sta_NoBPTX3BX_NoHalo"//, //5

    //"ptGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //1
    //"etaGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //2
    //"phiGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //3
    //"dxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10", //4
    //"lxyGenMuon_L2DoubleMu28_NoVertex_2Cha_Angle2p5_Mass10"//, //5

    //"ptGenMuon_DoubleMu33NoFiltersNoVtx", //1
    //"etaGenMuon_DoubleMu33NoFiltersNoVtx", //2
    //"phiGenMuon_DoubleMu33NoFiltersNoVtx", //3
    //"dxyGenMuon_DoubleMu33NoFiltersNoVtx", //4
    //"lxyGenMuon_DoubleMu33NoFiltersNoVtx"//, //5

  };

  char* xtitle1D[Num1DHists] = {
    //"L1 Muon p_{T} [GeV]",
    //"L1 Muon #eta",
    //"L1 Muon #phi",

    "Muon p_{T} [GeV]",
    "HLT Muon #eta",
    "HLT Muon #phi",

    //"L2 Muon Track p_{T} [GeV]",
    //"L2 Muon Track #eta",
    //"L2 Muon Track #phi",
    //"L2 Muon Track D_{xy} [cm]",
    //"L2 Muon Track L_{xy} [cm]",
    
    //"L2 Muon Track p_{T} [GeV]",
    //"L2 Muon Track #eta",
    //"L2 Muon Track #phi",
    //"L2 Muon Track D_{xy} [cm] ",
    //"L2 Muon Track L_{xy} [cm]"

    //"#Delta p_{T} / p_{T}"//,
    "Muon p_{T} [GeV]"//,
    //"Generator Muon #eta",
    //"Generator Muon #phi",
    //"Generator Muon D_{xy} [cm]",
    //"Generator Muon L_{xy} [cm]",
      
    //"Generator Muon p_{T} [GeV]",
    //"Generator Muon #eta",
    //"Generator Muon #phi",
    //"Generator Muon D_{xy} [cm]",
    //"Generator Muon L_{xy} [cm]"

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
  //TCanvas* canvases1D[5];
  //TCanvas* canvases1D[17];
  for (int i=0; i<Num1DHists; i++){
  //for (int i=0; i<5; i++){
    sprintf(Cname1D,"canvases1D[%i]",i);
    sprintf(Ctitle1D,"%s",plot1D[i]);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,10,700,500);
    if (i<89) canvases1D[i]->SetLogy();
    //canvas_style(canvases1D[i]);
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
  cout<<"made 2D canvases"<<endl;
  */

  //TH1D* mcMuonPt_hist = (TH1D*) f1.Get("mcMuonPt_hist");

  //get histograms
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  for(int i=0; i<Num1DHists; i++){
    //sprintf(oldH1Dname,"%shist",plot1D[i]);
    sprintf(oldH1Dname,"demo/%s",plot1D[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1Dname);
    HAll1D[1][i] = (TH1D*) f2.Get(oldH1Dname);
    HAll1D[2][i] = (TH1D*) f3.Get(oldH1Dname);
    //HAll1D[3][i] = (TH1D*) f4.Get(oldH1Dname);
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

  //put in histogram specifications
  int color[NumFiles] = {1,2,4};//,6};//,8,11};//,12,13,14};
  int style[NumFiles] = {1,2,3};//,4};//,5,6};//,7,8,9};
  int marker[NumFiles] = {20,21,22};//,23};//,24,25};//,26,27,28};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      //sprintf(axistitles,";%s;Events / 0.02",xtitle1D[i]);
      sprintf(axistitles,";%s;Events / 10 GeV",xtitle1D[i]);
      //cout<<"sprintf axis title"<<endl;
      HAll1D[a][i]->SetTitle(axistitles);
      //cout<<"set axis titles"<<endl;
      //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
      //h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      HAll1D[a][i]->SetLineColor(color[a]);
      HAll1D[a][i]->SetLineStyle(style[a]);
      HAll1D[a][i]->SetLineWidth(3);
      //h1_style(HAll1D[a][i],3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
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

  /*
  h1_style(mcMuonPt_hist,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  mcMuonPt_hist->SetTitle(";Generator Muon p_{T} [GeV];Events");
  mcMuonPt_hist->Sumw2();
  */
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
    //HAll1D[a][0]->Rebin(2);
    //HAll1D[a][3]->Rebin(2);
    //HAll1D[a][4]->Rebin(20);
    //HAll1D[a][8]->Rebin(20);

    //HAll1D[a][3]->Rebin(10);
    //HAll1D[a][8]->Rebin(10);
    
    //HAll1D[a][3]->GetXaxis()->SetRangeUser(-1,1);
    /*
    HAll1D[a][0]->GetXaxis()->SetRangeUser(0,500);
    HAll1D[a][5]->GetXaxis()->SetRangeUser(0,500);

    HAll1D[a][3]->GetXaxis()->SetRangeUser(-500,500);
    HAll1D[a][8]->GetXaxis()->SetRangeUser(-500,500);

    HAll1D[a][4]->GetXaxis()->SetRangeUser(0,500);
    HAll1D[a][9]->GetXaxis()->SetRangeUser(0,500);
    */

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
  //char* LegFile[NumFiles] = {"Without CS or MT","With CS and MT"};
  //char* LegFile[NumFiles] = {"L1_SingleMuOpen"};
  //char* LegFile[NumFiles] = {"L1_SingleMu6_NotBptxOR","L1_SingleMuOpen"};
  //char* LegFile[NumFiles] = {"Original","With L1_SingleMuOpen","With L1_SingleMuOpen and CS and MT"};
  //char* LegFile[NumFiles] = {"MH=1000, MX=150, ctau=10 mm","MH=1000, MX=150, ctau=100 mm","MH=1000, MX=150, ctau=1000 mm"};
  //char* LegFile[NumFiles] = {"No Trigger Required","Original (without CS or MT)","With CS and MT"};
  //char* LegFile[NumFiles] = {"No Trigger Required","Original (without CS or MT)","With CS and MT","With L1_SingleMuOpen and CS and MT"};
  char* LegFile[NumFiles] = {"Generator","2012 Configuration","L1 and HLT Improvements for 2015"};
  //char* LegFile[NumFiles] = {"L2 Configuration in 2012","L1 and L2 Improvements for 2015"};

  //char* LegFile[NumFiles] = {"53X","71X","71X, cosSeed, SA traj","71X, cosSeed, Exhaustive traj","72X, cosSeed, SA traj","72X, cosSeed, Exhaustive traj"};
  char LegEntry[100];
  //Leg1 = new TLegend(0.60,0.8,0.95,0.98);
  Leg1 = new TLegend(0.55,0.8,0.90,0.92);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);
  

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


  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    Simulation","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=13 TeV    Simulation","NDC");
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

  scalef2[0] = (1.0*(Double_t)HAll1D[1][0]->GetSumOfWeights())/((Double_t)HAll1D[0][3]->GetSumOfWeights());
  HAll1D[0][3]->Scale(scalef2[0]);

  //for(int i=0; i<Num1DHists; i++){

    //scalef0[i] = (1.0*(Double_t)HAll1D[1][0]->GetSumOfWeights())/((Double_t)HAll1D[0][i]->GetSumOfWeights());
    //scalef1[i] = (1.0*(Double_t)HAll1D[1][0]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    //scalef2[i] = (1.0*(Double_t)HAll1D[1][0]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    /*
    scalef2[i] = (1.0*(Double_t)HAll1D[1][0]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scalef3[i] = (1.0*(Double_t)HAll1D[1][0]->GetSumOfWeights())/((Double_t)HAll1D[3][i]->GetSumOfWeights());

    scalef4[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[4][i]->GetSumOfWeights());
    scalef5[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[5][i]->GetSumOfWeights());
    */
    /*
    scalef6[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[6][i]->GetSumOfWeights());
    scalef7[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[7][i]->GetSumOfWeights());
    scalef8[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[8][i]->GetSumOfWeights());
    */


    //HAll1D[0][i]->Scale(scalef0[i]);
    //HAll1D[1][i]->Scale(scalef1[i]);
    //HAll1D[2][i]->Scale(scalef2[i]);
    /*
    HAll1D[2][i]->Scale(scalef2[i]);
    HAll1D[3][i]->Scale(scalef3[i]);

    HAll1D[4][i]->Scale(scalef4[i]);
    HAll1D[5][i]->Scale(scalef5[i]);
    */
    /*
    HAll1D[6][i]->Scale(scalef6[i]);
    HAll1D[7][i]->Scale(scalef7[i]);
    HAll1D[8][i]->Scale(scalef8[i]);
    */
  //}

  
  

  cout<<"scaled histograms"<<endl;

  HAll1D[0][3]->GetYaxis()->SetRangeUser(.2,1000);
  HAll1D[1][0]->GetYaxis()->SetRangeUser(.2,1000);
  HAll1D[2][0]->GetYaxis()->SetRangeUser(.2,1000);

  for (int a=0; a<NumFiles; a++){
    //HAll1D[a][3]->GetYaxis()->SetRangeUser(.8,300);
    //HAll1D[a][2]->GetYaxis()->SetRangeUser(.1,10);
    /*
    HAll1D[a][4]->GetYaxis()->SetRangeUser(.1,1000);

    HAll1D[a][8]->GetYaxis()->SetRangeUser(.1,1000);
    HAll1D[a][3]->GetYaxis()->SetRangeUser(.1,8000);
    HAll1D[a][7]->GetYaxis()->SetRangeUser(.1,8000);
    HAll1D[a][11]->GetYaxis()->SetRangeUser(.1,8000);
    */
  }

  /*
  float sumwocsmt = 0.;
  float sumcsmt = 0.;
  for(i=5;i<=HAll1D[0][0]->GetNbinsX();i++){
    sumwocsmt += HAll1D[0][0]->GetBinContent(i);
    sumcsmt += HAll1D[1][0]->GetBinContent(i);
  }
  float fractionwocsmt = (1.0*sumwocsmt)/((Double_t)HAll1D[0][0]->GetSumOfWeights());
  float fractioncsmt = (1.0*sumcsmt)/((Double_t)HAll1D[1][0]->GetSumOfWeights());

  cout<<"fractionwocsmt is: "<<fractionwocsmt<<endl;
  cout<<"fractioncsmt is: "<<fractioncsmt<<endl;
  */

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists];//, *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];
  
  //for(int i=0; i<5; i++){
  //for(int i=0; i<Num1DHists; i++){
  //for(int i=1; i<Num1DHists; i++){
  //for(int i=0; i<17; i++){
    canvases1D[0]->cd();
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

    HAll1D[0][3]->Draw("hists");
    HAll1D[1][0]->Draw("histsames");
    HAll1D[2][0]->Draw("histsames");

    //HAll1D[1][i+5]->Draw("histsames");
    //HAll1D[2][i+5]->Draw("histsames");
    //HAll1D[3][i+5]->Draw("histsames");

    CMS_lumi( canvases1D[0], iPeriod, iPos );
    Leg1->Draw();
    //text1->Draw();

    //sprintf(canvasesEPS,"../plots/TriggerObjects/%s.eps",plot1D[i]);
    if (save_plots) canvases1D[0]->SaveAs("../plots/TriggerObjects/pt_GenHlt_NoBPTX_mchamp500.eps");
    //if (save_plots) canvases1D[0]->SaveAs("../plots/TriggerObjects/ptResolution_GenHlt_NoBPTX_mchamp500.eps");

    //}
  
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
  */

}
