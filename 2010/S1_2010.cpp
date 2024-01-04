#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Computer Purchase
//math + implementation

int main() {
  int n, first = 0, second = 0;
  string firstComp, secondComp;

  cin >> n;
  int score, r, s, d;
  string comp;
  for(int i = 0; i < n; i++){
    cin >> comp;
    cin >> r >> s >> d;
    score = 2*r + 3*s + d;

    if(score > first || (score == first && comp < firstComp)){
      secondComp = firstComp;
      second = first;
      firstComp = comp;
      first = score;
    } else if (score > second || (score == second && comp < secondComp)){
      secondComp = comp;
      second = score;
    }
    
  }

  if(n > 0){
    cout << firstComp << endl;
    if(n > 1) cout << secondComp << endl;
  }
  
  return 0;
}
