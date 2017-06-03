{

  using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  //gROOT->LoadMacro("/afs/cern.ch/user/j/jalimena/scratch0/plots/macros/style.cpp");
  //gROOT->LoadMacro("~/plots/macros/style.cpp");
  //global_style();
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("CMS_lumi.C");

  setTDRStyle();
  tdrGrid(false, tdrStyle);

  writeExtraText = true;
  extraText  = "Simulation Preliminary";
  lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV                                                                                                                                   
  //int iPos=11;
  int iPos=22;

  //int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  //gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow

  //bool save_plots = false;
  bool save_plots = true;

  TCanvas* canvas = new TCanvas("c1","c1",10,10,700,550);
  //canvas_style(canvas);

  //TH2* h1=new TH2F("h1","",200,0,1000,100,0,1);
  TH2* h1=new TH2F("h1","",40,0,200,110,0,1.1);
  h1->SetStats(kFALSE);
  h1->SetTitle(";HLT p_{T} Cut [GeV];Fraction of Accepted Events");
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);
  h1->SetLineColor(1);
  h1->SetLineStyle(1);
  h1->SetLineWidth(3);

  //const int n_efficiency = 200;
  const int n_efficiency = 41;
  Float_t ptCut[n_efficiency]; 
  Float_t efficiency0[n_efficiency];
  Float_t efficiency1[n_efficiency];
  Float_t ptCut_error[n_efficiency];
  Float_t efficiency0_error[n_efficiency];
  Float_t efficiency1_error[n_efficiency];

  ifstream infile0, infile1;
  infile0.open("../txtfiles/HltPlotIntegral_plot0.txt");
  infile1.open("../txtfiles/HltPlotIntegral_plot1.txt");

  for(int i=0; i<n_efficiency; i++){
    ptCut[i] = i*5;
    ptCut_error[0] = 0.;
    infile0 >> efficiency0[i] >> efficiency0_error[i];
    infile1 >> efficiency1[i] >> efficiency1_error[i];
    cout<<"efficiency["<<i<<"] is: "<<efficiency0[i]<<", error is: "<<efficiency0_error[i]<<endl;
  }
  infile0.close();

  for(int i=0; i<n_efficiency; i++){
    efficiency0[i] = 1.0*efficiency0[i]/19441;
    efficiency1[i] = 1.0*efficiency1[i]/19441;
    efficiency0_error[i] = 1.0*efficiency0_error[i]/19441;
    efficiency1_error[i] = 1.0*efficiency1_error[i]/19441;
  }
  TGraphErrors* graph0 = new TGraphErrors(n_efficiency, ptCut, efficiency0, ptCut_error, efficiency0_error);
  TGraphErrors* graph1 = new TGraphErrors(n_efficiency, ptCut, efficiency1, ptCut_error, efficiency1_error);
  //gr_style(graph0,1,1,1,1001,50,-1111,-1111,510,510,20,1,0.5,1);
  //gr_style(graph1,1,1,1,1001,50,-1111,-1111,510,510,21,2,0.5,1);
  graph0->SetTitle(";HLT p_{T} Cut [GeV];Fraction of Accepted Events");
  graph1->SetTitle(";HLT p_{T} Cut [GeV];Fraction of Accepted Events");
  graph1->SetMarkerStyle(21);
  graph1->SetMarkerColor(2);
  //graph0->GetYaxis()->SetRangeUser(0,20);

  TLine* line0 = new TLine(20,0,20,1.1);
  line0->SetLineStyle(3);
  line0->SetLineWidth(4);
  line0->SetLineColor(3);

  TLine* line1 = new TLine(35,0,35,1.1);
  line1->SetLineStyle(4);
  line1->SetLineWidth(4);
  line1->SetLineColor(6);

  /*
  Leg1 = new TLegend(0.45,0.75,0.75,0.85);
  Leg1->AddEntry(graph0_noChaCut,"Average Before TS","p");
  Leg1->AddEntry(graph0,"After TS","p");
  Leg1->AddEntry(graph_predicted,"Predicted After TS","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);
  */
  //char* LegFile[2] = {"Configuration in 2012","L1 and HLT Improvements for 2015"};
  char* LegFile[2] = {"2012 L1 and HLT","2015 L1 and HLT"};
  char LegEntry[100];

  //Leg1 = new TLegend(0.5,0.75,0.85,0.92);
  //Leg1 = new TLegend(0.6,0.7,0.85,0.92);
  Leg1 = new TLegend(0.65,0.63,0.9,0.85);
  //for (int a=0; a<NumFiles; a++){
  sprintf(LegEntry,"%s",LegFile[0]);
  Leg1->AddEntry(graph0,LegEntry,"p");
  sprintf(LegEntry,"%s",LegFile[1]);
  Leg1->AddEntry(graph1,LegEntry,"p");
  Leg1->AddEntry(line0,"2012 HLT p_{T} Cut","l");
  Leg1->AddEntry(line1,"2015 HLT p_{T} Cut","l");
    //}
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);

  
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  canvas->cd();
  h1->Draw();
  graph0->Draw("Psame");
  graph1->Draw("Psame");
  line0->Draw("same");
  line1->Draw("same");
  //text1->Draw();
  Leg1->Draw();
  CMS_lumi( canvas, iPeriod, iPos );

  if(save_plots) canvas->SaveAs("../plots/TriggerObjects/efficiencyVsPtcut_hlt_NoBPTX_mchamp500.eps");

}
