#include <cstdio>

int forbid[9], used[9], list[8];
int n, m, x;


void play(int state){
    for (int i=1; i<=n; i++){
        if (used[i] == 0 && (state > 0 || forbid[i] != 1)){
            used[i] = 1;
            list[state] = i;
            if (state == n-1){
                for (int i=0; i<n; i++)
                    printf("%d ", list[i]);
                printf("\n");
            }
            else {
                play(state+1);
            }
            used[i] = 0;
        }
    }
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++){
        scanf("%d", &x);
        forbid[x] = 1;
    }
    play(0);
    return 0;
}