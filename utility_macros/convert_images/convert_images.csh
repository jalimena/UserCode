#!/bin/tcsh

foreach i (*.eps)
    set f=$i:r
    convert -quality 100 $i ${f}.jpg
end
