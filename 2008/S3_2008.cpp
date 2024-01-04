#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Maze
//graph theory
//Run BFS, different scenerios at different intersections 

int r, c; 
char grid[20][20];
int intersections[20][20]; 
bool visited[20][20];
int minInter = -1;

int main(){
  int t; 
  cin >> t;

  for(int i = 0; i < t; i++){
    cin >> r >> c;
    char store[21];
    for(int j = 0; j < r; j++){
      cin >> store;
      for(int k = 0; k < c; k++){
        grid[j][k] = store[k];
      }
    }

    memset(intersections, 0 , sizeof(intersections));
    memset(visited, false, sizeof(visited));
  
    queue<pair<int,int>> q; 
    q.push(make_pair(0, 0));
    intersections[0][0] = 1; 
    visited[0][0] = true;

    while(!q.empty()){
      pair<int, int> p = q.front();
      q.pop(); 
      
      if(p.first == r - 1 && p.second == c - 1){
        minInter = intersections[p.first][p.second];
        break;
      }
      
      int add = intersections[p.first][p.second] + 1; 
      
      if(grid[p.first][p.second] == '+' || grid[p.first][p.second] == '|'){
        if(p.first > 0 && !visited[p.first - 1][p.second] && grid[p.first - 1][p.second] != '*'){
          q.push(make_pair(p.first - 1, p.second));
          intersections[p.first - 1][p.second] = add; 
          visited[p.first - 1][p.second] = true;
        }
        if(p.first < r - 1 && !visited[p.first + 1][p.second] && grid[p.first + 1][p.second] != '*'){
          q.push(make_pair(p.first + 1, p.second));
          intersections[p.first + 1][p.second] = add; 
          visited[p.first + 1][p.second] = true;
        }
      }
      
      if(grid[p.first][p.second] == '+' || grid[p.first][p.second] == '-'){
        if(p.second > 0 && !visited[p.first][p.second - 1] && grid[p.first][p.second - 1] != '*'){
          q.push(make_pair(p.first, p.second - 1));
          intersections[p.first][p.second - 1] = add; 
          visited[p.first][p.second - 1] = true;
        }
        if(p.second < c - 1 && !visited[p.first][p.second + 1] && grid[p.first][p.second + 1] != '*'){
          q.push(make_pair(p.first, p.second + 1));
          intersections[p.first][p.second + 1] = add; 
          visited[p.first][p.second + 1] = true;
        }
      }
      
    }
    cout << minInter << endl; 
    minInter = -1;
  }
}
