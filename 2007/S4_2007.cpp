#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Waterpark
//dynamic programming + graph theory 
//start from bottom, update the number of path down from one particular point

int numPaths[10000]; 

int main(){
  int n;
  cin >> n;

  vector<vector<int>> paths(10000);
  int a, b;
  cin >> a >> b;
  while(a!= 0 && b!=0){
    paths[b].push_back(a);
    cin >> a >> b;
  }
  

  for(int i = 0; i < paths[n].size(); i++){
    numPaths[paths[n][i]] = 1;
  }

  for(int i = n-1; i >= 1; i--){
    for(int j = 0; j < paths[i].size(); j++){
      numPaths[paths[i][j]] += numPaths[i];
    }
  }

  cout << numPaths[1] << endl;
  
}
