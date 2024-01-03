#include <iostream>
#include <vector>
#include <algorithm>
#include <istream>
#include <queue> 

using namespace std;

//Strategic Bombing
//graph theory + brute force
//one by one, disconnect paths (roads) and run bfs to identify whether the path is a "disconnecting road"

int main(){
  vector<vector<char>> neighbours(26);
  vector<string> roads; 

  string store;
  getline(cin, store);

  while(store != "**"){
    roads.push_back(store);
    neighbours[store[0] - 'A'].push_back(store[1]); 
    neighbours[store[1] - 'A'].push_back(store[0]); 
    getline(cin, store);
  }

  int poss = 0; 

  for(int i = 0; i < roads.size(); i++){
    string r = roads[i];
    neighbours[r[0] - 'A'].erase(find(neighbours[r[0] - 'A'].begin(), neighbours[r[0] - 'A'].end(),r[1]));
    neighbours[r[1] - 'A'].erase(find(neighbours[r[1] - 'A'].begin(), neighbours[r[1] - 'A'].end(),r[0]));

    bool atob = false; 
    vector<bool> visited(26, false); 
    queue<char> q; 
    q.push('A');
    
    while(!q.empty()){
      char loc = q.front();
      q.pop();

      if(loc == 'B'){
        atob = true; 
        break;
      }
      for(int i = 0; i < neighbours[loc - 'A'].size(); i++){
        if(!visited[(neighbours[loc - 'A'][i]) - 'A']){
          q.push(neighbours[loc - 'A'][i]);
          visited[(neighbours[loc - 'A'][i]) - 'A'] = true;
        }
      }
    }

    if(!atob){
      cout << r << endl; 
      poss++;
    }
    
    neighbours[r[0] - 'A'].push_back(r[1]);
    neighbours[r[1] - 'A'].push_back(r[0]);
    
  }

  cout << "There are " << poss << " disconnecting roads." << endl;
  
}