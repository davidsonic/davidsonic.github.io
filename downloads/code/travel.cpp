#include <iostream>
using namespace std;

const int  N = 10;
int g[N][N];
bool vis[N];
int n, k;

int res = 0;

void dfs(int u, int cnt, int dis){
    if(cnt==n){
        dis += g[u][1];
        if(dis==k) res++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(i, cnt+1, dis + g[u][i]);
            vis[i] = 0;
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    vis[1] = 1;
    dfs(1, 1, 0);
    cout<<res<<endl;
    return 0;
}