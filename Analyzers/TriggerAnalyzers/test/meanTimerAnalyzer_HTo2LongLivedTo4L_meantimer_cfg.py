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
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_10_1_zqk.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_11_1_GqV.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_12_1_oCv.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_13_1_Qle.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_14_1_GEZ.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_15_1_rod.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_16_1_lTG.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_17_1_T2w.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_18_1_uZ5.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_19_1_WmP.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_1_1_Izr.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_20_1_8ko.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_21_1_eHJ.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_22_1_gdi.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_2_1_1WX.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_3_1_Zdr.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_4_1_Udm.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_5_1_676.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_6_1_xF1.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_7_1_GA5.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_8_1_iqD.root",
"root://eoscms//eos/cms/store/user/jalimena/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_TSG_PU40BX25_RAWSIM/HTo2LongLivedTo4L_MH_1000_MFF_150_CTau10To1000_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_9_1_aGh.root"

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_HtoLongLivedTo4L_meantimer.root' )
                                    )


process.p = cms.Path(process.demo)
