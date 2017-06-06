//////////////////////////////////////////////////////////////////////////
//
// 'BASIC FUNCTIONALITY' RooFit tutorial macro #102
// 
// Importing data from ROOT TTrees and THx histograms
//
//
//
// 07/2008 - Wouter Verkerke 
// 
/////////////////////////////////////////////////////////////////////////

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooGaussian.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "TTree.h"
#include "TH1D.h"
#include "TRandom.h"
using namespace RooFit ;

TH1D* makeTH1() ;

void roofit_RegionCBackground()
{
  ////////////////////////////////////////////////////////
  // I m p o r t i n g   R O O T   h i s t o g r a m s  //
  ////////////////////////////////////////////////////////

  // I m p o r t   T H 1   i n t o   a   R o o D a t a H i s t
  // ---------------------------------------------------------

  // Create a ROOT TH1 histogram
  TH1D* hh = makeTH1() ;

  // Declare observable x
  RooRealVar x("x","#Delta t_{DT} [ns]",-100,100) ;

  // Create a binned dataset that imports contents of TH1 and associates its contents to observable 'x'
  RooDataHist dh("dh","dh",x,Import(*hh)) ;


  // P l o t   a n d   f i t   a   R o o D a t a H i s t
  // ---------------------------------------------------

  // Make plot of binned dataset showing Poisson error bars (RooFit default)
  RooPlot* frame = x.frame(Title(""));
  dh.plotOn(frame) ; 

  // Fit a Gaussian p.d.f to the data
  RooRealVar mean1("mean1","mean1",-40,-50,-30) ;
  RooRealVar sigma1("sigma1","sigma1",2,0.1,4) ;
  RooGaussian gauss1("gauss1","gauss1",x,mean1,sigma1) ;

  RooRealVar mean2("mean2","mean2",-40,-50,-30) ;
  RooRealVar sigma2("sigma2","sigma2",5,3,10) ;
  RooGaussian gauss2("gauss2","gauss2",x,mean2,sigma2) ;

  RooRealVar mean3("mean3","mean3",-40,-55,-25) ;
  //RooRealVar sigma3("sigma3","sigma3",7,5,10) ;
  RooRealVar sigma3("sigma3","sigma3",1,0.1,2) ;
  RooGaussian gauss3("gauss3","gauss3",x,mean3,sigma3) ;

  RooRealVar alpha("alpha","alpha",-6,-10,-1);
  RooRealVar n("n","n",0,-1,10);
  //RooRealVar n("n","n",1,-1,10);
  //RooRealVar n("n","n",5,-1,20);
  RooCBShape crystalBall("crystalBall","crystalBall",x,mean3,sigma3,alpha,n);

  RooLandau landau("landau","landau",x,mean3,sigma3);

  RooRealVar frac1("frac1","events in gauss1",0.5,0.3,0.8) ;
  RooRealVar frac2("frac2","events in gauss2",0.4,0.2,0.7) ; 
  //RooAddPdf sum("sum","sum",RooArgList(gauss1,gauss2),RooArgList(frac1));
  //RooAddPdf sum("sum","sum",RooArgList(gauss1,crystalBall),RooArgList(frac1));
  RooAddPdf sum("sum","sum",RooArgList(gauss1,landau),RooArgList(frac1));
  //RooAddPdf sum("sum","sum",RooArgList(gauss1),RooArgList(frac1));
  //RooAddPdf sum("sum","sum",RooArgList(crystalBall),RooArgList(frac1));
  //RooAddPdf sum("sum","sum",RooArgList(landau),RooArgList(frac1));
  //RooAddPdf sum("sum","sum",RooArgList(gauss1,gauss2,gauss3),RooArgList(frac1,frac2));
  //RooAddPdf sum("sum","sum",RooArgList(gauss1,gauss2,landau),RooArgList(frac1,frac2));
  //RooAddPdf sum("sum","sum",RooArgList(gauss1,gauss2,crystalBall),RooArgList(frac1,frac2));

  //crystalBall.fitTo(dh);
  //crystalBall.plotOn(frame) ;
  //x.setRange("fitRange",-25.,0);
  //sum.fitTo(dh,Range("fitRange"));
  sum.fitTo(dh);
  sum.plotOn(frame) ;
  sum.paramOn(frame);

  x.setRange("signal",-20.,100);
  RooAbsReal* integral = sum.createIntegral(x,NormSet(x),Range("signal"));
  cout << "Integral > -20 ns = " << integral->getVal()*hh->Integral() << endl; //fraction of fit > -20 * total number of events in histogram

  cout<<"chisq is: "<<frame->chiSquare(3)<<endl;

  // P l o t   a n d   f i t   a   R o o D a t a H i s t   w i t h   i n t e r n a l   e r r o r s
  // ---------------------------------------------------------------------------------------------

  // If histogram has custom error (i.e. its contents is does not originate from a Poisson process
  // but e.g. is a sum of weighted events) you can data with symmetric 'sum-of-weights' error instead
  // (same error bars as shown by ROOT)
  //RooPlot* frame2 = x.frame(Title("Imported TH1 with internal errors")) ;
  //dh.plotOn(frame2,DataError(RooAbsData::SumW2)) ; 
  //gauss.plotOn(frame2) ;

  // Please note that error bars shown (Poisson or SumW2) are for visualization only, the are NOT used
  // in a maximum likelihood fit
  //
  // A (binned) ML fit will ALWAYS assume the Poisson error interpretation of data (the mathematical definition 
  // of likelihood does not take any external definition of errors). Data with non-unit weights can only be correctly
  // fitted with a chi^2 fit (see rf602_chi2fit.C)

  // Draw all frames on a canvas

  TCanvas* c1 = new TCanvas("c1","c1",800,800) ;
  c1->SetLogy();
  frame->Draw();
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg50.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg40.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg30.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg20.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg10.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg45.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg35.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg25.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg15.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg5.pdf");

  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg50_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg40_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg30_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg20_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg10_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg45_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg35_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg25_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg15_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2016data_DeltaTrpcNeg5_GausLandau.pdf");

  //c1->SaveAs("backgroundExtrapolationRegionC_2015data.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg50.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg40.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg30.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg20.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg10.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg45.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg35.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg25.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg15.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg5.pdf");

  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg50_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg40_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg30_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg20_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg10_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg45_GausLandau.pdf");
  c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg35_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg25_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg15_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_2015data_DeltaTrpcNeg5_GausLandau.pdf");

  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg50.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg40.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg30.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg20.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg10.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg45.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg35.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg25.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg15.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicData_DeltaTrpcNeg5.pdf");

  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicMC80X.pdf");
  //c1->SaveAs("backgroundExtrapolationRegionC_cosmicMC76X.pdf");
}

