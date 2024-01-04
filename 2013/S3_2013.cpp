#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Chances of Winning
//brute force

int t, w = 0; 

void wins(vector<int> points, vector<vector<bool>> games, int gamesPlayed){

  if(gamesPlayed == 6){
    bool won = true; 
    for(int i = 1; i < 5; i++){
      if(t != i && points[t] <= points[i]){
        won = false;
        break;
      }
    }
    if(won){
      w++;
    }
    return;
  }

  for(int i = 1; i < 5; i++){
    for(int j = 1; j < 5; j++){
      if(!games[i][j]){

        games[i][j] = true;
        games[j][i] = true; 

        points[i] += 3;
        wins(points, games, gamesPlayed+1); 

        points[i] -= 3;
        points[j] += 3;
        wins(points, games, gamesPlayed+1); 

        points[j] -= 3;
        points[i]++;
        points[j]++;
        wins(points, games, gamesPlayed+1); 

        points[i]--;
        points[j]--;
      }
    }
  }
  return; 
}

int main(){
  vector<vector<bool>> games(5, vector<bool>(5, false));
  games[1][1] = true;
  games[2][2] = true;
  games[3][3] = true;
  games[4][4] = true;

  vector<int> points(5, 0);

  int gamesPlayed;
  cin >> t >> gamesPlayed; 

  for(int i = 0; i < gamesPlayed; i++){
    int a, b, ap, bp;
    cin >> a >> b >> ap >> bp; 
    games[a][b] = true; 
    games[b][a] = true; 

    if(ap > bp) points[a] += 3;
    else if (bp > ap) points[b] += 3;
    else{
      points[a]++;
      points[b]++;
    }
  }

  wins(points, games, gamesPlayed);
  cout << w << endl;
}
