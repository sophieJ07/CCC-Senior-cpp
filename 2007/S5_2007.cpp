#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bowling for Numbers
// Dynamic programming

int main(){
  int runs; 
  cin >> runs; 

  while(runs > 0){
    int n, k, w; 
    cin >> n >> k >> w;

    vector<int> pins;
    pins.push_back(0);
    for(int i = 0; i < n; i++){
      int p;
      cin >> p; 
      pins.push_back(p);
    }

    int dp[k+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= k; i++){
      int score = 0; 
      for(int j = 0; j <= n; j++){
        if(j <= w){
          score += pins[j];
          dp[i][j] = score;
        }else{
          score += pins[j] - pins[j-w]; 
          dp[i][j] = max(dp[i][j-1], dp[i-1][j-w] + score);
        }
      }
    }
    cout << dp[k][n] << endl;
    runs--;
  }


  
}
