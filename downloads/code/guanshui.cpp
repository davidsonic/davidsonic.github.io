#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 310;
int fa[N];

struct Edge{
    int a, b, v;
}edges[N*N];

int n;
int tot;
int find(int x){
    if(x==fa[x]) return x;
    return fa[x] = find(fa[x]);
}

bool cmp(Edge &a, Edge&b){
    return a.v < b.v;
}

int main(){
    scanf("%d", &n);
    int val;

    for(int i=1;i<=n;i++){
        scanf("%d", &val);
        edges[++tot].a = 0, edges[tot].b = i, edges[tot].v = val;
    }

    for(int i=1;i<n;i++)
        for(int j=1;j<=n;j++){
            scanf("%d", &val);
            if(i<j)
                edges[++tot].a= i, edges[tot].b = j, edges[tot].v = val;
        }


    for(int i=0;i<=n;i++) fa[i] = i;
    int ans = 0;
    sort(edges+1, edges+tot+1, cmp);
    for(int i=1;i<=tot;i++){
        int a = find(edges[i].a);
        int b = find(edges[i].b);
        if(a!=b) fa[a] = b, ans += edges[i].v;
    }

    printf("%d\n", ans);
    return 0;

}