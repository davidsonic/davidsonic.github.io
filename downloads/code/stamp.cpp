#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

const int M = 2e5 + 10;
int a[M];
int main(){
    int n, m;
    int res = 0;
    cin>>n>>m;
    for(int i=0;i<m;i++) scanf("%d", &a[i]);
    sort(a, a+m);

    int k = n;
    int pre = 0;
    for(int i=0;i<m;i++){
        int t = a[i] - pre - 1;
        if (t > 0)
            k = min(k, a[i] - pre - 1);
        pre = a[i];
        a[i] = t;
    }
    a[m] = n - pre ;
    for(int i=0;i<=m;i++){
        if(a[i] % k==0) res += a[i] / k ;
        else res += a[i] / k  + 1;
    }
    cout<<res<<endl;
    return 0;
}