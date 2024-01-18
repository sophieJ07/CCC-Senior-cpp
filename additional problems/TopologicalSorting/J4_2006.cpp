#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//It's tough being a teen!
//Graph Theory

int indegrees[8];
vector<vector<int>> afterTasks(8); 

int main(){
  int a, b;
  cin >> a >> b;

  //setup
  indegrees[7]++;
  afterTasks[1].push_back(7);
  indegrees[4]++;
  afterTasks[1].push_back(4);
  indegrees[1]++;
  afterTasks[2].push_back(1);
  indegrees[4]++;
  afterTasks[3].push_back(4);
  indegrees[5]++;
  afterTasks[3].push_back(5);
  
  while(a!=0 && b!=0){
    indegrees[b]++;
    afterTasks[a].push_back(b);
    cin >> a >> b;
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 1; i < 8; i++){
    if(indegrees[i] == 0) pq.push(i); 
  }

  vector<int> order; 
  
  while(!pq.empty()){
    int task = pq.top(); 
    pq.pop();
    order.push_back(task);
    for(int n : afterTasks[task]){
      indegrees[n]--;
      if(indegrees[n] == 0) pq.push(n);
    }
  }

  if(order.size()!= 7) cout << "Cannot complete these tasks. Going to bed." << endl;
  else{
    for(int t : order) cout << t << " ";
  }
  
}
