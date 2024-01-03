#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Maternity
//implementation

int main() {
  bool dominant[5], recessive[5];

  char p1[11], p2[11];
  cin >> p1 >> p2;

  for(int i = 0; i < 10; i+=2){
    if((isupper(p1[i]) && isupper(p1[i+1])) || (isupper(p2[i]) && isupper(p2[i+1]))){
      dominant[i/2] = true;
      recessive[i/2] = false;
    }else if(islower(p1[i]) && islower(p1[i+1]) && islower(p2[i]) && islower(p2[i+1])){
      dominant[i/2] = false;
      recessive[i/2] = true;
    }else{
      dominant[i/2] = true;
      recessive[i/2] = true;
    }
  }

  int x;
  cin >> x;
  char child[6];
  
  for(int i = 0; i < x; i++){
    bool possible = true;
    cin >> child;
    for(int j = 0; j < 5; j++){
      if((isupper(child[j]) && !dominant[j]) || (islower(child[j]) && !recessive[j])){
        possible = false;
        break;
      }
    }
    
    if(possible) cout << "Possible baby.\n";
    else cout << "Not their baby!\n";
  }
  
  return 0;
}
