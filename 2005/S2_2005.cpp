#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Mouse Move
//math + simulation 

int main(){
  int c, r;
  int xPos = 0, yPos = 0;
  cin >> c >> r;

  int moveX, moveY;
  cin >> moveX >> moveY;
  while(!(moveX == 0 && moveY ==0)){
    xPos += moveX;
    yPos += moveY;

    if(xPos > c) xPos = c;
    else if(xPos < 0) xPos = 0;
    if(yPos > r) yPos = r;
    else if(yPos < 0) yPos = 0;
    

    cout << xPos << " " << yPos << endl;

    cin >> moveX >> moveY;
  }
  return 0;
  
}
