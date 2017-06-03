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
  lumi_8TeV = "13 TeV";
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

  TH2* h1=new TH2F("h1","",20,0,20,100,0,100);
  //TH2* h1=new TH2F("h1","",30,0,1500,25,0,25);
  //TH2* h1=new TH2F("h1","",100,0,1,20,0,20);
  //TH2* h1=new TH2F("h1","",30,0,1500,100,0,1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Cut;Cumulative Efficiency");
  h1->GetYaxis()->SetTitleOffset(0.8);
  h1->GetXaxis()->SetNdivisions(505);
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  Int_t n_cuts = 18;

  Float_t cut_mchamp100[n_cuts] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
  Float_t eff_mchamp100[n_cuts]    = {100.0,29.3,29.3,29.3,29.3,26.5,25.6,20.1,18.6,6.78,6.65,0.872,0.688,0.577,0.577,0.577,0.577,0.577};


  TGraph* graph_mchamp100 = new TGraph(n_cuts, cut_mchamp100, eff_mchamp100);
  //gr_style(graph_mchamp100,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_mchamp100->SetMarkerStyle(23);
  graph_mchamp100->SetMarkerStyle(20);
  //graph_mchamp100->SetMarkerColor(6);
  graph_mchamp100->SetMarkerColor(1);
  graph_mchamp100->SetMarkerSize(1.6);
  graph_mchamp100->SetTitle(";Cut;Cumulative efficiency");
  graph_mchamp100->GetYaxis()->SetRangeUser(0,20);


  Float_t cut_mchamp400[n_cuts] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
  Float_t eff_mchamp400[n_cuts]    = {100.0,36.5,36.5,36.5,36.5,33.3,31.6,21.5,19.8,7.53,7.36,7.05,5.25,4.83,4.8,4.73,4.47,4.45};


  TGraph* graph_mchamp400 = new TGraph(n_cuts, cut_mchamp400, eff_mchamp400);
  //gr_style(graph_mchamp400,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_mchamp400->SetMarkerStyle(23);
  graph_mchamp400->SetMarkerStyle(21);
  //graph_mchamp400->SetMarkerColor(6);
  graph_mchamp400->SetMarkerColor(2);
  graph_mchamp400->SetMarkerSize(1.6);
  graph_mchamp400->SetTitle(";Cut;Cumulative efficiency");
  graph_mchamp400->GetYaxis()->SetRangeUser(0,20);



  Float_t cut_mchamp800[n_cuts] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
  Float_t eff_mchamp800[n_cuts]    = {100.0,35.7,35.7,35.7,35.7,32.5,30.6,20.4,18.9,6.98,6.84,6.51,4.39,4.0,3.92,3.84,3.69,3.69};


  TGraph* graph_mchamp800 = new TGraph(n_cuts, cut_mchamp800, eff_mchamp800);
  //gr_style(graph_mchamp800,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_mchamp800->SetMarkerStyle(23);
  graph_mchamp800->SetMarkerStyle(22);
  //graph_mchamp800->SetMarkerColor(6);
  graph_mchamp800->SetMarkerColor(4);
  graph_mchamp800->SetMarkerSize(1.6);
  graph_mchamp800->SetTitle(";Cut;Cumulative efficiency");
  graph_mchamp800->GetYaxis()->SetRangeUser(0,20);



  Float_t cut_mchamp1400[n_cuts] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
  Float_t eff_mchamp1400[n_cuts]    = {100.0,33.9,33.9,33.9,33.9,31.4,29.0,18.8,17.3,6.22,6.09,5.7,3.77,3.55,3.45,3.39,3.28,3.28};


  TGraph* graph_mchamp1400 = new TGraph(n_cuts, cut_mchamp1400, eff_mchamp1400);
  //gr_style(graph_mchamp1400,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_mchamp1400->SetMarkerStyle(23);
  graph_mchamp1400->SetMarkerStyle(23);
  //graph_mchamp1400->SetMarkerColor(6);
  graph_mchamp1400->SetMarkerColor(6);
  graph_mchamp1400->SetMarkerSize(1.6);
  graph_mchamp1400->SetTitle(";Cut;Cumulative efficiency");
  graph_mchamp1400->GetYaxis()->SetRangeUser(0,20);



  Float_t cut_mchamp2600[n_cuts] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
  Float_t eff_mchamp2600[n_cuts]    = {100.0,33.4,33.4,33.4,33.4,30.4,27.7,18.3,17.1,5.76,5.64,5.28,3.23,2.95,2.91,2.86,2.71,2.71};


  TGraph* graph_mchamp2600 = new TGraph(n_cuts, cut_mchamp2600, eff_mchamp2600);
  //gr_style(graph_mchamp2600,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_mchamp2600->SetMarkerStyle(23);
  graph_mchamp2600->SetMarkerStyle(24);
  //graph_mchamp2600->SetMarkerColor(6);
  graph_mchamp2600->SetMarkerColor(7);
  graph_mchamp2600->SetMarkerSize(1.6);
  graph_mchamp2600->SetTitle(";Cut;Cumulative efficiency");
  graph_mchamp2600->GetYaxis()->SetRangeUser(0,20);




  Leg1 = new TLegend(0.50,0.60,0.80,0.85);
  Leg1->AddEntry(graph_mchamp100,"mchamp100","p");
  Leg1->AddEntry(graph_mchamp400,"mchamp400","p");
  Leg1->AddEntry(graph_mchamp800,"mchamp800","p");
  Leg1->AddEntry(graph_mchamp1400,"mchamp1400","p");
  Leg1->AddEntry(graph_mchamp2600,"mchamp2600","p");
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
  graph_mchamp100->Draw("Psame");
  graph_mchamp400->Draw("Psame");
  graph_mchamp800->Draw("Psame");
  graph_mchamp1400->Draw("Psame");
  graph_mchamp2600->Draw("Psame");
  Leg1->Draw();
  CMS_lumi( canvas, iPeriod, iPos );
  //if(save_plots) canvas->SaveAs("../plots/nbunches_rate.eps");
  //if(save_plots) canvas->SaveAs("../plots/StoppedHSCPMuon/L2Mu40RateVsNCollidingBunches_2016.pdf");



}
