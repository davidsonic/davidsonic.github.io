#include <iostream>
using namespace std;

const int N = 10;
int A[N], B[N];

int n;
typedef long long LL;

int exgcd(int a, int b, LL &x, LL &y){
    if(b==0){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a%b, x, y);
    LL x1 = y;
    LL y1 = x - a/b * y;
    x = x1, y= y1;
    return d;
}

int main(){
    scanf("%d", &n);
    LL mul = 1;
    for(int i=1;i<=n;i++){
        scanf("%d%d", &A[i], &B[i]);
        mul *= A[i];
    }

    int sum = 0;
    for(int i=1;i<=n;i++){
        LL Mi = mul / A[i];
        LL x, y;
        exgcd(Mi, A[i], x, y);
        sum += ((x%A[i] + A[i]) % A[i]) * Mi * B[i];
    }

    printf("%lld\n", sum % mul);
    return 0;


}