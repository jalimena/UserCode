//plots trigger rate as function of number of colliding bunches, saves eps files
// 7e33 V3 menu, June/July 2012

#include "TCanvas.h"
#include "TRandom3.h"
#include "TGraph.h"
#include "TMath.h"
#include "TArc.h"
#include "TVirtualFitter.h"

using namespace std;

  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  gROOT->LoadMacro("./style.cpp");
  //global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow

TGraph *graph;

void myfcn(Int_t &, Double_t *, Double_t &f, Double_t *par, Int_t) {
  //minimisation function computing the sum of squares of residuals
  Int_t np = graph->GetN();
  f = 0;
  Double_t *x = graph->GetX();
  Double_t *y = graph->GetY();
  for (Int_t i=0;i<np;i++) {
    Double_t u = x[i] - par[0];
    Double_t v = y[i] - par[1];
    Double_t dr = par[2] - TMath::Sqrt(u*u+v*v);
    f += dr*dr;
  }
}


void makegraph_xyhits_cosmic(){

  //bool save_plots = false;
  bool save_plots = true;

  TCanvas* canvas = new TCanvas("c1","c1",10,10,700,550);
  //canvas_style(canvas);

  //TH2* h1=new TH2F("h1","",2000,0,2000,2000,-1000,1000);
  TH2* h1=new TH2F("h1","",1000,0,1000,1000,0,1000);
  h1->SetStats(kFALSE);
  h1->SetTitle(";x [cm];y [cm]");
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  //cosmic event Run 208593, Event 19650, LumiSection 1, 62nd record
  const Int_t n_hits = 30;
  Float_t x[n_hits] = {218.135, 
		       218.426,
		       218.801,
		       219.053,
		       224.073,
		       224.394,
		       224.772,
		       225.030,
		       238.764,
		       239.139,
		       239.416,
		       239.753,
		       245.176,
		       245.513,
		       245.827,
		       267.015,
		       267.428,
		       267.716,
		       268.071,
		       273.422,
		       273.719,
		       274.128,
		       274.444,
		       295.269,
		       295.803,
		       295.956,
		       296.377,
		       301.704,
		       302.769,
		       302.738};
  
  Float_t y[n_hits] = {355.278,
		       356.610,
		       357.894,
		       359.249,
		       379.134,
		       380.449,
		       381.731,
		       383.083,
		       437.293,
		       438.576,
		       439.916,
		       441.222,
		       462.320,
		       463.625,
		       464.944,
		       544.925,
		       546.187,
		       547.520,
		       548.815,
		       568.476,
		       569.804,
		       571.068,
		       572.385,
		       646.625,
		       647.817,
		       649.228,
		       650.485,
		       670.240,
		       672.626,
		       674.142};


  graph = new TGraph(n_hits, x, y);
  //gr_style(graph,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1);
  graph->SetMarkerStyle(20);
  graph->SetMarkerSize(1);
  graph->SetMarkerColor(1);
  graph->SetTitle(";x [cm];y [cm]");
  //graph->GetYaxis()->SetRangeUser(0,20);


  //Fit a circle to the graph points
  TVirtualFitter::SetDefaultFitter("Minuit");  //default is Minuit
  TVirtualFitter *fitter = TVirtualFitter::Fitter(0, 3);
  Int_t a,c;
  Double_t b,f,par;
  fitter->SetFCN(myfcn);

  fitter->SetParameter(0, "x0",   1000, 0.1, 0,     2000);
  fitter->SetParameter(1, "y0",   0,    0.1, -1000, 1000);
  fitter->SetParameter(2, "R",    500,  0.1, 0,     1000);

  Double_t arglist[1] = {0};
  fitter->ExecuteCommand("MIGRAD", arglist, 0);

  //Draw the circle on top of the points
  TArc *arc = new TArc(fitter->GetParameter(0),
		       fitter->GetParameter(1),fitter->GetParameter(2));
  arc->SetLineColor(kRed);
  arc->SetLineWidth(4);



  Leg1 = new TLegend(0.45,0.75,0.75,0.85);
  //Leg1->AddEntry(graph_noChaCut,"Average Before TS","p");
  Leg1->AddEntry(graph,"After TS","p");
  //Leg1->AddEntry(graph_predicted,"Predicted After TS","p");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);


  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    3.4 fb^{-1}","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    4.4 fb^{-1}","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);

  TPaveLabel *text2 = new TPaveLabel(.17,.85,.37,.89,"Cosmic Event, Run 208593, Event 19650","NDC");
  text2->SetBorderSize(0);
  text2->SetTextSize(0.7);
  text2->SetFillColor(0);


  TPaveText* text1a = new TPaveText(500,500,700,700);
  text1a->SetBorderSize(0);
  text1a->SetTextSize(0.05);
  text1a->SetFillColor(0);
  double p0  = fitter->GetParameter(0);
  double p1  = fitter->GetParameter(1);
  double p2  = fitter->GetParameter(2);
  double e0  = fitter->GetParError(0);
  double e1  = fitter->GetParError(1);
  double e2  = fitter->GetParError(2);
  char p0name[50], p1name[50], p2name[50];
  sprintf(p0name,"x0 = %.2f #pm %.2f",p0,e0);
  sprintf(p1name,"y0 = %.2f #pm %.2f",p1,e1);
  sprintf(p2name,"R = %.2f #pm %.2f",p2,e2);
  text1a->AddText(p0name);
  text1a->AddText(p1name);
  text1a->AddText(p2name);


  canvas->cd();
  h1->Draw();
  arc->Draw("same");
  graph->Draw("Psame");
  text1a->Draw();
  //text1->Draw();
  text2->Draw();
  //Leg1->Draw();
  if(save_plots) canvas->SaveAs("../plots/hits_xy_cosmic.eps");

  //return 0;

}
