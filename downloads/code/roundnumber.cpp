#include<stdio.h>
#include<string.h>
#include<iostream>
#define LL long long
using namespace std;
int dp[35][2][70];
int num[40],len;
int Abs(int x){ return x>0?x:-x; }
int dfs(int pos,bool lead0,int cha,bool limit){
    if(pos==0)return cha>=0;
    if(!limit&&~dp[pos][lead0][cha+35])return dp[pos][lead0][cha+35];
    int up=limit?num[pos]:1;
    int cnt=0;
    for(int i=0;i<=up;i++){
        if(lead0){
            if(i==0)cnt+=dfs(pos-1,1,cha,limit&&i==up);
            else cnt+=dfs(pos-1,0,cha-1,limit&&i==up);
        }else{
            int k=(i==0)?1:-1;
            cnt+=dfs(pos-1,0,cha+k,limit&&i==up);
        }
    }
    return limit?cnt:dp[pos][lead0][cha+35]=cnt;
}
int solve(int n){
    len=0;
    while(n){
        num[++len]=n%2;
        n/=2;
    }
    memset(dp,-1,sizeof(dp));
    return dfs(len,1,0,1);
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",solve(b)-solve(a-1));
    return 0;
}