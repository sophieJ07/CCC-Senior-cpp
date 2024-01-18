#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Palindrome
//Dynamic Programming

//LCS DP simplified with two rows

int dp[2][5001]; 

int main(){
  int n; 
  cin >> n; 
  string s; 
  cin >> s;

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(s[i-1] == s[n-j] || i-1 == n-j) dp[i%2][j] = dp[1 - i%2][j-1] + 1;
      else dp[i%2][j] = max(dp[1 - i%2][j], dp[i%2][j-1]);
    }
  }

  cout << n - dp[n%2][n] << endl;
}