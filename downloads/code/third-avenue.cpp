#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

const int N = 2010, INF = 0x3f3f3f3f;
char g[N][N];
int dis[N][N];
int n, m;

typedef pair<int,int> PII;
#define x first
#define y second

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int si, sj, ei, ej;
vector<PII> tele[26];
vector<bool> used(26);


int bfs(){
    queue<PII> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    while(q.size()){
        auto t = q.front();
        q.pop();
        if(t.x == ei && t.y == ej) return dis[t.x][t.y];
        for(int i=0;i<4;i++){
            int mx = t.x + dx[i], my = t.y + dy[i];
            if(mx<0 || mx >=n || my<0 || my>=m || dis[mx][my]!=INF || g[mx][my]=='#') continue;
            dis[mx][my] = dis[t.x][t.y] + 1;
            q.push({mx, my});
        }

        if(g[t.x][t.y]>='a' && g[t.x][t.y]<='z' && !used[g[t.x][t.y] - 'a']){
            used[g[t.x][t.y] - 'a'] = true;
            for(auto [x, y]: tele[g[t.x][t.y] - 'a']){
                if(dis[x][y]==INF){
                    dis[x][y] = dis[t.x][t.y] + 1;
                    q.push({x, y});
                }
            }
        }
    }
    return INF;
}

int main(){
    cin>>n>>m;
    memset(dis, 0x3f, sizeof dis);
    for(int i=0;i<n;i++) {
        scanf("%s", g[i]);
        for(int j=0;j<m;j++){
            if(g[i][j]=='S') si = i, sj = j;
            else if(g[i][j]=='G') ei = i, ej = j;
            else if(g[i][j]>='a' && g[i][j]<='z') tele[g[i][j]-'a'].push_back({i, j});
        }
    }

    int res = bfs();
    if(res==INF) cout<<-1<<endl;
    else cout<<res<<endl;
    return 0;
}