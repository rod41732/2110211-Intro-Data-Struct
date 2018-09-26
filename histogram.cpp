#include <map>
#include <iostream>
#include <string>
using namespace std;

map<string, int> freq;

int main(){
  // make I/O faster
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  string x;
  cin >> n;
  while(n--){
    cin >> x;
    freq[x]++;    
  }
  for (auto it=freq.begin(); it != freq.end(); ++it){
    if (it->second > 1)
      cout << it->first << " " << it->second << '\n';
  }
  return 0; 
}
