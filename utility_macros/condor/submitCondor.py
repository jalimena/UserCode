import os

# Number of events per job
maxEvents = 1000

# Initial random seeds. They will be increased by 1 for each successive job.
genSeed = 1
vtxSmearedSeed = 2
g4SimHitsSeed = 3
mixSeed = 4


#for index in range(10):
for index in range(2):
    print "index =", index
    newCfgName = "CosmicMCProduction_cfg_"+str(index)+".py"
    outputFileName = "MuonGun_"+str(index)+".root"
    newCfg = open(newCfgName, "w")
    for line in open("CosmicMCProduction_cfg.py"):
        line = line.replace("MAX_EVENTS", str(maxEvents))
        line = line.replace("GENERATOR_SEED", str(genSeed+index))
        line = line.replace("VTXSMEARED_SEED", str(vtxSmearedSeed+index))
        line = line.replace("G4SIMHITS_SEED", str(g4SimHitsSeed+index))
        line = line.replace("MIX_SEED", str(mixSeed+index))
        line = line.replace("OUTPUT_FILE", outputFileName)
        newCfg.write(line)
    newCfg.close()

    scriptFileName = "runJob_"+str(index)
    scriptFile = open(scriptFileName, "w")
    scriptFile.write("""
#!/bin/tcsh
setenv VO_CMS_SW_DIR /sharesoft/osg/app/cmssoft/cms/
setenv OSG_APP /sharesoft/osg/app/
setenv SCRAM_ARCH slc6_amd64_gcc481
source /cvmfs/cms.cern.ch/cmsset_default.csh
cd /home/alimena/Analysis/CMSSW_7_2_3_patch1/src/
eval `scram runtime -sh`
cmsRun """+newCfgName+"""
"""
)
    scriptFile.close()

    condorFileName = "condor_"+str(index)
    condorFile = open(condorFileName, "w")
    condorFile.write("""
universe = vanilla
Executable = """+scriptFileName+"""
Requirements = Memory >= 199 &&OpSys == \"LINUX\"&& (Arch != \"DUMMY\" )&& Disk > 1000000
Should_Transfer_Files = YES
Transfer_Input_Files = """+newCfgName+"""
Output = Cosmics_"""+str(index)+"""_$(Cluster)_$(Process).stdout
Error = Cosmics_"""+str(index)+"""_$(Cluster)_$(Process).stderr
Log = Cosmics_"""+str(index)+"""_$(Cluster)_$(Process).log
notify_user = ${LOGNAME}@FNAL.GOV
Queue 1
"""
)
    condorFile.close()


    print "condor_submit "+condorFileName
    os.system("condor_submit "+condorFileName)
