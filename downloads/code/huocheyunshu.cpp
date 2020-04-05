#include<stdio.h>
#include<string.h>
#include<vector>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#define M 100005
#define oo 2000000000
using namespace std;
struct node{
    int x,y,z;
}s[M];
struct Query{
    int x,id,next;
}query[M*10];
void Rd(int &res){
    char c;res=0;
    while(c=getchar(),!isdigit(c));
    do{
        res=(res<<3)+(res<<1)+(c^48);
    }while(c=getchar(),isdigit(c));
}
int fa[M],ans[M];
int qcnt[M],head[M],tot=0;
int get(int v){
    if(fa[v]!=v)
        fa[v]=get(fa[v]);
    return fa[v];
}
bool cmp(node A,node B){
    return A.z>B.z;
}
void check(int &x,int y){
    if(x<y)x=y;
}
void add(int a,int b,int c){
    qcnt[a]++;
    query[tot].x=b,query[tot].id=c,query[tot].next=head[a],head[a]=tot++;
}
int main(){
    int n,m,q,x,y,i,j;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)fa[i]=i;
    for(i=0;i<m;i++){
        Rd(s[i].x);Rd(s[i].y);Rd(s[i].z);
    }
    sort(s,s+m,cmp);
    Rd(q);
    memset(head,-1,sizeof(head));
    for(i=0;i<q;i++){
        Rd(x);Rd(y);
        add(x,y,i);add(y,x,i); ans[i]=-1;
    }
    for(i=0;i<m;i++){
        x=s[i].x,y=s[i].y;
        int fx=get(x),fy=get(y);
        if(fx==fy)continue;
        if(qcnt[fx]>qcnt[fy])swap(fx,fy);
        fa[fx]=fy;
        for(j=head[fx];j!=-1;j=query[j].next){
            if(get(query[j].x)==fy)check(ans[query[j].id],s[i].z);
            else add(fy,query[j].x,query[j].id);
        }
    }
    for(i=0;i<q;i++)printf("%d\n",ans[i]);
    return 0;
}