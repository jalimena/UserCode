#!/bin/tcsh
source hosts.csh

foreach x (mchampPlus100_723patch1 mchampPlus200_723patch1 mchampPlus300_723patch1 mchampPlus400_723patch1 mchampPlus500_723patch1 mchampPlus600_723patch1 mchampPlus700_723patch1 mchampPlus800_723patch1 mchampPlus900_723patch1 mchampPlus1000_723patch1)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
