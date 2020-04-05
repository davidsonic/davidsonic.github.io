#include<cstdio>
#include<algorithm>
using namespace std;
struct P{
    int l,to;
}e[50005],E[50005];
int n,m,sk[10005],tp,d[10005],l[10005],b[10005],t,nu,h[10005],x,y,H[10005],s,u;
bool v[10005],is[10005];
void se(int x){
    d[x]=l[x]=++t;sk[++tp]=x;is[x]=1;
    for(int i=h[x];i;i=e[i].l){
        if(!d[e[i].to]){
            se(e[i].to);
            l[x]=min(l[x],l[e[i].to]);
        }
        else if(is[e[i].to])l[x]=min(l[x],l[e[i].to]);
    }
    if(l[x]==d[x]){
        ++nu;
        do{
            y=sk[tp--];
            b[y]=nu;
            is[y]=0;
        }while(y!=x);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d %d",&x,&e[i].to);
        e[i].l=h[x];h[x]=i;
    }
    for(int i=1;i<=n;++i){
        if(!d[i])se(i);
    }
    for(int i=1;i<=n;++i){
        x=b[i];
        for(int o=h[i];o;o=e[o].l){
            y=b[e[o].to];
            if(x!=y)v[x]=1;
        }
//      printf("%d %d %d\n",i,x,v[x]);
    }
    for(int i=1;i<=nu;++i){
        if(!v[i])s++,u=i;
    }
    if(s!=1)printf("0\n");
    else {
        s--;
        for(int i=1;i<=n;++i)if(b[i]==u)s++;
        printf("%d\n",s);
    }
}