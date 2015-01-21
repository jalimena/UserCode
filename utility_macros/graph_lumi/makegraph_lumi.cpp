{

  using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  //gROOT->LoadMacro("/afs/cern.ch/user/j/jalimena/scratch0/plots/macros/style.cpp");
  gROOT->LoadMacro("~/plots/macros/style.cpp");
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

  TH2* h1=new TH2F("h1","",1600,0,1600,100,0,10);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Lumi Section;Inst Lumi [10^{33} cm^{-2}*s^{-1}]");
  h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  const int n_lumiSections = 1513;
  Float_t lumiSections[n_lumiSections];
  Float_t instLumi[n_lumiSections]; //instantaneous lumi for events passing HLT_ZeroBias in 207231
  //Float_t lumiSections_error[n_lumiSections] = {0,0,0,0};
  //Float_t instLumi_error[n_lumiSections] = {0.6,1,1.2,2};

  ifstream infile;
  infile.open("./lumi_WBM.txt");

  for(int i=0; i<n_lumiSections; i++){
    infile >> lumiSections[i] >> instLumi[i];
    //cout<<"lumiSections["<<i<<"] is: "<<lumiSections[i]<<", instLumi is: "<<instLumi[i]<<endl;
  }
  infile.close();

  TGraph* graph_data = new TGraph(n_lumiSections, lumiSections, instLumi);
  gr_style(graph_data,1,1,1,1001,50,-1111,-1111,510,510,20,1,0.5,1);
  graph_data->SetTitle(";Lumi Section;Inst Lumi [10^{33} cm^{-2}*s^{-1}]");
  //graph_data->GetYaxis()->SetRangeUser(0,20);

  /*
  Leg1 = new TLegend(0.45,0.75,0.75,0.85);
  Leg1->AddEntry(graph_data_noChaCut,"Average Before TS","p");
  Leg1->AddEntry(graph_data,"After TS","p");
  Leg1->AddEntry(graph_predicted,"Predicted After TS","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);
  */

  
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  canvas->cd();
  h1->Draw();
  graph_data->Draw("Psame");
  //text1->Draw();
  //Leg1->Draw();
  if(save_plots) canvas->SaveAs("../plots/lumi.eps");

}
