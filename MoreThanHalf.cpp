#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vct;
    int buf;
    while (1){
        cin >> buf;
        if (buf == -1) break;
        else vct.push_back(buf);
    }   
    sort(vct.begin(), vct.end());
    int idx = (vct.size())/2;
    if (idx <= 2 || vct[idx] == vct[idx-1]){
        cout << vct[idx]; 
    }
    else {
        cout << "Not found";
    }
    return 0;
}