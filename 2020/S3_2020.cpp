#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Searching for Strings
// Data Structures, String Algorithms (Hashing)

vector<int> freq(26), freqset(26);
vector<long long int> powers; 
//const long long int mod = 1e9 + 7;
const long long int mod = 4000002469;
const long long int base = 31; 

void powMod(int length) {
  long long int pow = 1;
  powers.push_back(1);
  for (int i = 0; i < length; i++) {
    pow = (pow * base) % mod;
    powers.push_back(pow); 
  }
}

long long int stringHash(string s) {
  
  long long int ans = 0;
  for (int i = s.size()-1; i >= 0; i++) {
    ans = ((ans + (s[i] - 'a') * powers[i])) % mod;
  }
  return ans;
}

bool fit() {
  bool fit = true;
  for (int i = 0; i < 26; i++) {
    if (freq[i] != freqset[i]) {
      fit = false;
      break;
    }
  }
  return fit;
}

int main() {
  string n, h;
  cin >> n >> h;

  fill(freq.begin(), freq.end(), 0);
  for (int i = 0; i < n.length(); i++) {
    freq[n[i] - 'a']++;
  }

  unordered_set<long long int> substr;
  fill(freqset.begin(), freqset.end(), 0);
  long long int hash = 0; 
  
  if (h.length() >= n.length()) {
    powMod(n.length()); 

    //first window
    for (int i = 0; i < n.length(); i++){
      freqset[h[i] - 'a']++;
    }
    for (int i = 0; i < n.length(); i++) {
      hash = (hash + (h[i] - 'a') * powers[n.length() - 1 - i]) % mod;
      //hash = (hash * base + (h[i] - 'a')) % mod;
    }
    if (fit()) substr.insert(hash);

    //rolling window
    for (int i = 1; i <= h.length() - n.length(); i++) {
      freqset[h[i - 1] - 'a']--;
      freqset[h[i + n.length() - 1] - 'a']++;
      hash = (((mod*base + hash  - (h[i-1] - 'a') * powers[n.length() - 1])*base) % mod + h[i + n.length() - 1] - 'a') % mod;
      //hash = (hash * base + ((h[i-1] - 'a') * powers[n.length() - 1]) + (h[i + n.length() - 1] - 'a')) % mod;

      if (fit()) substr.insert(hash);
      
    }
  }

  cout << substr.size() << endl;
}