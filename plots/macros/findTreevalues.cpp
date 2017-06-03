{
  //find particular values in a StoppedHSCPMuon tree

  gSystem.Load("libStoppedHSCPMuonNtuples");
  
  //file = TFile::Open("rfio:/castor/cern.ch/user/j/jalimena/Ntuples/stoppedHSCPMuonTree_onlyNoBPTX_191718.root");  
  file = TFile::Open("/afs/cern.ch/user/j/jalimena/public/Ntuples/stoppedHSCPMuonTree_onlyNoBPTX_190465_ls1_110.root");
  //get tree
  TTree* tree = (TTree*) file.Get("stoppedHSCPMuonTree/StoppedHSCPMuonTree");
  //tree->Print();
  //tree->Show(0);
  //tree->Draw("events.top5DigiROuter>>h_bx(1000,-1000,0)");

  StoppedHSCPMuonEvent* events = new StoppedHSCPMuonEvent();  
  
  // Declaration of leaf types
  ULong_t         id;
  ULong_t         bx;
  ULong_t         orbit;
  ULong_t         lb;
  ULong_t         run;
  ULong_t         fill;

  //set old branch address
  tree->SetBranchAddress("events",&events);

  //get entries for data_tree (read in the old tree), set new variables, fill new tree
  Int_t nentries = tree->GetEntriesFast();
  cout<<"number of entries is: "<<nentries<<endl;
  
  for (Int_t i = 0; i<nentries; i++) {
    tree->GetEntry(i);
    
    //if(events.bx==1339 || events.bx==1341 || events.bx==1343 || events.bx==1345 || events.bx==1347 || events.bx==1349 || events.bx==1351 || events.bx==1353 || events.bx==1355 || events.bx==1357 || events.bx==1359 || events.bx==1361){
    //if(events.id<100000000){
      cout<<"For bx=="<<events.bx<<", run=="<<events.run<<", id=="<<events.id<<", orbit=="<<events.orbit<<", lb=="<<events.lb<<", fill=="<<events.fill<<endl;
      //}
    //cout<<"for entry "<<i<<", top5DigiROuter is: "<<events.top5DigiROuter<<endl;
    
  }
  
  
  
}
