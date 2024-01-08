#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Zero That Out
//implementation 
//use of stack

int main() {
  int k, current;
  cin >> k;
  stack <int> nums;

  for(int i = 0; i < k; i++){
    cin >> current; 
    if(current != 0) nums.push(current);
    else nums.pop();
  }

  int sum = 0;
  while (!nums.empty()){
    sum += nums.top();
    nums.pop();
  }

  cout << sum << endl; 
  
  return 0;
}