#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> split(string &t){
    stringstream ss(t);
    string buf;
    vector<string> tokens;
    while (ss >> buf){
        tokens.push_back(buf);
    }
    return tokens;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<string> > students, match;
    int m;
    string line;
    cin >> m;
    cin.ignore();
    for (int i=0; i<m;i++){
        getline(cin, line);
        vector<string> tokens = split(line);
        students.push_back(tokens);  
    }
    getline(cin, line);
    vector<string> q = split(line);
    set<string> query(q.begin(), q.end()); // convert to set
    vector<string> intersect;
    for (vector<string> &st: students){
        set<string> s(st.begin()+1, st.end()); // convert to set (excluding name)
        set_intersection(s.begin(), s.end(), // intersect S (excluding name) with ...
                        query.begin(), query.end(), // query
                        back_inserter(intersect)); // and insert data into the vector "intersect"; must insert into vector 
        if (intersect.size() == query.size()){
            match.push_back(st);
        }
        intersect.clear();
    }
    sort(match.begin(), match.end()); // sort answer
    if (match.size()){
        for (vector<string> &student: match){
            for (string &s: student) cout << s << " ";
            cout << '\n';
        }
    }
    else {
        cout << "Not Found";
    }
}