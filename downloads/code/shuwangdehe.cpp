#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int N = 310, M = N*2;
int n,m;
int h[N], e[M], idx, ne[M], w[M];
int q[N], st[N], dist[N];
int pre[N];

typedef pair<int,int> PII;
vector<PII> path;

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}


void bfs(int start){
	int hh=0, tt =0;
	q[0] = start;
	memset(st, 0, sizeof st);
	dist[start] = 0;
	st[start] = true;
	pre[start] = -1;
	while(hh<=tt){
		int u= q[hh++];
		for(int i=h[u]; ~i; i = ne[i]){
			int j = e[i];
			if(!st[j]){
				st[j] = true;
				dist[j] = dist[u] + w[i];
				q[++tt] = j;
				pre[j] = u;
			}
		}
	}
}


int get_max(){
	int t = 1;
	for(int i=1;i<=n;i++){
		if(dist[i] > dist[t])
			t = i;
	}
	return t;
}


int bfs_max(int u){
	int hh=0, tt=0;
	dist[u] = 0;
	q[0] = u;
	int res = 0;
	while(hh<=tt){
		int t= q[hh++];
		res = max(res, dist[t]);
		for(int i=h[t];~i;i=ne[i]){
			int j = e[i];
			if(!st[j]){
				st[j] = true;
				dist[j] = dist[t] + w[i];
				q[++tt] = j;
			}
		}
	}
	return res;
}

bool check(int mid){
	int u = 0, v = path.size()-1;
	while(u+1<path.size() && path[u+1].second <= mid) u++;
	while(v-1>=0 && path.back().second - path[v-1].second<=mid) v--;
	if(u>v) return true;
	if(path[v].second - path[u].second>m) return false;

	memset(st, 0, sizeof st);
	for(int i=0;i<path.size();i++) st[path[i].first] = true;
	for(int i=u;i<=v;i++)
		if(bfs_max(path[i].first) > mid) return false;
	return true;
}



int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	for(int i=0;i<n-1;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}

	bfs(1);
	int p = get_max();
	bfs(p);
	int v = get_max();

	while(v!=-1){
		path.push_back(make_pair(v, dist[v]));
		v = pre[v];
	}

	reverse(path.begin(), path.end());
	// for(int i=0;i<path.size();i++)
	// 	printf("%d ", path[i].first);

	int l = 0, r = 1e9;
	while(l<r){
		int mid = (l+r)>>1;
		if(check(mid)) r = mid;
		else l = mid+1;
	}
	printf("%d\n", r);
	return 0;
}