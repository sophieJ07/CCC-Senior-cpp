#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Surmising a Sprinter's Speed
//implementation 

int main() {
  vector <pair <double, double>> obs;
  int n;
  cin >> n;
  
  double s1, s2;
  for(int i = 0; i < n; i++){
    cin >> s1 >> s2;
    obs.push_back(make_pair(s1, s2));
  }

  sort(obs.begin(), obs.end());
  
  double maxSpeed = INT_MIN;
  for(int i = 1; i < n; i++){
    double speed = (obs[i].second - obs[i-1].second) / (obs[i].first - obs[i-1].first);
    if(abs(speed) > maxSpeed) maxSpeed = abs(speed);
  }

  cout << setprecision(5) << fixed << maxSpeed << endl;
  
  return 0;
 
}