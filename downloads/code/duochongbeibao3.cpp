// dp[k*y+j] = max(dp[t*y+j] + (k-t)*z)
// dp[k*y+j] = max(dp[t*y+j] - t*z) + k*z

#include <iostream>
using namespace std;

const int N = 510;
const int M = 10010;
int m, V;
int dp[M];

struct node{
    int cnt, val;
}Q[M];

int main(){
    scanf("%d%d", &V, &m);
    int x, y, z;
    for(int i=1;i<=m;i++) {
        scanf("%d%d%d", &x, &y, &z);

        for(int j=0;j<y;j++) {
            int L = 0, R = -1;
            for (int k = 0; k * y + j <= V; k++) {
                node tmp = (node){k, dp[k*y+j] - k*z}; //easy to forget
                while(L<=R && Q[R].val<=tmp.val) R--;
                while(L<=R && tmp.cnt - Q[L].cnt > x ) L++;
                Q[++R] = tmp;
                dp[k*y+j] = max(dp[k*y+j], Q[L].val + k*z);

            }
        }

    }
    printf("%d\n", dp[V]);
    return 0;
}