#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<string, vector<string>> pss;

int main(){
    vector<pss> fruitList;
    int mx;
    string fname, line, person, fruit, mxFruit;
    cin >> fname;
    fstream file(fname.c_str());
    while (getline(file, line)){
        bool found = false;
        stringstream ss(line);
        ss >> fruit >> person;
        for (pss &fp : fruitList){ // pair of fruit, vector of person
            if (fp.first == fruit){
                fp.second.push_back(person);
                found = true;
                break;
            }
        }
        if (!found){
            fruitList.push_back(pss{fruit, {person}});
        }
    }
    file.close();
    cout << '[';
    for (auto it = fruitList.begin(); it != fruitList.end();){
        cout << "['" << it->first << "', [";
        vector<string> people = it->second; // for readability
        if (people.size() > mx){
            mx = people.size(); 
            mxFruit = it->first;
        }
        for (auto it2 = people.begin(); it2 != people.end();){
            cout << '\'' << *it2 << "'";
            if (++it2 != people.end()) cout << ", ";
        }
        cout << "]]";
        if (++it != fruitList.end()) cout << ", ";
    }
    cout << "]\n";
    cout << "The most favourite fruit is " << mxFruit;
    return 0;
}