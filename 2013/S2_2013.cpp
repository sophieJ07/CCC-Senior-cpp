#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Bridge Transport
//math + implementation

int main() {
  int maxWeight, n, cars[100000], t = 0;
  cin >> maxWeight >> n;

  int w;
  for(int i = 0; i < n; i++){
    cin >> w;
    cars[i] = w;
  }

  int current = 0;
  for(int i = 0; i < 4 && i < n; i++){
    current += cars[i];
    if(current > maxWeight) break;
    t++;
    
  }

  if(t < 4) cout << t << endl;
  else{
    for(int i = 4; i < n; i++){
    //rolling window to keep track of current weight
      current -= cars[i-4]; 
      current += cars[i];
      if(current > maxWeight) break;
      t++;
    }
    cout << t << endl;
  }
  
  return 0;
  
}

