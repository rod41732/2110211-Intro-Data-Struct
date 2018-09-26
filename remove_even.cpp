#include <iostream>
#include <vector>

using namespace std;

void remove_even(vector<int> &v, int a, int b)
{
    // solution 1 : remove using vector.erase(interator)
    /*
    // remove from back because removing from front will invalidate iterators of next elements
    for (int i=b; i>=a; i--){
        if (i%2 == 0){
            v.erase(v.begin()+i);
        }
    }
    */
    // solution 2: modify new vector in place
    // this is faster becuase we didn't shift element each time we remove
    int len = a; // len = number of element post remove
    for (int i=a; i<v.size(); i++){
        // not removed;
        if (!(a <= i && i <= b && i%2 == 0)){
            v[len++] = v[i];
        }
    }
    v.resize(len);
}
int main()
{
    int n, a, b;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;        
    //call function
    remove_even(v, a, b); 
    //display content of the vector
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
