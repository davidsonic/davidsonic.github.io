#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

const int N = 10010;
int a[N], b[N];
int f[N][N];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) f[i][j] = max(n, m);
    for(int i=1;i<=n;i++) f[i][0] = i;
    for(int j=1;j<=m;j++) f[0][j] = j;
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int j=1;j<=m;j++) scanf("%d", &b[j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            f[i][j] = min(f[i][j], f[i-1][j] + 1);
            f[i][j] = min(f[i][j], f[i][j-1] + 1);
            if(a[i]!=b[j]) f[i][j] = min(f[i][j], f[i-1][j-1] + 1);
            else f[i][j] = min(f[i][j], f[i-1][j-1] );
        }
    cout<<f[n][m]<<endl;
    return 0;
}