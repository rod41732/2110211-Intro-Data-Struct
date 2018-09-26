#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> split(string & t) {
    stringstream ss(t);
    string buf;
    vector<string> tokens;
    while (ss >> buf)
        tokens.push_back(buf);
    return tokens;
}
int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<string>> students;
    string line;
    for (int i=0; i<n; ++i) {
        getline(cin, line);
        vector<string> info = split(line);
        students.push_back(info);
    }
    getline(cin, line);
    vector<string> q = split(line);
    set<string> query(q.begin(), q.end());
    vector<vector<string>> results;
    for (vector<string> info: students) {
        set<string> s(info.begin()+1, info.end());
        vector<string> intersect;
        set_intersection(s.begin(), s.end(),
                         query.begin(), query.end(),
                         back_inserter(intersect));
        if (intersect.size() == query.size())
            results.push_back(info);
    }
    if (results.size() == 0) {
        cout << "Not Found\n";
    } else {
        sort(results.begin(), results.end());
        for (vector<string> info: results) {
            for (string e: info) cout << e << " ";
            cout << endl;
        }
    }
    return 0;
}
