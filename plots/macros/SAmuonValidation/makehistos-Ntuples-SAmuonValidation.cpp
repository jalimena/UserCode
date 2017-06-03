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
  /////gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  //bool other_cut = false;
  bool other_cut = true;
  //bool bx_cut = false;
  bool bx_cut = true;
  bool save_plots = false;
  //bool save_plots = true;
  //bool set1 = false;
  bool set1 = true;
  bool set2 = false;
  //bool set2 = true;
  bool set3 = false;
  //bool set3 = true;
  bool set4 = false;
  //bool set4 = true;

  const int NumFiles = 2;
  
  if(!bx_cut && !other_cut){
    TFile f1("/afs/cern.ch/user/j/jalimena/public/histos/SAmuonValidation/stoppedHSCPMuonHistos_NoBPTX_Run2012B_period2_without_bx_cut_without_other_cut.root"); //collision data Run2012A, json file from Jul 16
    TFile f2("/afs/cern.ch/user/j/jalimena/public/histos/SAmuonValidation/stoppedHSCPMuonHistos_cosmics_195155_without_bx_cut_without_other_cut.root"); //cosmic run
  }
  if(bx_cut && other_cut){
    TFile f1("/afs/cern.ch/user/j/jalimena/public/histos/SAmuonValidation/stoppedHSCPMuonHistos_NoBPTX_Run2012B_period2_with_bx_cut_with_other_cut.root"); //collision data Run2012A, json file from Jul 16
    TFile f2("/afs/cern.ch/user/j/jalimena/public/histos/SAmuonValidation/stoppedHSCPMuonHistos_cosmics_195155_with_bx_cut_with_other_cut.root"); //cosmic run
  }
  if(bx_cut && !other_cut){
    //cout<<"opening right input files"<<endl;
    TFile f1("/afs/cern.ch/user/j/jalimena/public/histos/SAmuonValidation/stoppedHSCPMuonHistos_NoBPTX_Run2012B_period2_with_bx_cut_without_other_cut.root"); //collision data Run2012A, json file from Jul 16
    TFile f2("/afs/cern.ch/user/j/jalimena/public/histos/SAmuonValidation/stoppedHSCPMuonHistos_cosmics_195155_with_bx_cut_without_other_cut.root"); //cosmic run
  }

  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  //const int Num1DHists = 14;
    //char* plot1D[Num1DHists] = {
    /*
    "bx_", //0
    "bxWrtCollision_", //1
    "bxWrtBunch_", //2
    */

    if (set1){
      const int Num1DHists = 14;
      char* plot1D[Num1DHists] = {
	"muLower_StandAlonePt_", //0
	"muLower_StandAloneEta_", //1
	"muLower_StandAlonePhi_", //2
	"muLower_StandAloneTrackNormalizedChi2_", //3
	"muLower_StandAloneTrackDxy_", //4
	"muLower_StandAloneTrackDz_", //5
	"muLower_StandAloneTrackNHitsMuon_", //6
	"muLower_StandAloneTrackNHitsCsc_", //7
	"muLower_StandAloneTrackNHitsDt_", //8
	"muLower_StandAloneTrackNHitsRpc_", //9
	"muLower_StandAloneTrackNStations_", //10
	"muLower_StandAloneTrackNChambersCsc_", //11
	"muLower_StandAloneTrackNChambersDt_", //12
	"muLower_StandAloneTrackNChambersRpc_" //13
      };
    }

  if (set2){
    const int Num1DHists = 14;
    char* plot1D[Num1DHists] = {
      "muUpper_StandAlonePt_", //0
      "muUpper_StandAloneEta_", //1
      "muUpper_StandAlonePhi_", //2
      "muUpper_StandAloneTrackNormalizedChi2_", //3
      "muUpper_StandAloneTrackDxy_", //4
      "muUpper_StandAloneTrackDz_", //5
      "muUpper_StandAloneTrackNHitsMuon_", //6
      "muUpper_StandAloneTrackNHitsCsc_", //7
      "muUpper_StandAloneTrackNHitsDt_", //8
      "muUpper_StandAloneTrackNHitsRpc_", //9
      "muUpper_StandAloneTrackNStations_", //10
      "muUpper_StandAloneTrackNChambersCsc_", //11
      "muUpper_StandAloneTrackNChambersDt_", //12
      "muUpper_StandAloneTrackNChambersRpc_" //13
    };
  }

  if (set3){
    const int Num1DHists = 14;
    char* plot1D[Num1DHists] = {
      "muLower_RefittedStandAlonePt_", //0
      "muLower_RefittedStandAloneEta_", //1
      "muLower_RefittedStandAlonePhi_", //2
      "muLower_RefittedStandAloneTrackNormalizedChi2_", //3
      "muLower_RefittedStandAloneTrackDxy_", //4
      "muLower_RefittedStandAloneTrackDz_", //5
      "muLower_RefittedStandAloneTrackNHitsMuon_", //6
      "muLower_RefittedStandAloneTrackNHitsCsc_", //7
      "muLower_RefittedStandAloneTrackNHitsDt_", //8
      "muLower_RefittedStandAloneTrackNHitsRpc_", //9
      "muLower_RefittedStandAloneTrackNStations_", //10
      "muLower_RefittedStandAloneTrackNChambersCsc_", //11
      "muLower_RefittedStandAloneTrackNChambersDt_", //12
      "muLower_RefittedStandAloneTrackNChambersRpc_" //13
    };
  }
  
  if (set4){
    const int Num1DHists = 14;
    char* plot1D[Num1DHists] = {
      "muUpper_RefittedStandAlonePt_", //0
      "muUpper_RefittedStandAloneEta_", //1
      "muUpper_RefittedStandAlonePhi_", //2
      "muUpper_RefittedStandAloneTrackNormalizedChi2_", //3
      "muUpper_RefittedStandAloneTrackDxy_", //4
      "muUpper_RefittedStandAloneTrackDz_", //5
      "muUpper_RefittedStandAloneTrackNHitsMuon_", //6
      "muUpper_RefittedStandAloneTrackNHitsCsc_", //7
      "muUpper_RefittedStandAloneTrackNHitsDt_", //8
      "muUpper_RefittedStandAloneTrackNHitsRpc_", //9
      "muUpper_RefittedStandAloneTrackNStations_", //10
      "muUpper_RefittedStandAloneTrackNChambersCsc_", //11
      "muUpper_RefittedStandAloneTrackNChambersDt_", //12
      "muUpper_RefittedStandAloneTrackNChambersRpc_" //13
    };
  }


    /*
    "BX",
    "BX w.r.t. Collision",
    "BX w.r.t. Bunch",
    */

  if (set1){
    const int Num1DHists = 14;
    char* xtitle1D[Num1DHists] = {
      "Lower SA Muon p_{T} [GeV]",
      "Lower SA Muon #eta",
      "Lower SA Muon #phi",
      "Lower SA Muon Track #chi^{2}/dof",
      "Lower SA Muon Dxy",
      "Lower SA Muon Dz",
      "Number of Hits in Lower SA Muon Track",
      "Number of CSC Hits in Lower SA Muon Track",
      "Number of DT Hits in Lower SA Muon Track",
      "Number of RPC Hits in Lower SA Muon Track",
      "Number of Muon Stations in Lower SA Muon Track",
      "Number of CSC Chambers in Lower SA Muon Track",
      "Number of DT Chambers in Lower SA Muon Track",
      "Number of RPC Chambers in Lower SA Muon Track"
      };
    }

  if (set2){
    const int Num1DHists = 14;
    char* xtitle1D[Num1DHists] = {
      "Upper SA Muon p_{T} [GeV]",
      "Upper SA Muon #eta",
      "Upper SA Muon #phi",
      "Upper SA Muon Track #chi^{2}/dof",
      "Upper SA Muon Dxy",
      "Upper SA Muon Dz",
      "Number of Hits in Upper SA Muon Track",
      "Number of CSC Hits in Upper SA Muon Track",
      "Number of DT Hits in Upper SA Muon Track",
      "Number of RPC Hits in Upper SA Muon Track",
      "Number of Muon Stations in Upper SA Muon Track",
      "Number of CSC Chambers in Upper SA Muon Track",
      "Number of DT Chambers in Upper SA Muon Track",
      "Number of RPC Chambers in Upper SA Muon Track"
      };
    }
    
  if (set3){
    const int Num1DHists = 14;
    char* xtitle1D[Num1DHists] = {
      "Lower Refitted SA Muon p_{T} [GeV]",
      "Lower Refitted SA Muon #eta",
      "Lower Refitted SA Muon #phi",
      "Lower Refitted SA Muon Track #chi^{2}/dof",
      "Lower Refitted SA Muon Dxy",
      "Lower Refitted SA Muon Dz",
      "Number of Hits in Lower Refitted SA Muon Track",
      "Number of CSC Hits in Lower Refitted SA Muon Track",
      "Number of DT Hits in Lower Refitted SA Muon Track",
      "Number of RPC Hits in Lower Refitted SA Muon Track",
      "Number of Muon Stations in Lower Refitted SA Muon Track",
      "Number of CSC Chambers in Lower Refitted SA Muon Track",
      "Number of DT Chambers in Lower Refitted SA Muon Track",
      "Number of RPC Chambers in Lower Refitted SA Muon Track"
    };
  }

  if (set4){
    const int Num1DHists = 14;
    char* xtitle1D[Num1DHists] = {
      "Upper Refitted SA Muon p_{T} [GeV]",
      "Upper Refitted SA Muon #eta",
      "Upper Refitted SA Muon #phi",
      "Upper Refitted SA Muon Track #chi^{2}/dof",
      "Upper Refitted SA Muon Dxy",
      "Upper Refitted SA Muon Dz",
      "Number of Hits in Upper Refitted SA Muon Track",
      "Number of CSC Hits in Upper Refitted SA Muon Track",
      "Number of DT Hits in Upper Refitted SA Muon Track",
      "Number of RPC Hits in Upper Refitted SA Muon Track",
      "Number of Muon Stations in Upper Refitted SA Muon Track",
      "Number of CSC Chambers in Upper Refitted SA Muon Track",
      "Number of DT Chambers in Upper Refitted SA Muon Track",
      "Number of RPC Chambers in Upper Refitted SA Muon Track"
    };
  }
  cout<<"ready for 1D hists"<<endl;

  //info for each 2D plot
  if (set1 || set3) const int Num2DHists = 4;
  if (set2 || set4) const int Num2DHists = 14;


  if (set1){
    char* plot2D[Num2DHists] = {
      "muLower_StandAloneTrackNHitsRpc_muLower_StandAloneTrackNormalizedChi2_",
      "muUpper_StandAloneTrackNHitsRpc_muUpper_StandAloneTrackNormalizedChi2_",
      "muLower_StandAloneTrackNHitsRpc_muLower_StandAloneTrackNHitsDt_",
      "muUpper_StandAloneTrackNHitsRpc_muUpper_StandAloneTrackNHitsDt_"
    };
  }
  
  if (set2){
    char* plot2D[Num2DHists] = {
      "muLower_muUpper_StandAlonePt_",
      "muLower_muUpper_StandAloneEta_",
      "muLower_muUpper_StandAlonePhi_",
      "muLower_muUpper_StandAloneTrackNormalizedChi2_",
      "muLower_muUpper_StandAloneTrackDxy_",
      "muLower_muUpper_StandAloneTrackDz_",
      "muLower_muUpper_StandAloneTrackNHitsMuon_",
      "muLower_muUpper_StandAloneTrackNHitsCsc_",
      "muLower_muUpper_StandAloneTrackNHitsDt_",
      "muLower_muUpper_StandAloneTrackNHitsRpc_",
      "muLower_muUpper_StandAloneTrackNStations_",
      "muLower_muUpper_StandAloneTrackNChambersCsc_",
      "muLower_muUpper_StandAloneTrackNChambersDt_",
      "muLower_muUpper_StandAloneTrackNChambersRpc_"
    };
  }
  
  if (set3){
    char* plot2D[Num2DHists] = {
      "muLower_RefittedStandAloneTrackNHitsRpc_muLower_RefittedStandAloneTrackNormalizedChi2_",
      "muUpper_RefittedStandAloneTrackNHitsRpc_muUpper_RefittedStandAloneTrackNormalizedChi2_",
      "muLower_RefittedStandAloneTrackNHitsRpc_muLower_RefittedStandAloneTrackNHitsDt_",
      "muUpper_RefittedStandAloneTrackNHitsRpc_muUpper_RefittedStandAloneTrackNHitsDt_"
      };
  }
  
  if (set4){
    char* plot2D[Num2DHists] = {
      "muLower_muUpper_RefittedStandAlonePt_",
      "muLower_muUpper_RefittedStandAloneEta_",
      "muLower_muUpper_RefittedStandAlonePhi_",
      "muLower_muUpper_RefittedStandAloneTrackNormalizedChi2_",
      "muLower_muUpper_RefittedStandAloneTrackDxy_",
      "muLower_muUpper_RefittedStandAloneTrackDz_",
      "muLower_muUpper_RefittedStandAloneTrackNHitsMuon_",
      "muLower_muUpper_RefittedStandAloneTrackNHitsCsc_",
      "muLower_muUpper_RefittedStandAloneTrackNHitsDt_",
      "muLower_muUpper_RefittedStandAloneTrackNHitsRpc_",
      "muLower_muUpper_RefittedStandAloneTrackNStations_",
      "muLower_muUpper_RefittedStandAloneTrackNChambersCsc_",
      "muLower_muUpper_RefittedStandAloneTrackNChambersDt_",
      "muLower_muUpper_RefittedStandAloneTrackNChambersRpc_"
    };
  }
  
  if (set1){
    char* xtitle2D[Num2DHists] = {
      "Number of RPC Hits in Lower SA Muon Track",
      "Number of RPC Hits in Upper SA Muon Track",
      "Number of RPC Hits in Lower SA Muon Track",
      "Number of RPC Hits in Upper SA Muon Track"
    };
  }
  if (set2){
    char* xtitle2D[Num2DHists] = {
      "Lower SA Muon p_{T} [GeV]",
      "Lower SA Muon #eta",
      "Lower SA Muon #phi",
      "Lower SA Muon Track #chi^{2}/dof",
      "Lower SA Muon Dxy",
      "Lower SA Muon Dz",
      "Number of Hits in Lower SA Muon Track",
      "Number of CSC Hits in Lower SA Muon Track",
      "Number of DT Hits in Lower SA Muon Track",
      "Number of RPC Hits in Lower SA Muon Track",
      "Number of Muon Stations in Lower SA Muon Track",
      "Number of CSC Chambers in Lower SA Muon Track",
      "Number of DT Chambers in Lower SA Muon Track",
      "Number of RPC Chambers in Lower SA Muon Track"
    };
  }
  
  if (set3){
    char* xtitle2D[Num2DHists] = {
      "Number of RPC Hits in Lower Refitted SA Muon Track",
      "Number of RPC Hits in Upper Refitted SA Muon Track",
      "Number of RPC Hits in Lower Refitted SA Muon Track",
      "Number of RPC Hits in Upper Refitted SA Muon Track"
    };
    }
  
  if (set4){
    char* xtitle2D[Num2DHists] = {
      "Lower Refitted SA Muon p_{T} [GeV]",
      "Lower Refitted SA Muon #eta",
      "Lower Refitted SA Muon #phi",
      "Lower Refitted SA Muon Track #chi^{2}/dof",
      "Lower Refitted SA Muon Dxy",
      "Lower Refitted SA Muon Dz",
      "Number of Hits in Lower Refitted SA Muon Track",
      "Number of CSC Hits in Lower Refitted SA Muon Track",
      "Number of DT Hits in Lower Refitted SA Muon Track",
      "Number of RPC Hits in Lower Refitted SA Muon Track",
      "Number of Muon Stations in Lower Refitted SA Muon Track",
      "Number of CSC Chambers in Lower Refitted SA Muon Track",
      "Number of DT Chambers in Lower Refitted SA Muon Track",
      "Number of RPC Chambers in Lower Refitted SA Muon Track"
    };
  }
  
  if (set1){
    char* ytitle2D[Num2DHists] = {
      "#chi^{2}/dof of Lower SA Muon Track",
      "#chi^{2}/dof of Upper SA Muon Track",
      "Number of DT Hits of Lower SA Muon Track",
      "Number of DT Hits of Upper SA Muon Track"
    };
  }
  if (set2){
    char* ytitle2D[Num2DHists] = {
      "Upper SA Muon p_{T} [GeV]",
      "Upper SA Muon #eta",
      "Upper SA Muon #phi",
      "Upper SA Muon Track #chi^{2}/dof",
      "Upper SA Muon Dxy",
      "Upper SA Muon Dz",
      "Number of Hits in Upper SA Muon Track",
      "Number of CSC Hits in Upper SA Muon Track",
      "Number of DT Hits in Upper SA Muon Track",
      "Number of RPC Hits in Upper SA Muon Track",
      "Number of Muon Stations in Upper SA Muon Track",
      "Number of CSC Chambers in Upper SA Muon Track",
      "Number of DT Chambers in Upper SA Muon Track",
      "Number of RPC Chambers in Upper SA Muon Track"
    };
  }
  if (set3){
    char* ytitle2D[Num2DHists] = {
      "#chi^{2}/dof of Lower Refitted SA Muon Track",
      "#chi^{2}/dof of Upper Refitted SA Muon Track",
      "Number of DT Hits of Lower Refitted SA Muon Track",
      "Number of DT Hits of Upper Refitted SA Muon Track"
    };
  }
  if (set4){
    char* ytitle2D[Num2DHists] = {
      "Upper Refitted SA Muon p_{T} [GeV]",
      "Upper Refitted SA Muon #eta",
      "Upper Refitted SA Muon #phi",
      "Upper Refitted SA Muon Track #chi^{2}/dof",
      "Upper Refitted SA Muon Dxy",
      "Upper Refitted SA Muon Dz",
      "Number of Hits in Upper Refitted SA Muon Track",
      "Number of CSC Hits in Upper Refitted SA Muon Track",
      "Number of DT Hits in Upper Refitted SA Muon Track",
      "Number of RPC Hits in Upper Refitted SA Muon Track",
      "Number of Muon Stations in Upper Refitted SA Muon Track",
      "Number of CSC Chambers in Upper Refitted SA Muon Track",
      "Number of DT Chambers in Upper Refitted SA Muon Track",
      "Number of RPC Chambers in Upper Refitted SA Muon Track"
    };
  }
  
  
  cout<<"ready for 2D hists"<<endl;

  //set up canvases
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

  
  char Cname2D[200], Ctitle2D[500];
  TCanvas* canvases2D[1.0*NumFiles*Num2DHists];
  for (int i=0; i<Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondata",plot2D[i]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=1*Num2DHists; i<1.0*NumFiles*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scosmicdata",plot2D[i-1*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  cout<<"made 2D canvases"<<endl;

  //get histograms
  TH1D* HAll1D[NumFiles][Num1DHists];
  char oldH1Dname[100];
  for(int i=0; i<Num1DHists; i++){
    sprintf(oldH1Dname,"%shist",plot1D[i]);
    HAll1D[0][i] = (TH1D*) f1.Get(oldH1Dname);
    HAll1D[1][i] = (TH1D*) f2.Get(oldH1Dname);
  }

  TH2D* HAll2D[NumFiles][Num2DHists];
  char oldH2Dname[100];
  for(int i=0; i<Num2DHists; i++){
    sprintf(oldH2Dname,"%shist",plot2D[i]);
    HAll2D[0][i] = (TH2D*) f1.Get(oldH2Dname);
    HAll2D[1][i] = (TH2D*) f2.Get(oldH2Dname);
  }
  cout<<"got histograms"<<endl;

  //put in histogram specifications
  int color[NumFiles] = {1,2};//,4,6,8};
  int style[NumFiles] = {1,2};//,3,4,5};
  int marker[NumFiles] = {20,21};//,22,23,24};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
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
    for(int i=0; i<Num2DHists; i++){
      sprintf(axistitles,";%s;%s",xtitle2D[i],ytitle2D[i]);
      HAll2D[a][i]->SetTitle(axistitles);
      //HAll2D[a][i]->GetYaxis()->SetTitle("Events");
      h2_style(HAll2D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //cout<<"xtitle2D[i] is: "<<xtitle2D[i]<<endl;
    }
  }

  //sumw2 for correct error bars
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      HAll1D[a][i]->Sumw2();
    }
    for(int i=0; i<Num2DHists; i++){
      HAll2D[a][i]->Sumw2();
    }
  }


  //for (int a=0; a<NumFiles; a++){
    //HAll1D[a][89]->Rebin(10);

    //HAll1D[a][89]->GetXaxis()->SetRangeUser(-50,50);

    //2D timing plots
    //HAll2D[a][4]->RebinX(10);
    //HAll2D[a][5]->RebinX(10);
    //HAll2D[a][4]->RebinY(10);
    //HAll2D[a][5]->RebinY(10);
    //}    
  cout<<"put in histogram specs"<<endl;

  
  //Set up legends
  char* LegFile[NumFiles] = {"Collision Data","Cosmic Data, Run 195155"};
  char LegEntry[100];
  Leg1 = new TLegend(0.60,0.8,0.95,0.98);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);

  TPaveLabel *Leg2a = new TPaveLabel(.19,.92,.39,.99,"Collision Data","NDC");
  Leg2a->SetBorderSize(0);
  Leg2a->SetTextSize(0.7);
  Leg2a->SetFillColor(0);

  TPaveLabel *Leg2b = new TPaveLabel(.19,.92,.39,.99,"Cosmic Data, Run 195155","NDC");
  Leg2b->SetBorderSize(0);
  Leg2b->SetTextSize(0.7);
  Leg2b->SetFillColor(0);



  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    3.4 fb^{-1}","NDC");
  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    5.9 fb^{-1}","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);



  //scale cosmics histograms to collision data
  Double_t scalecosmics[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
    scalecosmics[i] = (1.0*(Double_t)HAll1D[0][i]->GetSumOfWeights())/((Double_t)HAll1D[1][i]->GetSumOfWeights());

    HAll1D[1][i]->Scale(scalecosmics[i]);
  }
  cout<<"scaled histograms"<<endl;

  /*
  for (int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      HAll1D[a][i]->GetYaxis()->SetRangeUser(1,300000);
    }
  }
  */

  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[Num1DHists], *stats1[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
  //for(int i=0; i<17; i++){
    canvases1D[i]->cd();
    cout<<"drawing canvas "<<i<<endl;
    /*
    if (i<3){
      HAll1D[1][i]->Draw();
      HAll1D[0][i]->Draw("sames");
      HAll1D[2][i]->Draw("sames");
      HAll1D[3][i]->Draw("sames");
      HAll1D[4][i]->Draw("sames");
    }
    else if (i==8 || i==9 || i==89 || i==90 || i==91 || i==92 || i==93 || i==94){
      HAll1D[4][i]->Draw();
      HAll1D[3][i]->Draw("sames");
      HAll1D[2][i]->Draw("sames");
      HAll1D[1][i]->Draw("sames");
      HAll1D[0][i]->Draw("sames");
    }
    else {
    */
      HAll1D[0][i]->Draw("hist");
      HAll1D[1][i]->Draw("samehist");
      //}

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

    Leg1->Draw();
    text1->Draw();

    sprintf(canvasesEPS,"../../plots/StoppedHSCPMuon/RecoData/cosmic_collision/SAmuonValidation/%s.eps",plot1D[i]);
    if (save_plots) canvases1D[i]->SaveAs(canvasesEPS);

  }


  for(int i=0; i<Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[0][i]->Draw("colz");
    Leg2a->Draw();
    text1->Draw();
    sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/cosmic_collision/SAmuonValidation/%scollisiondata.eps",plot2D[i]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  for(int i=1*Num2DHists; i<1.0*NumFiles*Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[2][i-1*Num2DHists]->Draw("colz");
    Leg2b->Draw();
    text1->Draw();
    sprintf(canvasesEPS2D,"../../plots/StoppedHSCPMuon/RecoData/cosmic_collision/SAmuonValidation/%scosmicdata.eps",plot2D[i-1*Num2DHists]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }


}
