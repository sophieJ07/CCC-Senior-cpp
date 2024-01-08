#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Sunflowers
//implementation 

int main(){
  int n;
  cin >> n;

  int table[100][100];
  int min = INT_MAX, store;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> store;
      table[i][j] = store;
      if(store < min) min = store;
    }
  }

  if(min == table[0][0]){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << table[i][j] << " ";
      }
      cout << endl;
    }
  }else if(min == table[0][n-1]){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << table[j][n-1-i] << " ";
      }
      cout << endl;
    }
  }else if(min == table[n-1][0]){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << table[n-1-j][i] << " ";
      }
      cout << endl;
    }
  }else{
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << table[n-1-i][n-1-j] << " ";
      }
      cout << endl;
    }
  }

    return 0;
}