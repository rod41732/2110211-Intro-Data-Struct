#include <iostream>
#include <vector>

using namespace std;
void reverse(vector<int> &v,int a,int b) {

    while (a < b){
        swap(v[a++], v[b--]);
    }
    return;
}

int main(){
    int n, a, b;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    reverse(v, a, b);
    for (auto &x : v){
        cout << x << " ";
    }
    cout << endl;
}