{
  //overlays histograms, saves eps files

  using namespace std;
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  //gROOT->LoadMacro("../style.cpp");
  //global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  /////gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  gROOT->LoadMacro("../tdrstyle.C");
  gROOT->LoadMacro("../CMS_lumi.C");

  setTDRStyle();
  //tdrGrid(false, tdrStyle);

  writeExtraText = true;
  extraText  = "Preliminary";
  //lumi_8TeV = "";
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
  //int iPos=0;
  int iPos=11;
  //int iPos=22; 

  bool save_plots = false;
  //bool save_plots = true;

  const int NumFiles = 5;
  
  TFile f1("/home/alimena/histos/NoBPTX_Run2012C_ControlTriggers_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_RPC1.root");
  TFile f2("/home/alimena/histos/cosmicMC_Plus125_take2_updatedSim/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //TFile f1("/home/alimena/histos/cosmics_allphi_NoBPTX_Run2012D_723patch1/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");

  TFile f3("/home/alimena/histos/mchamp100_separateEvents_725_updatedSim_fixedMatching/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f4("/home/alimena/histos/mchamp500_separateEvents_725_updatedSim_fixedMatching/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  TFile f5("/home/alimena/histos/mchamp1000_separateEvents_725_updatedSim_fixedMatching/wBxCut_wCavCut_woGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_wPtCut_wChaCut_woEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  const int Num1DHists = 2;
  char* plot1D[Num1DHists] = {
    "muDisplacedStandAlonePt_HLTnumerator_",
    //"muDisplacedStandAlonePt_L1numerator_",
    "muDisplacedStandAlonePt_denominator_"
  };

  char* xtitle1D[Num1DHists] = {
    "DSA Track p_{T} [GeV]",
    "DSA Track p_{T} [GeV]"
  };
  cout<<"ready for 1D hists"<<endl;

  //set up canvases
  char Cname1D[200], Ctitle1D[500];
  TCanvas* canvases1D[Num1DHists];
  //TCanvas* canvases1D[17];
  for (int i=0; i<1; i++){
    sprintf(Cname1D,"canvases1D[%i]",i);
    sprintf(Ctitle1D,"%s",plot1D[i]);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,10,575,500);
    //if (i<89) canvases1D[i]->SetLogy();
    //canvas_style(canvases1D[i]);
  }
  cout<<"made 1D canvases"<<endl;

  //get histograms
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  for(int i=0; i<Num1DHists; i++){
    sprintf(oldH1Dname,"%shist",plot1D[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1Dname);
    HAll1D[1][i] = (TH1D*) f2.Get(oldH1Dname);    
    HAll1D[2][i] = (TH1D*) f3.Get(oldH1Dname);    
    HAll1D[3][i] = (TH1D*) f4.Get(oldH1Dname);    
    HAll1D[4][i] = (TH1D*) f5.Get(oldH1Dname);    
  }
  cout<<"got histograms"<<endl;

  //put in histogram specifications
  int color[NumFiles] = {1,2,4,6,8};//,11};
  int style[NumFiles] = {1,2,3,4,5};//,6};
  int marker[NumFiles] = {20,21,22,23,24};//,25};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
    HAll1D[a][0]->SetLineColor(1);
    HAll1D[a][1]->SetLineColor(2);
    for(int i=0; i<Num1DHists; i++){
      //sprintf(axistitles,";%s;Efficiency",xtitle1D[i]);
      sprintf(axistitles,";%s;Events",xtitle1D[i]);
      //cout<<"sprintf axis title"<<endl;
      HAll1D[a][i]->SetTitle(axistitles);
      //cout<<"set axis titles"<<endl;
      //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
      //h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //cout<<"h1_style"<<endl;
      cout<<"xtitle1D[i] is: "<<xtitle1D[i]<<endl;
    }
  }

  //sumw2 for correct error bars
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      HAll1D[a][i]->Sumw2();
    }
  }


  for (int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      HAll1D[a][i]->GetXaxis()->SetRangeUser(0,200);
      HAll1D[a][i]->Rebin(2);
      //HAll1D[a][i]->Rebin(10);
    }    
  }
  cout<<"put in histogram specs"<<endl;

  

  TGraphAsymmErrors* eff_graph = new TGraphAsymmErrors();
  //Really you can divide in any way you'd like, here's the link for the options:
  //http://root.cern.ch/root/html528/TGraphAsymmErrors.html (Wilson, CP, etc)
  eff_graph->BayesDivide(HAll1D[0][0],HAll1D[0][1]);
  eff_graph->SetTitle(";DSA Track p_{T} [GeV];Efficiency");
  //gr_style(eff_graph,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.,1);
  eff_graph->SetMarkerStyle(20);
  eff_graph->SetMarkerColor(1);
  eff_graph->SetMarkerSize(1);
  eff_graph->GetXaxis()->SetRangeUser(0,200);
  //eff_graph->GetYaxis()->SetRangeUser(0.5,1.2);
  //eff_graph->GetYaxis()->SetRangeUser(0.,1.2);
  eff_graph->GetYaxis()->SetRangeUser(0.,1.5);



  TGraphAsymmErrors* effMC_graph = new TGraphAsymmErrors();
  effMC_graph->BayesDivide(HAll1D[1][0],HAll1D[1][1]);
  effMC_graph->SetTitle(";DSA Track p_{T} [GeV];Efficiency");
  //gr_style(effMC_graph,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.,1);
  effMC_graph->SetMarkerStyle(21);
  effMC_graph->SetMarkerColor(2);
  effMC_graph->SetMarkerSize(1);
  effMC_graph->GetXaxis()->SetRangeUser(0,200);
  //effMC_graph->GetYaxis()->SetRangeUser(0.5,1.2);
  effMC_graph->GetYaxis()->SetRangeUser(0.,1.5);

  TGraphAsymmErrors* effsigMC100_graph = new TGraphAsymmErrors();
  effsigMC100_graph->BayesDivide(HAll1D[2][0],HAll1D[2][1]);
  effsigMC100_graph->SetTitle(";DSA Track p_{T} [GeV];Efficiency");
  //gr_style(effsigMC100_graph,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.,1);
  effsigMC100_graph->SetMarkerStyle(22);
  effsigMC100_graph->SetMarkerColor(4);
  effsigMC100_graph->SetMarkerSize(1);
  effsigMC100_graph->GetXaxis()->SetRangeUser(0,200);
  //effsigMC100_graph->GetYaxis()->SetRangeUser(0.5,1.2);
  effsigMC100_graph->GetYaxis()->SetRangeUser(0.,1.4);

  TGraphAsymmErrors* effsigMC500_graph = new TGraphAsymmErrors();
  effsigMC500_graph->BayesDivide(HAll1D[3][0],HAll1D[3][1]);
  effsigMC500_graph->SetTitle(";DSA Track p_{T} [GeV];Efficiency");
  //gr_style(effsigMC500_graph,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.,1);
  effsigMC500_graph->SetMarkerStyle(23);
  effsigMC500_graph->SetMarkerColor(6);
  effsigMC500_graph->SetMarkerSize(1);
  effsigMC500_graph->GetXaxis()->SetRangeUser(0,200);
  //effsigMC500_graph->GetYaxis()->SetRangeUser(0.5,1.2);
  effsigMC500_graph->GetYaxis()->SetRangeUser(0.,1.4);

  TGraphAsymmErrors* effsigMC1000_graph = new TGraphAsymmErrors();
  effsigMC1000_graph->BayesDivide(HAll1D[4][0],HAll1D[4][1]);
  effsigMC1000_graph->SetTitle(";DSA Track p_{T} [GeV];Efficiency");
  //gr_style(effsigMC1000_graph,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.,1);
  effsigMC1000_graph->SetMarkerStyle(24);
  effsigMC1000_graph->SetMarkerColor(8);
  effsigMC1000_graph->SetMarkerSize(1);
  effsigMC1000_graph->GetXaxis()->SetRangeUser(0,200);
  //effsigMC1000_graph->GetYaxis()->SetRangeUser(0.5,1.2);
  effsigMC1000_graph->GetYaxis()->SetRangeUser(0.,1.4);


  //Fitting with the error function with the form:
  //erf((m-m0)/sigma)+1)/2
  //DD: Change the range for the fitting yourself from 20 - 100 to your own (min,max)
  //TF1 * fit1 = new TF1("fit1","(TMath::Erf((x*[0] -[1])/[2])+1.)/2.",10.,200.);
  //fit1->SetParameter(2,1.);
  TF1 * fit1 = new TF1("fit1","pol0",40.,200.);
  fit1->SetLineColor(1);
  fit1->SetLineWidth(3);
  eff_graph->Fit(fit1,"R");
  //TF1 * fit2 = new TF1("fit2","(TMath::Erf((x*[0] -[1])/[2])+1.)/2.",10.,200.);
  //fit2->SetParameter(2,1.);
  TF1 * fit2 = new TF1("fit2","pol0",40.,200.);
  fit2->SetLineColor(kRed);
  fit2->SetLineWidth(3);
  //fit2->SetLineStyle(2);
  effMC_graph->Fit(fit2,"R");

  //Set up legends
  /*
  char* LegFile[NumFiles] = {"Collision Run2012A Data","Collision Run2012B period 1 Data","Collision Run2012B period 2 Data","Collision Run2012C-v1 Data","Collision Run2012C-v2 Data","Cosmic Data, Run 195155"};
  char LegEntry[100];
  Leg1 = new TLegend(0.60,0.8,0.95,0.98);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);
  */

  TPaveLabel *Leg2c = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012B period 2 Data","NDC");
  Leg2c->SetBorderSize(0);
  Leg2c->SetTextSize(0.7);
  Leg2c->SetFillColor(0);

  char* LegFile[NumFiles] = {"Control Trigger Data","Cosmic MC"};
  //char* LegFile[NumFiles] = {"Control Trigger Data","Cosmic MC","100 GeV mchamps","500 GeV mchamps","1000 GeV mchamps"};
  //char* LegFile[2] = {"Numerator","Denominator"};
  char LegEntry[100];
  Leg1 = new TLegend(0.2,0.72,0.38,0.84);
  
  sprintf(LegEntry,"%s",LegFile[0]);
  Leg1->AddEntry(eff_graph,LegEntry,"p");
  sprintf(LegEntry,"%s",LegFile[1]);
  Leg1->AddEntry(effMC_graph,LegEntry,"p");
  
  /*
  sprintf(LegEntry,"%s",LegFile[2]);
  Leg1->AddEntry(effsigMC100_graph,LegEntry,"p");
  sprintf(LegEntry,"%s",LegFile[3]);
  Leg1->AddEntry(effsigMC500_graph,LegEntry,"p");
  sprintf(LegEntry,"%s",LegFile[4]);
  Leg1->AddEntry(effsigMC1000_graph,LegEntry,"p");
  */
  /*
  sprintf(LegEntry,"%s",LegFile[0]);
  Leg1->AddEntry(HAll1D[0][0],LegEntry,"l");
  sprintf(LegEntry,"%s",LegFile[1]);
  Leg1->AddEntry(HAll1D[0][1],LegEntry,"l");
  */
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.035);
  Leg1->SetFillColor(0);


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    3.4 fb^{-1}","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    5.9 fb^{-1}","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);


  /*
  //scale Run2012B and cosmics histograms to Run2012A collision data
  Double_t scaleRun2012Bperiod1[Num1DHists];
  Double_t scaleRun2012Bperiod2[Num1DHists];
  Double_t scaleRun2012Cv1[Num1DHists];
  Double_t scaleRun2012Cv2[Num1DHists];
  Double_t scalecosmics[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
    scaleRun2012Bperiod1[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    scaleRun2012Bperiod2[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scaleRun2012Cv1[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[3][i]->GetSumOfWeights());
    scaleRun2012Cv2[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[4][i]->GetSumOfWeights());
    scalecosmics[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[5][i]->GetSumOfWeights());

    HAll1D[1][i]->Scale(scaleRun2012Bperiod1[i]);
    HAll1D[2][i]->Scale(scaleRun2012Bperiod2[i]);
    HAll1D[3][i]->Scale(scaleRun2012Cv1[i]);
    HAll1D[4][i]->Scale(scaleRun2012Cv2[i]);
    HAll1D[5][i]->Scale(scalecosmics[i]);
  }
  cout<<"scaled histograms"<<endl;
  */

  for (int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      //HAll1D[a][i]->GetYaxis()->SetRangeUser(1,300000);
    }
  }

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists], *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];

  for(int i=0; i<1; i++){
    canvases1D[i]->cd();
    cout<<"drawing canvas "<<i<<endl;
    
    eff_graph->Draw("AP");
    effMC_graph->Draw("Psame");
    /*
    effsigMC100_graph->Draw("AP");
    //effsigMC100_graph->Draw("Psame");
    effsigMC500_graph->Draw("Psame");
    effsigMC1000_graph->Draw("Psame");
    */
    //HAll1D[4][1]->Draw("hist");
    //HAll1D[4][0]->Draw("samehist");
    Leg1->Draw();
    //text1->Draw();
    CMS_lumi( canvases1D[i], iPeriod, iPos );

    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%s.eps",plot1D[i]);
    if (save_plots) canvases1D[i]->SaveAs("../../plots/StoppedHSCPMuon/RecoData/TriggerTurnOn/turnon_Run2012C_ControlTrigger.eps");

  }

}
