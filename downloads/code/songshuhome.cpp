#include <iostream>
#include <vector>
using namespace std;

const int N = 300010;
const int S = 20;

int n;
int path[N];

vector<int>edges[N];

int dis[N], dep[N];
int fa[N][S+1];
int cnt[N];
void dfs(int x, int f, int d){
    fa[x][0] = f, dep[x] = dep[f] +1, dis[x] = d;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(y==f) continue;
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
        int y = edges[x][i];
        if(y==f) continue;
        DFS(y, x);
        cnt[x] += cnt[y];
    }
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &path[i]);
    int a, b;
    for(int i=1;i<n;i++){
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1, 0, 0);
    for(int j=1;j<=S;j++)
        for(int i=1;i<=n;i++)
            fa[i][j] = fa[ fa[i][j-1] ][j-1];

//    for(int i=1;i<=n;i++) printf("%d ", fa[i][0]);
//    puts("");
    for(int i=1;i<n;i++){
        a = path[i], b = path[i+1];
        int c = lca(a, b);
//        printf("%d %d %d\n", a, b, c);
        cnt[a]++, cnt[b]++, cnt[c]--, cnt[fa[c][0]]--;
    }

    DFS(1, 0);
    for(int i=2;i<=n;i++) cnt[path[i]]--; //why?
    for(int i=1;i<=n;i++) printf("%d\n", cnt[i]);
    return 0;

}
