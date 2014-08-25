#!/bin/tcsh
source hosts.csh

foreach x (ppstau100_gravitinop0001 ppstau126_gravitinop0001 ppstau156_gravitinop0001 ppstau200_gravitinop0001 ppstau247_gravitinop0001 ppstau308_gravitinop0001 ppstau370_gravitinop0001 ppstau432_gravitinop0001 ppstau494_gravitinop0001)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end

