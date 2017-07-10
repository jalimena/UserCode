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
  //canvas->SetLogy();
  //canvas_style(canvas);
  //canvas->SetRightMargin(0.15);

  //TH2* h1=new TH2F("h1","",100,-100,0,100000,-10,3000);
  TH2* h1=new TH2F("h1","",100,-100,0,100000,0,150);
  h1->SetStats(kFALSE);
  h1->SetTitle(";#Delta t_{RPC} [ns];Integral of bkgnd fit #Delta t_{DT} > -20 ns");
  h1->GetYaxis()->SetTitleOffset(1.1);
  h1->GetXaxis()->SetNdivisions(505);
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  const Int_t n_cuts2016 = 9;
  Float_t cut_delta_tRPC2016[n_cuts2016] = {-75,-47.5,-42.5,-37.5,-32.5,-27.5,-22.5,-17.5,-12.5};
  Float_t int_delta_tDT2016[n_cuts2016] = {2.85,8.73,25.77,31.91,74,33.38,17,7.21,3.4}; //2gaus, crystal ball, FINAL (C+D)
  //Float_t int_delta_tDT2016[n_cuts2016] = {}; //2gaus, landau, FINAL (C+D)
  Float_t errorPlus_int_delta_tDT2016[n_cuts2016] = {1.25,3.92,16.6,1.52,40,2.8,15.4,5,3}; //2gaus, crystal ball FINAL (C+D)
  Float_t errorMinus_int_delta_tDT2016[n_cuts2016] = {2.15,0,7.64,0,51,0,0.36,0,0}; //2gaus, crystal ball FINAL (C+D)
  //Float_t errorPlus_int_delta_tDT2016[n_cuts2016] = {}; //2gaus, landau, FINAL (C+D)
  //Float_t errorMinus_int_delta_tDT2016[n_cuts2016] = {}; //2gaus, landau, FINAL (C+D)
  Float_t errorCut_delta_tRPC2016[n_cuts2016] = {25,2.5,2.5,2.5,2.5,2.5,2.5,2.5,2.5}; //2gaus, crystal ball FINAL (C+D)
  TGraphAsymmErrors* graph_integral2016 = new TGraphAsymmErrors(n_cuts2016, cut_delta_tRPC2016, int_delta_tDT2016,errorCut_delta_tRPC2016,errorCut_delta_tRPC2016,errorMinus_int_delta_tDT2016,errorPlus_int_delta_tDT2016);
  //gr_style(graph_integral2016,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_integral2016->SetMarkerStyle(23);
  graph_integral2016->SetMarkerStyle(20);
  //graph_integral2016->SetMarkerColor(6);
  graph_integral2016->SetMarkerColor(1);
  graph_integral2016->SetMarkerSize(1.6);
  graph_integral2016->SetTitle(";#Delta t_{RPC} [ns];Integral of bkgnd fit #Delta t_{DT} > -20 ns");
  //graph_integral2016->GetYaxis()->SetRangeUser(0,20);

  //from stopped particles reco efficiency turn on curve
  //TF1* fit1 = new TF1("fit1", "[0]*TMath::Erf([1]*x-[2])+[3]", -60, -10);
  //fit1->SetParameters(0.25,0.034,2.33,0.25);
  /*
  TF1* fit1 = new TF1("fit1", "[0]*TMath::Erf([1]*x-[2])+[3]", -32.5, -7.5);//2gaus, crystal ball, FINAL (C+D)
  //TF1* fit1 = new TF1("fit1", "[0]*TMath::Erf([1]*x-[2])+[3]", -35, -7.5);//2gaus, landau, FINAL (C+D)    
  fit1->SetParameters(1,0.001,0.09,1); //crystal ball
  //graph_integral2016->Fit("fit1","R");
  TF1* fit1ext = (TF1*)fit1->Clone();
  //graph_integral2016->Fit("fit1ext","R+");
  fit1ext->SetLineStyle(2);
  fit1ext->SetRange(-7.5,0);
  //graph_integral2016->Fit("pol2","","",-25,-7.5);
  */
  /*
  //const Int_t n_cuts2015 = 10;
  //const Int_t n_cuts2015 = 9;
  //Float_t cut_delta_tRPC2015[n_cuts2015] = {-100, -50, -45, -40, -35, -30, -25, -15, -10}; //2gaus, crystal ball, FINAL (C+D)
  //Float_t cut_delta_tRPC2015[n_cuts2015] = {-100, -50, -45, -40, -35, -30, -25, -20, -15, -10}; //2gaus, landau, FINAL (C+D)
  //Float_t int_delta_tDT2015[n_cuts2015] = {}; //2gaus, crystal ball, FINAL (C+D)
  //Float_t int_delta_tDT2015[n_cuts2015] = {}; //2gaus, landau, FINAL (C+D)
  //Float_t errorPlus_int_delta_tDT2015[n_cuts2015] = {}; //2gaus, crystal ball FINAL (C+D)
  //Float_t errorMinus_int_delta_tDT2015[n_cuts2015] = {}; //2gaus, crystal ball FINAL (C+D)
  //Float_t errorPlus_int_delta_tDT2015[n_cuts2015] = {}; //2gaus, landau FINAL (C+D)
  //Float_t errorMinus_int_delta_tDT2015[n_cuts2015] = {}; //2gaus, landau FINAL (C+D)
  TGraphAsymmErrors* graph_integral2015 = new TGraphAsymmErrors(n_cuts2015, cut_delta_tRPC2015, int_delta_tDT2015,0,0,errorMinus_int_delta_tDT2015,errorPlus_int_delta_tDT2015);
  //gr_style(graph_integral2015,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1);
  //graph_integral2015->SetMarkerStyle(23);
  graph_integral2015->SetMarkerStyle(21);
  //graph_integral2015->SetMarkerColor(6);
  graph_integral2015->SetMarkerColor(2);
  graph_integral2015->SetMarkerSize(1.6);
  graph_integral2015->SetTitle(";#Delta t_{RPC} [ns];Integral of bkgnd fit #Delta t_{DT} > -20 ns");
  //graph_integral2015->GetYaxis()->SetRangeUser(0,20);

  TF1* fit2 = new TF1("fit2", "[0]*TMath::Erf([1]*x-[2])+[3]", -50, -7.5);
  //fit2->SetParameters(1,0.034,5,0);
  fit2->SetParameters(1,0.034,1,0.5);
  graph_integral2015->Fit("fit2","R");
  TF1* fit2ext = (TF1*)fit2->Clone();
  graph_integral2015->Fit("fit2ext","R+");
  fit2ext->SetLineStyle(2);
  fit2ext->SetRange(-7.5,0);

  //graph_integral2015->Fit("pol2","","",-50,-25);
  */
  Leg1 = new TLegend(0.70,0.80,0.90,0.90);
  //Leg1->AddEntry(graph_integral2015,"2015 Data","p");
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

  gStyle->SetOptFit(kFALSE);
  canvas->cd();
  h1->Draw();
  //graph_integral2015->Draw("Psame");
  graph_integral2016->Draw("Psame");
  //fit1ext->Draw("same");
  //fit2ext->Draw("same");
  Leg1->Draw();
  CMS_lumi( canvas, iPeriod, iPos );
  if(save_plots) canvas->SaveAs("../../plots/backgroundExtrapolation_2GausCrystalBall_nonOverlappingRegions.pdf");
  //if(save_plots) canvas->SaveAs("../../plots/backgroundExtrapolation_FINAL2GausLandau_errorfuncfit.pdf");



}
