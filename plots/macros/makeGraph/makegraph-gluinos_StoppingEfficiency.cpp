{
  //plots signal MC efficiencies, saves eps files

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

  bool save_plots = false;
  //bool save_plots = true;

  TCanvas* c1 = new TCanvas("c1","c1",10,10,700,550);
  canvas_style(c1);

  TH2* h1=new TH2F("h1","",16,0,1600,70,0,0.7);
  //TH2* h1=new TH2F("h1","",11,0,1100,10,0,1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Mass [GeV];Stopping Efficiency");
  h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);


  //stopping efficiency, mchamps
  const Int_t n_mchamp_massPoints = 13;
  Float_t mchamp_massPoints[n_mchamp_massPoints];
  Float_t mchamp_negStoppingEfficiency[n_mchamp_massPoints] = {0.071,0.068,0.066,0.067,0.068,0.070,0.073,0.076,0.079,0.084,0.087,0.092,0.097};
  Float_t mchamp_posStoppingEfficiency[n_mchamp_massPoints] = {0.208,0.200,0.199,0.199,0.204,0.208,0.215,0.226,0.235,0.245,0.258,0.271,0.284};
  Float_t mchamp_atLeastOneStoppingEfficiency[n_mchamp_massPoints] = {0.243,0.234,0.230,0.229,0.234,0.238,0.244,0.253,0.262,0.273,0.283,0.297,0.309};
  Float_t mchamp_maxStoppingEfficiency[n_mchamp_massPoints] = {0.278,0.268,0.265,0.266,0.272,0.279,0.288,0.302,0.313,0.329,0.345,0.363,0.381};
  Float_t mchamp_mass_error[n_mchamp_massPoints];
  Float_t mchamp_stoppingEfficiency_error[n_mchamp_massPoints];
  for(int i=0; i<n_mchamp_massPoints; i++){
    mchamp_massPoints[i] = (i+3.)*100;
    mchamp_mass_error[i] = 0.;
    mchamp_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_mchamp_negStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_negStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  TGraphErrors* graph_mchamp_posStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_posStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  TGraphErrors* graph_mchamp_atLeastOneStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_atLeastOneStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  TGraphErrors* graph_mchamp_maxStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_maxStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  gr_style(graph_mchamp_negStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  gr_style(graph_mchamp_posStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  gr_style(graph_mchamp_atLeastOneStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.3,1);
  gr_style(graph_mchamp_maxStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,23,6,1.3,1);
  //gr_style(graph_mchamp_StoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,24,8,1.3,1);

  graph_mchamp_negStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Efficiency");
  graph_mchamp_posStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Efficiency");
  graph_mchamp_atLeastOneStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Efficiency");
  graph_mchamp_maxStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Efficiency");

  graph_mchamp_negStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_mchamp_posStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_mchamp_atLeastOneStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_mchamp_maxStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);


  Leg1 = new TLegend(0.45,0.75,0.75,0.95);
  Leg1->AddEntry(graph_mchamp_negStoppingEfficiency,"Negatively charged stopped gluinos","p");
  Leg1->AddEntry(graph_mchamp_posStoppingEfficiency,"Positively charged stopped gluinos","p");
  Leg1->AddEntry(graph_mchamp_atLeastOneStoppingEfficiency,"At least 1 stopped gluino","p");
  Leg1->AddEntry(graph_mchamp_maxStoppingEfficiency,"Maximum stopped gluinos","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary Simulation","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  c1->cd();
  h1->Draw();
  graph_mchamp_negStoppingEfficiency->Draw("Psame");
  graph_mchamp_posStoppingEfficiency->Draw("Psame");
  graph_mchamp_atLeastOneStoppingEfficiency->Draw("Psame");
  graph_mchamp_maxStoppingEfficiency->Draw("Psame");
  text1->Draw();
  Leg1->Draw();
  if(save_plots) canvas->SaveAs("../plots/StoppedHSCPMuon/RecoData/signalMC/efficiencies/stoppingEfficiency_gluinos.eps");

}
