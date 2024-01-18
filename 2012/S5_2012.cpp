#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Mouse Journey
//dynamic programming 
/*
set up a matrix, each containing the number of paths from [i, j] to [r, c]
-> start from the bottom right, fill bottom row and right columns with 1 (unless cut off by an obstacle)
-> since the mouse can only move down and right, iterate through the grid, updating each element by add [i+1, j] and [i, j+1]
*/

int main(){
  int r, c;
  cin >> r >> c; 
  bool hasCat[26][26];
  memset(hasCat, false, sizeof(hasCat));
  
  int cats; 
  cin >> cats;
  for(int i = 0; i < cats; i++){
    int a, b; 
    cin >> a >> b;
    hasCat[a][b] = true; 
  }

  int paths[26][26];
  memset(paths, 0, sizeof(paths)); 
  for(int j = c; j >= 1; j--){
    if(hasCat[r][j]) break;
    paths[r][j] = 1;
  }

  for(int i = r; i >= 1; i--){
    if(hasCat[i][c]) break;
    paths[i][c] = 1; 
  }

  for(int i = r - 1; i >= 1; i--){
    for(int j = c - 1; j >= 1; j--){
      if(!hasCat[i][j]) paths[i][j] = paths[i+1][j] + paths[i][j+1];
    }
  }
  
  cout << paths[1][1] << endl; 
}

