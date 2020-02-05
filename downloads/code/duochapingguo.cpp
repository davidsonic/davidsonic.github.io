// Note that m edges rather than m nodes.
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
int dp[N][N];
int tmp[N];
int sz[N];

void dfs(int x, int f){
    for(int i=0;i<edge[x].size();i++){
        int y = edge[x][i].to, val = edge[x][i].val;
        if (y==f) continue;
        dfs(y, x);
        sz[x] += sz[y] + 1;
        memset(tmp, 0, sizeof tmp);
        int mi= min(sz[x], m);
        for(int j=0;j<=mi;j++)
            for(int t=1;t<=j;t++) // t个分给新儿子用,j-t给之前儿子用
                tmp[j] = max(tmp[j], dp[y][t-1] + dp[x][j-t] + val);
        for(int j=1;j<=m;j++) dp[x][j] = max(dp[x][j], tmp[j]);
    }
}


int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n-1;i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[a].push_back((Node){b, c});
        edge[b].push_back((Node){a, c});
    }

    dfs(1, 0);
    printf("%d\n", dp[1][m]);
    return 0;
}

