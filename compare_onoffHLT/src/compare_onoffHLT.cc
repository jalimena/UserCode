// -*- C++ -*-
//
// Package:    compare_onoffHLT
// Class:      compare_onoffHLT
// 
/**\class compare_onoffHLT compare_onoffHLT.cc compare_onoffHLT/src/compare_onoffHLT.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Juliette Marie Alimena,40 3-A02,+41227671577,
//         Created:  Fri Apr 22 15:46:58 CEST 2011
// $Id: compare_onoffHLT.cc,v 1.1 2011/07/12 08:49:33 jalimena Exp $
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

class compare_onoffHLT : public edm::EDAnalyzer {
public:
  explicit compare_onoffHLT(const edm::ParameterSet&);
  ~compare_onoffHLT();
  
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
  //edm::Service<TFileService> fs;  
  
  //void init(const edm::TriggerResults &, const edm::TriggerNames & HLTNames);
  
  edm::InputTag triggerLabelON_;
  edm::InputTag triggerLabelOFF_;
  
  //Trigger Stuff
  edm::TriggerNames triggerNames_;
  edm::TriggerNames testNames_;
  bool bTrigExist, bTrigInit, bPassTrigs; 
  unsigned int nPaths, nDatasets;
  vector<string> triggerNames;
  vector< vector<string> > moduleLabel;
  vector<unsigned int> nModules, nPaths_PD;
  vector<string> datasetNames;
  vector<vector<string> > datasetContent;
  vector< vector< vector<bool> > > triggerNames_matched;

  string ElTrig, MuTrig;
  vector <string> HLT_Names;
  vector <char> namess;
  vector <int>  HLT_Pass;
  
  string processNameON_;
  string processNameOFF_;
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
  vector<int> trigger_online;
  vector<int> trigger_offline;
  int poolSize;
  TH1F* jetmet ;
  TH1F* muon ;
  TH1F* egamma;
  TH1F* btau ;
  TH1F* beam ; //Physics - trackPOinting
  TH1F* alca ; //IsoTrk - random + 2alca_cosm            
  TH1F* minbias ; //excluding final path       
  TH1F* lumi;

  TH1D* path_ON_hist;
  TH1D* path_ONnotOFF_hist;
  TH1D* path_OFFnotON_hist;
  TH2D* pathmodule_ONnotOFF_hist;
  TH2D* pathmodule_OFFnotON_hist;

  vector<TH1D*> path_ON_hist_PD;
  vector<TH1D*> path_ONnotOFF_hist_PD;
  vector<TH1D*> path_OFFnotON_hist_PD;
  vector<TH2D*> pathmodule_ONnotOFF_hist_PD;
  vector<TH2D*> pathmodule_OFFnotON_hist_PD;

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
compare_onoffHLT::compare_onoffHLT(const edm::ParameterSet& iConfig):  
  processNameON_(iConfig.getParameter<std::string>("processNameON")),
  processNameOFF_(iConfig.getParameter<std::string>("processNameOFF"))//,
  //triggerName_(iConfig.getParameter<std::string>("triggerName")),
  //triggerResultsTag_(iConfig.getParameter<edm::InputTag>("triggerResults")),
  //triggerEventTag_(iConfig.getParameter<edm::InputTag>("triggerEvent"))

{
  //now do what ever initialization is needed
  //define parameters
  nPaths=0;
  bTrigInit = false;
  nTot = 0;
  
  //get parameters from cfg
  triggerLabelON_ = iConfig.getUntrackedParameter<edm::InputTag>("triggerTagON");  
  triggerLabelOFF_ = iConfig.getUntrackedParameter<edm::InputTag>("triggerTagOFF");  
  Nfiles_ = iConfig.getUntrackedParameter<int>("Nfiles",0);
  Normalization_ = iConfig.getUntrackedParameter<double>("Norm",40.);
  isRealData_ = iConfig.getUntrackedParameter<bool>("isRealData",true);
  LumiSecNumber_ = iConfig.getUntrackedParameter<int>("LumiSecNumber",1);
  
}


compare_onoffHLT::~compare_onoffHLT()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
compare_onoffHLT::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
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
  if (trON.size()!=triggerListON.size()) cout << "ERROR: length of names and paths not the same: " << triggerListON.size() << "," << trON.size() << endl;  
  
  vector<string> triggerListOFF;
  Service<service::TriggerNamesService> tnsOFF;
  bool foundNamesOFF = tnsOFF->getTrigPaths(trOFF,triggerListOFF);
  if (!foundNamesOFF) cout << "Could not get trigger names!\n";
  if (trOFF.size()!=triggerListOFF.size()) cout << "ERROR: length of names and paths not the same: " << triggerListOFF.size() << "," << trOFF.size() << endl;  
  


  //loop over trigger paths (online and offline)
  for (unsigned int i=0; i<nPaths; i++) {
    //cout<<"Trigger number "<<i<<" is called "<<triggerNames[i]<<endl;

    bool path_fails_prescaler = false; 
    bool online_accept = false; 
    bool offline_accept = false;
    int module_indexON = -1;
    int module_indexOFF = -1;
    string module_index_labelON;
    string module_index_labelOFF;

    //const vector<string> & moduleLabels(hltConfig_.moduleLabels(i));

    //if online or offline accepted
    if (trON[i].wasrun()==1 && trON[i].accept()==1 && trON[i].error()==0) {
      online_accept = true;
      trigger_online[i]++;
      path_ON_hist->Fill(i);
      for (unsigned int a=0; a<nDatasets; a++) {
	for (unsigned int b=0; b<nPaths_PD[a]; b++) {
	  if (triggerNames_matched[i][a][b]) path_ON_hist_PD[a]->Fill(b);
	}
      }
    }
    if (trOFF[i].wasrun()==1 && trOFF[i].accept()==1 && trOFF[i].error()==0) {
      offline_accept = true;
      trigger_offline[i]++;
    }

    //if online or offline failed
    if (trON[i].accept() == 0){
      module_indexON = trON[i].index();
      module_index_labelON = moduleLabel[i][module_indexON];
    }
    if (trOFF[i].accept() == 0) {
      module_indexOFF = trOFF[i].index();
      module_index_labelOFF = moduleLabel[i][module_indexOFF];
    }

    //for each path, loop over modules and find if a path fails on a prescaler
    for (unsigned int j=0; j<nModules[i]; ++j) {
      //const string& moduleLabel(moduleLabel[j]);
      const string& moduleType = hltConfig_.moduleType(moduleLabel[i][j]);
      if ( ((trON[i].accept()==0 && j==trON[i].index()) || (trOFF[i].accept()==0 && j==trOFF[i].index())) && (moduleType=="HLTPrescaler" || moduleType=="TriggerResultsFilter") ) path_fails_prescaler = true;
    }

    //check agreement between online and offline
    if (!path_fails_prescaler){ //ignore paths that fail on a prescale
      if(online_accept && !offline_accept){ //online fires but offline doesn't
	path_ONnotOFF_hist->Fill(i);
	pathmodule_ONnotOFF_hist->Fill(i,module_indexOFF); //module and path for where it fails offline
	for (unsigned int a=0; a<nDatasets; a++) {
	  for (unsigned int b=0; b<nPaths_PD[a]; b++) {
	    if (triggerNames_matched[i][a][b]){
	      path_ONnotOFF_hist_PD[a]->Fill(b);
	      pathmodule_ONnotOFF_hist_PD[a]->Fill(b,module_indexOFF); //module and path for where it fails offline
	    }
	  }
	}
      }
      if(!online_accept && offline_accept){//offline fires but online doesn't
	path_OFFnotON_hist->Fill(i);
	pathmodule_OFFnotON_hist->Fill(i,module_indexON); //module and path for where it fails online
	for (unsigned int a=0; a<nDatasets; a++) {
	  for (unsigned int b=0; b<nPaths_PD[a]; b++) {
	    if (triggerNames_matched[i][a][b]){
	      path_OFFnotON_hist_PD[a]->Fill(b);
	      pathmodule_OFFnotON_hist_PD[a]->Fill(b,module_indexON); //module and path for where it fails online
	    }
	  }
	}
      }
    }

  }//end of loop over trigger paths


}


// ------------ method called once each job just before starting event loop  ------------
void 
compare_onoffHLT::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
compare_onoffHLT::endJob() 
{
}

// ------------ method called when starting to processes a run  ------------
void 
compare_onoffHLT::beginRun(edm::Run const& iRun, edm::EventSetup const& iSetup)
{
  edm::Service<TFileService> fs;  
  void init(const edm::TriggerResults &, const edm::TriggerNames & HLTNames);

  bool changed(true);
  unsigned int nPathsON=0, nPathsOFF=0;
  vector<string> triggerNamesON, triggerNamesOFF;
  vector<string> temp;
  vector <vector<string> > temp1;
  vector <vector<string> > moduleLabelON, moduleLabelOFF;
  unsigned int max_nModules=0;
  vector<unsigned int> max_nModules_PD;
  bool TriggerModuleNamesOK = true;

  //---------------------------------------hltConfig for online-------------------------------
  if (hltConfig_.init(iRun,iSetup,processNameON_,changed)) {
    // if init returns TRUE, initialisation has succeeded!
    if (changed) {
      cout<<"hlt_Config_.init returns true for online"<<endl;
      // The HLT config has actually changed wrt the previous Run, hence rebook your
      // histograms or do anything else dependent on the revised HLT config
      // check if trigger name in (new) config
      triggerNamesON = hltConfig_.triggerNames();

      //loop over trigger paths
      nPathsON = hltConfig_.size();
      for (unsigned int i=0; i<nPathsON; i++) {
	temp.clear();
	//const vector<string> & moduleLabelsON(hltConfig_.moduleLabels(i));
	for (unsigned int j=0; j<hltConfig_.moduleLabels(i).size(); j++) {
	  temp.push_back(hltConfig_.moduleLabel(i,j));
	}
	moduleLabelON.push_back(temp);
      }

    }
  } 
  else {
    // if init returns FALSE, initialisation has NOT succeeded, which indicates a problem
    // with the file and/or code and needs to be investigated!
    cout<<" HLT config extraction failure with process name " << processNameON_;
    // In this case, all access methods will return empty values!
  }

  //-------------------hltConfig for offline----------------------------------------
  if (hltConfig_.init(iRun,iSetup,processNameOFF_,changed)) {
    // if init returns TRUE, initialisation has succeeded!
    if (changed) {
      cout<<"hlt_Config_.init returns true for offline"<<endl;
      // The HLT config has actually changed wrt the previous Run, hence rebook your
      // histograms or do anything else dependent on the revised HLT config
      // check if trigger name in (new) config
      triggerNamesOFF = hltConfig_.triggerNames();

      //loop over trigger paths
      nPathsOFF = hltConfig_.size();
      for (unsigned int i=0; i<nPathsOFF; i++) {
	temp.clear();
	//const vector<string> & moduleLabelsOFF(hltConfig_.moduleLabels(i));
	for (unsigned int j=0; j<hltConfig_.moduleLabels(i).size(); j++){
	  temp.push_back(hltConfig_.moduleLabel(i,j));
	}
	moduleLabelOFF.push_back(temp);
      }

    }
  } 
  else {
    // if init returns FALSE, initialisation has NOT succeeded, which indicates a problem
    // with the file and/or code and needs to be investigated!
    cout<<" HLT config extraction failure with process name " << processNameOFF_;
    // In this case, all access methods will return empty values!
  }

  //------------------compare online and offline hltConfig------------------------
  if (nPathsON != nPathsOFF || nPathsON==0 || nPathsOFF==0){
    cout<<"Different number of paths online and offline!! There are "<<nPathsON<<" paths online and "<<nPathsOFF<<" paths offline!!!"<<endl;
    TriggerModuleNamesOK = false;
  }
  else{
    nPaths = nPathsON;
    for (unsigned int i=0; i<nPaths; i++) {
      if (triggerNamesON[i]!=triggerNamesOFF[i]){
	cout<<"Paths online are in a different order than paths offline!!"<<endl;
	for (unsigned int a=0; a<nPaths; a++) {
	  if (triggerNamesON[i]==triggerNamesOFF[a]) cout<<"Path "<<triggerNamesON[i]<<" corresponds to path number "<<i<<" for online and path number "<<a<<" for offline"<<endl;
	}
      }
      else {
	if (moduleLabelON[i].size()!=moduleLabelOFF[i].size()){
	  cout<<"For "<<triggerNamesON[i]<<", different number of modules!! There are "<<moduleLabelON[i].size()<<" modules online and "<<moduleLabelOFF[i].size()<<" modules offline!!"<<endl;
	  TriggerModuleNamesOK = false;
	}
	else{
	  if (moduleLabelON[i].size()>max_nModules) max_nModules=moduleLabelON[i].size();
	  for (unsigned int j=0; j<moduleLabelON[i].size(); j++) {
	    if (moduleLabelON[i][j]!=moduleLabelOFF[i][j]){
	      cout<<"For "<<triggerNamesON[i]<<", modules online and modules offline have different names!!"<<endl;	      
	      cout<<"  module "<<j<<" is called "<<moduleLabelON[i][j]<<" online, and called "<<moduleLabelOFF[i][j]<<" offline"<<endl;
	    }
	  }
	}
      }
    }
  }

  //----------------------------------------------------------------------------------------------------------

  //if everything is good:
  //save path and module names to be used in event loop, print out the module names and types for each path
  //get paths in each dataset
  if (TriggerModuleNamesOK){

    //------------all paths--------------
    cout<<"There are "<<nPaths<<" paths in total"<<endl;
    cout<<"Maximum number of modules over all paths is: "<<max_nModules<<endl;
    triggerNames = triggerNamesON;
    moduleLabel = moduleLabelON;    
    for (unsigned int i=0; i<nPaths; i++) {
      trigger_online.push_back(0);
      trigger_offline.push_back(0);
      nModules.push_back(moduleLabelON[i].size());
      cout<<endl<<"For "<<triggerNames[i]<<" (trigger number "<<i<<"), there are "<<nModules[i]<<" modules:"<<endl;
      for (unsigned int j=0; j<nModules[i]; j++) {
	const string& moduleType = hltConfig_.moduleType(moduleLabel[i][j]);
	cout<<"  module "<<j<<" is "<<moduleLabel[i][j]<<" and is of type "<<moduleType<<endl;
      }
    }

    //---------paths per dataset-------------------------------------------
    //get datasets, initialize max_nModules_PD
    datasetNames = hltConfig_.datasetNames();
    nDatasets = datasetNames.size();    
    for (unsigned int a=0; a<nDatasets; a++) {
      max_nModules_PD.push_back(0);
    }

    //loop over datasets, paths in each dataset
    for (unsigned int a=0; a<nDatasets; a++) {
      temp.clear();
      vector<string> datasetContent_ = hltConfig_.datasetContent(a);
      nPaths_PD.push_back(datasetContent_.size());
      cout<<endl<<"For dataset "<<datasetNames[a]<<" (dataset number "<<a<<"), there are "<<nPaths_PD[a]<<" paths:"<<endl;
      for (unsigned int b=0; b<nPaths_PD[a]; b++) {
	cout<<"  path "<<b<<" is "<<datasetContent_[b]<<endl;
	temp.push_back(datasetContent_[b]);
      }
      datasetContent.push_back(temp);
    }

    //match trigger names in full list to trigger names per dataset; find max number of modules over all triggers in each dataset
    //find matches
    vector <vector<bool> > temp1;
    vector<bool> temp2;
    for (unsigned int i=0; i<nPaths; i++) {
      temp1.clear();
      for (unsigned int a=0; a<nDatasets; a++) {
	temp2.clear();
	for (unsigned int b=0; b<nPaths_PD[a]; b++) {
	  if (triggerNames[i]==datasetContent[a][b]){
	    temp2.push_back(true);	    
	    //cout<<"Matched trigger name is: "<<datasetContent[a][b]<<" for dataset "<<a<<" and dataset path "<<b<<endl;
	  }
	  else temp2.push_back(false);
	}
	temp1.push_back(temp2);
      }
      triggerNames_matched.push_back(temp1);
    }

    //if matched and # of modules is bigger than all previous ones, take that number as new maximum
    for (unsigned int i=0; i<nPaths; i++) {
      for (unsigned int a=0; a<nDatasets; a++) {
	for (unsigned int b=0; b<nPaths_PD[a]; b++) {
	  if (triggerNames_matched[i][a][b] && nModules[i]>max_nModules_PD[a]) max_nModules_PD[a]=nModules[i];
	}
      }
    }

    //for (unsigned int a=0; a<nDatasets; a++) {
    //cout<<"For dataset "<<datasetNames[a]<<", the max number of modules is: "<<max_nModules_PD[a]<<endl;
    //}

  }//end if all triggers and modules match from online to offline


  //----------------------------------------------------------------------------------------------------------


  //define histograms

  //all paths
  path_ON_hist = fs->make<TH1D>("path_ON_hist","Total Times Online Path Fires",nPaths,0,nPaths);
  path_ONnotOFF_hist = fs->make<TH1D>("path_ONnotOFF_hist","Online Path fires but Offline does not",nPaths,0,nPaths);
  path_OFFnotON_hist = fs->make<TH1D>("path_OFFnotON_hist","Offline Path fires but Online does not",nPaths,0,nPaths);
  pathmodule_ONnotOFF_hist = fs->make<TH2D>("pathmodule_ONnotOFF_hist","Last run module index vs Path for Offline, when Online fired but Offline didn't",nPaths,0,nPaths,max_nModules,0,max_nModules);
  pathmodule_OFFnotON_hist = fs->make<TH2D>("pathmodule_OFFnotON_hist","Last run module index vs Path for Online, when Offline fired but Online didn't",nPaths,0,nPaths,max_nModules,0,max_nModules);
  
  //paths per dataset
  char path_ON_name[100], path_ONnotOFF_name[100], path_OFFnotON_name[100], pathmodule_ONnotOFF_name[100], pathmodule_OFFnotON_name[100];
  //char path_ON_title[200], path_ONnotOFF_title[200], path_OFFnotON_title[200], pathmodule_ONnotOFF_title[200], pathmodule_OFFnotON_title[200];
  for (unsigned int a=0; a<nDatasets; a++) {
    sprintf(path_ON_name,"path_ON_hist_PD[%i]",a);
    sprintf(path_ONnotOFF_name,"path_ONnotOFF_hist_PD[%i]",a);
    sprintf(path_OFFnotON_name,"path_OFFnotON_hist_PD[%i]",a);
    sprintf(pathmodule_ONnotOFF_name,"pathmodule_ONnotOFF_hist_PD[%i]",a);
    sprintf(pathmodule_OFFnotON_name,"pathmodule_OFFnotON_hist_PD[%i]",a);

    TString path_ON_title = "Total Times Online Path Fires (" + datasetNames[a] + " dataset)";
    TString path_ONnotOFF_title = "Online Path fires but Offline does not (" + datasetNames[a] + " dataset)";
    TString path_OFFnotON_title = "Offline Path fires but Online does not (" + datasetNames[a] + " dataset)";
    TString pathmodule_ONnotOFF_title = "Last run module index vs Path for Offline, when Online fired but Offline didn't (" + datasetNames[a] + " dataset)";
    TString pathmodule_OFFnotON_title = "Last run module index vs Path for Online, when Offline fired but Online didn't (" + datasetNames[a] + " dataset)";

    path_ON_hist_PD.push_back(fs->make<TH1D>(path_ON_name,path_ON_title,nPaths_PD[a],0,nPaths_PD[a]));
    path_ONnotOFF_hist_PD.push_back(fs->make<TH1D>(path_ONnotOFF_name,path_ONnotOFF_title,nPaths_PD[a],0,nPaths_PD[a]));
    path_OFFnotON_hist_PD.push_back(fs->make<TH1D>(path_OFFnotON_name,path_OFFnotON_title,nPaths_PD[a],0,nPaths_PD[a]));
    pathmodule_ONnotOFF_hist_PD.push_back(fs->make<TH2D>(pathmodule_ONnotOFF_name,pathmodule_ONnotOFF_title,nPaths_PD[a],0,nPaths_PD[a],max_nModules_PD[a],0,max_nModules_PD[a]));
    pathmodule_OFFnotON_hist_PD.push_back(fs->make<TH2D>(pathmodule_OFFnotON_name,pathmodule_OFFnotON_title,nPaths_PD[a],0,nPaths_PD[a],max_nModules_PD[a],0,max_nModules_PD[a]));
  }
  
}

// ------------ method called when ending the processing of a run  ------------
void 
compare_onoffHLT::endRun(edm::Run const&, edm::EventSetup const&)
{
  //all paths
  cout<<endl;
  for (unsigned int i=0; i<nPaths; i++) {
    cout<<triggerNames[i]<<" online accepts: "<<trigger_online[i]<<", offline accepts: "<<trigger_offline[i]<<endl;
    path_ON_hist->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
    path_ONnotOFF_hist->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
    path_OFFnotON_hist->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
    pathmodule_ONnotOFF_hist->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
    pathmodule_OFFnotON_hist->GetXaxis()->SetBinLabel(i+1,triggerNames[i].c_str());
  }
  cout<<endl;
  for (unsigned int i=0; i<nPaths; i++) if (trigger_online[i]>trigger_offline[i]) cout<<"Online accepts more than offline for: "<<triggerNames[i]<<" !!!!!!!!!!!!!!!!!!!"<<endl;
  cout<<endl;
  cout<<"Total number of events is: "<<nTot<<endl;

  //paths per dataset
  for (unsigned int a=0; a<nDatasets; a++) {
    for (unsigned int b=0; b<nPaths_PD[a]; b++) {
      path_ON_hist_PD[a]->GetXaxis()->SetBinLabel(b+1,datasetContent[a][b].c_str());
      path_ONnotOFF_hist_PD[a]->GetXaxis()->SetBinLabel(b+1,datasetContent[a][b].c_str());
      path_OFFnotON_hist_PD[a]->GetXaxis()->SetBinLabel(b+1,datasetContent[a][b].c_str());
      pathmodule_ONnotOFF_hist_PD[a]->GetXaxis()->SetBinLabel(b+1,datasetContent[a][b].c_str());
      pathmodule_OFFnotON_hist_PD[a]->GetXaxis()->SetBinLabel(b+1,datasetContent[a][b].c_str());
    }
  }

}

// ------------ method called when starting to processes a luminosity block  ------------
void 
compare_onoffHLT::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
compare_onoffHLT::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
compare_onoffHLT::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(compare_onoffHLT);
