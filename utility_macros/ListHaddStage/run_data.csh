#!/bin/tcsh
source hosts.csh

foreach x (SingleMu_Run2012A_723patch1 NoBPTX_Run2012B_period1_723patch1 NoBPTX_Run2012B_period2_723patch1 NoBPTX_Run2012C_723patch1 NoBPTX_Run2012C_ControlTriggers_723patch1 NoBPTX_Run2012D_723patch1)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
