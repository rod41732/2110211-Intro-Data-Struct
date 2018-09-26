#include <map>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

template <class T> 
vector<T> input_split(){
    string line;
    cin >> ws;
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
    map<int, int> count;
    for (int x: input_split<int>()){
        count[x] += 1;
    }
    for (auto nc: count){
        if (nc.second == 1){
            cout << nc.first;
            return 0;
        }
    }
    cout << "NONE";
    return 0;
}