#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> A(n+1);
    for(int i=1;i<=n;i++) scanf("%d", &A[i]);
    vector<int>g[n+1];
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d", &a, &b );
        // reverse edges
        g[b].push_back(a);
    }

    // lowest price reachable from i, sell at point i
    vector<LL> dp(n+1, INF);
    LL res = -INF;
    for(int i=1;i<=n;i++){
        for(int x:g[i]){
            dp[i] = min(dp[i], dp[x]);
        }
        if(dp[i] < INF) res = max(res, (LL)A[i] - dp[i]);
        dp[i] = min(dp[i], (LL)A[i]);
    }
    cout<<res<<endl;
    return 0;
}