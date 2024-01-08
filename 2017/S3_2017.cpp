#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Nailed It!
//implementation + math
//loop through height probabilities and check for length 

int boardsCountOrig[2001]; 

int findLength(int height){
  int boardsCount[2001];
  memcpy(boardsCount, boardsCountOrig, sizeof(boardsCount));
  
  int a = max(1, height-2000), b = height-a, length = 0;

  while(a <= height/2){
    int poss = 0;
    if(a == b){
      poss = boardsCount[a]/2;
      boardsCount[a] -= poss*2;
    }else{
      poss = min(boardsCount[a], boardsCount[b]);
      boardsCount[a] -= poss;
      boardsCount[b] -= poss;
    }

    length += poss; 
    a++;
    b--;
  }

  return length;
}

int main() {
  int n; 
  cin >> n;

  int store;
  for(int i = 0; i < n; i++){
    cin >> store; 
    boardsCountOrig[store]++;
  }

  int maxLength = 0, heightPoss = 0; 
  for(int i = 2; i <= 4000; i++){
    int length = findLength(i);
    if(length > maxLength){
      maxLength = length; 
      heightPoss = 1; 
    }else if (length == maxLength){
      heightPoss++;
    }
  }

  cout << maxLength << " " << heightPoss << endl;
  
}
