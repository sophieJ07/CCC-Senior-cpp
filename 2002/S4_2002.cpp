#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Bridge Crossing
//Dynamic Programming

int m, q, bestTime = INT_MAX;
int times[101];
int passingtimes[101];
string names[101];
int groupSizes[101];

int groupTime(int start, int end){
  int max = times[start];
  for(int i = start; i <= end; i++){
    if(times[i] > max){
      max = times[i];
    }
  }
  return max; 
}

int main(){
  cin >> m >> q;

  for(int i = 0; i < q; i++){
    cin >> names[i];
    cin >> times[i]; 
  }

  //last m people
  passingtimes[q-1] = times[q-1]; 
  groupSizes[q-1] = 1;
  for(int i = q-2; i >= q-m; i--){
    passingtimes[i] = max(times[i], passingtimes[i+1]); 
    groupSizes[i] = groupSizes[i+1] + 1;
  }

  //other people 
  for(int i = q-m-1; i >= 0; i--){
    int minTime = INT_MAX;
    for(int e = i; e < i + m; e++){
      int t = groupTime(i, e) + passingtimes[e+1]; 
      if(t < minTime){
        minTime = t;
        groupSizes[i] = e - i + 1;
      }
    }
    passingtimes[i] = minTime; 
  }

  cout << "Total Time: " << passingtimes[0] << endl; 

  int index = 0; 
  while (index < q){
    int gs = groupSizes[index];
    for(int i = 0; i < gs; i++){
      cout << names[index+i] << " ";
    }
    cout << endl; 
    index += gs; 
  }

  return 0; 
}