#include <iostream>
using namespace std;

typedef long long LL;
const int N = 2000010;
int st[N+10];
int sum[N+10];

int n;

int main(){
    for(int i=1;i<=N;i++) sum[i] = 1;
    for(int i=2;i<=N;i++){
        if(!st[i]){
            for(int j=i+i;j<=N;j+=i) st[j] =1;
            for(int j=i;j<=N;j+=i){
                int t = j, c= 0;
                while(t%i==0){
                    c++, t/=i;
                }
                sum[j]*=(c+1);
            }
        }
    }

    for(int i=1;i<=N;i++)
        sum[i] += sum[i-1];

    scanf("%d", &n);
    while(n--){
        int L, R;
        scanf("%d%d", &L, &R);
        printf("%d\n", sum[R] - sum[L-1]);
    }
    return 0;
}