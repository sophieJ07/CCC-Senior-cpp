#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Fix
//String theory + implementation

bool isFixFree(string fix, string s1, string s2){
  if(s1.length() >= fix.length()){
    if(s1.substr(0, fix.length()) == fix) return false;
    if(s1.substr(s1.length()-fix.length(), fix.length()) == fix) return false;
  }
  if(s2.length() >= fix.length()){
    if(s2.substr(0, fix.length()) == fix) return false;
    if(s2.substr(s2.length()-fix.length(), fix.length()) == fix) return false;
  }
  
  return true;
}

int main() {
  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    string a, b, c;
    cin >> a >> b >> c;

    if(isFixFree(a, b, c) && isFixFree (b, a, c) && isFixFree(c, a, b)){
      cout << "Yes" << endl;
    } else cout << "No" << endl;
    
  }
  return 0;
}
  