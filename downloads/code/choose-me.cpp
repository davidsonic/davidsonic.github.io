#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
LL delta[N];

int main(){
    int n;
    cin>>n;
    LL sum = 0;
    for(int i=0;i<n;i++){
        LL a, b;
        scanf("%lld%lld", &a, &b);
        sum -= a;
        delta[i] = 2 * a + b;
    }

    sort(delta, delta + n, [](LL a, LL b){
        return a > b;
    });

    int cnt = 0;
    for(int i=0;i<n;i++){
        if(sum>0) break;
        cnt++;
        sum += delta[i];
    }
    cout<<cnt<<endl;
    return 0;

}