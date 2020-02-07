#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
int A[N];
int n, m;
int V[N][17], Mi[N][17], Mx[N][17];

int query(int L, int R){
    int step = R - L + 1;
    int res = 0, mi = 1e9;
    for(int i=0;(1<<i)<=step;i++){
        if(step & (1<<i)){
            res = max(res, max(V[L][i], Mx[L][i] - mi));
            mi = min(mi, Mi[L][i]);
            L += (1<<i);
        }
    }
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) {
        scanf("%d", &A[i]);
        V[i][0] = 0;
        Mi[i][0] = A[i];
        Mx[i][0] = A[i];
    }

    for(int j=1;(1<<j)<=n;j++){
//      i starts from i cause'  A starts from 1
        for(int i=1;i+(1<<j)-1<=n;i++){
            int t = i+(1<<j-1);
            V[i][j] = max(max(V[i][j-1], V[t][j-1]), Mx[t][j-1] - Mi[i][j-1]);
            Mx[i][j] = max(Mx[i][j-1], Mx[t][j-1]);
            Mi[i][j] = min(Mi[i][j-1], Mi[t][j-1]);
        }
    }

    while(m--){
        int L, R;
        scanf("%d%d", &L, &R);
        printf("%d\n", query(L, R));
    }
    return 0;
}