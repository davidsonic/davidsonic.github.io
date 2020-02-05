#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 20;
int n, m;
int edge[N];
int dp[1<<N], arrive[1<<N];

int main(){
    while(scanf("%d", &n), n!=0){
        memset(dp, 0, sizeof dp);
        memset(arrive, 0, sizeof arrive);
        memset(edge, 0, sizeof edge);

        for(int i=0;i<n;i++){
            scanf("%d", &m);
            edge[i]|=(1<<i);
            int x;
            while(m--)
            {
                scanf("%d", &x);
                edge[i]|= (1<<x);
            }
        }

        for(int i=0;i<1<<n;i++){
            for(int j=0;j<n;j++){
                if(i>>j&1) arrive[i] |= edge[j];
            }
        }

        for(int i=1;i<1<<n;i++){
            int ans = 0;
            for(int j=i;j;j=(j-1)&i){
                if(arrive[j] == (1<<n)-1)
                    ans = max(ans, dp[i^j] + 1);
            }
            dp[i] = ans;
        }
        printf("%d\n", dp[(1<<n)-1]);
    }
    return 0;

}