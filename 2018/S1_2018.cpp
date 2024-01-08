#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Voronoi Villages
//implementation 

int main() {
  int n;
  cin >> n;
  vector<double> neighbours;

  double store;
  for(int i = 0; i < n; i++){
    cin >> store;
    neighbours.push_back(store);
  }

  sort(neighbours.begin(), neighbours.end());

  double size, min = INT_MAX;
  for(int i = 1; i < n-1; i++){
    size = (double) (neighbours[i] - neighbours[i-1])/2.0 + (neighbours[i+1] - neighbours[i]) / 2.0;
    if(size < min) min = size;
  }

  cout << setprecision(1) << fixed << min << endl;
  
  return 0;
}