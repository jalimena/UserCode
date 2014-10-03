import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("TriggerAnalyzer.MeanTimerAnalyzer.meanTimerAnalyzer_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.Tracer = cms.Service("Tracer")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.GlobalTag.globaltag = 'PRE_STA72_V4::All'

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_10_2_SgR.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_11_2_VK6.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_12_2_Y8M.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_13_2_Bp4.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_14_2_8b2.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_15_2_v4v.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_16_2_bqi.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_17_2_L5U.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_18_2_m34.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_19_2_ldL.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_1_2_r4N.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_20_2_q6m.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_21_2_xTl.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_22_2_i4P.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_2_2_l5a.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_3_2_AfW.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_4_2_YJo.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_5_2_deS.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_6_2_2cB.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_7_2_0ax.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_8_2_AXl.root',
'root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_9_2_j7X.root'

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_HtoLongLivedTo4L_womeantimer.root' )
                                    )


process.p = cms.Path(process.demo)
