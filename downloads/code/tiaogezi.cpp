#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define M 755
#define P 1000000007
using namespace std;
int n,m,k;
int del[M*M];
int c[M][M],dp[M][M];
void CDQ(int L,int R){
    if(L==R)return;
    int mid=(L+R)>>1;
    CDQ(L,mid);
    int sum=0;
    for(int j=2;j<=m;j++){
        for(int k=L;k<=mid;k++){
            sum=(sum+dp[k][j-1])%P;
            del[c[k][j-1]]=(del[c[k][j-1]]+dp[k][j-1])%P;
        }
        for(int k=mid+1;k<=R;k++){
            dp[k][j]=(dp[k][j]+sum)%P;
            dp[k][j]=(dp[k][j]-del[c[k][j]]+P)%P;
        }
    }
    for(int j=1;j<=m;j++)
        for(int k=L;k<=mid;k++)
            del[c[k][j]]=0;
    CDQ(mid+1,R);
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&c[i][j]);
    dp[1][1]=1;
    CDQ(1,n);
    printf("%d\n",dp[n][m]);
    return 0;
}