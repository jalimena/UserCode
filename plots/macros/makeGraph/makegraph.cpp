{
  //plots trigger rate as function of number of colliding bunches, saves eps files
  // 7e33 V3 menu, June/July 2012

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

  TCanvas* canvas = new TCanvas("c1","c1",10,10,700,550);
  canvas_style(canvas);

  TH2* h1=new TH2F("h1","",30,0,1500,20,0,20);
  //TH2* h1=new TH2F("h1","",100,0,1,20,0,20);
  //TH2* h1=new TH2F("h1","",30,0,1500,100,0,1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Number of Colliding Bunches;Rate [Hz]");
  h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  Int_t n_data = 4;
  Float_t bunches_data[n_data] = {1368,807,471,72}; //number of colliding bunches
  //Float_t bunches_data[n_data] = {.20,.49,.71,.94}; //livetime fraction
  //Float_t rate_data[n_data] = {.20,.49,.71,.94}; //livetime fraction
  Float_t rate_data[n_data] = {3.7,9,13.5,17}; //7e33 V3 rate of HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo (Hz)
  Float_t bunches_data_error[n_data] = {0,0,0,0};
  Float_t rate_data_error[n_data] = {0.6,1,1.2,2};

  TGraphErrors* graph_data = new TGraphErrors(n_data, bunches_data, rate_data, bunches_data_error, rate_data_error);
  gr_style(graph_data,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  graph_data->SetTitle(";Number of Colliding Bunches;Rate [Hz]");
  graph_data->GetYaxis()->SetRangeUser(0,20);

  TF1 *fit1 = new TF1("fit1","pol1",0,1400);
  fit1->SetLineColor(2);
  graph_data->Fit("fit1","R");


  Int_t n_data_noChaCut = 1;
  Float_t bunches_data_noChaCut[n_data_noChaCut] = {1377}; //number of colliding bunches
  Float_t rate_data_noChaCut[n_data_noChaCut] = {7.4}; //7e33 V3 rate of HLT_L2Mu20_NoVertex_NoBPTX3BX_NoHalo (Hz)
  Float_t bunches_data_noChaCut_error[n_data] = {0};
  Float_t rate_data_noChaCut_error[n_data] = {1};

  TGraphErrors* graph_data_noChaCut = new TGraphErrors(n_data_noChaCut, bunches_data_noChaCut, rate_data_noChaCut, bunches_data_noChaCut_error, rate_data_noChaCut_error);
  gr_style(graph_data_noChaCut,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1);
  graph_data_noChaCut->SetTitle(";Number of Colliding Bunches;Rate [Hz]");
  graph_data_noChaCut->GetYaxis()->SetRangeUser(0,20);



  Int_t n_predicted = 1;
  Float_t bunches_predicted[n_predicted] = {1377}; //number of colliding bunches
  Float_t rate_predicted[n_predicted] = {3.6}; //PREDICTED 7e33 V3 rate of HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo (Hz)
  Float_t bunches_predicted_error[n_data] = {0};
  Float_t rate_predicted_error[n_data] = {1};

  TGraphErrors* graph_predicted = new TGraphErrors(n_predicted, bunches_predicted, rate_predicted, bunches_predicted_error, rate_predicted_error);
  gr_style(graph_predicted,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.5,1);
  graph_predicted->SetTitle(";Number of Colliding Bunches;Rate [Hz]");
  graph_predicted->GetYaxis()->SetRangeUser(0,20);



  Leg1 = new TLegend(0.45,0.75,0.75,0.85);
  Leg1->AddEntry(graph_data_noChaCut,"Average Before TS","p");
  Leg1->AddEntry(graph_data,"After TS","p");
  Leg1->AddEntry(graph_predicted,"Predicted After TS","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);




  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.92,.37,.96,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");

  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  canvas->cd();
  h1->Draw();
  graph_data->Draw("Psame");
  //graph_data_noChaCut->Draw("Psame");
  //graph_predicted->Draw("Psame");
  text1->Draw();
  //Leg1->Draw();
  //if(save_plots) canvas->SaveAs("../plots/nbunches_rate.eps");
  if(save_plots) canvas->SaveAs("../plots/StoppedHSCPMuon/nbunches_rate_2012overview.eps");

}
