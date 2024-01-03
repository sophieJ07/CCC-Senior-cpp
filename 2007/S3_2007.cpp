#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Friends
//graph theory

bool visited[10000];

void fill(){
  for(int i = 0; i < 10000; i++){
    visited[i] = false;
  }
}

int main() {
  int n, friends[10000];
  cin >> n;

  int x, y;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    friends[x] = y;
  }
  
  cin >> x >> y;
  fill();
  
  while(x != 0 && y != 0){
    
    int seperation = -1;
    while(x != y && !visited[x]){
      visited[x] = true;
      x = friends[x];
      seperation++;
    }
    
    if(x == y) cout << "Yes " << seperation << endl;
    else cout << "No" << endl;

    fill();
    cin >> x >> y;
  }
  
}
