#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define M 100005
using namespace std;
struct Query{
    int id,c;
};
vector<Query>q[M];
vector<int>edge[M];
int col[M],cnt[M],Res[M];
int sz[M],Big[M],ans[M];
int Lt[M],Rt[M],dfsLine[M],tid=0;
void Rd(int &res){
    char c;res=0;
    while(c=getchar(),c<'0');
    do res=(res<<3)+(res<<1)+(c^48);
    while(c=getchar(),c>='0');
}
void dfs_pre(int x,int f){
    sz[x]=1;Big[x]=0;
    Lt[x]=++tid;dfsLine[tid]=x;
    for(int i=0;i<edge[x].size();i++){
        int y=edge[x][i];
        if(y==f)continue;
        dfs_pre(y,x);
        sz[x]+=sz[y];
    }
    Rt[x]=tid;
}
void Del(int x){
    for(int i=Lt[x];i<=Rt[x];i++){
        int t=dfsLine[i];
        --Res[cnt[col[t]]--];
    }

}
void Add(int x){
    for(int i=Lt[x];i<=Rt[x];i++) {
        int t=dfsLine[i];
        ++Res[++cnt[col[t]]];
    }
}
void solve(int x,int f){
    int big=-1;
    for(int i=0;i<edge[x].size();i++){
        int y=edge[x][i];
        if(y==f)continue;
        if(big==-1||sz[y]>sz[big])big=y;
    }
    for(int i=0;i<edge[x].size();i++){
        int y=edge[x][i];
        if(y!=f&&y!=big){
            solve(y,x);Del(y);
        }
    }
    if(big!=-1)solve(big,x);

    for(int i=0;i<edge[x].size();i++){
        int y=edge[x][i];
        if(y!=f&&y!=big)Add(y);
    }
    ++Res[++cnt[col[x]]];

    for(int i=0;i<q[x].size();i++)
        ans[q[x][i].id]=Res[q[x][i].c];
}
void Prt(int x){
    if(x==0)return;
    Prt(x/10); putchar(x%10^48);
}
int main(){
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        edge[i].clear();
        scanf("%d",&col[i]);
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        q[a].push_back((Query){i,b});
    }
    dfs_pre(1,0);
    solve(1,0);
    for(int i=1;i<=m;i++){
        if(ans[i]==0)putchar('0');
        Prt(ans[i]);
        putchar('\n');
    }
    return 0;
}