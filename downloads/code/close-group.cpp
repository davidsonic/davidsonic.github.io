#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 18, INF = 0x3f3f3f3f;
bool valid[1<<N];
bool adj[N][N];
int dp[1<<N];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a][b] = adj[b][a] = 1;
    }

    for(int i=1;i<1<<n;i++){
        vector<int> vec;
        for(int j=0;j<n;j++){
            if(i>>j&1) vec.push_back(j);
        }
        bool flag = true;
        for(int u=0;u<vec.size();u++) {
            for (int v = u + 1; v < vec.size(); v++) {
                if (!adj[vec[u]][vec[v]]) { //error
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag) valid[i] = true;
    }
    memset(dp, INF, sizeof dp);
    for(int i=1;i<1<<n;i++){
        if(valid[i]) dp[i] = 1;
        else {
            for (int j = i; j; j = (j - 1) & i) {
                dp[i] = min(dp[i], dp[j] + dp[i^j]);
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}