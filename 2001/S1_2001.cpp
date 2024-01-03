#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Keeping Score
//implementation

char cards[53];
int i;

int getPoints(){
  int p = 0;
  while(cards[i] != 'D' && cards[i] != 'H' && cards[i] != 'S'&& cards[i] != '\0'){
    cout << cards[i] << " ";
    if(cards[i] == 'A') p += 4;
    if(cards[i] == 'K') p += 3;
    if(cards[i] == 'Q') p += 2;
    if(cards[i] == 'J') p += 1;
    i++;
  }
  return p;
}

int addPoints(int amount){
  if(amount == 0) return 3;
  if(amount == 1) return 2;
  if(amount == 2) return 1;
  return 0;
}

int main() {
  
  cin >> cards;
  cout << "Cards Dealt Points" << endl;
  int p, start = 1, amount, total = 0;
  i = 1;
  
  cout << "Clubs ";
  p = getPoints();
  amount = i - start;
  p += addPoints(amount);
  cout << p << endl;
  total += p;

  cout << "Diamonds ";
  i++;
  start = i;
  p = getPoints();
  amount = i - start;
  p += addPoints(amount);
  cout << p << endl;
  total += p;

  cout << "Hearts ";
  i++;
  start = i;
  p = getPoints();
  amount = i - start;
  p += addPoints(amount);
  cout << p << endl;
  total += p;

  cout << "Spades ";
  i++;
  start = i;
  p = getPoints();
  amount = i - start;
  p += addPoints(amount);
  cout << p << endl;
  total += p;

  cout << "Total " << total << endl;
  
  return 0;
  
}
