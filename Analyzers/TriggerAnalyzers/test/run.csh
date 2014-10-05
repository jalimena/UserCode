#!/bin/tcsh

cmsRun meanTimerAnalyzer_QCD_30to50_meantimer_cfg.py > & out_QCD_30to50_meantimer1 &
cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer_cfg.py > & out_QCD_30to50_womeantimer1 &
cmsRun meanTimerAnalyzer_QCD_30to50_meantimer_cfg2.py > & out_QCD_30to50_meantimer2 &
cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer_cfg2.py > & out_QCD_30to50_womeantimer2 &
cmsRun meanTimerAnalyzer_QCD_30to50_meantimer_cfg3.py > & out_QCD_30to50_meantimer3 &
cmsRun meanTimerAnalyzer_QCD_30to50_womeantimer_cfg3.py > & out_QCD_30to50_womeantimer3 &

cmsRun meanTimerAnalyzer_QCD_50to80_meantimer_cfg.py > & out_QCD_50to80_meantimer1 &
cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer_cfg.py > & out_QCD_50to80_womeantimer1 &
cmsRun meanTimerAnalyzer_QCD_50to80_meantimer_cfg2.py > & out_QCD_50to80_meantimer2 &
cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer_cfg2.py > & out_QCD_50to80_womeantimer2 &
cmsRun meanTimerAnalyzer_QCD_50to80_meantimer_cfg3.py > & out_QCD_50to80_meantimer3 &
cmsRun meanTimerAnalyzer_QCD_50to80_womeantimer_cfg3.py > & out_QCD_50to80_womeantimer3 &

cmsRun meanTimerAnalyzer_DYToMuMu_meantimer_cfg.py > & out_DYToMuMu_meantimer1 &
cmsRun meanTimerAnalyzer_DYToMuMu_womeantimer_cfg.py > & out_DYToMuMu_womeantimer1 &
cmsRun meanTimerAnalyzer_DYToMuMu_meantimer_cfg2.py > & out_DYToMuMu_meantimer2 &
cmsRun meanTimerAnalyzer_DYToMuMu_womeantimer_cfg2.py > & out_DYToMuMu_womeantimer2 &
cmsRun meanTimerAnalyzer_DYToMuMu_meantimer_cfg3.py > & out_DYToMuMu_meantimer3 &
cmsRun meanTimerAnalyzer_DYToMuMu_womeantimer_cfg3.py > & out_DYToMuMu_womeantimer3 &

cmsRun meanTimerAnalyzer_mchamp500_meantimer_cfg.py > & out_mchamp500_meantimer &
cmsRun meanTimerAnalyzer_mchamp500_womeantimer_cfg.py > & out_mchamp500_womeantimer &

cmsRun meanTimerAnalyzer_HTo2LongLivedTo4L_meantimer_cfg.py > & out_HTo2LongLivedTo4L_meantimer &
cmsRun meanTimerAnalyzer_HTo2LongLivedTo4L_womeantimer_cfg.py > & out_HTo2LongLivedTo4L_womeantimer &

cmsRun meanTimerAnalyzer_DisplacedStops_meantimer_cfg.py > & out_DisplacedStops_meantimer &
cmsRun meanTimerAnalyzer_DisplacedStops_womeantimer_cfg.py > & out_DisplacedStops_womeantimer &
