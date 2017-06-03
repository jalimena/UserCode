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
  
  //info for each 1D plot
  const int Num1DHists = 1;
  char* plot1D[Num1DHists] = {
    "stoppingRegionPercentage_"
  };

  char* xtitle1D[Num1DHists] = {
    ""
  };
  cout<<"ready for 1D hists"<<endl;

  //set up canvases
  char Cname1D[200], Ctitle1D[500];
  TCanvas* canvases1D[Num1DHists];
  //TCanvas* canvases1D[17];
  for (int i=0; i<Num1DHists; i++){
    sprintf(Cname1D,"canvases1D[%i]",i);
    sprintf(Ctitle1D,"%s",plot1D[i]);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,10,700,500);
    //if (i<89) canvases1D[i]->SetLogy();
    canvas_style(canvases1D[i]);
  }
  cout<<"made 1D canvases"<<endl;

  //const Int_t n_detectorRegions = 8;
  const Int_t n_detectorRegions = 9;

  //get histograms
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  //for(int i=0; i<Num1DHists; i++){
  //sprintf(oldH1Dname,"%shist",plot1D[i]);
    HAll1D[0][0] = new TH1D("h1","",n_detectorRegions,0,n_detectorRegions);
    HAll1D[1][0] = new TH1D("h2","",n_detectorRegions,0,n_detectorRegions);
    HAll1D[2][0] = new TH1D("h3","",n_detectorRegions,0,n_detectorRegions);
    HAll1D[3][0] = new TH1D("h4","",n_detectorRegions,0,n_detectorRegions);
    HAll1D[4][0] = new TH1D("h5","",n_detectorRegions,0,n_detectorRegions);
    //}
  cout<<"got histograms"<<endl;

  //detector only
  //Float_t stop_regionFraction[n_detectorRegions] = {2.9,8.88,0.96,27.63,6.4,40.6,12.35};
  //Float_t gluino_regionFraction[n_detectorRegions] = {1.66,7.28,0.85,30.13,6.54,40.05,13.28,0.21};
  //Float_t mchamp_regionFraction[n_detectorRegions] = {3.73,11.37,1.08,28.84,7.13,34.25,13.28,0.32};
  //Float_t gmstau_regionFraction[n_detectorRegions] = {2.67,8.9,0.91,27.29,4.87,45.06,10.03,0.27};
  //Float_t ppstau_regionFraction[n_detectorRegions] = {0.56,4.23,0.08,25.96,1.84,59.9,7.35,0.08};
  //TString regionLabels[n_detectorRegions] = {"Tracker","EB","EE","HB","HE","MB","ME","Other"};

  //all that stop
  Float_t stop_regionFraction[n_detectorRegions] = {2.61,8.00,0.86,24.89,5.77,36.57,11.13,0.25,9.92};
  Float_t gluino_regionFraction[n_detectorRegions] = {1.50,6.56,0.77,27.18,5.90,36.14,11.98,0.19,9.78};
  Float_t mchamp_regionFraction[n_detectorRegions] = {3.41,10.37,0.99,26.30,6.50,31.22,12.11,0.29,8.81};
  Float_t gmstau_regionFraction[n_detectorRegions] = {2.38,7.95,0.82,24.37,4.35,40.23,8.96,0.24,10.70};
  Float_t ppstau_regionFraction[n_detectorRegions] = {0.47,3.59,0.07,22.03,1.56,50.85,6.24,0.07,15.12};
  TString regionLabels[n_detectorRegions] = {"Tracker","EB","EE","HB","HE","MB","ME","Other","Walls"};

  for(int z=0; z<n_detectorRegions; z++){
    HAll1D[0][0]->SetBinContent(z+1,1.*stop_regionFraction[z]/100);
    HAll1D[1][0]->SetBinContent(z+1,1.*gluino_regionFraction[z]/100);
    HAll1D[2][0]->SetBinContent(z+1,1.*mchamp_regionFraction[z]/100);
    HAll1D[3][0]->SetBinContent(z+1,1.*gmstau_regionFraction[z]/100);
    HAll1D[4][0]->SetBinContent(z+1,1.*ppstau_regionFraction[z]/100);
    for(int a=0; a<NumFiles; a++){
      HAll1D[a][0]->GetXaxis()->SetBinLabel(z+1,regionLabels[z]);
    }
  }
  //put in histogram specifications
  int color[NumFiles] = {1,2,4,6,8};//,11};
  int style[NumFiles] = {1,2,3,4,5};//,6};
  int marker[NumFiles] = {20,21,22,23,24};//,25};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      sprintf(axistitles,";;Fraction of Events");
      //cout<<"sprintf axis title"<<endl;
      HAll1D[a][i]->SetTitle(axistitles);
      //cout<<"set axis titles"<<endl;
      //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
      h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      HAll1D[a][i]->SetLabelOffset(0.005,"X");
      HAll1D[a][i]->SetLabelSize(0.04,"X");
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


  for (int a=0; a<NumFiles; a++){
    //HAll1D[a][0]->Rebin(5);
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

  /*
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
  */

  for (int a=0; a<NumFiles; a++){
    HAll1D[a][0]->GetYaxis()->SetRangeUser(0,0.8);
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


    //sprintf(canvasesEPS,"../../plots/StoppedHSCPMuon/RecoData/signalMC/allsamples/%s_DetectorOnly.eps",plot1D[i]);
    sprintf(canvasesEPS,"../../plots/StoppedHSCPMuon/RecoData/signalMC/allsamples/%s_AllThatStop.eps",plot1D[i]);
    if (save_plots) canvases1D[i]->SaveAs(canvasesEPS);

  }
}
