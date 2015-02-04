#!/bin/tcsh
source hosts.csh

foreach x (ppstau100_gravitinop0001_723patch1 ppstau126_gravitinop0001_723patch1 ppstau156_gravitinop0001_723patch1 ppstau200_gravitinop0001_723patch1 ppstau247_gravitinop0001_723patch1 ppstau308_gravitinop0001_723patch1 ppstau370_gravitinop0001_723patch1 ppstau432_gravitinop0001_723patch1 ppstau494_gravitinop0001_723patch1)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end

