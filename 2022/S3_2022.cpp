#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Good Samples
// Constructive, Greedy Algorithms

int main(){
  long long int length, high, sampleNum;
  cin >> length >> high >> sampleNum; 

  long long int arr[length];
  long long int filledIndex = 0;
  for(long long int i = 0; i < high; i++){
    if((sampleNum - i) >= (length - i)){  
      arr[i] = i + 1; 
      sampleNum -= i + 1; 
      filledIndex++;
    }else break;
  }
  
  for(long long int i = filledIndex; i < length; i++){
    long long int neededSample = sampleNum - (length - i - 1);
    neededSample = min(filledIndex, neededSample);
    arr[i] = arr[i - neededSample];
    sampleNum -= neededSample;
  }

  if(sampleNum != 0) cout << -1 << endl;
  else{
    for(int i = 0; i < length; i++){
      cout << arr[i] << " ";
    }
  }
  cout << endl; 
}