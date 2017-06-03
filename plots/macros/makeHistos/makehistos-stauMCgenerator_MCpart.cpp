{
  using namespace std;

  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  gROOT->LoadMacro("./style.cpp");
  global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  gStyle->SetOptStat("emrou"); //print entries, mean, rms, overflow, underflow
  //gStyle->SetStatW(.1);
  gStyle->SetStatH(.1);
  gStyle->SetTitleW(0.65);
  gStyle->SetTitleH(0.07);

  //bool save_plots = false;
  bool save_plots = true;

  const int NumFiles = 3;
  TFile f1("/afs/cern.ch/user/j/jalimena/private/keep/stau_HLThistos/stau100.root");
  TFile f2("/afs/cern.ch/user/j/jalimena/private/keep/stau_HLThistos/stau200.root");
  TFile f3("/afs/cern.ch/user/j/jalimena/private/keep/stau_HLThistos/stau308.root");

  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  const int NumHists = 10;
  char* plot[NumHists] = {"_Event","_NMCpart","_MCpid","_MCstatus","_MCpt","_MCeta","_MCphi","_MCvtxX","_MCvtxY","_MCvtxZ"};
  char* xtitle[NumHists] = {"Event Number","Number of MC Particles","MC PDG Id Number (low)","MC status","Generator p_{T} [GeV]","Generator #eta","Generator #phi","Generator x-coordinate of vertex [cm]","Generator y-coordinate of vertex [cm]","Generator z-coordinate of vertex [cm]"};

  //set up canvases
  char Cname[25], Ctitle[100];
  TCanvas* canvases[NumHists];
  for (int i=0; i<NumHists; i++){
    sprintf(Cname,"canvases[%i]",i);
    sprintf(Ctitle,"%s",plot[i]);
    canvases[i] = new TCanvas(Cname,Ctitle,10,10,700,500);
    if (i!=2 && i!=3) canvases[i]->SetLogy();
    canvas_style(canvases[i]);
  }

  //get histograms
  TH1F* HAll[NumFiles][NumHists]; 
  char oldHname[100];
  for(int i=0; i<NumHists; i++){
      sprintf(oldHname,"%shist",plot[i]);
      HAll[0][i] = (TH1F*) f1.Get(oldHname);
      HAll[1][i] = (TH1F*) f2.Get(oldHname);
      HAll[2][i] = (TH1F*) f3.Get(oldHname);
  }
 
  //put in histogram specifications
  int color[NumFiles] = {1,2,4};//,4,6};
  int style[NumFiles] = {1,2,3};//,4};
  int marker[NumFiles] = {20,21,22};//,23,24};
  char axistitles[100];
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<NumHists; i++){
      sprintf(axistitles,";%s;Events",xtitle[i]);
      HAll[a][i]->SetTitle(axistitles);
      //HAll[a][i]->GetYaxis()->SetTitle("Events");
      h1_style(HAll[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
    }
  }

  for (int a=0; a<NumFiles; a++){
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

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[NumHists], *stats1[NumHists], *stats2[NumHists];

  for(int i=0; i<NumHists; i++){
    canvases[i]->cd();
    if (i==2 || i==3){
      HAll[1][i]->Draw();
      HAll[0][i]->Draw("sames");
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

    sprintf(canvasesEPS,"../plots/stauMCgenerator/MCpart/%s.eps",plot[i]);
    if (save_plots) canvases[i]->SaveAs(canvasesEPS);
  }

}
