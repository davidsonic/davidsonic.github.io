#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100010;

int n, m;
int A[N];

struct Node{
    int L, R;
    vector<int> num;
} tree[N<<2];

void build(int l, int r, int p){
    tree[p].L = l, tree[p].R = r;
    tree[p].num.clear();
    if(l==r){
        tree[p].num.push_back(A[l]);
        return;
    }
    int mid = l+r>>1;
    build(l, mid, p<<1);
    build(mid+1, r, p<<1|1);


    tree[p].num.resize(r-l+1);
    merge(tree[p<<1].num.begin(), tree[p<<1].num.end(),
          tree[p<<1|1].num.begin(), tree[p<<1|1].num.end(),
          tree[p].num.begin());
}


int query(int l, int r, int x, int p){
    if(l==tree[p].L && r == tree[p].R){
        return upper_bound(tree[p].num.begin(), tree[p].num.end(), x) - tree[p].num.begin();
    }
    int mid = tree[p].L + tree[p].R >>1;
    if(r<=mid) return query(l, r, x, p<<1);
    else if(l>mid)  return query(l, r, x, p<<1|1);
    else{
        return query(l, mid, x, p<<1) + query(mid+1, r, x, p<<1|1);
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &A[i]);
    }

    build(1, n, 1);
    for(int i=1;i<=m;i++){
        int L, R, x;
        scanf("%d%d%d", &L, &R, &x);
        printf("%d\n", query(L, R, x, 1));
    }

    return 0;
}