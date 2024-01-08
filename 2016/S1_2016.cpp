#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Ragaman
//implementation 

int main() {
  int strLetters[26] = {0} , cardLetters[26] = {0}, wild = 0;
  
  char str[101], card[101];
  cin >> str >> card;

  for(int i = 0; str[i] != '\0'; i++){
    strLetters[str[i]-'a'] ++;
    if (card[i] == '*') wild++;
    else cardLetters[card[i]-'a']++;
  }

  bool a = true;
  for(int i = 0; i < 26; i++){
    if(cardLetters[i] > strLetters[i]){
      a = false;
      break;
    }
    if (strLetters[i] - cardLetters[i] <= wild){
      wild -= (strLetters[i] - cardLetters[i]);
    } else{
      a = false; 
      break;
    }
  }

  if(a) cout << 'A' << endl;
  else cout << 'N' << endl;
  
  return 0;

}