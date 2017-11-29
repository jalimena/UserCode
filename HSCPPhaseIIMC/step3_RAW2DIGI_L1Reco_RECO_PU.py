# Auto generated configuration file
# using:
# Revision: 1.19
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v
# with command line options: step3 --conditions auto:phase2_realistic -n -1 --era Phase2C2_timing --eventcontent FEVTDEBUGHLT --runUnscheduled -s RAW2DIGI,L1Reco,RECO --datatier GEN-SIM-RECO --geometry Extended2023D17 --pileup AVE_200_BX_25ns,{"B":(-8,8)} --pileup_input das:/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/PhaseIITDRSpring17GS-91X_upgrade2023_realistic_v3-v1/GEN-SIM --no_exec
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
process.load('Configuration.StandardSequences.EndOfProcess_cff')
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
    fileName = cms.untracked.string('step3_RAW2DIGI_L1Reco_RECO_PU.root'),
    outputCommands = process.FEVTDEBUGHLTEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.mix.input.nbPileupEvents.averageNumber = cms.double(200.000000)
process.mix.bunchspace = cms.int32(25)
process.mix.minBunch = cms.int32(-8)
process.mix.maxBunch = cms.int32(8)
process.mix.input.fileNames = cms.untracked.vstring(['/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/00224515-A577-E711-885E-0CC47AD9914A.root', '/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/0033DF1E-A577-E711-BEEA-0242AC130002.root', '/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/00A53FE7-BE77-E711-B340-001E67F8FA2E.root', '/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/00B59013-A577-E711-B38E-001E675A6630.root', '/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/00D8E595-AA77-E711-998C-0CC47A7C3458.root', '/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/00E5DEF4-0878-E711-A16C-008CFA1980B8.root', '/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/00EFEF80-A877-E711-BCBC-001E67247DF0.root', '/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/00F7ED14-A577-E711-8BA7-0025900B20E2.root', '/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/020FCD50-C077-E711-86DA-14187764311A.root', '/store/mc/PhaseIITDRSpring17GS/MinBias_TuneCUETP8M1_14TeV-v1-pythia8/GEN-SIM/91X_upgrade2023_realistic_v3-v1/50000/02131E0D-A577-E711-98DD-008CFAF293FE.root'])
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:phase2_realistic', '')

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.L1Reco_step = cms.Path(process.L1Reco)
process.reconstruction_step = cms.Path(process.reconstruction)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.FEVTDEBUGHLToutput_step = cms.EndPath(process.FEVTDEBUGHLToutput)

# Schedule definition
process.schedule = cms.Schedule(process.raw2digi_step,process.L1Reco_step,process.reconstruction_step,process.endjob_step,process.FEVTDEBUGHLToutput_step)
from PhysicsTools.PatAlgos.tools.helpers import associatePatAlgosToolsTask
associatePatAlgosToolsTask(process)

#do not add changes to your config after this point (unless you know what you are doing)
from FWCore.ParameterSet.Utilities import convertToUnscheduled
process=convertToUnscheduled(process)


# Customisation from command line

# Add early deletion of temporary data products to reduce peak memory need
from Configuration.StandardSequences.earlyDeleteSettings_cff import customiseEarlyDelete
process = customiseEarlyDelete(process)
# End adding early deletion
