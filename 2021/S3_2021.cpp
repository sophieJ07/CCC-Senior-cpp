#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Lunch Concert
//implementation
/*
view c as x and the total walking time as f(x) 
-> deduce that the function could be bellshaped and that the min point can be found with binary search
*/

int n; 
long long int p[200000], w[200000], d[200000];

long long int walkingTime(long long int c){
  long long int time = 0; 
  for(int i = 0; i < n; i++){
    long long int dist =  abs(p[i] - c) - d[i];
    if(dist < 0) dist = 0;
    time += dist * w[i];
  }
  return time; 
}

int main(){
  cin >> n; 
  for(int i = 0; i < n; i++){
    cin >> p[i] >> w[i] >> d[i];
  }
  
  long long int l = 0, r = 1100000000;
  long long int finalC = -1;
  while(l <= r){
    long long int m = l + (r-l)/2;
    long long int midTime = walkingTime(m);
    long long int leftTime = walkingTime(m-1);
    long long int rightTime = walkingTime(m+1);

    if(leftTime < midTime){
      r = m-1;
    }else if(rightTime < midTime){
      l = m+1;
    }else{
      finalC = midTime;
      break;
    }
  }

  cout << finalC << endl;
  
}
