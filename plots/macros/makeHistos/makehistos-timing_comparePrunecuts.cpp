{
  //overlays histograms, saves eps files

  using namespace std;
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  gROOT->LoadMacro("./style.cpp");
  global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  /////gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  //bool save_plots = false;
  bool save_plots = true;

  const int NumFiles = 5;

  /*
  TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_5_3_9/src/RecoMuon/MuonIdentification/test/test_timing_zmumu_pt20_eta1.root");
  TFile f2("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_5_3_9/src/RecoMuon/MuonIdentification/test/test_timing_allphi_cosmics_pt20_eta1.root");
  TFile f3("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_5_3_9/src/RecoMuon/MuonIdentification/test/test_timing_stop600_neutralino417_pt20_eta1.root");
  //TFile f3("/afs/cern.ch/user/j/jalimena/public/histos/stoppedHSCPMuonHistos_NoBPTX_Run2012B_period2_without_bx_cut_without_other_cut.root"); //collision data Run2012B period2, json file from July 16
  */

  /*
  TFile f1("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2.root");
  TFile f2("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_prune20.root");
  TFile f3("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_prune10.root");
  TFile f4("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_prune5.root");
  TFile f5("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_prune2.root");
  */

  /*
  TFile f1("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2.root");
  TFile f2("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_prune20.root");
  TFile f3("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_prune10.root");
  TFile f4("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_prune5.root");
  TFile f5("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_prune2.root");
  */
  
  /*
  TFile f1("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2.root");
  TFile f2("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_prune20.root");
  TFile f3("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_prune10.root");
  TFile f4("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_prune5.root");
  TFile f5("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_prune2.root");
  */

  /*
  TFile f1("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_upper.root");
  TFile f2("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_upper_prune20.root");
  TFile f3("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_upper_prune10.root");
  TFile f4("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_upper_prune5.root");
  TFile f5("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_upper_prune2.root");
  */

  /*
  TFile f1("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_upper.root");
  TFile f2("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_upper_prune20.root");
  TFile f3("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_upper_prune10.root");
  TFile f4("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_upper_prune5.root");
  TFile f5("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_upper_prune2.root");
  */
  
  
  TFile f1("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_upper.root");
  TFile f2("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_upper_prune20.root");
  TFile f3("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_upper_prune10.root");
  TFile f4("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_upper_prune5.root");
  TFile f5("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_upper_prune2.root");
  

  /*
  TFile f1("/home/alimena/histos/test_timing_zmumu_pt20_eta1_DTChambers2_LESSinvbetaerror1p5.root");
  TFile f2("/home/alimena/histos/test_timing_allphi_cosmics_pt20_eta1_DTChambers2_LESSinvbetaerror1p5.root");
  TFile f3("/home/alimena/histos/test_timing_stop600_neutralino417_pt20_eta1_DTChambers2_LESSinvbetaerror1p5.root");
  */

  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  const int Num1DHists = 15;
  char* plot1D[Num1DHists] = {
    "hi_dt_nmuons",
    "hi_sta_pt",
    "hi_sta_eta",
    "hi_sta_phi",
    "hi_dttime_ndof",
    "hi_dttime_ibt",
    "hi_dttime_ibt_err",
    "hi_dttime_vtx",
    "hi_dttime_vtx_err",
    "dttime_invbetaLS_hist",
    "dttime_invbetaLSError_hist",
    "dttime_yIntercept_hist",
    "dttime_yInterceptError_hist",
    "dttime_chi2Dof_hist",
    "dttime_nHits_hist"
  };

  char* xtitle1D[Num1DHists] = {
    "Number of SA Muons", //0
    "SA p_{T} [GeV]", //1
    "SA #eta", //2
    "SA #phi", //3
    "Number of DT DOF", //4
    "DT #beta^{-1}", //5
    "Error of DT #beta^{-1}", //6
    "DT Time at IP InOut", //7
    "Error of DT Time at IP for In-Out", //8
    "DT #beta^{-1}", //9
    "Error of DT #beta^{-1}", //10
    "Y-Intercept [ns]", //11
    "Error of Y-Intercept", //12
    "#chi^{2}/dof", //13
    "Number of Hits" //14
    



    //"Number of DT Hits in Second SA Muon Track",
    //"Direction of SA Muons",
    //"DT Free #beta^{-1}",
    //"Error of DT Free #beta^{-1}",
    //"DT Time at IP for Out-In",
    //"Error of DT Time at IP for Out-In",
  };
  cout<<"ready for 1D hists"<<endl;

  //info for each 2D plot
  const int Num2DHists = 6;
  char* plot2D[Num2DHists] = {"hi_dttime_ibt_pt","hi_dttime_ibt_ibt_err","sta_phi_dttime_invbetaLS_hist","dttime_invbetaLS_chi2Dof_hist","dttime_nHits_invbetaLS_hist","dttime_nHits_invbetaLSError_hist"};
  char* xtitle2D[Num2DHists] = {"SA p_{T} [GeV]","DT #beta^{-1}","SA #phi","DT #beta^{-1}","Number of DT Hits in Track","Number of DT Hits in Track"};
  char* ytitle2D[Num2DHists] = {"DT #beta^{-1}","Error of DT #beta^{-1}","DT #beta^{-1}","#chi^{2}/dof","DT #beta^{-1}","Error of DT #beta^{-1}"};
  cout<<"ready for 2D hists"<<endl;
  
  //set up canvases
  char Cname1D[200], Ctitle1D[500];
  TCanvas* canvases1D[Num1DHists];
  //TCanvas* canvases1D[17];
  for (int i=0; i<Num1DHists; i++){
    sprintf(Cname1D,"canvases1D[%i]",i);
    sprintf(Ctitle1D,"%s",plot1D[i]);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,10,700,500);
    if(i!=9) canvases1D[i]->SetLogy();
    //canvases1D[i]->SetLogy();
    canvas_style(canvases1D[i]);
  }
  cout<<"made 1D canvases"<<endl;

  
  char Cname2D[200], Ctitle2D[500];
  TCanvas* canvases2D[1.0*NumFiles*Num2DHists];
  for (int i=0; i<Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%szmumudata",plot2D[i]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=1*Num2DHists; i<2.0*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scosmicdata",plot2D[i-Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=2.*Num2DHists; i<1.0*3*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%ssignal",plot2D[i-2*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=3.*Num2DHists; i<1.0*4*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%ssignal",plot2D[i-3*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=4.*Num2DHists; i<1.0*5*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%ssignal",plot2D[i-4*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  cout<<"made 2D canvases"<<endl;

  //get histograms
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  for(int i=0; i<Num1DHists; i++){
    sprintf(oldH1Dname,"dt/%s",plot1D[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1Dname);
    HAll1D[1][i] = (TH1D*) f2.Get(oldH1Dname);
    HAll1D[2][i] = (TH1D*) f3.Get(oldH1Dname);
    HAll1D[3][i] = (TH1D*) f4.Get(oldH1Dname);
    HAll1D[4][i] = (TH1D*) f5.Get(oldH1Dname);
  }

  TH2D* HAll2D[NumFiles][Num2DHists];
  char oldH2Dname[100];
  for(int i=0; i<Num2DHists; i++){
    sprintf(oldH2Dname,"dt/%s",plot2D[i]);
    HAll2D[0][i] = (TH2D*) f1.Get(oldH2Dname);
    HAll2D[1][i] = (TH2D*) f2.Get(oldH2Dname);
    HAll2D[2][i] = (TH2D*) f3.Get(oldH2Dname);
    HAll2D[3][i] = (TH2D*) f4.Get(oldH2Dname);
    HAll2D[4][i] = (TH2D*) f5.Get(oldH2Dname);
  }
  cout<<"got histograms"<<endl;

  //put in histogram specifications
  int color[NumFiles] = {1,2,4,6,13};
  int style[NumFiles] = {1,2,3,4,5};
  int marker[NumFiles] = {20,21,22,23,24};
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
    for(int i=0; i<Num2DHists; i++){
      sprintf(axistitles,";%s;%s",xtitle2D[i],ytitle2D[i]);
      HAll2D[a][i]->SetTitle(axistitles);
      //HAll2D[a][i]->GetYaxis()->SetTitle("Events");
      h2_style(HAll2D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      cout<<"xtitle2D[i] is: "<<xtitle2D[i]<<endl;
    }
  }

  //sumw2 for correct error bars
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      HAll1D[a][i]->Sumw2();
    }
    for(int i=0; i<Num2DHists; i++){
      HAll2D[a][i]->Sumw2();
    }
  }


  for (int a=0; a<NumFiles; a++){
    HAll1D[a][9]->Rebin(50);

    //HAll1D[a][9]->GetXaxis()->SetRangeUser(-5,5);
    HAll1D[a][9]->GetXaxis()->SetRangeUser(-3,3);
    HAll1D[a][13]->GetXaxis()->SetRangeUser(0,30);

    HAll2D[a][2]->GetXaxis()->SetRangeUser(-3.2,3.2);
    HAll2D[a][2]->GetYaxis()->SetRangeUser(-5,5);

    HAll2D[a][3]->GetXaxis()->SetRangeUser(-5,5);
    HAll2D[a][3]->GetYaxis()->SetRangeUser(0,10);

    HAll2D[a][4]->RebinY(50);
    HAll2D[a][4]->GetYaxis()->SetRangeUser(-5,5);

    /*
    HAll1D[a][93]->Rebin(10);
    HAll1D[a][94]->Rebin(10);

    HAll1D[a][89]->GetXaxis()->SetRangeUser(-50,50);
    HAll1D[a][91]->GetXaxis()->SetRangeUser(-50,50);
    HAll1D[a][93]->GetXaxis()->SetRangeUser(-50,50);
    */
  }    
  cout<<"put in histogram specs"<<endl;

  
  //Set up legends
  //char* LegFile[NumFiles] = {"Z#rightarrow#mu#mu Data","Cosmic All-Phi Data","#tilde{t_{1}} 600 GeV"};
  //char* LegFile[NumFiles] = {"Z#rightarrow#mu#mu Data, No hit #chi^{2} cuts","Z#rightarrow#mu#mu Data, hit #chi^{2}<20","Z#rightarrow#mu#mu Data, hit #chi^{2}<10","Z#rightarrow#mu#mu Data, hit #chi^{2}<5","Z#rightarrow#mu#mu Data, hit #chi^{2}<2"};
  //char* LegFile[NumFiles] = {"Cosmic All-Phi Data, No hit #chi^{2} cuts","Cosmic All-Phi Data, hit #chi^{2}<20","Cosmic All-Phi Data, hit #chi^{2}<10","Cosmic All-Phi Data, hit #chi^{2}<5","Cosmic All-Phi Data, hit #chi^{2}<2"};
  char* LegFile[NumFiles] = {"#tilde{t_{1}} 600 GeV, No hit #chi^{2} cuts","#tilde{t_{1}} 600 GeV, hit #chi^{2}<20","#tilde{t_{1}} 600 GeV, hit #chi^{2}<10","#tilde{t_{1}} 600 GeV, hit #chi^{2}<5","#tilde{t_{1}} 600 GeV, hit #chi^{2}<2"};
  char LegEntry[100];
  Leg1 = new TLegend(0.60,0.8,0.95,0.98);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);

  //TPaveLabel *Leg2a = new TPaveLabel(.19,.92,.39,.99,"Z#rightarrow#mu#mu Data, No hit #chi^{2} cuts","NDC");
  //TPaveLabel *Leg2a = new TPaveLabel(.19,.92,.39,.99,"All-Phi Cosmic Data, No hit #chi^{2} cuts","NDC");
  TPaveLabel *Leg2a = new TPaveLabel(.19,.92,.39,.99,"#tilde{t_{1}} 600 GeV, No hit #chi^{2} cuts","NDC");
  Leg2a->SetBorderSize(0);
  Leg2a->SetTextSize(0.7);
  Leg2a->SetFillColor(0);

  //TPaveLabel *Leg2b = new TPaveLabel(.19,.92,.39,.99,"Z#rightarrow#mu#mu Data, hit #chi^{2}<20","NDC");
  //TPaveLabel *Leg2b = new TPaveLabel(.19,.92,.39,.99,"All-Phi Cosmic Data, hit #chi^{2}<20","NDC");
  TPaveLabel *Leg2b = new TPaveLabel(.19,.92,.39,.99,"#tilde{t_{1}} 600 GeV, hit #chi^{2}<20","NDC");
  Leg2b->SetBorderSize(0);
  Leg2b->SetTextSize(0.7);
  Leg2b->SetFillColor(0);

  //TPaveLabel *Leg2c = new TPaveLabel(.19,.92,.39,.99,"Z#rightarrow#mu#mu Data, hit #chi^{2}<10","NDC");
  //TPaveLabel *Leg2c = new TPaveLabel(.19,.92,.39,.99,"All-Phi Cosmic Data, hit #chi^{2}<10","NDC");
  TPaveLabel *Leg2c = new TPaveLabel(.19,.92,.39,.99,"#tilde{t_{1}} 600 GeV, hit #chi^{2}<10","NDC");
  Leg2c->SetBorderSize(0);
  Leg2c->SetTextSize(0.7);
  Leg2c->SetFillColor(0);

  //TPaveLabel *Leg2d = new TPaveLabel(.19,.92,.39,.99,"Z#rightarrow#mu#mu Data, hit #chi^{2}<5","NDC");
  //TPaveLabel *Leg2d = new TPaveLabel(.19,.92,.39,.99,"All-Phi Cosmic Data, hit #chi^{2}<5","NDC");
  TPaveLabel *Leg2d = new TPaveLabel(.19,.92,.39,.99,"#tilde{t_{1}} 600 GeV, hit #chi^{2}<5","NDC");
  Leg2d->SetBorderSize(0);
  Leg2d->SetTextSize(0.7);
  Leg2d->SetFillColor(0);

  //TPaveLabel *Leg2e = new TPaveLabel(.19,.92,.39,.99,"Z#rightarrow#mu#mu Data, hit #chi^{2}<2","NDC");
  //TPaveLabel *Leg2e = new TPaveLabel(.19,.92,.39,.99,"All-Phi Cosmic Data, hit #chi^{2}<2","NDC");
  TPaveLabel *Leg2e = new TPaveLabel(.19,.92,.39,.99,"#tilde{t_{1}} 600 GeV, hit #chi^{2}<2","NDC");
  Leg2e->SetBorderSize(0);
  Leg2e->SetTextSize(0.7);
  Leg2e->SetFillColor(0);

  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    3.4 fb^{-1}","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    5.9 fb^{-1}","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);



  //scale Run2012B and cosmics histograms to Run2012A collision data
  Double_t scalef2[Num1DHists];
  Double_t scalef3[Num1DHists];
  Double_t scalef4[Num1DHists];
  Double_t scalef5[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
    scalef2[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    scalef3[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scalef4[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[3][i]->GetSumOfWeights());
    scalef5[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[4][i]->GetSumOfWeights());

    HAll1D[1][i]->Scale(scalef2[i]);
    HAll1D[2][i]->Scale(scalef3[i]);
    HAll1D[3][i]->Scale(scalef4[i]);
    HAll1D[4][i]->Scale(scalef5[i]);
  }
  cout<<"scaled histograms"<<endl;


  for (int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      if(i==0) HAll1D[a][i]->GetYaxis()->SetRangeUser(.1,10000);
      //else if(i==9) HAll1D[a][i]->GetYaxis()->SetRangeUser(.1,100);
      //else if(i==9) HAll1D[a][i]->GetYaxis()->SetRangeUser(.1,1000);
      else if(i==9) HAll1D[a][i]->GetYaxis()->SetRangeUser(0,225);
      else if(i==13) HAll1D[a][i]->GetYaxis()->SetRangeUser(.1,10000);
      else if(i>9) HAll1D[a][i]->GetYaxis()->SetRangeUser(.1,3000);
      else HAll1D[a][i]->GetYaxis()->SetRangeUser(.1,1000);
    }
  }

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists], *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
    canvases1D[i]->cd();
    cout<<"drawing canvas "<<i<<endl;
    HAll1D[0][i]->Draw("hist");
    HAll1D[1][i]->Draw("samehist");
    HAll1D[2][i]->Draw("samehist");
    HAll1D[3][i]->Draw("samehist");
    HAll1D[4][i]->Draw("samehist");

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
    stats2[i] = (TPaveStats*)HAll1D[2][i]->GetListOfFunctions()->FindObject("stats");
    stats2[i]->SetY1NDC(.5); //move stats box
    stats2[i]->SetY2NDC(.6);
    stats2[i]->SetX1NDC(.75);
    stats2[i]->SetTextColor(4);
    stats2[i]->SetBorderSize(0);
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

    Leg1->Draw();
    text1->Draw();

    //sprintf(canvasesEPS,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/zmumu/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/cosmics/%s.eps",plot1D[i]);
    sprintf(canvasesEPS,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/signal/%s.eps",plot1D[i]);
    if (save_plots) canvases1D[i]->SaveAs(canvasesEPS);

  }


  for(int i=0; i<Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[0][i]->Draw("colz");
    Leg2a->Draw();
    text1->Draw();
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/zmumu/%sNoPruneCuts.eps",plot2D[i]);
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/cosmics/%sNoPruneCuts.eps",plot2D[i]);
    sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/signal/%sNoPruneCuts.eps",plot2D[i]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=Num2DHists; i<2*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[1][i-Num2DHists]->Draw("colz");
    Leg2b->Draw();
    text1->Draw();
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/zmumu/%sprune20.eps",plot2D[i-Num2DHists]);
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/cosmics/%sprune20.eps",plot2D[i-Num2DHists]);
    sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/signal/%sprune20.eps",plot2D[i-Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=2*Num2DHists; i<3*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[2][i-2*Num2DHists]->Draw("colz");
    Leg2c->Draw();
    text1->Draw();
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/zmumu/%sprune10.eps",plot2D[i-2*Num2DHists]);
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/cosmics/%sprune10.eps",plot2D[i-2*Num2DHists]);
    sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/signal/%sprune10.eps",plot2D[i-2*Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=3*Num2DHists; i<4*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[3][i-3*Num2DHists]->Draw("colz");
    Leg2d->Draw();
    text1->Draw();
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/zmumu/%sprune5.eps",plot2D[i-3*Num2DHists]);
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/cosmics/%sprune5.eps",plot2D[i-3*Num2DHists]);
    sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/signal/%sprune5.eps",plot2D[i-3*Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=4*Num2DHists; i<5*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[4][i-4*Num2DHists]->Draw("colz");
    Leg2e->Draw();
    text1->Draw();
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/zmumu/%sprune2.eps",plot2D[i-4*Num2DHists]);
    //sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/cosmics/%sprune2.eps",plot2D[i-4*Num2DHists]);
    sprintf(canvasesEPS2D,"../plots/timing/DT/comparePruneCuts/pt20_eta1_DTchambers2_upper/signal/%sprune2.eps",plot2D[i-4*Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  /*
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
  */

}
