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
  lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
  //int iPos=0;
  int iPos=11;
  //int iPos=22;

  //bool save_plots = false;
  bool save_plots = true;

  TCanvas* c1 = new TCanvas("c1","c1",10,10,575,500);
  //canvas_style(c1);

  TH2* h1=new TH2F("h1","",11,0,1100,11,0,1.1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Mass [GeV];Reconstruction Efficiency");
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  //stopping efficiency, stops
  const Int_t n_stop_massPoints = 9;
  Float_t stop_massPoints[n_stop_massPoints];
  Float_t stop_stoppingEfficiency[n_stop_massPoints] = {0.480,0.525,0.524,0.512,0.517,0.513,0.506,0.511,0.504};
  Float_t stop_mass_error[n_stop_massPoints];
  Float_t stop_stoppingEfficiency_error[n_stop_massPoints];
  for(int i=0; i<n_stop_massPoints; i++){
    stop_massPoints[i] = (i+2.)*100;
    stop_mass_error[i] = 0.;
    stop_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_stop_stoppingEfficiency = new TGraphErrors(n_stop_massPoints, stop_massPoints, stop_stoppingEfficiency, stop_mass_error, stop_stoppingEfficiency_error);
  //gr_style(graph_stop_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  graph_stop_stoppingEfficiency->SetTitle(";Mass [GeV];Reconstruction Efficiency");
  graph_stop_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);


  //stopping efficiency, gluinos
  const Int_t n_gluino_massPoints = 13;
  Float_t gluino_massPoints[n_gluino_massPoints];
  Float_t gluino_stoppingEfficiency[n_gluino_massPoints] = {0.489,0.455,0.461,0.472,0.453,0.476,0.502,0.466,0.462,0.459,0.479,0.489,0.446};
  Float_t gluino_mass_error[n_gluino_massPoints];
  Float_t gluino_stoppingEfficiency_error[n_gluino_massPoints];
  for(int i=0; i<n_gluino_massPoints; i++){
    gluino_massPoints[i] = (i+3.)*100;
    gluino_mass_error[i] = 0.;
    gluino_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_gluino_stoppingEfficiency = new TGraphErrors(n_gluino_massPoints, gluino_massPoints, gluino_stoppingEfficiency, gluino_mass_error, gluino_stoppingEfficiency_error);
  //gr_style(graph_gluino_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  graph_gluino_stoppingEfficiency->SetTitle(";Mass [GeV];Reconstruction Efficiency");
  graph_gluino_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);


  //stopping efficiency, mchamps
  const Int_t n_mchamp_massPoints = 10;
  Float_t mchamp_massPoints[n_mchamp_massPoints];
  Float_t mchamp_stoppingEfficiency[n_mchamp_massPoints] = {0.865,0.869,0.869,0.871,0.875,0.876,0.878,0.878,0.878,0.881};
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
  graph_mchamp_stoppingEfficiency->SetTitle(";Mass [GeV];Reconstruction Efficiency");
  graph_mchamp_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);

  //stopping efficiency, mchampsPlus
  const Int_t n_mchampPlus_massPoints = 10;
  Float_t mchampPlus_massPoints[n_mchampPlus_massPoints];
  Float_t mchampPlus_stoppingEfficiency[n_mchampPlus_massPoints] = {0.865,0.869,0.869,0.871,0.875,0.876,0.878,0.878,0.878,0.881};
  Float_t mchampPlus_mass_error[n_mchampPlus_massPoints];
  Float_t mchampPlus_stoppingEfficiency_error[n_mchampPlus_massPoints];
  for(int i=0; i<n_mchampPlus_massPoints; i++){
    mchampPlus_massPoints[i] = (i+1.)*100;
    mchampPlus_mass_error[i] = 0.;
    mchampPlus_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_mchampPlus_stoppingEfficiency = new TGraphErrors(n_mchampPlus_massPoints, mchampPlus_massPoints, mchampPlus_stoppingEfficiency, mchampPlus_mass_error, mchampPlus_stoppingEfficiency_error);
  //gr_style(graph_mchampPlus_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,23,6,1.3,1);
  graph_mchampPlus_stoppingEfficiency->SetTitle(";Mass [GeV];Reconstruction Efficiency");
  graph_mchampPlus_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);

  //stopping efficiency, gmstaus
  const Int_t n_gmstau_massPoints = 9;
  Float_t gmstau_massPoints[n_gmstau_massPoints];
  Float_t gmstau_stoppingEfficiency[n_gmstau_massPoints] = {0.396,0.399,0.385,0.398,0.404,0.403,0.414,0.413,0.408};
  Float_t gmstau_mass_error[n_gmstau_massPoints];
  Float_t gmstau_stoppingEfficiency_error[n_gmstau_massPoints];
  for(int i=0; i<n_gmstau_massPoints; i++){
    gmstau_massPoints[i] = (i+1.)*100;
    gmstau_mass_error[i] = 0.;
    gmstau_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_gmstau_stoppingEfficiency = new TGraphErrors(n_gmstau_massPoints, gmstau_massPoints, gmstau_stoppingEfficiency, gmstau_mass_error, gmstau_stoppingEfficiency_error);
  //gr_style(graph_gmstau_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,24,8,1.3,1);
  graph_gmstau_stoppingEfficiency->SetTitle(";Mass [GeV];Reconstruction Efficiency");
  graph_gmstau_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);

  //stopping efficiency, ppstaus
  const Int_t n_ppstau_massPoints = 9;
  Float_t ppstau_massPoints[n_ppstau_massPoints];
  Float_t ppstau_stoppingEfficiency[n_ppstau_massPoints] = {0.335,0.297,0.302,0.325,0.314,0.328,0.329,0.339,0.328};
  Float_t ppstau_mass_error[n_ppstau_massPoints];
  Float_t ppstau_stoppingEfficiency_error[n_ppstau_massPoints];
  for(int i=0; i<n_ppstau_massPoints; i++){
    ppstau_massPoints[i] = (i+1.)*100;
    ppstau_mass_error[i] = 0.;
    ppstau_stoppingEfficiency_error[i] = 0.;
  }

  TGraphErrors* graph_ppstau_stoppingEfficiency = new TGraphErrors(n_ppstau_massPoints, ppstau_massPoints, ppstau_stoppingEfficiency, ppstau_mass_error, ppstau_stoppingEfficiency_error);
  //gr_style(graph_ppstau_stoppingEfficiency,1,1,1,1001,50,-1111,-1111,510,510,25,9,1.3,1);
  graph_ppstau_stoppingEfficiency->SetTitle(";Mass [GeV];Reconstruction Efficiency");
  graph_ppstau_stoppingEfficiency->GetYaxis()->SetRangeUser(0,1.);




  Leg1 = new TLegend(0.45,0.7,0.75,0.9);
  Leg1->AddEntry(graph_stop_stoppingEfficiency,"Stops","p");
  Leg1->AddEntry(graph_gluino_stoppingEfficiency,"Gluinos","p");
  Leg1->AddEntry(graph_mchamp_stoppingEfficiency,"H^{--}","p");
  Leg1->AddEntry(graph_mchampPlus_stoppingEfficiency,"H^{++}","p");
  Leg1->AddEntry(graph_gmstau_stoppingEfficiency,"GM staus","p");
  Leg1->AddEntry(graph_ppstau_stoppingEfficiency,"PP staus","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary Simulation","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  c1->cd();
  h1->Draw();
  //graph_stop_stoppingEfficiency->Draw("Psame");
  //graph_gluino_stoppingEfficiency->Draw("Psame");
  graph_mchamp_stoppingEfficiency->Draw("Psame");
  //graph_mchampPlus_stoppingEfficiency->Draw("Psame");
  //graph_gmstau_stoppingEfficiency->Draw("Psame");
  //graph_ppstau_stoppingEfficiency->Draw("Psame");
  //text1->Draw();
  //Leg1->Draw();
  CMS_lumi( c1, iPeriod, iPos );
  if(save_plots) c1->SaveAs("../plots/StoppedHSCPMuon/RecoData/signalMC/efficiencies/recoEfficiency.eps");

}
