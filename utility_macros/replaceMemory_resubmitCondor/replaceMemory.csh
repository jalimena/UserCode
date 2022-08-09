#!/bin/tcsh

foreach i (*/condor_resubmit.sub)
    sed -i 's/2048MB/4000MB/' $i
end
