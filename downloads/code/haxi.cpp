#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL num[5000005],ans;
LL P=1000000000000037LL,T;
string a,b,c;
int all,n,m,tot;
void dfs(int x,LL p){
    if(x==n){
        num[tot]=p;
        for(int i=0;i<m;i++)num[tot]=(num[tot]*127)%P;
        tot++;
        return;
    }
    dfs(x+1,(p*127+a[x])%P);
    dfs(x+1,(p*127+b[x])%P);
    dfs(x+1,(p*127+c[x])%P);
}
void DFS(int x,LL p){
    if(x==all){
        LL tmp=(num[0]+p)%P;
        ans=min(ans,tmp);
        int k=lower_bound(num,num+tot,P-p)-num;
        if(k!=tot)ans=min(ans,(num[k]+p)%P);
        return;
    }
    DFS(x+1,(p*127+a[x])%P);
    DFS(x+1,(p*127+b[x])%P);
    DFS(x+1,(p*127+c[x])%P);
}
int main() {
        int N;string A,B,C;
        cin>>N>>A>>B>>C;
        n=N/2;all=N;
        m=N-n;
        tot=0;
        a=A;b=B;c=C;
        dfs(0,0);
        sort(num,num+tot);
        ans=P;
        DFS(n,0);
        cout<< ans <<endl;
};