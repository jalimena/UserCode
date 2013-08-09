#!/bin/tcsh
source /uscms/home/alimena/jalimena/utility_macros/ListHaddStage/hosts.csh

foreach x (stop200_neutralino75 stop300_neutralino109 stop400_neutralino214 stop500_neutralino316 stop600_neutralino417 stop700_neutralino518 stop800_neutralino618 stop900_neutralino718 stop1000_neutralino819)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
