from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'HSCPppstau_M_1599_TuneCUETP8M1_14TeV_pythia8_912_GenSim'
config.General.workArea = 'crab'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = 'EXO-PhaseIITDRSpring17GS-00041_1_cfg.py'

config.Data.outputPrimaryDataset = 'HSCPppstau_M_1599_TuneCUETP8M1_14TeV_pythia8_912'
config.Data.outputDatasetTag = 'GenSim'
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 10
NJOBS = 10000  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True

config.Site.storageSite = 'T3_US_FNALLPC'
