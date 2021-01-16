#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

const int N = 200010;
int a[N];

typedef long long LL;

int main(){
    int n;
    cin>>n;
    LL s = 0;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        s += a[i];
    }
    sort(a+1, a+n+1);
    LL res = 0;
    for(int i=1;i<=n;i++){
        s -= a[i];
        res += s  - (LL)(n-i) * a[i];
    }
    cout<<res<<endl;
    return 0;

}