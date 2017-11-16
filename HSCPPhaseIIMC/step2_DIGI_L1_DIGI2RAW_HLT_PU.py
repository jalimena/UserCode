# Auto generated configuration file
# using:
# Revision: 1.19
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v
# with command line options: step2 --conditions auto:phase2_realistic -s DIGI:pdigi_valid,L1,DIGI2RAW,HLT:@fake2 --datatier GEN-SIM-DIGI-RAW -n -1 --geometry Extended2023D17 --era Phase2C2_timing --eventcontent FEVTDEBUGHLT --pileup AVE_200_BX_25ns,{"B":(-8,8)} --pileup_input das:/RelValMinBias_14TeV/CMSSW_9_1_1_patch3-91X_upgrade2023_realistic_v3_D17noPU-v1/GEN-SIM --filein file:EXO-PhaseIITDRSpring17GS-00041.root --no_exec
import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('HLT',eras.Phase2C2_timing)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mix_POISSON_average_cfi')
process.load('Configuration.Geometry.GeometryExtended2023D17Reco_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('Configuration.StandardSequences.Digi_cff')
process.load('Configuration.StandardSequences.SimL1Emulator_cff')
process.load('Configuration.StandardSequences.DigiToRaw_cff')
process.load('HLTrigger.Configuration.HLT_Fake2_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

# Input source
process.source = cms.Source("PoolSource",
    dropDescendantsOfDroppedBranches = cms.untracked.bool(False),
    fileNames = cms.untracked.vstring('file:EXO-PhaseIITDRSpring17GS-00041.root'),
    inputCommands = cms.untracked.vstring('keep *',
        'drop *_genParticles_*_*',
        'drop *_genParticlesForJets_*_*',
        'drop *_kt4GenJets_*_*',
        'drop *_kt6GenJets_*_*',
        'drop *_iterativeCone5GenJets_*_*',
        'drop *_ak4GenJets_*_*',
        'drop *_ak7GenJets_*_*',
        'drop *_ak8GenJets_*_*',
        'drop *_ak4GenJetsNoNu_*_*',
        'drop *_ak8GenJetsNoNu_*_*',
        'drop *_genCandidatesForMET_*_*',
        'drop *_genParticlesForMETAllVisible_*_*',
        'drop *_genMetCalo_*_*',
        'drop *_genMetCaloAndNonPrompt_*_*',
        'drop *_genMetTrue_*_*',
        'drop *_genMetIC5GenJs_*_*'),
    secondaryFileNames = cms.untracked.vstring()
)

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('step2 nevts:-1'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.FEVTDEBUGHLToutput = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM-DIGI-RAW'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(10485760),
    fileName = cms.untracked.string('step2_DIGI_L1_DIGI2RAW_HLT_PU.root'),
    outputCommands = process.FEVTDEBUGHLTEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
#rpc customization
process.simMuonRPCDigis.digiModelConfig.linkGateWidth = cms.double(25.0)
process.simMuonRPCDigis.digiIRPCModelConfig.linkGateWidth = cms.double(25.0)

process.mix.input.nbPileupEvents.averageNumber = cms.double(200.000000)
process.mix.bunchspace = cms.int32(25)
process.mix.minBunch = cms.int32(-8)
process.mix.maxBunch = cms.int32(8)
process.mix.input.fileNames = cms.untracked.vstring(['/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/2A6FB974-CD68-E711-9299-0025905A6090.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/2C01BC33-CD68-E711-9231-0CC47A4D76C0.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/2CABCFB4-CF68-E711-BA87-0025905A60BE.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/5079824C-CF68-E711-9321-0025905B85CC.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/66DF1163-CB68-E711-853B-0025905A48F0.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/9ACED6A7-D068-E711-B10E-0025905B8562.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/CE0C5370-CE68-E711-A7AB-0025905A60BE.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/D6E59D46-D168-E711-A82C-0025905A4964.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/DE3DB95D-CB68-E711-B9E9-0025905A60B6.root', '/store/relval/CMSSW_9_1_1_patch3/RelValMinBias_14TeV/GEN-SIM/91X_upgrade2023_realistic_v3_D17noPU-v1/00000/DEAB6F4E-CF68-E711-9002-0025905A60AA.root'])
process.mix.digitizers = cms.PSet(process.theDigitizersValid)
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:phase2_realistic', '')

# Path and EndPath definitions
process.digitisation_step = cms.Path(process.pdigi_valid)
process.L1simulation_step = cms.Path(process.SimL1Emulator)
process.digi2raw_step = cms.Path(process.DigiToRaw)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.FEVTDEBUGHLToutput_step = cms.EndPath(process.FEVTDEBUGHLToutput)

# Schedule definition
process.schedule = cms.Schedule(process.digitisation_step,process.L1simulation_step,process.digi2raw_step)
process.schedule.extend(process.HLTSchedule)
process.schedule.extend([process.endjob_step,process.FEVTDEBUGHLToutput_step])
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

# customisation of the process.

# Automatic addition of the customisation function from HLTrigger.Configuration.customizeHLTforMC
from HLTrigger.Configuration.customizeHLTforMC import customizeHLTforMC

#call to customisation function customizeHLTforMC imported from HLTrigger.Configuration.customizeHLTforMC
process = customizeHLTforMC(process)

# End of customisation functions

# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
