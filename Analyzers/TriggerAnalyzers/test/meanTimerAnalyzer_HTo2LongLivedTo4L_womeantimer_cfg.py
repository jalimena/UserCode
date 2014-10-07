import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("Analyzers.TriggerAnalyzers.meanTimerAnalyzer_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

#process.Tracer = cms.Service("Tracer")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

if 'GlobalTag' in process.__dict__:
    from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag as customiseGlobalTag
    process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'auto:run2_mc_GRun')
    process.GlobalTag.connect   = 'frontier://FrontierProd/CMS_CONDITIONS'
    process.GlobalTag.pfnPrefix = cms.untracked.string('frontier://FrontierProd/')
    for pset in process.GlobalTag.toGet.value():
        pset.connect = pset.connect.value().replace('frontier://FrontierProd/', 'frontier://FrontierProd/')
    process.GlobalTag.RefreshEachRun = cms.untracked.bool( False )
    process.GlobalTag.ReconnectEachRun = cms.untracked.bool( False )


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(

"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_10_1_QaW.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_11_1_C7a.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_12_1_TeQ.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_13_1_mEP.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_14_1_Lvn.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_15_1_VNL.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_16_1_7Lk.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_17_1_g5E.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_18_1_iwl.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_19_1_4qU.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_1_1_wx9.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_20_1_f2d.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_21_1_lsH.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_22_1_TKq.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_2_1_TIn.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_3_1_jyK.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_4_1_A77.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_5_1_8fA.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_6_1_EIv.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_7_1_gCc.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_8_1_HT2.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_9_1_mIT.root"
    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_HtoLongLivedTo4L_womeantimer.root' )
                                    )


process.p = cms.Path(process.demo)
