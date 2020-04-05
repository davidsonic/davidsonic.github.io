#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#define M 30005
using namespace std;
struct node{
    int L,R,sum,mx;
}tree[M<<2];
vector<int>edge[M];
int val[M],A[M],dep[M];
int sz[M];//子树大小
int pathfa[M];//虚边，用于跳向上一条重链
int root[M];//所在重链的根节点
int sonID[M];//重儿子编号
int segID[M];//在线段树上的编号
int sT=0;//线段树编号
int qsum,qmx;
void Assign(int x,int f,int d){//分配重儿子
    sz[x]=1;int k=-1; dep[x]=d;
    for(int i=0;i<edge[x].size();i++){
        int y=edge[x][i];
        if(y==f)continue;
        Assign(y,x,d+1);
        if(k==-1||sz[y]>sz[k])k=y;
        sz[x]+=sz[y];
    }
    sonID[x]=k;
}
void Dfs(int x,int f,int pf){//分配线段树编号
    root[x]=f;pathfa[x]=pf;segID[x]=++sT;A[sT]=val[x];
    if(sonID[x]!=-1)Dfs(sonID[x],f,pf);
    for(int i=0;i<edge[x].size();i++){
        int y=edge[x][i];
        if(sonID[x]==y||sz[x]<sz[y])continue;//儿子节点和反向边
        Dfs(y,y,x);
    }
}
void Up(int p){
    tree[p].sum=tree[2*p].sum+tree[2*p+1].sum;
    tree[p].mx=max(tree[2*p].mx,tree[2*p+1].mx);
}
void build(int L,int R,int p){
    tree[p].L=L,tree[p].R=R;
    if(L==R){
        tree[p].sum=tree[p].mx=A[L];return;
    }
    int mid=(L+R)>>1;
    build(L,mid,2*p);build(mid+1,R,2*p+1);
    Up(p);
}
void update(int a,int x,int p){
    if(tree[p].L==tree[p].R){
        tree[p].mx=tree[p].sum=x;
        return;
    }
    int mid=(tree[p].L+tree[p].R)>>1;
    if(a<=mid)update(a,x,2*p);
    else update(a,x,2*p+1);
    Up(p);
}
void query(int L,int R,int p){
    if(tree[p].L==L&&tree[p].R==R){
        qsum+=tree[p].sum,qmx=max(qmx,tree[p].mx);
        return;
    }
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)query(L,R,2*p);
    else if(L>mid)query(L,R,2*p+1);
    else {
        query(L,mid,2*p);query(mid+1,R,2*p+1);
    }
}
void Query(int a,int b){
    while(root[a]!=root[b]){
        if(dep[root[a]]<dep[root[b]])swap(a,b);
        query(segID[root[a]],segID[a],1);
        a=pathfa[a];//跳到上一条重链
    }
    if(dep[a]<dep[b])swap(a,b);
    query(segID[b],segID[a],1);
}
int main(){
    int n,m,i,j,k,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for(i=1;i<=n;i++) scanf("%d",&val[i]);
    Assign(1,0,1);
    Dfs(1,1,0);
    build(1,n,1);
    scanf("%d",&m);
    char tmp[20];
    for(i=0;i<m;i++){
        scanf("%s%d%d",tmp,&a,&b);
        if(tmp[0]=='C'){
            update(segID[a],b,1);
        }else{
            qsum=0,qmx=-10000000;
            Query(a,b);
            if(tmp[1]=='S')printf("%d\n",qsum);
            else printf("%d\n",qmx);
        }
    }
    return 0;
}