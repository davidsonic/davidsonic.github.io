#include<stdio.h>
#define M 51
#define P 1000000007
int F2[M],Ft[M],F[M];
int Fast(int x,int n) {
    int res=1;
    while(n>0) {
        if(n&1)res=(1LL*res*x)%P;
        x=(1LL*x*x)%P;
        n>>=1;
    }
    return res;
}
void Init() {
    F2[0]=1;
    F[0]=1;
    for(int i=1; i<M; i++) {
        F2[i]=F2[i-1]*2%P;
        F[i]=1LL*F[i-1]*i%P;
    }
    Ft[M-1]=Fast(F[M-1],P-2);//Ft[i]= i!^-1
    for(int i=M-2; i>=0; i--) {
        Ft[i]=1LL*(i+1)*Ft[i+1]%P;
    }
}
void Add(int &x,int y) {
    x+=y;
    if(x>=P)x-=P;
    if(x<0)x+=P;
}
void solve() {
    int n,m;
    scanf("%d %d",&n,&m);
    int ans=0;
    for(int i=0; i<m; i++) {
        int tmp=1LL*F[m]*Ft[m-i]%P*Ft[i]%P*Fast(F2[m-i]-1,n)%P;
        if(i&1)tmp=-tmp;
        Add(ans,tmp);
    }
    printf("%d\n",ans);
}
int main() {
    Init();
    solve();
    return 0;
}