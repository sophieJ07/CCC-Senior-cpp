#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//From 1987 to 2013
//implementation

bool distinct (int y){
  bool digits[10] = {false};

  while(y > 0){
    if(digits[y%10] == true) return false;
    else digits[y%10] = true;
    y /= 10;
  }
  
  return true;
}

int main() {
  int year;
  cin >> year;

  if(year >= 1987 && year < 2013) cout << 2013 << endl;
  else{
    year++;
    while(!distinct(year)){
      year++;
    }
    cout << year;
  }
  
  return 0;
}

