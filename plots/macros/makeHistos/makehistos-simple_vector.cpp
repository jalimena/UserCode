{
  //   example of macro to read data from an ascii file and
  //   create an histogram

  using namespace std;

  gROOT->Reset();
  gROOT->SetStyle("Plain");
  gROOT->ForceStyle(); //forces it to use the style set above, rather than the style the rootfile was made with
  gROOT->LoadMacro("./style.cpp");
  global_style();
  int color_plot=1;   // 1/0 for color/black&white plots
  //gStyle->SetOptStat(10); //print only entries in histogram
  //gStyle->SetOptStat("e"); //print only entries in histogram
  //gStyle->SetOptStat("nemrou"); //print histogram name, entries, mean, rms, overflow, underflow
  gStyle->SetOptStat("emrou"); //print entries, mean, rms, overflow, underflow
  //gStyle->SetStatW(.1);
  gStyle->SetStatH(.1);
  gStyle->SetTitleW(0.65);
  gStyle->SetTitleH(0.07);
  
  TCanvas* c1 = new TCanvas("c1","opening angle",10,10,700,500);
  canvas_style(c1);

  ifstream in;
  in.open("opening_angle_191101.txt", ios::in);
  
  Float_t angle;
  TH1F *h1 = new TH1F("h1","Opening Angle",24,0,3);
  h1_style(h1,3,1,1,1001,50,-1111.,-1111.,510,510,20,1,1,1);
  h1->SetTitle(";Opening Angle [rad];Events");
  
  while (1) {
    in >> angle;
    if (!in.good()) break;
    h1->Fill(angle);
  }

  c1->cd();
  h1->Draw();
  c1->SaveAs("/afs/cern.ch/user/j/jalimena/scratch0/plots/plots/StoppedHSCPMuon/RawData/191101_cosmics/opening_angle.eps");
}
