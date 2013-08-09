#!/bin/tcsh
source /uscms/home/alimena/jalimena/utility_macros/ListHaddStage/hosts.csh

foreach x (SingleMu_Run2012A NoBPTX_Run2012B_period1 NoBPTX_Run2012B_period2 NoBPTX_Run2012C NoBPTX_Run2012D)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
