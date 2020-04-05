#include <bits/stdc++.h>
#define MN 20005
#define ll long long
using namespace std;
struct Edge {
    int a,b,x;
    bool operator < (const Edge &m) const {
        return x<m.x;
    }
};
Edge e[100005];
int ufs[MN],siz[MN];
int find(int x) {
    return x==ufs[x]?x:ufs[x]=find(ufs[x]);
}
ll Union(int a,int b) {
    a=find(a);
    b=find(b);
    if(a==b)return 0;
    ll ans=(ll)siz[a]*siz[b];
    siz[a]+=siz[b];
    ufs[b]=a;
    return ans;
}
struct Ques {
    int id,x;
    bool operator < (const Ques &m) const {
        return x<m.x;
    }
};
Ques q[5005];
ll out[5005];
int main() {
    int  n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++) {
        ufs[i]=i;
        siz[i]=1;
    }
    for(int i=1; i<=m; i++)
        scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].x);
    for(int i=1; i<=k; i++)
        scanf("%d",&q[i].x),q[i].id=i;
    sort(e+1,e+1+m);
    sort(q+1,q+1+k);
    ll ans=0;
    for(int i=1,j=1; i<=k; i++) {
        while(j<=m&&e[j].x<=q[i].x) {
            ans+=Union(e[j].a,e[j].b);
            j++;
        }
        out[q[i].id]=ans;
    }
    for(int i=1; i<=k; i++)
        printf("%lld\n",out[i]*2);
    return 0;
}