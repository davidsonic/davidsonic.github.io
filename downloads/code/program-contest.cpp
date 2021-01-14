#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

const int N = 45;
int a[N];

int main(){
    int n, m;
    cin>>n>>m;
    set<int> L, R;
    L.insert(0), R.insert(0);
    for(int i=0;i<n;i++) cin>>a[i];
    int l = n/2, r = n - l;
    for(int i=0;i<(1<<l);i++){
        int s = 0;
        for(int j=0;j<l;j++){
            if(i&(1<<j)){
                s += a[j];
                if(s>m) break;
            }
        }
        if(s<=m) L.insert(s);
    }

    for(int i=0;i<(1<<r);i++){
        int s = 0;
        for(int j=0;j<r;j++){
            if(i&(1<<j)){
                s += a[l + j];
                if(s>m) break;
            }
        }
        if(s<=m) R.insert(s);
    }

    int res = 0;
    for(int l: L){
        auto it = R.lower_bound(m+1-l);
        if(it!=R.begin())
            it--;
        if(l + * it <=m) res = max(res, l + *it);
        if(res==m) break;
    }
    cout<<res<<endl;
    return 0;
}