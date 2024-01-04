#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Lights Going On and Off
//implementation 
//use binary numbers to indicated state of rows

int main() {
  int r, c;
  int orig[30];
  cin >> r >> c;
  int store;
  for(int i = 0; i < r; i++){
    int biNum = 0; 
    for(int j = 0; j < c; j++){
      cin >> store;
      biNum += store * pow(2, c - j - 1); 
    }
    orig[i] = biNum;
  }

  set<int> previousRow;
  previousRow.insert(orig[0]); 
  set<int> currentRow;

  for(int i = 1; i < r; i++){
    currentRow.insert(orig[i]);
    for(auto j : previousRow){
      currentRow.insert(orig[i] ^ j);
    }
    previousRow = currentRow;
    currentRow.clear();
  }
  
  cout << previousRow.size() << endl; 
}
