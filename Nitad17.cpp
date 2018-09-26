#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
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

template <class T>
vector<T> split(string &line){
    stringstream ss(line);
    vector<T> tokens;
    T buf;
    while (ss >> buf){
        tokens.push_back(buf);
    }
    return tokens;
}


int main(){
    int n;
    cin >> n;
    string data[n], evt;
    cin >> ws;
    for (int i=0; i<n; i++){
        getline(cin, data[i]);
    }
    vector<string> events;
    set<string> uniqueEvents;
    map<string, int> count;
    cin >> evt;
    bool foundEvt = false;
    for (int i=0; i<n; i++){
        events = split<string>(data[i]);
        uniqueEvents = set<string>(events.begin(), events.end());
        if (uniqueEvents.find(evt) != uniqueEvents.end()){
            foundEvt = true;
            for (string s: uniqueEvents){
                if (s != evt){
                    count[s] += 1;
                }
            }
        }
    }
    if (!foundEvt){
        cout << "Not Found";
        return 0;
    }
    pair<int, string> answer = make_pair(0, "No suggested event");
    for (auto ec: count){
        if (make_pair(-ec.second, ec.first) < answer)
            answer = make_pair(-ec.second, ec.first);
    }
    cout << answer.second << "\n";
    if (-answer.first)
        cout << -answer.first;
    return 0;
}