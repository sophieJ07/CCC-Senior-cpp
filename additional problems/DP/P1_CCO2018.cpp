#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Geese vs. Hawks
//Dynamic Programming

//dp[i][j] stores the maximum score achievable by selecting a sequence of scores from the beginning up to the i-th Goose and the j-th Hawk
long long int dp[1000][1000];

int main(){
  int n;
  string g, h;
  cin >> n >> g; 
  
  long long int gScore[1000], hScore[1000];
  for(int i = 0; i < n; i++){
    cin >> gScore[i];
  }
  cin >> h;
  for(int i = 0; i < n; i++){
    cin >> hScore[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
    //check if condition is met
      if(g[i] != h[j] && ((g[i] == 'W' && gScore[i] > hScore[j]) || (h[j] == 'W' && gScore[i] < hScore[j]))){
        if(i != 0 && j != 0){
          dp[i][j] = gScore[i] + hScore[j] + dp[i-1][j-1]; //update dp
          if(dp[i][j] < max(dp[i-1][j], dp[i][j-1])) dp[i][j] = max(dp[i-1][j], dp[i][j-1]); //select optimal option
        }else if (i == 0 && j > 0) dp[i][j] = max(gScore[i] + hScore[j], dp[i][j-1]); 
        else if(i > 0 && j == 0) dp[i][j] = max(gScore[i] + hScore[j], dp[i-1][j]);
        else dp[i][j] = gScore[i] + hScore[j]; 
      }else{
        //if the current scores does not meet the condition, forward previous dp values
        if(i != 0 && j != 0) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        else if (i == 0) dp[i][j] = dp[i][j-1];
        else if (j == 0) dp[i][j] = dp[i-1][j];
        else dp[i][j] = 0;
      }
    }
  }
  
  cout << dp[n-1][n-1] << endl;
  
}