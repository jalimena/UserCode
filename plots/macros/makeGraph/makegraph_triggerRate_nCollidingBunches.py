#!/usr/bin/env python

#run with: python3 makegraph_triggerRate_nCollidingBunches.py

#plots trigger rate as function of number of colliding bunches, saves pdf files
#7e33 V3 menu, June/July 2012

import sys
import os
import re
import math
import functools
from math import *
from array import *
from decimal import *

from ROOT import gROOT, gStyle, gPad, TFile, TCanvas, TH1, TH1F, TH2F, TGraphErrors, TGraphAsymmErrors, TPaveLabel, TLegend, TLine, TF1

gROOT.SetBatch()
gStyle.SetOptStat(0)
gStyle.SetCanvasBorderMode(0)
gStyle.SetPadBorderMode(0)
gStyle.SetPadColor(0)
gStyle.SetCanvasColor(0)
gStyle.SetCanvasDefH(600)
gStyle.SetCanvasDefW(800)
gStyle.SetCanvasDefX(0)
gStyle.SetCanvasDefY(0)
gStyle.SetPadTopMargin(0.15)
gStyle.SetPadBottomMargin(0.15)
gStyle.SetPadLeftMargin(0.15)
gStyle.SetPadRightMargin(0.05)
gStyle.SetTitleColor(1, "XYZ")
gStyle.SetTitleFont(42, "XYZ")
gStyle.SetTitleSize(0.05, "XYZ")
gStyle.SetTitleXSize(0.04)
gStyle.SetTitleXOffset(1.25)
gStyle.SetTitleYSize(0.05)
gStyle.SetTitleYOffset(1.1)
gStyle.SetTextAlign(12)
gStyle.SetLabelColor(1, "XYZ")
gStyle.SetLabelFont(42, "XYZ")
gStyle.SetLabelOffset(0.008, "XYZ")
gStyle.SetLabelSize(0.05, "XYZ")
gStyle.SetAxisColor(1, "XYZ")
gStyle.SetStripDecimals(True)
gStyle.SetTickLength(0.03, "XYZ")
gStyle.SetNdivisions(505, "XYZ")
gStyle.SetPadTickX(1)
gStyle.SetPadTickY(1)
gStyle.SetErrorX(0)
gROOT.ForceStyle()


#using namespace std#
#gROOT->Reset()
#gROOT->SetStyle("Plain")
#gROOT->ForceStyle() #forces it to use the style set above, rather than the style the rootfile was made with
#gROOT->LoadMacro("./style.cpp")
#global_style()
#int color_plot=1   # 1/0 for color/black&white plots
#gStyle->SetOptStat(10) #print only entries in histogram
#gStyle->SetOptStat("e") #print only entries in histogram
#gStyle->SetOptStat("nemrou") #print histogram name, entries, mean, rms, overflow, underflow
#gStyle->SetOptStat("emrou") #entries, mean, rms, overflow, underflow

#gROOT->LoadMacro("tdrstyle.C")
#gROOT->LoadMacro("CMS_lumi.C")

#setTDRStyle()
#tdrGrid(false, tdrStyle)

#bool writeExtraText = True
#TString extraText  = "Preliminary"                                                                                                                                                                
#lumi_8TeV = "8, 13 TeV"
#TString lumi_8TeV = "13 TeV"
#lumi_8TeV = ""
#int iPeriod = 2 # 1=7TeV, 2=8TeV, 3=7+8TeV, 7=7+8+13TeV
#int iPos=0
#int iPos=11 
#int iPos=22
#bool save_plots = false
save_plots = True


#TCanvas* canvas =  TCanvas("c1","c1",10,10,700,550)
canvas = TCanvas("c1","HLT rate vs num colliding bunches",10,10,575,500)
#canvas_style(canvas)
#canvas->SetRightMargin(0.15)


h1 = TH2F("h1","",100,0,3000,30,0,30)
#TH2* h1= TH2F("h1","",30,0,1500,25,0,25)
#TH2* h1= TH2F("h1","",100,0,1,20,0,20)
#TH2* h1= TH2F("h1","",30,0,1500,100,0,1)
#h1.SetStats(kFALSE)
h1.SetTitle("HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX;Number of Colliding Bunches;Rate [Hz]")
h1.GetYaxis().SetTitleOffset(1)
h1.GetXaxis().SetNdivisions(505)
#h2_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1.4,0)


