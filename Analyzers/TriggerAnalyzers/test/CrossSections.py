# Cross sections for 13 TeV, Fall13 MC. If you're not using Fall13,
# check McM for the correct cross sections.

# NOTE: DO NOT USE QCD SAMPLES TOGETHER WITH THE LEPTON ENRICHED
# SAMPLES IF YOU DON'T KNOW HOW TO TAKE CARE OF DOUBLE COUNTING!!

#[0] is the cross section
#[1] is the total number of events
#[2] is the number of events that pass your trigger

crossSections13TeV={
    ## QCD Cross sections
    'QCD30to50'    :(161500000.),
    'QCD50to80'    :(22110000.),
    'QCD80to120'   :(3000114.3),
    'QCD120to170'  :(493200.),
    'QCD170to300'  :(120300.),
    'QCD300to470'  :(7475.),
    'QCD470to600'  :(587.1),
    'QCD600to800'  :(167.),
    'QCD800to1000' :(28.25),
    'QCD1000to1400':(8.195),
    'QCD1400to1800':(0.7346),
    'QCD1800'      :(0.1091),
    #EM Enriched cross sections    
    #the 2nd number for [0] is the EM filtering efficiency you can get from McM website
    'EMEnr20to30'    :(677300000.*0.007),
    'EMEnr30to80'    :(185900000.*0.056),
    'EMEnr80to170'   :(3529000.*0.158),
    #Mu Enriched cross sections
    #the 2nd number for [0] is the MuEnriched filtering efficiency you can get from McM website
    'MuEnr20to30'    :(675300000.*0.0065, 5000., 72.),
    'MuEnr30to50'    :(164400000.*0.0122, 100000., 97.),
    'MuEnr50to80'    :(21930000.*0.0218, 100000., 147.),
    'MuEnr80to120'   :(3000000.*0.0395, 4000., 53.),
    'MuEnr120to170'  :(493200.*0.0473, 5300., 15.),
    'MuEnr170to300'  :(12030.*0.0676, 2300., 35.),
    'MuEnr300to470'  :(7475.*0.0864),
    'MuEnr470to600'  :(587.1*0.1024),
    'MuEnr600to800'  :(167.*0.0996),
    'MuEnr800to1000' :(28.25*0.1033),
    'MuEnr1000'      :(8.975*0.1097),
     #W and Z cross sections
    'WToENu'         :(16000.),
    'WToMuNu'        :(16100., 5300., 16.),
    'DYToMuMu'       :(6870., 5000., 43.),
    'DYToEE'         :(6960.)   
}
