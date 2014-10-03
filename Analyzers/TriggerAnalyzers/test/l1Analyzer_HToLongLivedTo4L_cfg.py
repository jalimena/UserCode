import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("TriggerAnalyzer.MeanTimerAnalyzer.l1Analyzer_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

#process.Tracer = cms.Service("Tracer")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag.connect = cms.string('frontier://FrontierProd/CMS_COND_31X_GLOBALTAG')
process.GlobalTag.globaltag = cms.string('POSTLS162_V2::All')

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_10_1_fPR.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_11_1_8qT.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_12_1_xMA.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_13_1_hs1.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_14_1_q59.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_15_1_rg6.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_16_1_JvG.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_17_1_JS3.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_18_1_9wW.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_19_1_TgZ.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_1_1_LDN.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_20_1_JZd.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_21_1_qqp.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_22_1_HOT.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_2_1_Ney.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_3_1_a0m.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_4_1_mJa.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_5_1_abp.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_6_1_jJS.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_7_1_z7O.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_8_1_4dw.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/1b1b552c86cadae5f0385b4431240ba4/SimL1Emulator_Stage1_PP_9_1_151.root"

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosL1Analyzer_HTo2LongLivedTo4L.root' )
                                    )


process.p = cms.Path(process.demo)
