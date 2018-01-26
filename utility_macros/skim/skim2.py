import FWCore.ParameterSet.Config as cms

process = cms.Process("Skim")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring( "/some/input/file"),
                            )

process.out = cms.OutputModule( "PoolOutputModule",
                                fileName = cms.untracked.string( "skim.root" ),
                                outputCommands = cms.untracked.vstring( 'keep *' )
                                )

process.end = cms.EndPath( process.out )
