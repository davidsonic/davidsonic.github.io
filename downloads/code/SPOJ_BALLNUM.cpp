#include<bits/stdc++.h>
using namespace std;
#define uLL unsigned long long
uLL dp[21][1025][1025];
int num[21];
bool mark[1025][1025];
bool check(int mask,int x){
    if(!mask)return 0;
    for(int i=0;i<10;i++)
        if(mask&(1<<i)){
            if(((x&(1<<i))>0)==(i&1))return 0;
        }
    return 1;
}
void Init(){
    for(int i=0;i<1024;i++){
         for(int j=0;j<1024;j++)
             mark[i][j]=check(i,j);
    }
}
uLL dfs(int pos,int mask,int x,bool limit){
    if(pos==0)return mark[mask][x];
    if(!limit&&~dp[pos][mask][x])return dp[pos][mask][x];
    int up=limit?num[pos]:9;
    uLL cnt=0;
    for(int i=0;i<=up;i++){
        if(!mask&&!i)cnt+=dfs(pos-1,mask,x,limit&&(i==up));
        else cnt+=dfs(pos-1,mask|(1<<i),x^(1<<i),limit&&(i==up));
    }
    return limit?cnt:dp[pos][mask][x]=cnt;
}
uLL solve(uLL n){
    if(n==0)return 0;
    int len=0;
    while(n){
        num[++len]=n%10;
        n/=10;
    }
    return dfs(len,0,0,1);
}
int main(){
    Init();
    int cas;
    memset(dp,-1,sizeof(dp));
    cin>>cas;
    uLL L,R;
    while(cas--){
        cin>>L>>R;
        cout<<solve(R)-solve(L-1)<<endl;
    }
    return 0;
}