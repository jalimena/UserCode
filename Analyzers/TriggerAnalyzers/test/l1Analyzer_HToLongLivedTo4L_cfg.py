import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("Analyzers.TriggerAnalyzers.l1Analyzer_cfi")
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
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_10_1_zIt.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_11_2_kHZ.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_12_1_St2.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_13_1_ymn.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_14_2_kpw.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_15_2_uxv.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_16_1_XPK.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_17_1_IyZ.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_18_1_WAm.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_19_1_mWf.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_1_2_Xq8.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_20_1_bZh.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_21_1_zdM.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_22_1_ykb.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_2_1_HRE.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_3_1_Cpf.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_4_2_qU0.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_5_2_Gxr.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_6_1_Llw.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_7_1_D3t.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_8_1_wwB.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_L1Emulator/7852718100b4811f5da7057bf5ff23c3/SimL1Emulator_Stage1_PP_9_1_5hh.root"

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosL1Analyzer_HTo2LongLivedTo4L.root' )
                                    )


process.p = cms.Path(process.demo)
