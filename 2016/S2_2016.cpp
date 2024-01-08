#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Tandem Bicycle
//implementation + greedy algorithms

int main() {
  int question, n, total = 0;
  vector<int> dmoj, peg;

  cin >> question;
  cin >> n;

  int store;
  for(int i = 0; i < n; i++){
    cin >> store; 
    dmoj.push_back(store);
  }

  for(int i = 0; i < n; i++){
    cin >> store;
    peg.push_back(store);
  }

  sort(dmoj.begin(), dmoj.end());
  sort(peg.begin(), peg.end());

  if(question == 1){
    for(int i = 0; i < n; i++){
      total += max(dmoj[i], peg[i]);
    }
    
  }else{
    for(int i = 0; i < n; i++){
      total += max(dmoj[i], peg[n-i-1]);
    }
  }
  
  cout << total << endl;
  
  return 0;
  
}

