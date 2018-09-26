#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
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

typedef pair<int, string> pairEC;

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
    vector<pairEC> suggest;
    for (auto ec: count){
        suggest.push_back(pairEC(-ec.second, ec.first));
    }
    if (suggest.begin() == suggest.end()){
        cout << "No suggested event\n";
    }
    sort(suggest.begin(), suggest.end());
    for (auto ce: suggest){
        cout << ce.second << " " << -ce.first << '\n';
    }
    return 0;
}