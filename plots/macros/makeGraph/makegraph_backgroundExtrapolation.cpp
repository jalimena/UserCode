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
  gStyle->SetFitFormat("6.4f");
  gStyle->SetStatFormat("6.4f");

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

  TCanvas* canvas = new TCanvas("c1","Integral #Delta t_{DT} > -20 ns vs #Delta t_{RPC} Cut",10,10,575,500);
  //canvas_style(canvas);
  //canvas->SetRightMargin(0.15);

  //TH2* h1=new TH2F("h1","",20,-100,0,45,0,15);
  TH2* h1=new TH2F("h1","",20,-100,0,50,0,100);
  h1->SetStats(kFALSE);
  h1->SetTitle(";#Delta t_{RPC} Cut [ns];Integral of bkgnd fit #Delta t_{DT} > -20 ns");
  h1->GetYaxis()->SetTitleOffset(0.8);
  h1->GetXaxis()->SetNdivisions(505);
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  Int_t n_cuts2016 = 8;
  Float_t cut_delta_tRPC2016[n_cuts2016] = {-100, -50, -45, -40, -35, -30, -25, -20};
  //Float_t int_delta_tDT2016[n_cuts2016] = {10.67,10.31,9.42,9.05,7.88,4.99,1.13,0.497}; //2gaus, crystal ball
  Float_t int_delta_tDT2016[n_cuts2016] = {90,87,84,75,58,31,7.1,3.8}; //gaus, landau
  TGraph* graph_integral2016 = new TGraph(n_cuts2016, cut_delta_tRPC2016, int_delta_tDT2016);
  //gr_style(graph_integral2016,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_integral2016->SetMarkerStyle(23);
  graph_integral2016->SetMarkerStyle(20);
  //graph_integral2016->SetMarkerColor(6);
  graph_integral2016->SetMarkerColor(1);
  graph_integral2016->SetMarkerSize(1.6);
  graph_integral2016->SetTitle(";#Delta t_{RPC} Cut [ns];Integral of bkgnd fit #Delta t_{DT} > -20 ns");
  //graph_integral2016->GetYaxis()->SetRangeUser(0,20);

  graph_integral2016->Fit("pol2","","",-50,-20);

  Int_t n_cuts2015 = 6;
  Float_t cut_delta_tRPC2015[n_cuts2015] = {-100, -50, -45, -40, -35, -30};
  //Float_t int_delta_tDT2015[n_cuts2015] = {2.959,3.43,3.23,2.81,2.16,1.49}; //2gaus, crystal ball
  Float_t int_delta_tDT2015[n_cuts2015] = {13,12.6,12,11.8,10.9,8.8}; //gaus, landau
  TGraph* graph_integral2015 = new TGraph(n_cuts2015, cut_delta_tRPC2015, int_delta_tDT2015);
  //gr_style(graph_integral2015,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_integral2015->SetMarkerStyle(23);
  graph_integral2015->SetMarkerStyle(21);
  //graph_integral2015->SetMarkerColor(6);
  graph_integral2015->SetMarkerColor(2);
  graph_integral2015->SetMarkerSize(1.6);
  graph_integral2015->SetTitle(";#Delta t_{RPC} Cut [ns];Integral of bkgnd fit #Delta t_{DT} > -20 ns");
  //graph_integral2015->GetYaxis()->SetRangeUser(0,20);

  graph_integral2015->Fit("pol2","","",-50,-30);

  Leg1 = new TLegend(0.70,0.80,0.90,0.90);
  Leg1->AddEntry(graph_integral2015,"2015 Data","p");
  Leg1->AddEntry(graph_integral2016,"2016 Data","p");
  Leg1->SetBorderSize(0);
  //Leg1->SetTextSize(0.03);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);




  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.92,.37,.96,"CMS Preliminary    #sqrt{s}=13 TeV","NDC");

  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  canvas->cd();
  h1->Draw();
  graph_integral2015->Draw("Psame");
  graph_integral2016->Draw("Psame");
  Leg1->Draw();
  CMS_lumi( canvas, iPeriod, iPos );
  //if(save_plots) canvas->SaveAs("../plots/backgroundExtrapolation.pdf");
  if(save_plots) canvas->SaveAs("../plots/backgroundExtrapolationGausLandau.pdf");



}
