#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 1000010;
int mark[N+10], pmark[N+10];
typedef long long LL;

LL a, b;
void prime(){
    int n = sqrt(b);
    for(int i=2;i<=n;i++)
        if(!mark[i]){
            for(int j=i+i;j<=n;j+=i)
                mark[j] = 1;
            LL p;
            if(a%i==0) p = a;
            else p = max(2LL, (a/i + 1) * i);
            for(; p<=b; p+=i) pmark[p-a] = 1;
        }
}

int main(){
    scanf("%lld%lld", &a, &b);
    prime();
    int sum = 0;
    for(int i=0;i<=b-a;i++)
        if(pmark[i]==0) sum++;
    if(a==1) sum--;
    printf("%d\n", sum);
    return 0;
}