def makeTGraphErrors(x, y, x_err, y_err):
    graph_arrays = [array('d', arg) for arg in [x, y, x_err, y_err]]
    return TGraphErrors(int(len(x)), *graph_arrays)



bunches_data2024_25ns = [2, 8, 62, 386] #number of colliding bunches
rate_data2024_25ns    = [25, 25, 25, 22] #2024 25 ns, rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz)
bunches_data2024_25ns_error = [0,0,0,0]
rate_data2024_25ns_error = [2,2,2,2]

graph_data2024_25ns = makeTGraphErrors(bunches_data2024_25ns, rate_data2024_25ns, bunches_data2024_25ns_error, rate_data2024_25ns_error)
graph_data2024_25ns.SetMarkerStyle(30)
graph_data2024_25ns.SetMarkerColor(1)
graph_data2024_25ns.SetMarkerSize(1.6)




#n_data2023_25ns = 6
bunches_data2023_25ns = [62,  386,   986, 1150,  1805, 2361] #number of colliding bunches
rate_data2023_25ns    = [25,   20,    17,   16,    11,  6.9] #2023 25 ns, rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz)
bunches_data2023_25ns_error = [0,0,0, 0,0,0]
rate_data2023_25ns_error = [2,2,1, 0.5,0.5,0.5]

#graph_data2023_25ns = makeTGraphErrors(n_data2023_25ns, bunches_data2023_25ns, rate_data2023_25ns, bunches_data2023_25ns_error, rate_data2023_25ns_error)
graph_data2023_25ns = makeTGraphErrors(bunches_data2023_25ns, rate_data2023_25ns, bunches_data2023_25ns_error, rate_data2023_25ns_error)
#gr_style(graph_data2023_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1)
graph_data2023_25ns.SetMarkerStyle(29)
graph_data2023_25ns.SetMarkerColor(6)
graph_data2023_25ns.SetMarkerSize(1.6)





n_data2022_25ns = 8
bunches_data2022_25ns = [590,   974, 1214, 1538, 1922, 2160, 2400, 2448] #number of colliding bunches
rate_data2022_25ns    = [22,   19,   17,   14,   11,   9.5,  7.5,  7] #2022 25 ns, rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz)
bunches_data2022_25ns_error = [0,0,0, 0,0,0, 0,0]
rate_data2022_25ns_error = [2,1.5,1.5, 1.5, 1, 1, 1, 1] #determined from width of rate plot in WBM, L2Mu40

graph_data2022_25ns = makeTGraphErrors(bunches_data2022_25ns, rate_data2022_25ns, bunches_data2022_25ns_error, rate_data2022_25ns_error)
#gr_style(graph_data2022_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1)
graph_data2022_25ns.SetMarkerStyle(23)
graph_data2022_25ns.SetMarkerColor(4)
graph_data2022_25ns.SetMarkerSize(1.6)

fit1 = TF1("fit1","[0]*x+[1]",bunches_data2022_25ns[0],bunches_data2022_25ns[n_data2022_25ns-1])
fit1.SetLineColor(2)
graph_data2022_25ns.Fit("fit1","R")

fit1ext = TF1("fit1ext","[0]*x+[1]",bunches_data2022_25ns[n_data2022_25ns-1],3000)
fit1ext.SetParameters(-0.008,26.64)
fit1ext.SetLineColor(2)
fit1ext.SetLineStyle(2)
graph_data2022_25ns.Fit("fit1ext","R+")

#n_data2018_25ns = 8
bunches_data2018_25ns = [973, 1213, 1549, 1900, 2161, 2305, 2448, 2544] #number of colliding bunches
rate_data2018_25ns    = [14, 12.4,  11, 9.1,  7.1,  6.1,  5.4,  4.8] #2018 25 ns, rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz)
bunches_data2018_25ns_error = [0,0,0, 0,0,0, 0,0]
rate_data2018_25ns_error = [1,1,1, 1,1,1, 1,0.6] #determined from width of rate plot in WBM, L2Mu40

graph_data2018_25ns = makeTGraphErrors(bunches_data2018_25ns, rate_data2018_25ns, bunches_data2018_25ns_error, rate_data2018_25ns_error)
#gr_style(graph_data2018_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1)
graph_data2018_25ns.SetMarkerStyle(22)
graph_data2018_25ns.SetMarkerColor(8)
graph_data2018_25ns.SetMarkerSize(1.6)



