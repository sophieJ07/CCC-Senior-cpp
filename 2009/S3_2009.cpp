#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Degrees Of Separation
//graph theory
//use adjacency lists
//for s, run BFS and update degree of seperation as "friends" are added to the queue

vector<vector<int>> friends (51); 

void i (int x, int y){ 
  if(find(friends[x].begin(), friends[x].end(), y) == friends[x].end()){
    friends[x].push_back(y);
    friends[y].push_back(x);
  }
}

void d (int x, int y){
  friends[x].erase(find(friends[x].begin(), friends[x].end(), y));
  friends[y].erase(find(friends[y].begin(), friends[y].end(), x));
}

void n (int x){  
  cout << friends[x].size() << endl;
}

void f (int x){
  int count = 0; 
  vector<int> fof;
  
  for(int i = 0; i < friends[x].size(); i++){
    for(int j = 0; j < friends[friends[x][i]].size(); j++){
      int checking = friends[friends[x][i]][j]; 
      
      if(checking != x && find(fof.begin(), fof.end(), checking) == fof.end() && find(friends[x].begin(), friends[x].end(), checking) == friends[x].end()){
        count++;
        fof.push_back(friends[friends[x][i]][j]);
      }
    }
  }
  cout << count << endl; 
} 

void s (int x, int y){
  bool visited[51]; 
  memset(visited, false, sizeof(visited));
  int degrees[51];
  degrees[x] = 0;
  visited[x] = true;

  queue<int> q;
  q.push(x);
  while(!q.empty()){
    int f = q.front();
    q.pop();

    for(int i = 0; i < friends[f].size(); i++){
      if(friends[f][i] == y){
        cout << degrees[f] + 1 << endl;
        return; 
      }
      
      if(!visited[friends[f][i]]){
        q.push(friends[f][i]);
        visited[friends[f][i]] = true;
        degrees[friends[f][i]] = degrees[f] + 1;
      }
    }
  }
  cout << "Not connected" << endl;
  
}

int main(){
  friends = {
    {0},
    {6},
    {6}, 
    {4, 5, 6, 15},
    {3, 5, 6}, 
    {3, 4, 6},
    {1, 2, 3, 4, 5, 7}, 
    {6, 8},
    {7, 9},
    {8, 10, 12},
    {9, 11}, 
    {10, 12}, 
    {9, 11, 13}, 
    {12, 14, 15},
    {13}, 
    {3, 13}, 
    {17, 18}, 
    {15, 18}, 
    {16, 17}
  };

  
  char ins; 
  cin >> ins; 

  while(ins != 'q'){
    int x, y; 
    cin >> x; 
    
    if(ins == 'i'){
      cin >> y;
      i(x, y);
    }else if(ins == 'd'){
      cin >> y;
      d(x, y);
    }else if(ins == 'n') n(x);
    else if(ins == 'f') f(x);
    else {
      cin >> y;
      s(x, y);
    }
    cin >> ins; 
  }
  
}
