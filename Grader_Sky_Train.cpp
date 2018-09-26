#include <iostream>
#include <sstream>
#include <string>

#include <queue>
#include <map>
#include <vector>
#include <set>
using namespace std;

typedef pair<string, int> myPair; // pair of station, number of hop
map<string, vector<string> > adj; // adjacent stations 

vector<string> input_split(){
    string line, tok;
    getline(cin, line);
    stringstream ss(line);
    vector<string> tokens;
    while (ss >> tok){
        tokens.push_back(tok);
    }
    return tokens;
}

int main(){
    vector<string> stations;
    queue<myPair> que; 
    set<string> reach;
    while (true){
        stations = input_split();
        if (stations.size() == 2){
            string t1 = stations[0], t2 = stations[1];
            adj[t1].push_back(t2);
            adj[t2].push_back(t1);            
        }
        else if (stations.size() == 1){
            // queue = exploration
            que.push(myPair{stations[0], 0});
            while (!que.empty()){
                string current = que.front().first;
                int hop = que.front().second;
                reach.insert(current);
                que.pop();
                if (hop < 2){
                    // explore adjacent stations
                    for (string &a: adj[current]){
                        que.push(myPair{a, hop+1});
                    }
                }
            }
            // like python 's "for s in reach" 
            // can't use reference because we can't set what is in set
            for (string s: reach)
                cout << s << '\n';
            break;
        }
    }
    return 0;
}