#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
const int N = 100010;
int A[N], sum[320][N];
int S;

int query(int L, int R, int x) {
    int ka = L / S, kb = R / S;
    int res = 0;
    if (ka == kb) {
        for (int i = L; i <= R; i++) {
            res += A[i] <= x;
        }
    } else {
        for (int i = L; i < (ka + 1) * S; i++)
            res += A[i] <= x;

        for (int i = ka + 1; i < kb; i++) {
            res += sum[i][x];
        }

        for (int i = kb * S; i <= R; i++)
            res += A[i] <= x;
    }
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    S = sqrt(n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &A[i]);
        sum[i/S][A[i]] ++;
    }


    for(int i=1;i<=n/S; i++)
        for(int j=1;j<=n;j++)
            sum[i][j] += sum[i][j-1];

    while(m--){
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        int ans = query(a, b, x);
        printf("%d\n", ans);
    }
    return 0;
}