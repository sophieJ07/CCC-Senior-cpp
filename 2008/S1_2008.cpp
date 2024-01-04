#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//It's Cold Here!
//implementation

int main(){
  string minCity = " ", city = " ";
  int minTemp = INT_MAX, temp;

  for(int i = 0; city != "Waterloo"; i++){
    cin >> city >> temp;
    if(temp < minTemp){
      minCity = city;
      minTemp = temp;
    }
}

  cout << minCity << endl;
  
  return 0;
}