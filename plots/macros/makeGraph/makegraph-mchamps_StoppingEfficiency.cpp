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

  TCanvas* c1 = new TCanvas("c1","c1",10,10,575,500);
  //canvas_style(c1);

  //TH2* h1=new TH2F("h1","",15,0,1500,10,0,1);
  TH2* h1=new TH2F("h1","",11,0,1100,10,0,1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Mass [GeV];Stopping Fraction");
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);


  //stopping efficiency, mchamps
  const Int_t n_mchamp_massPoints = 10;
  Float_t mchamp_massPoints[n_mchamp_massPoints];
  Float_t mchamp_negStoppingEfficiency[n_mchamp_massPoints] = {0.192,0.180,0.181,0.185,0.193,0.204,0.213,0.226,0.239,0.252};
  Float_t mchamp_posStoppingEfficiency[n_mchamp_massPoints] = {0.214,0.203,0.206,0.212,0.221,0.229,0.242,0.252,0.263,0.275};
  Float_t mchamp_atLeastOneStoppingEfficiency[n_mchamp_massPoints] = {0.310,0.300,0.307,0.316,0.328,0.341,0.357,0.373,0.388,0.403};
  Float_t mchamp_maxStoppingEfficiency[n_mchamp_massPoints] = {0.407,0.383,0.387,0.397,0.414,0.433,0.455,0.478,0.502,0.527};
  Float_t mchamp_mass_error[n_mchamp_massPoints];
  Float_t mchamp_stoppingEfficiency_error[n_mchamp_massPoints];
  for(int i=0; i<n_mchamp_massPoints; i++){
    mchamp_massPoints[i] = (i+1.)*100;
    mchamp_mass_error[i] = 0.;
    mchamp_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_mchamp_negStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_negStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  TGraphErrors* graph_mchamp_posStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_posStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  TGraphErrors* graph_mchamp_atLeastOneStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_atLeastOneStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  TGraphErrors* graph_mchamp_maxStoppingEfficiency = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_maxStoppingEfficiency, mchamp_mass_error, mchamp_stoppingEfficiency_error);
  /*
  gr_style(graph_mchamp_negStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  gr_style(graph_mchamp_posStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  gr_style(graph_mchamp_atLeastOneStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.3,1);
  gr_style(graph_mchamp_maxStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,23,6,1.3,1);
  */

  /*
  gr_style(graph_mchamp_negStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  //gr_style(graph_mchamp_posStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  gr_style(graph_mchamp_atLeastOneStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  gr_style(graph_mchamp_maxStoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.3,1);
  */

  //gr_style(graph_mchamp_StoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,24,8,1.3,1);


  graph_mchamp_negStoppingEfficiency->SetMarkerStyle(20);
  graph_mchamp_negStoppingEfficiency->SetMarkerColor(1);
  graph_mchamp_negStoppingEfficiency->SetMarkerSize(1.3);

  graph_mchamp_atLeastOneStoppingEfficiency->SetMarkerStyle(21);
  graph_mchamp_atLeastOneStoppingEfficiency->SetMarkerColor(2);
  graph_mchamp_atLeastOneStoppingEfficiency->SetMarkerSize(1.3);

  graph_mchamp_maxStoppingEfficiency->SetMarkerStyle(22);
  graph_mchamp_maxStoppingEfficiency->SetMarkerColor(4);
  graph_mchamp_maxStoppingEfficiency->SetMarkerSize(1.3);

  graph_mchamp_negStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Fraction");
  graph_mchamp_posStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Fraction");
  graph_mchamp_atLeastOneStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Fraction");
  graph_mchamp_maxStoppingEfficiency->SetTitle(";Mass [GeV];Stopping Fraction");

  graph_mchamp_negStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_mchamp_posStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_mchamp_atLeastOneStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);
  graph_mchamp_maxStoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);


  Leg1 = new TLegend(0.18,0.65,0.50,0.80);
  //Leg1->AddEntry(graph_mchamp_negStoppingEfficiency,"Negatively charged stopped mchamps","p");
  //Leg1->AddEntry(graph_mchamp_posStoppingEfficiency,"Positively charged stopped mchamps","p");
  //Leg1->AddEntry(graph_mchamp_atLeastOneStoppingEfficiency,"At least 1 stopped mchamp","p");
  //Leg1->AddEntry(graph_mchamp_maxStoppingEfficiency,"Maximum stopped mchamps","p");

  Leg1->AddEntry(graph_mchamp_negStoppingEfficiency,"Before Stage 1 Extension","p");
  Leg1->AddEntry(graph_mchamp_atLeastOneStoppingEfficiency,"After Stage 1 Extension","p");
  Leg1->AddEntry(graph_mchamp_maxStoppingEfficiency,"After Stage 2 Extension","p");

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
  //graph_mchamp_posStoppingEfficiency->Draw("Psame");
  graph_mchamp_atLeastOneStoppingEfficiency->Draw("Psame");
  graph_mchamp_maxStoppingEfficiency->Draw("Psame");
  //text1->Draw();
  Leg1->Draw();
  CMS_lumi( c1, iPeriod, iPos );
  if(save_plots) canvas->SaveAs("../plots/StoppedHSCPMuon/RecoData/signalMC/efficiencies/stoppingEfficiency_mchamps.eps");

}
