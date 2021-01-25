#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long LL;
const int INF = 0x3f3f3f3f;

int main(){
    int n;
    cin>>n;
    LL sum = 0, x = 0, mx = 0;
    LL res = 0;
    for(int i=0;i<n;i++){
        LL a;
        scanf("%lld", &a);
        mx = max(mx, x + a);
        x += a;
        res = max(res, sum + mx);
        sum += x;
    }
    cout<<res<<endl;
    return 0;
}