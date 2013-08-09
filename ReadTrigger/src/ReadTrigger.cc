// -*- C++ -*-
//
// Package:    ReadTrigger
// Class:      ReadTrigger
// 
/**\class ReadTrigger ReadTrigger.cc compare_onoffHLT/ReadTrigger/src/ReadTrigger.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Juliette Marie Alimena,40 3-A02,+41227671577,
//         Created:  Fri Apr 22 15:46:58 CEST 2011
// $Id: ReadTrigger.cc,v 1.1 2011/05/10 12:29:56 jalimena Exp $
//
//

using namespace std;

// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/TriggerNamesService.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Common/interface/TriggerResultsByName.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/Common/interface/HLTGlobalStatus.h"
#include "DataFormats/HLTReco/interface/HLTPrescaleTable.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "HLTrigger/HLTcore/interface/HLTConfigData.h"

#include <TMath.h>
#include <TFile.h>
#include <TTree.h>
#include <TH1.h>
#include <TH2.h>
#include <vector>
#include <iostream>
#include <ostream>
//
// class declaration
//

class ReadTrigger : public edm::EDAnalyzer {
public:
  explicit ReadTrigger(const edm::ParameterSet&);
  ~ReadTrigger();
  
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  
  
private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;
  
  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  virtual void endRun(edm::Run const&, edm::EventSetup const&);
  virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
  virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
  
  bool check(std::string process, std::string pCheck);

  // ----------member data ---------------------------  
  TFile* rootfile ;  
  TFile* rootfile1;
  edm::Service<TFileService> fs;  
  
  void init(const edm::TriggerResults &, const edm::TriggerNames & HLTNames);
  
  edm::InputTag triggerLabelON_;
  edm::InputTag triggerLabelOFF_;
  
  //Trigger Stuff
  edm::TriggerNames triggerNames_;
  edm::TriggerNames testNames_;
  bool bTrigExist, bTrigInit, bPassTrigs; 
  string triggerNames[238];

  string ElTrig, MuTrig;
  vector <string> HLT_Names;
  vector <char> namess;
  vector <int>  HLT_Pass;
  
  string processName_;
  string triggerName_;
  edm::InputTag triggerResultsTag_;
  edm::InputTag triggerEventTag_;

  HLTConfigProvider hltConfig_;
  const HLTConfigData* hltConfigData_;

  //overlaps 
  vector <int> previousBitsFired;
  vector <int> allOtherBitsFired;
  vector <int> sPureCount;
  vector <int> pureCount;
        
  unsigned int ui;
  unsigned int uj;
      
  float nTot;
  float nTot1;
  int Nfiles_;
  double Normalization_;
  bool isRealData_;
  int LumiSecNumber_; 
  int trigger_online[238];
  int trigger_offline[238];
  int poolSize;
  TH1F* jetmet ;
  TH1F* muon ;
  TH1F* egamma;
  TH1F* btau ;
  TH1F* beam ; //Physics - trackPOinting
  TH1F* alca ; //IsoTrk - random + 2alca_cosm            
  TH1F* minbias ; //excluding final path       
  TH1F* lumi;
  TH1F* allpaths;

  TH1D* path_ONnotOFF_hist;
  TH1D* path_OFFnotON_hist;
  TH2D* pathmodule_ONnotOFF_hist;
  TH2D* pathmodule_OFFnotON_hist;
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
ReadTrigger::ReadTrigger(const edm::ParameterSet& iConfig):  
  processName_(iConfig.getParameter<std::string>("processName"))//,
  //triggerName_(iConfig.getParameter<std::string>("triggerName")),
  //triggerResultsTag_(iConfig.getParameter<edm::InputTag>("triggerResults")),
  //triggerEventTag_(iConfig.getParameter<edm::InputTag>("triggerEvent"))

{
  //now do what ever initialization is needed
  //define parameters
  bTrigInit = false;
  nTot = 0;
  for (int i=0; i<238; i++){
    trigger_online[i] = 0;
    trigger_offline[i] = 0;
  }
  
  //get parameters from cfg
  triggerLabelON_ = iConfig.getUntrackedParameter<edm::InputTag>("triggerTagON");  
  triggerLabelOFF_ = iConfig.getUntrackedParameter<edm::InputTag>("triggerTagOFF");  
  Nfiles_ = iConfig.getUntrackedParameter<int>("Nfiles",0);
  Normalization_ = iConfig.getUntrackedParameter<double>("Norm",40.);
  isRealData_ = iConfig.getUntrackedParameter<bool>("isRealData",true);
  LumiSecNumber_ = iConfig.getUntrackedParameter<int>("LumiSecNumber",1);

  //define histograms
  path_ONnotOFF_hist = fs->make<TH1D>("path_ONnotOFF_hist","Online Path fires but Offline does not",238,0,238);
  path_OFFnotON_hist = fs->make<TH1D>("path_OFFnotON_hist","Offline Path fires but Online does not",238,0,238);
  pathmodule_ONnotOFF_hist = fs->make<TH2D>("pathmodule_ONnotOFF_hist","Last run module index vs Path for Offline, when Online fired but Offline didn't",238,0,238,200,0,200);
  pathmodule_OFFnotON_hist = fs->make<TH2D>("pathmodule_OFFnotON_hist","Last run module index vs Path for Online, when Offline fired but Online didn't",238,0,238,200,0,200);

}


ReadTrigger::~ReadTrigger()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
ReadTrigger::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  
  //#ifdef THIS_IS_AN_EVENT_EXAMPLE
  //Handle<ExampleData> pIn;
  //iEvent.getByLabel("example",pIn);
  //#endif
  
  //#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
  //ESHandle<SetupData> pSetup;
  //iSetup.get<SetupRecord>().get(pSetup);
  //#endif

  //cout <<"Run/Event/Lumi block "<< iEvent.id().run()<<" "<<iEvent.id().event()<<" "<<iEvent.luminosityBlock() <<endl;
  
  nTot++;
  //Initialize Trigger
  TriggerResults trON;
  Handle<TriggerResults> h_trigResON;
  iEvent.getByLabel(triggerLabelON_, h_trigResON);
  
  trON = *h_trigResON;
  
  
  TriggerResults trOFF;
  Handle<TriggerResults> h_trigResOFF;
  iEvent.getByLabel(triggerLabelOFF_, h_trigResOFF);
  
  trOFF = *h_trigResOFF;

  vector<string> triggerListON;
  Service<service::TriggerNamesService> tnsON;
  bool foundNamesON = tnsON->getTrigPaths(trON,triggerListON);
  if (!foundNamesON) cout << "Could not get trigger names!\n";
  if (trON.size()!=triggerListON.size()) std::cout << "ERROR: length of names and paths not the same: " << triggerListON.size() << "," << trON.size() << endl;  
  
  vector<string> triggerListOFF;
  Service<service::TriggerNamesService> tnsOFF;
  bool foundNamesOFF = tnsOFF->getTrigPaths(trOFF,triggerListOFF);
  if (!foundNamesOFF) cout << "Could not get trigger names!\n";
  if (trOFF.size()!=triggerListOFF.size()) cout << "ERROR: length of names and paths not the same: " << triggerListOFF.size() << "," << trOFF.size() << endl;  
  
  if (trON.size()!=trOFF.size()) cout<<"ERROR: not the same number of paths online: "<<trON.size()<<" and offline: "<<trOFF.size()<<endl;


  //loop over trigger paths (online and offline)
  for (unsigned int i=0; i< trON.size(); i++) {
    triggerNames[i] = triggerListON[i];
    bool path_fails_prescaler = false; 
    bool online_accept = false; 
    bool offline_accept = false;
    int module_indexON = -1;
    int module_indexOFF = -1;
    string module_index_labelON;
    string module_index_labelOFF;

    const vector<string> & moduleLabels(hltConfig_.moduleLabels(i));

    //if online or offline accepted
    if (trON[i].wasrun()==1 && trON[i].accept()==1 && trON[i].error()==0) {
      online_accept = true;
      trigger_online[i]++;
    }
    if (trOFF[i].wasrun()==1 && trOFF[i].accept()==1 && trOFF[i].error()==0) {
      offline_accept = true;
      trigger_offline[i]++;
    }

    //if online or offline failed
    if (trON[i].accept() == 0){
      module_indexON = trON[i].index();
      module_index_labelON = moduleLabels[module_indexON];
    }
    if (trOFF[i].accept() == 0) {
      module_indexOFF = trOFF[i].index();
      module_index_labelOFF = moduleLabels[module_indexOFF];
    }

    //for each path, loop over modules and find if a path fails on a prescaler
    for (unsigned int j=0; j<moduleLabels.size(); ++j) {
      //const string& moduleLabel(moduleLabels[j]);
      const string& moduleType = hltConfig_.moduleType(moduleLabels[j]);
      if ( ((trON[i].accept()==0 && j==trON[i].index()) || (trOFF[i].accept()==0 && j==trOFF[i].index())) && (moduleType=="HLTPrescaler" || moduleType=="TriggerResultsFilter") ) path_fails_prescaler = true;
    }

    //check agreement between online and offline
    if (!path_fails_prescaler){ //ignore paths that fail on a prescale
      if(online_accept && !offline_accept){ //online fires but offline doesn't
	path_ONnotOFF_hist->Fill(i);
	pathmodule_ONnotOFF_hist->Fill(i,module_indexOFF); //module and path for where it fails offline
	cout<<"For run "<<iEvent.id().run()<<", event "<<iEvent.id().event()<<", luminosity block "<<iEvent.luminosityBlock()<<endl;
	cout<<"  Last run module where "<<triggerNames[i]<<" (path number "<<i<<") fails OFFLINE (but accepts online) is: "<<module_index_labelOFF<<" (module index "<<module_indexOFF<<")"<<endl;
      }
      if(!online_accept && offline_accept){//offline fires but online doesn't
	path_OFFnotON_hist->Fill(i);
	pathmodule_OFFnotON_hist->Fill(i,module_indexON); //module and path for where it fails online
	cout<<"For run "<<iEvent.id().run()<<", event "<<iEvent.id().event()<<", luminosity block "<<iEvent.luminosityBlock()<<endl;
	cout<<"  Last run module where "<<triggerNames[i]<<" (path number "<<i<<") fails ONLINE (but accepts offline) is: "<<module_index_labelON<<" (module index "<<module_indexON<<")"<<endl;
      }
    }

  }//end of loop over trigger paths


}


// ------------ method called once each job just before starting event loop  ------------
void 
ReadTrigger::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
ReadTrigger::endJob() 
{
  cout<<endl;
  for (int i=0; i<238; i++) {
    cout<<triggerNames[i]<<" online accepts: "<<trigger_online[i]<<", offline accepts: "<<trigger_offline[i]<<endl;
    path_ONnotOFF_hist->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
    path_OFFnotON_hist->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
    pathmodule_ONnotOFF_hist->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
    pathmodule_OFFnotON_hist->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
  }
  cout<<endl;
  for (int i=0; i<238; i++) if (trigger_online[i]>trigger_offline[i]) cout<<"Online accepts more than offline for: "<<triggerNames[i]<<" !!!!!!!!!!!!!!!!!!!"<<endl;
  cout<<endl;
  cout<<"Total number of events is: "<<nTot<<endl;
}

// ------------ method called when starting to processes a run  ------------
void 
ReadTrigger::beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup)
{
  
  bool changed(true);
  if (hltConfig_.init(iRun,iSetup,processName_,changed)) {
    // if init returns TRUE, initialisation has succeeded!
    if (changed) {
      cout<<"hlt_Config_.init returns true"<<endl;
      // The HLT config has actually changed wrt the previous Run, hence rebook your
      // histograms or do anything else dependent on the revised HLT config
      // check if trigger name in (new) config
      //if (triggerName_!="@") { // "@" means: analyze all triggers in config
      //const unsigned int n(hltConfig_.size());
      //const unsigned int triggerIndex(hltConfig_.triggerIndex(triggerName_));
      //if (triggerIndex>=n) {
      //cout << "ReadTrigger::analyze:"<< " TriggerName " << triggerName_<< " not available in (new) config!" << endl;
      //  cout << "Available TriggerNames are: " << endl;
      //  hltConfig_.dump("Triggers");
      //}
      //}
      //hltConfig_.dump("Streams");
      //hltConfig_.dump("Datasets");
      //hltConfig_.dump("PrescaleTable");
      //hltConfig_.dump("ProcessPSet");
    }
  } 
  else {
    // if init returns FALSE, initialisation has NOT succeeded, which indicates a problem
    // with the file and/or code and needs to be investigated!
    cout<<" HLT config extraction failure with process name " << processName_;
    // In this case, all access methods will return empty values!
  }
  
}

// ------------ method called when ending the processing of a run  ------------
void 
ReadTrigger::endRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
ReadTrigger::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
ReadTrigger::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
ReadTrigger::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(ReadTrigger);
