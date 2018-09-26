#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void stack_concat(stack<int> &s1, stack<int> &s2){
    stack<int> tmp;
    // move s1 to top of s2
    while (!s1.empty()){
        tmp.push(s1.top());
        s1.pop();
    }
    while (!tmp.empty()){
        s2.push(tmp.top());
        tmp.pop();
    }
    // move all of s2 to s1
    while (!s2.empty()){
        tmp.push(s2.top());
        s2.pop();
    }
    while (!tmp.empty()){
        s1.push(tmp.top());
        tmp.pop();
    }
    
    return ;
}

int main(){
    int n, m;
    int c;
    cin >> n >> m;
    stack<int> s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> c;
        s1.push(c);
    }
    for (int i = 0; i < m; i++) {
        cin >> c;
        s2.push(c);
    }
    stack_concat(s1, s2);
    cout << "S1 has " << s1.size() << endl;
    while (!s1.empty()){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;
    cout << "S2 has " << s2.size() << endl;
    while (!s2.empty()){
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;
}
