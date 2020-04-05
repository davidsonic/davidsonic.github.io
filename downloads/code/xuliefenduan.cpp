#include<stdio.h>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
#define lson l,m,rt*2
#define rson m+1,r,rt*2+1
int tree[350050*8];
int flag[350050*8];
int a[350050];
int last[350050];
int dp[350050];
int n,k;
void build(int l,int r,int rt) {
    flag[rt]=0;
    if(l==r) {
        tree[rt]=dp[l];
        flag[rt]=0;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void pushdown(int l,int r,int rt) { //向下维护树内数据
    if(flag[rt]) { //如果贪婪标记不是0（说明需要向下进行覆盖区间（或点）的值）
        int m=(l+r)/2;
        flag[rt*2]+=flag[rt];
        flag[rt*2+1]+=flag[rt];
        tree[rt*2]+=flag[rt];//千万理解如何覆盖的区间值（对应线段树的图片理解（m-l）+1）是什么意识.
        tree[rt*2+1]+=flag[rt];
        flag[rt]=0;
    }
}
void pushup(int rt) {
    tree[rt]=max(tree[rt<<1],tree[rt<<1|1]);
}
int Query(int L,int R,int l,int r,int rt) {
    if(L<=l&&r<=R) {
        return tree[rt];
    } else {
        pushdown(l,r,rt);
        int m=(l+r)>>1;
        int ans=0;
        if(L<=m) {
            ans=max(ans,Query(L,R,lson));
        }
        if(m<R) {
            ans=max(ans,Query(L,R,rson));
        }
        pushup(rt);
        return ans;
    }
}
void update(int L,int R,int c,int l,int r,int rt) {
    if(L<=l&&r<=R) { //覆盖的是区间~
        tree[rt]+=c;//覆盖当前点的值
        flag[rt]+=c;//同时懒惰标记~！
        return ;
    }
    pushdown(l,r,rt);
    int m=(l+r)/2;
    if(L<=m) {
        update(L,R,c,lson);
    }
    if(m<R) {
        update(L,R,c,rson);
    }
    pushup(rt);
}
int solve() {
    scanf("%d%d",&n,&k);
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=n; i++)scanf("%d",&a[i]);
    for(int i=1; i<=k; i++) {
        build(0,n,1);
        for(int j=1; j<=n; j++)dp[j]=0,last[a[j]]=0;
        for(int j=1; j<=n; j++) {
            update(last[a[j]],j-1,1,0,n,1);
            last[a[j]]=j;
            dp[j]=Query(0,j-1,0,n,1);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
int main(){
    char in[20]={"sub0.in"};
    char out[20]={"sub0.out"};
    for(int cas=0;cas<10;cas++){
        freopen(in,"r",stdin);in[3]++;
        freopen(out,"w",stdout);out[3]++;
        solve();
    }
    return 0;
}