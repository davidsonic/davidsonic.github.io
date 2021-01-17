#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

int main(){
    int n;
    cin>>n;
    vector<LL>G[n];
    vector<PII>edges;
    for(int i=0;i<n-1;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        edges.push_back({a, b});
    }
    vector<int> depth(n, -1);
    queue<int> Q;
    depth[0] = 0;
    Q.push(0);
    while(Q.size()){
        int t = Q.front(); Q.pop();
        for(int i=0; i<G[t].size();i++){
            if(depth[G[t][i]]==-1){
                depth[G[t][i]] = depth[t] + 1;
                Q.push(G[t][i]);
            }
        }
    }

    vector<LL> s(n, 0);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int t, e, x;
        scanf("%d%d%d", &t, &e, &x);
        int a = edges[e-1].first, b = edges[e-1].second; // e-1
        if(depth[a] > depth[b]){
            swap(a, b);
            if(t==1) t = 2;
            else t = 1;
        }

        if(t==1){
            s[0] += x;
            s[b] -= x;
        }else s[b] += x;
    }

    Q = queue<int> ();
    Q.push(0);
    while(Q.size()){
        int t = Q.front(); Q.pop();
        for(int i=0;i<G[t].size();i++){
            if(depth[G[t][i]] > depth[t]) {
                s[G[t][i]] += s[t];
                Q.push(G[t][i]);
            }
        }
    }
    for(auto x: s) printf("%lld\n", x);
    return 0;
}