#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Floor Plan
//floodfill for room sizes & fill with flooring from largest room as instructed

bool isWall[25][25]; 
bool isVisited[25][25]; 
int r, c;

int findRoomSize(int i, int j){
  if(j < 0 || j >= c || i < 0 || i >= r || isWall[i][j] || isVisited[i][j]) return 0;
  isVisited[i][j] = true; 
  return 1 + findRoomSize(i+1, j) + findRoomSize(i-1, j) + findRoomSize(i, j+1) + findRoomSize(i, j-1);
}


int main() {
  int flooring;
  cin >> flooring >> r >> c; 

  char line[26]; 
  for(int i = 0; i < r; i++){
    cin >> line;
    for(int j = 0; j < c; j++){
      if(line[j] == 'I') isWall[i][j] = true;
      else isWall[i][j] = false;
      isVisited[i][j] = false;
    }
  }

  vector<int> rooms;

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(!isWall[i][j] && !isVisited[i][j]){
        rooms.push_back(findRoomSize(i, j));
      }
    }
  }

  sort(rooms.begin(), rooms.end());
  
  int filledRooms = 0, index = rooms.size() - 1;
  while(flooring > 0 && index >= 0){
    if(flooring - rooms[index] >= 0){
      filledRooms++;
      flooring -= rooms[index];
    } else break; 
    index--;
  }

  if(filledRooms == 1) cout << filledRooms << " room, " << flooring << " square metre(s) left over" << endl;
  else cout << filledRooms << " rooms, " << flooring << " square metre(s) left over" << endl;
  
}
