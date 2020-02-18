#include <iostream>
using namespace std;

const int N = 510;
const int M = 10010;
int A[N];
int m, V;
int dp[M];
int main(){
    scanf("%d%d", &V, &m);
    int x, y, z;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d", &x, &y, &z);
        for(int j=V;j>=0;j--){
            for(int k=0;k<=x;k++)
                if(j>=k*y)
                    dp[j] = max(dp[j], dp[j-k*y] + k*z);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}