{
  //find particular values in a StoppedHSCPMuon tree, write to new, simpler tree
  //for Lizzy, Alex
#include "StoppedHSCPMuonEvent.h"
  
  gSystem->Load("libStoppedHSCPMuonNtuples");

  const char* filename="/mnt/hadoop/users/alimena/CMS/Ntuples/mchamp100/stoppedHSCPMuonTree.root";
  const char* newfilename="/home/alimena/for_Alex/ReducedNtuples/mchamp100/tree.root";

  //const char* filename="/mnt/hadoop/users/alimena/CMS/Ntuples/NoBPTX_Run2012D/stoppedHSCPMuonTree.root";
  //const char* newfilename="/home/alimena/for_Alex/ReducedNtuples/data/tree.root";

  //const char* filename="/mnt/hadoop/store/user/jalimena/Ntuples/NoBPTX_cosmics_allphi/stoppedHSCPMuonTree.root";
  //const char* newfilename="/home/alimena/for_Alex/ReducedNtuples/cosmics/tree.root";
  
  //get old files, create new files                                                                                                                                                             
  TFile f(filename);
  TFile* fnew = new TFile(newfilename,"RECREATE");
  
  //get old tree, create new tree                                                                                                                                                               
  TTree* tree = (TTree*) f.Get("stoppedHSCPMuonTree/StoppedHSCPMuonTree");
  TTree* tree_new = new TTree("tree","tree");

  StoppedHSCPMuonEvent* events = 0;
  
  // Declaration of leaf types
  Int_t         run;
  Int_t         evt;
  Int_t         bx;
  Int_t         orbit;
  Bool_t          pass_trigger;
  const Int_t mu_StandAlone_N = 9999;
  Double_t muStandAlonePt[mu_StandAlone_N];
  Double_t muStandAloneEta[mu_StandAlone_N];
  Double_t muStandAlonePhi[mu_StandAlone_N];
  Double_t muStandAloneCharge[mu_StandAlone_N];
  Double_t muStandAloneTrackChi2[mu_StandAlone_N];
  Double_t muStandAloneTrackNdof[mu_StandAlone_N];
  Int_t muStandAloneTrackNHits[mu_StandAlone_N];
  const Int_t muStandAloneTof_N = 9999;
  Int_t    muStandAloneTofDirection[muStandAloneTof_N];
  Double_t muStandAloneTofNDof[muStandAloneTof_N];
  Double_t muStandAloneTofInverseBeta[muStandAloneTof_N];
  Double_t muStandAloneTofInverseBetaErr[muStandAloneTof_N];
  Double_t muStandAloneTofFreeInverseBeta[muStandAloneTof_N];
  Double_t muStandAloneTofFreeInverseBetaErr[muStandAloneTof_N];
  Double_t muStandAloneTofTimeAtIpInOut[muStandAloneTof_N];
  Double_t muStandAloneTofTimeAtIpInOutErr[muStandAloneTof_N];
  Double_t muStandAloneTofTimeAtIpOutIn[muStandAloneTof_N];
  Double_t muStandAloneTofTimeAtIpOutInErr[muStandAloneTof_N];

  //set old branch address
  tree->SetBranchAddress("events",&events);
  
  //set new branches
  tree_new->Branch("run",&events->run,"run/I");
  tree_new->Branch("evt",&events->id,"evt/I");
  tree_new->Branch("bx",&events->bx,"bx/I");
  tree_new->Branch("orbit",&events->orbit,"orbit/I");
  tree_new->Branch("pass_trigger",&events->hltL2Mu20NoVertex2ChaNoBptx3BXNoHalo,"pass_trigger/B");
  tree_new->Branch("mu_StandAlone_N",&events->mu_StandAlone_N,"mu_StandAlone_N/I");
  tree_new->Branch("muStandAlonePt",&events->muStandAlonePt);
  tree_new->Branch("muStandAloneEta",&events->muStandAloneEta);
  tree_new->Branch("muStandAlonePhi",&events->muStandAlonePhi);
  tree_new->Branch("muStandAloneCharge",&events->muStandAloneCharge);
  tree_new->Branch("muStandAloneTrackChi2",&events->muStandAloneTrackChi2);
  tree_new->Branch("muStandAloneTrackNdof",&events->muStandAloneTrackNdof);
  tree_new->Branch("muStandAloneTrackNHits",&events->muStandAloneTrackNHits); //number of valid hits
  tree_new->Branch("muStandAloneTof_N",&events->muStandAloneTof_N,"muStandAloneTof_N/I");
  tree_new->Branch("muStandAloneTofDirection",&events->muStandAloneTofDirection);
  tree_new->Branch("muStandAloneTofNDof",&events->muStandAloneTofNDof);
  tree_new->Branch("muStandAloneTofInverseBeta",&events->muStandAloneTofInverseBeta);
  tree_new->Branch("muStandAloneTofInverseBetaErr",&events->muStandAloneTofInverseBetaErr);
  tree_new->Branch("muStandAloneTofFreeInverseBeta",&events->muStandAloneTofFreeInverseBeta);
  tree_new->Branch("muStandAloneTofFreeInverseBetaErr",&events->muStandAloneTofFreeInverseBetaErr);
  tree_new->Branch("muStandAloneTofTimeAtIpInOut",&events->muStandAloneTofTimeAtIpInOut);
  tree_new->Branch("muStandAloneTofTimeAtIpInOutErr",&events->muStandAloneTofTimeAtIpInOutErr);
  tree_new->Branch("muStandAloneTofTimeAtIpOutIn",&events->muStandAloneTofTimeAtIpOutIn);
  tree_new->Branch("muStandAloneTofTimeAtIpOutInErr",&events->muStandAloneTofTimeAtIpOutInErr);

  //get entries for data_tree (read in the old tree), set new variables, fill new tree
  Int_t nentries = tree->GetEntriesFast();
  cout<<"number of entries is: "<<nentries<<endl;
  
  //for (Int_t i = 0; i<100000; i++) {
  for (Int_t i = 0; i<nentries; i++) {
    tree->GetEntry(i);
    //cout<<"muStandAlonePt[0] is: "<<events.muStandAlonePt[0]<<endl;
    tree_new->Fill();    
  }
  
  //print new trees and write to new files
  tree_new->Print();
  tree_new->Write();
  fnew.Close();
  
}