#n_data2017_25ns = 10
bunches_data2017_25ns = [589,   973, 1213, 1549, 1729, 2017, 2161, 2305, 2448, 2544] #number of colliding bunches
rate_data2017_25ns    = [16.0, 13.4, 12.5, 10.4, 9.5,  7.9,  6.9,   6.1, 5.4,  4.95] #2017 25 ns, /cdaq/physics/Run2017/2e34/v1.0.0/HLT/V6 rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz), use 3.8T runs only
bunches_data2017_25ns_error = [0,0,0, 0,0,0, 0,0,0, 0]
rate_data2017_25ns_error = [1,1,1, 1,1,1, 1,0.6,0.6, 0.6] #determined from width of rate plot in WBM, L2Mu40

graph_data2017_25ns =  makeTGraphErrors(bunches_data2017_25ns, rate_data2017_25ns, bunches_data2017_25ns_error, rate_data2017_25ns_error)
#gr_style(graph_data2017_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1)
graph_data2017_25ns.SetMarkerStyle(21)
graph_data2017_25ns.SetMarkerColor(2)
graph_data2017_25ns.SetMarkerSize(1.6)


#n_data2016_25ns = 13
bunches_data2016_25ns = [49,   74,  301, 589, 877, 1165, 1453, 1740, 1812, 2028, 2064, 2161, 2208] #number of colliding bunches
#rate_data2016_25ns    = [21.5, 21, 19.5,  18, 17,    15,   13, 11.2, 10.8,  9.3,  8.9,  8.3,  8.0] #2016 25 ns, 10e33 V1.0 rate of HLT_L2Mu35_NoVertex_3Sta_NoBPTX3BX (Hz), use 3.8T runs only
rate_data2016_25ns    = [18.8, 18.4, 17,  16, 14.8, 13.2, 11.2,  10,  9.5,  8.3,  7.8,  7.0,  6.8] #2016 25 ns, 10e33 V1.0 rate of HLT_L2Mu40_NoVertex_3Sta_NoBPTX3BX (Hz), use 3.8T runs only
bunches_data2016_25ns_error = [0,0,0, 0,0,0, 0,0,0, 0,0,0, 0]
#rate_data2016_25ns_error = [2,2,2, 1.5,1.5,1.5, 1.5,1.5,1.5, 1,1,1, 1] #determined from width of rate plot in WBM, L2Mu35
rate_data2016_25ns_error = [2,2,2, 1.5,1.5,1.5, 1.5,1.5,1.5, 1,1,1, 1] #determined from width of rate plot in WBM, L2Mu40

graph_data2016_25ns =  makeTGraphErrors(bunches_data2016_25ns, rate_data2016_25ns, bunches_data2016_25ns_error, rate_data2016_25ns_error)
#gr_style(graph_data2016_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1)
#graph_data2016_25ns.SetMarkerStyle(23)
graph_data2016_25ns.SetMarkerStyle(20)
#graph_data2016_25ns.SetMarkerColor(6)
graph_data2016_25ns.SetMarkerColor(1)
graph_data2016_25ns.SetMarkerSize(1.6)



#n_data2015_25ns = 12
bunches_data2015_25ns = [1,26,303,446,589,1021,1165,1289,1453,1596,1813,2232] #number of colliding bunches
rate_data2015_25ns = [24.5,24,22.5,21.5,20,17.5,16,15,14,13,11.5,8] #2015 25 ns, 1.4e33 V3.3 rate of HLT_L2Mu35_NoVertex_3Sta_NoBPTX3BX_NoHalo (Hz), use 3.8T runs only
bunches_data2015_25ns_error = [0,0,0,0,0,00,0,0,0,0,0]
rate_data2015_25ns_error = [2,2,2,2,2,1.5,1.5,1.5,1.5,1.5,1,1] #determined from width of rate plot in WBM

graph_data2015_25ns =  makeTGraphErrors(bunches_data2015_25ns, rate_data2015_25ns, bunches_data2015_25ns_error, rate_data2015_25ns_error)
#gr_style(graph_data2015_25ns,1,1,1,1001,50,-1111,-1111,510,510,22,3,1.3,1)
graph_data2015_25ns.SetMarkerStyle(22)
graph_data2015_25ns.SetMarkerColor(4)
graph_data2015_25ns.SetMarkerSize(1.6)
graph_data2015_25ns.SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]")
graph_data2015_25ns.GetYaxis().SetRangeUser(0,20)



