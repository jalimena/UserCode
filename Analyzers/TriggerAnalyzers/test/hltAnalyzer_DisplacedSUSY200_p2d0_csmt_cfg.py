import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("Analyzers.TriggerAnalyzers.hltAnalyzer_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

if 'GlobalTag' in process.__dict__:
    from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag as customiseGlobalTag
    process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'MCRUN2_72_V3A')
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
        'file:/afs/cern.ch/work/j/jalimena/CMSSW_7_2_2_patch2/src/HLTrigger/Configuration/test/outputA_csmt_DisplacedSUSY200_p2d0.root',
    )
)

process.demo.hltL2MuonsTag = cms.untracked.InputTag("hltL2CosmicMuons")
process.demo.hltFilterTag_DiMuonL3NoFilters33 = cms.untracked.InputTag("hltL3fDimuonL1f0L2NVf10L3NoFiltersNoVtxCosmicSeedFiltered33","","TEST")
process.demo.hltFilterTag_DiMuonL3NoFilters23Displaced = cms.untracked.InputTag("hltL3fDimuonL1f0L2NVf10L3NoFiltersNoVtxCosmicSeedDisplacedFiltered23","","TEST")
process.demo.hltFilterTag_L2MuNoBptx20 = cms.untracked.InputTag("hltL2fL1sMu6NotBptxORL1f0NoVertexCosmicSeedL2Filtered20Sta3","","TEST")
process.demo.hltFilterTag_L2DoubleMu28 = cms.untracked.InputTag("hltL2DoubleMu28NoVertexCosmicSeedL2Filtered2ChaAngle2p5Mass10","","TEST")
process.demo.hltFilterTag_Mu38NoVtx_Photon38 = cms.untracked.InputTag("hltMu38NoFiltersNoVtxCosmicSeedPhoton38CaloIdLHEFilter","","TEST")
process.demo.hltFilterTag_Mu28NoVtxDisplaced_Photon28 = cms.untracked.InputTag("hltMu28NoFiltersNoVtxCosmicSeedDisplacedPhoton28CaloIdLHEFilter","","TEST")
process.demo.BarrelOnly = cms.untracked.bool(False)
process.demo.lookForMother = cms.untracked.bool(True)
process.demo.motherId = cms.untracked.int32(1000006) #stop

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosHltAnalyzer_DisplacedSUSY200_p2d0_csmt.root' )
                                    )


process.p = cms.Path(process.demo)
