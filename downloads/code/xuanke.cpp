#include<bits/stdc++.h>
#define M 305
using namespace std;
int m,val[M]= {0},cost[M];
vector<int>edge[M];
int dp[M][M];
void dfs(int x) {
    int t=0,i,j,k,y;
    for(i=1; i<=m; i++)
        dp[x][i]=val[x];
    if(x)t=1;
    for(i=0; i<edge[x].size(); i++) {
        y=edge[x][i];
        dfs(y);
        for(j=m; j>=t; j--)
            for(k=1; k<=j-t; k++)
                dp[x][j]=max(dp[x][j],dp[x][j-k]+dp[y][k]);
    }
}
int main() {
    int n,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=0; i<=n; i++)
        edge[i].clear();
    for(i=1; i<=n; i++) {
        scanf("%d %d",&a,&val[i]);
        edge[a].push_back(i);
    }
    memset(dp,0,sizeof(dp));
    dfs(0);
    printf("%d\n",dp[0][m]);
    return 0;
}