#n_data2015_50ns = 3
bunches_data2015_50ns = [110,254,414] #number of colliding bunches
rate_data2015_50ns = [23,20.5,18] #2015 50 ns, 5e33 V1.0 rate of HLT_L2Mu35_NoVertex_3Sta_NoBPTX3BX_NoHalo (Hz), use 3.8T runs only
bunches_data2015_50ns_error = [0,0,0]
rate_data2015_50ns_error = [2,1,1] #determined from width of rate plot in WBM

graph_data2015_50ns =  makeTGraphErrors(bunches_data2015_50ns, rate_data2015_50ns, bunches_data2015_50ns_error, rate_data2015_50ns_error)
#gr_style(graph_data2015_50ns,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1)
graph_data2015_50ns.SetMarkerStyle(21)
graph_data2015_50ns.SetMarkerColor(2)
graph_data2015_50ns.SetMarkerSize(1.3)
graph_data2015_50ns.SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]")
graph_data2015_50ns.GetYaxis().SetRangeUser(0,20)



#n_data = 4
bunches_data = [1368,807,471,72] #number of colliding bunches
#bunches_data = [.20,.49,.71,.94] #livetime fraction
#rate_data = [.20,.49,.71,.94] #livetime fraction
rate_data = [3.7,9,13.5,17] #7e33 V3 rate of HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo (Hz)
bunches_data_error = [0,0,0,0]
rate_data_error = [0.6,1,1.2,2]

graph_data =  makeTGraphErrors(bunches_data, rate_data, bunches_data_error, rate_data_error)
#gr_style(graph_data,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1)
graph_data.SetMarkerStyle(20)
graph_data.SetMarkerColor(1)
graph_data.SetMarkerSize(1.6)
graph_data.SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]")
graph_data.GetYaxis().SetRangeUser(0,20)

#TF1 *fit1 =  TF1("fit1","pol1",0,1400)
#fit1.SetLineColor(2)
#graph_data.Fit("fit1","R")


#n_data_noChaCut = 1
bunches_data_noChaCut = [1377] #number of colliding bunches
rate_data_noChaCut = [7.4] #7e33 V3 rate of HLT_L2Mu20_NoVertex_NoBPTX3BX_NoHalo (Hz)
bunches_data_noChaCut_error = [0]
rate_data_noChaCut_error = [1]

graph_data_noChaCut =  makeTGraphErrors(bunches_data_noChaCut, rate_data_noChaCut, bunches_data_noChaCut_error, rate_data_noChaCut_error)
#gr_style(graph_data_noChaCut,1,1,1,1001,50,-1111,-1111,510,510,21,2,1.3,1)
graph_data_noChaCut.SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]")
graph_data_noChaCut.GetYaxis().SetRangeUser(0,20)



#n_predicted = 1
bunches_predicted = [1377] #number of colliding bunches
rate_predicted = [3.6] #PREDICTED 7e33 V3 rate of HLT_L2Mu20_NoVertex_2Cha_NoBPTX3BX_NoHalo (Hz)
bunches_predicted_error = [0]
rate_predicted_error = [1]

graph_predicted =  makeTGraphErrors(bunches_predicted, rate_predicted, bunches_predicted_error, rate_predicted_error)
#gr_style(graph_predicted,1,1,1,1001,50,-1111,-1111,510,510,22,4,1.5,1)
graph_predicted.SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]")
graph_predicted.GetYaxis().SetRangeUser(0,20)







#n_instLumi = 7
#bunches_instLumi[n_instLumi] = [4,28,72,249,618,1051,1331] #number of colliding bunches
#instLumi[n_instLumi] = [8,90,300,1000,2600,4500,6000] #initial instantaneous luminosity of the fill *10^30 cm^-2 s^-1 (HF)
#instLumiScaled[n_instLumi] #instantaneous luminosity scaled to be on same graph
#bunches_instLumi_error[n_instLumi] = [0,0,0,0,0,0,0]
#instLumi_error[n_instLumi] = [1,10,50,200,300,500,800]
#instLumiScaled_error[n_instLumi]

#for(Int_t i=0 i<n_instLumi i++)[
#  instLumiScaled[i] = 1.0*instLumi[i]/280
#  instLumiScaled_error[i] = 1.0*instLumi_error[i]/280
#]

#graph_instLumi =  makeTGraphErrors(n_instLumi, bunches_instLumi, instLumi, bunches_instLumi_error, instLumi_error)
#graph_instLumi =  makeTGraphErrors(n_instLumi, bunches_instLumi, instLumiScaled, bunches_instLumi_error, instLumiScaled_error)
#gr_style(graph_instLumi,1,1,1,1001,50,-1111,-1111,510,510,20,1,1.3,1)
#graph_instLumi.SetMarkerStyle(21)
#graph_instLumi.SetMarkerColor(2)
#graph_instLumi.SetMarkerSize(1.6)
#graph_instLumi.SetTitle(";Number of Colliding Bunches;HLT Rate [Hz]")
#graph_instLumi.GetYaxis().SetRangeUser(0,20)


