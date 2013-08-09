#!/bin/tcsh
source cuts.csh
source cut_values.csh

foreach x (mchamp100 mchamp200 mchamp300 mchamp400 mchamp500 mchamp600 mchamp700 mchamp800 mchamp900 mchamp1000)
    ./findTreevalues_makehistos_Ntuples_allsamples $x $cuts $cut_values > & "out_"$x"_"$cuts_ &
end
