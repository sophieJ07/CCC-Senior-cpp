#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Jerseys
//implementation

int main(){
  int j, a;
  vector<char> sizes;
  sizes.push_back('0');
  
  cin >> j >> a;
  char store;
  for(int i = 0; i < j; i++){
    cin >> store;
    sizes.push_back(store);
  }

  int t = 0;
  char size;
  int num; 
  for(int i = 0; i < a; i++){
    cin >> size;
    cin >> num;

    if(sizes[num] != '0'){
      if(size == 'S' || sizes[num] == size || (size == 'M' && sizes[num] == 'L')){
        t++;
        sizes[num] = '0';
      }
    }
  }
  cout << t << endl;
  return 0;
  
}