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
  TH2* h1=new TH2F("h1","",11,0,1100,10,0,1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Mass [GeV];Stopping Efficiency");
  h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);


  //stopping efficiency, mchamps
  const Int_t n_mchamp_massPoints = 10;
  Float_t mchamp_massPoints[n_mchamp_massPoints];
  Float_t mchamp_maxStoppingEfficiency[n_mchamp_massPoints] = {0.407,0.383,0.387,0.397,0.414,0.433,0.455,0.478,0.502,0.527};
  Float_t mchamp_maxReweightedStoppingEfficiency[n_mchamp_massPoints] = {0.184,0.165,0.151,0.147,0.147,0.153,0.163,0.168,0.180,0.188};
  Float_t mchamp_mass_error[n_mchamp_massPoints];
  Float_t mchamp_stoppingEfficiency_error[n_mchamp_massPoints];
  for(int i=0; i<n_mchamp_massPoints; i++){
    mchamp_massPoints[i] = (i+1.)*100;
    mchamp_mass_error[i] = 0.;
    mchamp_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_mchamp_maxStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_maxStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  TGraphErrors* graph_mchamp_maxReweightedStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_maxReweightedStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  gr_style(graph_mchamp_maxStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  gr_style(graph_mchamp_maxReweightedStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);

  graph_mchamp_maxStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Efficiency");
  graph_mchamp_maxReweightedStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Efficiency");

  graph_mchamp_maxStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_mchamp_maxReweightedStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);


  Leg1 = new TLegend(0.45,0.75,0.75,0.95);
  Leg1->AddEntry(graph_mchamp_maxStoppingEfficiency,"Maximum stopped mchamps","p");
  Leg1->AddEntry(graph_mchamp_maxReweightedStoppingEfficiency,"Maximum stopped mchamps, with H^{#pm#pm} reweighting","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary Simulation","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  c1->cd();
  h1->Draw();
  graph_mchamp_maxStoppingEfficiency->Draw("Psame");
  graph_mchamp_maxReweightedStoppingEfficiency->Draw("Psame");
  text1->Draw();
  Leg1->Draw();
  if(save_plots) canvas->SaveAs("../plots/StoppedHSCPMuon/RecoData/signalMC/efficiencies/stoppingEfficiency_mchamps_withAndWOreweighting.eps");

}
