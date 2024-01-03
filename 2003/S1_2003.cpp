#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Snakes and Ladders
//implementation

int main(){
  int current = 1, step;

  while(true){
    cin >> step;

    if(step == 0){
      cout << "You Quit! \n";
      break;
    }

    if(current + step <= 100){
      current += step;
      if (current == 9) current = 34;
      if (current == 40) current = 64;
      if (current == 67) current = 86;
      if (current == 54) current = 19;
      if (current == 90) current = 48;
      if (current == 99) current = 77;
    } 

    cout << "You are now on square " << current << endl;
    
    if(current == 100){
      cout << "You Win!";
      break;
    }
  }
  
  return 0;
}
