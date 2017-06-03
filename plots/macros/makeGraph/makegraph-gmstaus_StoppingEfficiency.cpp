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

  //TH2* h1=new TH2F("h1","",15,0,1500,10,0,1);
  TH2* h1=new TH2F("h1","",10,0,500,10,0,0.2);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Mass [GeV];Stopping Efficiency");
  h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);


  //stopping efficiency, mchamps
  const Int_t n_mchamp_massPoints = 9;
  Float_t mchamp_massPoints[n_mchamp_massPoints] = {100,126,156,200,247,308,370,432,494};
  Float_t mchamp_negStoppingEfficiency[n_mchamp_massPoints] = {0.040,0.044,0.051,0.052,0.056,0.054,0.051,0.049,0.046};
  Float_t mchamp_posStoppingEfficiency[n_mchamp_massPoints] = {0.043,0.047,0.054,0.054,0.057,0.054,0.051,0.050,0.048};
  Float_t mchamp_atLeastOneStoppingEfficiency[n_mchamp_massPoints] = {0.079,0.086,0.098,0.100,0.106,0.101,0.096,0.093,0.088};
  Float_t mchamp_maxStoppingEfficiency[n_mchamp_massPoints] = {0.083,0.091,0.105,0.106,0.113,0.107,0.102,0.099,0.094};
  Float_t mchamp_mass_error[n_mchamp_massPoints];
  Float_t mchamp_stoppingEfficiency_error[n_mchamp_massPoints];
  for(int i=0; i<n_mchamp_massPoints; i++){
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


  Leg1 = new TLegend(0.40,0.75,0.75,0.95);
  Leg1->AddEntry(graph_mchamp_negStoppingEfficiency,"Negatively charged stopped gmstaus","p");
  Leg1->AddEntry(graph_mchamp_posStoppingEfficiency,"Positively charged stopped gmstaus","p");
  Leg1->AddEntry(graph_mchamp_atLeastOneStoppingEfficiency,"At least 1 stopped gmstau","p");
  Leg1->AddEntry(graph_mchamp_maxStoppingEfficiency,"Maximum stopped gmstaus","p");
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
  if(save_plots) canvas->SaveAs("../plots/StoppedHSCPMuon/RecoData/signalMC/efficiencies/stoppingEfficiency_gmstaus.eps");

}
