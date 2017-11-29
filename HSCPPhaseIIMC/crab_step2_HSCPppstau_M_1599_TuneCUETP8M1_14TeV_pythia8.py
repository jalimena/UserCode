from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'HSCPppstau_M_1599_TuneCUETP8M1_14TeV_pythia8_912_DigiHlt'
config.General.workArea = 'crab'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'step2_DIGI_L1_DIGI2RAW_HLT_PU.py'
config.JobType.maxMemoryMB = 4000

config.Data.inputDataset = '/HSCPppstau_M_1599_TuneCUETP8M1_14TeV_pythia8_912/jalimena-GenSim-97eba4a2a2d9ef6e868ffc3071ab1506/USER'
config.Data.outputDatasetTag = 'DigiHlt_PU200'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.ignoreLocality = True

config.Site.whitelist = ["T1_US_FNAL"]
config.Site.storageSite = 'T3_US_FNALLPC'
