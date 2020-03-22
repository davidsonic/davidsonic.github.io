#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N], bin[N];
int n;
int sum[N];

void update(int x){
    sum[x] = sum[x*2] + sum[x*2+1];
}

void build(int l,int r, int x){
    if(l==r){
        sum[x] = 0; //mistake
        return;
    }
    int mid = l+r>>1;
    build(l, mid, x<<1);
    build(mid+1, r, x<<1|1);
    update(x);
}


int query(int A, int B, int l, int r, int x){
    if(A<=l && B>=r) return sum[x];
    int mid = l+r>>1;
    int ans = 0;
    if(A<=mid) ans += query(A, B, l, mid, x<<1);
    if(B>mid) ans += query(A, B, mid+1, r, x<<1|1);
    return ans;
}

void change(int pos, int v, int l, int r, int x){
    if(l==r) {
        sum[x]+= v;
        return;
    }
    int mid = l+r>>1;
    if(pos <=mid) change(pos, v, l, mid, x<<1);
    else change(pos, v, mid+1, r, x<<1|1);
    update(x);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        memset(a, 0, sizeof a);
        memset(bin, 0, sizeof bin);
        memset(sum, 0, sizeof sum);
        scanf("%d", &n);
        int cnt = 0;
        for(int i=1;i<=n;i++) {
            scanf("%d", &a[i]);
            bin[++cnt] = a[i];
        }
        sort(bin+1, bin+1+cnt);
        cnt = unique(bin+1, bin+1+cnt) - bin-1;
        for(int i=1;i<=n;i++) {
            a[i] = lower_bound(bin + 1, bin + 1 + cnt, a[i]) - bin;
        }

        build(1, cnt, 1);
        int res = 0;
        for(int i=1;i<=n;i++){
            res += query(a[i]+1, cnt, 1, n, 1);
            change(a[i], 1, 1, n, 1);
        }

        printf("Scenario #%d:\n%d\n\n", i, res);
    }
    return 0;
}