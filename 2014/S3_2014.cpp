#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//The Geneva Confection
//implementation
//use of stack

int main() {
  int tests; 
  cin >> tests; 

  for(int i = 0; i < tests; i++){ 
    int n, store;
    cin >> n; 
    stack<int> top;
    for(int j = 0; j < n; j++){
      cin >> store;
      top.push(store); 
    }

    stack<int> branch; 
    int target = 1; 
    bool yum = true; 
    while(target <= n){
      if(!top.empty() && top.top() == target){
        top.pop();
        target++; 
      }else if(!branch.empty() && branch.top() == target){
        branch.pop();
        target++;
      }else if(!top.empty()){
        branch.push(top.top());
        top.pop();
        if(top.empty()){
          yum = false;
          break;
        }
      }else{
        yum = false;
        break;
      }
    }
    
    if(yum) cout << "Y" << endl;
    else cout << "N" << endl;
  }
  
}