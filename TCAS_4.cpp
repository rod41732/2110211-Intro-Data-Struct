#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <set>
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
    map<string, vector<string> > choices, applicant;
    map<string, set<pair<int, string> > > admitted;
    map<string, map<string, int> > order; // map[pid][sid] => order 
    vector<string> unassigned;
    map<string, int> cap;
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        string name;
        cin >> name;
        choices[name] = input_split<string>();
        unassigned.push_back(name);
    }
    cin >> n;
    for (int i=0; i<n; i++){
        string name;
        cin >> name; 
        cin >> cap[name];
        applicant[name] = input_split<string>();
        int j=0;
        for (string &student: applicant[name]){
            order[name][student] = j++;
        }
        admitted[name] = set<pair<int, string> >();
    }
    // cout << unassigned.size();
    while (unassigned.size()){
        string student = unassigned.back();
        // cout << unassigned.size() << "students \n";
        unassigned.pop_back();
        // cout << student << choices[student].size();
        if (choices[student].size()){
            string subject = choices[student][0]; //first subject chosed
            // cout << " go " << subject << '\n';
            choices[student].erase(choices[student].begin());
            admitted[subject].insert(make_pair(order[subject][student], student));

            if (admitted[subject].size() > cap[subject]){ // if full kick last people
                pair<int, string> out = *(--admitted[subject].end());
                admitted[subject].erase(--admitted[subject].end());
                unassigned.push_back(out.second);
                // cout << "failed\n";
            }
        }
    }

    for (auto subStu: admitted){
        cout << subStu.first << " ";
        set<string> sortedPeople;
        for (auto pOrStu: subStu.second){
            sortedPeople.insert(pOrStu.second);
        }
        for (string s: sortedPeople){
            cout << s << " ";
        }
        // delete &sortedPeople;
        cout << "\n";
    }

    return 0;
}