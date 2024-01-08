#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Symmetric Mountains
//implementation

int main() {
  vector<int> mountains;
  vector<int> minValues;
  minValues.push_back(0);
  
  int n; 
  cin >> n;
  
  int store;
  for(int i = 0; i < n; i++){
    cin >> store;
    mountains.push_back(store);
    minValues.push_back(INT_MAX);
  }

  for(int i = 0; i < n; i++){
    
    int value = 0, left = i - 1, right = i + 1;
    while(left >= 0 && right < n){
      value += abs(mountains[left] - mountains[right]);
      if(value < minValues[right - left + 1]) minValues[right - left + 1] = value;
      left--;
      right++;
    }

    if(i + 1 < n){
      int evenValue = abs(mountains[i] - mountains[i + 1]);
      if(evenValue < minValues[2]) minValues[2] = evenValue; 
      left = i - 1;
      right = i + 2;
      while(left >= 0 && right < n){
        evenValue += abs(mountains[left] - mountains[right]);
        if(evenValue < minValues[right - left + 1]) minValues[right - left + 1] = evenValue;
        left--;
        right++;
      }
    }
    
  }

  minValues[1] = 0;
  for(int i = 1; i <= n; i++){
    cout << minValues[i] << " ";
  }
  cout << endl;
  
}