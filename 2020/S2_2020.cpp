#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Escape Room
//graph theory

map<int, vector<pair<int, int>>>jumps; 
int room[1001][1001];
bool visited[1001][1001];
int r, c; 

bool recur(int row, int col){
//DFS
  if(row == r && col == c) return true; 
  if(visited[row][col]) return false;
  visited[row][col] = true; 
  
  int num = room[row][col];
  if (jumps.find(num) != jumps.end()) {
    for (int i = 0; i < jumps[num].size(); i++) {
      if (recur(jumps[num][i].first, jumps[num][i].second)) return true;
    }
  }

  return false;
}

int main() {
  cin >> r >> c;
  int store, num;
  
  for(int i = 1; i <= r; i++){
    for(int j = 1; j <= c; j++){
      cin >> store;
      room[i][j] = store; 
      visited[i][j] = false; 
      num = i * j;
      pair<int, int> indexes = make_pair(i, j);
      
      if(jumps.find(num) != jumps.end()) jumps[num].push_back(indexes);
      else{
        vector<pair<int, int>> v;
        v.push_back(indexes);
        jumps[num] = v; 
      }
    }
  }

  if(recur(1, 1)) cout << "yes" << endl;
  else cout << "no" << endl;
}



