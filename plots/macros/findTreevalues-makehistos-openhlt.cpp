void findTreevalues(char* channel, char* m){
  //cout<<"started"<<endl;
  //find particular values in a tree
  using namespace std;

  //channel options: stau
  //m options: 100, 200, 308
  
  char filename[200], newfilename[200];
  sprintf(filename,"/afs/cern.ch/user/j/jalimena/private/keep/%s_HLTntuples/openhlt_%s%s.root",channel,channel,m);
  sprintf(newfilename,"/afs/cern.ch/user/j/jalimena/private/keep/%s_HLThistos/%s%s.root",channel,channel,m);  
  TFile f(filename);
  TFile fnew(newfilename,"recreate");
  //cout<<"opened files"<<endl;

  //get tree
  TTree* tree = (TTree*) f.Get("HltTree");
  //cout<<"got tree"<<endl;

  // Declaration of leaf types
  //Int_t          _runno;
  //Int_t          _storeno;
  Int_t Event;
  const Int_t NMCpart=999999;
  Int_t MCstatus[NMCpart];
  Int_t MCpid[NMCpart];
  Float_t MCvtxX[NMCpart];
  Float_t MCvtxY[NMCpart];
  Float_t MCvtxZ[NMCpart];
  Float_t MCpt[NMCpart];
  Float_t MCeta[NMCpart];
  Float_t MCphi[NMCpart];
  //cout<<"declared variables"<<endl;

  //set old branch address
  tree->SetBranchAddress("Event",&Event);
  tree->SetBranchAddress("NMCpart",&NMCpart);
  tree->SetBranchAddress("MCstatus",&MCstatus);
  tree->SetBranchAddress("MCpid",&MCpid);
  tree->SetBranchAddress("MCvtxX",&MCvtxX);
  tree->SetBranchAddress("MCvtxY",&MCvtxY);
  tree->SetBranchAddress("MCvtxZ",&MCvtxZ);
  tree->SetBranchAddress("MCpt",&MCpt);
  tree->SetBranchAddress("MCeta",&MCeta);
  tree->SetBranchAddress("MCphi",&MCphi);

  //histograms
  TH1F* _Eventhist = new TH1F("_Eventhist","Event Number",100000,0,100000);

  TH1F* _NMCparthist = new TH1F("_NMCparthist","Number of MC Particles",20,0,20);
  TH1F* _MCpidhist = new TH1F("_MCpidhist","Particle ID Numbers",2010000,-10000,2000000);
  TH1F* _MCstatushist = new TH1F("_MCstatushist","MC Status",5,0,5);
  TH1F* _MCpthist = new TH1F("_MCpthist","p_{T}",1000,0,1000);
  TH1F* _MCetahist = new TH1F("_MCetahist","#eta",120,-6,6);
  TH1F* _MCphihist = new TH1F("_MCphihist","#phi",64,-6.2832,6.2832);
  TH1F* _MCvtxXhist = new TH1F("_MCvtxXhist","X component of Vertex",1000,-10000,10000);
  TH1F* _MCvtxYhist = new TH1F("_MCvtxYhist","Y component of Vertex",1000,-10000,10000);
  TH1F* _MCvtxZhist = new TH1F("_MCvtxZhist","Z component of Vertex",1000,-10000,10000);
  TH2F* _MCvtxXvtxYhist = new TH2F("_MCvtxXvtxYhist","X component vs Y component of Vertex",1000,-10000,10000,1000,-10000,10000);
  
  TH1F* _Nmuhist = new TH1F("_Nmuhist","Number of MC Muons",20,0,20);
  TH1F* _mustatushist = new TH1F("_mustatushist","MC Status of Muons",5,0,5);
  TH1F* _mupthist = new TH1F("_mupthist","Muon p_{T}",1000,0,1000);
  TH1F* _muetahist = new TH1F("_muetahist","Muon #eta",120,-6,6);
  TH1F* _muphihist = new TH1F("_muphihist","Muon #phi",64,-6.2832,6.2832);
  TH1F* _muvtxXhist = new TH1F("_muvtxXhist","X component of Muon Vertex",1000,-10000,10000);
  TH1F* _muvtxYhist = new TH1F("_muvtxYhist","Y component of Muon Vertex",1000,-10000,10000);
  TH1F* _muvtxZhist = new TH1F("_muvtxZhist","Z component of Muon Vertex",1000,-10000,10000);
  TH2F* _muvtxXvtxYhist = new TH2F("_muvtxXvtxYhist","X component vs Y component of Muon Vertex",1000,-10000,10000,1000,-10000,10000);
  
  TH1F* _Nstauhist = new TH1F("_Nstauhist","Number of MC Staus",20,0,20);
  TH1F* _staustatushist = new TH1F("_staustatushist","MC Status of Staus",5,0,5);
  TH1F* _staupthist = new TH1F("_staupthist","Stau p_{T}",1000,0,1000);
  TH1F* _stauetahist = new TH1F("_stauetahist","Stau #eta",120,-6,6);
  TH1F* _stauphihist = new TH1F("_stauphihist","Stau #phi",64,-6.2832,6.2832);
  TH1F* _stauvtxXhist = new TH1F("_stauvtxXhist","X component of Stau Vertex",1000,-10000,10000);
  TH1F* _stauvtxYhist = new TH1F("_stauvtxYhist","Y component of Stau Vertex",1000,-10000,10000);
  TH1F* _stauvtxZhist = new TH1F("_stauvtxZhist","Z component of Stau Vertex",1000,-10000,10000);
  TH2F* _stauvtxXvtxYhist = new TH2F("_stauvtxXvtxYhist","X component vs Y component of Stau Vertex",1000,-10000,10000,1000,-10000,10000);

  TH1F* _Nneutralinohist = new TH1F("_Nneutralinohist","Number of MC Neutralinos",20,0,20);
  TH1F* _neutralinostatushist = new TH1F("_neutralinostatushist","MC Status of Neutralinos",5,0,5);
  TH1F* _neutralinopthist = new TH1F("_neutralinopthist","Neutralino p_{T}",1000,0,1000);
  TH1F* _neutralinoetahist = new TH1F("_neutralinoetahist","Neutralino #eta",120,-6,6);
  TH1F* _neutralinophihist = new TH1F("_neutralinophihist","Neutralino #phi",64,-6.2832,6.2832);
  TH1F* _neutralinovtxXhist = new TH1F("_neutralinovtxXhist","X component of Neutralino Vertex",1000,-10000,10000);
  TH1F* _neutralinovtxYhist = new TH1F("_neutralinovtxYhist","Y component of Neutralino Vertex",1000,-10000,10000);
  TH1F* _neutralinovtxZhist = new TH1F("_neutralinovtxZhist","Z component of Neutralino Vertex",1000,-10000,10000);
  TH2F* _neutralinovtxXvtxYhist = new TH2F("_neutralinovtxXvtxYhist","X component vs Y component of Neutralino Vertex",1000,-10000,10000,1000,-10000,10000);

  //if pt, eta, or phi is 0
  TH1F* _0MCnumhist = new TH1F("_0MCnumhist","Particle Number if p_{T}, #eta, or #phi == 0.",20,0,20);
  TH1F* _0MCpidhist = new TH1F("_0MCpidhist","Particle ID Numbers if p_{T}, #eta, or #phi == 0.",2010000,-10000,2000000);
  TH1F* _0MCstatushist = new TH1F("_0MCstatushist","MC Status if p_{T}, #eta, or #phi == 0.",5,0,5);
  TH1F* _0MCpthist = new TH1F("_0MCpthist","p_{T} if p_{T}, #eta, or #phi == 0.",1000,0,1000);
  TH1F* _0MCetahist = new TH1F("_0MCetahist","#eta if p_{T}, #eta, or #phi == 0.",120,-6,6);
  TH1F* _0MCphihist = new TH1F("_0MCphihist","#phi if p_{T}, #eta, or #phi == 0.",64,-6.2832,6.2832);
  TH1F* _0MCvtxXhist = new TH1F("_0MCvtxXhist","X component of Vertex if p_{T}, #eta, or #phi == 0.",1000,-10000,10000);
  TH1F* _0MCvtxYhist = new TH1F("_0MCvtxYhist","Y component of Vertex if p_{T}, #eta, or #phi == 0.",1000,-10000,10000);
  TH1F* _0MCvtxZhist = new TH1F("_0MCvtxZhist","Z component of Vertex if p_{T}, #eta, or #phi == 0.",1000,-10000,10000);
  TH2F* _0MCvtxXvtxYhist = new TH2F("_0MCvtxXvtxYhist","X component vs Y component of Vertex if p_{T}, #eta, or #phi == 0.",1000,-10000,10000,1000,-10000,10000);

  //set up text file output (when pt, eta, or phi is 0)
  char outfile_path[200];
  sprintf(outfile_path,"../txtfiles/%s/%s%s/pt_eta_phi_is0.txt",channel,channel,m);
  ofstream outfile(outfile_path);

  //get entries for data_tree (read in the old tree), set new variables, fill new tree
  Int_t nentries = (Int_t)tree->GetEntries();
  cout<<"number of entries is: "<<nentries<<endl;
  
  for (Int_t i=0; i<nentries; i++) {
    tree->GetEntry(i);
    cout<<"for entry # "<<i<<", NMCpart is: "<<NMCpart<<endl;

    Int_t Nmuons = 0;
    Int_t Nstaus = 0;
    Int_t Nneutralinos = 0;

    _Eventhist->Fill(Event);
    _NMCparthist->Fill(NMCpart);

    for (Int_t j=0; j<NMCpart; j++) {
      if (MCstatus[j]>0){
	//cout<<"Entry # "<<i<<", particle # "<<j<<", MCstatus[j] "<<MCstatus[j]<<endl;

	_MCpidhist->Fill(MCpid[j]);
	_MCstatushist->Fill(MCstatus[j]);
	_MCpthist->Fill(MCpt[j]);
	_MCetahist->Fill(MCeta[j]);
	_MCphihist->Fill(MCphi[j]);
	_MCvtxXhist->Fill(MCvtxX[j]);
	_MCvtxYhist->Fill(MCvtxY[j]);
	_MCvtxZhist->Fill(MCvtxZ[j]);
	_MCvtxXvtxYhist->Fill(MCvtxX[j],MCvtxY[j]);
	
	if(abs(MCpid[j])==13){
	  cout<<"muon with particle # "<<j<<" has MCvtxX[j] of: "<<MCvtxX[j]<<endl;
	  Nmuons++;
	  _mustatushist->Fill(MCstatus[j]);
	  _mupthist->Fill(MCpt[j]);
	  _muetahist->Fill(MCeta[j]);
	  _muphihist->Fill(MCphi[j]);
	  _muvtxXhist->Fill(MCvtxX[j]);
	  _muvtxYhist->Fill(MCvtxY[j]);
	  _muvtxZhist->Fill(MCvtxZ[j]);
	  _muvtxXvtxYhist->Fill(MCvtxX[j],MCvtxY[j]);
	}
	
	if(abs(MCpid[j])==1000015){
	  Nstaus++;
	  _staustatushist->Fill(MCstatus[j]);
	  _staupthist->Fill(MCpt[j]);
	  _stauetahist->Fill(MCeta[j]);
	  _stauphihist->Fill(MCphi[j]);
	  _stauvtxXhist->Fill(MCvtxX[j]);
	  _stauvtxYhist->Fill(MCvtxY[j]);
	  _stauvtxZhist->Fill(MCvtxZ[j]);
	  _stauvtxXvtxYhist->Fill(MCvtxX[j],MCvtxY[j]);
	}
	
	if(abs(MCpid[j])==1000022){
	  cout<<"neutralino with particle # "<<j<<" has MCvtxX[j] of: "<<MCvtxX[j]<<endl;
	  Nneutralinos++;
	  _neutralinostatushist->Fill(MCstatus[j]);
	  _neutralinopthist->Fill(MCpt[j]);
	  _neutralinoetahist->Fill(MCeta[j]);
	  _neutralinophihist->Fill(MCphi[j]);
	  _neutralinovtxXhist->Fill(MCvtxX[j]);
	  _neutralinovtxYhist->Fill(MCvtxY[j]);
	  _neutralinovtxZhist->Fill(MCvtxZ[j]);
	  _neutralinovtxXvtxYhist->Fill(MCvtxX[j],MCvtxY[j]);
	}

	if (MCpt[j]==0. || MCeta[j]==0. || MCphi[j]==0.){
	  outfile<<"For entry # "<<i<<", particle # "<<j<<", MCpid[j] is: "<<MCpid[j]<<", MCstatus[j] is: "<<MCstatus[j]<<", MCpt[j] is: "<<MCpt[j]<<", MCeta[j] is: "<<MCeta[j]<<",	MCphi[j] is: "<<MCphi[j]<<", MCvtxX[j] is: "<<MCvtxX[j]<<", MCvtxY[j] is: "<<MCvtxY[j]<<", MCvtxZ[j] is: "<<MCvtxZ[j]<<endl;
	  _0MCnumhist->Fill(j);
	  _0MCpidhist->Fill(MCpid[j]);
	  _0MCstatushist->Fill(MCstatus[j]);
	  _0MCpthist->Fill(MCpt[j]);
	  _0MCetahist->Fill(MCeta[j]);
	  _0MCphihist->Fill(MCphi[j]);
	  _0MCvtxXhist->Fill(MCvtxX[j]);
	  _0MCvtxYhist->Fill(MCvtxY[j]);
	  _0MCvtxZhist->Fill(MCvtxZ[j]);
	  _0MCvtxXvtxYhist->Fill(MCvtxX[j],MCvtxY[j]);
	}


      }//end if MCstatus[j]>0
      else cout<<"MCstatus["<<j<<"] is "<<MCstatus[j]<<" !!!!!!!!"<<endl;
    }//end of loop over MC particles

    _Nmuhist->Fill(Nmuons);
    _Nstauhist->Fill(Nstaus);
    _Nneutralinohist->Fill(Nneutralinos);

    //find difference in muon/neutralino vertex position
    const int Nmuneutralino = Nmuons + Nneutralinos;
    //vector<float> vtxX_muneutralino[Nmuneutralino];
    vector<float> vtxX_muneutralino;

    cout<<"Nmuons is: "<<Nmuons<<endl;
    cout<<"Nneutralinos is: "<<Nneutralinos<<endl;
    cout<<"Nmunuetralino is: "<<Nmuneutralino<<endl;


    for (Int_t j=0; j<NMCpart; j++) {
      if (abs(MCpid[j])==13 || abs(MCpid[j])==1000022){
	vtxX_muneutralino.push_back(MCvtxX[j]);
	//cout<<"vtxX_muneutralino["<<k<<"] assigned is: "<<vtxX_muneutralino[k]<<endl;
      } //end of if muon or neutralino
    } //end of loop over MC particles

    for (Int_t k=0; k<Nmuneutralino; k++) {
      cout<<"vtxX_muneutralino["<<k<<"] is: "<<vtxX_muneutralino.at(k)<<endl;
    } //end of loop over muons and neutralinos

    for (Int_t k=0; k<Nmuneutralino; k++) {
      for (Int_t l=0; l<Nmuneutralino; l++) {
	if (k<l){
	  cout<<"  vtxX_muneutralino["<<k<<"]-vtxX_muneutralino["<<l<<"] is: "<<vtxX_muneutralino[k]-vtxX_muneutralino[l]<<endl;
	}
      }
    }

    //cout<<"  vtxX_muneutralino["<<j<<"] is: "<<vtxX_muneutralino[j]<<endl;


  }//end of loop over events

  outfile.close();
  fnew.Write();  
  
}
