#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Student {
public:
    string sid;
    float point;
    string depts[4];
};
bool stu_greater(const Student & s1, const Student & s2) {
    return s1.point > s2.point;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    map<string, int> avail; 
    int m;

    cin >> m;
    while (m--){
        string fac;
        int space;
        cin >> fac >> space;
        avail[fac] = space;    
    }

    vector<Student> students;
    cin >> m;
    for (int i=0; i<m; i++) {
        string s, d1, d2, d3, d4;
        float p;
        cin >> s >> p >> d1 >> d2 >> d3 >> d4;
        students.push_back(Student{s, p, {d1, d2, d3, d4}});
    }   
    sort(students.begin(), students.end(), stu_greater);
	// write code here
    map<string, string> faculty;
	for (int i=0; i<m; i++){
        Student s = students[i];
        // cout << s.sid; 
        for (int k=0; k<4; k++){
            if (avail[s.depts[k]] > 0){
                avail[s.depts[k]]--;
                faculty[s.sid] = s.depts[k];
                break;
            }
        }
    }
    // can loop in map because map order by key (studentID)
    for (auto &p: faculty){
        cout << p.first << " " << p.second << '\n';
    }
    return 0;
}