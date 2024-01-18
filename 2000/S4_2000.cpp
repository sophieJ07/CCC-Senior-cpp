#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Golf
//dynamic programming 
//memoize 

int numClubs;
int clubs[32];
int minStrokes = -1; 
int memo[5281][5281];

void recur(int distanceLeft, int strokesMade){
  if(distanceLeft == 0){
    if(minStrokes == -1 || (minStrokes > -1 && strokesMade < minStrokes)) minStrokes = strokesMade;
    return;
  }

  if(memo[distanceLeft][strokesMade] != 0) return;
  
  for(int i = 0; i < numClubs; i++){
    if(clubs[i] > distanceLeft) break;
    recur(distanceLeft - clubs[i], strokesMade + 1);
  }

  memo[distanceLeft][strokesMade] = minStrokes;
  return;
}


int main(){
  int distance; 
  cin >> distance >> numClubs;

  int c;
  for(int i = 0; i < numClubs; i++){
    cin >> c;
    clubs[i] = c;
  }
  sort(clubs, clubs + numClubs);
  
  recur(distance, 0); 

  if(minStrokes == -1) cout << "Roberta acknowledges defeat." << endl;
  else cout << "Roberta wins in " << minStrokes << " strokes." << endl;
  
}