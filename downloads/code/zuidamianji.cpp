#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
int h[N];
int n;
int L[N], R[N];
int stk[N], t=0;
typedef long long LL;

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &h[i]);

    stk[0] = 0;

    for(int i=1;i<=n;i++) {
        while (t > 0 && h[stk[t]] >= h[i]) t--;
        L[i] = stk[t];
        stk[++t] = i;
    }
    stk[0] = n+1;
    for(int i=n;i>=1;i--){
        while(t>0 && h[stk[t]] >= h[i]) t--;
        R[i] = stk[t];
        stk[++t] = i;
    }


//    for(int i=1;i<=n;i++) printf("%d ", L[i]);
//    puts("");
//
//    for(int i=1;i<=n;i++) printf("%d ", R[i]);
//    puts("");

    LL res = 0;
    for(int i=1;i<=n;i++){
        res = max(res, 1LL * (R[i]-L[i] -1) * h[i]);
    }
    printf("%lld\n", res);
    return 0;

}
