import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("Analyzers.TriggerAnalyzers.hltAnalyzer_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

if 'GlobalTag' in process.__dict__:
    from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag as customiseGlobalTag
    process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'MCRUN2_72_V1A')
    process.GlobalTag.connect   = 'frontier://FrontierProd/CMS_CONDITIONS'
    process.GlobalTag.pfnPrefix = cms.untracked.string('frontier://FrontierProd/')
    for pset in process.GlobalTag.toGet.value():
        pset.connect = pset.connect.value().replace('frontier://FrontierProd/', 'frontier://FrontierProd/')
    process.GlobalTag.RefreshEachRun = cms.untracked.bool( False )
    process.GlobalTag.ReconnectEachRun = cms.untracked.bool( False )


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/afs/cern.ch/work/j/jalimena/CMSSW_7_2_1_patch1/src/HLTrigger/Configuration/test/outputA_mchamp500_womeantimer.root'
    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosHltAnalyzer_mchamp500_womeantimer.root' )
                                    )


process.p = cms.Path(process.demo)
