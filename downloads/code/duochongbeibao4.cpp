#include <bits/stdc++.h>
using namespace std;
#define M 10005
int Q[M],Q2[M],dp[M];
int main() {
//  dp[cur][k*d+i]-k*val[i] = Max(dp[!cur][j*d+i]-j*val[i]);
    int n,v;
    scanf("%d%d",&v,&n);
    for(int i=1,num,ct,val; i<=n; i++) {
        scanf("%d%d%d",&num,&ct,&val);
        for(int j=0; j<ct; j++) {
            int head = 1,tail = 0;
            for(int k=0; k*ct+j<=v; k++) {
                int res = dp[k*ct+j]-k*val;
                while(head <= tail && k-Q2[head] > num) head ++;
                while(head <= tail && res >= Q[tail]) tail--;
                Q[++tail] = res,Q2[tail] = k;
                dp[k*ct+j] = Q[head]+k*val;
            }
        }
    }
    printf("%d\n",dp[v]);
    return 0;
}