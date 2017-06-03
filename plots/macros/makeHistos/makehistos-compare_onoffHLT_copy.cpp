{
  using namespace std;

  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  gROOT->LoadMacro("./style.cpp");
  global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  //gStyle->SetStatW(.1);
  gStyle->SetStatH(.1);
  gStyle->SetTitleW(0.65);
  gStyle->SetTitleH(0.07);

  bool make_plots = false;
  //bool make_plots = true;
  bool save_plots = false;
  //bool save_plots = true;
  //bool make_txtfiles = false;
  bool make_txtfiles = true;
  //string run = "165364"; char* _run = "165364";
  //string run = "167102"; char* _run = "167102";
  //string run = "176304"; char* _run = "176304";
  //string run = "179977"; char* _run = "179977";
  string run = "195774"; char* _run = "195774";
  //string run = "178840"; char* _run = "178840";
  //string run = "177139"; char* _run = "177139";
  //string PD = "Tau"; char* _PD = "Tau"; char* _PDnum = "32";
  //string PD = "TauPlusX"; char* _PD = "TauPlusX"; char* _PDnum = "34";
  //string PD = "DoubleMu"; char* _PD = "DoubleMu"; char* _PDnum = "6";
  //string PD = "DoubleElectron"; char* _PD = "DoubleElectron"; char* _PDnum = "5";
  //string PD = "BTag"; char* _PD = "BTag"; char* _PDnum = "2";
  //string PD = "HT"; char* _PD = "HT"; char* _PDnum = "11";
  //string PD = "MET"; char* _PD = "MET"; char* _PDnum = "17";
  //string PD = "Jet"; char* _PD = "Jet"; char* _PDnum = "14";
  //string PD = "Photon"; char* _PD = "Photon"; char* _PDnum = "27";
  //string PD = "ElectronHad"; char* _PD = "ElectronHad"; char* _PDnum = "8";
  //string PD = "MuHad"; char* _PD = "MuHad"; char* _PDnum = "21";
  //string PD = "MultiJet"; char* _PD = "MultiJet"; char* _PDnum = "24";
  //string PD = "SingleElectron"; char* _PD = "SingleElectron"; char* _PDnum = "33";
  //string PD = "SingleMu"; char* _PD = "SingleMu"; char* _PDnum = "34";

  //string PD = "BTag"; char* _PD = "BTag"; char* _PDnum = "3";
  //string PD = "DoubleElectron"; char* _PD = "DoubleElectron"; char* _PDnum = "6";
  //string PD = "DoubleMu"; char* _PD = "DoubleMu"; char* _PDnum = "7";
  //string PD = "ElectronHad"; char* _PD = "ElectronHad"; char* _PDnum = "9";
  //string PD = "HT"; char* _PD = "HT"; char* _PDnum = "12";
  //string PD = "HighPileUp"; char* _PD = "HighPileUp"; char* _PDnum = "15";
  //string PD = "Jet"; char* _PD = "Jet"; char* _PDnum = "16";
  //string PD = "MET"; char* _PD = "MET"; char* _PDnum = "19";
  //string PD = "MinimumBias"; char* _PD = "MinimumBias"; char* _PDnum = "20";
  //string PD = "MuEG"; char* _PD = "MuEG"; char* _PDnum = "21";
  //string PD = "MuHad"; char* _PD = "MuHad"; char* _PDnum = "22";
  //string PD = "MuOnia"; char* _PD = "MuOnia"; char* _PDnum = "23";
  //string PD = "Photon"; char* _PD = "Photon"; char* _PDnum = "29";
  //string PD = "PhotonHad"; char* _PD = "PhotonHad"; char* _PDnum = "30";
  //string PD = "Tau"; char* _PD = "Tau"; char* _PDnum = "35";
  //string PD = "TauPlusX"; char* _PD = "TauPlusX"; char* _PDnum = "36";

  string PD = "MinimumBias"; char* _PD = "MinimumBias"; char* _PDnum = "26";

  //string PDpaths = "MinimumBias"; char* _PDpaths = "MinimumBias"; char* _PDpathsnum = "26";
  //string PDpaths = "HTMHT"; char* _PDpaths = "HTMHT"; char* _PDpathsnum = "18";
  //string PDpaths = "JetHT"; char* _PDpaths = "JetHT"; char* _PDpathsnum = "21";
  //string PDpaths = "JetMon"; char* _PDpaths = "JetMon"; char* _PDpathsnum = "22";
  //string PDpaths = "MultiJet"; char* _PDpaths = "MultiJet"; char* _PDpathsnum = "31";
  string PDpaths = "OnlineMonitor"; char* _PDpaths = "OnlineMonitor"; char* _PDpathsnum = "37";
  //string PDpaths = "ParkingMonitor"; char* _PDpaths = "ParkingMonitor"; char* _PDpathsnum = "38";

  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_HT.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_DoubleMu.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_DoubleElectron.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_Photon.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_Jet.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_SingleMu.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_Tau.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_TauPlusX.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_MultiJet.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_SingleElectron.root");
  //TFile f1("/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_1_4/src/compare_onoffHLT/output/compare_onoffHLT_162909_METBTag.root");

    
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_3_patch2/src/compare_onoffHLT/output/compare_onoffHLT_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_4_hltpatch1/src/compare_onoffHLT/output/compare_onoffHLT_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_7_hltpatch3/src/HLTOfflineReproducibility/output/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT2/src/HLTOfflineReproducibility/output/HLTOfflineReproducibility_" + run + PD + ".root";
  
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_R/HLTOfflineReproducibility_" + run + PD + ".root";

  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_MuonR/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_EcalR/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_EcalR_IntercalibConstants/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_EcalR_ADC/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_HcalR/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_HcalR_Pedestals/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_HcalR_RecoParams/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_trackerR/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_trackerR_BadModule/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_trackerR_BadFiber/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch3/src/output_HLTOfflineReproducibility_trackerR_DetVOff/HLTOfflineReproducibility_" + run + PD + ".root";

  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_4_1/src/output_HLTOfflineReproducibility/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_4_1/src/output_HLTOfflineReproducibility_H/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_5_0_0_pre3/src/output_HLTOfflineReproducibility/HLTOfflineReproducibility_" + run + PD + ".root";

  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch2/src/output_HLTOfflineReproducibility/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_9_HLT3_hltpatch2/src/output_HLTOfflineReproducibility/HLTOfflineReproducibility_" + run + PD + "_BPTXCoincidence.root";

  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_7_hltpatch3/src/output_HLTOfflineReproducibility/HLTOfflineReproducibility_" + run + PD + ".root";
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_7_hltpatch3/src/output_HLTOfflineReproducibility/HLTOfflineReproducibility_" + run + PD + "_BPTXCoincidence.root";
  
  //TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_5_2_4_hltpatch4/src/OfflineReproducibilityOutput/noJEC/OfflineReproducibility_" + run + "_" + PD + ".root";
  TString file = "/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_5_2_4_hltpatch4/src/OfflineReproducibilityOutput/JEC/OfflineReproducibility_" + run + "_" + PD + ".root";

  TFile f1(file);

  cout<<"Loaded file: "<<file<<endl;

  const int NumHists = 2;
  const int Num2DHists = 2;  

  //info for each 1D plot
  char* plot[NumHists] = {"path_ORIGnotNEW_","path_NEWnotORIG_"};
  char* xtitle = "Path";
  
  //info for each 2D plot
  char* plot2D[Num2DHists] = {"pathmodule_ORIGnotNEW_","pathmodule_NEWnotORIG_"};
  char* xtitle2D = "Path";
  char* ytitle2D = "Module";

  if (make_plots){
    //set up canvases
    char Cname[25], Ctitle[100];
    char Cname2D[25], Ctitle2D[100];
    TCanvas* canvases[NumHists];
    TCanvas* canvases2D[Num2DHists];
    for (int a=0; a<NumHists; a++){
      sprintf(Cname,"canvases[%i]",a);
      sprintf(Ctitle,"%s",plot[a]);
      if (PDpaths=="HT") canvases[a] = new TCanvas(Cname,Ctitle,10,10,1500,500);//800,600
      else canvases[a] = new TCanvas(Cname,Ctitle,10,10,900,600);//800,600
      //canvases[a]->SetLogy();
      canvas_style(canvases[a]);
    }
    /*
    for (int a=0; a<Num2DHists; a++){
      sprintf(Cname2D,"canvases2D[%i]",a);
      sprintf(Ctitle2D,"%s",plot2D[a]);
      if (PDpaths=="HT") canvases2D[a] = new TCanvas(Cname2D,Ctitle2D,10,10,1500,500);
      else canvases2D[a] = new TCanvas(Cname2D,Ctitle2D,10,10,900,600);
      //canvases2D[a]->SetLogz();
      canvas_style(canvases2D[a]);
    }
    */
  }

  
  //get histograms
  TH1D* HAll[NumHists]; 
  //TH2D* H2All[Num2DHists];
  
  char oldHname[100], oldH2name[100];
  for(int i=0; i<NumHists; i++){
    //sprintf(oldHname,"hltofflinereproducibility/%shist",plot[i]);
    //sprintf(oldHname,"hltofflinereproducibility/%shist_PD[%s]",plot[i],_PDnum);
    sprintf(oldHname,"hltOfflineReproducibility/%s/%shist_%s",_PDpaths,plot[i],_PDpaths);
    HAll[i] = (TH1D*) f1.Get(oldHname);
  }
  /*
  for(int i=0; i<Num2DHists; i++){
    //sprintf(oldH2name,"hltofflinereproducibility/%shist",plot2D[i]);
    //sprintf(oldH2name,"hltofflinereproducibility/%shist_PD[%s]",plot2D[i],_PDnum);
    sprintf(oldH2name,"hltOfflineReproducibility/%s/%shist_%s",_PDpaths,plot2D[i],_PDpaths);
    H2All[i] = (TH2D*) f1.Get(oldH2name);
  }
  */
  //TH1D* path_ORIG_hist = f1.Get("hltofflinereproducibility/path_ORIG_hist"); //plot of total acceptances online
  char oldHname_[100];
  //sprintf(oldHname_,"hltofflinereproducibility/path_ORIG_hist_PD[%s]",_PDnum);
  sprintf(oldHname_,"hltOfflineReproducibility/%s/path_ORIG_hist_%s",_PDpaths,_PDpaths);
  TH1D* path_ORIG_hist = f1.Get(oldHname_); //plot of total acceptances online

 
  //put in histogram specifications
  //int color[NumFiles] = {1,2};//,3,4,6};
  //int style[NumFiles] = {1,1};//,2,3,4};
  //int marker[NumFiles] = {20,21};//,22,23,24};
  //char axistitles[50], axis2Dtitles[100];
  for(int i=0; i<NumHists; i++){
    //sprintf(axistitles,"%s;;Events");
    HAll[i]->GetYaxis()->SetTitle("Events");
    h1_style(HAll[i],3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  }
  /*
  //H2All[0]->SetTitle("Last run module index vs Path for Offline, when Online fired but Offline didn't");
  //H2All[1]->SetTitle("Last run module index vs Path for Online, when Offline fired but Online didn't");
  for(int i=0; i<Num2DHists; i++){
    //sprintf(axis2Dtitles,"%s;;%s",ytitle2D[i]);
    H2All[i]->GetYaxis()->SetTitle("Index of last run module");
    h2_style(H2All[i],3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  }
  */
  cout<<"put in histogram specs"<<endl;
  
  //for (int a=0; a<NumFiles; a++){
    //HAllArray[8][a]->Rebin(20);
    //HAllArray[0][a]->GetXaxis()->SetRangeUser(0,1);
    //HAllArray[8][a]->GetXaxis()->SetRangeUser(0,5);
    //for(int i=0; i<Num2DHists; i++){
    //H2AllArray[i][a]->RebinY(20);
    //}    
  

  
  //Set up legends
  //char* LegFile[NumFiles] = {"Single Muon Data","stau, 300 GeV/c^{2}"};
  //char LegEntry[100];
  
  //Leg1 = new TLegend(0.7,0.75,0.95,0.95);
  //Leg1 = new TLegend(0.4,0.75,0.65,0.95);
  //Leg1->AddEntry(HAllArray[0][0],"Single Muon Data","p");
  //for (int a=1; a<NumFiles; a++){
  //sprintf(LegEntry,"%s",LegFile[a]);
  //Leg1->AddEntry(HAllArray[0][a],LegEntry,"l");
  //}
  //Leg1->SetTextSize(0.03);
  //Leg1->SetFillColor(0);

  if (make_txtfiles){  
        
    //loop over bins in each histogram
    //print to text file: path and module index # when bin content is not 0
    //TString outfile_path = "../txtfiles/printout_path_module_diff/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/" + run + "_" + PD + "_BPTXCoincidence_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/" + run + "_" + PD + "_BPTXCoincidence_path_diff_percent.txt";

    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT2/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT2/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_R/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_R/" + run + "_" + PD + "_path_diff_percent.txt";

    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_MuonR/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_MuonR/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_EcalR/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_EcalR/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_EcalR_IntercalibConstants/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_EcalR_IntercalibConstants/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_EcalR_ADC/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_EcalR_ADC/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_HcalR/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_HcalR/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_HcalR_Pedestals/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_HcalR_Pedestals/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_HcalR_RecoParams/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_HcalR_RecoParams/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_trackerR/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_trackerR/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_trackerR_BadModule/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_trackerR_BadModule/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_trackerR_BadFiber/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_trackerR_BadFiber/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_trackerR_DetVOff/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/429HLT3hltpatch3_trackerR_DetVOff/" + run + "_" + PD + "_path_diff_percent.txt";

    //TString outfile_path = "../txtfiles/printout_path_module_diff/441/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/441/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/441_H/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/441_H/" + run + "_" + PD + "_path_diff_percent.txt";
    //TString outfile_path = "../txtfiles/printout_path_module_diff/500pre3/" + run + "_" + PD + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/500pre3/" + run + "_" + PD + "_path_diff_percent.txt";

    //TString outfile_path = "../txtfiles/printout_path_module_diff/noJEC/" + run + "_" + PDpaths + "_path_diff.txt";
    //TString outfile_path_percent = "../txtfiles/printout_path_module_diff/noJEC/" + run + "_" + PDpaths + "_path_diff_percent.txt";
    TString outfile_path = "../txtfiles/printout_path_module_diff/JEC/" + run + "_" + PDpaths + "_path_diff.txt";
    TString outfile_path_percent = "../txtfiles/printout_path_module_diff/JEC/" + run + "_" + PDpaths + "_path_diff_percent.txt";

    ofstream outfile(outfile_path);
    ofstream outfile_percent(outfile_path_percent);
    
    outfile<<"For run "<<run<<", the "<<PDpaths<<" PD:"<<endl<<endl;
    outfile_percent<<"For run "<<run<<", the "<<PDpaths<<" PD:"<<endl<<endl;
    
    int nxbins = HAll[0]->GetNbinsX();
    //int nybins = H2All[0]->GetNbinsY();
    
    for (int j=1; j<=nxbins; j++){
      double contentORIG = path_ORIG_hist->GetBinContent(j);
      double contentORIGnotNEW = HAll[0]->GetBinContent(j);
      double contentNEWnotORIG = HAll[1]->GetBinContent(j);
      //if(content!=0){
      //outfile<<"For 1D histogram "<<i<<", for path "<<HAll[i]->GetXaxis()->GetBinLabel(j)<<", bin content is: "<<content<<endl;
      outfile<<HAll[0]->GetXaxis()->GetBinLabel(j)<<" fired "<<contentORIG<<" times online; there were "<<contentORIGnotNEW<<" times when it fired online but offline didn't, and there were "<<contentNEWnotORIG<<" times when it fired offline but online didn't."<<endl;
      if (contentORIG!=0.){
	if(100.0*contentORIGnotNEW/contentORIG>=0. || 100.0*contentNEWnotORIG/contentORIG>=0.){ //print out if discrepancy is >1%
	  outfile_percent<<HAll[0]->GetXaxis()->GetBinLabel(j)<<" gave a "<<100.0*contentORIGnotNEW/contentORIG<<"% discrepancy in ORIG not NEW and a "<<100.0*contentNEWnotORIG/contentORIG<<"% discrepancy in NEW not ORIG."<<endl;
	}
      }
    }
    outfile<<endl;
    string str, str1, str2, str3, str4, str5, str6, str7, module_str, path_str="test";
    ifstream infile;
    string for_str = "For";
    string mod_str = "module";
    int module_index = -1;

    /*
    for (int j=1; j<=nxbins; j++){
      for (int k=1; k<=nybins; k++){
	for(int i=0; i<Num2DHists; i++){
	  double content = H2All[i]->GetBinContent(j,k);
	  if(content!=0){
	    //read in path_modules
	    TString pm_file = "../txtfiles/path_info/path_module_info_" + run + ".txt";
	    infile.open(pm_file);
	    
	    //skip 2 first lines
	    getline(infile,str);
	    getline(infile,str);
	    
	    while (infile.good()){
	      infile>>str1;
	      if (str1==for_str){
		infile>>path_str;
	      }
	      if(str1==mod_str){
		infile>>module_index>>str2>>module_str>>str3>>str4>>str5>>str6>>str7;
	      }	    
	      
	      //outfile<<"For 2D histogram "<<i<<", for path "<<H2All[i]->GetXaxis()->GetBinLabel(j)<<", for module index "<<k-1<<", bin content is: "<<content<<endl;
	      if (H2All[i]->GetXaxis()->GetBinLabel(j)==path_str && k-1==module_index){
		if(i==0) outfile<<"For "<<H2All[i]->GetXaxis()->GetBinLabel(j)<<", there were "<<content<<" times when online fired but offline didn't, and the last run module was module index "<<k-1<<", which corresponds to module "<<module_str<<endl;
		if(i==1) outfile<<"For "<<H2All[i]->GetXaxis()->GetBinLabel(j)<<", there were "<<content<<" times when offline fired but online didn't, and the last run module was module index "<<k-1<<", which corresponds to module "<<module_str<<endl;
	      }
	    }
	    infile.close();
	  }
	}
      }
    }
    */
    
    outfile.close();
  }
  

  //Draw and save histograms
  if (make_plots){
    char canvasesEPS[200], canvasesEPS2D[200];  
    for(int i=0; i<NumHists; i++){
      canvases[i]->cd();
      HAll[i]->Draw();
      //Leg2->Draw();
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_HT/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_DoubleMu/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_DoubleElectron/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_Photon/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_Jet/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_SingleMu/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_Tau/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_TauPlusX/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_MultiJet/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_SingleElectron/%s.eps",plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/162909_METBTag/%s.eps",plot[i]);
      
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/%s_BPTXCoincidence/%s.eps",_run,_PD,plot[i]);

      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_R/%s/%s.eps",_run,_PD,plot[i]);

      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_MuonR/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_EcalR/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_EcalR_IntercalibConstants/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_EcalR_ADC/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_HcalR/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_HcalR_Pedestals/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_HcalR_RecoParams/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_trackerR/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_trackerR_BadModule/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_trackerR_BadFiber/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_trackerR_DetVOff/%s/%s.eps",_run,_PD,plot[i]);
      
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/441/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/441_H/%s/%s.eps",_run,_PD,plot[i]);
      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/500pre3/%s/%s.eps",_run,_PD,plot[i]);

      //sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/noJEC/%s/%s.eps",_run,_PDpaths,plot[i]);
      sprintf(canvasesEPS,"../plots/compare_onoffHLT/%s/JEC/%s/%s.eps",_run,_PDpaths,plot[i]);

      if (save_plots) canvases[i]->SaveAs(canvasesEPS);
    }
    /*
    for(int i=0; i<Num2DHists; i++){
      canvases2D[i]->cd();
      H2All[i]->Draw("colz");
      if(H2All[i]->GetEntries()>0){
	gPad->Update();
	TPaletteAxis *palette = (TPaletteAxis*)H2All[i]->GetListOfFunctions()->FindObject("palette");
	palette->SetX2NDC(0.85);
	palette->SetLabelSize(0.03);
      }

      //Leg4->Draw();
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_HT/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_DoubleMu/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_DoubleElectron/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_Photon/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_Jet/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_SingleMu/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_Tau/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_TauPlusX/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_MultiJet/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_SingleElectron/%s.eps",plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/162909_METBTag/%s.eps",plot2D[i]);
      
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/%s_BPTXCoincidence/%s.eps",_run,_PD,plot2D[i]);
      
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_R/%s/%s.eps",_run,_PD,plot2D[i]);

      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_MuonR/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_EcalR/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_EcalR_IntercalibConstants/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_EcalR_ADC/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_HcalR/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_HcalR_Pedestals/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_HcalR_RecoParams/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_trackerR/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_trackerR_BadModule/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_trackerR_BadFiber/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/429HLT3hltpatch3_trackerR_DetVOff/%s/%s.eps",_run,_PD,plot2D[i]);

      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/441/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/441_H/%s/%s.eps",_run,_PD,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/500pre3/%s/%s.eps",_run,_PD,plot2D[i]);

      sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/noJEC/%s/%s.eps",_run,_PDpaths,plot2D[i]);
      //sprintf(canvasesEPS2D,"../plots/compare_onoffHLT/%s/JEC/%s/%s.eps",_run,_PDpaths,plot2D[i]);

      if (save_plots) canvases2D[i]->SaveAs(canvasesEPS2D);
    }
    */
  }

}
