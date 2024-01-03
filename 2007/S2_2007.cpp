#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Boxes
//implementation

int main() {
  vector<vector<int>> items;
  vector<vector<int>> boxes; 
  int itemsNum, boxesNum;
  
  cin >> boxesNum;
  for(int i = 0; i < boxesNum; i++){
    vector<int> store;
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    store.push_back(d1);
    store.push_back(d2);
    store.push_back(d3);
    sort(store.begin(), store.end());
    boxes.push_back(store); 
  }

  cin >> itemsNum;
  for(int i = 0; i < itemsNum; i++){
    vector<int> store;
    int d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    store.push_back(d1);
    store.push_back(d2);
    store.push_back(d3);
    sort(store.begin(), store.end());
    items.push_back(store); 
  }
  

  for(int i = 0; i < itemsNum; i++){
      bool canFit = false;
      int bestFit = INT_MAX;
      for(int j = 0; j < boxesNum; j++){
        if(items[i][0] <= boxes[j][0] && items[i][1] <= boxes[j][1] && items[i][2] <= boxes[j][2]){
          canFit = true; 
          if (boxes[j][0] * boxes[j][1] * boxes[j][2] < bestFit) bestFit = boxes[j][0] * boxes[j][1] * boxes[j][2];
        }
      }
      if(!canFit) cout << "Item does not fit." << endl;
      else cout << bestFit << endl;
  }
  
  return 0;
}