#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;

int n, m;
int A[N];
char s[10];

typedef long long LL;
struct node{
    int L, R;
    LL tag, sum;
    int len(){ return (R-L+1);}

}tree[N<<2];

void up(node&A, node B, node C){
    A.sum = B.sum + C.sum;
}

void build(int L, int R, int p){
    tree[p].L = L, tree[p].R =R;
    if(L==R){
        tree[p].tag = 0;
        tree[p].sum = A[L];
        // forget
        return ;
    }
    int mid = L+R>>1;
    build(L, mid, p<<1);
    build(mid+1, R, p<<1|1);

    up(tree[p], tree[p<<1], tree[p<<1|1]);
}

void down(int p){
    LL &t = tree[p].tag;
    if(t==0) return;
    tree[p<<1].tag += t;
    tree[p<<1].sum += t * tree[p<<1].len();

    tree[p<<1|1].tag += t;
    tree[p<<1|1].sum += t*tree[p<<1|1].len();

    //清空懒标记
    t = 0;
}

void update(int L, int R, int x, int p){
    if(tree[p].L ==L && tree[p].R ==R){
        tree[p].tag += x;
        tree[p].sum +=  x;
        //forget
        return ;
    }
    down(p);
    int mid = tree[p].L + tree[p].R >>1;
    if(R<=mid) update(L, R, x, p<<1);
    else if(L>mid) update(L, R, x, p<<1|1);
    else {
        update(L, mid, x, p<<1);
        update(mid+1, R, x, p<<1|1);
    }
    up(tree[p], tree[p<<1], tree[p<<1|1]);
}

LL query(int L, int R, int p){
    if(tree[p].L==L && tree[p].R==R){
        return tree[p].sum;
    }
//    forget
    down(p);
    int mid = tree[p].L + tree[p].R >>1;
    if(R<=mid) return query(L, R, p<<1);
    else if(L>mid) return query(L, R, p<<1|1);
    else {
        return query(L, mid, p<<1) + query(mid+1, R, p<<1|1);
    }
}


int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++) scanf("%d", &A[i]);
    build(1, n, 1);
    while(m--){
        scanf("%s", s);
        if(s[0]=='A'){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            update(a, b, c, 1);
        }else{
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%lld\n", query(a, b, 1));
        }

    }
    return 0;
}