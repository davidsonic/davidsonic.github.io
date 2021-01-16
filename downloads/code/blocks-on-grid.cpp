#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int a[N][N];
int main() {
    int n, m;
    cin>>n>>m;
    int k = INF;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) {
            scanf("%d", &a[i][j]);
            k = min(k, a[i][j]);
        }
    int res = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            res += a[i][j] - k;
    cout<<res<<endl;
    return 0;
}
