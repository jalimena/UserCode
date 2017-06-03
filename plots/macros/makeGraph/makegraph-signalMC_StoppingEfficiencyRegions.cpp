{
  //plots signal MC efficiencies, saves eps files

  using namespace std;
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  //gROOT->LoadMacro("./style.cpp");
  //global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow

  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("CMS_lumi.C");

  setTDRStyle();
  //tdrGrid(false, tdrStyle);                                                                                                                                                                
  gStyle->SetPalette(1);
  writeExtraText = true;
  extraText  = "Preliminary Simulation";
  //lumi_8TeV = ""; 
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
  //int iPos=0;  
  int iPos=11;
  //int iPos=22; 
  bool save_plots = false;
  //bool save_plots = true;

  TCanvas* c1 = new TCanvas("c1","c1",10,10,575,500);
  //canvas_style(c1);
  c1->SetRightMargin(0.13);

  //TH2* h1=new TH2F("h1","",8,0,8,100,0,1.0);//fraction of stopped events
  TH2* h1=new TH2F("h1","",8,0,8,100,0,2);//cumulative fraction of stopped events
  //TH2* h1=new TH2F("h1","",8,0,8,100,0,0.25); //total stopping fraction
  //TH2* h1=new TH2F("h1","",8,0,8,100,0,0.8); //cumulative total stopping fraction
  h1->SetStats(kFALSE);
  h1->SetTitle(";;Fraction of Stopped Events");
  //h1->SetTitle(";;Total Stopping Fraction");
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);
  h1->SetLabelOffset(0.01,"X");

  const int nbins = h1->GetNbinsX();
  string RegionLabel[] = {"Tracker","Ecal Barrel","Ecal Endcaps","Hcal Barrel","Hcal Endcaps","Muon Barrel","Muon Endcaps","Other"}; //"other" now includes cavern walls
  for (int x=0; x<nbins; x++) {
    h1->GetXaxis()->SetBinLabel(x+1,RegionLabel[x].c_str());
  }

  const Int_t n_detectorRegions = 8;
  Float_t detectorRegions[n_detectorRegions];
  for(int i=0; i<n_detectorRegions; i++){
    detectorRegions[i] = i+0.5;
  }

  //stopping efficiency, stops
  //Float_t stop_stoppingEfficiency[n_detectorRegions] = {0.024,0.077,0.007,0.250,0.055,0.369,0.113,0.105}; //out of those stopped
  Float_t stop_stoppingEfficiency[n_detectorRegions] = {0.024,0.101,0.108,0.358,0.413,0.782,0.895,1.0}; //cumulative out of those stopped
  //Float_t stop_stoppingEfficiency[n_detectorRegions] = {0.005,0.016,0.002,0.047,0.011,0.065,0.021,0.018}; //out of total generated
  //Float_t stop_stoppingEfficiency[n_detectorRegions] = {0.005,0.021,0.023,0.070,0.081,0.146,0.167,0.185}; //cumulative out of total generated

  TGraph* graph_stop_stoppingEfficiency = new TGraph(n_detectorRegions, detectorRegions, stop_stoppingEfficiency);
  //gr_style(graph_stop_stoppingEfficiency,3,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  graph_stop_stoppingEfficiency->SetTitle(";;Fraction of Stopped Events");
  graph_stop_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_stop_stoppingEfficiency->SetMarkerStyle(22);
  graph_stop_stoppingEfficiency->SetMarkerSize(1.3);
  graph_stop_stoppingEfficiency->SetMarkerColor(4);
  graph_stop_stoppingEfficiency->SetLineColor(4);

  //stopping efficiency, gluinos
  //Float_t gluino_stoppingEfficiency[n_detectorRegions] = {0.015,0.071,0.008,0.271,0.060,0.355,0.116,0.104}; //out of those stopped
  Float_t gluino_stoppingEfficiency[n_detectorRegions] = {0.015,0.086,0.094,0.365,0.425,0.780,0.896,1.0}; //cumulative out of those stopped
  //Float_t gluino_stoppingEfficiency[n_detectorRegions] = {0.004,0.019,0.002,0.072,0.016,0.094,0.031,0.028}; //out of total generated
  //Float_t gluino_stoppingEfficiency[n_detectorRegions] = {0.004,0.023,0.025,0.097,0.113,0.207,0.238,0.265}; //cumulative out of total generated

  TGraph* graph_gluino_stoppingEfficiency = new TGraph(n_detectorRegions, detectorRegions, gluino_stoppingEfficiency);
  //gr_style(graph_gluino_stoppingEfficiency,3,2,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  graph_gluino_stoppingEfficiency->SetTitle(";;Fraction of Stopped Events");
  graph_gluino_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_gluino_stoppingEfficiency->SetMarkerStyle(21);
  graph_gluino_stoppingEfficiency->SetMarkerSize(1.3);
  graph_gluino_stoppingEfficiency->SetMarkerColor(2);
  graph_gluino_stoppingEfficiency->SetLineColor(2);

  //stopping efficiency, mchamps
  //Float_t mchamp_stoppingEfficiency[n_detectorRegions] = {0.036,0.106,0.001,0.268,0.064,0.309,0.118,0.089}; //out of those stopped
  Float_t mchamp_stoppingEfficiency[n_detectorRegions] = {0.036,0.142,0.143,0.411,0.475,0.784,0.902,1.0}; //cumulative out of those stopped
  //Float_t mchamp_stoppingEfficiency[n_detectorRegions] = {0.015,0.044,0.004,0.111,0.027,0.128,0.049,0.037}; //out of total generated
  //Float_t mchamp_stoppingEfficiency[n_detectorRegions] = {0.015,0.059,0.063,0.174,0.201,0.329,0.378,0.415}; //cumulative out of total generated

  TGraph* graph_mchamp_stoppingEfficiency = new TGraph(n_detectorRegions, detectorRegions, mchamp_stoppingEfficiency);
  //gr_style(graph_mchamp_stoppingEfficiency,3,4,1,1001,50,-1111,-1111,510,510,22,4,1.3,1);
  graph_mchamp_stoppingEfficiency->SetTitle(";;Fraction of Stopped Events");
  graph_mchamp_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_mchamp_stoppingEfficiency->SetMarkerStyle(20);
  graph_mchamp_stoppingEfficiency->SetMarkerSize(1.3);
  graph_mchamp_stoppingEfficiency->SetMarkerColor(1);
  graph_mchamp_stoppingEfficiency->SetLineColor(1);


  //stopping efficiency, gmstaus
  //Float_t gmstau_stoppingEfficiency[n_detectorRegions] = {0.025,0.084,0.008,0.250,0.044,0.387,0.098,0.103}; //out of those stopped
  Float_t gmstau_stoppingEfficiency[n_detectorRegions] = {0.025,0.109,0.117,0.357,0.401,0.788,0.886,1.0}; //cumulative out of those stopped
  //Float_t gmstau_stoppingEfficiency[n_detectorRegions] = {0.002,0.008,0.001,0.023,0.004,0.036,0.009,0.001}; //out of total generated
  //Float_t gmstau_stoppingEfficiency[n_detectorRegions] = {0.002,0.010,0.011,0.034,0.038,0.074,0.083,0.084}; //cumulative out of total generated

  TGraph* graph_gmstau_stoppingEfficiency = new TGraph(n_detectorRegions, detectorRegions, gmstau_stoppingEfficiency);
  //gr_style(graph_gmstau_stoppingEfficiency,3,6,1,1001,50,-1111,-1111,510,510,23,6,1.3,1);
  graph_gmstau_stoppingEfficiency->SetTitle(";;Fraction of Stopped Events");
  graph_gmstau_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_gmstau_stoppingEfficiency->SetMarkerStyle(23);
  graph_gmstau_stoppingEfficiency->SetMarkerSize(1.3);
  graph_gmstau_stoppingEfficiency->SetMarkerColor(6);
  graph_gmstau_stoppingEfficiency->SetLineColor(6);

  //stopping efficiency, ppstaus
  //Float_t ppstau_stoppingEfficiency[n_detectorRegions] = {0.007,0.039,0.001,0.222,0.012,0.525,0.060,0.134}; //out of those stopped
  Float_t ppstau_stoppingEfficiency[n_detectorRegions] = {0.007,0.046,0.047,0.269,0.281,0.806,0.866,1.0}; //cumulative out of those stopped
  //Float_t ppstau_stoppingEfficiency[n_detectorRegions] = {0.000,0.001,0.000,0.007,0.000,0.016,0.002,0.004}; //out of total generated
  //Float_t ppstau_stoppingEfficiency[n_detectorRegions] = {0.000,0.001,0.001,0.008,0.008,0.024,0.026,0.030}; //cumulative out of total generated

  TGraph* graph_ppstau_stoppingEfficiency = new TGraph(n_detectorRegions, detectorRegions, ppstau_stoppingEfficiency);
  //gr_style(graph_ppstau_stoppingEfficiency,3,8,1,1001,50,-1111,-1111,510,510,24,8,1.3,1);
  graph_ppstau_stoppingEfficiency->SetTitle(";;Fraction of Stopped Events");
  graph_ppstau_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_ppstau_stoppingEfficiency->SetMarkerStyle(24);
  graph_ppstau_stoppingEfficiency->SetMarkerSize(1.3);
  graph_ppstau_stoppingEfficiency->SetMarkerColor(8);
  graph_ppstau_stoppingEfficiency->SetLineColor(8);



  Leg1 = new TLegend(0.17,0.60,0.42,0.80);
  Leg1->AddEntry(graph_mchamp_stoppingEfficiency,"500 GeV mchamps","lp");
  Leg1->AddEntry(graph_gluino_stoppingEfficiency,"500 GeV gluinos","lp");
  Leg1->AddEntry(graph_stop_stoppingEfficiency,"500 GeV stops","lp");
  Leg1->AddEntry(graph_gmstau_stoppingEfficiency,"494 GeV staus including cascade decays","lp");
  Leg1->AddEntry(graph_ppstau_stoppingEfficiency,"494 GeV directly pair-produced staus","lp");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary Simulation","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  c1->cd();
  h1->Draw();
  graph_stop_stoppingEfficiency->Draw("LPsame");
  graph_gluino_stoppingEfficiency->Draw("LPsame");
  graph_mchamp_stoppingEfficiency->Draw("LPsame");
  graph_gmstau_stoppingEfficiency->Draw("LPsame");
  graph_ppstau_stoppingEfficiency->Draw("LPsame");
  //text1->Draw();
  Leg1->Draw();
  CMS_lumi( c1, iPeriod, iPos );
  //if(save_plots) canvas->SaveAs("../plots/StoppedHSCPMuon/RecoData/signalMC/efficiencies/stoppingEfficiency.eps");

}
