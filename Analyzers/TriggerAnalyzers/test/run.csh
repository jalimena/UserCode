#!/bin/tcsh

cmsRun meanTimerAnalyzer_QCD_30to50_meantimer1_cfg.py > & out_QCD_30to50_meantimer1 &
cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer1_cfg.py > & out_QCD_30to50_womeantimer1 &
cmsRun meanTimerAnalyzer_QCD_30to50_meantimer2_cfg.py > & out_QCD_30to50_meantimer2 &
cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer2_cfg.py > & out_QCD_30to50_womeantimer2 &
cmsRun meanTimerAnalyzer_QCD_30to50_meantimer3_cfg.py > & out_QCD_30to50_meantimer3 &
cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer3_cfg.py > & out_QCD_30to50_womeantimer3 &
cmsRun meanTimerAnalyzer_QCD_30to50_meantimer4_cfg.py > & out_QCD_30to50_meantimer4 &
cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer4_cfg.py > & out_QCD_30to50_womeantimer4 &

cmsRun meanTimerAnalyzer_QCD_50to80_meantimer1_cfg.py > & out_QCD_50to80_meantimer1 &
cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer1_cfg.py > & out_QCD_50to80_womeantimer1 &
cmsRun meanTimerAnalyzer_QCD_50to80_meantimer2_cfg.py > & out_QCD_50to80_meantimer2 &
cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer2_cfg.py > & out_QCD_50to80_womeantimer2 &
cmsRun meanTimerAnalyzer_QCD_50to80_meantimer3_cfg.py > & out_QCD_50to80_meantimer3 &
cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer3_cfg.py > & out_QCD_50to80_womeantimer3 &
cmsRun meanTimerAnalyzer_QCD_50to80_meantimer4_cfg.py > & out_QCD_50to80_meantimer4 &
cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer4_cfg.py > & out_QCD_50to80_womeantimer4 &
#cmsRun meanTimerAnalyzer_DYToMuMu_meantimer_cfg.py > & out_DYToMuMu_meantimer1 &
#cmsRun meanTimerAnalyzer_DYToMuMu_womeantimer_cfg.py > & out_DYToMuMu_womeantimer1 &
#cmsRun meanTimerAnalyzer_DYToMuMu_meantimer2_cfg.py > & out_DYToMuMu_meantimer2 &
#cmsRun meanTimerAnalyzer_DYToMuMu_womeantimer2_cfg.py > & out_DYToMuMu_womeantimer2 &
#cmsRun meanTimerAnalyzer_mchamp500_meantimer_cfg.py > & out_mchamp500_meantimer &
#cmsRun meanTimerAnalyzer_mchamp500_womeantimer_cfg.py > & out_mchamp500_womeantimer &
