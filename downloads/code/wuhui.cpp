#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 200010;
int a[N];
int n;
vector<int> edge[N];
int cnt[N];
int dp[N][2];

void dfs(int x){
    for(int i=0;i<edge[x].size();i++){
        int y = edge[x][i];
        dfs(y);
        dp[x][1] += dp[y][0];
        dp[x][0] += max(dp[y][0], dp[y][1]);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &dp[i][1]);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edge[a].push_back(b);
        cnt[b]++;
    }
    int t = 0;
    for (int i = 1; i <=n; i++)
        if (!cnt[i]) {
            t = i;
            break;
        }
    dfs(t);
    printf("%d\n", max(dp[t][0], dp[t][1]));
    return 0;
}
