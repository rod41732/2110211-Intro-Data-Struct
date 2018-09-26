#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n, m, x;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i=0; i<n; i++){
    cin >> a[i];
  }
  for (int i=0; i<m; i++){
    cin >> b[i];
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  auto ia=a.begin(), ib=b.begin();
  vector<int> inter;
  while (ia != a.end() && ib != b.end()){
    if (*ia < *ib) ia++;
    else if (*ib < *ia) ib++;
    else {
      inter.push_back(*ia);
      ia++; ib++ ;
    }
  }
  if (n = inter.size()){
    int last = inter[0];
    cout << last << ' ';
    for (int i=1; i<n; i++){
      if (inter[i] != last){
        last = inter[i];
        cout << last << ' ';
      }
    }
  }
  
  
  return 0;
}