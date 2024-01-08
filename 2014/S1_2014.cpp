#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Party Invitation 
//implementation

int main() {
    int n, round, ppl[1000], multiple;
  cin >> n >> round;
  
  for(int i = 0; i <= n; i++){
    ppl[i] = i;
  }

  for(int i = 0; i < round; i++){
    cin >> multiple;
    int count = 0; 
    for(int j = 1; j <= n; j++){
      if(ppl[j] != 0){
        if(count == multiple-1){
          ppl[j] = 0;
          count = 0;
        } else count++;
     }
    }
  }

  for(int i = 1; i <= n; i++){
    if(ppl[i] != 0) cout << ppl[i] << endl;
  }
  
    return 0;
}