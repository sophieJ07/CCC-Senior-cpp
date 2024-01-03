#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Poetry
//implementation

string lastSyllable(string str){
  
  for(int i = 0; i < str.length(); i++){
    str[i] = tolower(str[i]);
  }
  
  int lastVowel = -1; 
  int lastSpace = -1; 

  for(int i = 0; i < str.length(); i++){
    if(str[i] == ' ') lastSpace = i;
    else if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') lastVowel = i;
  }

  if(lastVowel > lastSpace) return str.substr(lastVowel, str.length() - lastVowel);
  else if(lastSpace > lastVowel) return str.substr(lastSpace + 1, str.length() - lastSpace - 1);
  else return str;
  
}

int main() {
  int n;
  cin >> n;
  

  string l1, l2, l3, l4;
  getline(cin, l1);
  for(int i = 0; i < n; i++){
    getline(cin, l1);
    getline(cin, l2);
    getline(cin, l3);
    getline(cin, l4);

    l1 = lastSyllable(l1);
    l2 = lastSyllable(l2);
    l3 = lastSyllable(l3);
    l4 = lastSyllable(l4);


    if(l1 == l2 && l1 == l3 && l1 == l4) cout << "perfect" << endl;
    else if(l1 == l2 && l3 == l4) cout << "even" << endl;
    else if(l1 == l3 && l2 == l4) cout << "cross" << endl;
    else if(l1 == l4 && l2 == l3) cout << "shell" << endl;
    else cout << "free" << endl;
  }
  
  return 0;
  
}
