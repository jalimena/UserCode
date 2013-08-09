#!/bin/tcsh

#define dataset and number of jobs

#data ntuples
#set dataset='/Ntuples/Zmumu_Run2012B'
#set dataset='/Ntuples/SingleMu_Run2012A'
#set dataset='/Ntuples/NoBPTX_Run2012B_period1'
#set dataset='/Ntuples/NoBPTX_Run2012B_period2'
#set dataset='/Ntuples/NoBPTX_Run2012C'
set dataset='/Ntuples/NoBPTX_Run2012D'
#set dataset='/Ntuples/NoBPTX_cosmics_allphi'
#set dataset='/Ntuples/JetTriggers_NoBPTX_Run2012D'

#MC ntuples
#set dataset='/Ntuples/stop600_neutralino200'
#set dataset='/Ntuples/stop100_neutralino30'
#set dataset='/Ntuples/stop100_neutralino50'
#set dataset='/Ntuples/stop200_neutralino75'
#set dataset='/Ntuples/stop300_neutralino109'
#set dataset='/Ntuples/stop400_neutralino214'
#set dataset='/Ntuples/stop500_neutralino316'
#set dataset='/Ntuples/stop600_neutralino417'
#set dataset='/Ntuples/stop700_neutralino518'
#set dataset='/Ntuples/stop800_neutralino618'
#set dataset='/Ntuples/stop900_neutralino718'
#set dataset='/Ntuples/stop1000_neutralino819'
#set dataset='/Ntuples/stop600_neutralino200_decayStoppedParticle2'
#set dataset='/Ntuples/gluino600_neutralino200'
#set dataset='/Ntuples/gluino600_neutralino490'
#set dataset='/Ntuples/gmstau494_neutralino200'
#set dataset='/Ntuples/gmstau100_gravitinop0001'
#set dataset='/Ntuples/gmstau126_gravitinop0001'
#set dataset='/Ntuples/gmstau156_gravitinop0001'
#set dataset='/Ntuples/gmstau200_gravitinop0001'
#set dataset='/Ntuples/gmstau247_gravitinop0001'
#set dataset='/Ntuples/gmstau308_gravitinop0001'
#set dataset='/Ntuples/gmstau370_gravitinop0001'
#set dataset='/Ntuples/gmstau432_gravitinop0001'
#set dataset='/Ntuples/gmstau494_gravitinop0001'
#set dataset='/Ntuples/ppstau494_neutralino200'
#set dataset='/Ntuples/mchamp100'
#set dataset='/Ntuples/mchamp200'
#set dataset='/Ntuples/mchamp300'
#set dataset='/Ntuples/mchamp400'
#set dataset='/Ntuples/mchamp500'
#set dataset='/Ntuples/mchamp600'
#set dataset='/Ntuples/mchamp700'
#set dataset='/Ntuples/mchamp800'
#set dataset='/Ntuples/mchamp900'
#set dataset='/Ntuples/mchamp1000'
#set dataset='/Ntuples/gluino300_neutralino173'
#set dataset='/Ntuples/gluino400_neutralino283'
#set dataset='/Ntuples/gluino500_neutralino387'
#set dataset='/Ntuples/gluino600_neutralino490'
#set dataset='/Ntuples/gluino700_neutralino592'
#set dataset='/Ntuples/gluino800_neutralino693'
#set dataset='/Ntuples/gluino900_neutralino794'
#set dataset='/Ntuples/gluino1000_neutralino894'
#set dataset='/Ntuples/gluino1100_neutralino995'
#set dataset='/Ntuples/gluino1200_neutralino1095'
#set dataset='/Ntuples/gluino1300_neutralino1196'
#set dataset='/Ntuples/gluino1400_neutralino1296'
#set dataset='/Ntuples/gluino1500_neutralino1396'

#gluinos
#set dataset='/HSCPgluino_M-600_Tune4C_8TeV-pythia8/stage2_step1_gluino600_neutralino200_533/700c9d43d31ca9fa4661184c6d2052b7'
#set dataset='/HSCPgluino_M-600_Tune4C_8TeV-pythia8/stage2_step1_gluino600_neutralino200_533_take2/700c9d43d31ca9fa4661184c6d2052b7'

#ppstaus
#set dataset='/HSCPppstau_M-494_TuneZ2star_8TeV-pythia6/stage2_step1_ppstau494_neutralino200_533_forceMuons/abb2e826f10e24ec4e2f91b04c47bb96'

