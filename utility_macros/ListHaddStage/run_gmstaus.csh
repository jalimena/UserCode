#!/bin/tcsh
source /uscms/home/alimena/jalimena/utility_macros/ListHaddStage/hosts.csh

foreach x (gmstau100_gravitinop0001 gmstau126_gravitinop0001 gmstau156_gravitinop0001 gmstau200_gravitinop0001 gmstau247_gravitinop0001 gmstau308_gravitinop0001 gmstau370_gravitinop0001 gmstau432_gravitinop0001 gmstau494_gravitinop0001)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
