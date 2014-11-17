This filter is a simple filter to select various kinds of H->XX decays from the samples that we use. This is
necessary because there are as many as 12 different types of X bosons generated, and you might want only a
particular lifetime and/or decay mode.

In general, the X bosons in the sample have the PDG ID 600x11y, where x determines the ctau of the X boson:
(1 = 0.1*nominal, 2 = nominal, 3 = 10*nominal) and y determines the decay mode (1 = uds, 2 = b, 3 = l, 4 =
udscb). The older 2011 samples don't have the three different lifetime values so x is always 0 for them.

Example usage of the filter:

process.HXXDecayFilter = cms.EDFilter('HXXDecayFilter',
  genParticlesTag = cms.untracked.InputTag('genParticles'),
  decayMode = cms.untracked.string('mumu'),
  lifetime = cms.untracked.string('nominal'),
  numRequired = cms.untracked.int32(1),
  acceptMore = cms.untracked.bool(False)
)

Here's the parameters to the filter:

* genParticlesTag is the InputTag for the genParticles. Normally this should be genParticles.

* decayMode is the decay mode of the X that you wish to select. Allowed values are:
 - any: any decay mode
 - ll: decay to leptons (either ee or mumu)
 - ee: decay to ee
 - mumu: decay to mumu
 - qq: decay to quarks (this will accept both 600x111 and 600x114; since there is no sample which has
   both of these decay modes, the overlap shouldn't matter) 
 - bb: decay to b

* lifetime is the mean lifetime of the X that you wish to select. Allowed values are:
 - any: any lifetime
 - 0.1: 0.1*nominal
 - 1: nominal; "nominal" is also accepted as a synonym
 - 10: 10*nominal

* numRequired: Number of X with the desired decay required for the event to be accepted.

* acceptMore: Whether or not events with more X passing the criteria will be accepted. For example, if you
  want to accept events with only one X->mumu, not two, then you should set numRequired to 1 and acceptMore to
  false (as in the example above).

Note that in the standard 2012 samples, the mean lifetime of the two Xes in the event will always be the same,
so these options are probably only useful if you're filtering on the decay mode.

If you have any questions, drop me a line (plujan@princeton.edu).

Paul Lujan, June 2014
