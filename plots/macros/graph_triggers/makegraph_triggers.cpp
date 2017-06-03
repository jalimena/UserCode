{
#include <fstream>
#include <sstream>
  using namespace std;
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

  bool save_plots = false;
  //bool save_plots = true;

  //TCanvas* canvas = new TCanvas("c1","c1",10,10,700,550);
  TCanvas* canvas = new TCanvas("c1","c1",100,100,1400,550);
  canvas_style(canvas);
  canvas->SetGrid();

  TH1* h_data=new TH1F("h_data","",36,0,36);//,100,0,20000);
  h_data->SetStats(kFALSE);
  h_data->SetTitle(";;Acceptance");
  //h2_style(h_data,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);
  h1_style(h_data,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  TH1* h_mchamp500=new TH1F("h_mchamp500","",36,0,36);//,100,0,20000);
  h_mchamp500->SetStats(kFALSE);
  h_mchamp500->SetTitle(";;Acceptance");
  h1_style(h_mchamp500,3,2,2,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);

  const int n_triggers = 36;
  Float_t triggers[n_triggers];
  Float_t triggers_mchamp500[n_triggers];
  Float_t counts_data[n_triggers]; 
  Float_t counts_mchamp500[n_triggers]; 
  string triggerNames[n_triggers];
  string triggerNames_mchamp500[n_triggers];
  //Float_t triggers_error[n_triggers] = {0,0,0,0};
  //Float_t counts_data_error[n_triggers] = {0.6,1,1.2,2};

  ifstream infile_data;
  infile_data.open("./trigger_counts.txt");

  for(int i=0; i<n_triggers; i++){
    infile_data >> triggers[i] >> counts_data[i] >> triggerNames[i];
    //cout<<"triggers["<<i<<"] is: "<<triggers[i]<<", counts_data is: "<<counts_data[i]<<endl;
  }
  infile_data.close();

  ifstream infile_mchamp500;
  infile_mchamp500.open("./trigger_counts_mchamp500.txt");

  for(int i=0; i<n_triggers; i++){
    infile_mchamp500 >> triggers_mchamp500[i] >> counts_mchamp500[i] >> triggerNames_mchamp500[i];
    //cout<<"triggers["<<i<<"] is: "<<triggers[i]<<", counts_mchamp500 is: "<<counts_mchamp500[i]<<endl;
  }
  infile_mchamp500.close();

  for(int i=0; i<n_triggers; i++){
    h_data->SetBinContent(i+1,counts_data[i]);
    h_mchamp500->SetBinContent(i+1,counts_mchamp500[i]);
    h_data->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
    h_mchamp500->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
  }

  //Leg1 = new TLegend(0.45,0.75,0.75,0.85);
  Leg1 = new TLegend(0.15,0.45,0.30,0.55);
  Leg1->AddEntry(h_data,"Data","l");
  Leg1->AddEntry(h_mchamp500,"500 GeV mchamps","l");
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.04);
  Leg1->SetFillColor(0);


  
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  TPaveLabel *text1 = new TPaveLabel(.1,.93,.3,.97,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  canvas->cd();
  h_data->Draw("hist");
  h_mchamp500->Draw("histsame");
  text1->Draw();
  Leg1->Draw();
  if(save_plots) canvas->SaveAs("../../plots/trigger2015/possibleTriggerCuts.eps");

}
