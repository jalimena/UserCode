{
  //overlays histograms, saves eps files

  using namespace std;
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  gROOT->LoadMacro("style.cpp");
  global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  /////gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  bool save_plots = false;
  //bool save_plots = true;

  const int NumFiles = 1;
  
  TFile f1("/home/alimena/histos/NoBPTX_Run2012_globalMuMatching/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_wRpcBxCut__wDtHitsCut_wCscHitsCut_wDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_wCosEnrich.root");


  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  const int Num1DHists = 1;
  char* plot1D[Num1DHists] = {
    "muDisplacedStandAlonePtResolution_"
  };

  char* xtitle1D[Num1DHists] = {
    "#Delta p_{T} / p_{T}"
  };
  cout<<"ready for 1D hists"<<endl;

  //set up canvases
  char Cname1D[200], Ctitle1D[500];
  TCanvas* canvases1D[Num1DHists];
  //TCanvas* canvases1D[17];
  for (int i=0; i<NumFiles; i++){
    sprintf(Cname1D,"canvases1D[%i]",i);
    sprintf(Ctitle1D,"%s",plot1D[i]);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,10,700,500);
    //if (i<89) canvases1D[i]->SetLogy();
    canvas_style(canvases1D[i]);
  }
  cout<<"made 1D canvases"<<endl;

  //get histograms
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  for(int i=0; i<Num1DHists; i++){
    sprintf(oldH1Dname,"%shist",plot1D[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1Dname);
  }
  cout<<"got histograms"<<endl;

  //put in histogram specifications
  int color[NumFiles] = {1};//,2};//,4,6,8,11};
  int style[NumFiles] = {1};//,2};//,3,4,5,6};
  int marker[NumFiles] = {20};//,21};//,22,23,24,25};
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
  }

  //sumw2 for correct error bars
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      HAll1D[a][i]->Sumw2();
    }
  }


  //for (int a=0; a<NumFiles; a++){
  HAll1D[0][0]->Rebin(10);
  HAll1D[0][0]->GetXaxis()->SetRangeUser(-2,2);

  //}
  cout<<"put in histogram specs"<<endl;

  


  //Set up legends
  /*
  char* LegFile[NumFiles] = {"Collision Run2012A Data","Collision Run2012B period 1 Data","Collision Run2012B period 2 Data","Collision Run2012C-v1 Data","Collision Run2012C-v2 Data","Cosmic Data, Run 195155"};
  char LegEntry[100];
  Leg1 = new TLegend(0.60,0.8,0.95,0.98);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);
  */

  TPaveLabel *Leg2c = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012B period 2 Data","NDC");
  Leg2c->SetBorderSize(0);
  Leg2c->SetTextSize(0.7);
  Leg2c->SetFillColor(0);


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    3.4 fb^{-1}","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    5.9 fb^{-1}","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  /*
  //scale Run2012B and cosmics histograms to Run2012A collision data
  Double_t scaleRun2012Bperiod1[Num1DHists];
  Double_t scaleRun2012Bperiod2[Num1DHists];
  Double_t scaleRun2012Cv1[Num1DHists];
  Double_t scaleRun2012Cv2[Num1DHists];
  Double_t scalecosmics[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
    scaleRun2012Bperiod1[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    scaleRun2012Bperiod2[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scaleRun2012Cv1[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[3][i]->GetSumOfWeights());
    scaleRun2012Cv2[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[4][i]->GetSumOfWeights());
    scalecosmics[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[5][i]->GetSumOfWeights());

    HAll1D[1][i]->Scale(scaleRun2012Bperiod1[i]);
    HAll1D[2][i]->Scale(scaleRun2012Bperiod2[i]);
    HAll1D[3][i]->Scale(scaleRun2012Cv1[i]);
    HAll1D[4][i]->Scale(scaleRun2012Cv2[i]);
    HAll1D[5][i]->Scale(scalecosmics[i]);
  }
  cout<<"scaled histograms"<<endl;
  */

  for (int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      //HAll1D[a][i]->GetYaxis()->SetRangeUser(1,300000);
    }
  }

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists], *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];

  for(int i=0; i<NumFiles; i++){
    canvases1D[i]->cd();
    cout<<"drawing canvas "<<i<<endl;
    HAll1D[0][i]->Draw("hist");
    //HAll1D[1][i]->Draw("samehist");
    //Leg1->Draw();
    text1->Draw();


    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%s.eps",plot1D[i]);
    if (save_plots) canvases1D[i]->SaveAs("../../plots/StoppedHSCPMuon/RecoData/TriggerTurnOn/turnon_Run2012C_ControlTrigger.eps");

  }

}
