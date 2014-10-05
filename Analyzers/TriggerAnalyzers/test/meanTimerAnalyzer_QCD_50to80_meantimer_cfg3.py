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

"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_326_1_Hkz.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_327_1_wxE.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_328_1_iwT.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_329_1_BG8.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_32_1_wWL.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_330_1_uK5.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_331_1_Ujp.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_332_1_dhA.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_333_1_80j.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_334_1_dJu.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_335_1_2Dv.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_336_1_lVb.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_337_1_oz0.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_338_1_pNH.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_339_1_22P.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_33_1_QFd.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_340_1_mhR.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_341_1_B51.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_342_1_QCQ.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_343_1_J9o.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_344_1_VEL.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_345_1_A6M.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_346_1_wYH.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_347_1_Wz3.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_348_1_ohK.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_349_1_XEE.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_34_1_tPL.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_350_1_ttZ.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_351_1_5ZD.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_352_1_g0Y.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_353_1_1tn.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_354_1_mF2.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_355_1_gJe.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_356_1_8ie.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_357_1_NO6.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_358_1_Oqw.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_359_1_xl1.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_35_1_ZPs.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_360_1_NoC.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_361_1_wrL.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_362_1_4m8.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_363_1_Ig3.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_364_1_ODE.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_365_1_RP6.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_366_1_mdJ.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_367_1_wy4.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_368_1_n0t.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_369_1_xi8.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_36_1_rIc.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_370_1_NAi.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_371_1_vZS.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_372_1_hfG.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_373_1_Age.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_374_1_Oe5.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_375_1_mlT.root",

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_QCD_50to80_meantimer3.root' )
                                    )


process.p = cms.Path(process.demo)
