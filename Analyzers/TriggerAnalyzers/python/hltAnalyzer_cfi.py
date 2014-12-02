import FWCore.ParameterSet.Config as cms

demo = cms.EDAnalyzer('HLTAnalyzer',
                      hltResultsTag = cms.untracked.InputTag("TriggerResults","","TEST"),
                      hltEventTag = cms.untracked.InputTag("hltTriggerSummaryAOD","","TEST"),
                      genParticlesTag = cms.untracked.InputTag("genParticles"),
                      hltFilterTag_L3Mu40 = cms.untracked.InputTag("hltL3fL1sMu16orMu25L1f0L2f16QL3Filtered40Q","","TEST"),
                      hltFilterTag_L3Mu24Iso = cms.untracked.InputTag("hltL3crIsoL1sMu16L1f0L2f16QL3f24QL3crIsoRhoFiltered0p15IterTrk02","","TEST"),
                      hltFilterTag_L3TrkMu24Iso = cms.untracked.InputTag("hltL3fL1sMu16L1f0TkFiltered24QL3crIsoRhoFiltered0p15IterTrk02","","TEST"),
                      hltFilterTag_DiMuonGlb17Glb8 = cms.untracked.InputTag("hltDiMuonGlb17Glb8DzFiltered0p2","","TEST"),
                      hltFilterTag_DiMuonGlb17Trk8 = cms.untracked.InputTag("hltDiMuonGlb17Trk8DzFiltered0p2","","TEST"),
                      hltFilterTag_DiMuonGlb30Trk11 = cms.untracked.InputTag("hltDiMuonGlb30Trk11DzFiltered0p2","","TEST"),
                      hltFilterTag_DiMuonGlb17Glb8Iso = cms.untracked.InputTag("hltDiMuonGlb17Glb8DzFiltered0p2RelTrkIsoFiltered0p4","","TEST"),
                      hltFilterTag_DiMuonGlb17Trk8Iso = cms.untracked.InputTag("hltDiMuonGlb17Trk8DzFiltered0p2RelTrkIsoFiltered0p4","","TEST"),
                      hltFilterTag_DiMuonL3NoFilters33 = cms.untracked.InputTag("hltL3fDimuonL1f0L2NVf10L3NoFiltersNoVtxFiltered33","","TEST"),
                      hltFilterTag_DiMuonL3NoFilters23Displaced = cms.untracked.InputTag("hltL3fDimuonL1f0L2NVf10L3NoFiltersNoVtxDisplacedFiltered23","","TEST"),
                      hltFilterTag_L2MuNoBptx20 = cms.untracked.InputTag("hltL2fL1sMu6NotBptxORL1f0L2Filtered20Sta3","","TEST"),
                      hltFilterTag_L2DoubleMu28 = cms.untracked.InputTag("hltL2DoubleMu28NoVertexL2Filtered2ChaAngle2p5Mass10","","TEST"),
                      hltFilterTag_Mu38NoVtx_Photon38 = cms.untracked.InputTag("hltMu38NoFiltersNoVtxPhoton38CaloIdLHEFilter","","TEST"),
                      hltFilterTag_Mu28NoVtxDisplaced_Photon28 = cms.untracked.InputTag("hltMu28NoFiltersNoVtxDisplacedPhoton28CaloIdLHEFilter","","TEST"),
                      BarrelOnly = cms.untracked.bool(False),
                      subLeading = cms.untracked.bool(False)
                      #subLeading = cms.untracked.bool(True)
                      )
