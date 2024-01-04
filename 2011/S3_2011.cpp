#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Alice Through the Looking Glass
//recursion 
//recursively find height at x given m, compare height to y to determine whether the grid position is filled

int getHeight(int m, int x){
  if(m==0)
    return 0;
  int h = pow(5, m-1);
  int col = x / h;
  if(col == 0 || col == 4) return 0;
  else if(col == 1 || col == 3) return h + getHeight(m-1, x % h);
  else return 2 * h + getHeight(m-1, x % h);
}

int main(){
  int t; 
  cin >> t;

  for(int i = 0; i < t; i++){
    int m, x, y;
    cin >> m >> x >> y;

    int height = getHeight(m, x);
    if(height > y) cout << "crystal" << endl;
    else cout << "empty" << endl;
  }
}