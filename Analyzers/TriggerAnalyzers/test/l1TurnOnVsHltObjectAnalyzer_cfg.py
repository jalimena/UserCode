import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("Analyzers.TriggerAnalyzers.l1TurnOnVsHltObjectAnalyzer_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

if 'GlobalTag' in process.__dict__:
    from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag as customiseGlobalTag
    process.GlobalTag = customiseGlobalTag(process.GlobalTag, globaltag = '80X_dataRun2_Prompt_v9')
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
        "file:/afs/cern.ch/work/j/jalimena/CMSSW_8_0_12/src/HLTrigger/Configuration/test/outputPhysicsEGammaCommissioning.root"
        #'/store/relval/CMSSW_8_0_11/HLTPhysics/FEVTDEBUGHLT/80X_dataRun2_HLT_relval_v11_RelVal_hltPhy2015D-v1/10000/00387150-F334-E611-B810-0025905A60F2.root'
        )
                            )

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'hist.root' )
                                    )


process.p = cms.Path(process.demo)
