import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.MessageLogger.cerr.FwkReport.reportEvery = 10000

INPUTFILE="rfio:/castor/cern.ch/user/j/jalimena/167102/Jet/out_167102_Jet_xxx.root"
process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(INPUTFILE)
                            )

process.demo = cms.EDAnalyzer('compare_onoffHLT',
                              processNameON = cms.string("HLT"),
                              processNameOFF = cms.string("TEST"),
                              triggerTagON  = cms.untracked.InputTag('TriggerResults::HLT'),
                              triggerTagOFF  = cms.untracked.InputTag('TriggerResults::TEST'),
                              isRealData = cms.untracked.bool(True),
                              Nfiles = cms.untracked.int32(235),
                              Norm = cms.untracked.double(1.),
                              LumiSecNumber = cms.untracked.int32(1)                              
)

OUTPUTFILE="/afs/cern.ch/user/j/jalimena/scratch0/CMSSW_4_2_4_hltpatch1/src/compare_onoffHLT/output/compare_onoffHLT_167102Jet.root"
process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string(OUTPUTFILE)
                                   )

process.p = cms.Path(process.demo)
