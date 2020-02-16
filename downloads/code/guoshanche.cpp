#include <iostream>
#include <cstring>
using namespace std;
const int N = 510;
int mp[N][N];
int st[N];
int a[N], b[N];
int n,m;
int ans;

bool sp(int v){
    for(int i=1;i<=m;i++){
        if(mp[v][i] && !st[i]){
            st[i] = 1; //类似于减枝
            if(b[i]==-1 || sp(b[i])){
                b[i] = v;
                a[v] = i;
                return true;
            }
        }
    }
    return false;
}

void solve(){
    ans = 0;
    memset(a, -1, sizeof a);
    memset(b, -1, sizeof b);
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            memset(st, 0, sizeof st); //对每一i，都要做一次
            if(sp(i)) ans ++;
        }
    }
}
int main(){
    int k;
    while(scanf("%d", &k) && k){
        scanf("%d%d", &n, &m);
        int a, b;
        memset(mp, 0, sizeof mp);
        while(k--){
            scanf("%d%d", &a, &b);
            mp[a][b] = 1;
        }
        solve();
        printf("%d\n", ans);
    }
    return 0;
}
