#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Babbling Brooks
//simulation

int n; 
vector<int> streams;

void split(int s, int p){
  int orig = streams[s-1];
  streams.insert(streams.begin() + s - 1, orig*p/100);
  streams.insert(streams.begin() + s, orig-streams[s-1]);
  streams.erase(streams.begin() + s + 1);
}

void merge(int s){
  int total = streams[s-1] + streams[s];

  streams.insert(streams.begin() + s - 1, total);
  streams.erase(streams.begin() + s);
  streams.erase(streams.begin() + s);
}

int main() {
  cin >> n;

  int store;
  for(int i = 0; i < n; i++){
    cin >> store;
    streams.push_back(store);
  }

  cin >> store;
  while(store != 77){
    if(store == 99){
      int s, p;
      cin >> s >> p;
      split(s, p);
    }
    else if (store == 88){
      int s;
      cin >> s;
      merge(s);
    }
    cin >> store;
  }
  

  for(int i = 0; i < streams.size(); i++){
    cout << streams[i] << " ";
  }

  cout << endl;
  return 0;
  
}
