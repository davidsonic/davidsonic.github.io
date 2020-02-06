#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
const int N = 100010;
int A[N], B[N];
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
            res += upper_bound(B + i * S, B + i * S + S, x) - (B + i * S);
        }

        for (int i = kb * S; i <= R; i++)
            res += A[i] <= x;
    }
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) {
        scanf("%d", &A[i]);
        B[i] = A[i];
    }
    S = sqrt(n*log(n)/log(2));

    for(int i=S;i+S-1<=n;i+=S){
        sort(B+i, B+i+S);
    }
    while(m--){
        int a, b, x;
        scanf("%d%d%d", &a, &b, &x);
        int ans = query(a, b, x);
        printf("%d\n", ans);
    }
    return 0;
}