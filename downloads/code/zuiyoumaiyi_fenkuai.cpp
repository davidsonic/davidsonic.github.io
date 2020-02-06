#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;


const int N = 320, M = 100010;
int n, m;
int S;
int A[M];
int V[N], Mi[N], Mx[N];

int query(int L, int R){
    int ka = L/S, kb= R/S;
    int res = 0, mi = A[L];
    if(ka==kb){
        for(int i=L+1;i<=R;i++){
            res = max(res, A[i] - mi);
            mi = min(mi, A[i]);
        }
    }
    else{
        for(int i=L+1;i<(ka+1)*S;i++){
            res = max(res, A[i] - mi);
            mi = min(mi, A[i]);
        }
        for(int i=ka+1;i<kb;i++){
            res = max(res, max(V[i], Mx[i] - mi));
            mi = min(mi, Mi[i]);
        }

        for(int i=kb*S;i<=R;i++){
            res = max(res, A[i] - mi);
            mi = min(mi, A[i]);
        }
    }
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) scanf("%d", &A[i]);
    S = sqrt(n);
    for(int i=1;i<=n/S; i++){
        V[i] = 0;
        Mi[i] = 1e9;
        Mx[i] = 0;
    }

    for(int i=0;i<=n;i++){
        int x = i/S;
        V[x] = max(V[x], A[i] - Mi[x]);
        Mi[x] = min(Mi[x], A[i]);
        Mx[x] = max(Mx[x], A[i]);
    }

    while(m--){
        int l, r;
        scanf("%d%d", &l, &r);
        int ans = query(l, r);
        printf("%d\n", ans);
    }
    return 0;

}