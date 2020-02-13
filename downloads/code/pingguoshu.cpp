#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
const int M = 100010;

vector<int>edges[M];

int L[M], R[M], tot;
int val[M];

struct Bit{
    int C[M];
    void add(int x, int t){
        while(x<=n){
            C[x] += t;
            x += x&-x;
        }
    }
    int sum(int x){
        int res = 0;
        while(x){
            res += C[x];
            x -= x&-x;
        }
        return res;
    }
}bit;


void dfs(int x, int f){
    L[x] = ++tot;
    for(int i=0;i<edges[x].size();i++){
        int y = edges[x][i];
        if(y==f) continue;
        dfs(y, x);
    }
    R[x] = tot;
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n-1;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        edges[a].push_back({b});
        edges[b].push_back({a});
        bit.add(i,1);
        val[i] = 1;
    }
    val[n] = 1;
    bit.add(n, 1);
    dfs(1, 0);

    //每个点的新编号是L[x], 管理的区间是[L[x], R[x]]
    scanf("%d", &m);
    char s[10];
    int x;


    // 单点修改， 区间查询
    while(m--){
        scanf("%s%d", s, &x);
        if(s[0]=='C') {
            bit.add(L[x], -val[x]);
            val[x] = -val[x];
        }
        else {
            int m = bit.sum(R[x]) - bit.sum(L[x]-1);
            printf("%d\n", m);
        }
    }
    return 0;
}