#include <iostream>
using namespace std;

const int N = 1000010, P = 1e9+7;

int n, m;

int pcnt, pr[N+10];
int cnt[N+10];
int mark[N+10];

void prime(){
    for(int i=2;i<=N;i++)
        if(!mark[i]) {
            pr[++pcnt] = i;
            for (int j = i + i; j <= n; j += i)
                mark[j] = 1;
        }
}

//阶乘质因子分解
void solve(int n, int k){
    for(int i=1; i<=pcnt && pr[i]<=n;i++){  //starts from 1
        int x = pr[i];
        // x在n!中指数
        long long t = x;
        while(t<=n){
            cnt[x] += n/t * k;
            t*=x;
        }
    }
}

long long fast(int n, int x){
    long long res = 1;
    while(x){
        if(x&1) res = res * n % P;
        n = n * n % P;
        x >>= 1;
    }
    return res;
}

int main(){
    scanf("%d%d", &n, &m);
    prime();
    solve(n, 1);
    solve(n-m, -1);
    solve(m, -1);
    long long res = 1;
    for(int i=2;i<=n;i++)
        if(cnt[i])
            res = res * fast(i, cnt[i]) % P;
    printf("%lld\n", res);
    return 0;
}