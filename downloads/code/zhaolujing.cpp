#include <iostream>
#include <vector>
using namespace std;

const int N = 100010;
typedef long long LL;
int n,m;

vector<int>edges[N];
int val[N]; // number on this node
int Lid[N], Rid[N], tot;
int Line[N]; //map from dfs_id to original id
LL dis[N]; // accumulated number from root till this node

void dfs(int x, int f, LL d){
    Lid[x] = ++tot; dis[x] = d; Line[tot] = x;
    for(int i=0;i<edges[x].size();i++){
        int j = edges[x][i];
        if(j==f) continue;
        dfs(j, x, d + val[j]);
    }
    Rid[x] = tot;
}

struct Node{
    int L, R;
    LL mx, add;
}tree[N<<2];


void up(int p){
    tree[p].mx = max(tree[p<<1].mx, tree[p<<1|1].mx);
}

void build(int L, int R, int p){
    tree[p].L = L, tree[p].R = R;
    tree[p].add = 0;
    if(L==R){
        tree[p].mx = dis[Line[L]];
        return;
    }
    int mid = (L + R )>>1;
    build(L, mid, p<<1);
    build(mid+1, R, p<<1|1);
    up(p);
}

void down(int p){
    LL &t = tree[p].add;
    if(t==0) return;
    tree[p<<1].add += t;
    tree[p<<1].mx += t;
    tree[p<<1|1].add += t;
    tree[p<<1|1].mx += t;
    t = 0;
}

void update(int L, int R, int x, int p){
    if(tree[p].L == L && tree[p].R ==R){
        tree[p].add += x;
        tree[p].mx += x;
        return;
    }
    down(p);
    int mid = (tree[p].L + tree[p].R )>>1;
    if(R<=mid) update(L, R, x, p<<1);
    else if(L>mid) update(L, R, x, p<<1|1);
    else{
        update(L, mid, x, p<<1);
        update(mid+1, R, x, p<<1|1);

    }
    up(p);
}

LL query(int L, int R, int p){
    if(tree[p].L == L && tree[p].R ==R ){
        return tree[p].mx;
    }
    down(p);
    int mid = (tree[p].L + tree[p].R) >>1;
    if(R<=mid) return query(L,R, p<<1);
    else if(L>mid) return query(L, R, p<<1|1);
    else{
        return max(query(L, mid, p<<1), query(mid+1, R, p<<1|1));
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i=0;i<n;i++) edges[i].clear();
    for(int i=1;i<n;i++){
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        scanf("%d", &val[i]);
    }
//  dfs order
    dfs(0, -1, val[0]);
    build(1, tot, 1);
    int c;
    while(m--){
        scanf("%d%d", &a, &b);
        if(a==0){
            scanf("%d", &c);
            update(Lid[b], Rid[b], c-val[b], 1); // segment tree supports dfs_id manipulation
            val[b] = c;  // original id
        }else{
            printf("%d\n", query(Lid[b], Rid[b], 1));
        }
    }
    return 0;
}