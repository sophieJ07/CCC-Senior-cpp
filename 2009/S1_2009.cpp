#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Cool numbers
//math 

int main() {
  int n1, n2, total = 0;
  cin >> n1 >> n2;

  for(int i = sqrt(n1); i <= sqrt(n2); i++){
    for(int j = cbrt(n1); j <= cbrt(n2); j++){
      if(pow(i,2) == pow(j,3)) total++;
      if(pow(i,2) < pow(j,3)) break;
    }
  }
  
  cout << total << endl;
  
  return 0;

}
