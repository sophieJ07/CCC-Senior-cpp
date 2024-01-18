#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Shop and Ship
//graph theory 
//classic Dijkstras 

int n, t;
int routes[5001][5001], costs[5001];
bool marked[5001];

int minDistance(){
  int min = INT_MAX, ret = -1;
  for(int i = 1; i <= n; i++){
    if(!marked[i] && costs[i] <= min){
      min = costs[i];
      ret = i; 
    }
  }
  return ret;
}

void findCosts(int source){
  for(int i = 1; i <= n; i++){
    costs[i] = INT_MAX;
  }

  costs[source] = 0; 
  for(int i = 0; i < n-1; i++){
    int current = minDistance(); 
    marked[current] = true; 
    if(costs[current] == INT_MAX) break; 
    
    for(int j = 1; j <= n; j++){
      if(!marked[j] && routes[current][j] && (costs[current] + routes[current][j]) < costs[j]) 
        costs[j] = costs[current] + routes[current][j];
    }
  }
}


int main(){
  scanf("%d%d",&n,&t);
  
  for(int i = 0; i < t; i++){
    int a, b;
    scanf("%d%d",&a,&b);

    scanf("%d",&routes[a][b]);
    routes[b][a] = routes[a][b];
  }

  int k; 
  scanf("%d",&k);
  vector<int> penCost(n+1, INT_MAX); 
  for(int i = 0; i < k; i++){
    int a; 

    scanf("%d",&a);
    scanf("%d",&penCost[a]);
  }

  int d; 

  scanf("%d",&d);
  
  findCosts(d);


  for(int i = 1; i <= n; i++){
    if(penCost[i] != INT_MAX){
      costs[i] += penCost[i];
    }
  }

  int minCost = INT_MAX;
  for(int i = 1; i <= n; i++){
    if(penCost[i] != INT_MAX && costs[i] < minCost ) minCost = costs[i]; 
  }
  
  printf("%d\n",minCost);
  
}