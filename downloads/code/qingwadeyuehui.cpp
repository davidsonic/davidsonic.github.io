#include <iostream>
using namespace std;
#define int long long
int s1, s2, m, n, L;

int exgcd(int a, int b, int &x, int &y){
    if(b==0){
        x = 1, y = 0;
        return a;
    }
    int  res = exgcd(b, a%b, x, y);
    int x1 = y;
    int y1 =  x - a/b * y;
    x = x1, y = y1;
    return res;
}


signed main(){

    scanf("%d%d%d%d%d", &s1, &s2, &m, &n, &L);
    s1%=L, s2%=L;
    int a = m-n, b = s2-s1;
    if(a<0) a = -a, b = -b;
    int x, y;
    int d = exgcd(a, L, x, y);
    if(b%d) puts("Impossible");
    else x = x * b / d,  L/= d, printf("%lld", (x%L + L) % L);
    return 0;

}