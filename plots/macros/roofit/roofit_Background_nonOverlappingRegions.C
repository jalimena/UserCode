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

void roofit_Background_nonOverlappingRegions()
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
  RooRealVar sigma3("sigma3","sigma3",7,5,10) ; //crystal ball
  //RooRealVar sigma3("sigma3","sigma3",1,0.1,2) ; //landau
  RooGaussian gauss3("gauss3","gauss3",x,mean3,sigma3) ;

  RooRealVar alpha("alpha","alpha",-6,-10,-1);
  RooRealVar n("n","n",0,-1,10);
  //RooRealVar n("n","n",1,-1,10);
  //RooRealVar n("n","n",5,-1,20);
  RooCBShape crystalBall("crystalBall","crystalBall",x,mean3,sigma3,alpha,n);

  RooLandau landau("landau","landau",x,mean3,sigma3);

  RooRealVar frac1("frac1","events in gauss1",0.5,0.3,0.8) ;
  RooRealVar frac2("frac2","events in gauss2",0.4,0.2,0.7) ; 
  RooAddPdf sum("sum","sum",RooArgList(gauss1,gauss2,crystalBall),RooArgList(frac1,frac2));
  //RooAddPdf sum("sum","sum",RooArgList(gauss1,gauss2,landau),RooArgList(frac1,frac2));

  //crystalBall.fitTo(dh);
  //crystalBall.plotOn(frame) ;
  //x.setRange("fitRange",-25.,0);
  //sum.fitTo(dh,Range("fitRange"));
  sum.fitTo(dh);
  sum.plotOn(frame) ;
  sum.paramOn(frame);


  x.setRange("signal",-20.,100);
  RooAbsReal* integral = sum.createIntegral(x,NormSet(x),Range("signal"));
  double integralValueNominal = integral->getVal()*hh->Integral();
  cout << "Integral > -20 ns = " << integralValueNominal << endl; //fraction of fit > -20 * total number of events in histogram

  cout<<"chisq is: "<<frame->chiSquare(3)<<endl;



  RooRealVar mean1Lo("mean1Lo","mean1Lo",mean1.getVal()-mean1.getError()) ;
  RooRealVar sigma1Lo("sigma1Lo","sigma1Lo",sigma1.getVal()-sigma1.getError()) ;
  RooGaussian gauss1Lo("gauss1Lo","gauss1Lo",x,mean1Lo,sigma1Lo) ;

  RooRealVar mean2Lo("mean2Lo","mean2Lo",mean2.getVal()-mean2.getError()) ;
  RooRealVar sigma2Lo("sigma2Lo","sigma2Lo",sigma2.getVal()-sigma2.getError()) ;
  RooGaussian gauss2Lo("gauss2Lo","gauss2Lo",x,mean2Lo,sigma2Lo) ;

  RooRealVar mean3Lo("mean3Lo","mean3Lo",mean3.getVal()-mean3.getError()) ;
  RooRealVar sigma3Lo("sigma3Lo","sigma3Lo",sigma3.getVal()-sigma3.getError()) ;
  RooGaussian gauss3Lo("gauss3Lo","gauss3Lo",x,mean3Lo,sigma3Lo) ;


  RooRealVar alphaLo("alphaLo","alphaLo",alpha.getVal()-alpha.getError()) ;
  RooRealVar nLo("nLo","nLo",n.getVal()-n.getError()) ;

  RooCBShape crystalBallLo("crystalBallLo","crystalBallLo",x,mean3Lo,sigma3Lo,alphaLo,nLo);

  RooLandau landauLo("landauLo","landauLo",x,mean3Lo,sigma3Lo);

  RooRealVar frac1Lo("frac1Lo","events in gauss1",frac1.getVal()-frac1.getError()) ;
  RooRealVar frac2Lo("frac2Lo","events in gauss2",frac2.getVal()-frac2.getError()) ;
  RooAddPdf sumLo("sumLo","sumLo",RooArgList(gauss1Lo,gauss2Lo,crystalBallLo),RooArgList(frac1Lo,frac2Lo));
  //RooAddPdf sumLo("sumLo","sumLo",RooArgList(gauss1Lo,gauss2Lo,landauLo),RooArgList(frac1Lo,frac2Lo));

  sumLo.plotOn(frame,LineColor(kRed)) ;

  RooAbsReal* integralLo = sumLo.createIntegral(x,NormSet(x),Range("signal"));
  double integralValueLo = integralLo->getVal()*hh->Integral();
  cout << "IntegralLo > -20 ns = " << integralValueLo << endl; //fraction of fit > -20 * total number of events in histogram


  RooRealVar mean1Hi("mean1Hi","mean1Hi",mean1.getVal()+mean1.getError()) ;
  RooRealVar sigma1Hi("sigma1Hi","sigma1Hi",sigma1.getVal()+sigma1.getError()) ;
  RooGaussian gauss1Hi("gauss1Hi","gauss1Hi",x,mean1Hi,sigma1Hi) ;

  RooRealVar mean2Hi("mean2Hi","mean2Hi",mean2.getVal()+mean2.getError()) ;
  RooRealVar sigma2Hi("sigma2Hi","sigma2Hi",sigma2.getVal()+sigma2.getError()) ;
  RooGaussian gauss2Hi("gauss2Hi","gauss2Hi",x,mean2Hi,sigma2Hi) ;

  RooRealVar mean3Hi("mean3Hi","mean3Hi",mean3.getVal()+mean3.getError()) ;
  RooRealVar sigma3Hi("sigma3Hi","sigma3Hi",sigma3.getVal()+sigma3.getError()) ;
  RooGaussian gauss3Hi("gauss3Hi","gauss3Hi",x,mean3Hi,sigma3Hi) ;


  RooRealVar alphaHi("alphaHi","alphaHi",alpha.getVal()+alpha.getError()) ;
  RooRealVar nHi("nHi","nHi",n.getVal()+n.getError()) ;

  RooCBShape crystalBallHi("crystalBallHi","crystalBallHi",x,mean3Hi,sigma3Hi,alphaHi,nHi);

  RooLandau landauHi("landauHi","landauHi",x,mean3Hi,sigma3Hi);

  RooRealVar frac1Hi("frac1Hi","events in gauss1",frac1.getVal()+frac1.getError()) ;
  RooRealVar frac2Hi("frac2Hi","events in gauss2",frac2.getVal()+frac2.getError()) ;
  RooAddPdf sumHi("sumHi","sumHi",RooArgList(gauss1Hi,gauss2Hi,crystalBallHi),RooArgList(frac1Hi,frac2Hi));
  //RooAddPdf sumHi("sumHi","sumHi",RooArgList(gauss1Hi,gauss2Hi,landauHi),RooArgList(frac1Hi,frac2Hi));

  sumHi.plotOn(frame,LineColor(kGreen)) ;

  RooAbsReal* integralHi = sumHi.createIntegral(x,NormSet(x),Range("signal"));
  double integralValueHi = integralHi->getVal()*hh->Integral();
  cout << "IntegralHi > -20 ns = " << integralValueHi << endl; //fraction of fit > -20 * total number of events in histogram

  double integralValueMinus, integralValuePlus;
  if((integralValueNominal-integralValueLo)> 0.) integralValuePlus = integralValueNominal-integralValueLo;
  else integralValueMinus = integralValueLo-integralValueNominal;

  if((integralValueNominal-integralValueHi)> 0.) integralValuePlus = integralValueNominal-integralValueHi;
  else integralValueMinus = integralValueHi-integralValueNominal;

 

  cout << "Integral > -20 ns = " << integralValueNominal <<" + "<<integralValuePlus  <<" - "<<integralValueMinus<< endl;
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
  frame->GetYaxis()->SetRangeUser(.1,100);
  frame->Draw();
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg999toNeg50.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg50toNeg45.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg45toNeg40.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg40toNeg35.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg35toNeg30.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg30toNeg25.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg25toNeg20.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg20toNeg15.pdf");
  c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg15toNeg10.pdf");

  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg999toNeg50_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg50toNeg45_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg45toNeg40_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg40toNeg35_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg35toNeg30_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg30toNeg25_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg25toNeg20_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg20toNeg15_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2016data_DeltaTrpcNeg15toNeg10_GausLandau.pdf");

  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg999toNeg50.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg50toNeg45.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg45toNeg40.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg40toNeg35.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg35toNeg30.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg30toNeg25.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg25toNeg20.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg20toNeg15.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg15toNeg10.pdf");

  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg999toNeg50_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg50toNeg45_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg45toNeg40_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg40toNeg35_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg35toNeg30_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg30toNeg25_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg25toNeg20_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg20toNeg15_GausLandau.pdf");
  //c1->SaveAs("backgroundExtrapolation_2015data_DeltaTrpcNeg15toNeg10_GausLandau.pdf");


  frame->Print("v");
}

