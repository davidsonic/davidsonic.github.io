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

int ans = 0;
int dfs(int x, int f){
    int fir = 0, sec = 0;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i].to;
        if(y==f) continue;
        int t= dfs(y, x) + edges[x][i].val;
        if(t >fir){
            sec = fir;
            fir = t;
        }
        else if(t > sec)
            sec = t;
    }
    ans = max(ans, fir+sec);
    return fir;
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n-1;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    dfs(0, -1);
    printf("%d\n", ans);
    return 0;
}