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

  TH1* h1=new TH1F("h1","",60,-20,40);
  TH1* h2=new TH1F("h2","",60,-20,40);
  TH1* h3=new TH1F("h3","",60,-20,40);
  TH1* h4=new TH1F("h4","",60,-20,40);
  h1->SetStats(kFALSE);
  h2->SetStats(kFALSE);
  h3->SetStats(kFALSE);
  h4->SetStats(kFALSE);
  h1->SetTitle(";Hit Time [ns]; Events/ 1 ns");
  h2->SetTitle(";Hit Time [ns]; Events/ 1 ns");
  h3->SetTitle(";Hit Time [ns]; Events/ 1 ns");
  h4->SetTitle(";Hit Time [ns]; Events/ 1 ns");
  h1_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  h1_style(h2,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  h1_style(h3,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  h1_style(h4,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);

  Int_t nHits_station1 = 39;
  Float_t time_station1[nHits_station1] = {    3.765,    4.944,    0.722,    -0.407,    -11.503,    -0.928,    9.077,    2.91,    6.022,    6.893,    3.238,    1.551,    1.437,    2.881,    -1.303,    -3.453,    -3.69,    -1.938,    1.088,    -2.359,    1.615,    4.031,    1.431,    -2.801,    -0.532,    4.544,    0.338,    -2.705,    -2.97,    -0.704,    6.095,    -5.236,    -1.057,    -2.377,    -0.503,    1.144,    -0.64,    -2.281,    0.582  };

  Int_t nHits_station2 = 47;
  Float_t time_station2[nHits_station2] = {-0.429,-0.429,2.925,2.925,0.657,4.28,-4.401,-0.049,-1.558,-1.633,-6.458,-1.809,3.138,9.526,-4.389,-0.379,-1.848,-4.12,-3.765,-0.74,2.593,-0.747,-0.836,-1.007,-2.715,-2.23,1.307,5.375,1.911,-2.442,0.772,3.558,5.329,6.091,2.08,5.458,4.369,0.706,1.014,4.846,4.796,-5.094,-2.221,-2.609,-5.837,-10.678,-10.323};

  Int_t nHits_station3 = 45;
  Float_t time_station3[nHits_station3] = {2.722,-1.026,-3.104,-2.9,-0.341,2.451,-1.497,-4.497,2.815,-1.66,1.267,-4.6,4.529,0.036,-3.777,-1.429,-1.429,-1.429,1.982,-2.094,-4.662,14.371,5.275,-5.329,-4.84,-0.168,-1.164,-6.372,-1.573,0.697,1.037,-3.905,-8.291,1.939,7.119,8.814,6.01,-4.053,-2.042,-1.732,-3.506,-4.769,-4.982,-2.616,-0.76};

  Int_t nHits_station4 = 51;
  Float_t time_station4[nHits_station4] = {-2.653,-1.11,-4.381,-2.797,-8.719,1.124,4.78,0.728,-0.287,-0.287,-0.287,-0.129,1.477,0.307,-4.595,-4.714,-1.181,6.752,8.426,4.533,1.879,-1.826,0.118,3.217,-8.736,-4.266,-5.828,-12.173,-8.022,4.58,4.382,-6.346,-6.053,12.89,1.706,-7.402,-4.297,-2.896,0.888,1.075,-0.861,4.947,3.011,-1.517,3.476,2.438,-1.745,10.984,-1.364,-12.291,-0.753};


  for(int i=0; i<nHits_station1; i++) h1->Fill(time_station1[i]);
  for(int i=0; i<nHits_station2; i++) h2->Fill(time_station2[i]);
  for(int i=0; i<nHits_station3; i++) h3->Fill(time_station3[i]);
  for(int i=0; i<nHits_station4; i++) h4->Fill(time_station4[i]);

  TF1 *fit1 = new TF1("fit1","gaus",-15,15);
  TF1 *fit2 = new TF1("fit2","gaus",-15,15);
  TF1 *fit3 = new TF1("fit3","gaus",-15,15);
  TF1 *fit4 = new TF1("fit4","gaus",-15,15);
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
  if(save_plots) c1->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTtimes_zmumu_station1.eps");

  c2->cd();
  h2->Draw();
  text1->Draw();
  text_station2->Draw();
  //text1a->Draw();
  //Leg1->Draw();
  if(save_plots) c2->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTtimes_zmumu_station2.eps");

  c3->cd();
  h3->Draw();
  text1->Draw();
  text_station3->Draw();
  //text1a->Draw();
  //Leg1->Draw();
  if(save_plots) c3->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTtimes_zmumu_station3.eps");

  c4->cd();
  h4->Draw();
  text1->Draw();
  text_station4->Draw();
  //text1a->Draw();
  //Leg1->Draw();
  if(save_plots) c4->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTtimes_zmumu_station4.eps");

}
