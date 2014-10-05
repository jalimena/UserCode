import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("Analyzers.TriggerAnalyzers.meanTimerAnalyzer_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

if 'GlobalTag' in process.__dict__:
    from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag as customiseGlobalTag
    process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'auto:run2_mc_GRun')
    process.GlobalTag.connect   = 'frontier://FrontierProd/CMS_CONDITIONS'
    process.GlobalTag.pfnPrefix = cms.untracked.string('frontier://FrontierProd/')
    for pset in process.GlobalTag.toGet.value():
        pset.connect = pset.connect.value().replace('frontier://FrontierProd/', 'frontier://FrontierProd/')
    process.GlobalTag.RefreshEachRun = cms.untracked.bool( False )
    process.GlobalTag.ReconnectEachRun = cms.untracked.bool( False )



process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_326_1_f5I.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_327_1_lc3.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_328_1_85H.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_329_1_tWN.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_32_1_O0g.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_330_1_ETz.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_331_1_WVx.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_332_1_Ufk.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_333_1_7NY.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_334_1_NiF.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_335_1_qcY.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_336_1_yGt.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_337_1_N6d.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_338_1_uvf.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_339_1_kvT.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_33_1_WBb.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_340_1_85N.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_341_1_g0Z.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_342_1_2Dd.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_343_1_9o7.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_344_1_sjt.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_345_1_9J1.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_346_1_oYl.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_347_1_1zH.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_348_2_alr.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_349_1_luo.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_34_1_vnX.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_350_1_2bW.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_351_1_pvC.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_352_1_HWG.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_353_1_hvR.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_354_1_fJl.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_355_1_Oob.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_356_1_ILP.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_357_1_eqd.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_358_1_WeE.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_359_1_z4k.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_35_1_fkg.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_360_1_OM3.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_361_1_ksf.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_362_1_qbz.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_363_1_lgz.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_364_1_t6J.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_365_1_r43.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_366_1_ISe.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_367_1_rxe.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_368_1_SO1.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_369_1_A1c.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_36_1_9Qu.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_370_1_tjy.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_371_1_jbu.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_372_1_2Wq.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_373_1_91P.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_374_1_iIP.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_375_1_IkM.root"
    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_DYToMuMu_meantimer3.root' )
                                    )


process.p = cms.Path(process.demo)
