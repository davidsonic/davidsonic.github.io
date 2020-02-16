// 每次修改路径，而非一个点, 区别于苹果树，同于找路径
// 要求动态回答询问， 区别于松鼠的新家，路径更新

// Two mistakes from LCA, (1) fa[N][S+2], (2) return after goUp.
#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
const int S = 20;

int fa[N][S+2], dep[N];
int n,m;

int Lid[N], Rid[N], tot;

struct Node{
    int to, id;
};

typedef long long LL;

vector<Node>edges[N];

void dfs(int x, int f){
    Lid[x] = ++tot;
    fa[x][0] = f, dep[x] = dep[f]+ 1;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i].to;
        if(y==f)continue;
        dfs(y, x);
    }
    Rid[x] = tot;
}

void goUp(int &x, int step){
    for(int i=0;i<=S;i++)
        if(step & (1<<i)) x = fa[x][i];
}

int lca(int a, int b){
    if(dep[a] < dep[b]) swap(a,b);
    goUp(a, dep[a]-dep[b]);
    if(a==b ) return a;
    for(int i=S;i>=0;i--)
        if(fa[a][i] != fa[b][i])
            a = fa[a][i], b= fa[b][i];
    return fa[a][0];
}

struct Bit{
    LL C[N];
    void add(int x, int d){
        while(x<=tot){
            C[x] += d;
            x += x&-x;
        }
    }
    LL sum(int x){
        int res = 0;
        while(x){
            res += C[x];
            x -= x&-x;
        }
        return res;
    }
}bit;

int main(){
    scanf("%d%d", &n ,&m);
    int a, b;
    for(int i=1;i<n;i++){
        scanf("%d%d", &a, &b);
        edges[a].push_back({b, i});
        edges[b].push_back({a, i});
    }

    dfs(1, 0);
    for(int j=1;j<=S;j++)
        for(int i=1;i<=n;i++) fa[i][j] = fa[ fa[i][j-1] ][j-1];

    int x, y, d;
    for(int i=1;i<=m;i++){
        scanf("%d", &a);
        if(a==1){
            scanf("%d%d%d", &x ,&y, &d);
            int c = lca(x, y);
//            printf("lca = %d %d %d\n", x, y, c);
            int e = fa[c][0];
            bit.add(Lid[x], d);
            bit.add(Lid[y], d);
            bit.add(Lid[c], -d);
            if(e)bit.add(Lid[e], -d); // if is crucial!
        }
        else{
            scanf("%d", &x);
            printf("%lld\n", bit.sum(Rid[x]) - bit.sum(Lid[x] -1));
        }
    }
    return 0;

}
