{
gROOT->Reset();
gROOT->SetStyle("Plain");
gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
gROOT->LoadMacro("./style.cpp");
global_style();

TCanvas* canvas = new TCanvas("canvas","canvas",10,10,800,600);
canvas->SetGridx();
canvas->SetGridy();
const int NumPoints = 1000;

Double_t x[NumPoints];
Double_t y_data[NumPoints];
Double_t y_allphi_cosmics[NumPoints];
Double_t y_signal[NumPoints];
Double_t y_SsqrtB[NumPoints];

for(int i=0; i<NumPoints; i++) x[i]=1.0*i/10;

//read in text files
ifstream inFile1, inFile2, inFile3;
/*
inFile1.open("../txtfiles/percent_passHitChisq_zmumu.txt");
inFile2.open("../txtfiles/percent_passHitChisq_allphi_cosmics.txt");
inFile3.open("../txtfiles/percent_passHitChisq_stop600_neutralino417.txt");
*/
/*
inFile1.open("../txtfiles/percent_passHitChisq_LowInversebetaLS_zmumu.txt");
inFile2.open("../txtfiles/percent_passHitChisq_LowInversebetaLS_allphi_cosmics.txt");
inFile3.open("../txtfiles/percent_passHitChisq_LowInversebetaLS_stop600_neutralino417.txt");
*/
/*
inFile1.open("../txtfiles/pt20_eta1_DTchambers2/percent_passHitChisq_zmumu.txt");
inFile2.open("../txtfiles/pt20_eta1_DTchambers2/percent_passHitChisq_allphi_cosmics.txt");
inFile3.open("../txtfiles/pt20_eta1_DTchambers2/percent_passHitChisq_stop600_neutralino417.txt");
*/
/*
inFile1.open("../txtfiles/pt20_eta1_DTchambers2/percent_passHitChisq_LowInversebetaLS_zmumu.txt");
inFile2.open("../txtfiles/pt20_eta1_DTchambers2/percent_passHitChisq_LowInversebetaLS_allphi_cosmics.txt");
inFile3.open("../txtfiles/pt20_eta1_DTchambers2/percent_passHitChisq_LowInversebetaLS_stop600_neutralino417.txt");
*/

/*
inFile1.open("../txtfiles/pt20_eta1_DTchambers2_upper/percent_passHitChisq_zmumu.txt");
inFile2.open("../txtfiles/pt20_eta1_DTchambers2_upper/percent_passHitChisq_allphi_cosmics.txt");
inFile3.open("../txtfiles/pt20_eta1_DTchambers2_upper/percent_passHitChisq_stop600_neutralino417.txt");
*/
/*
inFile1.open("../txtfiles/pt20_eta1_DTchambers2_upper/percent_passHitChisq_LowInversebetaLS_zmumu.txt");
inFile2.open("../txtfiles/pt20_eta1_DTchambers2_upper/percent_passHitChisq_LowInversebetaLS_allphi_cosmics.txt");
inFile3.open("../txtfiles/pt20_eta1_DTchambers2_upper/percent_passHitChisq_LowInversebetaLS_stop600_neutralino417.txt");
*/

inFile1.open("../txtfiles/pt20_eta1_DTchambers2_upper/percent_passHitChisq_HighInversebetaLS_zmumu.txt");
inFile2.open("../txtfiles/pt20_eta1_DTchambers2_upper/percent_passHitChisq_HighInversebetaLS_allphi_cosmics.txt");
inFile3.open("../txtfiles/pt20_eta1_DTchambers2_upper/percent_passHitChisq_HighInversebetaLS_stop600_neutralino417.txt");

for(int i=0; i<NumPoints; i++){
  inFile1 >> y_data[i];
  inFile2 >> y_allphi_cosmics[i];
  inFile3 >> y_signal[i];
  y_SsqrtB[i] = y_signal[i]/(y_allphi_cosmics[i]);
}
inFile1.close();
inFile2.close();
inFile3.close();

for(int i=0; i<NumPoints; i++){
  cout<<"y_signal["<<i<<"] is: "<<y_signal[i]<<", y_allphi_cosmics["<<i<<"] is: "<<y_allphi_cosmics[i]<<", and y_SsqrtB["<<i<<"] is: "<<y_SsqrtB[i]<<endl;
}

TGraph* gr_data = new TGraph(NumPoints,x,y_data);
TGraph* gr_allphi_cosmics = new TGraph(NumPoints,x,y_allphi_cosmics);
TGraph* gr_signal = new TGraph(NumPoints,x,y_signal);
TGraph* gr_SsqrtB = new TGraph(NumPoints,x,y_SsqrtB);
gr_style(gr_data);
gr_style(gr_allphi_cosmics,2,2,1,1001,50,-1111,-1111,510,510,21,2,1,1);
gr_style(gr_signal,2,3,1,1001,50,-1111,-1111,510,510,22,3,1,1);
gr_style(gr_SsqrtB,2,4,1,1001,50,-1111,-1111,510,510,23,4,1,1);
gr_data->SetTitle(";Individual #chi^{2} Cut;Fraction of Hits Passing Individual #chi^{2} Cut");
gr_allphi_cosmics->SetTitle(";#Individual chi^{2} Cut;Fraction of Hits Passing Individual #chi^{2} Cut");
gr_signal->SetTitle(";#Individual chi^{2} Cut;Fraction of Hits Passing Individual #chi^{2} Cut");
gr_data->GetXaxis()->SetRangeUser(0,50);
gr_allphi_cosmics->GetXaxis()->SetRangeUser(0,50);
gr_signal->GetXaxis()->SetRangeUser(0,50);
gr_SsqrtB->GetXaxis()->SetRangeUser(0,50);
gr_data->GetYaxis()->SetRangeUser(0.4,1.1);
gr_allphi_cosmics->GetYaxis()->SetRangeUser(0.4,1.1);
gr_signal->GetYaxis()->SetRangeUser(0.4,1.1);
gr_SsqrtB->GetYaxis()->SetRangeUser(0.4,1.1);
/*
gr_data->GetYaxis()->SetRangeUser(0.4,1);
gr_allphi_cosmics->GetYaxis()->SetRangeUser(0.4,1);
gr_signal->GetYaxis()->SetRangeUser(0.4,1);
gr_SsqrtB->GetYaxis()->SetRangeUser(0.4,1);
*/


Leg1 = new TLegend(0.60,0.6,0.85,0.78);
Leg1->AddEntry(gr_data,"Z->mumu Data","p");
Leg1->AddEntry(gr_allphi_cosmics,"All-Phi Cosmics","p");
Leg1->AddEntry(gr_signal,"#tilde{t_{1}} 600 GeV","p");
Leg1->SetTextSize(0.03);
Leg1->SetFillColor(0);
Leg1->SetBorderSize(0);
Leg1->SetFillColor(0);

canvas->cd();
gr_data->Draw("AP");
gr_allphi_cosmics->Draw("Psame");
gr_signal->Draw("Psame");
//gr_SsqrtB->Draw("Psame");
Leg1->Draw("same");
//canvas->SaveAs("../plots/timing/DT/zmumu_cosmic_signal/percent_chi2.eps");
//canvas->SaveAs("../plots/timing/DT/zmumu_cosmic_signal/percent_chi2_LowInversebetaLS.eps");
//canvas->SaveAs("../plots/timing/DT/zmumu_cosmic_signal/pt20_eta1_DTchambers2/percent_chi2.eps");
//canvas->SaveAs("../plots/timing/DT/zmumu_cosmic_signal/pt20_eta1_DTchambers2/percent_chi2_LowInversebetaLS.eps");
//canvas->SaveAs("../plots/timing/DT/zmumu_cosmic_signal/pt20_eta1_DTchambers2_upper/percent_chi2.eps");
//canvas->SaveAs("../plots/timing/DT/zmumu_cosmic_signal/pt20_eta1_DTchambers2_upper/percent_chi2_LowInversebetaLS.eps");
canvas->SaveAs("../plots/timing/DT/zmumu_cosmic_signal/pt20_eta1_DTchambers2_upper/percent_chi2_HighInversebetaLS.eps");


}