TH1D* makeTH1() 
{
  TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/NoBPTX_2016BCDEFGH_23Sep2016_Ntuple.root");
  //TFile* f1 = new TFile("/afs/cern.ch/work/j/jalimena/CMSSW_8_0_22/src/NoBPTX_16Dec2015_Ntuple.root");

  //TH1D* hh = (TH1D*) f1->Get("BackgroundExtrapolationUpperLowerSelectionDeltaTrpcTimeNeg999ToNeg50Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("BackgroundExtrapolationUpperLowerSelectionDeltaTrpcTimeNeg50ToNeg45Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("BackgroundExtrapolationUpperLowerSelectionDeltaTrpcTimeNeg45ToNeg40Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("BackgroundExtrapolationUpperLowerSelectionDeltaTrpcTimeNeg40ToNeg35Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("BackgroundExtrapolationUpperLowerSelectionDeltaTrpcTimeNeg35ToNeg30Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("BackgroundExtrapolationUpperLowerSelectionDeltaTrpcTimeNeg30ToNeg25Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("BackgroundExtrapolationUpperLowerSelectionDeltaTrpcTimeNeg25ToNeg20Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TH1D* hh = (TH1D*) f1->Get("BackgroundExtrapolationUpperLowerSelectionDeltaTrpcTimeNeg20ToNeg15Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  TH1D* hh = (TH1D*) f1->Get("BackgroundExtrapolationUpperLowerSelectionDeltaTrpcTimeNeg15ToNeg10Plotter/Track-secondaryTrack Plots/delta_dtTofTimeAtIpInOut");
  //TCanvas* c0 = new TCanvas("c0","c0",800,800) ;
  //hh->Draw();

  return hh ;
}
