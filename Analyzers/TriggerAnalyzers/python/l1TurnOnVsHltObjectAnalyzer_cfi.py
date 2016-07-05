import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer('L1TurnOnVsHLTObjectAnalyzer',
                      hltResultsTag = cms.untracked.InputTag("TriggerResults","","HLTFULL"),
                      hltEventTag = cms.untracked.InputTag("hltTriggerSummaryAOD","","HLTFULL"),
                      hltCaloJetsTag = cms.untracked.InputTag("hltStoppedHSCPIterativeCone4CaloJets"),
                      #hltFilterTag_L1SingleJetC36NotBptxOR3BX = cms.untracked.InputTag("hltL1sV0SingleJetC20NotBptxOR","","HLTFULL"),
                      hltFilterTag_L1SingleJetC20NotBptxOR3BX = cms.untracked.InputTag("hltL1sSingleJetC20NotBptxOR3BX","","HLTFULL"),
                      hltFilterTag_L1SingleJetC36NotBptxOR3BX = cms.untracked.InputTag("hltL1sSingleJetC32NotBptxOR3BXIorSingleJetC36NotBptxOR3BX","","HLTFULL"),
                      #hltFilterTag_L3Mu40 = cms.untracked.InputTag("hltL3fL1sMu16orMu25L1f0L2f16QL3Filtered40Q","","HLTFULL"),
                      )
