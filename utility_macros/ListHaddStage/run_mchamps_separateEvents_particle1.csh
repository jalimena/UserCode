#!/bin/tcsh
source hosts.csh

foreach x (mchamp100_separateEvents_particle1_725 mchamp200_separateEvents_particle1_725 mchamp300_separateEvents_particle1_725 mchamp400_separateEvents_particle1_725 mchamp500_separateEvents_particle1_725 mchamp600_separateEvents_particle1_725 mchamp700_separateEvents_particle1_725 mchamp700_separateEvents_particle1_2ndHalf_725 mchamp800_separateEvents_particle1_725 mchamp900_separateEvents_particle1_725 mchamp1000_separateEvents_particle1_725)
    source $p"ListHaddStage.csh" $x > & "out_"$x &
end
