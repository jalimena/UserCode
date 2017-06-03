{
//creates new trees data_tree_new from old trees data_tree in order to only keep those events which pass the "preselection" and "positive" criteria
const int NumFiles = 1;
char* filenames[NumFiles]={"/mnt/hadoop/store/user/jalimena/Ntuples//stoppedHSCPMuonTree.root"};
 char* newfilenames[NumFiles]={"mchamp100/tree.root"};

for (int a=0; a<NumFiles; a++){
  //get old files, create new files
  TFile f(filenames[a]);
  TFile fnew(newfilenames[a],"recreate");

  //get tree 
  TTree* tree = (TTree*)f1->Get("stoppedHSCPMuonTree/StoppedHSCPMuonTree");
  //TTree* tree = (TTree*)f1->Get("ABCDStoppedHSCPMuonTree");
  //tree->Print(); 
  //tree->Show(0);
  
  StoppedHSCPMuonEvent* events = 0;

  //set branch address 
  tree->SetBranchAddress("events",&events);

  //get entries for data_tree (read in the old tree), set new variables, fill new tree 
  Int_t nentries = tree->GetEntriesFast();
  //Int_t nentries = tree->GetEntries(); 
  cout<<"number of entries is: "<<nentries<<endl;

  //make new tree (write to same file as histograms)
  TTree* newTree = new TTree("tree","");

  cout<<"made new events branch"<<endl;
  
  // Declaration of new leaf types
  Int_t           runNo;
  Int_t           evtNo;
  Double_t        Eg0;
  Double_t        Eg1;
  Double_t        Etag0;
  Double_t        Etag1;
  Double_t        Phig0;
  Double_t        Phig1;
  Double_t        pg0;
  Double_t        pg1;
  Double_t        ptg0;
  Double_t        ptg1;
  Double_t        pxg0;
  Double_t        pxg1;
  Double_t        pyg0;
  Double_t        pyg1;
  Double_t        pzg0;
  Double_t        pzg1;
  Double_t        beta0;
  Double_t        beta1;
  Double_t        E0;
  Double_t        E1;
  Double_t        Eta0;
  Double_t        Eta1;
  Double_t        Phi0;
  Double_t        Phi1;
  Double_t        p0;
  Double_t        p1;
  Double_t        pt0;
  Double_t        pt1;
  Double_t        px0;
  Double_t        px1;
  Double_t        py0;
  Double_t        py1;
  Double_t        pz0;
  Double_t        pz1;
  Int_t           nsmt0;
  Int_t           nsmt1;
  Double_t        dedx0;
  Double_t        dedx1;
  Double_t        speed0;
  Double_t        speed1;
  Double_t        Chi0;
  Double_t        Chi1;
  Double_t        signif0;
  Double_t        signif1;
  Double_t        signifprod;
  Double_t        invmass;
  Float_t         evtweight;
  Bool_t          pass_presel;
  Bool_t          pass_posi;
    
  //set new branch addresses
  newTree->Branch("runNo",&runNo,"runNo/I");
  newTree->Branch("evtNo",&evtNo,"evtNo/I");
  newTree->Branch("Eg0",&Eg0,"Eg0/D");
  newTree->Branch("Eg1",&Eg1,"Eg1/D");
  newTree->Branch("Etag0",&Etag0,"Etag0/D");
  newTree->Branch("Etag1",&Etag1,"Etag1/D");
  newTree->Branch("Phig0",&Phig0,"Phig0/D");
  newTree->Branch("Phig1",&Phig1,"Phig1/D");
  newTree->Branch("pg0",&pg0,"pg0/D");
  newTree->Branch("pg1",&pg1,"pg1/D");
  newTree->Branch("ptg0",&ptg0,"ptg0/D");
  newTree->Branch("ptg1",&ptg1,"ptg1/D");
  newTree->Branch("pxg0",&pxg0,"pxg0/D");
  newTree->Branch("pxg1",&pxg1,"pxg1/D");
  newTree->Branch("pyg0",&pyg0,"pyg0/D");
  newTree->Branch("pyg1",&pyg1,"pyg1/D");
  newTree->Branch("pzg0",&pzg0,"pzg0/D");
  newTree->Branch("pzg1",&pzg1,"pzg1/D");
  newTree->Branch("beta0",&beta0,"beta0/D");
  newTree->Branch("beta1",&beta1,"beta1/D");
  newTree->Branch("E0",&E0,"E0/D");
  newTree->Branch("E1",&E1,"E1/D");
  newTree->Branch("Eta0",&Eta0,"Eta0/D");
  newTree->Branch("Eta1",&Eta1,"Eta1/D");
  newTree->Branch("Phi0",&Phi0,"Phi0/D");
  newTree->Branch("Phi1",&Phi1,"Phi1/D");
  newTree->Branch("p0",&p0,"p0/D");
  newTree->Branch("p1",&p1,"p1/D");
  newTree->Branch("pt0",&pt0,"pt0/D");
  newTree->Branch("pt1",&pt1,"pt1/D");
  newTree->Branch("px0",&px0,"px0/D");
  newTree->Branch("px1",&px1,"px1/D");
  newTree->Branch("py0",&py0,"py0/D");
  newTree->Branch("py1",&py1,"py1/D");
  newTree->Branch("pz0",&pz0,"pz0/D");
  newTree->Branch("pz1",&pz1,"pz1/D");
  newTree->Branch("nsmt0",&nsmt0,"nsmt0/I");
  newTree->Branch("nsmt1",&nsmt1,"nsmt1/I");
  newTree->Branch("dedx0",&dedx0,"dedx0/D");
  newTree->Branch("dedx1",&dedx1,"dedx1/D");
  newTree->Branch("speed0",&speed0,"speed0/D");
  newTree->Branch("speed1",&speed1,"speed1/D");
  newTree->Branch("Chi0",&Chi0,"Chi0/D");
  newTree->Branch("Chi1",&Chi1,"Chi1/D");
  newTree->Branch("signif0",&signif0,"signif0/D");
  newTree->Branch("signif1",&signif1,"signif1/D");
  newTree->Branch("signifprod",&signifprod,"signifprod/D");
  newTree->Branch("invmass",&invmass,"invmass/D");
  newTree->Branch("evtweight",&evtweight,"evtweight/F");
  newTree->Branch("pass_presel",&pass_presel,"pass_presel/O");
  newTree->Branch("pass_posi",&pass_posi,"pass_posi/O");

  //for (Int_t i=0; i<100000; i++) {
  //for (Int_t i=0; i<500000; i++) {
  for (Int_t i=0; i<nentries; i++) {
    //for (Int_t i=0; i<2000; i++) { 
    //for (Int_t i=0; i<100; i++) {
    tree->GetEntry(i);

    runNo_new = runNo;
    evtNo_new = evtNo;
    pass_presel_new = pass_presel;
    pass_posi_new = pass_posi;
    if ((pass_presel == 1) &&(pass_posi == 1)){
      Eg0_new = Eg0;
      Eg1_new = Eg1;
      Etag0_new = Etag0;
      Etag1_new = Etag1;
      Phig0_new = Phig0;
      Phig1_new = Phig1;
      pg0_new = pg0;
      pg1_new = pg1;
      ptg0_new = ptg0;
      ptg1_new = ptg1;
      pxg0_new = pxg0;
      pxg1_new = pxg1;
      pyg0_new = pyg0;
      pyg1_new = pyg1;
      pzg0_new = pzg0;
      pzg1_new = pzg1;
      beta0_new = beta0;
      beta1_new = beta1;
      E0_new = E0;
      E1_new = E1;
      Eta0_new = Eta0;
      Eta1_new = Eta1;
      Phi0_new = Phi0;
      Phi1_new = Phi1;
      p0_new = p0;
      p1_new = p1;
      pt0_new = pt0;
      pt1_new = pt1;
      px0_new = px0;
      px1_new = px1;
      py0_new = py0;
      py1_new = py1;
      pz0_new = pz0;
      pz1_new = pz1;
      nsmt0_new = nsmt0;
      nsmt1_new = nsmt1;
      dedx0_new = dedx0;
      dedx1_new = dedx1;
      speed0_new = speed0;
      speed1_new = speed1;
      Chi0_new = Chi0;
      Chi1_new = Chi1;
      signif0_new = signif0;
      signif1_new = signif1;
      signifprod_new = signifprod;
      invmass_new = invmass;
      evtweight_new = evtweight;
      newTree->Fill();
    } 
  }

  //print new trees and write to new files
  newTree->Print();
  fnew.Write();
  
}
}
