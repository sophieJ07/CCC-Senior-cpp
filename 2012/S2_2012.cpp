#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Aromatic Numbers
//math + implementation 

int getBase(char b){
  if(b == 'I') return 1;
  if(b == 'V') return 5;
  if(b == 'X') return 10;
  if(b == 'L') return 50;
  if(b == 'C') return 100;
  if(b == 'D') return 500;
  if(b == 'M') return 1000;
  return 0;
}

int main() {
  char number[21];
  cin >> number;
  int total = 0; 
  int previous = 1000, previousValue = 0;

  for(int i = 0; number[i] != '\0'; i+=2){
    int value = (number[i]-'0') * getBase(number[i+1]);
    total += value;
    if(getBase(number[i+1]) > previous) total -= previousValue * 2;
    
    previous = getBase(number[i+1]);
    previousValue = value;

  }

  cout << total << endl;
  
  return 0;
}
