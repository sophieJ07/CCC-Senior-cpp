#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//TopYodeller
//implementation

int main() {
  int scores[100], ranks[100], lowestRanks[100];
  int n, rounds; 

  cin >> n >> rounds;

  for(int i = 0; i < n; i++){
    scores[i] = 0; 
    lowestRanks[i] = 1;
  }

  int store; 
  for(int i = 0; i < rounds; i++){
    for(int j = 0; j < n; j++){
      cin >> store;
      scores[j] += store; 
    }

    for(int j = 0; j < n; j++){
      int higher = 0;
      for(int k = 0; k < n; k++){
        if(scores[k] > scores[j]) higher++;
      }
      ranks[j] = higher + 1;
      if(ranks[j] > lowestRanks[j]) lowestRanks[j] = ranks[j];
    }
  }

  for(int i = 0; i < n; i++){
    if(ranks[i] == 1){
      cout << "Yodeller " << (i+1) << " is the TopYodeller: score " << scores[i] << ", worst rank " << lowestRanks[i] << endl;
    }
  }
  
  
}