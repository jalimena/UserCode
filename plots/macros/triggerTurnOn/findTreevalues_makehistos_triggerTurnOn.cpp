//makes trigger turn on curve histograms from ntuples

#include "iostream"
#include "string"
#include "sstream"
#include "cmath"
#include "vector"
#include "math.h"
#include "TROOT.h"
#include "TRint.h"
#include "TSystem.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TFile.h"
#include "TTree.h"
#include "TMath.h"
#include "TObject.h"
#include "TString.h"
#include "Riostream.h"
#include "../StoppedHSCPMuonEvent.h"

using namespace std;

int main(int argc, char* argv[]){
  if(argc!=5){
    cout<<"ERROR, need more arguments!"<<endl;
    return 1;
  }

  string host=getenv("HOST");
  string host_=host.substr(0,4);
  cout<<"host is: "<<host_<<endl;
  cout<<"started function"<<endl;

  gSystem->Load("libStoppedHSCPMuonNtuples");
  cout<<"loaded library"<<endl;

  string file_dataset = "NoBPTX_Run2012B";
  string sub_run_range = "with_sub_run_range";
  string bx_cut = "with_bx_cut";
  string other_cut = "with_other_cut";
  if(argc==5){
    file_dataset = argv[1];
    sub_run_range = argv[2];
    bx_cut = argv[3];
    other_cut = argv[4];
    cout<<"file_dataset is: "<<file_dataset<<endl;
  }
  
  bool do_sub_run_range = false;
  if (sub_run_range=="with_sub_run_range") do_sub_run_range = true;
  if (sub_run_range=="without_sub_run_range") do_sub_run_range = false;
  cout<<"do_sub_run_range is: "<<do_sub_run_range<<endl;

  bool do_bx_cut = false;
  if (bx_cut=="with_bx_cut") do_bx_cut = true;
  if (bx_cut=="without_bx_cut") do_bx_cut = false;
  cout<<"do_bx_cut is: "<<do_bx_cut<<endl;

  bool do_other_cut = false;
  if (other_cut=="with_other_cut") do_other_cut = true;
  if (other_cut=="without_other_cut") do_other_cut = false;
  cout<<"do_other_cut is: "<<do_other_cut<<endl;


  TString file = "blah";
  if(host_=="cmsl") file = "dcap:///pnfs/cms/WAX/11/store/user/alimena/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";
  if(host_=="brux") file = "/mnt/hadoop/users/alimena/CMS/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";
  if(host_=="lxpl") file = "root://eoscms//eos/cms/store/user/jalimena/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";
  //if(host_=="lxpl") file = "/afs/cern.ch/work/j/jalimena/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";

  cout<<"file is: "<<file<<endl;
  TFile* f1;
  if(host_=="brux") f1 = new TFile(file);
  else f1 = TFile::Open(file);

  if(!f1->IsZombie()) cout<<"opened input file"<<endl;
  else {
    cout<<"problem with input file?"<<endl;
    if(host_=="brux"){
      file = "/mnt/hadoop/store/user/jalimena/Ntuples/" + file_dataset + "/stoppedHSCPMuonTree.root";
      f1 = new TFile(file);
      if(!f1->IsZombie()) cout<<"opened input file on second attempt"<<endl;
    }
  }

  TString new_file = "blah2";
  if(host_=="cmsl") new_file = "/uscms/home/alimena/histos/TriggerTurnOnHistos_" + file_dataset + ".root";
  if(host_=="brux") new_file = "/home/alimena/histos/TriggerTurnOnHistos_" + file_dataset + ".root";
  if(host_=="lxpl") new_file = "/afs/cern.ch/user/j/jalimena/public/histos/TriggerTurnOnHistos_" + file_dataset + ".root";

  TFile* fnew = new TFile(new_file, "recreate");
  cout<<"opened output file"<<endl;


  //get tree
  TTree* tree = (TTree*)f1->Get("stoppedHSCPMuonTree/StoppedHSCPMuonTree");
  //tree->Print();
  //tree->Show(0);

  //StoppedHSCPMuonEvent* events = new StoppedHSCPMuonEvent();
  StoppedHSCPMuonEvent* events = 0;

  //set old branch address
  tree->SetBranchAddress("events",&events);

  //define histograms
  TH1D* id_hist = new TH1D("id_hist","Event Number",100000,0,100000);
  TH1D* run_hist = new TH1D("run_hist","Run Number",8000,192000,200000);
  TH1D* bx_hist = new TH1D("bx_hist","BX",8000,0,4000);
  TH1D* bxWrtCollision_hist = new TH1D("bxWrtCollision_hist","BX w.r.t. Collision",4000,-1000,1000);
  TH1D* bxWrtBunch_hist = new TH1D("bxWrtBunch_hist","BX w.r.t. Bunch",4000,-1000,1000);

  TH1D* muStandAlonePt_numerator_hist = new TH1D("muStandAlonePt_numerator_hist","StandAlone Muon p_{T}",200,0,200);
  TH1D* muStandAlonePt_denominator_hist = new TH1D("muStandAlonePt_denominator_hist","StandAlone Muon p_{T}",200,0,200);

  //get entries for data_tree (read in the old tree), set new variables, fill new tree
  Int_t nentries = tree->GetEntriesFast();
  //Int_t nentries = tree->GetEntries();
  cout<<"number of entries is: "<<nentries<<endl;
  
  int pass_bx_cut = 0;
  int pass_trigger_cut = 0;

  for (Int_t i=0; i<nentries; i++) {
  //for (Int_t i=0; i<2000; i++) {    
  //for (Int_t i=0; i<100; i++) {
    tree->GetEntry(i);
    if(i%50000==0) cout<<"i is: "<<i<<endl;

    if( (do_sub_run_range && events->run>=198346 && events->run<=198487) || (!do_sub_run_range)){

      if ( (do_bx_cut && TMath::Abs(events->bxWrtCollision)>=2. && TMath::Abs(events->bxWrtBunch)>=2.) || (!do_bx_cut) ){
	pass_bx_cut++;
	
	if(events->mu_StandAlone_N>0){
	  if(TMath::Abs(events->muStandAloneEta[0])<1.0){
	    if( (events->muStandAloneTrackNChambersDt[0] + events->muStandAloneTrackNChambersCsc[0])>1 ){
	      
	      muStandAlonePt_denominator_hist->Fill(events->muStandAlonePt[0],1.0);
	      
	      //pass trigger
	      if ( (do_other_cut && (events->hltL2Mu20NoVertexNoBptx3BX || events->hltL2Mu30NoVertexNoBptx3BX || events->hltL2Mu20NoVertexNoBptx3BXNoHalo || events->hltL2Mu30NoVertexNoBptx3BXNoHalo || events->hltL2Mu20NoVertex2ChaNoBptx3BXNoHalo || events->hltL2Mu30NoVertex2ChaNoBptx3BXNoHalo ) ) || (!do_other_cut) ){
		pass_trigger_cut++;
		
		
		id_hist->Fill(events->id,1.0);
		run_hist->Fill(events->run,1.0);
		bx_hist->Fill(events->bx,1.0);
		bxWrtCollision_hist->Fill(events->bxWrtCollision,1.0);
		bxWrtBunch_hist->Fill(events->bxWrtBunch,1.0);
		
		muStandAlonePt_numerator_hist->Fill(events->muStandAlonePt[0],1.0);
		
	      } //end of pass trigger
	    }//end of noise cut
	  }//end of eta<1 cut
	} //end of at least 1 SA muon
      }//end of bx_cut
    }//end of sub run range
  }//end of loop over entries


  cout<<endl;
  cout<<"number of events passing bx cut is: "<<pass_bx_cut<<endl;
  cout<<"number of events passing trigger cut is: "<<pass_trigger_cut<<endl;

  fnew->Write();
  
  return(0);
}


