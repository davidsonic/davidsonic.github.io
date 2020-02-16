#include <iostream>
#include <vector>
using namespace std;

const int N = 300010;
const int S = 20;

int n, m;
int path[N];
int ans[N], ID[N]; //map node id to edge id

struct Node{
    int to, id;
};
vector<Node>edges[N];

int dis[N], dep[N];
int fa[N][S+2];
int cnt[N];
void dfs(int x, int f, int d){
    fa[x][0] = f, dep[x] = dep[f] +1, dis[x] = d;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i].to;
        if(y==f) continue;
        ID[y] = edges[x][i].id;  // ID maps y to edge id;
        dfs(y, x, d + 1);
    }
}

void goUp(int &x, int step){
//  starts from 0
    for(int i=0;i<=S;i++){
        if(step & (1<<i)) x = fa[x][i];
    }
}

int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    goUp(x, dep[x]-dep[y]);
    if(x==y) return x; // easy to forget
    for(int i=S;i>=0;i--){
        if(fa[x][i] != fa[y][i])
            x = fa[x][i], y= fa[y][i];
    }
    return fa[x][0];
}

void DFS(int x, int f){
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i].to;
        if(y==f) continue;
        DFS(y, x);
        cnt[x] += cnt[y];
    }
    // crucial
    ans[ID[x]] = cnt[x];
}

int main(){
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i=1;i<n;i++){
        scanf("%d%d", &a, &b);
        edges[a].push_back({b, i});
        edges[b].push_back({a, i});
    }
    dfs(1, 0, 0);
    for(int j=1;j<=S;j++)
        for(int i=1;i<=n;i++)
            fa[i][j] = fa[ fa[i][j-1] ][j-1];


    for(int i=1;i<=m;i++){
        scanf("%d%d", &a, &b);
        int c = lca(a, b);
        cnt[a]++, cnt[b]++, cnt[c]-=2;
    }

    DFS(1, 0);
    for(int i=1;i<n;i++) printf("%d\n", ans[i]);
    return 0;

}
