#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define reg register
#define N 10005
#define M 105
#define P 20140921
using namespace std;
int A[N],B[N],cnt[N];
long long dp[M][N];
int n,m,mx;

void add(int x,int y) {
    while(x<=mx) {
        cnt[x]+=y;
        if(cnt[x]>=P)cnt[x]-=P;
        x+=x&-x;
    }
}
int query(int x) {
    int res=0;
    while(x) {
        res+=cnt[x];
        if(res>=P)res-=P;
        x-=x&-x;
    }
    return res;
}

int main() {
    reg int i,j;
    scanf("%d%d",&n,&m);

    for(i=1; i<=n; i++) {
        scanf("%d",&A[i]);
        dp[1][i]=1;
        B[i]=A[i];
    }
    if(m==1){
        printf("%d\n",n);
        return 0;
    }
    sort(B+1,B+n+1);
    mx=unique(B+1,B+n+1)-B;//去重
    for(i=1; i<=n; i++)A[i]=lower_bound(B+1,B+1+mx,A[i])-B+1;
    for(i=2; i<=m; i++) {
        memset(cnt,0,sizeof cnt);
        for(j=1; j<=n; j++) {
            dp[i][j]=query(A[j]-1);
            if(dp[i-1][j])add(A[j],dp[i-1][j]);
        }
    }
    reg long long ans=0;
    for(j=1; j<=n; j++)
    {
        ans+=dp[m][j];
        if(ans>=P)ans-=P;
    }
    printf("%d\n",ans%P);
    return 0;
}