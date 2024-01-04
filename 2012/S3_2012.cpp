#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Absolutely Acidic
//implementation

int main() {
  int n;
  cin >> n;

  map <int, int> frequency;
  int acidity;
  for(int i = 0; i < n; i++){
    cin >> acidity;
    frequency[acidity]++;
  }

  int num1 = 0, num2 = 0, maxDiff = 0; 
  for(map <int, int>::iterator i = frequency.begin(); i != frequency.end(); i++){
    if(i->second > frequency[num1] || (i->second == frequency[num1] && abs(i->first - num2) > maxDiff)){
      if(frequency[num1] > frequency[num2] || (frequency[num1] == frequency[num2] && abs(num1 - i->first) > maxDiff)) num2 = num1;
      num1 = i->first;
    }else if(i->second == frequency[num1]){
      if(i->second > frequency[num2] || (i->second == frequency[num2] && abs(i->first - num1) > maxDiff)) 
        num2 = i->first;
    }else if(i->second > frequency[num2] || (i->second == frequency[num2] && abs(i->first - num1) > maxDiff)) 
        num2 = i->first;
    
      maxDiff = abs(num1 - num2);

  }

  cout << maxDiff << endl;
  
}