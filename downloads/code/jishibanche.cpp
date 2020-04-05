/*
 按照下车地点从小到大排序之后，早下车的一定要优先选取
 每次决策，先算出当前区间上车子最多有多少乘客
 那么剩下的位置安排给当前这批
 用线段树维护每个点车上的乘客数
 需要支持区间最值 和 区间加值
 */
#include<bits/stdc++.h>
#define M 10005
#define N 50005
using namespace std;
struct node {
    int s,e,m;
} A[N];
bool cmp(node w1,node w2) {
    return w1.e<w2.e;
}
struct Node {
    int L,R,mx,add;
} tree[M<<2];
void up(int p) {
    tree[p].mx=max(tree[p<<1].mx,tree[p<<1|1].mx);
}
void down(int p) {
    if(!tree[p].add)return;
    tree[p<<1].add+=tree[p].add;
    tree[p<<1].mx+=tree[p].add;
    tree[p<<1|1].add+=tree[p].add;
    tree[p<<1|1].mx+=tree[p].add;
    tree[p].add=0;
}
void build(int L,int R,int p) {
    tree[p].L=L,tree[p].R=R,tree[p].mx=0,tree[p].add=0;
    if(L==R)return;
    int mid=(L+R)>>1;
    build(L,mid,p<<1);
    build(mid+1,R,p<<1|1);
}
void update(int L,int R,int p,int a) {
    if(tree[p].L==L&&tree[p].R==R) {
        tree[p].mx+=a;
        tree[p].add+=a;
        return;
    }
    down(p);
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)update(L,R,p<<1,a);
    else if(L>mid)update(L,R,p<<1|1,a);
    else update(L,mid,p<<1,a),update(mid+1,R,p<<1|1,a);
    up(p);
}
int query(int L,int R,int p) {
    if(tree[p].L==L&&tree[p].R==R)return tree[p].mx;
    down(p);
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)return query(L,R,p<<1);
    if(L>mid)return query(L,R,p<<1|1);
    return max(query(L,mid,p<<1),query(mid+1,R,p<<1|1));
}
int main() {
    int k,n,c,ans=0;
    scanf("%d%d%d",&k,&n,&c);
    for(int i=1;i<=k;i++)
        scanf("%d%d%d",&A[i].s,&A[i].e,&A[i].m);
    sort(A+1,A+1+k,cmp);
    build(1,n,1);
    for(int i=1;i<=k;i++) {
        int mx=query(A[i].s,A[i].e-1,1);
        mx=max(c-mx,0);
        mx=min(mx,A[i].m);
        update(A[i].s,A[i].e-1,1,mx);
        ans+=mx;
    }
    printf("%d\n",ans);
    return 0;
}