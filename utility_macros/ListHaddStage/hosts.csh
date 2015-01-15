#!/bin/tcsh

set host=${HOST}
set host_=(`expr substr $host 1 4`)

if ($host_ == 'cmsl') then #(cms)LPC is host
    set p='/uscms/home/alimena/jalimena/utility_macros/ListHaddStage/'
endif
if ($host_ == 'brux') then #brux6 is host
    set p='/home/alimena/Analysis/CMSSW_7_2_3_patch1/src/UserCode/utility_macros/ListHaddStage/'
endif
if ($host_ == 'lxpl') then #lxplus is host
    #set p='/afs/cern.ch/user/j/jalimena/scratch0/jalimena/utility_macros/ListHaddStage/'
    set p='/afs/cern.ch/work/j/jalimena/CMSSW_7_2_0_pre3/src/UserCode/utility_macros/ListHaddStage/'
endif

