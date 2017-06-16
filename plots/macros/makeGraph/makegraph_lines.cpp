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

  TCanvas* canvas = new TCanvas("c1","c1",10,10,575,500);
  //canvas_style(canvas);
  //canvas->SetRightMargin(0.15);

  TH2* h1=new TH2F("h1","",20,-10,10,5,0,1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";BX;Efficiency");
  h1->GetYaxis()->SetTitleOffset(0.8);
  //h1->GetXaxis()->SetNdivisions(505);
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);


  TF1* f1 = new TF1("f1","-1.*x/10.+1.",0,10);
  TF1* f2 = new TF1("f2","1.*x/10.+1.",-10,0);
  f1->SetLineWidth(2);
  f2->SetLineWidth(2);
  f1->SetLineColor(1);
  f2->SetLineColor(1);

  canvas->cd();
  h1->Draw();
  f1->Draw("same");
  f2->Draw("same");
  //graph_data2017_25ns->Draw("Psame");
  //Leg1->Draw();
  //CMS_lumi( canvas, iPeriod, iPos );
  if(save_plots) canvas->SaveAs("../../plots/muonRecoEfficiencyVsBX.pdf");

}
