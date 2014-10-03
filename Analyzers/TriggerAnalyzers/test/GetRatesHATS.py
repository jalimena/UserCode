import math,ROOT, glob
from ROOT import gROOT, TFile, TChain, TTree, TH1F, TF1

from CrossSections import crossSections13TeV

gROOT.Reset()

#Recommended samples to use: QCD with Pt 30-1800, DYToMuMu, DYToEE, WToMuNu, WToENu
#samples = ['MuEnr20to30', 'MuEnr30to50', 'MuEnr50to80', 'MuEnr80to120', 'MuEnr120to170', 'MuEnr170to300', 'DYToMuMu', 'WToMuNu']
samples = ['MuEnr30to50', 'MuEnr50to80']


ilumi = 1.1e34


def Rate(count,xsec,nevts):
    rate = xsec*ilumi*(count/nevts)
    return rate


def RateErr(count,xsec,nevts):
    rateerr = ((xsec * ilumi)/nevts) * math.sqrt(count)
    return rateerr

rates = []
err = []

for sample in samples:

    xsec = crossSections13TeV[sample][0]*1e-36
    nevts = crossSections13TeV[sample][1]
    count = crossSections13TeV[sample][2]

    print "sample, nevt, count, xsec: ", sample, " ", nevts, " ", count, " ", xsec/1e-36

    rate = Rate(count,xsec,nevts)
    rateerr = RateErr(count,xsec,nevts)
    rateerrsq = pow(rateerr,2)

    rates.append(rate)
    err.append(rateerrsq)


Totrate = sum(rates)

Toterr = math.sqrt(sum(err))

print "The total rate is ", Totrate, " +- ", Toterr
    
