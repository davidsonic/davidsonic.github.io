#include<bits/stdc++.h>
#define M 30005
using namespace std;
struct node{
    int L,R;
    vector<int>num;
}tree[M<<2];
int A[M],s[M];
void build(int L,int R,int p){
    tree[p].L=L,tree[p].R=R;
    tree[p].num.clear();
    if(L==R){
        tree[p].num.push_back(A[L]);
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,p<<1);
    build(mid+1,R,p<<1|1);
    tree[p].num.resize(R-L+1);//****
    merge(tree[p<<1].num.begin(),tree[p<<1].num.end(),
          tree[p<<1|1].num.begin(),tree[p<<1|1].num.end(),
          tree[p].num.begin());
}
int query(int L,int R,int x,int p){
    if(L==tree[p].L&&R==tree[p].R){
        return upper_bound(tree[p].num.begin(),tree[p].num.end(),x)-tree[p].num.begin();
    }
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)return query(L,R,x,p<<1);
    else if(L>mid)return query(L,R,x,p<<1|1);
    else{
        return query(L,mid,x,p<<1)+query(mid+1,R,x,p<<1|1);
    }
}
int main(){
    freopen("kth.in","r",stdin);
    freopen("my.out","w",stdout);
    int n,m,a,b,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        s[i-1]=A[i];
    }
    sort(s,s+n);
    build(1,n,1);

    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        int L=0,R=n-1,res;
        while(L<=R){
            int mid=(L+R)>>1;
            int tmp=query(a,b,s[mid],1);
            if(tmp>=c){
                R=mid-1;res=s[mid];
            }else L=mid+1;
        }
        printf("%d\n",res);
    }
    return 0;
}