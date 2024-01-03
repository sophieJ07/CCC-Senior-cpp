#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//The Students' Council Breakfast
//implementation

int main() {
  int pink, green, red, orange, total, comb = 0;
  cin >> pink >> green >> red >> orange >> total;

  int min = total / pink;

  for(int p = 0; p <= total/pink; p++){
    for(int g = 0; g <= total/green; g++){
      for(int r = 0; r <= total/red; r++){
        for(int o = 0; o <= total/orange; o++){
          if(p*pink + g*green + r*red + o*orange == total){
            comb++;
            cout << "# of PINK is " << p << " # of GREEN is " << g << " # of RED is " << r << " # of ORANGE is " << o << endl;

            if((p + g + r + o) < min) min = p + g + r + o;
            
          }
        }
      }
    }
  }

  cout << "Total combinations is " << comb << "." << endl;
  cout << "Minimum number of tickets to print is " << min << "." << endl;
  
  return 0;
}