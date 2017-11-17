# Auto generated configuration file
# using:
# Revision: 1.19
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v
# with command line options: step3 --conditions auto:phase2_realistic -n -1 --era Phase2C2_timing --eventcontent FEVTDEBUGHLT,MINIAODSIM,DQM --runUnscheduled -s RAW2DIGI,L1Reco,RECO,PAT,VALIDATION:@phase2Validation+@miniAODValidation,DQM:@phase2+@miniAODDQM --datatier GEN-SIM-RECO,MINIAODSIM,DQMIO --geometry Extended2023D17 --pileup AVE_200_BX_25ns,{"B":(-8,8)} --pileup_input das:/RelValMinBias_14TeV/CMSSW_9_1_1_patch3-91X_upgrade2023_realistic_v3_D17noPU-v1/GEN-SIM --no_exec
import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('RECO',eras.Phase2C2_timing)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mix_POISSON_average_cfi')
process.load('Configuration.Geometry.GeometryExtended2023D17Reco_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.RawToDigi_cff')
process.load('Configuration.StandardSequences.L1Reco_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('PhysicsTools.PatAlgos.slimming.metFilterPaths_cff')
process.load('Configuration.StandardSequences.PATMC_cff')
process.load('Configuration.StandardSequences.Validation_cff')
process.load('DQMOffline.Configuration.DQMOfflineMC_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring('file:step2_DIGI_L1_DIGI2RAW_HLT_PU.root'),
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step3 nevts:-1'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.FEVTDEBUGHLToutput = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM-RECO'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(10485760),
    fileName = cms.untracked.string('step3_RAW2DIGI_L1Reco_RECO_PAT_VALIDATION_DQM_PU.root'),
    outputCommands = process.FEVTDEBUGHLTEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

process.MINIAODSIMoutput = cms.OutputModule("PoolOutputModule",
    compressionAlgorithm = cms.untracked.string('LZMA'),
    compressionLevel = cms.untracked.int32(4),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('MINIAODSIM'),
        filterName = cms.untracked.string('')
    ),
    dropMetaData = cms.untracked.string('ALL'),
    eventAutoFlushCompressedSize = cms.untracked.int32(15728640),
    fastCloning = cms.untracked.bool(False),
    fileName = cms.untracked.string('step3_RAW2DIGI_L1Reco_RECO_PAT_VALIDATION_DQM_PU_inMINIAODSIM.root'),
    outputCommands = process.MINIAODSIMEventContent.outputCommands,
    overrideInputFileSplitLevels = cms.untracked.bool(True)
)

process.DQMoutput = cms.OutputModule("DQMRootOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('DQMIO'),
        filterName = cms.untracked.string('')
    ),
    fileName = cms.untracked.string('step3_RAW2DIGI_L1Reco_RECO_PAT_VALIDATION_DQM_PU_inDQM.root'),
    outputCommands = process.DQMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.mix.input.nbPileupEvents.averageNumber = cms.double(200.000000)
process.mix.bunchspace = cms.int32(25)
process.mix.minBunch = cms.int32(-8)
process.mix.maxBunch = cms.int32(8)
process.mix.input.fileNames = cms.untracked.vstring(['/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/2A6FB974-CD68-E711-9299-0025905A6090.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/2C01BC33-CD68-E711-9231-0CC47A4D76C0.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/2CABCFB4-CF68-E711-BA87-0025905A60BE.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/5079824C-CF68-E711-9321-0025905B85CC.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/66DF1163-CB68-E711-853B-0025905A48F0.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/9ACED6A7-D068-E711-B10E-0025905B8562.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/CE0C5370-CE68-E711-A7AB-0025905A60BE.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/D6E59D46-D168-E711-A82C-0025905A4964.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/DE3DB95D-CB68-E711-B9E9-0025905A60B6.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/DEAB6F4E-CF68-E711-9002-0025905A60AA.root'])
process.mix.playback = True
process.mix.digitizers = cms.PSet()
for a in process.aliases: delattr(process, a)
process.RandomNumberGeneratorService.restoreStateLabel=cms.untracked.string("randomEngineStateProducer")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:phase2_realistic', '')

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
process.Flag_trackingFailureFilter = cms.Path(process.goodVertices+process.trackingFailureFilter)
process.Flag_goodVertices = cms.Path(process.primaryVertexFilter)
process.Flag_CSCTightHaloFilter = cms.Path(process.CSCTightHaloFilter)
process.Flag_trkPOGFilters = cms.Path(~process.logErrorTooManyClusters)
process.Flag_HcalStripHaloFilter = cms.Path(process.HcalStripHaloFilter)
process.Flag_trkPOG_logErrorTooManyClusters = cms.Path(~process.logErrorTooManyClusters)
process.Flag_EcalDeadCellTriggerPrimitiveFilter = cms.Path(process.EcalDeadCellTriggerPrimitiveFilter)
process.Flag_ecalLaserCorrFilter = cms.Path(process.ecalLaserCorrFilter)
process.Flag_globalSuperTightHalo2016Filter = cms.Path(process.globalSuperTightHalo2016Filter)
process.Flag_eeBadScFilter = cms.Path()
process.Flag_METFilters = cms.Path(process.metFilters)
process.Flag_chargedHadronTrackResolutionFilter = cms.Path(process.chargedHadronTrackResolutionFilter)
process.Flag_globalTightHalo2016Filter = cms.Path(process.globalTightHalo2016Filter)
process.Flag_CSCTightHaloTrkMuUnvetoFilter = cms.Path(process.CSCTightHaloTrkMuUnvetoFilter)
process.Flag_HBHENoiseIsoFilter = cms.Path()
process.Flag_BadChargedCandidateSummer16Filter = cms.Path(process.BadChargedCandidateSummer16Filter)
process.Flag_hcalLaserEventFilter = cms.Path(process.hcalLaserEventFilter)
process.Flag_BadPFMuonFilter = cms.Path(process.BadPFMuonFilter)
process.Flag_HBHENoiseFilter = cms.Path()
process.Flag_trkPOG_toomanystripclus53X = cms.Path()
process.Flag_EcalDeadCellBoundaryEnergyFilter = cms.Path(process.EcalDeadCellBoundaryEnergyFilter)
process.Flag_BadChargedCandidateFilter = cms.Path(process.BadChargedCandidateFilter)
process.Flag_trkPOG_manystripclus53X = cms.Path()
process.Flag_BadPFMuonSummer16Filter = cms.Path(process.BadPFMuonSummer16Filter)
process.Flag_muonBadTrackFilter = cms.Path(process.muonBadTrackFilter)
process.Flag_CSCTightHalo2015Filter = cms.Path(process.CSCTightHalo2015Filter)
process.prevalidation_step = cms.Path(process.baseCommonPreValidation)
process.prevalidation_step1 = cms.Path(process.globalPrevalidationTracking)
process.prevalidation_step2 = cms.Path(process.globalPrevalidationMuons)
process.prevalidation_step3 = cms.Path(process.globalPrevalidationJetMETOnly)
process.prevalidation_step4 = cms.Path(process.prebTagSequenceMC)
process.prevalidation_step5 = cms.Path(process.globalPrevalidationHCAL)
process.prevalidation_step6 = cms.Path(process.prevalidationMiniAOD)
process.validation_step = cms.EndPath(process.baseCommonValidation)
process.validation_step1 = cms.EndPath(process.globalValidationTrackingOnly)
process.validation_step2 = cms.EndPath(process.globalValidationMuons)
process.validation_step3 = cms.EndPath(process.globalValidationJetMETonly)
process.validation_step4 = cms.EndPath(process.bTagPlotsMCbcl)
process.validation_step5 = cms.EndPath(process.globalValidationHCAL)
process.validation_step6 = cms.EndPath(process.validationMiniAOD)
process.dqmoffline_step = cms.EndPath(process.DQMOfflineTracking)
process.dqmoffline_1_step = cms.EndPath(process.DQMOuterTracker)
process.dqmoffline_2_step = cms.EndPath(process.DQMOfflineMuon)
process.dqmoffline_3_step = cms.EndPath(process.DQMOfflineHcal)
process.dqmoffline_4_step = cms.EndPath(process.HcalDQMOfflineSequence)
process.dqmoffline_5_step = cms.EndPath(process.DQMOfflineEGamma)
process.dqmoffline_6_step = cms.EndPath(process.DQMOfflineMiniAOD)
process.dqmofflineOnPAT_step = cms.EndPath(process.PostDQMOffline)
process.dqmofflineOnPAT_1_step = cms.EndPath(process.PostDQMOfflineMiniAOD)
process.FEVTDEBUGHLToutput_step = cms.EndPath(process.FEVTDEBUGHLToutput)
process.MINIAODSIMoutput_step = cms.EndPath(process.MINIAODSIMoutput)
process.DQMoutput_step = cms.EndPath(process.DQMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.Flag_HBHENoiseFilter,process.Flag_HBHENoiseIsoFilter,process.Flag_CSCTightHaloFilter,process.Flag_CSCTightHaloTrkMuUnvetoFilter,process.Flag_CSCTightHalo2015Filter,process.Flag_globalTightHalo2016Filter,process.Flag_globalSuperTightHalo2016Filter,process.Flag_HcalStripHaloFilter,process.Flag_hcalLaserEventFilter,process.Flag_EcalDeadCellTriggerPrimitiveFilter,process.Flag_EcalDeadCellBoundaryEnergyFilter,process.Flag_goodVertices,process.Flag_eeBadScFilter,process.Flag_ecalLaserCorrFilter,process.Flag_trkPOGFilters,process.Flag_chargedHadronTrackResolutionFilter,process.Flag_muonBadTrackFilter,process.Flag_BadChargedCandidateFilter,process.Flag_BadPFMuonFilter,process.Flag_BadChargedCandidateSummer16Filter,process.Flag_BadPFMuonSummer16Filter,process.Flag_trkPOG_manystripclus53X,process.Flag_trkPOG_toomanystripclus53X,process.Flag_trkPOG_logErrorTooManyClusters,process.Flag_METFilters,process.prevalidation_step,process.prevalidation_step1,process.prevalidation_step2,process.prevalidation_step3,process.prevalidation_step4,process.prevalidation_step5,process.prevalidation_step6,process.validation_step,process.validation_step1,process.validation_step2,process.validation_step3,process.validation_step4,process.validation_step5,process.validation_step6,process.dqmoffline_step,process.dqmoffline_1_step,process.dqmoffline_2_step,process.dqmoffline_3_step,process.dqmoffline_4_step,process.dqmoffline_5_step,process.dqmoffline_6_step,process.dqmofflineOnPAT_step,process.dqmofflineOnPAT_1_step,process.FEVTDEBUGHLToutput_step,process.MINIAODSIMoutput_step,process.DQMoutput_step)
process.schedule.associate(process.patTask)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

# customisation of the process.

# Automatic addition of the customisation function from SimGeneral.MixingModule.fullMixCustomize_cff
from SimGeneral.MixingModule.fullMixCustomize_cff import setCrossingFrameOn

#call to customisation function setCrossingFrameOn imported from SimGeneral.MixingModule.fullMixCustomize_cff
process = setCrossingFrameOn(process)

# End of customisation functions
#do not add changes to your config after this point (unless you know what you are doing)
from FWCore.ParameterSet.Utilities import convertToUnscheduled
process=convertToUnscheduled(process)

# customisation of the process.

# Automatic addition of the customisation function from PhysicsTools.PatAlgos.slimming.miniAOD_tools
from PhysicsTools.PatAlgos.slimming.miniAOD_tools import miniAOD_customizeAllMC

#call to customisation function miniAOD_customizeAllMC imported from PhysicsTools.PatAlgos.slimming.miniAOD_tools
process = miniAOD_customizeAllMC(process)

# End of customisation functions

# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
