#include <iostream>
#include <cstring>
using namespace std;

const int N = 1010;
int sum[N][N];
int n;
int C(int x){
    return x & -x;
}

int query(int x, int y){
    int ans = 0;
    while(x>0){
        int ty = y;
        while(ty>0){
            ans += sum[x][ty];
            ty -= C(ty);
        }
        x -= C(x);
    }
    return ans;
}

void add(int x, int y, int d){
    while(x<=n){
        int ty = y;
        while(ty<=n){
            sum[x][ty] = (sum[x][ty] + d) % 2;
            ty += C(ty);
        }
        x += C(x);
    }
}

int main(){
    int X ;
    scanf("%d", &X);
    int T;
    char c[10];
    int x1, y1, x2, y2;
    int x, y;
    for(int i=0;i<X;i++){
        scanf("%d%d", &n, &T);
        memset(sum, 0, sizeof sum);
        while(T--){
            scanf("%s",c);
            if(c[0]=='C'){
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
//                printf("%d %d %d %d\n", x1,y1, x2,y2);
                add(x1, y1, 1);
                add(x1, y2+1, 1);
                add(x2+1, y1, 1);
                add(x2+1, y2+1, +1);
            }else if(c[0]=='Q'){
                scanf("%d%d", &x, &y);
//                printf("%d %d\n", x, y);
                printf("%d\n", query(x, y) % 2);
            }
        }
        puts("");
    }
    return 0;
}