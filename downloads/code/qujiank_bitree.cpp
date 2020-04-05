#include<bits/stdc++.h>
#define M 30005
#define lowbit(x) (x&(-x))
using namespace std;
int A[M],B[M],S,num[M],C[M],V,ans[M],n;
struct node{
    int a,b,c,l,r,mid,res,id;
}query[M];
struct Num{
    int id,x;
}G[M];
bool cmp(node a,node b){
    return a.mid<b.mid;
}
bool cmp1(Num a,Num b){
    return a.x<b.x;
}
void Add(int x){
    if(x==0)return;
    while(x<=n){
        C[x]++;x+=lowbit(x);
    }
}
int Get(int x){
    int res=0;
    while(x>0){
        res+=C[x];
        x-=lowbit(x);
    }
    return res;
}
int main(){
    freopen("kth.in","r",stdin);
    freopen("my.out","w",stdout);
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        num[i]=A[i];
    }
    sort(num,num+n);
    V=unique(num,num+n)-num;
    for(int i=0;i<n;i++){
        A[i]=lower_bound(num,num+V,A[i])-num;
        G[i].id=i+1,G[i].x=A[i];
    }
    sort(G,G+n,cmp1);
    int a,b,c;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        query[i]=(node){a,b,c,0,V-1,(V-1)>>1,-1,i};
    }
    for(int i=0;i<15;i++){
        sort(query,query+m,cmp);

        int k=0;
        for(int j=1;j<=n;j++)C[j]=0;
        for(int j=0;j<m;j++){
            if(query[j].l>query[j].r)continue;
            while(k<n&&G[k].x<=query[j].mid){
                Add(G[k++].id);
            }
            int tmp=Get(query[j].b)-Get(query[j].a-1);
            if(tmp>=query[j].c){
                query[j].res=query[j].mid;
                query[j].r=query[j].mid-1;
            }else{
                query[j].l=query[j].mid+1;
            }
            query[j].mid=query[j].l+query[j].r>>1;
        }
    }
    for(int i=0;i<m;i++)ans[query[i].id]=num[query[i].res];
    for(int i=0;i<m;i++)printf("%d\n",ans[i]);
    return 0;
}