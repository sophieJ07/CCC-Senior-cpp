#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Pretty Average Primes
//math 
//label prime numbers using the sieve of Eratosthenes

bool primes[3000001];

void primeList(){
  memset(primes,1,sizeof(primes));
  primes[0] = false;
  primes[1] = false;

  for(int i = 2; i*i < 3000001; i++){
    if(primes[i]){
      for(int j = i*i; j < 3000001; j+=i){
        primes[j] = false;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  primeList();
  int num;
  for(int i = 0; i < n; i++){
    cin >> num;
    for(int j = 2; j <= num; j++){
      if(primes[j] && primes[num*2-j]){
        cout << j << " " << num*2-j << endl;
        break;
      }
    }
  }
  
  return 0;
}
