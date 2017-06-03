{
  //overlays histograms, saves eps files

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
  //gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  //bool save_plots = false;
  bool save_plots = true;

  //const int NumFiles = 4;
  const int NumFiles = 3;
  
  //TFile f1("/afs/cern.ch/user/j/jalimena/public/histos/stoppedHSCPMuonHistos_stop600_neutralino200_without_bx_cut_without_other_cut_withouttrigger.root");
  //TFile f2("/afs/cern.ch/user/j/jalimena/public/histos/stoppedHSCPMuonHistos_stop600_neutralino200_without_bx_cut_without_other_cut_withtrigger.root");
  //TFile f3("/afs/cern.ch/user/j/jalimena/public/histos/stoppedHSCPMuonHistos_stop600_neutralino200_without_bx_cut_with_other_cut_withtrigger.root");                                                  
  /*
  TFile f1("/home/alimena/histos/stoppedHSCPMuonHistos_stop200_neutralino75_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  //TFile f2("/home/alimena/histos/stoppedHSCPMuonHistos_stop300_neutralino109_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f2("/home/alimena/histos/stoppedHSCPMuonHistos_stop600_neutralino417_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f3("/home/alimena/histos/stoppedHSCPMuonHistos_stop1000_neutralino819_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  */

  
  TFile f1("/home/alimena/histos/stoppedHSCPMuonHistos_gluino300_neutralino173_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f2("/home/alimena/histos/stoppedHSCPMuonHistos_gluino900_neutralino794_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f3("/home/alimena/histos/stoppedHSCPMuonHistos_gluino1500_neutralino1396_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  

  /*
  TFile f1("/home/alimena/histos/stoppedHSCPMuonHistos_mchamp100_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f2("/home/alimena/histos/stoppedHSCPMuonHistos_mchamp500_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f3("/home/alimena/histos/stoppedHSCPMuonHistos_mchamp1000_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  */

  /*
  TFile f1("/home/alimena/histos/stoppedHSCPMuonHistos_gmstau100_gravitinop0001_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f2("/home/alimena/histos/stoppedHSCPMuonHistos_gmstau247_gravitinop0001_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f3("/home/alimena/histos/stoppedHSCPMuonHistos_gmstau494_gravitinop0001_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  */

  /*    
  TFile f1("/home/alimena/histos/stoppedHSCPMuonHistos_ppstau100_gravitinop0001_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f2("/home/alimena/histos/stoppedHSCPMuonHistos_ppstau247_gravitinop0001_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  TFile f3("/home/alimena/histos/stoppedHSCPMuonHistos_ppstau494_gravitinop0001_with_bx_cut_with_cavern_cut_with_generatorMuon_cut_with_other_cut_.root");
  */  
  

  //cout<<"Loaded file: "<<file<<endl;
  /*
  //info for each 1D plot
  //const int Num1DHists = 95;a
  //const int Num1DHists = 45;
  const int Num1DHists = 1;
  //const int Num1DHists = 16;
  char* plot1D[Num1DHists] = {

  };

  char* xtitle1D[Num1DHists] = {
    "Number of Generated Muons",
    "Generated Muon p_{T} [GeV]",
    "Generated Muon #eta",
    "Generated Muon #phi",
    "Generated Muon Charge",
    "Generated Muon Mass [GeV]"
  };
  */
  cout<<"ready for 1D hists"<<endl;

  //info for each 2D plot
  const int Num2DHists = 1;
  /*
  char* plot2D[Num2DHists] = {"muEta_muPhi_","muCosmicEta_muCosmicPhi_","muStandAloneEta_muStandAlonePhi_","muRefittedStandAloneEta_muRefittedStandAlonePhi_", "mu0_mu1_StandAloneTofTimeAtIpInOut_", "mu0_mu1_StandAloneTofTimeAtIpOutIn_"};
  char* xtitle2D[Num2DHists] = {"Reco Muon #eta","Cosmic Muon #eta","StandAlone Muon #eta","Refitted StandAlone Muon #eta","Time At IP for InOut for #phi<0 StandAlone Muon","Time At IP for OutIn for #phi<0 StandAlone Muon"};
  char* ytitle2D[Num2DHists] = {"Reco Muon #phi","Cosmic Muon #phi","StandAlone Muon #phi","Refitted StandAlone Muon #phi","Time At IP for InOut for #phi>0 StandAlone Muon","Time At IP for OutIn for #phi>0 StandAlone Muon"};
  */
  char* plot2D[Num2DHists] = {"mcStoppedParticleXY_"};
  char* xtitle2D[Num2DHists] = {"x position [cm]"};
  char* ytitle2D[Num2DHists] = {"y position [cm]"};
  cout<<"ready for 2D hists"<<endl;

  //set up canvases
  /*
  char Cname1D[200], Ctitle1D[500];
  TCanvas* canvases1D[Num1DHists];
  //TCanvas* canvases1D[17];
  for (int i=0; i<Num1DHists; i++){
    sprintf(Cname1D,"canvases1D[%i]",i);
    sprintf(Ctitle1D,"%s",plot1D[i]);
    canvases1D[i] = new TCanvas(Cname1D,Ctitle1D,10,10,700,500);
    if (i<89) canvases1D[i]->SetLogy();
    canvas_style(canvases1D[i]);
  }
  cout<<"made 1D canvases"<<endl;
  */
  
  char Cname2D[200], Ctitle2D[500];
  TCanvas* canvases2D[1.0*NumFiles*Num2DHists];
  for (int i=0; i<Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%sf1",plot2D[i]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=Num2DHists; i<2*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%sf2",plot2D[i-Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=2*Num2DHists; i<3*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%sf3",plot2D[i-2*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  cout<<"made 2D canvases"<<endl;


  //get histograms
  /*
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  for(int i=0; i<Num1DHists; i++){
    sprintf(oldH1Dname,"%shist",plot1D[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1Dname);
    HAll1D[1][i] = (TH1D*) f2.Get(oldH1Dname);
    HAll1D[2][i] = (TH1D*) f3.Get(oldH1Dname);
    //HAll1D[3][i] = (TH1D*) f4.Get(oldH1Dname);
  }
  */
  
  TH2D* HAll2D[NumFiles][Num2DHists];
  char oldH2Dname[100];
  for(int i=0; i<Num2DHists; i++){
    sprintf(oldH2Dname,"%shist",plot2D[i]);
    HAll2D[0][i] = (TH2D*) f1.Get(oldH2Dname);
    HAll2D[1][i] = (TH2D*) f2.Get(oldH2Dname);
    HAll2D[2][i] = (TH2D*) f3.Get(oldH2Dname);
  }
  
  cout<<"got histograms"<<endl;

  //put in histogram specifications
  int color[NumFiles] = {1,2,4};//,6};//,8};//,11};
  int style[NumFiles] = {1,2,3};//,4};//,5};//,6};
  int marker[NumFiles] = {20,21,22};//,23};//,24};//,25};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
    /*
    for(int i=0; i<Num1DHists; i++){
      sprintf(axistitles,";%s;Events",xtitle1D[i]);
      //cout<<"sprintf axis title"<<endl;
      HAll1D[a][i]->SetTitle(axistitles);
      //cout<<"set axis titles"<<endl;
      //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
      h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //cout<<"h1_style"<<endl;
      cout<<"xtitle1D[i] is: "<<xtitle1D[i]<<endl;
    }
    */
    
    for(int i=0; i<Num2DHists; i++){
      sprintf(axistitles,";%s;%s",xtitle2D[i],ytitle2D[i]);
      HAll2D[a][i]->SetTitle(axistitles);
      //HAll2D[a][i]->GetYaxis()->SetTitle("Events");
      h2_style(HAll2D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      cout<<"xtitle2D[i] is: "<<xtitle2D[i]<<endl;
    }
    
  }

  //sumw2 for correct error bars
  for(int a=0; a<NumFiles; a++){
    /*
    for(int i=0; i<Num1DHists; i++){
      HAll1D[a][i]->Sumw2();
    }
    */    
    for(int i=0; i<Num2DHists; i++){
      HAll2D[a][i]->Sumw2();
    }    
  }


  for (int a=0; a<NumFiles; a++){
    //HAll1D[a][1]->Rebin(2);
    //HAll1D[a][4]->Rebin(2);

    //HAll1D[a][1]->GetXaxis()->SetRangeUser(0,200); //for stops
    //HAll1D[a][1]->GetXaxis()->SetRangeUser(0,50); //for gluinos
    //HAll1D[a][1]->GetXaxis()->SetRangeUser(0,600); //for mchamps
    //HAll1D[a][1]->GetXaxis()->SetRangeUser(0,300); //for staus


    //HAll1D[a][0]->GetXaxis()->SetRangeUser(0,10);
    //HAll1D[a][4]->GetXaxis()->SetRangeUser(0,20);

    for(int i=0; i<Num2DHists; i++){
      HAll2D[a][i]->GetXaxis()->SetRangeUser(-1000,1000);
      HAll2D[a][i]->GetYaxis()->SetRangeUser(-1000,1000);
      //eta plots
      //HAll2D[a][i]->RebinX(4);
    }
    /*
    //2D timing plots
    HAll2D[a][4]->RebinX(10);
    HAll2D[a][5]->RebinX(10);
    HAll2D[a][4]->RebinY(10);
    HAll2D[a][5]->RebinY(10);

    HAll2D[a][4]->GetXaxis()->SetRangeUser(-50,50);
    HAll2D[a][4]->GetYaxis()->SetRangeUser(-50,50);
    */
  }    
  cout<<"put in histogram specs"<<endl;

  
  //Set up legends
  /*
  //char* LegFile[NumFiles] = {"Without trigger cut","With trigger cut"};//,"With trigger and other cuts"};
  //char* LegFile[NumFiles] = {"#tilde{t_{1}} 500 GeV","#tilde{g} 500 GeV","H^{++} 500 GeV","GMSB #tilde{#tau_{1}} 494 GeV","PP #tilde{#tau_{1}} 494 GeV"};
  //char* LegFile[NumFiles] = {"#tilde{t_{1}} 200 GeV","#tilde{t_{1}} 600 GeV","#tilde{t_{1}} 1000 GeV"};
  char* LegFile[NumFiles] = {"#tilde{t_{1}} 200 GeV","#tilde{t_{1}} 300 GeV","#tilde{t_{1}} 600 GeV","#tilde{t_{1}} 1000 GeV"};
  //char* LegFile[NumFiles] = {"#tilde{g} 300 GeV","#tilde{g} 900 GeV","#tilde{g} 1500 GeV"};
  //char* LegFile[NumFiles] = {"H^{++} 100 GeV","H^{++} 500 GeV","H^{++} 1000 GeV"};
  //char* LegFile[NumFiles] = {"GMSB #tilde{#tau_{1}} 100 GeV","GMSB #tilde{#tau_{1}} 247 GeV","GMSB #tilde{#tau_{1}} 494 GeV"};
  //char* LegFile[NumFiles] = {"PP #tilde{#tau_{1}} 100 GeV","PP #tilde{#tau_{1}} 247 GeV","PP #tilde{#tau_{1}} 494 GeV"};
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
  /*
  Leg2 = new TLegend(0.60,0.8,0.95,0.98);
  //Leg2->AddEntry(HAll1D[a][0],"Without trigger cut, with ,"l");
  Leg2->SetBorderSize(0);
  Leg2->SetTextSize(0.03);
  Leg2->SetFillColor(0);
  */
  /*
  TPaveLabel *Leg2a = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012A Data","NDC");
  Leg2a->SetBorderSize(0);
  Leg2a->SetTextSize(0.7);
  Leg2a->SetFillColor(0);

  TPaveLabel *Leg2b = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012B period 1 Data","NDC");
  Leg2b->SetBorderSize(0);
  Leg2b->SetTextSize(0.7);
  Leg2b->SetFillColor(0);

  TPaveLabel *Leg2c = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012B period 2 Data","NDC");
  Leg2c->SetBorderSize(0);
  Leg2c->SetTextSize(0.7);
  Leg2c->SetFillColor(0);

  TPaveLabel *Leg2d = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012C-v1 Data","NDC");
  Leg2d->SetBorderSize(0);
  Leg2d->SetTextSize(0.7);
  Leg2d->SetFillColor(0);

  TPaveLabel *Leg2e = new TPaveLabel(.19,.92,.39,.99,"Collision Run2012C-v2 Data","NDC");
  Leg2e->SetBorderSize(0);
  Leg2e->SetTextSize(0.7);
  Leg2e->SetFillColor(0);

  TPaveLabel *Leg2f = new TPaveLabel(.19,.92,.39,.99,"Cosmic Data, Run 195155","NDC");
  Leg2f->SetBorderSize(0);
  Leg2f->SetTextSize(0.7);
  Leg2f->SetFillColor(0);
  */


  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    Simulation","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);
  /*
  //scale to guest's
  Double_t scalef2[Num1DHists];
  Double_t scalef3[Num1DHists];
  Double_t scalef4[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
    scalef2[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());
    scalef3[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scalef4[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[3][i]->GetSumOfWeights());

    HAll1D[1][i]->Scale(scalef2[i]);
    HAll1D[2][i]->Scale(scalef3[i]);
    HAll1D[3][i]->Scale(scalef4[i]);
  }
  cout<<"scaled histograms"<<endl;
  */

  /*
  for (int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      if(i==0 || i==5) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,100000); //for stops, mchamps
      if(i==1) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,10000); //for stops, mchamps
      if(i==2 || i==3) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,3000); //for stops, mchamps
      if(i==4) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,300000); //for stops, mchamps

      //if(i==0 || i==5) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,3000); //for gluinos
      //if(i==1) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,400); //for gluinos
      //if(i==2 || i==3) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,100); //for gluinos
      //if(i==4) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,3000); //for gluinos

      //if(i==0 || i==5) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,10000); //for staus
      //if(i==1 || i==2 || i==3) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,1000); //for staus
      //if(i==4) HAll1D[a][i]->GetYaxis()->SetRangeUser(1,30000); //for staus
    }
  }
  */

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  //TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists];//, *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];

  //for(int i=0; i<Num1DHists; i++){
  //for(int i=1; i<Num1DHists; i++){
  //for(int i=0; i<17; i++){
    /*
    canvases1D[i]->cd();
    cout<<"drawing canvas "<<i<<endl;
    HAll1D[1][i]->Draw("hists");
    HAll1D[0][i]->Draw("sameshist");
    HAll1D[2][i]->Draw("sameshist");
    HAll1D[3][i]->Draw("sameshist");
    */
    /*
    else if (i==8 || i==9 || i==89 || i==90 || i==91 || i==92 || i==93 || i==94){
      HAll1D[4][i]->Draw();
      HAll1D[3][i]->Draw("sames");
      HAll1D[2][i]->Draw("sames");
      HAll1D[1][i]->Draw("sames");
      HAll1D[0][i]->Draw("sames");
    }
    else {
    */
    //HAll1D[0][i]->Draw("hists");
    //HAll1D[1][i]->Draw("sameshist");
      //HAll1D[2][i]->Draw("sameshist");
      //}
    //Leg1->Draw();
      /*
      gPad->Update();
      stats0[i] = (TPaveStats*)HAll1D[0][i]->GetListOfFunctions()->FindObject("stats");
      stats0[i]->SetY1NDC(.7); //move stats box
      stats0[i]->SetY2NDC(.8);
      stats0[i]->SetX1NDC(.75);
      stats0[i]->SetBorderSize(0);
      stats1[i] = (TPaveStats*)HAll1D[1][i]->GetListOfFunctions()->FindObject("stats");
      stats1[i]->SetY1NDC(.6); //move stats box
      stats1[i]->SetY2NDC(.7);
      stats1[i]->SetX1NDC(.75);
      stats1[i]->SetTextColor(2);
      stats1[i]->SetBorderSize(0);
      */
      /*
      stats2[i] = (TPaveStats*)HAll1D[2][i]->GetListOfFunctions()->FindObject("stats");
      stats2[i]->SetY1NDC(.5); //move stats box
      stats2[i]->SetY2NDC(.6);
      stats2[i]->SetX1NDC(.75);
      stats2[i]->SetTextColor(4);
      stats2[i]->SetBorderSize(0);
      */
    /*
    stats3[i] = (TPaveStats*)HAll1D[3][i]->GetListOfFunctions()->FindObject("stats");
    stats3[i]->SetY1NDC(.4); //move stats box
    stats3[i]->SetY2NDC(.5);
    stats3[i]->SetX1NDC(.75);
    stats3[i]->SetTextColor(6);
    stats3[i]->SetBorderSize(0);
    stats4[i] = (TPaveStats*)HAll1D[4][i]->GetListOfFunctions()->FindObject("stats");
    stats4[i]->SetY1NDC(.3); //move stats box
    stats4[i]->SetY2NDC(.4);
    stats4[i]->SetX1NDC(.75);
    stats4[i]->SetTextColor(8);
    stats4[i]->SetBorderSize(0);
      */

    //text1->Draw();


    //sprintf(canvasesEPS,"../../plots/StoppedHSCPMuon/RecoData/signalMC/stops/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../../plots/StoppedHSCPMuon/RecoData/signalMC/gluinos/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../../plots/StoppedHSCPMuon/RecoData/signalMC/mchamps/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../../plots/StoppedHSCPMuon/RecoData/signalMC/gmstaus/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../../plots/StoppedHSCPMuon/RecoData/signalMC/ppstaus/%s.eps",plot1D[i]);
    //if (save_plots) canvases1D[i]->SaveAs(canvasesEPS);

  //}


  for(int i=0; i<Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[0][i]->Draw("colz");
    //Leg2a->Draw();
    text1->Draw();
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/stops/%sstop200_neutralino75.eps",plot2D[i]);
    sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/gluinos/%sgluino300_neutralino173.eps",plot2D[i]);
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/mchamps/%smchamp100.eps",plot2D[i]);
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/gmstaus/%sgmstau100_gravitinop0001.eps",plot2D[i]);
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/ppstaus/%sppstau100_gravitinop0001.eps",plot2D[i]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=Num2DHists; i<2*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[1][i-Num2DHists]->Draw("colz");
    //Leg2b->Draw();
    text1->Draw();
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/stops/%sstop600_neutralino417.eps",plot2D[i-Num2DHists]);
    sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/gluinos/%sgluino900_neutralino794.eps",plot2D[i-Num2DHists]);
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/mchamps/%smchamp500.eps",plot2D[i-Num2DHists]);
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/gmstaus/%sgmstau247_gravitinop0001.eps",plot2D[i-Num2DHists]);
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/ppstaus/%sppstau247_gravitinop0001.eps",plot2D[i-Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=2*Num2DHists; i<3*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[2][i-2*Num2DHists]->Draw("colz");
    //Leg2c->Draw();
    text1->Draw();
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/stops/%sstop1000_neutralino819.eps",plot2D[i-2*Num2DHists]);
    sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/gluinos/%sgluino1500_neutralino1396.eps",plot2D[i-2*Num2DHists]);
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/mchamps/%smchamp1000.eps",plot2D[i-2*Num2DHists]);
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/gmstaus/%sgmstau494_gravitinop0001.eps",plot2D[i-2*Num2DHists]);
    //sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/signalMC/ppstaus/%sppstau494_gravitinop0001.eps",plot2D[i-2*Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }

}