#r_axis =  TGaxis(1500,0,1500,25,0,7000,7,"+L")
#r_axis.SetTitle("Instantaneous Luminosity [E30 cm^{-2}s^{-1}]")
#r_axis.SetLineColor(2)
#r_axis.SetLabelColor(2)
#r_axis.SetTitleColor(2)
#r_axis.SetTitleOffset(1.5)
#r_axis.SetLabelOffset(0.01)

Leg1 = TLegend(0.70,0.60,0.90,0.80)
#Leg1 =  TLegend(0.50,0.70,0.80,0.85)
#Leg1 =  TLegend(0.18,0.75,0.43,0.85)
#Leg1.AddEntry(graph_data_noChaCut,"Average Before TS","p")
#Leg1.AddEntry(graph_data,"After TS","p")
#Leg1.AddEntry(graph_predicted,"Predicted After TS","p")
#Leg1.AddEntry(graph_data,"HLT Rate","p")
#Leg1.AddEntry(graph_instLumi,"Instantaneous Luminosity","p")
#Leg1.AddEntry(graph_data,"2012 Trigger, 50 ns","p")
#Leg1.AddEntry(graph_data2015_50ns,"2015 Trigger, 50 ns","p")
#Leg1.AddEntry(graph_data2015_25ns,"2015 Trigger, 25 ns","p")
#Leg1.AddEntry(graph_data2016_25ns,"2016 Trigger, 25 ns","p")
Leg1.AddEntry(graph_data2016_25ns,"2016","p")
Leg1.AddEntry(graph_data2017_25ns,"2017","p")
Leg1.AddEntry(graph_data2018_25ns,"2018","p")
Leg1.AddEntry(graph_data2022_25ns,"2022","p")
Leg1.AddEntry(graph_data2023_25ns,"2023","p")
Leg1.AddEntry(graph_data2024_25ns,"2024","p")
Leg1.SetBorderSize(0)
#Leg1.SetTextSize(0.03)
Leg1.SetTextSize(0.04)
Leg1.SetFillColor(0)



#bestest place for lumi. label, in top left corner
topLeft_x_left    = 0.18
y_bottom    = 0.86
y_bottomCMS = 0.77
topLeft_x_right   = 0.53
y_top     = 0.91
y_topCMS  = 0.82

#position for header
header_x_left    = 0.60
header_x_right   = 0.95


HeaderLabel = TPaveLabel(header_x_left,y_bottom,header_x_right,y_top,"(13, 13.6 TeV)","NDC")
HeaderLabel.SetTextAlign(32)
HeaderLabel.SetTextFont(42)
HeaderLabel.SetTextSize(0.9)
HeaderLabel.SetBorderSize(0)
HeaderLabel.SetFillColor(0)

CMSLabel = TPaveLabel(topLeft_x_left,y_bottomCMS,topLeft_x_right,y_topCMS,"CMS","NDC")
CMSLabel.SetTextFont(62)
CMSLabel.SetTextSize(1)
CMSLabel.SetTextAlign(12)
CMSLabel.SetBorderSize(0)
CMSLabel.SetFillColor(0)


canvas.cd()
h1.Draw()
#graph_data.Draw("Psame")
#graph_data2015_50ns.Draw("Psame")
#graph_data2015_25ns.Draw("Psame")
graph_data2016_25ns.Draw("Psame")
graph_data2017_25ns.Draw("Psame")
graph_data2018_25ns.Draw("Psame")
graph_data2022_25ns.Draw("Psame")
graph_data2023_25ns.Draw("Psame")
graph_data2024_25ns.Draw("Psame")
#graph_instLumi.Draw("Psame")
#graph_data_noChaCut.Draw("Psame")
#graph_predicted.Draw("Psame")
CMSLabel.Draw()
HeaderLabel.Draw()
#r_axis.Draw()
Leg1.Draw()
#CMS_lumi( canvas, iPeriod, iPos )
#if(save_plots) canvas.SaveAs("../../plots/nbunches_rate.eps")
if save_plots:
    canvas.SaveAs("L2Mu40RateVsNCollidingBunches.pdf")

