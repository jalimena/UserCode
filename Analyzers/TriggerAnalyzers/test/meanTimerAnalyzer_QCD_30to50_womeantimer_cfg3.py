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

"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_326_1_7uD.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_327_1_cDy.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_328_1_1qg.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_329_1_tx1.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_32_1_dkQ.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_330_1_ZMJ.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_331_1_60K.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_332_1_MK1.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_333_1_ZAl.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_334_1_Hty.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_335_1_IbS.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_336_1_GXq.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_337_1_QSR.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_338_1_sp3.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_339_1_6Fv.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_33_1_aT6.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_340_1_Ggj.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_341_1_Q6B.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_342_1_l4a.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_343_1_Q4i.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_344_1_W3X.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_345_1_0sD.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_346_1_8Gg.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_347_1_dLY.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_348_1_iUo.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_349_1_wsT.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_34_1_S67.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_350_1_IJp.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_351_1_aDY.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_352_1_M1u.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_353_1_GzV.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_354_1_ixF.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_355_1_s9n.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_356_1_ZFM.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_357_1_hs1.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_358_1_0LT.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_359_1_T47.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_35_1_dJ0.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_360_1_WBg.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_361_1_iTE.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_362_1_ANe.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_363_1_qPv.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_364_1_Ml5.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_365_1_tnQ.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_366_1_gsd.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_367_1_4eG.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_368_1_opP.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_369_1_eYG.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_36_1_ERo.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_370_1_gmI.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_371_1_WEi.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_372_1_hnb.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_373_1_BOA.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_374_1_I7t.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_womeantimer_outputA/804833c397580757512fe862d2f783c8/outputA_mchamp500_meantimer_375_1_ukm.root",

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_QCD_30to50_womeantimer3.root' )
                                    )


process.p = cms.Path(process.demo)
