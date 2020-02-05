#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 110, M = 15;
int S[N];
int n, m;
char ms[M];
int s[100], tot;
int c[1025];
int dp[N][1025][1025];

int lowbit(int x){
    return x&(-x);
}


int main(){
    scanf("%d%d",&n, &m);
    for(int i=1;i<=n;i++){
        scanf("%s", ms);
        for(int j=0;j<m;j++){
            S[i]|= (ms[j]=='H') <<j;
        }
    }

    for(int i=0;i<1<<m;i++)
        if(!(i&(i<<1)) && !(i&(i<<2))) s[++tot] = i;
    for(int i=1;i<1<<m;i++)
        c[i]  = c[i-lowbit(i)] + 1;

    int ans = 0;
    for(int x=1;x<=n;x++)
        for(int i=1;i<=tot;i++){
            if(s[i]&S[x]) continue;
            for(int j=1;j<=tot;j++){
                if(s[i] & s[j]) continue;
                if(s[j] & S[x-1]) continue;
                for(int k=1;k<=tot;k++){
                    if(s[i]&s[k]) continue;
                    if(s[j]&s[k]) continue;
                    if(x>=2 && s[k]&S[x-2]) continue;
                    dp[x][i][j] = max(dp[x][i][j], dp[x-1][j][k] + c[s[i]]);
                    ans = max(ans, dp[x][i][j]);
                }
            }
        }
    printf("%d\n", ans);
    return 0;
}