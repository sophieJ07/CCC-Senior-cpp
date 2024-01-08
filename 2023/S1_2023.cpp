#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Trianglane
//implementation 

int main() {
  int c, total = 0; 
  cin >> c; 

  bool isPainted[2][200000]; 
  int store;
  for(int i = 0; i < c; i++){
    cin >> store;
    isPainted[0][i] = (store == 1);
  }

  for(int i = 0; i < c; i++){
    cin >> store;
    isPainted[1][i] = (store == 1);
  }

  for(int i = 0; i < c; i++){
    if(isPainted[0][i]){
      total+=3;
      if(i!=0 && isPainted[0][i-1]) total--;
      if(i!=c-1 && isPainted[0][i+1]) total--;
      if(i%2 == 0 && isPainted[1][i]) total--;
    }
    
  }

  for(int i = 0; i < c; i++){
    if(isPainted[1][i]){
      total+=3;
      if(i!=0 && isPainted[1][i-1]) total--;
      if(i!=c-1 && isPainted[1][i+1]) total--;
      if(i%2 == 0 && isPainted[0][i]) total--;
    }
    
  }

  cout << total << endl;
  
  return 0;
}
