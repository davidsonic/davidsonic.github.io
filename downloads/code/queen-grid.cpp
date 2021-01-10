#include <iostream>
using namespace std;

const int N = 2010;
char g[N][N];

typedef long long LL;
int f[N][N], rsum[N][N], csum[N][N], dsum[N][N];
int n, m;
const int mod = 1e9 + 7;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%s", g[i]);

    f[1][1] = 1;
    rsum[1][1] = 1, csum[1][1] = 1, dsum[1][1] = 1;
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= m; j++) {
            if (g[i - 1][j - 1] == '#') {
                f[i][j] = 0;
                rsum[i][j] = 0, csum[i][j] = 0, dsum[i][j] = 0;
                continue;
            }
            LL tmp = f[i][j];
            tmp = (tmp + rsum[i-1][j]) % mod;
            tmp = (tmp + csum[i][j-1]) % mod;
            tmp = (tmp + dsum[i-1][j-1]) % mod;

            f[i][j] = tmp;
            rsum[i][j] = (rsum[i-1][j] + f[i][j]) % mod;
            csum[i][j] = (csum[i][j-1] + f[i][j]) % mod;
            dsum[i][j] = (dsum[i-1][j-1] + f[i][j]) % mod;
        }
    }

//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=m;j++)
//            printf("%d ", f[i][j]);
//        puts("");
//    }

    cout<<f[n][m]<<endl;
    return 0;
}