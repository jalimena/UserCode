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
  //lumi_8TeV = "8, 13 TeV";
  TString lumi_8TeV = "13 TeV";
  //lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
  //int iPos=0;
  int iPos=11; 
  //int iPos=22;
  //bool save_plots = false;
  bool save_plots = true;

  //TCanvas* canvas = new TCanvas("c1","c1",10,10,700,550);
  TCanvas* canvas = new TCanvas("c1","HLT rate vs num colliding bunches",10,10,575,500);
  //canvas_style(canvas);
  //canvas->SetRightMargin(0.15);

  TH2* h1=new TH2F("h1","",100,0,3000,30,0,30);
  //TH2* h1=new TH2F("h1","",30,0,1500,25,0,25);
  //TH2* h1=new TH2F("h1","",100,0,1,20,0,20);
  //TH2* h1=new TH2F("h1","",30,0,1500,100,0,1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Number of Colliding Bunches;Rate of L2Mu40 NoBPTX Path [Hz]");
  h1->GetYaxis()->SetTitleOffset(1);
  h1->GetXaxis()->SetNdivisions(505);
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  const Int_t n_data2022_25ns = 7;
  Float_t bunches_data2022_25ns[n_data2022_25ns] = {590,   974, 1214, 1538, 1922, 2160, 2400}; //number of colliding bunches
  Float_t rate_data2022_25ns[n_data2022_25ns]    = {22,   19,   17,   14,   11,   9.5,  7.5}; //2022 25 ns, rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz)
  Float_t bunches_data2022_25ns_error[n_data2022_25ns] = {0,0,0, 0,0,0, 0};
  Float_t rate_data2022_25ns_error[n_data2022_25ns] = {2,1.5,1.5, 1.5, 1, 1, 1}; //determined from width of rate plot in WBM, L2Mu40

  TGraphErrors* graph_data2022_25ns = new TGraphErrors(n_data2022_25ns, bunches_data2022_25ns, rate_data2022_25ns, bunches_data2022_25ns_error, rate_data2022_25ns_error);
  //gr_style(graph_data2022_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  graph_data2022_25ns->SetMarkerStyle(23);
  graph_data2022_25ns->SetMarkerColor(4);
  graph_data2022_25ns->SetMarkerSize(1.6);

  TF1* fit1 = new TF1("fit1","[0]*x+[1]",590,2400);
  fit1->SetLineColor(2);
  graph_data2022_25ns->Fit("fit1","R");

  TF1* fit1ext = new TF1("fit1ext","[0]*x+[1]",2400,3000);
  fit1ext->SetParameters(-0.008,26.63);
  fit1ext->SetLineColor(2);
  fit1ext->SetLineStyle(2);
  graph_data2022_25ns->Fit("fit1ext","R+");

  const Int_t n_data2018_25ns = 8;
  Float_t bunches_data2018_25ns[n_data2018_25ns] = {973, 1213, 1549, 1900, 2161, 2305, 2448, 2544}; //number of colliding bunches
  Float_t rate_data2018_25ns[n_data2018_25ns]    = {14, 12.4,  11, 9.1,  7.1,  6.1,  5.4,  4.8}; //2018 25 ns, rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz)
  Float_t bunches_data2018_25ns_error[n_data2018_25ns] = {0,0,0, 0,0,0, 0,0};
  Float_t rate_data2018_25ns_error[n_data2018_25ns] = {1,1,1, 1,1,1, 1,0.6}; //determined from width of rate plot in WBM, L2Mu40

  TGraphErrors* graph_data2018_25ns = new TGraphErrors(n_data2018_25ns, bunches_data2018_25ns, rate_data2018_25ns, bunches_data2018_25ns_error, rate_data2018_25ns_error);
  //gr_style(graph_data2018_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  graph_data2018_25ns->SetMarkerStyle(22);
  graph_data2018_25ns->SetMarkerColor(8);
  graph_data2018_25ns->SetMarkerSize(1.6);



  const Int_t n_data2017_25ns = 10;
  Float_t bunches_data2017_25ns[n_data2017_25ns] = {589,   973, 1213, 1549, 1729, 2017, 2161, 2305, 2448, 2544}; //number of colliding bunches
  Float_t rate_data2017_25ns[n_data2017_25ns]    = {16.0, 13.4, 12.5, 10.4, 9.5,  7.9,  6.9,   6.1, 5.4,  4.95}; //2017 25 ns, /cdaq/physics/Run2017/2e34/v1.0.0/HLT/V6 rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz), use 3.8T runs only
  Float_t bunches_data2017_25ns_error[n_data2017_25ns] = {0,0,0, 0,0,0, 0,0,0, 0};
  Float_t rate_data2017_25ns_error[n_data2017_25ns] = {1,1,1, 1,1,1, 1,0.6,0.6, 0.6}; //determined from width of rate plot in WBM, L2Mu40

  TGraphErrors* graph_data2017_25ns = new TGraphErrors(n_data2017_25ns, bunches_data2017_25ns, rate_data2017_25ns, bunches_data2017_25ns_error, rate_data2017_25ns_error);
  //gr_style(graph_data2017_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  graph_data2017_25ns->SetMarkerStyle(21);
  graph_data2017_25ns->SetMarkerColor(2);
  graph_data2017_25ns->SetMarkerSize(1.6);


  const Int_t n_data2016_25ns = 13;
  Float_t bunches_data2016_25ns[n_data2016_25ns] = {49,   74,  301, 589, 877, 1165, 1453, 1740, 1812, 2028, 2064, 2161, 2208}; //number of colliding bunches
  //Float_t rate_data2016_25ns[n_data2016_25ns]    = {21.5, 21, 19.5,  18, 17,    15,   13, 11.2, 10.8,  9.3,  8.9,  8.3,  8.0}; //2016 25 ns, 10e33 V1.0 rate of HLT_L2Mu35_NoVertex_3Sta_NoBPTX3BX (Hz), use 3.8T runs only
  Float_t rate_data2016_25ns[n_data2016_25ns]    = {18.8, 18.4, 17,  16, 14.8, 13.2, 11.2,  10,  9.5,  8.3,  7.8,  7.0,  6.8}; //2016 25 ns, 10e33 V1.0 rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz), use 3.8T runs only
  Float_t bunches_data2016_25ns_error[n_data2016_25ns] = {0,0,0, 0,0,0, 0,0,0, 0,0,0, 0};
  //Float_t rate_data2016_25ns_error[n_data2016_25ns] = {2,2,2, 1.5,1.5,1.5, 1.5,1.5,1.5, 1,1,1, 1}; //determined from width of rate plot in WBM, L2Mu35
  Float_t rate_data2016_25ns_error[n_data2016_25ns] = {2,2,2, 1.5,1.5,1.5, 1.5,1.5,1.5, 1,1,1, 1}; //determined from width of rate plot in WBM, L2Mu40

  TGraphErrors* graph_data2016_25ns = new TGraphErrors(n_data2016_25ns, bunches_data2016_25ns, rate_data2016_25ns, bunches_data2016_25ns_error, rate_data2016_25ns_error);
  //gr_style(graph_data2016_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_data2016_25ns->SetMarkerStyle(23);
  graph_data2016_25ns->SetMarkerStyle(20);
  //graph_data2016_25ns->SetMarkerColor(6);
  graph_data2016_25ns->SetMarkerColor(1);
  graph_data2016_25ns->SetMarkerSize(1.6);



  const Int_t n_data2015_25ns = 12;
  Float_t bunches_data2015_25ns[n_data2015_25ns] = {1,26,303,446,589,1021,1165,1289,1453,1596,1813,2232}; //number of colliding bunches
  Float_t rate_data2015_25ns[n_data2015_25ns] = {24.5,24,22.5,21.5,20,17.5,16,15,14,13,11.5,8}; //2015 25 ns, 1.4e33 V3.3 rate of HLT_L2Mu35_NoVertex_3Sta_NoBPTX3BX_NoHalo (Hz), use 3.8T runs only
  Float_t bunches_data2015_25ns_error[n_data2015_25ns] = {0,0,0,0,0,00,0,0,0,0,0};
  Float_t rate_data2015_25ns_error[n_data2015_25ns] = {2,2,2,2,2,1.5,1.5,1.5,1.5,1.5,1,1}; //determined from width of rate plot in WBM

  TGraphErrors* graph_data2015_25ns = new TGraphErrors(n_data2015_25ns, bunches_data2015_25ns, rate_data2015_25ns, bunches_data2015_25ns_error, rate_data2015_25ns_error);
  //gr_style(graph_data2015_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  graph_data2015_25ns->SetMarkerStyle(22);
  graph_data2015_25ns->SetMarkerColor(4);
  graph_data2015_25ns->SetMarkerSize(1.6);
  graph_data2015_25ns->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  graph_data2015_25ns->GetYaxis()->SetRangeUser(0,20);



  const Int_t n_data2015_50ns = 3;
  Float_t bunches_data2015_50ns[n_data2015_50ns] = {110,254,414}; //number of colliding bunches
  Float_t rate_data2015_50ns[n_data2015_50ns] = {23,20.5,18}; //2015 50 ns, 5e33 V1.0 rate of HLT_L2Mu35_NoVertex_3Sta_NoBPTX3BX_NoHalo (Hz), use 3.8T runs only
  Float_t bunches_data2015_50ns_error[n_data2015_50ns] = {0,0,0};
  Float_t rate_data2015_50ns_error[n_data2015_50ns] = {2,1,1}; //determined from width of rate plot in WBM

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
  Float_t rate_data[n_data] = {3.7,9,13.5,17}; //7e33 V3 rate of HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo (Hz)
  Float_t bunches_data_error[n_data] = {0,0,0,0};
  Float_t rate_data_error[n_data] = {0.6,1,1.2,2};

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


  const Int_t n_data_noChaCut = 1;
  Float_t bunches_data_noChaCut[n_data_noChaCut] = {1377}; //number of colliding bunches
  Float_t rate_data_noChaCut[n_data_noChaCut] = {7.4}; //7e33 V3 rate of HLT_L2Mu20_NoVertex_NoBPTX3BX_NoHalo (Hz)
  Float_t bunches_data_noChaCut_error[n_data] = {0};
  Float_t rate_data_noChaCut_error[n_data] = {1};

  TGraphErrors* graph_data_noChaCut = new TGraphErrors(n_data_noChaCut, bunches_data_noChaCut, rate_data_noChaCut, bunches_data_noChaCut_error, rate_data_noChaCut_error);
  //gr_style(graph_data_noChaCut,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  graph_data_noChaCut->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  graph_data_noChaCut->GetYaxis()->SetRangeUser(0,20);



  const Int_t n_predicted = 1;
  Float_t bunches_predicted[n_predicted] = {1377}; //number of colliding bunches
  Float_t rate_predicted[n_predicted] = {3.6}; //PREDICTED 7e33 V3 rate of HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo (Hz)
  Float_t bunches_predicted_error[n_data] = {0};
  Float_t rate_predicted_error[n_data] = {1};

  TGraphErrors* graph_predicted = new TGraphErrors(n_predicted, bunches_predicted, rate_predicted, bunches_predicted_error, rate_predicted_error);
  //gr_style(graph_predicted,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.5,1);
  graph_predicted->SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]");
  graph_predicted->GetYaxis()->SetRangeUser(0,20);







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

  Leg1 = new TLegend(0.70,0.70,0.90,0.90);
  //Leg1 = new TLegend(0.50,0.70,0.80,0.85);
  //Leg1 = new TLegend(0.18,0.75,0.43,0.85);
  //Leg1->AddEntry(graph_data_noChaCut,"Average Before TS","p");
  //Leg1->AddEntry(graph_data,"After TS","p");
  //Leg1->AddEntry(graph_predicted,"Predicted After TS","p");
  //Leg1->AddEntry(graph_data,"HLT Rate","p");
  //Leg1->AddEntry(graph_instLumi,"Instantaneous Luminosity","p");
  //Leg1->AddEntry(graph_data,"2012 Trigger, 50 ns","p");
  //Leg1->AddEntry(graph_data2015_50ns,"2015 Trigger, 50 ns","p");
  //Leg1->AddEntry(graph_data2015_25ns,"2015 Trigger, 25 ns","p");
  //Leg1->AddEntry(graph_data2016_25ns,"2016 Trigger, 25 ns","p");
  Leg1->AddEntry(graph_data2016_25ns,"2016","p");
  Leg1->AddEntry(graph_data2017_25ns,"2017","p");
  Leg1->AddEntry(graph_data2018_25ns,"2018","p");
  Leg1->AddEntry(graph_data2022_25ns,"2022","p");
  Leg1->SetBorderSize(0);
  //Leg1->SetTextSize(0.03);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);




  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.92,.37,.96,"CMS Preliminary    #sqrt{s}=8 TeV, 13 TeV","NDC");

  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  canvas->cd();
  h1->Draw();
  //graph_data->Draw("Psame");
  //graph_data2015_50ns->Draw("Psame");
  //graph_data2015_25ns->Draw("Psame");
  graph_data2016_25ns->Draw("Psame");
  graph_data2017_25ns->Draw("Psame");
  graph_data2018_25ns->Draw("Psame");
  graph_data2022_25ns->Draw("Psame");
  //graph_instLumi->Draw("Psame");
  //graph_data_noChaCut->Draw("Psame");
  //graph_predicted->Draw("Psame");
  //text1->Draw();
  //r_axis->Draw();
  Leg1->Draw();
  //CMS_lumi( canvas, iPeriod, iPos );
  //if(save_plots) canvas->SaveAs("../../plots/nbunches_rate.eps");
  if(save_plots) canvas->SaveAs("L2Mu40RateVsNCollidingBunches.pdf");



  //L1 rate vs n Colliding bunches
  TCanvas* c2 = new TCanvas("c2","L1 rate vs num colliding bunches",10,10,575,500);

  TH2* h2=new TH2F("h2","",100,0,3000,50,0,1);
  h2->SetStats(kFALSE);
  h2->SetTitle(";Number of Colliding Bunches;L1 Rate [kHz]");
  h2->GetYaxis()->SetTitleOffset(1);
  h2->GetXaxis()->SetNdivisions(505);

  const Int_t n_data2016_25ns_L1 = 13;
  Float_t bunches_data2016_25ns_L1[n_data2016_25ns_L1] = {   49,    74,   301,   589,   877,  1165,  1453,  1740,  1812,  2028,  2064,  2161,  2208}; //number of colliding bunches
  Float_t rate_data2016_25ns_L1[n_data2016_25ns_L1]    = {0.193, 0.210, 0.280, 0.250, 0.250, 0.300, 0.400, 0.550, 0.450, 0.500, 0.500, 0.460, 0.400}; //2016 25 ns, collisions2016_TSC/v42, l1_hlt_collisions2016/v88, L1Menu_TSGv5, rate of L1_SingleMuOpen_NotBptxOR_3BX (kHz), use 3.8T runs only
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
  //CMS_lumi( c2, iPeriod, iPos );
  if(save_plots) c2->SaveAs("delayedMuons_L1RateVsNCollidingBunches.pdf");

}
