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

"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_326_1_3th.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_327_1_Jll.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_328_1_zmN.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_329_1_r5S.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_32_1_OrB.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_330_1_64R.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_331_1_A5f.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_332_2_NaH.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_333_2_1et.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_334_2_snB.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_335_1_kUg.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_336_2_rFb.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_337_1_1AS.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_338_2_AUX.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_339_2_zB2.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_33_1_gz9.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_340_2_Q1V.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_341_2_Mno.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_342_2_52t.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_343_2_ffS.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_344_2_9Pt.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_345_2_PIF.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_346_2_hNj.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_347_2_yWz.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_348_2_qE1.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_349_2_inH.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_34_1_Dc0.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_350_1_i5V.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_351_1_aqW.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_352_2_e40.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_353_2_3Bv.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_354_2_vXX.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_355_2_ci5.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_356_2_6SD.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_357_2_kSM.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_358_2_K8R.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_359_2_Moh.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_35_1_lew.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_360_2_9IM.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_361_2_7qe.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_362_2_Sn6.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_363_2_Phv.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_364_2_Kf5.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_365_2_J93.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_366_2_6Qp.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_367_2_FQJ.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_368_2_PNO.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_369_2_zsA.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_36_1_9oU.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_370_2_mP6.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_371_2_NCV.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_372_2_gwQ.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_373_2_hPo.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_374_2_icS.root",
"root://eoscms//eos/cms/store/user/jalimena/DYToMuMu_M-50_Tune4C_13TeV-pythia8/DYToMuMu_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_375_2_kl5.root",
    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_DYToMuMu_womeantimer3.root' )
                                    )


process.p = cms.Path(process.demo)
