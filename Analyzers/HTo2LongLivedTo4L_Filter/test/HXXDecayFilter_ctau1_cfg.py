import FWCore.ParameterSet.Config as cms

process = cms.Process("LifetimeSkim")

process.load("Analyzers.HTo2LongLivedTo4L_Filter.HXXDecayFilter_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')


if 'GlobalTag' in process.__dict__:
    from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag as customiseGlobalTag
    process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = 'MCRUN2_72_V1A')
    process.GlobalTag.connect   = 'frontier://FrontierProd/CMS_CONDITIONS'
    process.GlobalTag.pfnPrefix = cms.untracked.string('frontier://FrontierProd/')
    for pset in process.GlobalTag.toGet.value():
        pset.connect = pset.connect.value().replace('frontier://FrontierProd/', 'frontier://FrontierProd/')
    process.GlobalTag.RefreshEachRun = cms.untracked.bool( False )
    process.GlobalTag.ReconnectEachRun = cms.untracked.bool( False )


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )                                                                                                                    
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

process.HXXDecayFilter.lifetime = cms.untracked.string('1')
process.HXXDecayFilter.numRequired = cms.untracked.int32(1)
process.HXXDecayFilter.acceptMore = cms.untracked.bool(True)


process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    )
)

process.p = cms.Path(process.HXXDecayFilter)


process.out = cms.OutputModule( "PoolOutputModule",
                                fileName = cms.untracked.string( "skim_ctau1.root" ),
                                outputCommands = cms.untracked.vstring( 'keep *' ),
                                SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring('p'))
                                )

process.end = cms.EndPath( process.out )
