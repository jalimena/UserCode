{
  //overlays histograms, saves eps files

  using namespace std;
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  gROOT->LoadMacro("style.cpp");
  global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  //gStyle->SetOptStat("emrou"); //entries, mean, rms, overflow, underflow
  gStyle->SetOptStat(0); //entries, mean, rms, overflow, underflow

  bool save_plots = false;
  //bool save_plots = true;

  //const int NumFiles = 5;
  //const int NumFiles = 6;
  //const int NumFiles = 7;
  //const int NumFiles = 16;
  const int NumFiles = 9;
  

  TFile f1 ("/home/alimena/histos/mchamp500_l1muons/wBxCut_wCavernCut_wGeneratorMuonCut_wSACut_woGenMuonMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosmicEnriched.root"); //no cuts, 53X

  TFile f2 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root"); //no cuts, 71X
  TFile f3 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_loose.root"); //loose, 71X
  TFile f4 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_medium.root"); //medium, 71X
  TFile f5 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_tight.root"); //tight, 71X


  TFile f6 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3_cosSeedSAreco/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_woEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root"); //no cuts, 71X, cosmic seed + SA reco
  TFile f7 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3_cosSeedSAreco/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_loose.root"); //loose, 71X, cosmic seed + SA reco
  TFile f8 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3_cosSeedSAreco/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_medium.root"); //medium, 71X, cosmic seed + SA reco
  TFile f9 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3_cosSeedSAreco/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_tight.root"); //tight, 71X, cosmic seed + SA reco


  /*
  TFile f6 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_wDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich.root"); //loose + dist stations cut, 71X
  TFile f7 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_dt1.root"); 
  TFile f8 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_dt2.root"); 
  TFile f9 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_woRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_dt3.root"); 
  TFile f10 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_rpc1.root"); 
  TFile f11 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_rpc2.root"); 
  TFile f12 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_rpc3.root"); 
  TFile f13 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_rpc4.root"); 
  TFile f14 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_wEtaCut_woUpperCut_wRpcCut_woDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_rpc5.root"); 
  TFile f15 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_wEtaCut_woUpperCut_woRpcCut_wDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_disSt1.root"); 
  TFile f16 ("/home/alimena/histos/mchamp500_710pre7_PRESTA71V3/wBxCut_wCavCut_wGenMuCut_wSACut_woGenMuMatchedCut_wTriggerCut_woPtCut_woChaCut_wEtaCut_woUpperCut_woRpcCut_wDisStCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosEnrich_disSt2.root"); 
  */

  //TFile f3 ("/home/alimena/histos/mchamp500_l1muons/wBxCut_wCavernCut_wGeneratorMuonCut_wSACut_woGenMuonMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosmicEnriched_loose.root"); //loose, 71X
  //TFile f4 ("/home/alimena/histos/mchamp500_l1muons/wBxCut_wCavernCut_wGeneratorMuonCut_wSACut_woGenMuonMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosmicEnriched_medium.root"); //medium, 71X
  //TFile f5 ("/home/alimena/histos/mchamp500_l1muons/wBxCut_wCavernCut_wGeneratorMuonCut_wSACut_woGenMuonMatchedCut_wTriggerCut_woPtCut_wChaCut_wEtaCut_woUpperCut_wRpcCut_woRpcBxCut_woDtHitsCut_woCscHitsCut_woDtInvBetaCut_woTimeInOutCut_woOppEtaCut_woOppPhiCut_woTightPhi_woCosmicEnriched_tight.root"); //tight, 71X



  //cout<<"Loaded file: "<<file<<endl;

  //info for each 1D plot
  const int Num1DHists = 14;
  char* plot1D[Num1DHists] = {
    "muStandAlonePt_", //1
    "muStandAloneEta_", //2
    "muStandAlonePhi_", //3
    "muStandAlonePtResolution_", //4
    "muRefittedStandAlonePt_", //5
    "muRefittedStandAloneEta_", //6
    "muRefittedStandAlonePhi_", //7
    "muRefittedStandAlonePtResolution_", //8
    "muCosmicPt_", //9
    "muCosmicEta_", //10
    "muCosmicPhi_", //11
    "muCosmicPtResolution_", //12
    "l1MuonPt_", //13
    "hlt20Cha2MuonPt_" //14
    //"mu0_StandAloneTrackNChambersDt_", //
    //"mu0_StandAloneTrackNChambersRpc_", //
  };

  char* xtitle1D[Num1DHists] = {
    "SA p_{T} [GeV]",
    "SA #eta",
    "SA #phi",
    "SA p_{T} Resolution",
    "RSA p_{T} [GeV]",
    "RSA #eta",
    "RSA #phi",
    "RSA p_{T} Resolution",
    "Cosmic p_{T} [GeV]",
    "Cosmic #eta",
    "Cosmic #phi",
    "Cosmic p_{T} Resolution",
    "L1 Muon p_{T} [GeV]",
    "L2 Muon p_{T} [GeV]"
  };
  cout<<"ready for 1D hists"<<endl;

  //info for each 2D plot
  const int Num2DHists = 3;
  /*
  char* plot2D[Num2DHists] = {"muEta_muPhi_","muCosmicEta_muCosmicPhi_","muStandAloneEta_muStandAlonePhi_","muRefittedStandAloneEta_muRefittedStandAlonePhi_", "mu0_mu1_StandAloneTofTimeAtIpInOut_", "mu0_mu1_StandAloneTofTimeAtIpOutIn_"};
  char* xtitle2D[Num2DHists] = {"Reco Muon #eta","Cosmic Muon #eta","StandAlone Muon #eta","Refitted StandAlone Muon #eta","Time At IP for InOut for #phi<0 StandAlone Muon","Time At IP for OutIn for #phi<0 StandAlone Muon"};
  char* ytitle2D[Num2DHists] = {"Reco Muon #phi","Cosmic Muon #phi","StandAlone Muon #phi","Refitted StandAlone Muon #phi","Time At IP for InOut for #phi>0 StandAlone Muon","Time At IP for OutIn for #phi>0 StandAlone Muon"};
  */
  char* plot2D[Num2DHists] = {"muStandAloneTrackNHitsRpc_muStandAloneTrackNormalizedChi2_","mu0_StandAloneTrackNHitsRpc_mu0_StandAloneTrackNormalizedChi2_","mu1_StandAloneTrackNHitsRpc_mu1_StandAloneTrackNormalizedChi2_"};
  char* xtitle2D[Num2DHists] = {"RPC Hits in SA Muon Track","RPC Hits in 1st SA Muon Track","RPC Hits in 2nd SA Muon Track"};
  char* ytitle2D[Num2DHists] = {"#chi^{2}/dof of SA Muon Track","#chi^{2}/dof of 1st SA Muon Track","#chi^{2}/dof of 2nd SA Muon Track"};
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

  /*
  char Cname2D[200], Ctitle2D[500];
  TCanvas* canvases2D[1.0*NumFiles*Num2DHists];
  for (int i=0; i<Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012A",plot2D[i]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=Num2DHists; i<2*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012Bperiod1",plot2D[i-Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=2*Num2DHists; i<3*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012Bperiod2",plot2D[i-2*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=3*Num2DHists; i<4*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012Cv1",plot2D[i-3*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=4*Num2DHists; i<1.0*5*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scollisiondataRun2012Cv2",plot2D[i-4*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  for (int i=5*Num2DHists; i<1.0*NumFiles*Num2DHists; i++){
    sprintf(Cname2D,"canvases2D[%i]",i);
    sprintf(Ctitle2D,"%scosmicdata",plot2D[i-5*Num2DHists]);
    canvases2D[i] = new TCanvas(Cname2D,Ctitle2D,10,10,700,500);
    canvases2D[i]->SetLogz();
    canvas_style(canvases2D[i]);
  }
  cout<<"made 2D canvases"<<endl;
  */

  TH1D* mcMuonPt_hist = (TH1D*) f2.Get("mcMuonPt_hist");

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
    HAll1D[5][i] = (TH1D*) f6.Get(oldH1Dname);
    HAll1D[6][i] = (TH1D*) f7.Get(oldH1Dname);
    HAll1D[7][i] = (TH1D*) f8.Get(oldH1Dname);
    HAll1D[8][i] = (TH1D*) f9.Get(oldH1Dname);
    /*
    HAll1D[9][i] = (TH1D*) f10.Get(oldH1Dname);
    HAll1D[10][i] = (TH1D*) f11.Get(oldH1Dname);
    HAll1D[11][i] = (TH1D*) f12.Get(oldH1Dname);
    HAll1D[12][i] = (TH1D*) f13.Get(oldH1Dname);
    HAll1D[13][i] = (TH1D*) f14.Get(oldH1Dname);
    HAll1D[14][i] = (TH1D*) f15.Get(oldH1Dname);
    HAll1D[15][i] = (TH1D*) f16.Get(oldH1Dname);
    */
  }

  /*
  TH2D* HAll2D[NumFiles][Num2DHists];
  char oldH2Dname[100];
  for(int i=0; i<Num2DHists; i++){
    sprintf(oldH2Dname,"%shist",plot2D[i]);
    HAll2D[0][i] = (TH2D*) f1.Get(oldH2Dname);
    HAll2D[1][i] = (TH2D*) f2.Get(oldH2Dname);
    //HAll2D[2][i] = (TH2D*) f3.Get(oldH2Dname);
  }
  */
  cout<<"got histograms"<<endl;

  /*
  for(int a=0; a<NumFiles; a++){
    UInt_t nx = HAll1D[a][17]->GetNbinsX()+1;
    Double_t *xbins= new Double_t[nx+1];
    for (UInt_t b=0;b<nx;b++) xbins[b]=HAll1D[a][17]->GetBinLowEdge(b+1);
    xbins[nx]=xbins[nx-1]+HAll1D[a][17]->GetBinWidth(nx);
    char *tempName= new char[strlen(HAll1D[a][17]->GetName())+10];
    sprintf(tempName,"%swtOverFlow",HAll1D[a][17]->GetName());
    // Book a temporary histogram having ab extra bin for overflows
    HAll1D[a][19] = new TH1D(tempName, HAll1D[a][17]->GetTitle(), nx, xbins);
    // Fill the new hitogram including the extra bin for overflows
    for (UInt_t b=1; b<=nx; b++) HAll1D[a][19]->Fill(HAll1D[a][19]->GetBinCenter(b), HAll1D[a][17]->GetBinContent(b));
    // Fill the underflows
    HAll1D[a][19]->Fill(HAll1D[a][17]->GetBinLowEdge(1)-1, HAll1D[a][17]->GetBinContent(0));
    // Restore the number of entries
    HAll1D[a][19]->SetEntries(HAll1D[a][17]->GetEntries());
  }
  cout<<"replaced histo to plot overflow bin"<<endl;
  */

  //put in histogram specifications
  int color[NumFiles] = {1,2,4,6,8,11,12,13,14};
  int style[NumFiles] = {1,2,3,4,5,6,7,8,9};
  int marker[NumFiles] = {20,21,22,23,24,25,26,27,28};
  char axistitles[200];
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      sprintf(axistitles,";%s;Events",xtitle1D[i]);
      //cout<<"sprintf axis title"<<endl;
      HAll1D[a][i]->SetTitle(axistitles);
      //cout<<"set axis titles"<<endl;
      //HAll1D[a][i]->GetYaxis()->SetTitle("Events");
      //h1_style(HAll1D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      h1_style(HAll1D[a][i],3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
      //cout<<"h1_style"<<endl;
      cout<<"xtitle1D[i] is: "<<xtitle1D[i]<<endl;
    }
    /*
    for(int i=0; i<Num2DHists; i++){
      sprintf(axistitles,";%s;%s",xtitle2D[i],ytitle2D[i]);
      HAll2D[a][i]->SetTitle(axistitles);
      //HAll2D[a][i]->GetYaxis()->SetTitle("Events");
      h2_style(HAll2D[a][i],3,color[a],style[a],1001,50,-1111.,-1111.,510,510,marker[a],color[a],1,1);
      //cout<<"xtitle2D[i] is: "<<xtitle2D[i]<<endl;
    }
    */
  }

  mcMuonPt_hist->Sumw2();
  //sumw2 for correct error bars
  for(int a=0; a<NumFiles; a++){
    for(int i=0; i<Num1DHists; i++){
      HAll1D[a][i]->Sumw2();
    }
    /*
    for(int i=0; i<Num2DHists; i++){
      HAll2D[a][i]->Sumw2();
    }
    */
  }

  //KS test
  for (int a=0; a<NumFiles; a++){
    double ks = mcMuonPt_hist->KolmogorovTest(HAll1D[a][4]);
    cout<<"KS prob for RSA pt and gen pt, for file "<<a<<" is: "<<ks<<endl;
  }  

  mcMuonPt_hist->Rebin(20);
  for (int a=0; a<NumFiles; a++){
    HAll1D[a][0]->Rebin(20);
    HAll1D[a][4]->Rebin(20);
    HAll1D[a][8]->Rebin(20);

    HAll1D[a][3]->GetXaxis()->SetRangeUser(-5,1);
    HAll1D[a][7]->GetXaxis()->SetRangeUser(-5,1);
    HAll1D[a][11]->GetXaxis()->SetRangeUser(-5,1);
    HAll1D[a][12]->GetXaxis()->SetRangeUser(0,150);
  }    
  cout<<"put in histogram specs"<<endl;

  
  //Set up legends
  //char* LegFile[NumFiles] = {"Without trigger cut","With trigger cut"};//,"With trigger and other cuts"};
  //char* LegFile[NumFiles] = {"#tilde{t_{1}} 500 GeV","#tilde{g} 500 GeV","H^{++} 500 GeV","GMSB #tilde{#tau_{1}} 494 GeV","PP #tilde{#tau_{1}} 494 GeV"};
  //char* LegFile[NumFiles] = {"#tilde{t_{1}} 200 GeV","#tilde{t_{1}} 600 GeV","#tilde{t_{1}} 1000 GeV"};
  //char* LegFile[NumFiles] = {"#tilde{g} 300 GeV","#tilde{g} 900 GeV","#tilde{g} 1500 GeV"};
  //char* LegFile[NumFiles] = {"H^{++} 100 GeV","H^{++} 500 GeV","H^{++} 1000 GeV"};
  //char* LegFile[NumFiles] = {"GMSB #tilde{#tau_{1}} 100 GeV","GMSB #tilde{#tau_{1}} 247 GeV","GMSB #tilde{#tau_{1}} 494 GeV"};
  //char* LegFile[NumFiles] = {"PP #tilde{#tau_{1}} 100 GeV","PP #tilde{#tau_{1}} 247 GeV","PP #tilde{#tau_{1}} 494 GeV"};
  //char* LegFile[NumFiles] = {"#tilde{t_{1}} 200 GeV","#tilde{t_{1}} 600 GeV","#tilde{t_{1}} 1000 GeV","Cosmic All-Phi Data"};
  //char* LegFile[NumFiles] = {"H^{++} 100 GeV","H^{++} 500 GeV","H^{++} 1000 GeV","Cosmic All-Phi Data"};
  //////char* LegFile[NumFiles] = {"53X, no cuts","71X, no cuts","71X, loose cuts","71X, medium cuts","71X, tight cuts","71X, loose + dist stations cuts"};
  //char* LegFile[NumFiles] = {"53X, no cuts","71X, no cuts","53X, loose cuts","53X, medium cuts","53X, tight cuts"};
  char* LegFile[NumFiles] = {"53X, no cuts","71X, no cuts","71X, loose cuts","71X, medium cuts","71X, tight cuts","71X, cosSeed, no cuts","71X, cosSeed, loose cuts","71X, cosSeed, medium cuts","71X, cosSeed, tight cuts"};
  char LegEntry[100];
  Leg1 = new TLegend(0.60,0.8,0.95,0.98);
  for (int a=0; a<NumFiles; a++){
    sprintf(LegEntry,"%s",LegFile[a]);
    Leg1->AddEntry(HAll1D[a][0],LegEntry,"l");
  }
  Leg1->SetBorderSize(0);
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);

  Leg2 = new TLegend(0.60,0.8,0.95,0.98);
  //Leg2->AddEntry(HAll1D[a][0],"Without trigger cut, with ,"l");
  Leg2->SetBorderSize(0);
  Leg2->SetTextSize(0.03);
  Leg2->SetFillColor(0);
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


  //TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV    Simulation","NDC");
  TPaveLabel *text1 = new TPaveLabel(.17,.85,.37,.89,"CMS Preliminary    #sqrt{s}=8 TeV","NDC");
  text1->SetBorderSize(0);
  text1->SetTextSize(0.7);
  text1->SetFillColor(0);

  //scale to guest's
  Double_t scalef0[Num1DHists];
  Double_t scalef2[Num1DHists];
  Double_t scalef3[Num1DHists];
  Double_t scalef4[Num1DHists];
  Double_t scalef5[Num1DHists];
  Double_t scalef6[Num1DHists];
  Double_t scalef7[Num1DHists];
  Double_t scalef8[Num1DHists];

  for (int a=0; a<NumFiles; a++){
    cout<<"sum of weights for file "<<a<<" is: "<<((Double_t)HAll1D[a][0]->GetSumOfWeights())<<endl;
  }

  for(int i=0; i<Num1DHists; i++){
    scalef0[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[0][i]->GetSumOfWeights());
    scalef2[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[2][i]->GetSumOfWeights());
    scalef3[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[3][i]->GetSumOfWeights());
    scalef4[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[4][i]->GetSumOfWeights());
    scalef5[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[5][i]->GetSumOfWeights());
    scalef6[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[6][i]->GetSumOfWeights());
    scalef7[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[7][i]->GetSumOfWeights());
    scalef8[i] = (1.0*(Double_t)HAll1D[1][i]->GetSumOfWeights())/((Double_t)HAll1D[8][i]->GetSumOfWeights());

    HAll1D[0][i]->Scale(scalef0[i]);
    HAll1D[2][i]->Scale(scalef2[i]);
    HAll1D[3][i]->Scale(scalef3[i]);
    HAll1D[4][i]->Scale(scalef4[i]);
    HAll1D[5][i]->Scale(scalef5[i]);
    HAll1D[6][i]->Scale(scalef6[i]);
    HAll1D[7][i]->Scale(scalef7[i]);
    HAll1D[8][i]->Scale(scalef8[i]);
  }
  cout<<"scaled histograms"<<endl;


  for (int a=0; a<NumFiles; a++){
    HAll1D[a][0]->GetYaxis()->SetRangeUser(.1,1000);
    HAll1D[a][4]->GetYaxis()->SetRangeUser(.1,1000);
    HAll1D[a][8]->GetYaxis()->SetRangeUser(.1,1000);
    HAll1D[a][3]->GetYaxis()->SetRangeUser(.1,8000);
    HAll1D[a][7]->GetYaxis()->SetRangeUser(.1,8000);
    HAll1D[a][11]->GetYaxis()->SetRangeUser(.1,8000);
  }


  //Draw and save histograms
  char canvasesEPS[200], canvasesEPS2D[200];  
  TPaveStats *stats0[Num1DHists], *stats1[Num1DHists], *stats2[Num1DHists];//, *stats3[Num1DHists], *stats4[Num1DHists], *stats5[Num1DHists];

  for(int i=0; i<Num1DHists; i++){
  //for(int i=1; i<Num1DHists; i++){
  //for(int i=0; i<17; i++){
    canvases1D[i]->cd();
    cout<<"drawing canvas "<<i<<endl;
    //mcMuonPt_hist->Draw();

    HAll1D[1][i]->Draw("hists");
    HAll1D[0][i]->Draw("sameshist");
    HAll1D[2][i]->Draw("sameshist");
    HAll1D[3][i]->Draw("sameshist");
    HAll1D[4][i]->Draw("sameshist");
    HAll1D[5][i]->Draw("sameshist");
    HAll1D[6][i]->Draw("sameshist");
    HAll1D[7][i]->Draw("sameshist");
    HAll1D[8][i]->Draw("sameshist");

    Leg1->Draw();
    /*
      stats2[i] = (TPaveStats*)HAll1D[2][i]->GetListOfFunctions()->FindObject("stats");
      stats2[i]->SetY1NDC(.5); //move stats box
      stats2[i]->SetY2NDC(.6);
      stats2[i]->SetX1NDC(.75);
      stats2[i]->SetTextColor(4);
      stats2[i]->SetBorderSize(0);
      */
    text1->Draw();

    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/mchamp500/53Xcheck/%s.eps",plot1D[i]);
    sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/mchamp500/DisStcheck/%s.eps",plot1D[i]);
    //sprintf(canvasesEPS,"../plots/StoppedHSCPMuon/RecoData/mchamp500/%s.eps",plot1D[i]);
    if (save_plots) canvases1D[i]->SaveAs(canvasesEPS);

  }

  /*
  for(int i=0; i<Num2DHists; i++){
    canvases2D[i]->cd();
    HAll2D[0][i]->Draw("colz");
    Leg2a->Draw();
    text1->Draw();
    if (bx_cut && other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_with_bx_cut_with_other_cut.eps",plot2D[i]);
    if (bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_with_bx_cut_without_other_cut.eps",plot2D[i]);
    if (!bx_cut && !other_cut) sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_without_bx_cut_without_other_cut.eps",plot2D[i]);
    //else sprintf(canvasesEPS2D,"../plots/StoppedHSCPMuon/RecoData/cosmic_collision/%scollisiondataRun2012A_without_bx_cut.eps",plot2D[i]);
    if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
  }
  */

}
