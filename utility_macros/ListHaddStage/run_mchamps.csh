#!/bin/tcsh
source hosts.csh

foreach x (mchamp100_723patch1 mchamp200_723patch1 mchamp300_723patch1 mchamp400_723patch1 mchamp500_723patch1 mchamp600_723patch1 mchamp700_723patch1 mchamp800_723patch1 mchamp900_723patch1 mchamp1000_723patch1)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
