#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Huffman Encoding
//implementation + string algorithm 

int main() {
  map<string, char> letter;
  int k, minLength = 20;
  cin >> k;

  char l;
  string b;
  for(int i = 0; i < k; i++){
    cin >> l >> b;
    letter[b] = l;
    if(b.length() < minLength) minLength = b.length();
  }

  string seq;
  cin >> seq;
  int index = 0;
  while(index + minLength <= seq.length()){
    int addLength = 0;
    string test = seq.substr(index, minLength);
    while(letter.find(test) == letter.end()){
      addLength++;
      test = seq.substr(index, minLength + addLength);
    }
    cout << letter[test];
    index += test.length();
  }

  cout << endl;
  
  return 0;
}
