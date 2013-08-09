#include "iostream"
#include "string"
#include "sstream"
#include "cmath"
#include "vector"
#include "math.h"
#include "TROOT.h"
#include "TRint.h"
#include "TSystem.h"
#include "TFile.h"
#include "TMath.h"
#include "TObject.h"
#include "TString.h"
#include "Riostream.h"

using namespace std;

bool debug = false;
//bool debug = true;

//read in text file of crab job output files
//find the number of output files created
int get_Nfiles(){
  ifstream inFile;
  TString f = "crabOutput.txt";
  inFile.open(f);
  
  int nfiles = 0;
  string line;
  while (getline(inFile, line)){
    nfiles++;
    if(debug) cout<<"line is: "<<line<<endl;
  }
  cout<<endl<<"Number of files: "<<nfiles<<endl;
  inFile.close();
  
  return nfiles;
}

int main(int argc, char* argv[]){
  if(argc!=2){
    cout<<"ERROR, need more arguments!"<<endl;
    return 1;
  }

  if(debug) cout<<"started function"<<endl;

  TString number_jobs = "1";
  if(argc==2){
    number_jobs = argv[1];
    if(debug) cout<<" number_jobs is: "<<number_jobs<<endl;
  }

  int total_number_jobs = 1;
  sscanf(number_jobs,"%d",&total_number_jobs);
  cout<<"The total number of jobs is: "<<total_number_jobs<<endl;

  //read in text file of crab job output files and their sizes
  int Nfiles;
  if(debug) Nfiles = 5;
  else Nfiles = get_Nfiles();
  ifstream inFile;
  TString f = "crabOutput.txt";
  inFile.open(f);

  string path[Nfiles];
  string size[Nfiles];
  for (int a=0; a<Nfiles; a++) {
    inFile>>path[a]>>size[a];
    if(debug) cout<<"path is: "<<path[a]<<", size is: "<<size[a]<<endl;
  }
  if(Nfiles>0) cout<<"First path is: "<<path[0]<<endl;

  //find any files with 0 size
  cout<<endl<<"----------------------------------------- Files with 0 size ------------------------------------------"<<endl;
  for (int a=0; a<Nfiles; a++) {
    if(size[a]=="size=0") cout<<path[a]<<" "<<size[a]<<endl;
    if(debug) {
      if(size[a]=="size=93442458") cout<<path[a]<<" "<<size[a]<<endl;
    }
  }
  cout<<"------------------------------------------------------------------------------------------------------"<<endl<<endl;

  //get job number from each file path in list
  size_t position[Nfiles];
  size_t position2[Nfiles];
  size_t start_position[Nfiles];
  size_t end_position[Nfiles];
  size_t n[Nfiles];
  string job_number[Nfiles];
  for (int a=0; a<Nfiles; a++) {
    if(path[a].find("stoppedHSCP") != string::npos){
      if(debug) cout<<"stoppedHSCP"<<endl;
      position[a] = path[a].find("stoppedHSCP");
      start_position[a] = path[a].find("_",position[a]+1);
    }
    if (path[a].find("stop600_200") != string::npos){
      if(debug) cout<<"stop600_200"<<endl;
      position[a] = path[a].find("stop600_200");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop100_30") != string::npos){
      if(debug) cout<<"stop100_30"<<endl;
      position[a] = path[a].find("stop100_30");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop100_50") != string::npos){
      if(debug) cout<<"stop100_50"<<endl;
      position[a] = path[a].find("stop100_50");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop200_75") != string::npos){
      if(debug) cout<<"stop200_75"<<endl;
      position[a] = path[a].find("stop200_75");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop300_109") != string::npos){
      if(debug) cout<<"stop300_109"<<endl;
      position[a] = path[a].find("stop300_109");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop400_214") != string::npos){
      if(debug) cout<<"stop400_214"<<endl;
      position[a] = path[a].find("stop400_214");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop500_316") != string::npos){
      if(debug) cout<<"stop500_316"<<endl;
      position[a] = path[a].find("stop500_316");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop600_417") != string::npos){
      if(debug) cout<<"stop600_417"<<endl;
      position[a] = path[a].find("stop600_417");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop700_518") != string::npos){
      if(debug) cout<<"stop700_518"<<endl;
      position[a] = path[a].find("stop700_518");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop800_618") != string::npos){
      if(debug) cout<<"stop800_618"<<endl;
      position[a] = path[a].find("stop800_618");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop900_718") != string::npos){
      if(debug) cout<<"stop900_718"<<endl;
      position[a] = path[a].find("stop900_718");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("stop1000_819") != string::npos){
      if(debug) cout<<"stop1000_819"<<endl;
      position[a] = path[a].find("stop1000_819");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gluino600_200") != string::npos){
      if(debug) cout<<"gluino600_200"<<endl;
      position[a] = path[a].find("gluino600_200");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("ppstau494_200") != string::npos){
      if(debug) cout<<"ppstau494_200"<<endl;
      position[a] = path[a].find("ppstau494_200");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau494_200") != string::npos){
      if(debug) cout<<"gmstau494_200"<<endl;
      position[a] = path[a].find("gmstau494_200");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau100_p0001") != string::npos){
      if(debug) cout<<"gmstau100_p0001"<<endl;
      position[a] = path[a].find("gmstau100_p0001");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau126_p0001") != string::npos){
      if(debug) cout<<"gmstau126_p0001"<<endl;
      position[a] = path[a].find("gmstau126_p0001");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau156_p0001") != string::npos){
      if(debug) cout<<"gmstau156_p0001"<<endl;
      position[a] = path[a].find("gmstau156_p0001");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau200_p0001") != string::npos){
      if(debug) cout<<"gmstau200_p0001"<<endl;
      position[a] = path[a].find("gmstau200_p0001");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau247_p0001") != string::npos){
      if(debug) cout<<"gmstau247_p0001"<<endl;
      position[a] = path[a].find("gmstau247_p0001");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau308_p0001") != string::npos){
      if(debug) cout<<"gmstau308_p0001"<<endl;
      position[a] = path[a].find("gmstau308_p0001");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau370_p0001") != string::npos){
      if(debug) cout<<"gmstau370_p0001"<<endl;
      position[a] = path[a].find("gmstau370_p0001");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau432_p0001") != string::npos){
      if(debug) cout<<"gmstau432_p0001"<<endl;
      position[a] = path[a].find("gmstau432_p0001");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("gmstau494_p0001") != string::npos){
      if(debug) cout<<"gmstau494_p0001"<<endl;
      position[a] = path[a].find("gmstau494_p0001");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("mchamp600_200") != string::npos){
      if(debug) cout<<"mchamp600_200"<<endl;
      position[a] = path[a].find("mchamp600_200");
      start_position[a] = path[a].find("_",position[a]+10); //for stop600_200, gluino600_200
    }
    if (path[a].find("mchamp100") != string::npos){
      if(debug) cout<<"mchamp100"<<endl;
      position2[a] = path[a].find("mchamp100");
      position[a] = path[a].find("mchamp100",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("mchamp200") != string::npos){
      if(debug) cout<<"mchamp200"<<endl;
      position2[a] = path[a].find("mchamp200");
      position[a] = path[a].find("mchamp200",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("mchamp300") != string::npos){
      if(debug) cout<<"mchamp300"<<endl;
      position2[a] = path[a].find("mchamp300");
      position[a] = path[a].find("mchamp300",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("mchamp400") != string::npos){
      if(debug) cout<<"mchamp400"<<endl;
      position2[a] = path[a].find("mchamp400");
      position[a] = path[a].find("mchamp400",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("mchamp500") != string::npos){
      if(debug) cout<<"mchamp500"<<endl;
      position2[a] = path[a].find("mchamp500");
      position[a] = path[a].find("mchamp500",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("mchamp600") != string::npos){
      if(debug) cout<<"mchamp600"<<endl;
      position2[a] = path[a].find("mchamp600");
      position[a] = path[a].find("mchamp600",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("mchamp700") != string::npos){
      if(debug) cout<<"mchamp700"<<endl;
      position2[a] = path[a].find("mchamp700");
      position[a] = path[a].find("mchamp700",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("mchamp800") != string::npos){
      if(debug) cout<<"mchamp800"<<endl;
      position2[a] = path[a].find("mchamp800");
      position[a] = path[a].find("mchamp800",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("mchamp900") != string::npos){
      if(debug) cout<<"mchamp900"<<endl;
      position2[a] = path[a].find("mchamp900");
      position[a] = path[a].find("mchamp900",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("mchamp1000") != string::npos){
      if(debug) cout<<"mchamp1000"<<endl;
      position2[a] = path[a].find("mchamp1000");
      position[a] = path[a].find("mchamp1000",position2[a]+1);
      start_position[a] = path[a].find("_",position[a]+5); //for mchamp100
    }
    if (path[a].find("gluino300_173") != string::npos){
      if(debug) cout<<"gluino300_173"<<endl;
      position[a] = path[a].find("gluino300_173");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino400_283") != string::npos){
      if(debug) cout<<"gluino400_283"<<endl;
      position[a] = path[a].find("gluino400_283");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino500_387") != string::npos){
      if(debug) cout<<"gluino500_387"<<endl;
      position[a] = path[a].find("gluino500_387");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino600_490") != string::npos){
      if(debug) cout<<"gluino600_490"<<endl;
      position[a] = path[a].find("gluino600_490");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino700_592") != string::npos){
      if(debug) cout<<"gluino700_592"<<endl;
      position[a] = path[a].find("gluino700_592");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino800_693") != string::npos){
      if(debug) cout<<"gluino800_693"<<endl;
      position[a] = path[a].find("gluino800_693");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino900_794") != string::npos){
      if(debug) cout<<"gluino900_794"<<endl;
      position[a] = path[a].find("gluino900_794");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino1000_894") != string::npos){
      if(debug) cout<<"gluino1000_894"<<endl;
      position[a] = path[a].find("gluino1000_894");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino1100_995") != string::npos){
      if(debug) cout<<"gluino1100_995"<<endl;
      position[a] = path[a].find("gluino1100_995");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino1200_1095") != string::npos){
      if(debug) cout<<"gluino1200_1095"<<endl;
      position[a] = path[a].find("gluino1200_1095");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino1300_1196") != string::npos){
      if(debug) cout<<"gluino1300_1196"<<endl;
      position[a] = path[a].find("gluino1300_1196");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino1400_1296") != string::npos){
      if(debug) cout<<"gluino1400_1296"<<endl;
      position[a] = path[a].find("gluino1400_1296");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    if (path[a].find("gluino1500_1396") != string::npos){
      if(debug) cout<<"gluino1500_1396"<<endl;
      position[a] = path[a].find("gluino1500_1396");
      start_position[a] = path[a].find("_",position[a]+10); //for gluino600_200, gluino600_200
    }
    end_position[a] = path[a].find("_",start_position[a]+1);
    if(debug) cout<<"position of first _ is: "<<start_position[a]<<", position of second _ is: "<<end_position[a]<<endl;
    n[a] = end_position[a]-start_position[a]-1;
    if(debug) cout<<"size of job number is: "<<n[a]<<endl;
    job_number[a] = path[a].substr(start_position[a]+1,n[a]);
    if(debug) cout<<"job_number is: "<<job_number[a]<<endl;
  }

  //check that don't have two files with same job number
  //bool some_duplicate_jobs = false;
  cout<<endl<<"----------------------------------------- Duplicate jobs ------------------------------------------"<<endl;
  for (int a=0; a<Nfiles; a++) {
    for (int b=a+1; b<Nfiles; b++) {
      if (job_number[a]==job_number[b]){
	//some_duplicate_jobs = true;
	cout<<"1st file is: "<<path[a]<<" "<<size[a]<<endl;
	cout<<"2nd file is: "<<path[b]<<" "<<size[b]<<endl<<endl;
      }
    }
  }
  cout<<"------------------------------------------------------------------------------------------------------"<<endl<<endl;

    
  //get an array of strings of all the possible job numbers
  int numbers[total_number_jobs];
  ostringstream convert[total_number_jobs];
  string numbers_string[total_number_jobs];
  for (int a=0; a<total_number_jobs; a++) {
    numbers[a]=a+1;
    convert[a]<<numbers[a];
    numbers_string[a] = convert[a].str();
    if(debug) cout<<"numbers_string is: "<<numbers_string[a]<<endl;
  }
  
  //check whether each string of possible job numbers corresponds to a file with that job number
  bool job_exists[total_number_jobs];
  for (int a=0; a<total_number_jobs; a++) job_exists[a] = false;
  
  for (int a=0; a<total_number_jobs; a++) {
    for (int b=0; b<Nfiles; b++) {
      if(numbers_string[a]==job_number[b]){
	if(debug) cout<<"job_number "<<job_number[b]<<" exists!"<<endl;
	job_exists[a] = true;
      }
    }
  }

  //print out which jobs haven't finished, and how many there are
  int count_unfinished_jobs = 0;
  cout<<"jobs: ";
  for (int a=0; a<total_number_jobs; a++) {
    if (!job_exists[a]){
      cout<<numbers_string[a]<<",";
      count_unfinished_jobs++;
    }
  }
  cout<<" do not yet exist"<<endl;
  cout<<endl<<"There are "<<count_unfinished_jobs<<" unfinished jobs"<<endl;
 
}
