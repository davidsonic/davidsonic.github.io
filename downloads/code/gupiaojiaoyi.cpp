#include<bits/stdc++.h>
#define M 2005
using namespace std;
struct node{
    int ap,bp,as,bs;
}A[M];
int dp[M][M];
int INF;
struct Node{
    int v,id;
}Q[M];
int main(){
    int n,m,W;
    cin>>n>>m>>W;
    for(int i=1;i<=n;i++){
        cin>>A[i].ap>>A[i].bp>>A[i].as>>A[i].bs;
    }
    memset(dp,-127,sizeof(dp));
    for(int i=1;i<=W+1;i++){
        for(int j=0;j<=m;j++){
            if(j<=A[i].as)dp[i][j]=-j*A[i].ap;
            if(i>1)dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }
    }
    for(int i=W+2;i<=n;i++){
        int ii=i-W-1;
        int L=0,R=-1;
        for(int j=m;j>=0;j--){//卖
            Node tmp;
            tmp.v=dp[ii][j]+j*A[i].bp;  tmp.id=j;
            while(L<=R&&Q[R].v<=tmp.v)R--;
            Q[++R]=tmp;
            while(L<=R&&Q[L].id-j>A[i].bs)L++;
            dp[i][j]=Q[L].v-j*A[i].bp;
        }
        L=0,R=-1;
        for(int j=0;j<=m;j++){//买
            Node tmp;
            tmp.v=dp[ii][j]+j*A[i].ap;   tmp.id=j;
            while(L<=R&&Q[R].v<=tmp.v)R--;
            Q[++R]=tmp;
            while(L<=R&&j-Q[L].id>A[i].as)L++;
            dp[i][j]=max(dp[i][j],Q[L].v-j*A[i].ap);
        }
        for(int j=0;j<=m;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        //  printf("%d %d %d\n",i,j,dp[i][j]);
        }
        /*
        for(int j=0;j<=m;j++){
            {
                for(int jj=j;jj<=min(j+A[i].bs,m);jj++)//卖
                    dp[i][j]=max(dp[i][j],dp[ii][jj]+jj*A[i].bp)-j*A[i].bp);


                for(int jj=j;jj>=max(0,j-A[i].as);jj--)//买
                    dp[i][j]=max(dp[i][j],dp[ii][jj]+jj*A[i].ap)-j*A[i].ap);
            }
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
        }*/
    }
    int ans=0;
    for(int j=0;j<=m;j++)ans=max(ans,dp[n][j]);
    printf("%d\n",ans);
    return 0;
}