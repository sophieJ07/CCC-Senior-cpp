#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//RoboThieves
//graph theory + implementation 

/*
weighted graph appoarch: treat conveyors as edges of length 0, others as edges of length 1.
1. mark off cells seen by the camera
2. run BFS with a priority queue storing (steps (sorted), row, col) 
   for conveyors: do not change step, push cell in the indicate direction
   for regular cells: change step by one, push cells in all 4 directions
*/

int n, m; 
char grid[101][101]; 
bool visited[101][101];
int steps[101][101]; 

void camera(int r, int c){
  visited[r][c] = true;
  //up
  for(int i = r-1; i >= 0; i--){
    if(grid[i][c] == '.' || grid[i][c] == 'S') visited[i][c] = true;
    if(grid[i][c] == 'W') break;
  }

  //down 
  for(int i = r+1; i < n; i++){
    if(grid[i][c] == '.' || grid[i][c] == 'S') visited[i][c] = true;
    if(grid[i][c] == 'W') break;
  }

  //left 
  for(int j = c-1; j >= 0; j--){
    if(grid[r][j] == '.'|| grid[r][j] == 'S') visited[r][j] = true;
    if(grid[r][j] == 'W') break;
  }

  //right
  for(int j = c+1; j < m; j++){
    if(grid[r][j] == '.'|| grid[r][j] == 'S') visited[r][j] = true;
    if(grid[r][j] == 'W') break;
  }
}

int main(){
  cin >> n >> m;
  pair<int, int> start;
  for(int i = 0; i < n; i++){
    cin >> grid[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'S'){
        start.first = i;
        start.second = j;
      }else if(grid[i][j] == 'C'){
        camera(i, j); 
      }else if(grid[i][j] == 'W') visited[i][j] = true;
    }
  }

  priority_queue<tuple<int,int,int>> pq;
  //priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<Triple>> pq;
  pq.push(make_tuple(0, start.first, start.second));
  while(!pq.empty()){
    auto [step, r, c] = pq.top();
    pq.pop();
    if(visited[r][c]) continue; 
    visited[r][c] = true; 

    if(grid[r][c] == '.' || grid[r][c] == 'S'){
      steps[r][c] = step * -1;
      if(!visited[r+1][c]) pq.push(make_tuple(step-1, r+1, c));
      if(!visited[r-1][c]) pq.push(make_tuple(step-1, r-1, c));
      if(!visited[r][c+1]) pq.push(make_tuple(step-1, r, c+1));
      if(!visited[r][c-1]) pq.push(make_tuple(step-1, r, c-1));  
      
    }
    if(grid[r][c] == 'U' && !visited[r-1][c]){
      pq.push(make_tuple(step, r-1, c));
    }else if(grid[r][c] == 'D' && !visited[r+1][c]){
      pq.push(make_tuple(step, r+1, c));
    }else if(grid[r][c] == 'L' && !visited[r][c-1]){
      pq.push(make_tuple(step, r, c-1));
    }else if(grid[r][c] == 'R' && !visited[r][c+1]){
      pq.push(make_tuple(step, r, c+1));
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == '.'){
        if(steps[i][j] != 0) cout << steps[i][j] << endl;
        else cout << -1 << endl;
      }
    }
  }
}