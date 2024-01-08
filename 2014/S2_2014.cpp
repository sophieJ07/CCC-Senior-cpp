#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Assigning Partners
//implementation

int findIndex(string line[], string name, int n){
  int index = 0;
  while(index < n){
    if(line[index] == name) return index;
    index++;
  }
  return -1;
}

int main(){
  int n;
  cin >> n;

  string first[30], second[30];
  string name;
  for(int i = 0; i < n; i++){
    cin >> name;
    first[i] = name;
  }
  for(int i = 0; i < n; i++){
    cin >> name;
    second[i] = name; 
  }

  string print = "good";
  for(int i = 0; i < n; i++){
    int check = findIndex(second, first[i], n);
    if(check == -1 || second[i] != first[check] || check == i){
      print = "bad";
      break;
    }
  }  

  cout << print << endl;
  
  return 0;
}