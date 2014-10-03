#!/bin/tcsh
source hosts.csh

#foreach x (mchamp100 mchamp200 mchamp300 mchamp400 mchamp500 mchamp600 mchamp700 mchamp800 mchamp900 mchamp1000)
foreach x (mchamp500_720pre6_PRESTA72V4)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
