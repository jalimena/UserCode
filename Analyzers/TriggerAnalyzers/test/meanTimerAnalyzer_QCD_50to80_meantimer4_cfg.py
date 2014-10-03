import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")
process.load("TriggerAnalyzer.MeanTimerAnalyzer.meanTimerAnalyzer_cfi")
process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.GlobalTag.globaltag = 'PRE_LS172_V11::All'

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(10) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_726_1_hum.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_727_1_aYD.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_728_1_4em.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_729_1_13p.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_72_1_8vb.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_730_1_0Y6.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_731_1_1ls.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_732_1_LEW.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_733_1_kDA.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_734_1_XhO.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_735_1_xRH.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_736_1_gfb.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_737_1_3ty.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_738_1_leb.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_73_1_aHw.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_740_1_Nwz.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_741_1_Ok3.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_742_1_ViT.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_743_1_2vO.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_744_1_xni.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_745_1_Jjz.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_746_1_RZc.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_747_1_Byu.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_748_1_p0r.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_749_1_BnF.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_74_1_OgO.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_750_1_uLa.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_751_1_84h.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_752_1_W2L.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_753_1_hZ3.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_754_1_ldT.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_755_1_JdG.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_756_1_541.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_757_1_3sp.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_758_1_G2l.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_759_1_459.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_75_1_b1x.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_760_1_Cvm.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_761_1_uIP.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_763_1_fFz.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_764_1_2v2.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_765_1_vQr.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_767_1_ype.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_768_1_SqY.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_769_1_Re7.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_76_1_GLW.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_770_1_bHD.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_771_1_c6s.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_772_1_t8v.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_773_1_v64.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_774_1_cNM.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_775_1_1Ss.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_776_1_B3E.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_777_1_I28.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_778_1_FK4.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_779_1_Fto.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_77_1_x4X.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_780_1_ZyS.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_781_1_Q3i.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_782_1_Rcp.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_783_1_a2F.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_784_1_4mK.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_785_1_hIJ.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_786_1_cWX.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_787_1_3Ag.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_788_1_M33.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_789_1_Ijr.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_78_1_j4O.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_790_1_ROd.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_791_1_Pyq.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_792_1_FKo.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_793_1_g99.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_794_1_Jua.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_795_1_Tcc.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_796_1_dVv.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_797_1_QAB.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_798_1_Upb.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_799_1_SVv.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_79_1_e6e.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_7_1_ROw.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_800_1_aYz.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_80_1_xY8.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_81_1_51H.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_82_1_OSS.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_83_1_psO.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_84_1_5w7.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_85_1_Xpq.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_86_1_BAJ.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_87_1_chm.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_88_1_pdB.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_89_1_4oS.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_8_1_aU0.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_90_1_yyC.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_91_1_lvE.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_92_1_KeC.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_93_1_Gf0.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_94_1_0Fg.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_95_1_hgI.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_96_1_JAC.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_97_1_Knb.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_98_1_fYq.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_99_1_x3B.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_meantimer_outputA/25c13d068aeb6012dbb08f65bb431296/outputA_mchamp500_meantimer_9_1_WVD.root'

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_QCD_50to80_meantimer4.root' )
                                    )


process.p = cms.Path(process.demo)
