#!/bin/tcsh
source hosts.csh

foreach x (gluino300_neutralino173 gluino400_neutralino283 gluino500_neutralino387 gluino600_neutralino490 gluino700_neutralino592 gluino800_neutralino693 gluino900_neutralino794 gluino1000_neutralino894 gluino1100_neutralino995 gluino1200_neutralino1095 gluino1300_neutralino1196 gluino1400_neutralino1296 gluino1500_neutralino1396)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
