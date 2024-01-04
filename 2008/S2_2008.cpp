#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Pennies in the Ring
//geometry 

int main() {
  int r = 0; 
  cin >> r;

  while(r != 0){
    int pennies = 0;
    for(int i = 1; i <= r; i++){
      for(int j = 0; j <= r; j++){
        if((i * i + j * j) <= r * r) pennies++;
        else break;
      }
    }
    cout << pennies * 4 + 1 << endl;
    cin >> r;
  }
  
  return 0;
}