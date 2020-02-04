#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int T, n, m;
typedef pair<double, double> PDD;
const int N = 20, M = 1<<N;
PDD q[N];
double eps = 1e-6;


#define x first
#define y second

int path[N][N];
int f[M];
int lb[M];

int cmp(double x, double y){
    if(fabs(x-y)<eps) return 0;
    if(x<y) return -1;
    return 1;
}


int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++){
            scanf("%lf%lf", &q[i].x, &q[i].y);
        }

        for(int i=1;i+1<1<<n;i++)
            for(int j=0;j<n;j++)
                if(!(i>>j&1)){
                    lb[i] = j;
                    break;
                }
        memset(path, 0, sizeof path);
        for(int i=0;i<n;i++) {
            path[i][i] = 1 << i;
            for (int j = 0; j < n; j++) {
                if (!cmp(q[i].x, q[j].x)) continue;
                double x1 = q[i].x, y1 = q[i].y, x2 = q[j].x, y2 = q[j].y;
                double b = (y1 * x2 * x2 / x1 / x1 - y2) / (x2 * x2 / x1 - x2);
                double a = (y1 - b * x1) / x1 / x1;
                if (a >= 0) continue;
                for (int k = 0; k < n; k++) {
                    double x = q[k].x, y = q[k].y;
                    if (!cmp(y, a * x * x + b * x)) path[i][j] |= 1 << k;
                }

            }
        }

        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for(int i=0;i+1<1<<n;i++){
            int x = lb[i];
            for(int j=0;j<n;j++){
                int state = path[x][j];
                f[i|state] = min(f[i|state], f[i] +1);
            }
        }

        printf("%d\n", f[(1<<n)-1]);
    }
    return 0;
}