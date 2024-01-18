#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Gates
//Data structure 
//find appropriate gate with binary search, update available gates

int main() {
  int g, p; 
  cin >> g >> p;
  vector<int> gates; 

  int parked = 0; 
  for(int i = 1; i <= g; i++){
    gates.push_back(i); 
  }

  int plane; 
  for(int i = 0; i < p; i++){
    cin >> plane; 
    int l = 0, h = gates.size() - 1, parkedGate = -1;
    while(l <= h){
      int mid = (l + h)/2;
      int gate = gates[mid];
      if(gate == plane){
        parkedGate = mid; 
        break; 
      }else if(gate < plane){
        parkedGate = mid; 
        l = mid + 1; 
      }else h = mid - 1; 
    }

    if(parkedGate != -1){
      parked++;
      gates.erase(gates.begin() + parkedGate);
    }else break;
  }

  cout << parked << endl;

}