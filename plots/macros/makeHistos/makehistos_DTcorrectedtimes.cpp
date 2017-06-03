{
  //plots trigger rate as function of number of colliding bunches, saves eps files
  // 7e33 V3 menu, June/July 2012

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
  gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptFit(11111);
  gStyle->SetFitFormat("5.3g");

  //bool save_plots = false;
  bool save_plots = true;

  TCanvas* c1 = new TCanvas("c1","",10,10,700,550);
  TCanvas* c2 = new TCanvas("c2","",10,10,700,550);
  TCanvas* c3 = new TCanvas("c3","",10,10,700,550);
  TCanvas* c4 = new TCanvas("c4","",10,10,700,550);
  canvas_style(c1);
  canvas_style(c2);
  canvas_style(c3);
  canvas_style(c4);

  TH1* h1=new TH1F("h1","",60,0,60);
  TH1* h2=new TH1F("h2","",60,0,60);
  TH1* h3=new TH1F("h3","",60,0,60);
  TH1* h4=new TH1F("h4","",60,0,60);
  h1->SetStats(kFALSE);
  h2->SetStats(kFALSE);
  h3->SetStats(kFALSE);
  h4->SetStats(kFALSE);
  h1->SetTitle(";Corrected Time [ns]; Events/ 1 ns");
  h2->SetTitle(";Corrected Time [ns]; Events/ 1 ns");
  h3->SetTitle(";Corrected Time [ns]; Events/ 1 ns");
  h4->SetTitle(";Corrected Time [ns]; Events/ 1 ns");
  h1_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  h1_style(h2,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  h1_style(h3,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  h1_style(h4,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);

  Int_t nHits_station1 = 39;
  Float_t time_station1[nHits_station1] = {17.817,19.040,14.905,14.439,3.386,14.005,24.054,17.568,20.725,21.641,18.723,17.081,17.013,18.502,19.250,17.163,16.989,18.804,22.785,19.401,23.500,19.936,17.386,13.204,15.523,21.358,17.202,14.259,16.467,18.793,25.652,14.381,16.252,14.986,16.914,18.615,17.652,16.065,19.036};

  Int_t nHits_station2 = 47;
  Float_t time_station2[nHits_station2] = {22.864,22.922,26.335,26.393,17.655,21.322,12.686,21.043,16.245,16.259,10.328,15.021,20.012,26.443,13.190,17.244,15.818,13.590,20.731,23.819,27.215,23.938,24.800,24.692,23.047,23.595,18.344,22.456,19.036,14.727,18.650,21.480,23.295,25.117,21.156,24.584,23.545,20.640,20.998,24.879,24.879,17.434,20.364,20.034,16.864,12.897,13.310};

  Int_t nHits_station3 = 45;
  Float_t time_station3[nHits_station3] = {29.750,26.060,24.040,24.302,27.743,30.594,26.704,23.762,23.427,18.996,21.968,16.145,25.946,21.497,17.773,20.623,20.669,20.714,28.643,24.624,22.169,42.059,33.019,22.528,15.823,20.539,19.587,14.423,19.932,22.246,22.630,19.230,14.894,25.174,30.404,32.849,30.095,20.082,22.142,25.556,23.840,22.635,23.356,25.770,27.694};

  Int_t nHits_station4 = 51;
  Float_t time_station4[nHits_station4] = {28.958,30.560,27.347,28.989,23.952,33.853,37.567,33.574,25.004,25.050,25.097,23.747,25.397,24.270,20.034,19.959,23.579,31.545,33.310,29.462,27.500,23.840,25.829,28.974,22.374,26.900,25.395,19.106,24.116,36.774,36.633,25.961,18.075,37.062,25.922,16.858,20.636,22.125,25.953,32.911,31.033,36.899,35.020,27.878,32.925,31.941,27.812,41.359,29.065,18.192,29.785};


  for(int i=0; i<nHits_station1; i++) h1->Fill(time_station1[i]);
  for(int i=0; i<nHits_station2; i++) h2->Fill(time_station2[i]);
  for(int i=0; i<nHits_station3; i++) h3->Fill(time_station3[i]);
  for(int i=0; i<nHits_station4; i++) h4->Fill(time_station4[i]);

  TF1 *fit1 = new TF1("fit1","gaus",0,30);
  TF1 *fit2 = new TF1("fit2","gaus",0,40);
  TF1 *fit3 = new TF1("fit3","gaus",10,45);
  TF1 *fit4 = new TF1("fit4","gaus",10,50);
  fit1->SetLineColor(2);
  fit2->SetLineColor(2);
  fit3->SetLineColor(2);
  fit4->SetLineColor(2);

  h1->Fit("fit1","R");
  h2->Fit("fit2","R");
  h3->Fit("fit3","R");
  h4->Fit("fit4","R");

  h1->GetYaxis()->SetRangeUser(0,10);
  h2->GetYaxis()->SetRangeUser(0,10);
  h3->GetYaxis()->SetRangeUser(0,10);
  h4->GetYaxis()->SetRangeUser(0,10);

  /*
  Leg1 = new TLegend(0.45,0.75,0.75,0.85);
  Leg1->AddEntry(graph_194704_114168114_noChaCut,"Average Before TS","p");
  Leg1->AddEntry(graph_194704_114168114,"After TS","p");
  Leg1->AddEntry(graph_194704_114168114_predicted,"Predicted After TS","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);
  */

  /*
  TPaveText* text1a = new TPaveText(100,5,1000,15);
  text1a->SetBorderSize(0);
  text1a->SetTextSize(0.05);
  text1a->SetFillColor(0);
  double p1_1  = linfit1->GetParameter(0)*30.;
  double p2_1  = linfit1->GetParameter(1);
  double e1_1  = linfit1->GetParError(0)*30.;
  double e2_1  = linfit1->GetParError(1);
  char p1e1name_1[50], p2e2name_1[50];
  sprintf(p1e1name_1,"#beta^{-1} = %.2f #pm %.2f",p1_1,e1_1);
  sprintf(p2e2name_1,"y-intercept = %.2f #pm %.2f ns",p2_1,e2_1);
  text1a->AddText(p1e1name_1);
  text1a->AddText(p2e2name_1);
  */

  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    3.4 fb^{-1}","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    4.4 fb^{-1}","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);

  TPaveLabel *text_station1 = new TPaveLabel(.22,.79,.37,.84,"Station 1","NDC");
  TPaveLabel *text_station2 = new TPaveLabel(.22,.79,.37,.84,"Station 2","NDC");
  TPaveLabel *text_station3 = new TPaveLabel(.22,.79,.37,.84,"Station 3","NDC");
  TPaveLabel *text_station4 = new TPaveLabel(.22,.79,.37,.84,"Station 4","NDC");
  text_station1->SetBorderSize(0);
  text_station2->SetBorderSize(0);
  text_station3->SetBorderSize(0);
  text_station4->SetBorderSize(0);
  text_station1->SetTextSize(0.7);
  text_station2->SetTextSize(0.7);
  text_station3->SetTextSize(0.7);
  text_station4->SetTextSize(0.7);
  text_station1->SetFillColor(0);
  text_station2->SetFillColor(0);
  text_station3->SetFillColor(0);
  text_station4->SetFillColor(0);

  c1->cd();
  h1->Draw();
  text1->Draw();
  text_station1->Draw();
  //text1a->Draw();
  //Leg1->Draw();
  if(save_plots) c1->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTcorrectedtimes_zmumu_station1.eps");

  c2->cd();
  h2->Draw();
  text1->Draw();
  text_station2->Draw();
  //text1a->Draw();
  //Leg1->Draw();
  if(save_plots) c2->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTcorrectedtimes_zmumu_station2.eps");

  c3->cd();
  h3->Draw();
  text1->Draw();
  text_station3->Draw();
  //text1a->Draw();
  //Leg1->Draw();
  if(save_plots) c3->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTcorrectedtimes_zmumu_station3.eps");

  c4->cd();
  h4->Draw();
  text1->Draw();
  text_station4->Draw();
  //text1a->Draw();
  //Leg1->Draw();
  if(save_plots) c4->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTcorrectedtimes_zmumu_station4.eps");

}
