import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("TriggerAnalyzer.MeanTimerAnalyzer.meanTimerAnalyzer_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.GlobalTag.globaltag = 'PRE_STA72_V4::All'

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
        'file:/afs/cern.ch/work/j/jalimena/CMSSW_7_2_0_pre6/src/HLTrigger/Configuration/test/outputA_mchamp500_womeantimer.root'
    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_mchamp500_womeantimer.root' )
                                    )


process.p = cms.Path(process.demo)
