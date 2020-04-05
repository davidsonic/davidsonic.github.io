/*
 区间查询，考虑用线段树
 两个子区间合并时，答案可能是来自三个部分
 （1）左区间
 （2）右区间
 （3）左区间右边的一段 和 右区间左边一段

 需要记录线段树区间左右两个端点向内延伸的最大和，用于合并


 */
#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
struct node {
    int mx;//最大连续和
    int sum;//区间和
    int Lmx;//左端点向右的最大和
    int Rmx;//右端点向左的最大和
} tree[M<<2];
int A[M],n,m,a,b,f;
inline void Max(int &a,int b) {
    if(a<b)a=b;
}
inline void up(node &C,node A,node B) { //[A][B]合并成[C]
    C.sum=A.sum+B.sum;
    C.mx=max(A.mx,B.mx);
    Max(C.mx,A.Rmx+B.Lmx);
    C.Lmx=max(A.Lmx,A.sum+B.Lmx);
    C.Rmx=max(B.Rmx,B.sum+A.Rmx);
}
void build(int l,int r,int p) {
    if(l==r) {
        tree[p].mx=tree[p].Lmx=tree[p].Rmx=tree[p].sum=A[l];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,p<<1);
    build(mid+1,r,p<<1|1);
    up(tree[p],tree[p<<1],tree[p<<1|1]);
}
void update(int L,int R,int a,int x,int p) {
    if(L==R) {
        tree[p].mx=tree[p].Lmx=tree[p].Rmx=tree[p].sum=x;
        return;
    }
    int mid=L+R>>1;
    if(a<=mid)update(L,mid,a,x,p<<1);
    else update(mid+1,R,a,x,p<<1|1);
    up(tree[p],tree[p<<1],tree[p<<1|1]);
}
node query(int L,int R,int l,int r,int p) {
    if(L==l&&R==r)return tree[p];
    int mid=L+R>>1;
    if(r<=mid)return query(L,mid,l,r,p<<1);
    else if(l>mid)return query(mid+1,R,l,r,p<<1|1);
    else {
        node A=query(L,mid,l,mid,p<<1);
        node B=query(mid+1,R,mid+1,r,p<<1|1);
        node C;
        up(C,A,B);
        return C;
    }
}
int main() {
    cin>>n;
    for(int i=1; i<=n; ++i)
        scanf("%d",&A[i]);
    build(1,n,1);
    cin>>m;
    while(m--) {
        scanf("%d %d %d",&f,&a,&b);
        if(f) {
            node tmp=query(1,n,a,b,1);
            printf("%d\n",tmp.mx);
        } else update(1,n,a,b,1);
    }
    return 0;
}