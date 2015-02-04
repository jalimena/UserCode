#!/bin/tcsh
source hosts.csh

foreach x (gmstau100_gravitinop0001_723patch1 gmstau126_gravitinop0001_723patch1 gmstau156_gravitinop0001_723patch1 gmstau200_gravitinop0001_723patch1 gmstau247_gravitinop0001_723patch1 gmstau308_gravitinop0001_723patch1 gmstau370_gravitinop0001_723patch1 gmstau432_gravitinop0001_723patch1 gmstau494_gravitinop0001_723patch1)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
