#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Snow Calls
//implementation

int main() {
    int n;
  cin >> n;

  char orig[41];
  for(int i = 0; i < n; i++){
    cin >> orig;
    
    vector<char> line;
    int j = 0;
    while(line.size() < 12){
      if(line.size() == 3 || line.size() == 7) line.push_back('-');
      if(isdigit(orig[j])) line.push_back(orig[j]);
      else{
        if(orig[j] >= 'A' && orig[j] <= 'C') line.push_back('2');
        if(orig[j] >= 'D' && orig[j] <= 'F') line.push_back('3');
        if(orig[j] >= 'G' && orig[j] <= 'I') line.push_back('4');
        if(orig[j] >= 'J' && orig[j] <= 'L') line.push_back('5');
        if(orig[j] >= 'M' && orig[j] <= 'O') line.push_back('6');
        if(orig[j] >= 'P' && orig[j] <= 'S') line.push_back('7');
        if(orig[j] >= 'T' && orig[j] <= 'V') line.push_back('8');
        if(orig[j] >= 'W' && orig[j] <= 'Z') line.push_back('9');
      }
      j++;
    }

    for(int k = 0; k < 12; k++){
      cout << line[k];
    }
    cout << endl;
  }
    return 0;
}
