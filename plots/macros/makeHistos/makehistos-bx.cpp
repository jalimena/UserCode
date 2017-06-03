{
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
  //gStyle->SetOptStat("emrou"); //print entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); 
  //gStyle->SetStatW(.1);
  gStyle->SetStatH(.1);
  gStyle->SetTitleW(0.65);
  gStyle->SetTitleH(0.07);

  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("CMS_lumi.C");

  setTDRStyle();
  //tdrGrid(false, tdrStyle); 

  writeExtraText = true;
  extraText  = "Preliminary"; 

  //lumi_8TeV = "8, 13 TeV"; 
  //lumi_8TeV = ""; 
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
  //int iPos=0;
  int iPos=11;
  //int iPos=22; 

  bool save_plots = false;
  //bool save_plots = true;

  const int NumFiles = 1;
  //TFile f1("/afs/cern.ch/user/j/jalimena/public/Ntuples/stoppedHSCPMuonTree.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/public/histos/stoppedHSCPMuonHistos_NoBPTX_Run2012B_period2_with_bx_cut_with_other_cut.root");
  //TFile f1("/home/alimena/histos/stoppedHSCPMuonHistos_NoBPTX_Run2012B_period2_with_bx_cut_with_other_cut.root");
  TFile f1("/home/alimena/histos/NoBPTX_Run2012D_723patch1/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_woTriggerCut_wPtCut_wChaCut_woEtaCut_wUpperCut_wRpcCut_woDisStCut_woRpcBxCut__wDtHitsCut_wCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root");
  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  const int NumHists = 1;
  char* plot[NumHists] = {"bx_"};
  char* xtitle[NumHists] = {"BX"};

  //set up canvases
  char Cname[25], Ctitle[100];
  TCanvas* canvases[NumHists];
  for (int i=0; i<NumHists; i++){
    sprintf(Cname,"canvases[%i]",i);
    sprintf(Ctitle,"%s",plot[i]);
    canvases[i] = new TCanvas(Cname,Ctitle,10,10,575,500);
    //canvases[i]->SetLogy();
    //canvas_style(canvases[i]);
  }

  //get histograms
  TH1D* HAll[NumFiles][NumHists]; 
  char oldHname[100];
  for(int i=0; i<NumHists; i++){
      sprintf(oldHname,"%shist",plot[i]);
      HAll[0][i] = (TH1D*) f1.Get(oldHname);
  }
 
  //put in histogram specifications
  int color[NumFiles] = {1};//,2,4};//,4,6};
  int style[NumFiles] = {1};//,2,3};//,4};
  int marker[NumFiles] = {20};//,21,22};//,23,24};
  char axistitles[100];
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<NumHists; i++){
      sprintf(axistitles,";%s;Events/50 BX",xtitle[i]);
      HAll[a][i]->SetTitle(axistitles);
      //HAll[a][i]->GetYaxis()->SetTitle("Events");
      //h1_style(HAll[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
    }
  }
  HAll[0][0]->SetLineWidth(3);
  HAll[0][0]->SetTitleOffset(1.4,"Y");

  //for (int a=0; a<NumFiles; a++){

  //HAll[0][0]->GetYaxis()->SetRangeUser(.1,50000);
  HAll[0][0]->Rebin(50);

  HAll[0][0]->GetXaxis()->SetRangeUser(0,3600);
  HAll[0][0]->GetYaxis()->SetRangeUser(0,20000);
    //}
  /*

    HAll[a][7]->Rebin(5);
    HAll[a][8]->Rebin(5);
    HAll[a][9]->Rebin(5);

    HAll[a][2]->GetXaxis()->SetRangeUser(-20,120);
    //HAll[a][2]->GetXaxis()->SetRangeUser(1000000,1000030);
    HAll[a][4]->GetXaxis()->SetRangeUser(0,100);
    HAll[a][5]->GetXaxis()->SetRangeUser(-4.5,4.5);
    HAll[a][6]->GetXaxis()->SetRangeUser(-3.5,3.5);
    HAll[a][7]->GetXaxis()->SetRangeUser(-3000,3000);
    HAll[a][8]->GetXaxis()->SetRangeUser(-3000,3000);
    HAll[a][9]->GetXaxis()->SetRangeUser(-6000,6000);
  }    
  */

  /*
  //Set up legends
  char* LegFile[NumFiles] = {"100 GeV #tilde{#tau_{1}}","200 GeV #tilde{#tau_{1}}","308 GeV #tilde{#tau_{1}}"};
  char LegEntry[100];
  Leg1 = new TLegend(0.75,0.85,0.95,0.95);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll[a][0],LegEntry,"l");
  }
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);
 
  //scale histograms to 1
  //not for histos #0,1,2,3
  Double_t scalestau100[NumHists];
  Double_t scalestau200[NumHists];
  Double_t scalestau308[NumHists];

  for(int i=4; i<NumHists; i++){
    scalestau100[i] = 1.0/((Double_t)HAll[0][i]->GetSumOfWeights());
    scalestau200[i] = 1.0/((Double_t)HAll[1][i]->GetSumOfWeights());
    scalestau308[i] = 1.0/((Double_t)HAll[2][i]->GetSumOfWeights());

    HAll[0][i]->Scale(scalestau100[i]);
    HAll[1][i]->Scale(scalestau200[i]);
    HAll[2][i]->Scale(scalestau308[i]);
  }
  */

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  //TPaveStats *stats0[NumHists], *stats1[NumHists], *stats2[NumHists];

  for(int i=0; i<NumHists; i++){
    canvases[i]->cd();
    HAll[0][i]->Draw("hist");
    CMS_lumi( canvases[i], iPeriod, iPos );
    /*
    if (i==2 || i==3){
      HAll[1][i]->Draw();

      HAll[2][i]->Draw("sames");
    }
    else if (i<2){
      HAll[2][i]->Draw();
      for (int a=0; a<NumFiles-1; a++){
	HAll[a][i]->Draw("sames");
      }
    }
    else{
      HAll[0][i]->Draw();
      for (int a=1; a<NumFiles; a++){
	HAll[a][i]->Draw("sames");
      }
    }
    gPad->Update();
    stats0[i] = (TPaveStats*)HAll[0][i]->GetListOfFunctions()->FindObject("stats");
    stats0[i]->SetY1NDC(.7); //move stats box
    stats0[i]->SetY2NDC(0.85);
    stats0[i]->SetX1NDC(.75);
    stats1[i] = (TPaveStats*)HAll[1][i]->GetListOfFunctions()->FindObject("stats");
    stats1[i]->SetY1NDC(.55); //move stats box
    stats1[i]->SetY2NDC(.7);
    stats1[i]->SetX1NDC(.75);
    stats1[i]->SetTextColor(2);
    stats2[i] = (TPaveStats*)HAll[2][i]->GetListOfFunctions()->FindObject("stats");
    stats2[i]->SetY1NDC(.55); //move stats box
    stats2[i]->SetY2NDC(.4);
    stats2[i]->SetX1NDC(.75);
    stats2[i]->SetTextColor(4);
    Leg1->Draw();
    */
    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/collision_Run2012B/%s.eps",plot[i]);
    sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/collision_Run2012B/%szoom.eps",plot[i]);
    if (save_plots) canvases[i]->SaveAs(canvasesEPS);
  }

}
