{
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  //gROOT->LoadMacro("./style.cpp");
  //global_style();
  
  gROOT->LoadMacro("tdrstyle.C");
  gROOT->LoadMacro("CMS_lumi.C");

  setTDRStyle();
  //tdrGrid(false, tdrStyle); 
  gStyle->SetPalette(1);

  writeExtraText = true;
  extraText  = "Preliminary";
  //lumi_8TeV = "";                                                                                                                                                                                      
  int iPeriod = 2; // 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
  //int iPos=0;
  int iPos=11;
  //int iPos=22;

  TCanvas* canvas = new TCanvas("canvas","canvas",10,10,575,500);
  canvas->SetGridx();
  canvas->SetGridy();
  const int NumPoints = 51;

  //TH2* h1=new TH2F("h1","",50,0,250,400,0,400);
  //TH2* h1=new TH2F("h1","",50,0,250,50,0,50);
  TH2* h1=new TH2F("h1","",44,30,250,80,0,80);
  h1->SetStats(kFALSE);
  //h1->SetTitle(";Upper p_{T} Cut [GeV];S/#sqrt{B}");
  //h1->SetTitle(";Highest p_{T} Cut;S/#sqrt{B}");
  //h1->SetTitle(";Difference in p_{T} Cut;S/#sqrt{B}");
  //h1->SetTitle(";Average p_{T} Cut;S/#sqrt{B}");

  //h1->SetTitle(";Upper p Cut;S/#sqrt{B}");
  //h1->SetTitle(";Highest p Cut;S/#sqrt{B}");
  //h1->SetTitle(";Difference in p Cut;S/#sqrt{B}");
  //h1->SetTitle(";Average p Cut;S/#sqrt{B}");

  //h1->SetTitle(";Upper DSA Track p_{T} Cut [GeV];S/#sqrt{S+B}");
  //h1->SetTitle(";Highest DSA Track p_{T} Cut [GeV];S/#sqrt{S+B}");
  //h1->SetTitle(";Difference in DSA Track p_{T} Cut [GeV];S/#sqrt{S+B}");
  //h1->SetTitle(";Average DSA Track p_{T} Cut [GeV];S/#sqrt{S+B}");

  h1->SetTitle(";DSA Track p Cut [GeV];S/#sqrt{S+B}");
  //h1->SetTitle(";Highest DSA Track p Cut [GeV];S/#sqrt{S+B}");
  //h1->SetTitle(";Difference in DSA Track p Cut [GeV];S/#sqrt{S+B}");
  //h1->SetTitle(";Average DSA Track p Cut [GeV];S/#sqrt{S+B}");
  //h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0);
  
  Double_t x[NumPoints];
  Double_t y_data[NumPoints];
  Double_t y_allphi_cosmics[NumPoints];
  Double_t y_mchamp100[NumPoints];
  Double_t y_mchamp200[NumPoints];
  Double_t y_mchamp300[NumPoints];
  Double_t y_mchamp400[NumPoints];
  Double_t y_mchamp500[NumPoints];
  Double_t y_mchamp600[NumPoints];
  Double_t y_mchamp700[NumPoints];
  Double_t y_mchamp800[NumPoints];
  Double_t y_mchamp900[NumPoints];
  Double_t y_mchamp1000[NumPoints];
  Double_t y_mchamp100SsqrtB[NumPoints];
  Double_t y_mchamp200SsqrtB[NumPoints];
  Double_t y_mchamp300SsqrtB[NumPoints];
  Double_t y_mchamp400SsqrtB[NumPoints];
  Double_t y_mchamp500SsqrtB[NumPoints];
  Double_t y_mchamp600SsqrtB[NumPoints];
  Double_t y_mchamp700SsqrtB[NumPoints];
  Double_t y_mchamp800SsqrtB[NumPoints];
  Double_t y_mchamp900SsqrtB[NumPoints];
  Double_t y_mchamp1000SsqrtB[NumPoints];
  
  for(int i=0; i<NumPoints; i++) x[i]=1.0*i*5;
  
  //read in text files
  ifstream inFile1, inFile2, inFile3, inFile4, inFile5, inFile6, inFile7, inFile8, inFile9, inFile10, inFile11;
  /*  
  inFile1.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/BCAUpperPt_ABCDtree_2DSAdata_Run2012BCD_723patch1.txt");
  inFile2.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperPt_mchamp100_ABCDtree_2DSA_723patch1.txt");
  inFile3.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperPt_mchamp500_ABCDtree_2DSA_723patch1.txt");
  inFile4.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperPt_mchamp1000_ABCDtree_2DSA_723patch1.txt");
  */
  /*    
  inFile1.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/BCAHighestPt_ABCDtree_2DSAdata_Run2012BCD_723patch1.txt");
  inFile2.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestPt_mchamp100_ABCDtree_2DSA_723patch1.txt");
  inFile3.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestPt_mchamp500_ABCDtree_2DSA_723patch1.txt");
  inFile4.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestPt_mchamp1000_ABCDtree_2DSA_723patch1.txt");
  */
  /*
  inFile1.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/BCADifferencePt_ABCDtree_2DSAdata_Run2012BCD_723patch1.txt");
  inFile2.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DDifferencePt_mchamp100_ABCDtree_2DSA_723patch1.txt");
  inFile3.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DDifferencePt_mchamp500_ABCDtree_2DSA_723patch1.txt");
  inFile4.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DDifferencePt_mchamp1000_ABCDtree_2DSA_723patch1.txt");
  */
  /*
  inFile1.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/BCAAvePt_ABCDtree_2DSAdata_Run2012BCD_723patch1.txt");
  inFile2.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DAvePt_mchamp100_ABCDtree_2DSA_723patch1.txt");
  inFile3.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DAvePt_mchamp500_ABCDtree_2DSA_723patch1.txt");
  inFile4.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DAvePt_mchamp1000_ABCDtree_2DSA_723patch1.txt");
  */
  /*  
  inFile1.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/BCAUpperP_ABCDtree_2DSAdata_Run2012BCD_723patch1.txt");
  inFile2.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp100_ABCDtree_2DSA_723patch1.txt");
  inFile3.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp200_ABCDtree_2DSA_723patch1.txt");
  inFile4.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp300_ABCDtree_2DSA_723patch1.txt");
  inFile5.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp400_ABCDtree_2DSA_723patch1.txt");
  inFile6.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp500_ABCDtree_2DSA_723patch1.txt");
  inFile7.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp600_ABCDtree_2DSA_723patch1.txt");
  inFile8.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp700_ABCDtree_2DSA_723patch1.txt");
  inFile9.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp800_ABCDtree_2DSA_723patch1.txt");
  inFile10.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp900_ABCDtree_2DSA_723patch1.txt");
  inFile11.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DUpperP_mchamp1000_ABCDtree_2DSA_723patch1.txt");
  */

  inFile1.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/BCALowerP_ABCDtree_2DSAdata_Run2012BCD_pRpcBx.txt");
  inFile2.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp100_separateEvents_725_updatedSim_fixedMatching.txt");
  inFile3.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp200_separateEvents_725_updatedSim_fixedMatching.txt");
  inFile4.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp300_separateEvents_725_updatedSim_fixedMatching.txt");
  inFile5.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp400_separateEvents_725_updatedSim_fixedMatching.txt");
  inFile6.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp500_separateEvents_725_updatedSim_fixedMatching.txt");
  inFile7.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp600_separateEvents_725_updatedSim_fixedMatching.txt");
  inFile8.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp700_separateEvents_725_updatedSim_fixedMatching.txt");
  inFile9.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp800_separateEvents_725_updatedSim_fixedMatching.txt");
  inFile10.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp900_separateEvents_725_updatedSim_fixedMatching.txt");
  inFile11.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DLowerP_mchamp1000_separateEvents_725_updatedSim_fixedMatching.txt");
  
  /*      
  inFile1.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/BCAHighestP_ABCDtree_2DSAdata_Run2012BCD_723patch1.txt");
  inFile2.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp100_ABCDtree_2DSA_723patch1.txt");
  inFile3.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp200_ABCDtree_2DSA_723patch1.txt");
  inFile4.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp300_ABCDtree_2DSA_723patch1.txt");
  inFile5.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp400_ABCDtree_2DSA_723patch1.txt");
  inFile6.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp500_ABCDtree_2DSA_723patch1.txt");
  inFile7.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp600_ABCDtree_2DSA_723patch1.txt");
  inFile8.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp700_ABCDtree_2DSA_723patch1.txt");
  inFile9.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp800_ABCDtree_2DSA_723patch1.txt");
  inFile10.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp900_ABCDtree_2DSA_723patch1.txt");
  inFile11.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DHighestP_mchamp1000_ABCDtree_2DSA_723patch1.txt");
  */
  /*
  inFile1.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/BCADifferenceP_ABCDtree_2DSAdata_Run2012BCD_723patch1.txt");
  inFile2.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DDifferenceP_mchamp100_ABCDtree_2DSA_723patch1.txt");
  inFile3.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DDifferenceP_mchamp500_ABCDtree_2DSA_723patch1.txt");
  inFile4.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DDifferenceP_mchamp1000_ABCDtree_2DSA_723patch1.txt");
  */
  /*  
  inFile1.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/BCAAveP_ABCDtree_2DSAdata_Run2012BCD_723patch1.txt");
  inFile2.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DAveP_mchamp100_ABCDtree_2DSA_723patch1.txt");
  inFile3.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DAveP_mchamp500_ABCDtree_2DSA_723patch1.txt");
  inFile4.open("/home/alimena/Analysis/CMSSW_7_2_5/src/StoppedHSCPMuon/Ntuples/txtfiles/FractionEvents_PtCuts/DAveP_mchamp1000_ABCDtree_2DSA_723patch1.txt");
  */
  for(int i=0; i<NumPoints; i++){
    inFile1 >> y_data[i];
    //inFile2 >> y_allphi_cosmics[i];
    inFile2 >> y_mchamp100[i];
    inFile3 >> y_mchamp200[i];
    inFile4 >> y_mchamp300[i];
    inFile5 >> y_mchamp400[i];
    inFile6 >> y_mchamp500[i];
    //inFile3 >> y_mchamp500[i];
    inFile7 >> y_mchamp600[i];
    inFile8 >> y_mchamp700[i];
    inFile9 >> y_mchamp800[i];
    inFile10 >> y_mchamp900[i];
    inFile11 >> y_mchamp1000[i];
    //inFile4 >> y_mchamp1000[i];
    //y_mchamp100SsqrtB[i] = y_mchamp100[i]/TMath::Sqrt(y_data[i]);
    //y_mchamp500SsqrtB[i] = y_mchamp500[i]/TMath::Sqrt(y_data[i]);
    //y_mchamp1000SsqrtB[i] = y_mchamp1000[i]/TMath::Sqrt(y_data[i]);
    y_mchamp100SsqrtB[i] = y_mchamp100[i]/TMath::Sqrt(y_mchamp100[i]+y_data[i]);
    y_mchamp200SsqrtB[i] = y_mchamp200[i]/TMath::Sqrt(y_mchamp200[i]+y_data[i]);
    y_mchamp300SsqrtB[i] = y_mchamp300[i]/TMath::Sqrt(y_mchamp300[i]+y_data[i]);
    y_mchamp400SsqrtB[i] = y_mchamp400[i]/TMath::Sqrt(y_mchamp400[i]+y_data[i]);
    y_mchamp500SsqrtB[i] = y_mchamp500[i]/TMath::Sqrt(y_mchamp500[i]+y_data[i]);
    y_mchamp600SsqrtB[i] = y_mchamp600[i]/TMath::Sqrt(y_mchamp600[i]+y_data[i]);
    y_mchamp700SsqrtB[i] = y_mchamp700[i]/TMath::Sqrt(y_mchamp700[i]+y_data[i]);
    y_mchamp800SsqrtB[i] = y_mchamp800[i]/TMath::Sqrt(y_mchamp800[i]+y_data[i]);
    y_mchamp900SsqrtB[i] = y_mchamp900[i]/TMath::Sqrt(y_mchamp900[i]+y_data[i]);
    y_mchamp1000SsqrtB[i] = y_mchamp1000[i]/TMath::Sqrt(y_mchamp1000[i]+y_data[i]);
    //y_mchamp100SsqrtB[i] = y_data[i];
    //y_mchamp500SsqrtB[i] = y_data[i];
    //y_mchamp1000SsqrtB[i] = y_data[i];
  }
  
  inFile1.close();
  inFile2.close();
  inFile3.close();
  inFile4.close();
  inFile5.close();
  inFile6.close();
  inFile7.close();
  inFile8.close();
  inFile9.close();
  inFile10.close();
  inFile11.close();

  for(int i=0; i<NumPoints; i++){
    if(y_data[i]==-1) y_mchamp100SsqrtB[i]=TMath::Sqrt(y_mchamp100[i]);
    if(y_data[i]==-1) y_mchamp200SsqrtB[i]=TMath::Sqrt(y_mchamp200[i]);
    if(y_data[i]==-1) y_mchamp300SsqrtB[i]=TMath::Sqrt(y_mchamp300[i]);
    if(y_data[i]==-1) y_mchamp400SsqrtB[i]=TMath::Sqrt(y_mchamp400[i]);
    if(y_data[i]==-1) y_mchamp500SsqrtB[i]=TMath::Sqrt(y_mchamp500[i]);
    if(y_data[i]==-1) y_mchamp600SsqrtB[i]=TMath::Sqrt(y_mchamp600[i]);
    if(y_data[i]==-1) y_mchamp700SsqrtB[i]=TMath::Sqrt(y_mchamp700[i]);
    if(y_data[i]==-1) y_mchamp800SsqrtB[i]=TMath::Sqrt(y_mchamp800[i]);
    if(y_data[i]==-1) y_mchamp900SsqrtB[i]=TMath::Sqrt(y_mchamp900[i]);
    if(y_data[i]==-1) y_mchamp1000SsqrtB[i]=TMath::Sqrt(y_mchamp1000[i]);
    cout<<"y_mchamp500["<<i<<"] is: "<<y_mchamp500[i]<<", y_data["<<i<<"] is: "<<y_data[i]<<", and y_mchamp100SsqrtB["<<i<<"] is: "<<y_mchamp500SsqrtB[i]<<endl;
  }
  
  //TGraph* gr_data = new TGraph(NumPoints,x,y_data);
  //TGraph* gr_allphi_cosmics = new TGraph(NumPoints,x,y_allphi_cosmics);
  //TGraph* gr_signal = new TGraph(NumPoints,x,y_signal);
  TGraph* gr_mchamp100SsqrtB = new TGraph(NumPoints,x,y_mchamp100SsqrtB);
  TGraph* gr_mchamp200SsqrtB = new TGraph(NumPoints,x,y_mchamp200SsqrtB);
  TGraph* gr_mchamp300SsqrtB = new TGraph(NumPoints,x,y_mchamp300SsqrtB);
  TGraph* gr_mchamp400SsqrtB = new TGraph(NumPoints,x,y_mchamp400SsqrtB);
  TGraph* gr_mchamp500SsqrtB = new TGraph(NumPoints,x,y_mchamp500SsqrtB);
  TGraph* gr_mchamp600SsqrtB = new TGraph(NumPoints,x,y_mchamp600SsqrtB);
  TGraph* gr_mchamp700SsqrtB = new TGraph(NumPoints,x,y_mchamp700SsqrtB);
  TGraph* gr_mchamp800SsqrtB = new TGraph(NumPoints,x,y_mchamp800SsqrtB);
  TGraph* gr_mchamp900SsqrtB = new TGraph(NumPoints,x,y_mchamp900SsqrtB);
  TGraph* gr_mchamp1000SsqrtB = new TGraph(NumPoints,x,y_mchamp1000SsqrtB);
  //gr_style(gr_data);
  //gr_style(gr_allphi_cosmics,2,2,1,1001,50,-1111,-1111,510,510,21,2,1,1);
  //gr_style(gr_signal,2,3,1,1001,50,-1111,-1111,510,510,22,3,1,1);
  /*
  gr_style(gr_mchamp100SsqrtB,2,1,1,1001,50,-1111,-1111,510,510,20,1,1,1);
  gr_style(gr_mchamp200SsqrtB,2,2,1,1001,50,-1111,-1111,510,510,21,2,1,1);
  gr_style(gr_mchamp300SsqrtB,2,3,1,1001,50,-1111,-1111,510,510,22,3,1,1);
  gr_style(gr_mchamp400SsqrtB,2,4,1,1001,50,-1111,-1111,510,510,23,4,1,1);
  gr_style(gr_mchamp500SsqrtB,2,6,1,1001,50,-1111,-1111,510,510,34,6,1,1);
  gr_style(gr_mchamp600SsqrtB,2,1,1,1001,50,-1111,-1111,510,510,24,1,1,1);
  gr_style(gr_mchamp700SsqrtB,2,2,1,1001,50,-1111,-1111,510,510,25,2,1,1);
  gr_style(gr_mchamp800SsqrtB,2,3,1,1001,50,-1111,-1111,510,510,26,3,1,1);
  gr_style(gr_mchamp900SsqrtB,2,4,1,1001,50,-1111,-1111,510,510,32,4,1,1);
  gr_style(gr_mchamp1000SsqrtB,2,6,1,1001,50,-1111,-1111,510,510,28,6,1,1);
  */
  //gr_data->SetTitle(";Individual #chi^{2} Cut;Fraction of Hits Passing Individual #chi^{2} Cut");
  //gr_allphi_cosmics->SetTitle(";#Individual chi^{2} Cut;Fraction of Hits Passing Individual #chi^{2} Cut");
  //gr_signal->SetTitle(";#Individual chi^{2} Cut;Fraction of Hits Passing Individual #chi^{2} Cut");
  /*
  gr_mchamp100SsqrtB->SetMarkerStyle(20);
  gr_mchamp500SsqrtB->SetMarkerStyle(21);
  gr_mchamp1000SsqrtB->SetMarkerStyle(22);

  gr_mchamp100SsqrtB->SetMarkerColor(1);
  gr_mchamp500SsqrtB->SetMarkerColor(2);
  gr_mchamp1000SsqrtB->SetMarkerColor(4);
  */
  
  gr_mchamp100SsqrtB->SetMarkerStyle(20);
  gr_mchamp200SsqrtB->SetMarkerStyle(21);
  gr_mchamp300SsqrtB->SetMarkerStyle(22);
  gr_mchamp400SsqrtB->SetMarkerStyle(23);
  gr_mchamp500SsqrtB->SetMarkerStyle(34);
  gr_mchamp600SsqrtB->SetMarkerStyle(24);
  gr_mchamp700SsqrtB->SetMarkerStyle(25);
  gr_mchamp800SsqrtB->SetMarkerStyle(26);
  gr_mchamp900SsqrtB->SetMarkerStyle(32);
  gr_mchamp1000SsqrtB->SetMarkerStyle(28);

  gr_mchamp100SsqrtB->SetMarkerColor(1);
  gr_mchamp200SsqrtB->SetMarkerColor(2);
  gr_mchamp300SsqrtB->SetMarkerColor(3);
  gr_mchamp400SsqrtB->SetMarkerColor(4);
  gr_mchamp500SsqrtB->SetMarkerColor(6);
  gr_mchamp600SsqrtB->SetMarkerColor(1);
  gr_mchamp700SsqrtB->SetMarkerColor(2);
  gr_mchamp800SsqrtB->SetMarkerColor(3);
  gr_mchamp900SsqrtB->SetMarkerColor(4);
  gr_mchamp1000SsqrtB->SetMarkerColor(6);
  

  /*
  gr_mchamp100SsqrtB->SetTitle(";Upper p_{T} Cut;S/#sqrt(B)");
  gr_mchamp500SsqrtB->SetTitle(";Upper p_{T} Cut;S/#sqrt(B)");
  gr_mchamp1000SsqrtB->SetTitle(";Upper p_{T} Cut;S/#sqrt(B)");
  */
  gr_mchamp100SsqrtB->SetTitle(";Lower p Cut;S/#sqrt(B)");
  gr_mchamp500SsqrtB->SetTitle(";Lower p Cut;S/#sqrt(B)");
  gr_mchamp1000SsqrtB->SetTitle(";Lower p Cut;S/#sqrt(B)");


  /*
  gr_data->GetXaxis()->SetRangeUser(0,50);
  gr_allphi_cosmics->GetXaxis()->SetRangeUser(0,50);
  gr_signal->GetXaxis()->SetRangeUser(0,50);
  gr_SsqrtB->GetXaxis()->SetRangeUser(0,50);
  gr_data->GetYaxis()->SetRangeUser(0.4,1.1);
  gr_allphi_cosmics->GetYaxis()->SetRangeUser(0.4,1.1);
  gr_signal->GetYaxis()->SetRangeUser(0.4,1.1);
  gr_SsqrtB->GetYaxis()->SetRangeUser(0.4,1.1);
  */
  /*
    gr_data->GetYaxis()->SetRangeUser(0.4,1);
    gr_allphi_cosmics->GetYaxis()->SetRangeUser(0.4,1);
    gr_signal->GetYaxis()->SetRangeUser(0.4,1);
    gr_SsqrtB->GetYaxis()->SetRangeUser(0.4,1);
  */
  
  
  Leg1 = new TLegend(0.6,0.72,0.85,0.90);
  //Leg1->AddEntry(gr_data,"Z->mumu Data","p");
  //Leg1->AddEntry(gr_allphi_cosmics,"All-Phi Cosmics","p");
  //Leg1->AddEntry(gr_signal,"#tilde{t_{1}} 600 GeV","p");
  Leg1->AddEntry(gr_mchamp100SsqrtB,"100 GeV mchamps","p");
  Leg1->AddEntry(gr_mchamp200SsqrtB,"200 GeV mchamps","p");
  Leg1->AddEntry(gr_mchamp300SsqrtB,"300 GeV mchamps","p");
  Leg1->AddEntry(gr_mchamp400SsqrtB,"400 GeV mchamps","p");
  Leg1->AddEntry(gr_mchamp500SsqrtB,"500 GeV mchamps","p");
  Leg1->SetTextSize(0.03);
  Leg1->SetFillColor(0);
  Leg1->SetBorderSize(0);
  Leg1->SetFillColor(0);

  
  Leg2 = new TLegend(0.60,0.72,0.85,0.90);
  Leg2->AddEntry(gr_mchamp600SsqrtB,"600 GeV mchamps","p");
  Leg2->AddEntry(gr_mchamp700SsqrtB,"700 GeV mchamps","p");
  Leg2->AddEntry(gr_mchamp800SsqrtB,"800 GeV mchamps","p");
  Leg2->AddEntry(gr_mchamp900SsqrtB,"900 GeV mchamps","p");
  Leg2->AddEntry(gr_mchamp1000SsqrtB,"1000 GeV mchamps","p");  
  Leg2->SetTextSize(0.03);
  Leg2->SetFillColor(0);
  Leg2->SetBorderSize(0);
  Leg2->SetFillColor(0);
  

  canvas->cd();
  //gr_data->Draw("AP");
  //gr_allphi_cosmics->Draw("Psame");
  //gr_signal->Draw("Psame");
  h1->Draw();
  /*  
  gr_mchamp100SsqrtB->Draw("Psame");
  gr_mchamp500SsqrtB->Draw("Psame");
  gr_mchamp1000SsqrtB->Draw("Psame");      
  Leg1->Draw("same");
  */
        
  gr_mchamp100SsqrtB->Draw("Psame");
  gr_mchamp200SsqrtB->Draw("Psame");
  gr_mchamp300SsqrtB->Draw("Psame");
  gr_mchamp400SsqrtB->Draw("Psame");
  gr_mchamp500SsqrtB->Draw("Psame");
  Leg1->Draw("same");
  

  /*      
  gr_mchamp600SsqrtB->Draw("Psame");
  gr_mchamp700SsqrtB->Draw("Psame");
  gr_mchamp800SsqrtB->Draw("Psame");
  gr_mchamp900SsqrtB->Draw("Psame");
  gr_mchamp1000SsqrtB->Draw("Psame");      
  Leg2->Draw("same");
  */

  CMS_lumi( canvas, iPeriod, iPos );
  //canvas->SaveAs("../plots/timing/DT/zmumu_cosmic_signal/percent_chi2.eps");
  

}
