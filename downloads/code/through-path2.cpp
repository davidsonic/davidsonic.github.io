#include<bits/stdc++.h>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson l , mid , rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define lr2 (l + r) >> 1
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 50;
ll sum[maxn << 2], lazy[maxn << 2];
int L[maxn], R[maxn];
void push_up(int rt){
    sum[rt] = sum[ls] + sum[rs];
}
void push_down(int rt, int m){
    if(lazy[rt])
	{
		lazy[ls] += lazy[rt];
		lazy[rs] += lazy[rt];
		sum[ls] += lazy[rt] * (m - (m >> 1));
		sum[rs] += lazy[rt] * (m >> 1);
		lazy[rt] = 0;
	}
}
void update(int a, int b, ll v, int l, int r, int rt){
    if(a <= l && b >= r){
        sum[rt] += 1LL * (r - l + 1) * v;
        lazy[rt] += v;
        return;
    }
    push_down(rt, r - l + 1);
    int mid = lr2;
    if(a <= mid) update(a, b, v, lson);
    if(b > mid) update(a, b, v, rson);
    push_up(rt);
}
ll query(int a, int b, int l, int r, int rt){
    if(a <= l && b >= r){
        return sum[rt];
    }
    int mid = lr2;
    push_down(rt, r - l + 1);
    ll ans = 0;
    if(a <= mid) ans += query(a, b, lson);
    if(b > mid) ans += query(a, b, rson);
    return ans;
    push_up(rt);
}
int a[maxn], b[maxn];
int cnt, n;
vector<int> G[maxn];
int d[maxn];
void dfs(int v, int fa){
    L[v] = ++cnt;
    d[v] = d[fa] + 1;
    for(auto u : G[v]){
        if(u != fa){
            dfs(u, v);
        }
    }
    R[v] = cnt;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i < n;i++){
        cin >> a[i] >> b[i];
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    dfs(1, 0);
    int q;
    cin >> q;
    ll ans = 0;
    while(q--){
        int t, id;
        ll x;
        cin >> t >> id >> x;
        if(t == 1){
            if(d[a[id]] < d[b[id]]){
                ans += x;
                update(L[b[id]], R[b[id]], -x, 1, n, 1);
            }
            else update(L[a[id]], R[a[id]], x, 1, n, 1);
        }
        else{
            if(d[b[id]] < d[a[id]]){
                ans += x;
                update(L[a[id]], R[a[id]], -x, 1, n, 1);
            }
            else update(L[b[id]], R[b[id]], x, 1, n, 1);
        }
    }
    for(int i = 1;i <= n;i++) cout << query(L[i], L[i], 1, n ,1) + ans << endl;
    return 0;
}