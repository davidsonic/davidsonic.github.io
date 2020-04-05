#include<bits/stdc++.h>
using namespace std;
double dp[2005][2005],A[10],B[10],p,q;
double dfs(int x,int y) {
    if(y==0)return 1.0;
    if(x==0)return 0;
    if(dp[x][y]>-1.0)return dp[x][y];
    return dp[x][y]=dfs(x-1,y)*q+dfs(x,y-1)*p;
}
int solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=6; i++)scanf("%lf",&A[i]);
    for(int i=1; i<=6; i++)scanf("%lf",&B[i]);
    p=0,q=0;
    for(int i=1; i<=6; i++)
        for(int j=1; j<=6; j++) {
            if(i>j)p+=A[i]*B[j];
            else if(i<j)q+=A[i]*B[j];
        }
    double s=p+q;
    p/=s,q/=s;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)dp[i][j]=-1;
    double tmp=dfs(n,m);
    printf("%.6f\n",tmp);
    return 0;
}
int main() {
    solve();
    return 0;
}