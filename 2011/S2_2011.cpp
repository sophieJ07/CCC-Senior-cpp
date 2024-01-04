#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Multiple Choice
//implementation

int main() {
  int n, correct = 0;
  char key[10000];
  cin >> n;

  char store;
  for(int i = 0; i < n; i++){
    cin >> store;
    key[i] = store;
  }

  for(int i = 0; i < n; i++){
    cin >> store;
    if(store == key[i]) correct++;
  }

  cout << correct << endl;
  
  return 0; 
  
}
