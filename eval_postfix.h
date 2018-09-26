#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

int eval_postfix(const vector<pair<int,int> > &v){
    stack<int> op;
    for (pair<int, int> p: v){
        if (p.first == 1) op.push(p.second);
        else {
            int t1 = op.top(); op.pop();
            int t2 = op.top(); op.pop();
            switch (p.second){
                case 0: 
                    op.push(t2+t1);
                    break;
                case 1: 
                    op.push(t2-t1);
                    break;
                case 2: 
                    op.push(t2*t1);
                    break;
                case 3: 
                    op.push(t2/t1);
                    break;
            }
        }
    }
    return op.top();
}