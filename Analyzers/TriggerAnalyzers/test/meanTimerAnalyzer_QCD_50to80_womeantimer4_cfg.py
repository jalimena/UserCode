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
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_726_1_Kw5.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_727_1_Otn.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_728_1_7mR.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_729_1_bYf.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_72_1_eA4.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_730_1_ko9.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_731_1_0Sw.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_732_1_vBq.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_733_1_UHN.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_734_1_1xz.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_737_1_fzZ.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_738_1_Q0j.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_739_1_9pQ.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_73_1_s2q.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_740_1_vM3.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_741_1_G8m.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_742_1_Huk.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_743_1_S96.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_744_1_OCf.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_745_1_OHg.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_746_1_Nil.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_747_1_7ml.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_748_1_M3n.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_749_1_nJ4.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_74_1_7Ps.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_750_1_nRJ.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_751_1_9Kt.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_752_1_xgx.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_753_1_pbM.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_754_1_3MS.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_755_1_xgk.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_756_1_nes.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_757_1_EFm.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_758_1_jnz.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_759_1_nSH.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_75_1_wgs.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_760_1_Cgr.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_765_1_iZa.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_768_1_2Cc.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_76_1_MxK.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_776_1_OBI.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_77_1_nen.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_780_1_vwY.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_78_1_DqC.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_79_1_Y0S.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_7_1_FGQ.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_80_1_uBY.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_81_1_qsG.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_82_1_nh1.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_83_1_Pc1.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_84_1_2EJ.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_85_1_4R4.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_86_1_Dpo.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_87_1_U5q.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_88_1_WOh.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_89_1_yod.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_8_1_akz.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_90_1_kwV.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_91_1_zlC.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_92_1_k9H.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_93_1_VCl.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_94_1_PFP.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_95_1_whP.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_96_1_61c.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_97_1_8pc.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_98_1_92f.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_99_1_KAO.root',
'root://eoscms//eos/cms/store/user/jalimena/QCD_Pt-50to80_MuEnrichedPt5_Tune4C_13TeV_pythia8/QCD_Pt-50to80_MuEnriched_womeantimer_outputA/16ac801b1226d85fd0d5986304adb810/outputA_mchamp500_womeantimer_9_1_esC.root'

    )
)

process.TFileService = cms.Service( "TFileService",
                                    fileName = cms.string( 'histosMeanTimerAnalyzer_QCD_50to80_womeantimer4.root' )
                                    )


process.p = cms.Path(process.demo)
