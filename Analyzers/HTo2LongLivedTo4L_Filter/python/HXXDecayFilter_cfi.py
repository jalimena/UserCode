import FWCore.ParameterSet.Config as cms

HXXDecayFilter = cms.EDFilter('HXXDecayFilter',
  genParticlesTag = cms.untracked.InputTag('genParticles'),
  decayMode = cms.untracked.string('any'),
  lifetime = cms.untracked.string('any'),
  numRequired = cms.untracked.int32(0),
  acceptMore = cms.untracked.bool(True)
)
