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

  bool writeExtraText = true;
  TString extraText  = "Preliminary Simulation"; 
  //lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
  //int iPos=0;
  int iPos=11;
  //int iPos=22;
  //bool save_plots = false;
  bool save_plots = true;

  TCanvas* c1 = new TCanvas("c1","c1",10,10,700,550);
  //canvas_style(c1);

  TH2* h1=new TH2F("h1","",28,0,2800,100,0,1.0);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Mass [GeV];Stopping Efficiency");
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  /*
  //stopping efficiency, stops
  const Int_t n_stop_massPoints = 10;
  Float_t stop_massPoints[n_stop_massPoints];
  Float_t stop_stoppingEfficiency[n_stop_massPoints] = {};
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
  */

  //stopping efficiency, gluinos
  const Int_t n_gluino_massPoints = 14;
  Float_t gluino_massPoints[n_gluino_massPoints] = {100, 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600};
  Float_t gluino_stoppingEfficiency[n_gluino_massPoints] = {
    0.30,
    0.22,
    0.19,
    0.17,
    0.17,
    0.17,
    0.18,
    0.20,
    0.21,
    0.22,
    0.23,
    0.25,
    0.25,
    0.26};
  Float_t gluino_mass_error[n_gluino_massPoints];
  Float_t gluino_stoppingEfficiency_error[n_gluino_massPoints];
  for(int i=0; i<n_gluino_massPoints; i++){
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
  Float_t mchamp_massPoints[n_mchamp_massPoints] = {100, 200, 400, 600, 800, 1000, 1400, 1800, 2200, 2600};
  Float_t mchamp_stoppingEfficiency[n_mchamp_massPoints] = {
    0.33,
    0.29,
    0.28,
    0.25,
    0.30,
    0.32,
    0.35,
    0.41,
    0.48,
    0.54};
  Float_t mchamp_mass_error[n_mchamp_massPoints];
  Float_t mchamp_stoppingEfficiency_error[n_mchamp_massPoints];
  for(int i=0; i<n_mchamp_massPoints; i++){
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




  Leg1 = new TLegend(0.18,0.60,0.50,0.80);
  Leg1->AddEntry(graph_mchamp_stoppingEfficiency,"mchamps","p");
  Leg1->AddEntry(graph_gluino_stoppingEfficiency,"gluinos","p");
  //Leg1->AddEntry(graph_stop_stoppingEfficiency,"stops","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.05);
  Leg1->SetFillColor(0);


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary Simulation","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  c1->cd();
  h1->Draw();
  //graph_stop_stoppingEfficiency->Draw("Psame");
  graph_gluino_stoppingEfficiency->Draw("Psame");
  graph_mchamp_stoppingEfficiency->Draw("Psame");
  //text1->Draw();
  Leg1->Draw();
  CMS_lumi( c1, iPeriod, iPos );
  if(save_plots) c1->SaveAs("StoppingEfficiency.pdf");

}
