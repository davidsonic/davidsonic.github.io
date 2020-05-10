#include <iostream>
using namespace std;

const int N = 100005;
int dp[N][N];

struct node{
    int cnt, val;
}Q[N];

int main(){
    int V, n, x, y, z;
    cin>>V>>n;
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d", &x, &y, &z);
        for(int j=0;j<x;j++){
            int L = 0, R = -1;
            for(int k=0;k*x+j<=V; k++){
                node tmp = (node){k,dp[i-1][k*x+j] - k*y};
                while(R>=L && tmp.val >= Q[R].val)R--;
                while(R>=L && tmp.cnt - Q[L].cnt>z) L++;
                Q[++R] = tmp;
                dp[i][k*x+j] = Q[L].val + k*y;
            }
        }
        for(int j=0;j<=V;j++) dp[i][j] = max(dp[i-1][j], dp[i][j]);
    }
    return 0;
}