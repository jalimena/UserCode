{
  //overlays histograms, saves eps files

  using namespace std;
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  //gROOT->LoadMacro("style.cpp");
  //global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  //gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("CMS_lumi.C");

  setTDRStyle();
  //tdrGrid(false, tdrStyle);
  gStyle->SetPalette(1);

  writeExtraText = true;
  extraText  = "Preliminary";
  //lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV                                                                                                                                    
  int iPos=0;
  //int iPos=11;
  //int iPos=22;

  bool save_plots = false;
  //bool save_plots = true;


  const int NumFiles = 2;

  TFile f1 ("/home/alimena/histos/NoBPTX_Run2012D_cosmics_allphi_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root"); //1D plots
  //TFile f1 ("/home/alimena/histos/cosmics_allphi_NoBPTX_Run2012D_723patch1/wBxCut_woCavCut_woGenMuCut_woSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root"); //2D plots
  TFile f2 ("/home/alimena/histos/cosmicMC_Plus125_take2_updatedSim/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f2 ("/home/alimena/histos/NoBPTX_Run2012C_ControlTriggers_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");

  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  const int Num1DHists = 22;
  char* plot1D[Num1DHists] = {
    /*
    "muDisplacedStandAlone_N_", //0
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
    "muDisplacedStandAloneDTTofNDof_" //20
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
    "CSCSegment_N_" //21
  };


  char* xtitle1D[Num1DHists] = {
    "Number of DSA Tracks",
    "DSA Track p_{T} [GeV]",
    "DSA Track #eta",
    "DSA Track #phi",
    "DSA Track Charge",
    "DSA Track Normalized Track #chi^{2}",
    "DSA Track d_{xy}",
    "DSA Track d_{z}",
    "Number of Muon Hits in DSA Track",
    "Number of CSC Hits in DSA Track",
    "Number of DT Hits in DSA Track",
    "Number of RPC Hits in DSA Track",
    "Number of Muon Stations in DSA Track",
    "Number of CSC Chambers in DSA Track",
    "Number of DT Chambers in DSA Track",
    "Number of RPC Chambers in DSA Track",
    "RPC BX Pattern for DSA Track",
    "DSA Track #beta^{-1}_{Free}",
    "DSA Track TimeInOut [ns]",
    "DSA Track TOF Direction",
    "DSA Track TOF nDOF",
    "Total Number of CSC Segments"
  };
  cout<<"ready for 1D hists"<<endl;

  //info for each 2D plot
  const int Num2DHists = 4;
  /*
  char* plot2D[Num2DHists] = {"muEta_muPhi_","muCosmicEta_muCosmicPhi_","muStandAloneEta_muStandAlonePhi_","muRefittedStandAloneEta_muRefittedStandAlonePhi_", "mu0_mu1_StandAloneTofTimeAtIpInOut_", "mu0_mu1_StandAloneTofTimeAtIpOutIn_"};
  char* xtitle2D[Num2DHists] = {"Reco Muon #eta","Cosmic Muon #eta","StandAlone Muon #eta","Refitted StandAlone Muon #eta","Time At IP for InOut for #phi<0 StandAlone Muon","Time At IP for OutIn for #phi<0 StandAlone Muon"};
  char* ytitle2D[Num2DHists] = {"Reco Muon #phi","Cosmic Muon #phi","StandAlone Muon #phi","Refitted StandAlone Muon #phi","Time At IP for InOut for #phi>0 StandAlone Muon","Time At IP for OutIn for #phi>0 StandAlone Muon"};
  */
  char* plot2D[Num2DHists] = {
    "Upper_Lower_muDisplacedStandAloneTofTimeAtIpInOut_",
    "Upper_Lower_muDisplacedStandAloneDtTofFreeInverseBeta_",
    "Upper_muDisplacedStandAloneTimeAtIpInOut_Upper_muDisplacedStandAloneFreeInverseBeta_",
    "Lower_muDisplacedStandAloneTimeAtIpInOut_Lower_muDisplacedStandAloneFreeInverseBeta_"
  };
  char* xtitle2D[Num2DHists] = {
    "Upper DSA Track TimeInOut [ns]",
    "Upper DSA Track #beta^{-1}_{Free}",
    "Upper DSA Track TimeInOut [ns]",
    "Lower DSA Track TimeInOut [ns]"
  };
  char* ytitle2D[Num2DHists] = {
    "Lower DSA Track TimeInOut [ns]",
    "Lower DSA Track #beta^{-1}_{Free}",
    "Upper DSA Track #beta^{-1}_{Free}",
    "Lower DSA Track #beta^{-1}_{Free}"
  };
  cout<<"ready for 2D hists"<<endl;

  //set up canvases
  char Cname1D[200], Ctitle1D[500];
  TCanvas* canvases1D[Num1DHists];
  //TCanvas* canvases1D[17];
  TPad* mainPad[Num1DHists];
  TPad* ratioPad[Num1DHists];
  for (int i=0; i<Num1DHists; i++){
    sprintf(Cname1D,"canvases1D[%i]",i);
    sprintf(Ctitle1D,"%s",plot1D[i]);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,10,575,500);

    mainPad[i] = new TPad(Cname1D,Ctitle1D,0,.95,1,0.4);
    ratioPad[i] = new TPad(Cname1D,Ctitle1D,0,0.4,1,0.06);

    if (i!=0 && i!=4 && i!=16 && i!=19) canvases1D[i]->SetLogy();
    //canvas_style(canvases1D[i]);
    //canvases1D[i]->Divide(1,2);
    //mainPad[i]->SetMargin(0.1,1,0,0.1);

    mainPad[i]->SetMargin(0.1,2,0,0);
    ratioPad[i]->SetMargin(1,2,0.6,0);
    if (i!=0 && i!=4 && i!=16 && i!=19) mainPad[i]->SetLogy();
    mainPad[i]->Draw();
    ratioPad[i]->Draw();

  }
  cout<<"made 1D canvases"<<endl;
  /*
  char Cname2D[200], Ctitle2D[500];
  TCanvas* canvases2D[1.0*NumFiles*Num2DHists];
  for (int i=0; i<Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%sCosmicData",plot2D[i]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,575,500);
    canvases2D[i]->SetRightMargin(0.13);
    //canvases2D[i]->SetLogz();
    //canvas_style(canvases2D[i]);
  }
  */
  /*
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

  //TH1D* mcMuonPt_hist = (TH1D*) f1.Get("mcMuonPt_hist");

  //get histograms
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  for(int i=0; i<Num1DHists; i++){
    sprintf(oldH1Dname,"%shist",plot1D[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1Dname);
    HAll1D[1][i] = (TH1D*) f2.Get(oldH1Dname);
    /*
    HAll1D[2][i] = (TH1D*) f3.Get(oldH1Dname);
    HAll1D[3][i] = (TH1D*) f4.Get(oldH1Dname);
    HAll1D[4][i] = (TH1D*) f5.Get(oldH1Dname);
    */
    //HAll1D[5][i] = (TH1D*) f6.Get(oldH1Dname);
    //HAll1D[6][i] = (TH1D*) f7.Get(oldH1Dname);
    /*
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

  for (int a=0; a<NumFiles; a++){
    HAll1D[a][1]->Rebin(20);
    HAll1D[a][6]->Rebin(20);
    HAll1D[a][7]->Rebin(20);
    HAll1D[a][17]->Rebin(2);
    HAll1D[a][18]->Rebin(10);
  }

  /*
  for(int a=0; a<NumFiles; a++){
    const Int_t nx = HAll1D[a][1]->GetNbinsX();
    cout<<"nx is: "<<nx<<endl;
    Double_t xbins[nx];
    for (Int_t c=0;c<20;c++) xbins[c]=HAll1D[a][1]->GetBinLowEdge(c+1);
    for (Int_t c=20;c<=21;c++) xbins[c]=HAll1D[a][1]->GetBinLowEdge(30*(c-20)+21);
    //char *tempName= new char[strlen(HAll1D[a][1]->GetName())+10];
    //sprintf(tempName,"%swtOverFlow",HAll1D[a][1]->GetName());
    // Book a temporary histogram having ab extra bin for overflows
    HAll1D[a][21] = new TH1D("hnew", "", 21, xbins);
    // Fill the new hitogram including the extra bin for overflows
    
    for (Int_t c=0; c<nx; c++) {
      if(c<40) HAll1D[a][21]->Fill(HAll1D[a][21]->GetBinCenter(c+1), HAll1D[a][1]->GetBinContent(c+1));
      else HAll1D[a][21]->Fill(HAll1D[a][21]->GetBinCenter(c+1), HAll1D[a][1]->GetBinContent(c+1)/30);
    }
    
    // Fill the underflows
    //HAll1D[a][21]->Fill(HAll1D[a][1]->GetBinLowEdge(1)-1, HAll1D[a][1]->GetBinContent(0));
    // Restore the number of entries
    //HAll1D[a][21]->SetEntries(HAll1D[a][1]->GetEntries());
  }
  cout<<"replaced histo to plot overflow bin"<<endl;
  */

  //put in histogram specifications
  int color[NumFiles] = {1,2};//,4,6,8};//,11};//,12};//,13,14};
  int style[NumFiles] = {1,2};//,3,4,5};//,6};//,7};//,8,9};
  int marker[NumFiles] = {20,21};//,22,23,24};//,25};//,26};//,27,28};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      //cout<<"i is: "<<i<<endl;
      sprintf(axistitles,";%s;Events",xtitle1D[i]);
      //cout<<"sprintf axis title"<<endl;
      HAll1D[a][i]->SetTitle(axistitles);
      cout<<"xtitle1D[i] is: "<<xtitle1D[i]<<endl;
      //cout<<"set axis titles"<<endl;
      //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
      //h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //h1_style(HAll1D[a][i],3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
      //HAll1D[a][i]->SetTitleOffset(0.6,"Y");
      HAll1D[a][i]->SetLineWidth(3);
      HAll1D[a][i]->SetLineColor(color[a]);
      HAll1D[a][i]->SetLineStyle(style[a]);
      //cout<<"h1_style"<<endl;
    }
    /*
    for(int i=0; i<Num2DHists; i++){
      sprintf(axistitles,";%s;%s",xtitle2D[i],ytitle2D[i]);
      HAll2D[a][i]->SetTitle(axistitles);
      //HAll2D[a][i]->GetYaxis()->SetTitle("Events");
      //h2_style(HAll2D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //cout<<"xtitle2D[i] is: "<<xtitle2D[i]<<endl;
    }
    */
  }

  /*
  for(int i=0; i<Num1DHists; i++){
    sprintf(axistitles,";%s;Data/MC",xtitle1D[i]);
    //cout<<"sprintf axis title"<<endl;
    ratio_graph[i]->SetTitle(axistitles);
    //cout<<"set axis titles"<<endl;
    //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
    gr_style(ratio_graph[i],1,1,1,1001,50,-1111,-1111,510,510,20,1,1.,1);
  }

  */

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
    HAll1D[a][0]->GetXaxis()->SetRangeUser(0,10);
    HAll1D[a][1]->GetXaxis()->SetRangeUser(0,400);
    HAll1D[a][4]->GetXaxis()->SetRangeUser(-2,2);
    HAll1D[a][5]->GetXaxis()->SetRangeUser(0,5);
    HAll1D[a][8]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][9]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][10]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][11]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][17]->GetXaxis()->SetRangeUser(-3,3);
    //HAll1D[a][17]->GetXaxis()->SetRangeUser(-5,5);
    HAll1D[a][20]->GetXaxis()->SetRangeUser(0,40);
    /*
    HAll1D[a][4]->GetXaxis()->SetRangeUser(0,150);
    HAll1D[a][8]->GetXaxis()->SetRangeUser(0,150);

    HAll1D[a][3]->GetXaxis()->SetRangeUser(-5,1);
    HAll1D[a][7]->GetXaxis()->SetRangeUser(-5,1);
    HAll1D[a][11]->GetXaxis()->SetRangeUser(-5,1);
    HAll1D[a][12]->GetXaxis()->SetRangeUser(0,150);
    */
    /*
    HAll2D[a][1]->GetXaxis()->SetRangeUser(-5,5);
    HAll2D[a][1]->GetYaxis()->SetRangeUser(-5,5);
    HAll2D[a][2]->GetYaxis()->SetRangeUser(-5,5);
    HAll2D[a][3]->GetYaxis()->SetRangeUser(-5,5);
    */
  }    
  cout<<"put in histogram specs"<<endl;

  
  //Set up legends
  char* LegFile[NumFiles] = {"Cosmic Data","Cosmic MC"};
  //char* LegFile[NumFiles] = {"Cosmic Data","Control Trigger Data"};

  char LegEntry[100];
  Leg1 = new TLegend(0.65,0.78,0.83,0.90); //cosmic data vs cosmic mc
  //Leg1 = new TLegend(0.55,0.78,0.75,0.90); //cosmic data vs control trigger data
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
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

    scalef0[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[0][i]->GetSumOfWeights());
    scalef1[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    /*
    scalef2[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scalef3[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[3][i]->GetSumOfWeights());
    scalef4[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[4][i]->GetSumOfWeights());
    //scalef5[i] = (1.0*(Double_t)HAll1D[4][i]->GetSumOfWeights())/((Double_t)HAll1D[5][i]->GetSumOfWeights());
    //scalef6[i] = (1.0*(Double_t)HAll1D[4][i]->GetSumOfWeights())/((Double_t)HAll1D[6][i]->GetSumOfWeights());
    */
    /*
    scalef7[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[7][i]->GetSumOfWeights());
    scalef8[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[8][i]->GetSumOfWeights());
    */

    HAll1D[0][i]->Scale(scalef0[i]);
    HAll1D[1][i]->Scale(scalef1[i]);
    /*
    HAll1D[2][i]->Scale(scalef2[i]);
    HAll1D[3][i]->Scale(scalef3[i]);
    HAll1D[4][i]->Scale(scalef4[i]);
    */
    //HAll1D[5][i]->Scale(scalef5[i]);
    //HAll1D[6][i]->Scale(scalef6[i]);
    /*
    HAll1D[7][i]->Scale(scalef7[i]);
    HAll1D[8][i]->Scale(scalef8[i]);
    */
  }

  
  

  cout<<"scaled histograms"<<endl;


  for (int a=0; a<NumFiles; a++){
    HAll1D[a][17]->GetYaxis()->SetRangeUser(1,3000);
    HAll1D[a][18]->GetYaxis()->SetRangeUser(.1,10000);
    //HAll1D[a][0]->GetYaxis()->SetRangeUser(.1,1000);
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


  for(int i=0; i<Num1DHists; i++){
    double ks = HAll1D[0][i]->KolmogorovTest(HAll1D[1][i]);
    cout<<"KS prob for hist "<<i<<" is: "<<ks<<endl; 
  }

  
  TF1 *fitDataNeg = new TF1("fitDataNeg","gaus",-1.8,-0.2); 
  TF1 *fitDataPos = new TF1("fitDataPos","gaus",0.2,1.8); 
  TF1 *fitMCneg = new TF1("fitMCneg","gaus",-1.8,-0.2);
  TF1 *fitMCpos = new TF1("fitMCpos","gaus",0.2,1.8); 
  fitDataNeg->SetLineColor(1); 
  fitDataPos->SetLineColor(1);
  fitMCneg->SetLineColor(2);
  fitMCpos->SetLineColor(2);
  

  TLine* line0[Num1DHists];
  double x0[Num1DHists] = {0,0,-6,-3.2,0,0,0,0,0,0,0,0,0,0,0,0,0,-3,-100,-1,0};
  double x1[Num1DHists] = {10,400,6,3.2,10,10,500,500,10,10,10,10,10,10,10,3,50,3,100,2,40};
  for(int i=0; i<Num1DHists; i++){
    line0[i] = new TLine(x0[i],1.0,x1[i],1.0);
    line0[i]->SetLineStyle(3);
    line0[i]->SetLineWidth(2);
    line0[i]->SetLineColor(1);
  }


  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists];//, *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];
  
  for(int i=0; i<Num1DHists; i++){
  //for(int i=1; i<Num1DHists; i++){
  //for(int i=0; i<17; i++){
    //canvases1D[i]->cd(1);
    //gPad->SetMargin(1,1,0,0.1);
    cout<<"drawing canvas "<<i<<endl;
    mainPad[i]->cd();
    //canvases1D[i]->cd();
    //canvases1D[i]_1->SetMargin(1,1,0,0.1);
    cout<<"cded to canvas "<<i<<endl;
    /*
    if(i==17){
      HAll1D[0][17]->Fit("fitDataNeg","R");
      HAll1D[0][17]->Fit("fitDataPos","R+","sames");
      HAll1D[1][17]->Fit("fitMCneg","R");
      HAll1D[1][17]->Fit("fitMCpos","R+","sames");
      HAll1D[0][i]->Draw("s");
      HAll1D[1][i]->Draw("sames");
    }
    else{
    */
      HAll1D[1][i]->Draw("hists");
      cout<<"drew file 0 hist "<<i<<endl;
      HAll1D[0][i]->Draw("sameshist");
      cout<<"drew file 1 hist "<<i<<endl;
      //}
    /*
    stats1[i] = (TPaveStats*)HAll1D[1][i]->GetListOfFunctions()->FindObject("stats");
    stats1[i]->SetY1NDC(.5); //move stats box
    stats1[i]->SetY2NDC(.6);
    stats1[i]->SetX1NDC(.75);
    stats1[i]->SetTextColor(2);
    stats1[i]->SetBorderSize(0);
    */
    //mcMuonPt_hist->Draw("hists");

    /*
    if(i==0 || i==6 || i==7 || i==10 || i==16 || i==18 || i==20){
      HAll1D[1][i]->Draw("hists");
      HAll1D[0][i]->Draw("sameshist");
      HAll1D[2][i]->Draw("histsames");
      HAll1D[3][i]->Draw("histsames");
    }
    else if(i==4 || i==19){
      HAll1D[0][i]->Draw("hists");
      HAll1D[1][i]->Draw("sameshist");
      HAll1D[2][i]->Draw("histsames");
      HAll1D[3][i]->Draw("histsames");
    }
    else{
    */
      /*
      HAll1D[2][i]->Draw("histsames");
      HAll1D[3][i]->Draw("histsames");
      HAll1D[4][i]->Draw("histsames");
      */
      //}
    //HAll1D[4][i]->Draw("sameshist");
    //HAll1D[5][i]->Draw("sameshist");
    //HAll1D[6][i]->Draw("sameshist");

    Leg1->Draw();
      cout<<"drew legend "<<endl;

    //text1->Draw();
    CMS_lumi( canvases1D[i], iPeriod, iPos );
      cout<<"drew CMS_lumi for canvas "<<i<<endl;

    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/mchamp500/53Xcheck/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/mchamp500/DisStcheck/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/mchamp500/%s.eps",plot1D[i]);
    if (save_plots) canvases1D[i]->SaveAs(canvasesEPS);

  }


  //TGraphAsymmErrors* ratio_graph[Num1DHists];
  TH1D* ratio[Num1DHists];
  for(int i=0; i<Num1DHists; i++){
    //ratio_graph[i] = new TGraphAsymmErrors();
    //ratio_graph[i]=HAll1D[0][i]->Divide(HAll1D[1][i]);
    ratio[i] = (TH1D*)HAll1D[0][i]->Clone();
    ratio[i]->Divide(HAll1D[1][i]);
    ratio[i]->SetMarkerSize(1.3);
    ratio[i]->SetMarkerStyle(20);
    ratio[i]->GetYaxis()->SetTitle("Data/MC");
    //ratio[i]->GetYaxis()->SetTitle("Cosmics/Control");
    ratio[i]->GetYaxis()->SetNdivisions(7);
    ratio[i]->SetLabelOffset(0.000,"X");
    ratio[i]->SetLabelOffset(0.005,"Y");
    ratio[i]->SetLabelSize(0.15,"X");
    ratio[i]->SetLabelSize(0.15,"Y");
    if(i==16) ratio[i]->SetTitleOffset(1.2,"X");
    else ratio[i]->SetTitleOffset(0.8,"X");
    ratio[i]->SetTitleOffset(0.3,"Y");
    //ratio[i]->SetTitleOffset(0.5,"Y");
    ratio[i]->SetTitleSize(0.2,"X");
    ratio[i]->SetTitleSize(0.15,"Y");
    //ratio[i]->SetTitleSize(0.045,"Y");
    //ratio[i]->SetTitle(0);                           
  }

  for(int i=0; i<Num1DHists; i++){
    //canvases1D[i]->cd(2);
    //gPad->SetMargin(1,1,0.1,0);
    gPad->RedrawAxis();
    ratioPad[i]->cd();
    ratio[i]->Draw("p");
    line0[i]->Draw("same");
    mainPad[i]->cd();
    CMS_lumi( canvases1D[i], iPeriod, iPos );
    //ratio_graph[i]->Draw("AP");
  } 

  /*
  for(int i=0; i<Num2DHists; i++){
    canvases2D[i]->cd(); 
    HAll2D[0][i]->Draw("colz"); 
    CMS_lumi( canvases2D[i], iPeriod, iPos );
  }
  */
}
