#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Good Groups
//implementation 
//assign each student a group ID and compare IDs to check for violated constraints 

int main() {
  map<string,int> groupID;
  int x, y, g;
  vector <vector<string>> tgt;
  vector <vector<string>> apart; 

  cin >> x;
  for(int i = 0; i < x; i++){
    vector<string> names;
    string t1,t2;
    cin >> t1 >> t2;
    names.push_back(t1);
    names.push_back(t2);
    tgt.push_back(names);
  }

  cin >> y;
  for(int i = 0; i < y; i++){
    vector<string> names;
    string t1,t2;
    cin >> t1 >> t2;
    names.push_back(t1);
    names.push_back(t2);
    apart.push_back(names);
  }

  cin >> g;
  string g1, g2, g3;
  for(int i = 0; i < g; i++){
    cin >> g1 >> g2 >> g3;
    groupID[g1] = i;
    groupID[g2] = i;
    groupID[g3] = i;
  }

  int violated = 0;
  for(int i = 0; i < x; i++){
    if(groupID[tgt[i][0]] != groupID[tgt[i][1]]) violated++;
  }

  for(int i = 0; i < y; i++){
    if(groupID[apart[i][0]] == groupID[apart[i][1]]) violated++;
  }

  cout << violated << endl;
  
  return 0;
}
