//70%
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 110;
int n, m;

struct Node{
    int to, val;
};
vector<Node> edge[N];
int ch[N][2];
int dp[N][N];
int val[N];

void dfs(int x, int f){
    int k=0;
    for(int i=0;i<edge[x].size();i++){
        int y = edge[x][i].to;
        if(y!=f){
            dfs(y, x);
            val[y] = edge[x][i].val;
            ch[x][k++] = y;
        }
    }
//    printf("%d %d\n", x, k);
}

void DP(int x){
    int ls = ch[x][0];
    int rs = ch[x][1];
    if(ls==0 && rs==0){
        for(int i=1;i<=m;i++) dp[x][i] = val[x];
        return;
    }
    if(ls!=0 && rs!=0) {
        DP(ls);
        DP(rs);
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j + 1 <= i; j++)
                dp[x][i] = max(dp[x][i], dp[ls][j] + dp[rs][i - j - 1] + val[x]);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m); m++;
    for(int i=1;i<=n-1;i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    dfs(1, 0);
    DP(1);
    printf("%d\n", dp[1][m]);
    return 0;
}