#gmstaus
#set dataset='/HSCPgmstau_M-494_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau494_neutralino200_533/abb2e826f10e24ec4e2f91b04c47bb96'
#set dataset='/HSCPgmstau_M-100_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau100_gravitinop0001_539/5e81afd505d8364701b49d40523adddd'
#set dataset='/HSCPgmstau_M-126_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau126_gravitinop0001_539/3d181c8a8a7ff536694e0bde3da703cf'
#set dataset='/HSCPgmstau_M-156_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau156_gravitinop0001_539/613416f226305b1ffe3a0e6f466b30ce'
#set dataset='/HSCPgmstau_M-200_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau200_gravitinop0001_539/5b29b5ed646e5c8099afd4651c6e2158'
#set dataset='/HSCPgmstau_M-247_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau247_gravitinop0001_539/8c17821472c77590eaa8f299e35c5382'
#set dataset='/HSCPgmstau_M-308_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau308_gravitinop0001_539/f36b5a93f783c17efbe0c4f3ed039165'
#set dataset='/HSCPgmstau_M-370_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau370_gravitinop0001_539/1bea6938da7b0c930a96fcda80f784fc'
#set dataset='/HSCPgmstau_M-432_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau432_gravitinop0001_539/d1bcfa5eaba472b055f25fb963626879'
#set dataset='/HSCPgmstau_M-494_TuneZ2star_8TeV-pythia6/stage2_step1_gmstau494_gravitinop0001_539/477f173831343778c631f24f9c68003b'

#mchamps
#set dataset='/HSCPmchamp6_M-600_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp600_533_forceMuons/5a045082e897aecb4b08e021a52f2a4a'
#set dataset='/HSCPmchamp6_M-600_TuneZ2star_8TeV-pythia6/reco_mchamp600_533_noPU_forceMuons/a5fd4cac2592ce07df32b7c4e3a336e1'
#set dataset='/HSCPmchamp6_M-100_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp100_539/006f4eb20a126896de6bdd0b9730bd6c'
#set dataset='/HSCPmchamp6_M-200_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp200_539/75a6b069505312f01c442575b0069497'
#set dataset='/HSCPmchamp6_M-300_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp300_539/c96d24a94d97b60cfafb8f3b03661d3e'
#set dataset='/HSCPmchamp6_M-400_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp400_539/84276b45ed12e96d542e55e1d2400dce'
#set dataset='/HSCPmchamp6_M-500_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp500_539/c87f97405ea6f5e8fe39c8229eba8fe8'
#set dataset='/HSCPmchamp6_M-600_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp600_539/b5cf8325e68fb1b855c7c1a17706387b'
#set dataset='/HSCPmchamp6_M-700_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp700_539/8a693091767301f5acb74e3225d10484'
#set dataset='/HSCPmchamp6_M-800_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp800_539/9af1459ab7bc5b2e0ba2f5f13984091d'
#set dataset='/HSCPmchamp6_M-900_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp900_539/3e41a1b78b9cc51031aa7dc950bee3b2'
#set dataset='/HSCPmchamp6_M-1000_TuneZ2star_8TeV-pythia6/stage2_step1_mchamp1000_539/fdde24e91ac61d61cda198c812e229df'

#stops
#set dataset='/HSCPstop_M-600_Tune4C_8TeV-pythia6/stage2_step1_stop600_neutralino200_533_forceMuons/5bbab91ee374f4e286f27b99214f0d91'
#set dataset='/HSCPstop_M-100_Tune4C_8TeV-pythia8/stage2_step1_stop100_neutralino30_539/f734428631286f4f612e97d236dd7989'
#set dataset='/HSCPstop_M-100_Tune4C_8TeV-pythia8/stage2_step1_stop100_neutralino50_539/da175b09b882a480966ad02f15ead008'
#set dataset='/HSCPstop_M-200_Tune4C_8TeV-pythia8/stage2_step1_stop200_neutralino75_539/4fa9030c6f496481a8f0bb335903f18b'
#set dataset='/HSCPstop_M-300_Tune4C_8TeV-pythia8/stage2_step1_stop300_neutralino109_539/6bb4030e034a2e046eb9aac80506dbc4'
#set dataset='/HSCPstop_M-400_Tune4C_8TeV-pythia8/stage2_step1_stop400_neutralino214_539/ba5fefab2588558df4d52bae6191ce6c'
#set dataset='/HSCPstop_M-500_Tune4C_8TeV-pythia8/stage2_step1_stop500_neutralino316_539/d4ddb32aa811468b19c81cbcb42422e2'
#set dataset='/HSCPstop_M-600_Tune4C_8TeV-pythia8/stage2_step1_stop600_neutralino417_539/b989c11f74bc89ab9ba21caaa9b5a802'
#set dataset='/HSCPstop_M-700_Tune4C_8TeV-pythia8/stage2_step1_stop700_neutralino518_539/45afb6a3b24b206154f37ee54524e15d'
#set dataset='/HSCPstop_M-800_Tune4C_8TeV-pythia8/stage2_step1_stop800_neutralino618_539/23db47df8142cf0df05d2e35be105ac1'
#set dataset='/HSCPstop_M-900_Tune4C_8TeV-pythia8/stage2_step1_stop900_neutralino718_539/4fac547ce39cfa5d8e9182a5cb42b0f9'
#set dataset='/HSCPstop_M-1000_Tune4C_8TeV-pythia8/stage2_step1_stop1000_neutralino819_539/2573b944d8566b9c3821eff9dc3f3856'


