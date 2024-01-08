#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Good Fours and Good Fives
//implementation + math

int main() {
  int num, ans = 0;
  cin >> num;

  for(int i = 0; i <= num/5; i++){
    int check = num - i*5;
    if(check % 4 == 0 && check >= 0) ans++;
  }

  cout << ans << endl;
  
  return 0;
  
}

