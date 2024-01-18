#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//https://cses.fi/problemset/task/1675

int n, m;
int parents[100001];
int ranks[100001];

int findParent(int node){
  if(parents[node] == node) return node;
  return parents[node] = findParent(parents[node]);
}

//unions sets considering ranks 
void unionSets(int a, int b){
  int parentA = findParent(a);
  int parentB = findParent(b);

  if(ranks[parentA] > ranks[parentB]){
    parents[parentB] = parentA;
  }else if(ranks[parentA] < ranks[parentB]){
    parents[parentA] = parentB;
  }else{
    parents[parentA] = parentB;
    ranks[parentB]++;
  }
}

int main(){
  cin >> n >> m;

  //set up roads for kruskal's algorithm
  priority_queue<tuple<int, int, int>> roads; 
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    roads.push(make_tuple(c*-1, a, b));
  }

  //setting up sets for DSU
  for(int i = 0; i < n; i++){
    parents[i] = i;
    ranks[i] = 0;
  }
  
  //running kruskal's algorithm
  int ans = 0, selected = 0; 
  while(!roads.empty()){
    if(selected == n-1) break; 
    tuple<int, int, int> r = roads.top();
    roads.pop();

    //check for loop
    if(findParent(get<1>(r)) != (findParent(get<2>(r)))){
      selected++;
      ans -= get<0>(r);
      unionSets(get<1>(r), get<2>(r));
    }
  }

  if(selected != n-1) cout << "IMPOSSIBLE" << endl;
  else cout << ans << endl;
    
}