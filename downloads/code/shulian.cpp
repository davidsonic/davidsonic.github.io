#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 100010;
vector<int>edges[N];

int fa[N], dep[N], son[N], top[N], sz[N];
int n, m;

// get son vector
void dfs(int x, int f, int d){
    fa[x] = f, dep[x] = d, sz[x] = 1, son[x] = 0;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(y==f) continue;
        dfs(y, x, d+1);
        sz[x] += sz[y];
        if(sz[son[x]] < sz[y]) son[x] = y;
    }
}

// get top vector
void dfs2(int x, int f, int tp){
    top[x] = tp; ID[x] = ++tot;
    if(son[x]) dfs2(son[x], x, tp);
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(y==f || y == son[x]) continue;
        dfs2(y, x, y);
    }
}

// a和b走向一条重链
int LCA(int a, int b){
    while(top[a]!=top[b]){
        if(dep[top[a]] > dep[top[b]]){
            // ID[top[a]], ID[a] 是一段连续的区间
            a = fa[top[a]];
        }else b = fa[top[b]];
    }
    return dep[a] > dep[b] ? b: a;
}

int main(){
    cin>>n>>m;
    int a, b;
    for(int i=1;i<n;i++){
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 0, 1);
    dfs2(1,0,1);
    for(int i=1;i<=n;i++){
        printf("%d %d %d\n", i, son[i], top[i]);
    }
// 8 jumps to 8, fa[8] = 4Œ
    for(int i=1;i<=m;i++){
        scanf("%d%d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}