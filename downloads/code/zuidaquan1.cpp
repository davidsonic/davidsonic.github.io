#include<bits/stdc++.h>
#define M 2005
#define max(x,y) (x)>(y)?(x):(y)
#define S(x) sum[C][x]
using namespace std;
int sum[M][M],stk[M],L[M],R[M];
void check(int &x,int y) {
    if(x<y) x=y;
}
int solve(int C,int n) {
    int top=0;
    S(0)=-2e9,stk[++top]=0;
    for(int i=1; i<=n; i++) {
        while(S(stk[top])>=S(i)) top--;
        L[i]=stk[top];
        stk[++top]=i;
    }
    top=0;
    S(n+1)=-2e9,stk[++top]=n+1;
    for(int i=n; i>=1; i--) {
        while(S(stk[top])>=S(i)) top--;
        R[i]=stk[top];
        stk[++top]=i;
    }
    int ans=-1;
    for(int i=1; i<=n; i++) check(ans,(R[i]-L[i]-1)*S(i));
    return ans;
}
int solve() {
    int n,m;
    scanf("%d%d",&n,&m);
    memset(sum,0,sizeof(sum));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            int x;
            scanf("%d",&x);
            if(x!=0)//算出每个点向上的最大距离
                sum[i][j]=sum[i-1][j]+x;
        }
    int ans=-1;
    for(int i=1; i<=n; i++)
        check(ans,solve(i,m));
//    cerr<<n<<" "<<m<<" "<<ans<<endl;
    printf("%d\n",ans);
    return 0;
}
int main(){
    char in[20]={"zero0.in"};
    char out[20]={"zero0.out"};
    for(int cas=1;cas<=10;cas++){
        freopen(in,"r",stdin);in[4]++;
        freopen(out,"w",stdout);out[4]++;
        solve();
    }
    return 0;
}