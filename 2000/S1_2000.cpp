#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Slot Machines
//simulation

int main() {
    int quarters, m1, m2, m3, rounds = 0;
  cin >> quarters >> m1 >> m2 >> m3;

  while(quarters > 0){
    rounds++;
    m1++;
    quarters--;
    if(m1 == 35){
      quarters += 30;
      m1 = 0;
    }
    if(quarters == 0) break;

    rounds++;
    m2++;
    quarters--;
    if(m2 == 100){
      quarters += 60;
      m2 = 0;
    }
    if(quarters == 0) break;

    rounds++;
    m3++;
    quarters--;
    if(m3 == 10){
      quarters += 9;
      m3 = 0;
    }
    
  }

  cout << "Martha plays " << rounds << " times before going broke." << endl;
    
    return 0;
}