TH1D* makeTH1() 
{
  //TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/NoBPTX_2016BCDEFGH_23Sep2016_Ntuple.root");
  //TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/NoBPTX_2016BCDEFGH_23Sep2016_Ntuple_addDeltaTimeRpcCutSlowly.root");
  //TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/NoBPTX_2016BCDEFGH_23Sep2016_Ntuple_moreDeltaTimeRpcCuts.root");
  //TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/NoBPTX_16Dec2015_Ntuple.root");
  //TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/NoBPTX_16Dec2015_Ntuple_addDeltaTimeRpcCutSlowly.root");
  TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/NoBPTX_16Dec2015_Ntuple_moreDeltaTimeRpcCuts.root");
  //TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/NoBPTX_2016DE_PromptReco_Cosmic_TopAndBottom_Ntuple_addDeltaTimeRpcCutSlowly.root");
  //TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/cosmicMC_0To25Timing_Ntuple_2016_v2_addDeltaTimeRpcCutSlowly.root");
  //TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/cosmicMC_0To25Timing_Ntuple_v2_addDeltaTimeRpcCutSlowly.root");

  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg50Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg40Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg30Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg20Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg10Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg45Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg35Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg25Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg15Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("DelayedMuonsUpperLowerSelection2DeltaTrpcTimeNeg5Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TCanvas* c0 = new TCanvas("c0","c0",800,800) ;
  //hh->Draw();

  return hh ;
}
