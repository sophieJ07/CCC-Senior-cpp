#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Blindfold
//simulation
//optimize by finding a "formula" for each direction
//generated two sets of formula (down, left), reflected (*-1) them for the up and right direction

int r, c, m;
vector<char> moves;

set<pair<int, int>> findSteps(int d, int x, int y, pair<int, int> &last){
  set<pair<int, int>> ret;
  ret.insert(make_pair(x, y));
  for(int i = 0; i < m; i++){
    if(moves[i] == 'R'){
      d += 90;
      if(d >= 360) d = 0;
    }else if(moves[i] == 'L'){
      d -= 90;
      if(d < 0) d = 270;
    }else{
      if(d == 0) y--;
      else if(d == 90) x--;
      else if (d == 180) y++;
      else x++;
    }
    ret.insert(make_pair(x, y));
    if(i == m-1) last = make_pair(x, y);
  }
  return ret;
}

int main(){
  cin >> r >> c;
  string grid[r];

  for(int i = 0; i < r; i++){
      cin >> grid[i];
  }

  cin >> m;
  for(int i = 0; i < m; i++){
    char c;
    cin >> c;
    moves.push_back(c);
  }

  //find steps
  pair<int, int> lastDown, lastUp, lastRight, lastLeft;
  set<pair<int, int>> down = findSteps(0, 0, 0, lastDown);
  set<pair<int, int>> left = findSteps(90, 0, 0, lastLeft);
  set<pair<int, int>> up, right;

  for(auto& pair:down){
    up.insert(make_pair(pair.first * -1, pair.second * -1));
  }
  for(auto& pair:left){
    right.insert(make_pair(pair.first * -1, pair.second * -1));
  }
  lastUp = make_pair(lastDown.first * -1, lastDown.second * -1);
  lastRight = make_pair(lastLeft.first * -1, lastLeft.second * -1);

  //simulation
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      bool works = true;
      for(auto& pair:up){
        int x = pair.first + i, y = pair.second + j;
        if(x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == 'X'){
          works = false;
          break;
        }
      }
      if(works) grid[lastUp.first + i][lastUp.second + j] = '*';

      works = true;
      for(auto& pair:down){
        int x = pair.first + i, y = pair.second + j;
        if(x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == 'X'){
          works = false;
          break;
        }
      }
      if(works) grid[lastDown.first + i][lastDown.second + j] = '*';

      works = true;
      for(auto& pair:left){
        int x = pair.first + i, y = pair.second + j;
        if(x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == 'X'){
          works = false;
          break;
        }
      }
      if(works) grid[lastLeft.first + i][lastLeft.second + j] = '*';

      works = true;
      for(auto& pair:right){
        int x = pair.first + i, y = pair.second + j;
        if(x < 0 || x >= r || y < 0 || y >= c || grid[x][y] == 'X'){
          works = false;
          break;
        }
      }
      if(works) grid[lastRight.first + i][lastRight.second + j] = '*';
    }
  }

  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cout << grid[i][j];
    }
    cout << endl;
  }

}