#data ntuples
#set nJobs=128
#set nJobs=516
#set nJobs=140
#set nJobs=300
#set nJobs=327
set nJobs=361
#set nJobs=4
#set nJobs=360
#set nJobs=4
#set nJobs=360

#MC ntuples
#set nJobs=16
#set nJobs=48
#set nJobs=49
#set nJobs=42
#set nJobs=38
#set nJobs=36
#set nJobs=33
#set nJobs=32
#set nJobs=30
#set nJobs=29
#set nJobs=29
#set nJobs=28
#set nJobs=16
#set nJobs=24
#set nJobs=12
#set nJobs=5
#set nJobs=2
#set nJobs=8
#set nJobs=9
#set nJobs=10
#set nJobs=11
#set nJobs=11
#set nJobs=11
#set nJobs=10
#set nJobs=10
#set nJobs=10
#set nJobs=38
#set nJobs=36
#set nJobs=37
#set nJobs=38
#set nJobs=39
#set nJobs=42
#set nJobs=43
#set nJobs=46
#set nJobs=48
#set nJobs=51
#set nJobs=51
#set nJobs=49
#set nJobs=47
#set nJobs=47
#set nJobs=47
#set nJobs=47
#set nJobs=48
#set nJobs=49
#set nJobs=51
#set nJobs=53
#set nJobs=54
#set nJobs=57
#set nJobs=60
#set nJobs=61

#gluinos
#set nJobs=100
#set nJobs=100

#ppstaus
#set nJobs=101

#gmstaus
#set nJobs=107
#set nJobs=193
#set nJobs=254
#set nJobs=201
#set nJobs=203
#set nJobs=201
#set nJobs=207
#set nJobs=201
#set nJobs=202
#set nJobs=206

#mchamps
#set nJobs=101
#set nJobs=42
#set nJobs=210
#set nJobs=207
#set nJobs=201
#set nJobs=207
#set nJobs=208
#set nJobs=202
#set nJobs=204
#set nJobs=206
#set nJobs=212
#set nJobs=211

#stops
#set nJobs=105
#set nJobs=202
#set nJobs=202
#set nJobs=203
#set nJobs=206
#set nJobs=201
#set nJobs=200
#set nJobs=204
#set nJobs=203
#set nJobs=206
#set nJobs=201
#set nJobs=200

#define whether brux6 or lxplus or lpc
set host=${HOST}
set host_=(`expr substr $host 1 4`)

#print list of output file paths and their sizes, and pipe into crabOutput.txt
if ($host_ == 'cmsl') then #(cms)LPC is host
    find /pnfs/cms/WAX/11/store/user/alimena$dataset -type f -ls | awk '{print "path=" $11 " " "size=" $7}' > crabOutput.txt
    #find /pnfs/cms/WAX/resilient/alimena$dataset -type f -ls | awk '{print "path=" $11 " " "size=" $7}' > crabOutput.txt
endif
if ($host_ == 'brux') then #brux6 is host                                                                                                                                       
    find /mnt/hadoop/store/user/jalimena$dataset -type f -ls | awk '{print "path=" $11 " " "size=" $7}' > crabOutput.txt
endif
if ($host_ == 'lxpl') then #lxplus is host                                                                                                                                      
    eos find -f --size /store/user/jalimena$dataset > crabOutput.txt
endif

#run the OutputChecker
./crabOutputChecker $nJobs

