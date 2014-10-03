import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer('MeanTimerAnalyzer',
                      hltResultsTag = cms.untracked.InputTag("TriggerResults","","TEST"),
                      hltEventTag = cms.untracked.InputTag("hltTriggerSummaryAOD","","TEST"),
                      hltFilterTag_DiMuonGlb17Iso = cms.untracked.InputTag("hltDiMuonGlb17Glb8DzFiltered0p2RelTrkIsoFiltered0p4","","TEST"),
                      hltFilterTag_DiMuonL2NoFilters33 = cms.untracked.InputTag("hltDimuonL3NoFiltersNoVtxFiltered33","","TEST"),
                      hltFilterTag_L2MuNoBptx20 = cms.untracked.InputTag("hltL2fL1sMu6NotBptxORL1f0L2Filtered20Sta3","","TEST"),
                      hltFilterTag_DiMuonGlb17 = cms.untracked.InputTag("hltDiMuonGlb17Trk8DzFiltered0p2","","TEST"),
                      hltFilterTag_L2DoubleMu28 = cms.untracked.InputTag("hltL2DoubleMu28NoVertexL2Filtered2ChaAngle2p5Mass10","","TEST"),
                      hltFilterTag_L3Mu24Iso = cms.untracked.InputTag("hltL3crIsoL1sMu16L1f0L2f16QL3f24QL3crIsoRhoFiltered0p15IterTrk02","","TEST"),
                      hltFilterTag_L3Mu40 = cms.untracked.InputTag("hltL3fL1sMu16L1f0L2f16QL3Filtered40Q","","TEST")                      
                      )
