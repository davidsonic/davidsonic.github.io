#include<bits/stdc++.h>
using namespace std;
#define M 100005
double dp[M];
vector<int>son[M];
double dfs(int n){
    if(dp[n]<0){
        double &res=dp[n];
        int t=son[n].size();
        res=t;
        /*
            dp[n]=sum(dp[son[n][i]])/t+1;

        */
        for(int i=0;i<son[n].size();i++){
            int x=son[n][i];
            if(x==n)continue;
            res+=dfs(x);
        }
        res=res/(t-1);
    }
    return dp[n];
}
int main(){
    for(int i=1;i<M;i++){
        dp[i]=-1;
        for(int j=i;j<M;j+=i)
            son[j].push_back(i);
    }
    dp[1]=0;
    int cas,n,v=1;
    cin>>cas;
    while(cas--){
        scanf("%d",&n);
        printf("%.4f\n",dfs(n));
    }
    return 0;
}