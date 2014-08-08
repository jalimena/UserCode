#!/bin/tcsh
source hosts.csh

#make a directory for everything
#argument is: dataset name (like SingleMu_Run2012A)
set dataset=$argv[1]
mkdir $dataset
cd $dataset

#get the list of ntuples, modify them accordingly
if ($host_ == 'cmsl') then #(cms)LPC is host
    find /pnfs/cms/WAX/11/store/user/alimena/Ntuples/$dataset -type f > list.txt
    #find /pnfs/cms/WAX/resilient/alimena/Ntuples/$dataset -type f > list.txt
    sed -i 's/\/pnfs/dcap:\/\/\/pnfs/g' list.txt
endif
if ($host_ == 'brux') then #brux6 is host
    find /mnt/hadoop/store/user/jalimena/Ntuples/$dataset -type f > list.txt
endif
if ($host_ == 'lxpl') then #lxplus is host
    eos find -f /store/user/jalimena/Ntuples/$dataset > list.txt
    sed -i 's/\/eos/root:\/\/eoscms\/\/eos/g' list.txt
endif

#hadd all the ntuples
hadd -f stoppedHSCPMuonTree.root @list.txt > & hadd.out

#check size of hadded file
ls -lrth stoppedHSCPMuonTree.root

#cp to /mnt or /store/user area
if ($host_ == 'cmsl') then #(cms)LPC is host
    echo "must setup crab first!!!"
    /opt/gLite-3.2.11-1/d-cache/srm/bin/srmcp "file://localhost/${PWD}/stoppedHSCPMuonTree.root" "srm://cmssrm.fnal.gov:8443/11/store/user/alimena/Ntuples/"$dataset"/stoppedHSCPMuonTree.root" > & srmcp.out
    #/opt/gLite-3.2.11-1/d-cache/srm/bin/srmcp "file://localhost/${PWD}/stoppedHSCPMuonTree.root" "srm://cmssrm.fnal.gov:8443/resilient/alimena/Ntuples/"$dataset"/stoppedHSCPMuonTree.root" > & srmcp.out
endif
if ($host_ == 'brux') then #brux6 is host
    lcg-cp -b -v -D srmv2 stoppedHSCPMuonTree.root srm://srm.hep.brown.edu:8443/srm/v2/server'?'SFN=/mnt/hadoop/store/user/jalimena/Ntuples/$dataset/stoppedHSCPMuonTree.root > & lcg-cp.out
endif
if ($host_ == 'lxpl') then #lxplus is host
    cmsStage stoppedHSCPMuonTree.root /store/user/jalimena/Ntuples/$dataset > & stage.out
endif
