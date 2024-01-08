#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Crazy Fencing
//math

int main() {
  double n, h[10001], w[10000], total = 0;
  cin >> n;

  for(int i = 0; i <= n; i ++){
    cin >> h[i];
  }

  for(int i = 0; i < n; i ++){
    cin >> w[i];
  }

  for(int i = 0; i < n; i++){
    if(h[i] > h[i+1]){
      total += h[i+1] * w[i] + (h[i] - h[i+1]) * w[i] / 2.0;
    } else{
      total += h[i] * w[i] + (h[i+1] - h[i]) * w[i] / 2.0;
    }
  }

  cout << fixed << total << endl;
  
  return 0;
  
}