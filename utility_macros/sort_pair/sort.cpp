#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

struct myclass{
  bool operator()(float i,float j) { return (i>j);}
};

bool myfunction (float i,float j) { return (i>j); }

int main(){

  std::pair<float, int> a;
  std::pair<float, int> b;
  std::pair<float, int> c;

  a.first = 36.4; a.second = 0;
  b.first = 83.2; b.second = 1;
  c.first = 12.4; c.second = 2;

  std::vector< std::pair<float, int> > trackPt;

  trackPt.push_back(a);
  trackPt.push_back(b);
  trackPt.push_back(c);

  cout << trackPt.size() << endl;

  std::sort(trackPt.begin(), trackPt.end());

  for (int t = 0; t < trackPt.size(); t++ ){
    cout << trackPt[t].first << ", " << trackPt[t].second << endl;    
  }

  for (int k = trackPt.size()-1; k >= 0 ; k-- ){
    cout << "New pt : " << trackPt[k].first << endl;    
  }


}
