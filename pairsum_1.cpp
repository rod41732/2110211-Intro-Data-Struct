#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

template <class T>
vector<T> input_split(){
    cin >> ws;
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<T> tokens; 
    T buf;
    while (ss >> buf){
        tokens.push_back(buf);
    }
    return tokens;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum, ans = 0;
    vector<int> ls = input_split<int>();
    map<int, int> count;
    for (int &x: ls){
        count[x]++;
    }
    cin >> sum;
    for (auto nc: count){
        int x = nc.first;
        ans += count[x] * count[sum - x];
    }
    int half = sum/2; 
    if (half*2 == sum) { //only when sum is even
        ans -= count[half];
    }
    cout << ans/2;
    return 0; 
}