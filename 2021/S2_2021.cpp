#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Modern Art
//implementation

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> r(n+1, false), c(m+1, false);
  
  string store;
  int num;
  for(int i = 0; i < k; i++){
    cin >> store >> num;
    if(store == "R") r[num] = !r[num];
    else c[num] = !c[num];
  }


  int row = 0, col = 0;
  for(int i = 0; i <= n; i++){
    if(r[i]) row++;
  }

  for(int i = 0; i <= m; i++){
    if(c[i]) col++;
  }

  int t = row*m + col*n - 2*row*col;
  cout << t <<endl;
  
  return 0;
  
}