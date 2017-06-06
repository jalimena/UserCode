{
  //plots trigger rate as function of number of colliding bunches, saves eps files
  // 7e33 V3 menu, June/July 2012

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
  extraText  = "Preliminary";                                                                                                                                                                
  lumi_8TeV = "8, 13 TeV";
  //lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
  //int iPos=0;
  int iPos=11; 
  //int iPos=22;
  //bool save_plots = false;
  bool save_plots = true;

  //TCanvas* canvas = new TCanvas("c1","c1",10,10,700,550);
  TCanvas* canvas = new TCanvas("c1","c1",10,10,575,500);
  //canvas_style(canvas);
  //canvas->SetRightMargin(0.15);

  TH2* h1=new TH2F("h1","",50,0,2500,50,0,6);
  //TH2* h1=new TH2F("h1","",30,0,1500,25,0,25);
  //TH2* h1=new TH2F("h1","",100,0,1,20,0,20);
  //TH2* h1=new TH2F("h1","",30,0,1500,100,0,1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  h1->GetYaxis()->SetTitleOffset(0.8);
  h1->GetXaxis()->SetNdivisions(505);
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  const Int_t n_data2017_25ns = 1;
  Float_t bunches_data2017_25ns[n_data2017_25ns] = {589}; //number of colliding bunches
  Float_t rate_data2017_25ns[n_data2017_25ns]    = {0.9}; //2017 25 ns, /cdaq/physics/Run2017/2e34/v1.0.0/HLT/V6 rate of HLT_UncorrectedJetE60_NoBPTX3BX (Hz), use 3.8T runs only
  Float_t bunches_data2017_25ns_error[n_data2017_25ns] = {0};
  Float_t rate_data2017_25ns_error[n_data2017_25ns] = {0.4}; //determined from width of rate plot in WBM

  TGraphErrors* graph_data2017_25ns = new TGraphErrors(n_data2017_25ns, bunches_data2017_25ns, rate_data2017_25ns, bunches_data2017_25ns_error, rate_data2017_25ns_error);
  //gr_style(graph_data2017_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  graph_data2017_25ns->SetMarkerStyle(21);
  graph_data2017_25ns->SetMarkerColor(2);
  graph_data2017_25ns->SetMarkerSize(1.6);
  graph_data2017_25ns->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  graph_data2017_25ns->GetYaxis()->SetRangeUser(0,20);



  const Int_t n_data2016_25ns = 13;
  Float_t bunches_data2016_25ns[n_data2016_25ns] = { 49,  74, 301, 589, 877, 1165, 1453, 1740, 1812, 2028, 2064, 2161, 2208}; //number of colliding bunches
  Float_t rate_data2016_25ns[n_data2016_25ns]    = {4.5, 4.4, 3.0, 2.0, 1.2,  1.5,  1.3,  1.2,  1.1,  0.9,  1.1,  0.9,  0.9}; //2016 25 ns, 10e33 V1.0 rate of HLT_JetE50_NoBPTX3BX (Hz), use 3.8T runs only
  Float_t bunches_data2016_25ns_error[n_data2016_25ns] = {0,0,0, 0,0,0, 0,0,0, 0,0,0, 0};
  Float_t rate_data2016_25ns_error[n_data2016_25ns] = {1,1,0.75, 0.75,0.4,0.4, 0.4,0.4,0.4, 0.4,0.4,0.4, 0.4}; //determined from width of rate plot in WBM

  TGraphErrors* graph_data2016_25ns = new TGraphErrors(n_data2016_25ns, bunches_data2016_25ns, rate_data2016_25ns, bunches_data2016_25ns_error, rate_data2016_25ns_error);
  //gr_style(graph_data2016_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  graph_data2016_25ns->SetMarkerStyle(20);
  graph_data2016_25ns->SetMarkerColor(1);
  graph_data2016_25ns->SetMarkerSize(1.6);
  graph_data2016_25ns->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  graph_data2016_25ns->GetYaxis()->SetRangeUser(0,20);


  const Int_t n_data2015_25ns_end = 8;
  Float_t bunches_data2015_25ns_end[n_data2015_25ns_end] = {589,881,1165, 1309,1453, 1596,1813,2232}; //number of colliding bunches
  Float_t rate_data2015_25ns_end[n_data2015_25ns_end] = {0.95,1.2,1.2, 1.5,1.4, 1.6,1.7,1.7}; //2015 25 ns, 1.4e33 V3.3 rate of L1_SingleJetC32_NotBptxOR (kHz), use 3.8T runs only
  Float_t bunches_data2015_25ns_end_error[n_data2015_25ns_end] = {0,0,0, 0,0, 0,0,0};
  Float_t rate_data2015_25ns_end_error[n_data2015_25ns_end] = {0.6,0.6,0.6, 0.6,0.6, 0.6,0.6,0.6}; //determined from width of rate plot in WBM

  TGraphErrors* graph_data2015_25ns_end = new TGraphErrors(n_data2015_25ns_end, bunches_data2015_25ns_end, rate_data2015_25ns_end, bunches_data2015_25ns_end_error, rate_data2015_25ns_end_error);
  //gr_style(graph_data2015_25ns_end,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  graph_data2015_25ns_end->SetMarkerStyle(22);
  graph_data2015_25ns_end->SetMarkerColor(4);
  graph_data2015_25ns_end->SetMarkerSize(1.6);
  graph_data2015_25ns_end->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  graph_data2015_25ns_end->GetYaxis()->SetRangeUser(0,20);




  const Int_t n_data2015_50ns = 3;
  Float_t bunches_data2015_50ns[n_data2015_50ns] = {110,254,414}; //number of colliding bunches
  Float_t rate_data2015_50ns[n_data2015_50ns] = {}; //2015 50 ns, 5e33 V1.0 rate of HLT_L2Mu35_NoVertex_3Sta_NoBPTX3BX_NoHalo (Hz), use 3.8T runs only
  Float_t bunches_data2015_50ns_error[n_data2015_50ns] = {0,0,0};
  Float_t rate_data2015_50ns_error[n_data2015_50ns] = {}; //determined from width of rate plot in WBM

  TGraphErrors* graph_data2015_50ns = new TGraphErrors(n_data2015_50ns, bunches_data2015_50ns, rate_data2015_50ns, bunches_data2015_50ns_error, rate_data2015_50ns_error);
  //gr_style(graph_data2015_50ns,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  graph_data2015_50ns->SetMarkerStyle(21);
  graph_data2015_50ns->SetMarkerColor(2);
  graph_data2015_50ns->SetMarkerSize(1.3);
  graph_data2015_50ns->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  graph_data2015_50ns->GetYaxis()->SetRangeUser(0,20);



  const Int_t n_data = 4;
  Float_t bunches_data[n_data] = {1368,807,471,72}; //number of colliding bunches
  //Float_t bunches_data[n_data] = {.20,.49,.71,.94}; //livetime fraction
  //Float_t rate_data[n_data] = {.20,.49,.71,.94}; //livetime fraction
  Float_t rate_data[n_data] = {}; //7e33 V3 rate of HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo (Hz)
  Float_t bunches_data_error[n_data] = {0,0,0,0};
  Float_t rate_data_error[n_data] = {};

  TGraphErrors* graph_data = new TGraphErrors(n_data, bunches_data, rate_data, bunches_data_error, rate_data_error);
  //gr_style(graph_data,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  graph_data->SetMarkerStyle(20);
  graph_data->SetMarkerColor(1);
  graph_data->SetMarkerSize(1.6);
  graph_data->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  graph_data->GetYaxis()->SetRangeUser(0,20);

  //TF1 *fit1 = new TF1("fit1","pol1",0,1400);
  //fit1->SetLineColor(2);
  //graph_data->Fit("fit1","R");







  const Int_t n_instLumi = 7;
  Float_t bunches_instLumi[n_instLumi] = {4,28,72,249,618,1051,1331}; //number of colliding bunches
  Float_t instLumi[n_instLumi] = {8,90,300,1000,2600,4500,6000}; //initial instantaneous luminosity of the fill *10^30 cm^-2 s^-1 (HF)
  Float_t instLumiScaled[n_instLumi]; //instantaneous luminosity scaled to be on same graph
  Float_t bunches_instLumi_error[n_instLumi] = {0,0,0,0,0,0,0};
  Float_t instLumi_error[n_instLumi] = {1,10,50,200,300,500,800};
  Float_t instLumiScaled_error[n_instLumi];

  for(Int_t i=0; i<n_instLumi; i++){
    instLumiScaled[i] = 1.0*instLumi[i]/280;
    instLumiScaled_error[i] = 1.0*instLumi_error[i]/280;
  }

  //TGraphErrors* graph_instLumi = new TGraphErrors(n_instLumi, bunches_instLumi, instLumi, bunches_instLumi_error, instLumi_error);
  TGraphErrors* graph_instLumi = new TGraphErrors(n_instLumi, bunches_instLumi, instLumiScaled, bunches_instLumi_error, instLumiScaled_error);
  //gr_style(graph_instLumi,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  graph_instLumi->SetMarkerStyle(21);
  graph_instLumi->SetMarkerColor(2);
  graph_instLumi->SetMarkerSize(1.6);
  graph_instLumi->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  //graph_instLumi->GetYaxis()->SetRangeUser(0,20);


  TGaxis* r_axis = new TGaxis(1500,0,
			      1500,25,
			      0,7000,7,"+L");
  r_axis->SetTitle("Instantaneous Luminosity [E30 cm^{-2}s^{-1}]");
  r_axis->SetLineColor(2);
  r_axis->SetLabelColor(2);
  r_axis->SetTitleColor(2);
  r_axis->SetTitleOffset(1.5);
  //r_axis->SetLabelOffset(0.01);

  Leg1 = new TLegend(0.50,0.75,0.80,0.90);
  //Leg1 = new TLegend(0.18,0.75,0.43,0.85);
  //Leg1->AddEntry(graph_instLumi,"Instantaneous Luminosity","p");
  //Leg1->AddEntry(graph_data,"2012 Trigger, 50 ns","p");
  //Leg1->AddEntry(graph_data2015_50ns,"2015 Trigger, 50 ns","p");
  //Leg1->AddEntry(graph_data2015_25ns_end,"2015 Trigger, 25 ns","p");
  Leg1->AddEntry(graph_data2016_25ns,"2016 Trigger, 25 ns","p");
  Leg1->AddEntry(graph_data2017_25ns,"2017 Trigger, 25 ns","p");
  Leg1->SetBorderSize(0);
  //Leg1->SetTextSize(0.03);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);



  canvas->cd();
  h1->Draw();
  //graph_data->Draw("Psame");
  //graph_data2015_50ns->Draw("Psame");
  //graph_data2015_25ns_end->Draw("Psame");
  graph_data2016_25ns->Draw("Psame");
  graph_data2017_25ns->Draw("Psame");
  //graph_instLumi->Draw("Psame");
  //r_axis->Draw();
  Leg1->Draw();
  CMS_lumi( canvas, iPeriod, iPos );
  if(save_plots) canvas->SaveAs("../../plots/stoppedParticles_HltRateVsNCollidingBunches_2016_2017.pdf");






  //L1 rate vs n Colliding bunches                                                                                                                                 
  TCanvas* c2 = new TCanvas("c2","L1 rate vs num colliding bunches",10,10,575,500);

  TH2* h2=new TH2F("h2","",50,0,2500,60,0,6);
  h2->SetStats(kFALSE);
  h2->SetTitle(";Number of Colliding Bunches;L1 Rate [kHz]");
  h2->GetYaxis()->SetTitleOffset(0.8);
  h2->GetXaxis()->SetNdivisions(505);

  const Int_t n_data2016_25ns_L1 = 13;
  Float_t bunches_data2016_25ns_L1[n_data2016_25ns_L1] = {   49,    74, 301, 589, 877, 1165, 1453, 1740, 1812, 2028, 2064, 2161, 2208}; //number of colliding bunches
  Float_t rate_data2016_25ns_L1[n_data2016_25ns_L1]    = {0.361, 0.419, 1.0, 1.7, 1.8,  2.5,  3.0,  3.6, 4.0,   1.8,  2.8,  2.6,  2.6}; //2016 25 ns, collisions2016_TSC/v42, l1_hlt_collisions2016/v88, L1Menu_TSGv5, rate of L1_SingleJetC32_NotBptxOR_3BX (kHz), use 3.8T runs only
  Float_t bunches_data2016_25ns_L1_error[n_data2016_25ns_L1] = {0,0,0, 0,0,0, 0,0,0, 0,0,0, 0};
  Float_t rate_data2016_25ns_L1_error[n_data2016_25ns_L1] = {0,0,0, 0,0,0, 0,0,0, 0,0,0, 0}; //determined from width of rate plot in WBM

  TGraphErrors* graph_data2016_25ns_L1 = new TGraphErrors(n_data2016_25ns_L1, bunches_data2016_25ns_L1, rate_data2016_25ns_L1, bunches_data2016_25ns_L1_error, rate_data2016_25ns_L1_error);
  //gr_style(graph_data2016_25ns_L1,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1); 
  graph_data2016_25ns_L1->SetMarkerStyle(23);
  graph_data2016_25ns_L1->SetMarkerColor(6);
  graph_data2016_25ns_L1->SetMarkerSize(1.6);
  graph_data2016_25ns_L1->SetTitle(";Number of Colliding Bunches;L1 Rate [Hz]");
  //graph_data2016_25ns_L1->GetYaxis()->SetRangeUser(0,20);

  Leg2 = new TLegend(0.50,0.75,0.80,0.85);
  Leg2->AddEntry(graph_data2016_25ns_L1,"2016 Trigger, 25 ns","p");
  Leg2->SetBorderSize(0);
  //Leg2->SetTextSize(0.03); 
  Leg2->SetTextSize(0.04);
  Leg2->SetFillColor(0);

  c2->cd();
  h2->Draw();
  graph_data2016_25ns_L1->Draw("Psame");
  //r_axis->Draw();
  Leg2->Draw();
  CMS_lumi( c2, iPeriod, iPos );
  if(save_plots) c2->SaveAs("../../plots/stoppedParticles_L1RateVsNCollidingBunches.pdf");
}
