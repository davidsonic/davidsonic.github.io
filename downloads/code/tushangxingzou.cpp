#include<bits/stdc++.h>
#define M 100005
using namespace std;
struct node{
    int to,v;
};
vector<node>edge[M];
double dp[M];
int n;
bool mark[M];
double dfs(int x){
    if(x==n)return 0;
    if(dp[x]>-1.0)return dp[x];
    dp[x]=0;
    for(int i=0;i<edge[x].size();i++){
        int y=edge[x][i].to;
        dp[x]+=edge[x][i].v+dfs(y);
    }
    dp[x]/=edge[x].size();
    return dp[x];
}
int main(){
    int m,a,b,c;
    cin>>n>>m;
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        edge[a].push_back((node)<%b,c%>);
    }
    for(int i=1;i<=n;i++)dp[i]=-1;
    double ans=dfs(1);
    printf("%.2f\n",ans);
    return 0;
}