#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
const int N = 100010;
vector<int>edges[N];
int colors[N];
bool ff = true;

void dfs(int x, int c){
    colors[x] = c;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(colors[x]==colors[y]){
            ff = false;
            return;
        }else if(colors[y]==0){
            dfs(y, -c);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i=1;i<=m;i++){
        scanf("%d%d", &a, &b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    memset(colors, 0, sizeof(colors));
    for(int i=1;i<=n;i++){
        if(colors[i]==0) dfs(i, 1);
    }
    if(ff) puts("it's your own problem");
    else puts("there are must be something wrong");
    return 0;
}