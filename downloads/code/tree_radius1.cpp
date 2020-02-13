#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
const int M = 100010;
struct Node{
    int to, val;
};

vector<Node>edges[M];

int ans = 0, R=-1;
void dfs(int x, int f, int dis){
    if(dis > ans) {ans = dis, R = x;}
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i].to;
        if(y==f) continue;
        dfs(y, x, dis + edges[x][i].val);
    }
    return;
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n-1;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    dfs(0, -1, 0);
    dfs(R, -1, 0);
    printf("%d\n", ans);
    return 0;
}