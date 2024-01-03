#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Spirals
//implementation
//create adequate space for 100 numbers, start from the middle and recursively fill 

int spiral[10][10];
int start, endNum; 

void recur(int row, int column, int length, int num){
  for(int i = 0; i < length; i++){
    row++;
    num++;
    spiral[row][column] = num;
    if(num == endNum) return; 
  }

  for(int i = 0; i < length; i++){
    column++;
    num++;
    spiral[row][column] = num;
    if(num == endNum) return; 
  }

  length++; 

  for(int i = 0; i < length; i++){
    row--;
    num++;
    spiral[row][column] = num;
    if(num == endNum) return; 
  }

  for(int i = 0; i < length; i++){
    column--;
    num++;
    spiral[row][column] = num;
    if(num == endNum) return; 
  }
  
  recur(row, column, length + 1, num);
}

int main() {
  cin >> start >> endNum;
  int row = 4, column = 4, length = 1, num = start;

  if (start == endNum){
    cout << start << endl; 
    return 0;
  }
  
  spiral[row][column] = start;

  recur(row, column, length, num);

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(spiral[i][j] != 0) cout << spiral[i][j] << " ";
    }
    cout << endl;
  }
}
