#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<string> allTeam, loseTeam;
    int n;
    string winner, loser;
    cin >> n;
    while (n--){
        cin >> winner >> loser;
        allTeam.insert(winner);
        loseTeam.insert(loser);
    }
    for (string t: loseTeam){
        allTeam.erase(t);
    }
    // print python list
    cout << "[";
    for (auto it=allTeam.begin(); it != allTeam.end();){
        cout << "'" << *it << "'";
        if (++it != allTeam.end())
            cout << ", ";
    }
    cout << "]";
    return 0;
}