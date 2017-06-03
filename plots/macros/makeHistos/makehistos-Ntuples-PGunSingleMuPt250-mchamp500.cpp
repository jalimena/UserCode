{
  //overlays histograms, saves eps files
  using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with                                                                                      
  //gROOT->LoadMacro("style.cpp");
  //global_style();
  //int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("CMS_lumi.C");

  setTDRStyle();
  tdrGrid(false, tdrStyle);

  writeExtraText = true;
  extraText  = "Simulation Preliminary";
  lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV 
  int iPos=0; 
  //int iPos=11; 
  //int iPos=22;

  bool save_plots = false;
  //bool save_plots = true;

  const int NumFiles = 6;

  //2 DT chambers
  TFile f1 ("/home/alimena/histos/PGunSingleMuP250/wBxCut_wCavCut_woGenMuCut_woSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f2 ("/home/alimena/histos/mchamp500_separateEvents_725_updatedSim_fixedMatching/wBxCut_wCavCut_woGenMuCut_woSACut_woGenMuMatchedCut_woTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut__woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");



  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  const int Num1DHists = 5;
  char* plot1DMu[Num1DHists] = {
    "muP_", //0
    "muPtResolution_", //1
    "mcMuonEta_", //2
    "muGenDR_", //3
    "muQoverPtResolution_" //4
  };
  char* plot1DMuStandAlone[Num1DHists] = {
    "muStandAloneP_", //0
    "muStandAlonePtResolution_", //1
    "mcMuonP_", //2
    "muStandAloneTrackGenDR_", //3
    "muStandAloneQoverPtResolution_", //4
  };
  char* plot1DMuStandAloneUpdatedAtVtx[Num1DHists] = {
    "muStandAloneUpdatedAtVtxP_", //0
    "muStandAloneUpdatedAtVtxPtResolution_", //1
    "mcMuonPhi_", //2
    "muStandAloneTrackUpdatedAtVtxGenDR_", //3
    "muStandAloneUpdatedAtVtxQoverPtResolution_" //4
  };
  char* plot1DMuDisplacedStandAlone[Num1DHists] = {
    "muDisplacedStandAloneP_", //0
    "muDisplacedStandAlonePtResolution_", //1
    "mcMuonVx_", //2
    "muDisplacedStandAloneGenDR_", //3
    "muDisplacedStandAloneQoverPtResolution_" //4
  };

  char* xtitle1D[Num1DHists] = {
    "Reco p [GeV]",
    "#Delta p_{T} / p_{T}",
    "Generator p [GeV]",
    "#Delta R",
    "#Delta (q/p_{T}) / (q/p_{T})"
  };

  char* ytitle1D[Num1DHists] = {
    "Events / 10 GeV",
    "Events / 0.05",
    "Events / 1 GeV",
    "Events",
    //"Events / 0.05"
    "Events / 0.02"
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
    sprintf(Ctitle1D,"%s",plot1DMu[i]);
    //canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,20,700,500);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,20,700,550);
    if(i!=2) canvases1D[i]->SetLogy();
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
  char oldH1DnameMu[100], oldH1DnameMuStandAlone[100], oldH1DnameMuStandAloneUpdatedAtVtx[100], oldH1DnameMuDisplacedStandAlone[100];
  for(int i=0; i<Num1DHists; i++){
    sprintf(oldH1DnameMu,"%shist",plot1DMu[i]);
    sprintf(oldH1DnameMuStandAlone,"%shist",plot1DMuStandAlone[i]);
    sprintf(oldH1DnameMuStandAloneUpdatedAtVtx,"%shist",plot1DMuStandAloneUpdatedAtVtx[i]);
    sprintf(oldH1DnameMuDisplacedStandAlone,"%shist",plot1DMuDisplacedStandAlone[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1DnameMu);
    HAll1D[1][i] = (TH1D*) f1.Get(oldH1DnameMuStandAlone);
    HAll1D[2][i] = (TH1D*) f1.Get(oldH1DnameMuStandAloneUpdatedAtVtx);
    HAll1D[3][i] = (TH1D*) f1.Get(oldH1DnameMuDisplacedStandAlone);
    HAll1D[4][i] = (TH1D*) f2.Get(oldH1DnameMuStandAlone);
    HAll1D[5][i] = (TH1D*) f2.Get(oldH1DnameMuDisplacedStandAlone);
    //HAll1D[3][i] = (TH1D*) f4.Get(oldH1Dname);
    //HAll1D[4][i] = (TH1D*) f5.Get(oldH1Dname);
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

  //put in histogram specifications
  //int color[NumFiles] = {1,2,4,6,8,11};//,12};//,13,14};
  int color[NumFiles] = {1,2,4,11,6,8};//,12};//,13,14};
  int style[NumFiles] = {1,2,3,4,5,6};//,7};//,8,9};
  int marker[NumFiles] = {20,21,22,23,24,25};//,26};//,27,28};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      sprintf(axistitles,";%s;%s",xtitle1D[i],ytitle1D[i]);
      //cout<<"sprintf axis title"<<endl;
      HAll1D[a][i]->SetTitle(axistitles);
      //cout<<"set axis titles"<<endl;
      //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
      HAll1D[a][i]->SetLineWidth(3);
    }
    for(int i=0; i<2; i++){
      HAll1D[a][i]->SetLineColor(color[a]);
      HAll1D[a][i]->SetLineStyle(style[a]);
      //h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //h1_style(HAll1D[a][i],3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
      //cout<<"h1_style"<<endl;
      cout<<"xtitle1D[i] is: "<<xtitle1D[i]<<endl;
    }
    for(int i=3; i<Num1DHists; i++){
      HAll1D[a][i]->SetLineColor(color[a]);
      HAll1D[a][i]->SetLineStyle(style[a]);
      //h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
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
  //h1_style(HAll1D[1][2],3,color[0],style[0],1001,50,-1111.,-1111.,510,510,marker[0],color[0],1,1);
  //h1_style(HAll1D[3][2],3,color[1],style[1],1001,50,-1111.,-1111.,510,510,marker[1],color[1],1,1);
  HAll1D[1][2]->SetLineColor(color[0]);
  HAll1D[1][2]->SetLineStyle(style[0]);
  HAll1D[4][2]->SetLineColor(color[1]);
  HAll1D[4][2]->SetLineStyle(style[1]);

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
    HAll1D[a][0]->Rebin(10);
    HAll1D[a][1]->Rebin(5);
    HAll1D[a][2]->Rebin(4);
    HAll1D[a][4]->Rebin(2);
    

    //HAll1D[a][0]->Rebin(20);
    //HAll1D[a][6]->Rebin(20);
    //HAll1D[a][7]->Rebin(20);
    //HAll1D[a][18]->Rebin(10);
    //HAll1D[a][22]->Rebin(5);

    HAll1D[a][1]->GetXaxis()->SetRangeUser(-1,1);
    HAll1D[a][2]->GetXaxis()->SetRangeUser(0,300);
    HAll1D[a][3]->GetXaxis()->SetRangeUser(0,1);
    //HAll1D[a][4]->GetXaxis()->SetRangeUser(-4,4);
    HAll1D[a][4]->GetXaxis()->SetRangeUser(-2,2);
    //HAll1D[a][4]->GetXaxis()->SetRangeUser(-1,1);

    /*
    HAll1D[a][0]->GetXaxis()->SetRangeUser(0,10);
    HAll1D[a][4]->GetXaxis()->SetRangeUser(-2,2);
    HAll1D[a][5]->GetXaxis()->SetRangeUser(0,5);
    HAll1D[a][8]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][9]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][10]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][11]->GetXaxis()->SetRangeUser(0,50);
    HAll1D[a][17]->GetXaxis()->SetRangeUser(-5,5);
    HAll1D[a][20]->GetXaxis()->SetRangeUser(0,40);
    HAll1D[a][22]->GetXaxis()->SetRangeUser(0,30);
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
  //char* LegFile[NumFiles] = {"Global Muons, Prompt Muon Sample","StandAlone Muons Not Updated At Vertex, Prompt Muon Sample","StandAlone Muons Updated At Vertex, Prompt Muon Sample","Displaced StandAlone Muons, Prompt Muon Sample","StandAlone Muons, Displaced Muon Sample","Displaced StandAlone Muons, Displaced Muon Sample"};
  char* LegFile[NumFiles+1] = {"Prompt Tracker+Muon Fit","Prompt Muon-Only Fit","(no vertex constraint)","Prompt Muon-Only Fit (with vertex constraint)","Prompt Displaced Muon-Only Fit","Displaced Muon-Only Fit","Displaced Muon-Only Fit"};
  //char* LegFileA[3] = {"Tracker+Muon fit (#sigma=0.03)","Muon-only fit (#sigma=0.30)","(no vertex constraint)"};
  char* LegFileA[3] = {"Tracker+Muon fit","Muon-only fit","(no vertex constraint)"};
  //char* LegFileA[4] = {"Muon-only fit","(with vertex constraint)","Muon-only fit","(no vertex constraint)"};
  ////char* LegFileB[1] = {"Displaced muon-only fit (#sigma=0.72)"};
  //char* LegFileB[3] = {"Displaced muon-only fit (#sigma=0.72)","Standard muon-only fit (#sigma=1.34)","(not usable for physics analyses)"};
  char* LegFileB[3] = {"Disp. muon-only fit","Muon-only fit","(no vertex constraint)"};

  char* LegFile2[2] = {"Prompt Muon Sample","Displaced Muon Sample"};

  char LegEntry[100];
  //Leg1 = new TLegend(0.60,0.8,0.95,0.98);
  /*
  Leg1 = new TLegend(0.18,0.74,0.63,0.92);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][1],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);
  */

  Leg1 = new TLegend(0.18,0.74,0.45,0.92);
  sprintf(LegEntry,"%s",LegFile[0]);
  Leg1->AddEntry(HAll1D[0][1],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFile[1]);
  Leg1->AddEntry(HAll1D[1][1],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFile[2]);
  Leg1->AddEntry("",LegEntry,"");
  //sprintf(LegEntry,"%s",LegFile[2]);
  //Leg1->AddEntry(HAll1D[2][1],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFile[5]);
  Leg1->AddEntry(HAll1D[5][1],LegEntry,"l");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);

  
  Leg1a = new TLegend(0.18,0.74,0.48,0.92,"Prompt muons");
  sprintf(LegEntry,"%s",LegFileA[0]);
  Leg1a->AddEntry(HAll1D[0][1],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFileA[1]);
  Leg1a->AddEntry(HAll1D[1][1],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFileA[2]);
  Leg1a->AddEntry("",LegEntry,"");
  //sprintf(LegEntry,"%s",LegFile[2]);
  //Leg1->AddEntry(HAll1D[2][1],LegEntry,"l");
  //sprintf(LegEntry,"%s",LegFileA[5]);
  //Leg1a->AddEntry(HAll1D[5][1],LegEntry,"l");
  Leg1a->SetBorderSize(0);
  Leg1a->SetTextSize(0.03);
  Leg1a->SetFillColor(0);
  
  /*
  Leg1a = new TLegend(0.20,0.74,0.50,0.92,"Prompt muons");
  sprintf(LegEntry,"%s",LegFileA[0]);
  Leg1a->AddEntry(HAll1D[2][1],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFileA[1]);
  Leg1a->AddEntry("",LegEntry,"");
  sprintf(LegEntry,"%s",LegFileA[2]);
  Leg1a->AddEntry(HAll1D[1][1],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFileA[3]);
  Leg1a->AddEntry("",LegEntry,"");
  //sprintf(LegEntry,"%s",LegFile[2]);
  //Leg1->AddEntry(HAll1D[2][1],LegEntry,"l");
  //sprintf(LegEntry,"%s",LegFileA[5]);
  //Leg1a->AddEntry(HAll1D[5][1],LegEntry,"l");
  Leg1a->SetBorderSize(0);
  Leg1a->SetTextSize(0.03);
  Leg1a->SetFillColor(0);
  */
  /*
  Leg1b = new TLegend(0.60,0.82,0.85,0.92,"Displaced muons");
  sprintf(LegEntry,"%s",LegFileB[0]);
  Leg1b->AddEntry(HAll1D[5][1],LegEntry,"l");
  Leg1b->SetBorderSize(0);
  Leg1b->SetTextSize(0.03);
  Leg1b->SetFillColor(0);
  */
  
  Leg1b = new TLegend(0.60,0.74,0.85,0.92,"Displaced muons");
  sprintf(LegEntry,"%s",LegFileB[0]);
  Leg1b->AddEntry(HAll1D[5][1],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFileB[1]);
  Leg1b->AddEntry(HAll1D[4][1],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFileB[2]);
  Leg1b->AddEntry("",LegEntry,"");
  Leg1b->SetBorderSize(0);
  Leg1b->SetTextSize(0.03);
  Leg1b->SetFillColor(0);
  

  Leg2 = new TLegend(0.60,0.8,0.95,0.98);
  sprintf(LegEntry,"%s",LegFile2[0]);
  Leg2->AddEntry(HAll1D[1][2],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFile2[1]);
  Leg2->AddEntry(HAll1D[4][2],LegEntry,"l");
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
  TPaveLabel *text1 = new TPaveLabel(.17,.92,.37,.96,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
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

    scalef0[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[0][i]->GetSumOfWeights());
    scalef1[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    scalef2[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scalef3[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[3][i]->GetSumOfWeights());
    scalef4[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[4][i]->GetSumOfWeights());
    scalef5[i] = (1.0*(Double_t)HAll1D[2][i]->GetSumOfWeights())/((Double_t)HAll1D[5][i]->GetSumOfWeights());
    //scalef6[i] = (1.0*(Double_t)HAll1D[4][i]->GetSumOfWeights())/((Double_t)HAll1D[6][i]->GetSumOfWeights());
    /*
    scalef7[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[7][i]->GetSumOfWeights());
    scalef8[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[8][i]->GetSumOfWeights());
    */

    
    HAll1D[0][i]->Scale(scalef0[i]);
    HAll1D[1][i]->Scale(scalef1[i]);
    HAll1D[2][i]->Scale(scalef2[i]);
    HAll1D[3][i]->Scale(scalef3[i]);    
    HAll1D[4][i]->Scale(scalef4[i]);    
    HAll1D[5][i]->Scale(scalef5[i]);
    //HAll1D[6][i]->Scale(scalef6[i]);
    /*
    HAll1D[7][i]->Scale(scalef7[i]);
    HAll1D[8][i]->Scale(scalef8[i]);
    */
  }

  
  

  cout<<"scaled histograms"<<endl;


  for (int a=0; a<NumFiles; a++){
    HAll1D[a][0]->GetYaxis()->SetRangeUser(.1,400000);
    HAll1D[a][1]->GetYaxis()->SetRangeUser(.1,400000);
    HAll1D[a][2]->GetYaxis()->SetRangeUser(0,11000);
    HAll1D[a][3]->GetYaxis()->SetRangeUser(.1,100000);
    //HAll1D[a][4]->GetYaxis()->SetRangeUser(2,10000);
    //HAll1D[a][4]->GetYaxis()->SetRangeUser(2,5000);
    HAll1D[a][4]->GetYaxis()->SetRangeUser(7,5000);
    //HAll1D[a][4]->GetYaxis()->SetRangeUser(0,10000);
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
  /*
  TF1 *fit1 = new TF1("fit1","gaus",-2,2);
  TF1 *fit2 = new TF1("fit2","gaus",-2,2);
  TF1 *fit3 = new TF1("fit3","gaus",-2,2);
  TF1 *fit4 = new TF1("fit4","gaus",-2,2);
  fit1->SetLineColor(1);
  fit2->SetLineColor(2);
  fit3->SetLineColor(8);
  fit4->SetLineColor(6);

  HAll1D[0][4]->Fit("fit1","R");
  HAll1D[1][4]->Fit("fit2","R");
  HAll1D[5][4]->Fit("fit3","R");
  HAll1D[4][4]->Fit("fit4","R");
  */


  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  //TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists];//, *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];
  //TPaveStats *stats0, *stats1, *stats2;//, *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];
    
  for(int i=0; i<Num1DHists; i++){
  //for(int i=1; i<Num1DHists; i++){
  //for(int i=0; i<17; i++){
    canvases1D[i]->cd();
    cout<<"drawing canvas "<<i<<endl;

  
    //stats0 = (TPaveStats*)HAll1D[0][4]->GetListOfFunctions()->FindObject("stats");
    //stats0->SetY1NDC(.5); //move stats box
    //stats0->SetY2NDC(.6);
    //stats0->SetX1NDC(.75);
    //stats0->SetTextColor(2);
    //stats0->SetBorderSize(0);
      
    //mcMuonPt_hist->Draw("hists");

    if(i==2){
      HAll1D[1][i]->Draw("hists");
      HAll1D[4][i]->Draw("sameshist");
      Leg2->Draw();
    }
    else{
      
      HAll1D[0][i]->Draw("hists");
      HAll1D[1][i]->Draw("sameshist");
      //HAll1D[2][i]->Draw("sameshist");
      //HAll1D[3][i]->Draw("sameshist");
      HAll1D[4][i]->Draw("sameshist");
      HAll1D[5][i]->Draw("sameshist");
      //HAll1D[6][i]->Draw("sameshist");
      
      /*
      HAll1D[0][i]->Draw("funcs");
      HAll1D[1][i]->Draw("samesfunc");
      //HAll1D[2][i]->Draw("samesfunc");
      //HAll1D[3][i]->Draw("samesfunc");
      //HAll1D[4][i]->Draw("samesfunc");
      HAll1D[5][i]->Draw("samesfunc");
      //HAll1D[6][i]->Draw("samesfunc");
      */
      //Leg1->Draw();
      Leg1a->Draw();
      Leg1b->Draw();
    }

    CMS_lumi( canvases1D[i], iPeriod, iPos );
    //text1->Draw();

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
