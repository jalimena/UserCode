#!/bin/tcsh
source hosts.csh

foreach x (gluino300_neutralino173_723patch1 gluino400_neutralino283_723patch1 gluino500_neutralino387_723patch1 gluino600_neutralino490_723patch1 gluino700_neutralino592_723patch1 gluino800_neutralino693_723patch1 gluino900_neutralino794_723patch1 gluino1000_neutralino894_723patch1 gluino1100_neutralino995_723patch1 gluino1200_neutralino1095_723patch1 gluino1300_neutralino1196_723patch1 gluino1400_neutralino1296_723patch1 gluino1500_neutralino1396_723patch1)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
