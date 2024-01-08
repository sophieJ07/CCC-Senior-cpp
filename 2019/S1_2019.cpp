#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Flipper
//implementation 

int main() {
    
  char str[1000001];
  cin >> str;
  int h = 0, v = 0;

  for(int i = 0; str[i] == 'H' || str[i] == 'V'; i++){
    if(str[i] == 'H') h++;
    else v++;
  }

  h %= 2;
  v %= 2;

  if(h == 1 && v == 0){
    cout << "3 4" << endl << "1 2" << endl;
  } else if (h == 0 && v == 1){
    cout << "2 1" << endl << "4 3" << endl;
  } else if(h == 1 && v == 1){
    cout << "4 3" << endl << "2 1" << endl;
  } else cout << "1 2" << endl << "3 4" << endl;
  
    return 0;
}