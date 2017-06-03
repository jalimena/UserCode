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

  writeExtraText = true;
  extraText  = "Preliminary Simulation"; 
  //lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
  //int iPos=0;
  int iPos=11;
  //int iPos=22;
  bool save_plots = false;
  //bool save_plots = true;

  TCanvas* c1 = new TCanvas("c1","c1",10,10,700,550);
  //canvas_style(c1);

  TH2* h1=new TH2F("h1","",16,0,1600,100,0,1.0);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Mass [GeV];Stopping Fraction");
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  //stopping efficiency, stops
  const Int_t n_stop_massPoints = 10;
  Float_t stop_massPoints[n_stop_massPoints];
  //Float_t stop_stoppingEfficiency[n_stop_massPoints] = {0.241,0.208,0.190,0.175,0.165,0.158,0.148,0.144,0.141,0.137}; //old
  //Float_t stop_stoppingEfficiency[n_stop_massPoints] = {0.239,0.208,0.187,0.175,0.165,0.154,0.146,0.143,0.139,0.137}; //at least one
  Float_t stop_stoppingEfficiency[n_stop_massPoints] = {0.273,0.233,0.209,0.194,0.185,0.172,0.162,0.160,0.156,0.154}; //max
  Float_t stop_mass_error[n_stop_massPoints];
  Float_t stop_stoppingEfficiency_error[n_stop_massPoints];
  for(int i=0; i<n_stop_massPoints; i++){
    stop_massPoints[i] = (i+1.)*100;
    stop_mass_error[i] = 0.;
    stop_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_stop_stoppingEfficiency = new TGraphErrors(n_stop_massPoints, stop_massPoints, stop_stoppingEfficiency, stop_mass_error, stop_stoppingEfficiency_error);
  //gr_style(graph_stop_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  //gr_style(graph_stop_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.3,1);
  graph_stop_stoppingEfficiency->SetMarkerStyle(22);
  graph_stop_stoppingEfficiency->SetMarkerColor(4);
  graph_stop_stoppingEfficiency->SetMarkerSize(1.3);
  graph_stop_stoppingEfficiency->SetTitle(";Mass [GeV];Stopping Fraction");
  graph_stop_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);

  //stopping efficiency, gluinos
  const Int_t n_gluino_massPoints = 13;
  Float_t gluino_massPoints[n_gluino_massPoints];
  //Float_t gluino_stoppingEfficiency[n_gluino_massPoints] = {0.243,0.234,0.230,0.229,0.234,0.238,0.244,0.253,0.262,0.273,0.283,0.297,0.309};//at least one
  Float_t gluino_stoppingEfficiency[n_gluino_massPoints] = {0.278,0.268,0.265,0.266,0.272,0.279,0.288,0.302,0.313,0.329,0.345,0.363,0.381};//max
  Float_t gluino_mass_error[n_gluino_massPoints];
  Float_t gluino_stoppingEfficiency_error[n_gluino_massPoints];
  for(int i=0; i<n_gluino_massPoints; i++){
    gluino_massPoints[i] = (i+3.)*100;
    gluino_mass_error[i] = 0.;
    gluino_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_gluino_stoppingEfficiency = new TGraphErrors(n_gluino_massPoints, gluino_massPoints, gluino_stoppingEfficiency, gluino_mass_error, gluino_stoppingEfficiency_error);
  //gr_style(graph_gluino_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  graph_gluino_stoppingEfficiency->SetMarkerStyle(21);
  graph_gluino_stoppingEfficiency->SetMarkerColor(2);
  graph_gluino_stoppingEfficiency->SetMarkerSize(1.3);
  graph_gluino_stoppingEfficiency->SetTitle(";Mass [GeV];Stopping Fraction");
  graph_gluino_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);

  //stopping efficiency, mchamps
  const Int_t n_mchamp_massPoints = 10;
  Float_t mchamp_massPoints[n_mchamp_massPoints];
  //Float_t mchamp_stoppingEfficiency[n_mchamp_massPoints] = {0.188,0.179,0.181,0.185,0.194,0.207,0.215,0.226,0.239,0.253}; //old
  //Float_t mchamp_stoppingEfficiency[n_mchamp_massPoints] = {0.310,0.300,0.307,0.316,0.328,0.341,0.357,0.373,0.388,0.403}; //at least one
  Float_t mchamp_stoppingEfficiency[n_mchamp_massPoints] = {0.407,0.383,0.387,0.397,0.414,0.433,0.455,0.478,0.502,0.527}; //max
  Float_t mchamp_mass_error[n_mchamp_massPoints];
  Float_t mchamp_stoppingEfficiency_error[n_mchamp_massPoints];
  for(int i=0; i<n_mchamp_massPoints; i++){
    mchamp_massPoints[i] = (i+1.)*100;
    mchamp_mass_error[i] = 0.;
    mchamp_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_mchamp_stoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_stoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  //gr_style(graph_mchamp_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.3,1);
  //gr_style(graph_mchamp_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  graph_mchamp_stoppingEfficiency->SetMarkerStyle(20);
  graph_mchamp_stoppingEfficiency->SetMarkerColor(1);
  graph_mchamp_stoppingEfficiency->SetMarkerSize(1.3);
  graph_mchamp_stoppingEfficiency->SetTitle(";Mass [GeV];Stopping Fraction");
  graph_mchamp_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);


  //stopping efficiency, gmstaus
  const Int_t n_gmstau_massPoints = 9;
  Float_t gmstau_massPoints[n_gmstau_massPoints] = {100,126,156,200,247,308,370,432,494};
  //Float_t gmstau_stoppingEfficiency[n_gmstau_massPoints] = {0.041,0.043,0.048,0.050,0.054,0.051,0.049,0.046,0.044};//old
  //Float_t gmstau_stoppingEfficiency[n_gmstau_massPoints] = {0.079,0.086,0.098,0.100,0.106,0.101,0.096,0.093,0.088};//at least one
  Float_t gmstau_stoppingEfficiency[n_gmstau_massPoints] = {0.083,0.091,0.105,0.106,0.113,0.107,0.102,0.099,0.094};//max
  Float_t gmstau_mass_error[n_gmstau_massPoints];
  Float_t gmstau_stoppingEfficiency_error[n_gmstau_massPoints];
  for(int i=0; i<n_gmstau_massPoints; i++){
    gmstau_mass_error[i] = 0.;
    gmstau_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_gmstau_stoppingEfficiency = new TGraphErrors(n_gmstau_massPoints, gmstau_massPoints, gmstau_stoppingEfficiency, gmstau_mass_error, gmstau_stoppingEfficiency_error);
  //gr_style(graph_gmstau_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,23,6,1.3,1);
  graph_gmstau_stoppingEfficiency->SetMarkerStyle(23);
  graph_gmstau_stoppingEfficiency->SetMarkerColor(6);
  graph_gmstau_stoppingEfficiency->SetMarkerSize(1.3);
  graph_gmstau_stoppingEfficiency->SetTitle(";Mass [GeV];Stopping Fraction");
  graph_gmstau_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);

  //stopping efficiency, ppstaus
  const Int_t n_ppstau_massPoints = 9;
  Float_t ppstau_massPoints[n_ppstau_massPoints] = {100,126,156,200,247,308,370,432,494};
  //Float_t ppstau_stoppingEfficiency[n_ppstau_massPoints] = {0.019,0.017,0.016,0.015,0.019,0.014,0.013,0.013,0.014};//old
  //Float_t ppstau_stoppingEfficiency[n_ppstau_massPoints] = {0.043,0.037,0.034,0.030,0.030,0.028,0.027,0.026,0.027};//at least one
  Float_t ppstau_stoppingEfficiency[n_ppstau_massPoints] = {0.050,0.042,0.039,0.034,0.033,0.031,0.031,0.030,0.030};//max
  Float_t ppstau_mass_error[n_ppstau_massPoints];
  Float_t ppstau_stoppingEfficiency_error[n_ppstau_massPoints];
  for(int i=0; i<n_ppstau_massPoints; i++){
    ppstau_mass_error[i] = 0.;
    ppstau_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_ppstau_stoppingEfficiency = new TGraphErrors(n_ppstau_massPoints, ppstau_massPoints, ppstau_stoppingEfficiency, ppstau_mass_error, ppstau_stoppingEfficiency_error);
  //gr_style(graph_ppstau_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,24,8,1.3,1);
  graph_ppstau_stoppingEfficiency->SetMarkerStyle(24);
  graph_ppstau_stoppingEfficiency->SetMarkerColor(8);
  graph_ppstau_stoppingEfficiency->SetMarkerSize(1.3);
  graph_ppstau_stoppingEfficiency->SetTitle(";Mass [GeV];Stopping Fraction");
  graph_ppstau_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);



  Leg1 = new TLegend(0.18,0.60,0.50,0.80);
  Leg1->AddEntry(graph_mchamp_stoppingEfficiency,"mchamps","p");
  Leg1->AddEntry(graph_gluino_stoppingEfficiency,"gluinos","p");
  Leg1->AddEntry(graph_stop_stoppingEfficiency,"stops","p");
  Leg1->AddEntry(graph_gmstau_stoppingEfficiency,"staus including cascade decays","p");
  Leg1->AddEntry(graph_ppstau_stoppingEfficiency,"directly pair-produced staus","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary Simulation","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  c1->cd();
  h1->Draw();
  graph_stop_stoppingEfficiency->Draw("Psame");
  graph_gluino_stoppingEfficiency->Draw("Psame");
  graph_mchamp_stoppingEfficiency->Draw("Psame");
  graph_gmstau_stoppingEfficiency->Draw("Psame");
  graph_ppstau_stoppingEfficiency->Draw("Psame");
  //text1->Draw();
  Leg1->Draw();
  CMS_lumi( c1, iPeriod, iPos );
  if(save_plots) canvas->SaveAs("../plots/StoppedHSCPMuon/RecoData/signalMC/efficiencies/stoppingEfficiency.eps");

}
