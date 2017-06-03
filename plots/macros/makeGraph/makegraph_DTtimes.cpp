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

  bool save_plots = false;
  //bool save_plots = true;

  TCanvas* c1 = new TCanvas("c1","run 194704, event 114168114",10,10,700,550);
  TCanvas* c2 = new TCanvas("c2","run 194704, event 114361308",10,10,700,550);
  TCanvas* c3 = new TCanvas("c3","run 194704, event 114925174",10,10,700,550);
  TCanvas* c4 = new TCanvas("c4","run 194704, event 114925174, 1 hit removed",10,10,700,550);
  canvas_style(c1);
  canvas_style(c2);
  canvas_style(c3);
  canvas_style(c4);

  TH2* h1=new TH2F("h1","",1100,0,1100,55,0,55);
  TH2* h2=new TH2F("h2","",1100,0,1100,60,-10,50);
  TH2* h3=new TH2F("h3","",1100,0,1100,200,-100,100);
  TH2* h4=new TH2F("h4","",1100,0,1100,200,-100,100);
  h1->SetStats(kFALSE);
  h2->SetStats(kFALSE);
  h3->SetStats(kFALSE);
  h4->SetStats(kFALSE);
  h1->SetTitle(";Hit Position [cm];Hit Time [ns]");
  h2->SetTitle(";Hit Position [cm];Hit Time [ns]");
  h3->SetTitle(";Hit Position [cm];Hit Time [ns]");
  h4->SetTitle(";Hit Position [cm];Hit Time [ns]");
  h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.,0);
  h2_style(h2,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.,0);
  h2_style(h3,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.,0);
  h2_style(h4,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.,0);

  Int_t n_194704_114168114 = 20;
  Float_t distance_194704_114168114[n_194704_114168114] = {698.794,700.540,702.287,704.033,810.831,812.575,814.320,816.064,842.534,844.279,846.023,847.768,948.344,950.086,951.829,953.571,980.138,981.880,983.623,985.365};
  Float_t time_194704_114168114[n_194704_114168114] = {22.86420433,22.92239433,26.33437667,26.39258667,29.74944,26.06013333,24.03994,24.30255333,27.74371267,30.59367333,26.70384667,23.76184333,28.95873667,30.56001333,27.34699333,28.98879,23.95253667,33.85347333,37.56789333,33.573441};
  Float_t time_194704_114168114_error[n_194704_114168114] = {4.24264,4.24264,4.24264,4.24264,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641,3.4641};
  Float_t distance_194704_114168114_error[n_194704_114168114];
  for(int i=0; i<n_194704_114168114; i++){
    distance_194704_114168114_error[i]=0.;
  }

  Int_t n_194704_114361308 = 23;
  Float_t distance_194704_114361308[n_194704_114361308] = {477.151,478.648,480.146,481.644,504.427,505.925,508.920,570.791,572.286,573.781,575.275,598.011,599.506,601.001,602.495,694.064,695.556,697.047,698.539,721.060,722.552,724.043,725.534};
  Float_t time_194704_114361308[n_194704_114361308] = {4.031, 1.431, -2.801,-0.532,4.544, 0.338, -2.705,6.091, 2.080, 5.458, 4.369, 0.706, 1.014, 4.846, 4.796, -3.905,-8.291,1.939, 7.119, 8.814, 6.010, -4.053,-2.042};
  Float_t corrected_time_194704_114361308[n_194704_114361308];
  Float_t time_194704_114361308_error[n_194704_114361308] = {3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464};
  Float_t distance_194704_114361308_error[n_194704_114361308];
  for(int i=0; i<n_194704_114361308; i++){
    distance_194704_114361308_error[i]=0.;
    corrected_time_194704_114361308[i]=distance_194704_114361308[i]/30.+time_194704_114361308[i];
  }

  Int_t n_194704_114925174 = 29;
  Float_t distance_194704_114925174[n_194704_114925174] = {425.606,426.933,428.260,429.587,451.079,452.406,453.733,508.856,510.182,511.509,512.835,532.936,534.262,535.588,618.001,620.651,621.976,642.031,643.357,644.682,646.007,722.459,723.783,725.108,726.432,746.609,747.933,749.258,750.582};
  Float_t time_194704_114925174[n_194704_114925174] = {7.871,-2.457,-1.315,10.163,4.990, 4.288, 4.446, 7.101, 5.233, 5.958, 3.752, 1.455, -1.303,0.876, 3.459, 2.858, 4.995, 2.739, 1.830, -2.498,-1.165,-5.468,6.435, 13.254,7.199,   -59.856,  -18.374,20.227,-15.407};
  Float_t corrected_time_194704_114925174[n_194704_114925174];
  Float_t time_194704_114925174_error[n_194704_114925174] = {3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.464,3.464,3.464,3.464,3.464,3.464,3.464,3.464};
  Float_t distance_194704_114925174_error[n_194704_114925174];
  for(int i=0; i<n_194704_114925174; i++){
    distance_194704_114925174_error[i]=0.;
    corrected_time_194704_114925174[i]=distance_194704_114925174[i]/30.+time_194704_114925174[i];
    //cout<<"i is: "<<i<<", time is: "<<corrected_time_194704_114925174[i]<<", distance is: "<<distance_194704_114925174[i]<<endl;
  }

  Int_t n_194704_114925174_ = 28;
  Float_t distance_194704_114925174_[n_194704_114925174_] = {425.606,426.933,428.260,429.587,451.079,452.406,453.733,508.856,510.182,511.509,512.835,532.936,534.262,535.588,618.001,620.651,621.976,642.031,643.357,644.682,646.007,722.459,723.783,725.108,726.432,747.933,749.258,750.582};
  Float_t time_194704_114925174_[n_194704_114925174_] = {7.871,-2.457,-1.315,10.163,4.990, 4.288, 4.446, 7.101, 5.233, 5.958, 3.752, 1.455, -1.303,0.876, 3.459, 2.858, 4.995, 2.739, 1.830, -2.498,-1.165,-5.468,6.435, 13.254,7.199, -18.374,20.227,-15.407};
  Float_t corrected_time_194704_114925174_[n_194704_114925174_];
  Float_t time_194704_114925174__error[n_194704_114925174_] = {3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.550,3.464,3.464,3.464,3.464,3.464,3.464,3.464};
  Float_t distance_194704_114925174__error[n_194704_114925174_];
  for(int i=0; i<n_194704_114925174_; i++){
    distance_194704_114925174__error[i]=0.;
    corrected_time_194704_114925174_[i]=distance_194704_114925174_[i]/30.+time_194704_114925174_[i];
    //cout<<"i is: "<<i<<", time is: "<<corrected_time_194704_114925174_[i]<<", distance is: "<<distance_194704_114925174_[i]<<endl;
  }


  TGraphErrors* graph_194704_114168114 = new TGraphErrors(n_194704_114168114, distance_194704_114168114, time_194704_114168114, distance_194704_114168114_error, time_194704_114168114_error);
  TGraphErrors* graph_194704_114361308 = new TGraphErrors(n_194704_114361308, distance_194704_114361308, corrected_time_194704_114361308, distance_194704_114361308_error, time_194704_114361308_error);
  TGraphErrors* graph_194704_114925174 = new TGraphErrors(n_194704_114925174, distance_194704_114925174, corrected_time_194704_114925174, distance_194704_114925174_error, time_194704_114925174_error);
  TGraphErrors* graph_194704_114925174_ = new TGraphErrors(n_194704_114925174_, distance_194704_114925174_, corrected_time_194704_114925174_, distance_194704_114925174__error, time_194704_114925174__error);
  //gr_style(graph_194704_114168114,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.,1);
  gr_style(graph_194704_114168114,1,1,1,1001,50,-1111,-1111,510,510,5,1,1.5,1);
  gr_style(graph_194704_114361308,1,1,1,1001,50,-1111,-1111,510,510,5,1,1.5,1);
  gr_style(graph_194704_114925174,1,1,1,1001,50,-1111,-1111,510,510,5,1,1.5,1);
  gr_style(graph_194704_114925174_,1,1,1,1001,50,-1111,-1111,510,510,5,1,1.5,1);
  graph_194704_114168114->SetTitle(";Hit Position [cm];Hit Time [ns]");
  graph_194704_114361308->SetTitle(";Hit Position [cm];Hit Time [ns]");
  graph_194704_114925174->SetTitle(";Hit Position [cm];Hit Time [ns]");
  graph_194704_114925174_->SetTitle(";Hit Position [cm];Hit Time [ns]");

  TF1 *linfit1 = new TF1("linfit1","[0]*x+[1]",698.794,985.365);
  TF1 *linfit2 = new TF1("linfit2","[0]*x+[1]",477.151,725.534);
  TF1 *linfit3 = new TF1("linfit3","[0]*x+[1]",425.606,750.582);
  TF1 *linfit4 = new TF1("linfit4","[0]*x+[1]",425.606,750.582);
  linfit1->SetLineColor(2);
  linfit2->SetLineColor(2);
  linfit3->SetLineColor(2);
  linfit4->SetLineColor(2);

  graph_194704_114168114->Fit("linfit1","R");
  graph_194704_114361308->Fit("linfit2","R");
  graph_194704_114925174->Fit("linfit3","R");
  graph_194704_114925174_->Fit("linfit4","R");
  /*
  Leg1 = new TLegend(0.45,0.75,0.75,0.85);
  Leg1->AddEntry(graph_194704_114168114_noChaCut,"Average Before TS","p");
  Leg1->AddEntry(graph_194704_114168114,"After TS","p");
  Leg1->AddEntry(graph_194704_114168114_predicted,"Predicted After TS","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);
  */

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

  TPaveText* text2a = new TPaveText(100,-5,1000,5);
  text2a->SetBorderSize(0);
  text2a->SetTextSize(0.05);
  text2a->SetFillColor(0);
  double p1_2  = linfit2->GetParameter(0)*30.;
  double p2_2  = linfit2->GetParameter(1);
  double e1_2  = linfit2->GetParError(0)*30.;
  double e2_2  = linfit2->GetParError(1);
  char p1e1name_2[50], p2e2name_2[50];
  sprintf(p1e1name_2,"#beta^{-1} = %.2f #pm %.2f",p1_2,e1_2);
  sprintf(p2e2name_2,"y-intercept = %.2f #pm %.2f ns",p2_2,e2_2);
  text2a->AddText(p1e1name_2);
  text2a->AddText(p2e2name_2);

  TPaveText* text3a = new TPaveText(100,-90,1000,-60);
  text3a->SetBorderSize(0);
  text3a->SetTextSize(0.05);
  text3a->SetFillColor(0);
  double p1_3  = linfit3->GetParameter(0)*30.;
  double p2_3  = linfit3->GetParameter(1);
  double e1_3  = linfit3->GetParError(0)*30.;
  double e2_3  = linfit3->GetParError(1);
  char p1e1name_3[50], p2e2name_3[50];
  sprintf(p1e1name_3,"#beta^{-1} = %.2f #pm %.2f",p1_3,e1_3);
  sprintf(p2e2name_3,"y-intercept = %.2f #pm %.2f ns",p2_3,e2_3);
  text3a->AddText(p1e1name_3);
  text3a->AddText(p2e2name_3);

  TPaveText* text4a = new TPaveText(100,-90,1000,-60);
  text4a->SetBorderSize(0);
  text4a->SetTextSize(0.05);
  text4a->SetFillColor(0);
  double p1_4  = linfit4->GetParameter(0)*30.;
  double p2_4  = linfit4->GetParameter(1);
  double e1_4  = linfit4->GetParError(0)*30.;
  double e2_4  = linfit4->GetParError(1);
  char p1e1name_4[50], p2e2name_4[50];
  sprintf(p1e1name_4,"#beta^{-1} = %.2f #pm %.2f",p1_4,e1_4);
  sprintf(p2e2name_4,"y-intercept = %.2f #pm %.2f ns",p2_4,e2_4);
  text4a->AddText(p1e1name_4);
  text4a->AddText(p2e2name_4);

  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    3.4 fb^{-1}","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    4.4 fb^{-1}","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);

  TPaveLabel *text_runevent1 = new TPaveLabel(.22,.79,.37,.84,"Run 194704, Event 114168114","NDC");
  text_runevent1->SetBorderSize(0);
  text_runevent1->SetTextSize(0.7);
  text_runevent1->SetFillColor(0);

  TPaveLabel *text_runevent2 = new TPaveLabel(.22,.79,.37,.84,"Run 194704, Event 114361308","NDC");
  text_runevent2->SetBorderSize(0);
  text_runevent2->SetTextSize(0.7);
  text_runevent2->SetFillColor(0);

  TPaveLabel *text_runevent3 = new TPaveLabel(.22,.79,.37,.84,"Run 194704, Event 114925174","NDC");
  text_runevent3->SetBorderSize(0);
  text_runevent3->SetTextSize(0.7);
  text_runevent3->SetFillColor(0);

  TPaveLabel *text_runevent4 = new TPaveLabel(.3,.79,.5,.84,"Run 194704, Event 114925174, 1 Hit Removed","NDC");
  text_runevent4->SetBorderSize(0);
  text_runevent4->SetTextSize(0.7);
  text_runevent4->SetFillColor(0);

  c1->cd();
  h1->Draw();
  graph_194704_114168114->Draw("Psame");
  text1->Draw();
  text_runevent1->Draw();
  text1a->Draw();
  //Leg1->Draw();
  if(save_plots) c1->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTtimes_zmumu_194704_114168114.eps");

  c2->cd();
  h2->Draw();
  graph_194704_114361308->Draw("Psame");
  text1->Draw();
  text_runevent2->Draw();
  text2a->Draw();
  //Leg1->Draw();
  if(save_plots) c2->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTtimes_zmumu_194704_114361308.eps");

  c3->cd();
  h3->Draw();
  graph_194704_114925174->Draw("Psame");
  text1->Draw();
  text_runevent3->Draw();
  text3a->Draw();
  //Leg1->Draw();
  if(save_plots) c3->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTtimes_zmumu_194704_114925174.eps");

  c4->cd();
  h4->Draw();
  graph_194704_114925174_->Draw("Psame");
  text1->Draw();
  text_runevent4->Draw();
  text4a->Draw();
  //Leg1->Draw();
  if(save_plots) c4->SaveAs("../plots/StoppedHSCPMuon/RecoData/DTtimes/DTtimes_zmumu_194704_114925174_1hitremoved.eps");

}
