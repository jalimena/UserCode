{

  using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  gROOT->LoadMacro("../style.cpp");
  global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow

  //bool save_plots = false;
  bool save_plots = true;

  TCanvas* canvas = new TCanvas("c1","c1",10,10,700,550);
  canvas_style(canvas);

  TH2* h1=new TH2F("h1","",250,0,250,110,0,550);
  h1->SetStats(kFALSE);
  h1->SetTitle(";Generator Muon p_{T} [GeV];Cosmic Muon Track p_{T} [GeV]");
  h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  const int n = 9;
  Float_t gen_pt[n];
  Float_t reco_pt[n];
  //Float_t delta_phi_error[n] = {0,0,0,0};
  //Float_t gen_pt_error[n] = {0.6,1,1.2,2};

  ifstream infile;
  infile.open("./genpt_recopt.txt");

  for(int i=0; i<n; i++){
    infile >> gen_pt[i] >> reco_pt[i];
    //cout<<"lumiSections["<<i<<"] is: "<<lumiSections[i]<<", gen_pt is: "<<gen_pt[i]<<endl;
  }
  infile.close();

  TGraph* graph_data = new TGraph(n, gen_pt, reco_pt);
  //gr_style(graph_data,1,1,1,1001,50,-1111,-1111,510,510,20,1,0.5,1);
  gr_style(graph_data,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.0,1);
  graph_data->SetTitle(";Generator Muon p_{T} [GeV];Cosmic Muon Track p_{T} [GeV]");
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
  if(save_plots) canvas->SaveAs("../../plots/plots/genpt_recopt.eps");

}
