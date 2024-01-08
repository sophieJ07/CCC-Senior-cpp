#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Sum Game
//implementation 

int main() {
    int n, day = 0, swp = 0, sep = 0;
  vector<int> swift, sema;
  cin >> n;

  int store;
  for(int i = 0; i < n; i++){
    cin >> store;
    swift.push_back(store);
  }

  for(int i = 0; i < n; i++){
    cin >> store;
    sema.push_back(store);
  }

  for(int i = 0; i < n; i++){
    swp += swift[i];
    sep += sema[i];

    if(swp == sep) day = i+1;
  }

  cout << day << endl;
    
    return 0;
}


