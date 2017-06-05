#include <fstream>
#include <sstream>
using namespace std;

void makehistos_cosmicEventMixing(){
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

  //gROOT->LoadMacro("../tdrstyle.C");
  //gROOT->LoadMacro("../CMS_lumi.C");

  //setTDRStyle();
  //tdrGrid(false, tdrStyle); 
  //writeExtraText = true;
  //extraText  = "Preliminary"; 

  //lumi_8TeV = "8, 13 TeV"; 
  //lumi_8TeV = "13 TeV";
  //lumi_8TeV = ""; 
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV 
  //int iPos=0; 
  int iPos=11;
  //int iPos=22; 
  //bool save_plots = false; 
  bool save_plots = true;

  TCanvas* canvas_ptUpper_ptLower = new TCanvas("canvas_ptUpper_ptLower","canvas_ptUpper_ptLower",10,10,650,550);
  TH2* hist_ptUpper_ptLower=new TH2F("hist_ptUpper_ptLower","hist_ptUpper_ptLower",100,0,1000,100,0,1000);
  hist_ptUpper_ptLower->SetTitle(";Upper DSA p_{T} [GeV];Lower DSA p_{T} [GeV]");

  TCanvas* canvas_pUpper_delta_t_RPC = new TCanvas("canvas_pUpper_delta_t_RPC","canvas_pUpper_delta_t_RPC",10,10,650,550);
  TH2* hist_pUpper_delta_t_RPC=new TH2F("hist_pUpper_delta_t_RPC","hist_pUpper_delta_t_RPC",100,0,1000,200,-100,100);
  hist_pUpper_delta_t_RPC->SetTitle(";Upper DSA p [GeV];#Delta t_{RPC} [ns]");

  TCanvas* canvas_pUpper_delta_t_RPC_afterDeltaTDTCut = new TCanvas("canvas_pUpper_delta_t_RPC_afterDeltaTDTCut","canvas_pUpper_delta_t_RPC_afterDeltaTDTCut",10,10,650,550);
  TH2* hist_pUpper_delta_t_RPC_afterDeltaTDTCut=new TH2F("hist_pUpper_delta_t_RPC_afterDeltaTDTCut","hist_pUpper_delta_t_RPC_afterDeltaTDTCut",100,0,1000,200,-100,100);
  hist_pUpper_delta_t_RPC_afterDeltaTDTCut->SetTitle(";Upper DSA p [GeV];#Delta t_{RPC} [ns]");

  TCanvas* canvas_delta_t_RPC = new TCanvas("canvas_delta_t_RPC","canvas_delta_t_RPC",10,10,650,550);
  TH1* hist_delta_t_RPC=new TH1F("hist_delta_t_RPC","hist_delta_t_RPC",200,-100,100);
  hist_delta_t_RPC->SetTitle(";#Delta t_{RPC} [ns];Events");

  TCanvas* canvas_delta_t_DT = new TCanvas("canvas_delta_t_DT","canvas_delta_t_DT",10,10,650,550);
  TH1* hist_delta_t_DT=new TH1F("hist_delta_t_DT","hist_delta_t_DT",200,-100,100);
  hist_delta_t_DT->SetTitle(";#Delta t_{DT} [ns];Events");

  TCanvas* canvas_delta_t_DT_delta_t_RPC = new TCanvas("canvas_delta_t_DT_delta_t_RPC","canvas_delta_t_DT_delta_t_RPC",10,10,650,550);
  TH2* hist_delta_t_DT_delta_t_RPC=new TH2F("hist_delta_t_DT_delta_t_RPC","hist_delta_t_DT_delta_t_RPC",200,-100,100,200,-100,100);
  hist_delta_t_DT_delta_t_RPC->SetTitle(";#Delta t_{DT} [ns];#Delta t_{RPC} [ns]");

  TCanvas* canvas_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut = new TCanvas("canvas_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut","canvas_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut",10,10,650,550);
  TH2* hist_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut=new TH2F("hist_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut","hist_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut",100,0,1000,200,-100,100);
  hist_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut->SetTitle(";Upper DSA p [GeV];#Delta t_{RPC} [ns]");


  //pUpper_delta_t_RPC->SetStats(kFALSE);
  //h2_style(pUpper_delta_t_RPC,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);
  //h1_style(pUpper_delta_t_RPC,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  const int nEvents = 350;
  Int_t upperRun[nEvents];
  Int_t upperLs[nEvents];
  Long_t upperEvent[nEvents];
  Double_t upperP[nEvents];
  Double_t upperPt[nEvents];
  Double_t upperEta[nEvents];
  Double_t upperPhi[nEvents];
  Double_t upperT_DT[nEvents];
  Double_t upperRpcAv[nEvents];
  Int_t lowerRun[nEvents];
  Int_t lowerLs[nEvents];
  Long_t lowerEvent[nEvents];
  Double_t lowerP[nEvents];
  Double_t lowerPt[nEvents];
  Double_t lowerEta[nEvents];
  Double_t lowerPhi[nEvents];
  Double_t lowerT_DT[nEvents];
  Double_t lowerRpcAv[nEvents];
  Double_t delta_t_DT[nEvents];
  Double_t delta_t_RPC[nEvents];

  ifstream infileEventMixing;
  infileEventMixing.open("./cosmicsEventMixing.txt");

  for(int i=0; i<nEvents; i++){
    infileEventMixing >> upperRun[i] >> upperLs[i] >> upperEvent[i] >> upperP[i] >> upperPt[i] >> upperEta[i] >> upperPhi[i] >> upperT_DT[i] >> upperRpcAv[i] >> lowerRun[i] >> lowerLs[i] >> lowerEvent[i] >> lowerP[i] >> lowerPt[i] >> lowerEta[i] >> lowerPhi[i] >> lowerT_DT[i] >> lowerRpcAv[i] >> delta_t_DT[i] >> delta_t_RPC[i];
    //cout << upperRun[i] << " " << upperLs[i] << " " << upperEvent[i] << " " << upperP[i] << " " << upperPt[i] << " " << upperEta[i] << " " << upperPhi[i] << " " << upperT_DT[i] << " " << upperRpcAv[i] << " " << lowerRun[i] << " " << lowerLs[i] << " " << lowerEvent[i] << " " << lowerP[i] << " " << lowerPt[i] << " " << lowerEta[i] << " " << lowerPhi[i] << " " << lowerT_DT[i] << " " << lowerRpcAv[i] << " " << delta_t_DT[i] << " " << delta_t_RPC[i] << endl;
  }
  infileEventMixing.close();

  for(int i=0; i<nEvents; i++){
    hist_ptUpper_ptLower->Fill(upperPt[i],lowerPt[i]);
    hist_pUpper_delta_t_RPC->Fill(upperP[i],delta_t_RPC[i]);
    hist_delta_t_RPC->Fill(delta_t_RPC[i]);
    hist_delta_t_DT->Fill(delta_t_DT[i]);
    hist_delta_t_DT_delta_t_RPC->Fill(delta_t_DT[i],delta_t_RPC[i]);
    if(delta_t_DT[i]>-20) hist_pUpper_delta_t_RPC_afterDeltaTDTCut->Fill(upperP[i],delta_t_RPC[i]);
    if(delta_t_DT[i]>-20 && delta_t_RPC[i]>-7.5) hist_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut->Fill(upperP[i],delta_t_RPC[i]);
    //hist_ptUpper_ptLower->SetBinContent(i+1,counts_data[i]);
    //hist_ptUpper_ptLower->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
  }

  //Leg1 = new TLegend(0.45,0.75,0.75,0.85);
  TLegend* Leg1 = new TLegend(0.15,0.45,0.30,0.55);
  Leg1->AddEntry(hist_ptUpper_ptLower,"Data","l");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);


  
  TPaveLabel *text1 = new TPaveLabel(.1,.93,.3,.97,"CMS Preliminary    #sqrt{s}=13 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  canvas_ptUpper_ptLower->cd();
  hist_ptUpper_ptLower->Draw("colz");
  //text1->Draw();
  //Leg1->Draw();
  if(save_plots) canvas_ptUpper_ptLower->SaveAs("../../plots/cosmicEventMixing/ptUpper_ptLower.pdf");

  canvas_pUpper_delta_t_RPC->cd();
  hist_pUpper_delta_t_RPC->Draw("colz");
  //text1->Draw();
  //Leg1->Draw();
  if(save_plots) canvas_pUpper_delta_t_RPC->SaveAs("../../plots/cosmicEventMixing/pUpper_delta_t_RPC.pdf");

  canvas_pUpper_delta_t_RPC_afterDeltaTDTCut->cd();
  hist_pUpper_delta_t_RPC_afterDeltaTDTCut->Draw("colz");
  //text1->Draw();
  //Leg1->Draw();
  if(save_plots) canvas_pUpper_delta_t_RPC_afterDeltaTDTCut->SaveAs("../../plots/cosmicEventMixing/pUpper_delta_t_RPC_afterDeltaTDTCut.pdf");

  canvas_delta_t_RPC->cd();
  hist_delta_t_RPC->Draw("hist");
  //text1->Draw();
  //Leg1->Draw();
  if(save_plots) canvas_delta_t_RPC->SaveAs("../../plots/cosmicEventMixing/delta_t_RPC.pdf");

  canvas_delta_t_DT->cd();
  hist_delta_t_DT->Draw("hist");
  //text1->Draw();
  //Leg1->Draw();
  if(save_plots) canvas_delta_t_DT->SaveAs("../../plots/cosmicEventMixing/delta_t_DT.pdf");

  canvas_delta_t_DT_delta_t_RPC->cd();
  hist_delta_t_DT_delta_t_RPC->Draw("colz");
  //text1->Draw();
  //Leg1->Draw();
  if(save_plots) canvas_delta_t_DT_delta_t_RPC->SaveAs("../../plots/cosmicEventMixing/delta_t_DT_delta_t_RPC.pdf");

  canvas_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut->cd();
  hist_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut->Draw("colz");
  //text1->Draw();
  //Leg1->Draw();
  if(save_plots) canvas_pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut->SaveAs("../../plots/cosmicEventMixing/pUpper_delta_t_RPC_afterDeltaTDTDeltaTRPCCut.pdf");

}
