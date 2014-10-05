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

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(

"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_326_2_Yib.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_327_2_0d8.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_328_2_NLx.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_329_2_BO9.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_32_1_mvc.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_330_2_vq3.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_331_2_lMX.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_332_2_mMg.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_333_2_qzY.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_334_2_ra1.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_335_2_0rE.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_336_2_QpM.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_337_2_0Fy.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_338_2_hvw.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_339_2_5nj.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_33_1_aN0.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_340_2_ydS.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_341_2_uGM.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_342_2_tKB.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_343_2_ync.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_344_2_JFO.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_345_2_9Tg.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_346_2_UlC.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_347_2_lCD.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_348_2_csi.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_349_2_d0v.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_34_1_w6j.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_350_2_Kjh.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_351_2_DJy.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_352_2_Gdh.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_353_2_Goj.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_354_2_gOZ.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_355_2_CJO.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_356_2_3ke.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_357_2_hGS.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_358_2_as9.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_359_2_Nro.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_35_1_1AJ.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_360_2_KVH.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_361_2_Auh.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_362_2_06H.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_363_2_9ob.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_364_2_RsF.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_365_2_fCw.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_366_2_Woy.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_367_2_f3z.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_368_2_Zce.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_369_2_Fd3.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_36_1_LLz.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_370_2_IjN.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_371_2_AKE.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_372_2_q6n.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_373_2_Oon.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_374_2_d1j.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_375_2_6Cj.root",

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_QCD_50to80_womeantimer3.root' )
                                    )


process.p = cms.Path(process.demo)
