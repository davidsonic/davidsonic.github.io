#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100010, S = 17;
int n,m;

int fa[N][S+2]; //crucial!

struct Node {
    int to, val;
};

vector<Node> edges[N];
int dep[N], dis[N];

//f can't be -1, because of dep[f];
void dfs(int x, int f, int d){
    fa[x][0] = f, dep[x] = dep[f] + 1, dis[x] = d;
    for(int i=0; i< edges[x].size();i++){
        int j = edges[x][i].to;
        if(j==f) continue;
        dfs(j, x, d + edges[x][i].val);
    }
}

void goUp(int &x, int step){
    for(int i=0;i<=S;i++)
        if(step & (1<<i)) x = fa[x][i];
}


int LCA(int a, int b){
    if(dep[a]<dep[b]) swap(a, b);
    goUp(a, dep[a] - dep[b]);
    if(a==b) return a;
    for(int i=S;i>=0;i--){
        if(fa[a][i] != fa[b][i]){
            a = fa[a][i];  b = fa[b][i];
        }
    }
    return fa[a][0];
}

int main(){
    scanf("%d%d", &n, &m);
    int a, b, c;
    for(int i=1;i<n;i++){
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back((Node){b, c});
        edges[b].push_back((Node){a, c});
    }

    dfs(1, 0, 0);

    for(int j=1;j<=S;j++){
        for(int i=1;i<=n;i++)
            fa[i][j] = fa[ fa[i][j-1] ][j-1];
    }

    while(m--){
        scanf("%d%d", &a, &b);
        int c = LCA(a, b);
        printf("%d\n", dis[a] + dis[b] - 2*dis[c]);
    }
    return 0;
}

