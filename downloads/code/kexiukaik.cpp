#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#define M 305
using namespace std;
int A[M*M],sz[M],K;
struct node {
    int id,num;
    void set(int _id,int _num) {
        id=_id,num=_num;
    }
} C[M][M];
bool cmp(node a,node b) {
    return a.num<b.num;
}
int Find(int id,int R,int x) {
    int L=0,res=-1;
    while(L<=R) {
        int mid=(L+R)>>1;
        if(C[id][mid].num<=x) {
            res=mid;
            L=mid+1;
        } else R=mid-1;
    }
    return res;
}
int find_less(int x,int a,int b) {//不完整块暴力扫描，完整块二分查找
    int id_a=a/K,id_b=b/K;
    int res=0,i;
    if(id_a==id_b) {
        for(i=a; i<=b; i++)
            res+=A[i]<=x;
    } else {
        for(i=a; i<id_a*K+sz[id_a]; i++)
            res+=A[i]<=x;
        for(i=id_a+1; i<id_b; i++)
            res+=Find(i,sz[i]-1,x)+1;
        for(i=id_b*K; i<=b; i++)
            res+=A[i]<=x;
    }
    return res;
}
int query(int a,int b,int k) {//二分查找
    int L=0,R=1000000000;
    int res=0;
    while(L<=R) {
        int mid=(L+R)>>1;
        if(find_less(mid,a,b)>=k) {
            res=mid;
            R=mid-1;
        } else L=mid+1;
    }
    return res;
}
void update(int a,int x) {//更新
    int i,id_a=a/K;
    A[a]=x;
    for(i=0; i<sz[id_a]; i++)//找到位置，修改值
        if(C[id_a][i].id==a) {
            C[id_a][i].num=x;
            break;
        }
    sort(C[id_a],C[id_a]+sz[id_a],cmp);//重新排序，可用插入排序优化
}
int main() {
    int cas,n,m,i,j,k,a,b;
    scanf("%d",&cas);
    while(cas--) {
        scanf("%d %d",&n,&m);
        K=int(sqrt(n));
        memset(sz,0,sizeof(sz));
        for(i=0; i<n; i++) {
            scanf("%d",&A[i]);
            C[i/K][i%K].set(i,A[i]);
            sz[i/K]++;
        }
        for(i=0; i<=(n-1)/K; i++) {
            sort(C[i],C[i]+sz[i],cmp);
        }
        char op[2];
        while(m--&&scanf("%s",op)) {
            if(op[0]=='Q') {
                scanf("%d %d %d",&a,&b,&k);
                printf("%d\n",query(--a,--b,k));
            } else {
                scanf("%d %d",&a,&b);
                update(--a,b);
            }
        }
    }
    return 0;
}