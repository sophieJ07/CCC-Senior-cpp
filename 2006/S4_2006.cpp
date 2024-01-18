#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Groups
//implementation + math

int n;
int matrix[101][101]; 
vector<int> iden;

bool checkAssociativity(){
  for(int x = 1; x <= n; x++){
    for(int y = 1; y <= n; y++){
      for(int z = 1; z <= n; z++){
        if(matrix[x][matrix[y][z]] != matrix[matrix[x][y]][z]) 
          return false;
      }
    }
  }
  return true; 
}

bool checkIdentity(){
  bool found;
  for(int i = 1; i <= n; i++){
    found = true; 
    for(int x = 1; x <= n; x++){
      if(matrix[i][x] != x || matrix[x][i] != x){
        found = false; 
        continue; 
      }
    }
    if(found){
      iden.push_back(i);
    }
  }
  
  if(iden.size() == 0) return false; 
  return true;
}

bool checkInverse(){
  for(int i : iden){
    bool idenWorks = true;
    for(int x = 1; x <= n; x++){
      bool found = false; 
      for(int e = 1; e <= n; e++){
        if(matrix[x][e] == i && matrix[e][x] == i){
          found = true;
          break;
        }
      }
      if(!found){
        idenWorks = false; 
        break;
      }
    }
    if(idenWorks) return true;
  }
  return false;
}

int main(){ 
  cin >> n; 

  while(n != 0){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        cin >> matrix[i][j];
      }
    }

    iden.clear();

    if(checkAssociativity() && checkIdentity() && checkInverse()){
      cout << "yes" << endl;
    }else cout << "no" << endl;

    cin >> n;
  }
}