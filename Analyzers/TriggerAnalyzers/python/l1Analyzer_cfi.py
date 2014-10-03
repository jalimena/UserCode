import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer('L1Analyzer',
                      #l1CollectionsTag = cms.untracked.string("l1extraParticles")
                      #l1CollectionsTag = cms.untracked.string("l1ExtraLayer2")
                      l1CollectionsTag = cms.untracked.InputTag("l1ExtraLayer2","","L1TEMULATION")
                      )
