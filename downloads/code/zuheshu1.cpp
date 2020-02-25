#include <iostream>
#include <vector>
using namespace std;

const int N = 1000010, P = 1e9+7;
int cnt[N+10];
vector<int> son[N+10];
int n, m;

void prime(){
    for(int i=2;i<=N;i++){
        if(son[i].size()==0)
            for(int j=i;j<=n;j+=i) {
                son[j].push_back(i); //该数是质数， 包含该质数因子本身
            }
    }
}

void solve(int n, int k){
    for(int i=2;i<=n;i++)
        for(int j=0;j<son[i].size();j++){
            int x = son[i][j], c = 0, p=i;
            while(p%x==0){
                p/=x, c++;
            }
            cnt[x] += c*k;
        }
}

long long fast(int a, int b){
    long long res = 1;
    while(b){
        if(b&1) res = res * a % P;
        a = a * a % P;
        b>>=1;
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
        if(cnt[i]>0)
            res = res * fast(i, cnt[i]) % P;
    printf("%lld\n", res);
    return 0;
}
