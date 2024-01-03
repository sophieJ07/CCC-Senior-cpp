#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Federal Voting Age
//math + implementation

int main(){
  int n, year, month, day;
  cin >> n;
  
  for(int i = 0; i < n; i++){
    cin >> year >> month >> day;
    if((year > 1989) || (year == 1989 && month > 2) || (year == 1989 && month == 2 && day > 27)) cout << "No \n";
    else cout << "Yes \n";
  }
  
  return 0; 
}