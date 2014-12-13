#!/bin/tcsh

#cmsRun meanTimerAnalyzer_QCD_30to50_meantimer_cfg.py > & out_QCD_30to50_meantimer1 &
#cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer_cfg.py > & out_QCD_30to50_womeantimer1 &
#cmsRun meanTimerAnalyzer_QCD_30to50_meantimer_cfg2.py > & out_QCD_30to50_meantimer2 &
#cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer_cfg2.py > & out_QCD_30to50_womeantimer2 &
#cmsRun meanTimerAnalyzer_QCD_30to50_meantimer_cfg3.py > & out_QCD_30to50_meantimer3 &
#cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer_cfg3.py > & out_QCD_30to50_womeantimer3 &

#cmsRun meanTimerAnalyzer_QCD_50to80_meantimer_cfg.py > & out_QCD_50to80_meantimer1 &
#cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer_cfg.py > & out_QCD_50to80_womeantimer1 &
#cmsRun meanTimerAnalyzer_QCD_50to80_meantimer_cfg2.py > & out_QCD_50to80_meantimer2 &
#cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer_cfg2.py > & out_QCD_50to80_womeantimer2 &
#cmsRun meanTimerAnalyzer_QCD_50to80_meantimer_cfg3.py > & out_QCD_50to80_meantimer3 &
#cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer_cfg3.py > & out_QCD_50to80_womeantimer3 &

#cmsRun meanTimerAnalyzer_DYToMuMu_meantimer_cfg.py > & out_DYToMuMu_meantimer1 &
#cmsRun meanTimerAnalyzer_DYToMuMu_womeantimer_cfg.py > & out_DYToMuMu_womeantimer1 &
#cmsRun meanTimerAnalyzer_DYToMuMu_meantimer_cfg2.py > & out_DYToMuMu_meantimer2 &
#cmsRun meanTimerAnalyzer_DYToMuMu_womeantimer_cfg2.py > & out_DYToMuMu_womeantimer2 &
#cmsRun meanTimerAnalyzer_DYToMuMu_meantimer_cfg3.py > & out_DYToMuMu_meantimer3 &
#cmsRun meanTimerAnalyzer_DYToMuMu_womeantimer_cfg3.py > & out_DYToMuMu_womeantimer3 &

cmsRun hltAnalyzer_mchamp500_csmt_cfg.py > & out_mchamp500_csmt &
cmsRun hltAnalyzer_mchamp500_wocsmt_cfg.py > & out_mchamp500_wocsmt &
cmsRun hltAnalyzer_mchamp500_wotriggers_cfg.py > & out_mchamp500_wotriggers &

cmsRun hltAnalyzer_DisplacedSUSY200_csmt_cfg.py > & out_DisplacedSUSY200_csmt &
cmsRun hltAnalyzer_DisplacedSUSY200_wocsmt_cfg.py > & out_DisplacedSUSY200_wocsmt &
cmsRun hltAnalyzer_DisplacedSUSY200_wotriggers_cfg.py > & out_DisplacedSUSY200_wotriggers &

cmsRun hltAnalyzer_DisplacedSUSY200_p2d0_csmt_cfg.py > & out_DisplacedSUSY200_p2d0_csmt &
cmsRun hltAnalyzer_DisplacedSUSY200_p2d0_wocsmt_cfg.py > & out_DisplacedSUSY200_p2d0_wocsmt &
cmsRun hltAnalyzer_DisplacedSUSY200_p2d0_wotriggers_cfg.py > & out_DisplacedSUSY200_p2d0_wotriggers &

#cmsRun hltAnalyzer_HTo2LongLivedTo4L_csmt_cfg.py > & out_HTo2LongLivedTo4L_csmt &
#cmsRun hltAnalyzer_HTo2LongLivedTo4L_wocsmt_cfg.py > & out_HTo2LongLivedTo4L_wocsmt &

