import FWCore.ParameterSet.Config as cms

process = cms.Process("PickEvent")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(2000) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring( "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/02018186-E689-E211-9775-001E67396FD1.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/127F61FC-E889-E211-BE5E-002590200B34.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/162F7006-E589-E211-85E0-003048D45F8E.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/2060F6CC-E489-E211-91F8-001E673967C5.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/281900B2-E489-E211-A8A6-001E67397C79.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/2C41833C-E789-E211-8902-F04DA23BCE4C.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/5CD4A0BD-E989-E211-99B0-001E67397CB0.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/5E3A1306-E589-E211-B356-001E673973D2.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/5EEF896C-E489-E211-B483-002481E100DE.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/6AEA8CE7-E689-E211-B794-002481E0DCD8.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/76DA1C99-E589-E211-AFCA-002481E100DE.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/9CD0474C-E689-E211-A987-001E673987D2.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/AA9BD23B-E889-E211-8F5B-001E67397B1B.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/D28FB27A-E489-E211-A1CC-003048D45FA2.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/E609F69D-E589-E211-BB3D-F04DA23BCE4C.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/ECDF964A-E989-E211-9216-001E673975EE.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/F0274AEF-EA89-E211-A726-003048D45FCA.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/F0E68FF7-E289-E211-9B11-001E67398CAA.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/F85EC599-E589-E211-A517-003048D479BE.root",
                                                               "/store/data/Run2012D/NoBPTX/RECO/22Jan2013-v1/30000/FAAF99D8-E389-E211-9FAF-003048D4776A.root"
                                                               ),
                            eventsToProcess = cms.untracked.VEventRange( #'198230:476058077-198230:476058077', # good cosmics with 2 legs, good timing
        #'198230:491183654-198230:491183654',#lower cosmic only
        #'198230:491580268-198230:491580268' #upper good cosmic
        '1:187737-1:187737'
    )#,
                            #lumisToProcess = cms.untracked.VLuminosityBlockRange('207454:139-207454:165',
                                                                                                #'207454:730-207454:800',
                                                                                                #'207454:1820-207454:1880',
                                                                                                #)
                            )

# HLT bit filter                                                                                                                                                                                                               
#skim events that pass signal or backup trigger
process.load('HLTrigger.HLTfilters.hltHighLevel_cfi')
process.hltHighLevel.TriggerResultsTag = cms.InputTag("TriggerResults","","HLT")
process.hltHighLevel.throw = cms.bool(False)
process.hltHighLevel.HLTPaths = cms.vstring(
    #"HLT_L2Mu20_eta2p1_NoVertex_v*",
    #"HLT_L2Mu10_NoVertex_NoBPTX3BX_v*",
    "HLT_L2Mu20_NoVertex_NoBPTX3BX_v*",
    "HLT_L2Mu30_NoVertex_NoBPTX3BX_v*",
    #"HLT_L2Mu10_NoVertex_NoBPTX3BX_NoHalo_v*",
    "HLT_L2Mu20_NoVertex_NoBPTX3BX_NoHalo_v*",
    "HLT_L2Mu30_NoVertex_NoBPTX3BX_NoHalo_v*",
    "HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo_v*",
    "HLT_L2Mu30_NoVertex_2Cha_NoBPTX3BX_NoHalo_v*",
)

#process.p = cms.Path(process.hltHighLevel)

process.out = cms.OutputModule( "PoolOutputModule",
                                #fileName = cms.untracked.string( "skim.root" ),
                                fileName = cms.untracked.string( "skim_187737_particle0.root" ),
                                #fileName = cms.untracked.string( "skim_187737_particle1.root" ),
                                outputCommands = cms.untracked.vstring( 'keep *' )
                                )

process.end = cms.EndPath( process.out )
