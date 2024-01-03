#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Fraction Action
//math + implementation 

int getGCD(int n1, int n2){
  int ret = 1;
  for(int i = 1; i <= n1 && i <= n2; i++){
    if(n1%i == 0 && n2%i == 0) ret = i;
  }
  return ret; 
}

int main(){
  int n, d;
  cin >> n >> d;

  int divide = getGCD(n, d);
  n /= divide;
  d /= divide;
  
  if(d == 1 || n == 0) cout << n << endl;
  else if(n > d){
    int wholeNum = n/d;
    cout << wholeNum << " " << (n-wholeNum*d) << "/" << d << endl;
  }else cout << n << "/" << d << endl;
  
 return 0;
}