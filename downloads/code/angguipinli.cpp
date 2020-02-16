#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int N = 110;

int n, m;
int level[N];

struct Node{
    int to, v;
    bool operator < (const Node &A) const{ //小根堆
        return v > A.v;
    }
};

vector<Node>edges[N];
priority_queue<Node> Q;
int dis[N], st[N];

int ans = 1e9;

//Node in Q is different from node used in input. Q stores (index, dis[index])
void Dijstra(int L){ //[L, L+m]
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);
    dis[0] = 0;
    Q.push({0, 0});
    while(!Q.empty()){
        Node tmp = Q.top();Q.pop();
        int k = tmp.to;
        if(st[k]) continue;
        st[k] = 1;
        for(int i=0;i<edges[k].size();i++){
            int y = edges[k][i].to;
            int v = edges[k][i].v;
            if(level[y]<L || level[y] > L+m) continue;
            if(dis[y] > dis[k] + v){
                dis[y] = dis[k] + v;
                Q.push({y, dis[y]});
            }
        }
    }
    ans = min(ans, dis[1]);
}

int main(){
    scanf("%d%d", &m, &n);
    int x, k, y;
    for(int i=1;i<=n;i++){ //该物品编号为i
        scanf("%d%d%d", &x, &level[i], &k);
        edges[0].push_back({i, x}); //编号， 价格
        while(k--){
            scanf("%d%d", &y, &x);
            edges[y].push_back({i, x}); // 替代品x到target i插入价格为y的边
        }
    }
    for(int i=0;i<=100;i++){
        Dijstra(i);
    }
    cout<<ans<<endl;
    return 0;
}