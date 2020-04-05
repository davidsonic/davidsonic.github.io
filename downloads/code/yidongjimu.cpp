#include<iostream>
#include<stdio.h>
#define M 30005
using namespace std;
int m;
int p[M],dis[M];//cnt里为最终答案
int sz[M];
char S[5];
int find(int x) {
    if(p[x]!=x) {
        int t=find(p[x]);
        dis[x]+=dis[p[x]];
        p[x]=t;
        return t;
    }
    return x;
}
int main() {
    //a移至b上与b移至a下相同
    scanf("%d",&m);
    for(int i=1; i<=M-5; i++)p[i]=i,dis[i]=0,sz[i]=1;
    for(int i=1,x,y; i<=m; i++) {
        scanf("%s",S);
        if(S[0]=='M') {
            scanf("%d%d",&x,&y);
            int r1=find(x),r2=find(y);
            if(r1!=r2) {
                p[r1]=r2;
                dis[r1]+=sz[r2];
                sz[r2]+=sz[r1];
                sz[r1]=0;
            }
        } else {
            scanf("%d",&x);
            int r=find(x);
            printf("%d\n",dis[x]);
        }
    }
    return 0;
}