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
  //cout<<"Loaded files: "<<endl;

  //info for each 1D plot
  const int NumHists = 1;
  char* plot[NumHists] = {"_0MCpid"};
  char* xtitle[NumHists] = {"MC PDG Id Number if p_{T}, #eta, or #phi == 0. (high)"};

  //set up canvases
  char Cname[25], Ctitle[100];
  TCanvas* canvases[NumHists];
  for (int i=0; i<NumHists; i++){
    sprintf(Cname,"canvases[%i]",i);
    sprintf(Ctitle,"%s",plot[i]);
    canvases[i] = new TCanvas(Cname,Ctitle,10,10,700,500);
    canvas_style(canvases[i]);
  }
  //cout<<"made canvases"<<endl;

  //get histograms
  TH1F* HAll[NumFiles][NumHists]; 
  char oldHname[100];
  for(int i=0; i<NumHists; i++){
      sprintf(oldHname,"%shist",plot[i]);
      HAll[0][i] = (TH1F*) f1.Get(oldHname);
      HAll[1][i] = (TH1F*) f2.Get(oldHname);
      HAll[2][i] = (TH1F*) f3.Get(oldHname);
  }
  //cout<<"made histos"<<endl;

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
    HAll[a][0]->GetXaxis()->SetRangeUser(1000000,1000030);
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

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[NumHists], *stats1[NumHists], *stats2[NumHists];

  for(int i=0; i<NumHists; i++){
    canvases[i]->cd();
    HAll[1][i]->Draw();
    HAll[0][i]->Draw("sames");
    HAll[2][i]->Draw("sames");

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

    sprintf(canvasesEPS,"../plots/stauMCgenerator/MC0/%s_high.eps",plot[i]);
    if (save_plots) canvases[i]->SaveAs(canvasesEPS);
  }

}
