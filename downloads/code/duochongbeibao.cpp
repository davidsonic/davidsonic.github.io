#include<bits/stdc++.h>
#define M 100005
using namespace std;
int dp[M],A[M];
int main(){
        int V,m,v,c,k;
        scanf("%d %d",&V,&m);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            scanf("%d %d %d",&k,&v,&c);
            if(k*v>=V){
                for(int j=v;j<=V;j++)//完全背包
                    dp[j]=max(dp[j],dp[j-v]+c);
            }else{
                int n=0;
                for(int j=1;j<=k;j<<=1){
                    A[n++]=j;k-=j;
                }
                if(k)A[n++]=k;
                for(int a=0;a<n;a++){//01背包
                    for(int b=V;b>=A[a]*v;b--)
                        dp[b]=max(dp[b],dp[b-v*A[a]]+c*A[a]);
                }
            }
        }
        printf("%d\n",dp[V]);
    return 0;
}