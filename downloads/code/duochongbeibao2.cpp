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
        int k = 0;
        for(int j=1; j<=x; j*=2){
            A[k++] = j;
            x-=j;
        }
        if(x) A[k++] = x;

// note: m must be at the outerloop
        for(int m=0;m<k;m++)
            for(int j=V;j>=A[m]*y; j--){
                dp[j] = max(dp[j], dp[j-A[m]*y] + A[m]*z);
            }
    }
    printf("%d\n", dp[V]);
    return 0;
}