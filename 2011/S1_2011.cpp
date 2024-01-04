#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//English or French?
//string algorithm + implementation 

int main() {
int n, english = 0, french = 0;
  cin >> n;
  string line;

  for(int i = 0; i <= n; i++){
    getline(cin, line);

    for(int j = 0; line[j]; j++){
      if(line[j] == 's' || line[j] == 'S') french++;
      if(line[j] == 't' || line[j] == 'T') english ++;
    }

  }
  
  if(english > french) cout << "English \n";
  else cout << "French \n";
  
    return 0;
}