#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 100010;
int A[N];
int fa[N];
// corresponding value from i to root
int V[N], Mx[N], Mi[N];
int ans[N];

int n, m;

struct Node{
    int L, id;
};
vector<Node>query[N];


int getfa(int x){
    if(fa[x] != x) {
        int t = fa[x];
        // finish calc of father's Mi[t], V[t], Mx[t]
        fa[x] = getfa(t);
        // x--> t --> fa[x]
        V[x] = max(V[x], max(V[t], Mx[t] - Mi[x]));
        Mi[x] = min(Mi[x], Mi[t]);
        Mx[x] = max(Mx[x], Mx[t]);
    }
    return fa[x];
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &A[i]);
        fa[i] = i;
        Mi[i] = Mx[i] = A[i];
        V[i] = 0;
    }

    for(int i=1;i<=m;i++){
        int L, R;
        scanf("%d%d", &L, &R);
        query[R].push_back((Node){L, i});
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<query[i].size();j++){
            int L = query[i][j].L;  //[L, i]
            getfa(L);
            ans[query[i][j].id] = V[L];
        }
        fa[i] = i+1;
    }

    for(int i=1;i<=m;i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}