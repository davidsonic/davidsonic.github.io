#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,f[1000009],n,m;
const int p=1e9+7;
ll fast(ll x,int b){
    ll res=1;
    while(b>0){
        if(b&1)res=res*x%p,res%=p;
        x=x*x%p,x%=p;
        b/=2;
    }
    return res;
}
int main(){
    f[0]=1;
    for(int i=1;i<=1000000;i++)f[i]=(f[i-1]%p*i)%p;
    char in[20]={"data0.in"};
    char out[20]={"data0.out"};
    for(int cas=1;cas<=10;cas++){
        freopen(in,"r",stdin);in[4]++;
        freopen(out,"w",stdout);out[4]++;

        scanf("%d %d",&n,&m);
        //cerr<<n<<" "<<m<<endl;
        // 除法转为逆元+费马小定理
        printf("%lld\n",f[n]%p*fast(f[m],p-2)%p*fast(f[n-m],p-2)%p);
    }
    return 0;
}