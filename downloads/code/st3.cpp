#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
int a[N];
int n, m;
int S[N][17];
int Log[N];


int query(int L, int R){
    int k= Log[R-L+1];
    int res = max(S[L][k], S[R-(1<<k)+1][k]);
    return res;
}

int main(){
    scanf("%d%d", &n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        S[i][0] = a[i];
    }

    Log[0] =-1;
    for(int i=1;i<=n;i++) Log[i] = Log[i>>1] + 1;

    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++) {
            int t = i + (1<<j-1);
            S[i][j] = max(S[i][j-1], S[t][j-1]);
        }

    while(m--){
        int L, R;
        scanf("%d%d", &L, &R);
        printf("%d\n", query(L, R));
    }
    return 0;
}