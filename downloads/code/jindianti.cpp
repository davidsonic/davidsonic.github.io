#include <iostream>
#include <cstdio>
using namespace std;

const int N = 2010;
double dp[N][N];
int n, t;
double p;

int main(){

    scanf("%d%d%lf", &n, &t, &p);
//    cin>>n>>t>>p;

    for(int i=1;i<=n;i++) dp[0][i] = 0;
    dp[0][0] = 1;
    for(int i=1;i<=t;i++){
        dp[i][0] = dp[i-1][0] * (1-p);
        for(int j=1;j<=(i,n-1);j++) {
            dp[i][j] = dp[i-1][j] * (1-p) + dp[i-1][j-1] * p;
        }
        if(i>=n) dp[i][n] = dp[i-1][n] + dp[i-1][n-1] * p;
    }

    double ans = 0;
    for(int i=1;i<=n;i++)
        ans += dp[t][i] * i;
    printf("%.6lf\n", ans);
    return 0;
}