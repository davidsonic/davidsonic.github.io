#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100010;
int n, m;
int A[N];

struct Node{
    int val, mi, mx;
    int L, R;
}tree[N<<2];


void up(Node&root, Node &ls, Node &rs){
    root.val = max(max(ls.val, rs.val), rs.mx-ls.mi);
    root.mi = min(ls.mi, rs.mi);
    root.mx = max(ls.mx, rs.mx);
}

void build(int L, int R, int p){
    tree[p].L = L, tree[p].R = R;
    if(L==R){
        tree[p].val = 0;
        tree[p].mi = A[L];
        tree[p].mx = A[L];
        return;
    }
    int mid = L+R>>1;
    build(L, mid, p<<1);
    build(mid+1, R, p<<1|1);
    //递归完毕，用tree
    up(tree[p], tree[p<<1], tree[p<<1|1]);
}


Node query(int L, int R, int p){
    if(tree[p].L ==L && tree[p].R==R){
        return tree[p];
    }
    int mid = tree[p].L + tree[p].R >>1;
    if(R<=mid) return query(L, R, p<<1);
    else if(L>mid) return query(L, R, p<<1|1);
    else{
//        准备开始递归
        Node B = query(L, mid, p<<1);
        Node C = query(mid+1, R, p<<1|1);
        Node res;
        up(res, B, C);
        return res;
    }
}

int main(){
    scanf("%d%d", &n ,&m);
    for(int i=1;i<=n;i++) scanf("%d", &A[i]);
    build(1, n, 1);
    while(m--){
        int L, R;
        scanf("%d%d", &L, &R);
        printf("%d\n", query(L, R, 1).val);
    }
    return 0;
}