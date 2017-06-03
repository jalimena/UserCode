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
  //bool save_plots = false;
  bool save_plots = true;

  TCanvas* c1 = new TCanvas("c1","c1",10,10,700,550);
  //canvas_style(c1);

  TH2* h1=new TH2F("h1","",28,0,2800,100,0,1.0);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Mass [GeV];Trigger Efficiency");
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  /*
  //trigger efficiency2015, stops
  const Int_t n_stop_massPoints = 10;
  Float_t stop_massPoints[n_stop_massPoints];
  Float_t stop_triggerEfficiency2015[n_stop_massPoints] = {};
  Float_t stop_mass_error[n_stop_massPoints];
  Float_t stop_triggerEfficiency2015_error[n_stop_massPoints];
  for(int i=0; i<n_stop_massPoints; i++){
    stop_massPoints[i] = (i+1.)*100;
    stop_mass_error[i] = 0.;
    stop_triggerEfficiency2015_error[i] = 0.;
  }

  TGraphErrors* graph_stop_triggerEfficiency2015 = new TGraphErrors(n_stop_massPoints, stop_massPoints, stop_triggerEfficiency2015, stop_mass_error, stop_triggerEfficiency2015_error);
  //gr_style(graph_stop_triggerEfficiency2015,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  //gr_style(graph_stop_triggerEfficiency2015,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.3,1);
  graph_stop_triggerEfficiency2015->SetMarkerStyle(22);
  graph_stop_triggerEfficiency2015->SetMarkerColor(4);
  graph_stop_triggerEfficiency2015->SetMarkerSize(1.3);
  graph_stop_triggerEfficiency2015->SetTitle(";Mass [GeV];Trigger Fraction");
  graph_stop_triggerEfficiency2015->GetYaxis()->SetRangeUser(0,1.);
  */

  //trigger efficiency2015, gluinos
  const Int_t n_gluino_massPoints = 14;
  Float_t gluino_massPoints[n_gluino_massPoints] = {100, 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2000, 2200, 2400, 2600};
  Float_t gluino_triggerEfficiency2015[n_gluino_massPoints] = {
    0.0223,
    0.135,
    0.253,
    0.283,
    0.285,
    0.304,
    0.298,
    0.296,
    0.292,
    0.303,
    0.301,
    0.298,
    0.301,
    0.302
  };
  Float_t gluino_triggerEfficiency2016[n_gluino_massPoints] = {
    0.0178,
    0.104,
    0.179,
    0.194,
    0.190,
    0.205,
    0.197,
    0.199,
    0.198,
    0.199,
    0.205,
    0.201,
    0.206,
    0.202
  };
  Float_t gluino_mass_error[n_gluino_massPoints];
  Float_t gluino_triggerEfficiency2015_error[n_gluino_massPoints];
  Float_t gluino_triggerEfficiency2016_error[n_gluino_massPoints];
  for(int i=0; i<n_gluino_massPoints; i++){
    gluino_mass_error[i] = 0.;
    gluino_triggerEfficiency2015_error[i] = 0.;
    gluino_triggerEfficiency2016_error[i] = 0.;
  }

  TGraphErrors* graph_gluino_triggerEfficiency2015 = new TGraphErrors(n_gluino_massPoints, gluino_massPoints, gluino_triggerEfficiency2015, gluino_mass_error, gluino_triggerEfficiency2015_error);
  TGraphErrors* graph_gluino_triggerEfficiency2016 = new TGraphErrors(n_gluino_massPoints, gluino_massPoints, gluino_triggerEfficiency2016, gluino_mass_error, gluino_triggerEfficiency2016_error);
  //gr_style(graph_gluino_triggerEfficiency2015,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  graph_gluino_triggerEfficiency2015->SetMarkerStyle(21);
  graph_gluino_triggerEfficiency2015->SetMarkerColor(2);
  graph_gluino_triggerEfficiency2015->SetMarkerSize(1.3);
  graph_gluino_triggerEfficiency2015->SetTitle(";Mass [GeV];Trigger Fraction");
  graph_gluino_triggerEfficiency2015->GetYaxis()->SetRangeUser(0,1.);

  graph_gluino_triggerEfficiency2016->SetMarkerStyle(21);
  graph_gluino_triggerEfficiency2016->SetMarkerColor(2);
  graph_gluino_triggerEfficiency2016->SetMarkerSize(1.3);
  graph_gluino_triggerEfficiency2016->SetTitle(";Mass [GeV];Trigger Fraction");
  graph_gluino_triggerEfficiency2016->GetYaxis()->SetRangeUser(0,1.);

  //trigger efficiency2015, mchamps
  const Int_t n_mchamp_massPoints = 10;
  Float_t mchamp_massPoints[n_mchamp_massPoints] = {100, 200, 400, 600, 800, 1000, 1400, 1800, 2200, 2600};
  Float_t mchamp_triggerEfficiency2015[n_mchamp_massPoints] = {
    0.315,
    0.389,
    0.404,
    0.384,
    0.387,
    0.376,
    0.371,
    0.372,
    0.371,
    0.369
  };
  Float_t mchamp_triggerEfficiency2016[n_mchamp_massPoints] = {
    0.293,
    0.364,
    0.365,
    0.354,
    0.357,
    0.339,
    0.339,
    0.332,
    0.332,
    0.334
  };
  Float_t mchamp_mass_error[n_mchamp_massPoints];
  Float_t mchamp_triggerEfficiency2015_error[n_mchamp_massPoints];
  Float_t mchamp_triggerEfficiency2016_error[n_mchamp_massPoints];
  for(int i=0; i<n_mchamp_massPoints; i++){
    mchamp_mass_error[i] = 0.;
    mchamp_triggerEfficiency2015_error[i] = 0.;
    mchamp_triggerEfficiency2016_error[i] = 0.;
  }

  TGraphErrors* graph_mchamp_triggerEfficiency2015 = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_triggerEfficiency2015, mchamp_mass_error, mchamp_triggerEfficiency2015_error);
  TGraphErrors* graph_mchamp_triggerEfficiency2016 = new TGraphErrors(n_mchamp_massPoints, mchamp_massPoints, mchamp_triggerEfficiency2016, mchamp_mass_error, mchamp_triggerEfficiency2015_error);
  //gr_style(graph_mchamp_triggerEfficiency2015,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.3,1);
  //gr_style(graph_mchamp_triggerEfficiency2015,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  graph_mchamp_triggerEfficiency2015->SetMarkerStyle(20);
  graph_mchamp_triggerEfficiency2015->SetMarkerColor(1);
  graph_mchamp_triggerEfficiency2015->SetMarkerSize(1.3);
  graph_mchamp_triggerEfficiency2015->SetTitle(";Mass [GeV];Trigger Fraction");
  graph_mchamp_triggerEfficiency2015->GetYaxis()->SetRangeUser(0,1.);

  graph_mchamp_triggerEfficiency2016->SetMarkerStyle(20);
  graph_mchamp_triggerEfficiency2016->SetMarkerColor(1);
  graph_mchamp_triggerEfficiency2016->SetMarkerSize(1.3);
  graph_mchamp_triggerEfficiency2016->SetTitle(";Mass [GeV];Trigger Fraction");
  graph_mchamp_triggerEfficiency2016->GetYaxis()->SetRangeUser(0,1.);




  Leg1 = new TLegend(0.18,0.60,0.50,0.80);
  Leg1->AddEntry(graph_mchamp_triggerEfficiency2015,"mchamps","p");
  Leg1->AddEntry(graph_gluino_triggerEfficiency2015,"gluinos","p");
  //Leg1->AddEntry(graph_stop_triggerEfficiency2015,"stops","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary Simulation","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  c1->cd();
  h1->Draw();
  //graph_stop_triggerEfficiency2015->Draw("Psame");
  //graph_gluino_triggerEfficiency2015->Draw("Psame");
  //graph_mchamp_triggerEfficiency2015->Draw("Psame");

  graph_gluino_triggerEfficiency2016->Draw("Psame");
  graph_mchamp_triggerEfficiency2016->Draw("Psame");
  //text1->Draw();
  Leg1->Draw();
  CMS_lumi( c1, iPeriod, iPos );
  //if(save_plots) c1->SaveAs("TriggerEfficiency2015.pdf");
  if(save_plots) c1->SaveAs("TriggerEfficiency2016.pdf");

}
