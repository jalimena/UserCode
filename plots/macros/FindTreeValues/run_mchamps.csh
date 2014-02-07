#!/bin/tcsh
source cuts.csh
source cut_values.csh

#foreach x (mchamp100 mchamp200 mchamp300 mchamp400 mchamp500 mchamp600 mchamp700 mchamp800 mchamp900 mchamp1000)
    #./findTreevalues_makehistos_Ntuples_allsamples $x $cuts $cut_values > & "out_"$x"_"$cuts_ &
#end


    #./findTreevalues_makehistos_Ntuples_allsamples mchamp500_l1muons $cuts $cut_values > & "out_mchamp500l1_"$cuts_ &
    #./findTreevalues_makehistos_Ntuples_allsamples mchamp100_changeCosmicPt $cuts $cut_values > & "out_mchamp100co_"$cuts_ &
    ./findTreevalues_makehistos_Ntuples_allsamples mchamp1000_changeCosmicPt $cuts $cut_values > & "out_mchamp1000co_"$cuts_ &
