#include <iostream>
using namespace std;

int n;
const int N = 20;
int mp[N][N], dp[N][70000];
int A[30005], tot;

int calc(int x, int y){
    int res =0;
    int j = n;
    while(y){
        if(y&1) res += mp[x][j];
        j--; y>>=1;
    }
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d", &mp[i][j]);


    for(int i=0;i<(1<<n);i++){
        if((i&(i>>1))==0) A[++tot] = i;
    }


//    dp[i][k] = max(dp[i][k], dp[i-1][j] + val(i-1, j))
    for(int i=1;i<=n;i++)
        for(int k=1;k<=tot;k++){
            for(int j=1;j<=tot;j++){
                if((A[j] & A[k]) ==0){
                    int val = calc(i, A[k]);
                    dp[i][k] = max(dp[i][k], dp[i-1][j] + val);
                }
            }
        }

    int ans = 0;
    for(int i=1;i<=tot;i++) ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}