/*
 环的问题一般把序列变成两倍
 预处理出前缀和
 枚举右端点i，sum[i]-sum[x]最大，x需要在某个范围内sum[x]最小，使用单调队列
 */
#include<bits/stdc++.h>
#define M 200005
using namespace std;
int q[M],sum[M];
int main() {
    int n,k,l=1,r=1,ans=-2e9,al,ar;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) {
        scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];
    }
    for(int i=n+1; i<n+k; i++)sum[i]=sum[n]+sum[i-n];
    q[r]=0;
    for(int i=1; i<n+k; i++) {
        while(r>=l&&i-q[l]>k)l++;
        if(r>=l&&ans<sum[i]-sum[q[l]]) {
            ans=sum[i]-sum[q[l]];
        }
        while(r>=l&&sum[q[r]]>=sum[i])r--;
        q[++r]=i;
    }
    printf("%d\n",ans);
    return 0;
}