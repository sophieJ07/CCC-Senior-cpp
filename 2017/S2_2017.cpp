#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//High Tide, Low Tide
//implementation 

int main() {
    
    int n;
  vector<int> tides;
  cin >> n;
  
  int store;
  for(int i = 0; i < n ;i++){
    cin >> store; 
    tides.push_back(store);
  }

  sort(tides.begin(), tides.end());

  int half = n%2 == 0 ? n/2 : n/2+1;

  for(int i = 0; i < half; i++){
    cout << tides[half - i - 1] << " ";
    if(half + i != n) cout << tides[half + i] << " ";
  }

  cout << endl;

    return 0;
}