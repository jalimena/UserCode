from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()


config.General.requestName = 'HltExoDqm_NoBPTX_Run2017B_PromptReco_v1_2July2017_withBugFix'
config.General.workArea = 'crab'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'hltEXOdqm_DQM.py'
#config.JobType.maxMemoryMB = 4000

config.Data.inputDataset = '/NoBPTX/Run2017B-PromptReco-v1/AOD'
config.Data.outputDatasetTag = 'ExoHltDqm_withBugFix'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
config.Data.lumiMask = '/uscms_data/d3/alimena/2017TriggerDQM_take2/CMSSW_9_2_4/src/Cert_13TeV_2017_HCAL_DCS_GOOD.txt'
config.Data.outLFNDirBase = '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.ignoreLocality = True

#config.Site.whitelist = ["T1_US_FNAL"]
config.Site.storageSite = 'T3_US_FNALLPC'
