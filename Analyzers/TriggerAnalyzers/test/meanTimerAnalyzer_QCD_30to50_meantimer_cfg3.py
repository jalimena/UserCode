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
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_326_1_acA.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_327_1_ei5.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_328_1_QVP.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_329_1_PzT.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_32_1_2ra.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_330_1_Hr8.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_331_1_B2Y.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_332_1_i8x.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_333_1_GtR.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_334_1_bOf.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_335_1_mwq.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_336_1_yJ1.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_337_1_iCC.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_338_1_fLs.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_339_1_zlq.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_33_1_3s0.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_340_1_NEN.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_341_1_Lbq.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_342_1_EfW.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_343_1_eqg.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_344_1_FIy.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_345_1_HZj.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_346_1_TPI.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_347_1_N0f.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_348_1_W5I.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_349_1_CcM.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_34_1_pG9.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_350_1_88t.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_351_1_2w0.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_352_1_ABT.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_353_1_PTI.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_354_1_H3Y.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_355_1_fNR.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_356_1_9yL.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_357_1_SFa.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_358_1_ydV.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_359_1_XhR.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_35_1_Vqj.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_360_1_qp3.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_361_1_5wC.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_362_1_hZG.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_363_1_d7A.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_364_1_egh.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_365_1_jbH.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_366_1_JQr.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_367_1_nt6.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_368_1_tVM.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_369_1_TpP.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_36_1_ZX6.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_370_1_lAU.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_371_1_ZWH.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_372_1_HjY.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_373_1_OOe.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_374_1_xWS.root",
"root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-30to50_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-30to50_MuEnriched_meantimer_outputA/38c7e7569b260919fbe54e04a6d16de2/outputA_mchamp500_meantimer_375_1_rP3.root",

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_QCD_30to50_meantimer3.root' )
                                    )


process.p = cms.Path(process.demo)
