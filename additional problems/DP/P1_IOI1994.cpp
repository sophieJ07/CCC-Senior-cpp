#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//The Triangle
//Dynamic Programming

int n;
int tri[100][100]; 

int main(){
  cin >> n; 

  for(int i = 1; i <= n; i++){
    for(int j = 0; j < i; j++){
      int num;
      cin >> num; 
      tri[i-1][j] = num;
    }
  }

  for(int i = n-2; i >= 0; i--){
    for(int j = 0; j <= i; j++){
      tri[i][j] += max(tri[i+1][j], tri[i+1][j+1]);
    }
  }

  cout << tri[0][0] << endl;
  
}
