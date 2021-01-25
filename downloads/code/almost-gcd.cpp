#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int INF = 1e9;

int main(){
    unordered_map<int,int> mp;
    int n;
    cin>>n;
    vector<int> a(n);
    int k = 0;
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
        k = max(k, a[i]);
    }

    int res = 0, num = 0;
    for(int i=2;i<=k;i++){
        for(int j=0;j<n;j++) {
            if(a[j] % i==0) mp[i]++;
        }
        if(mp[i] > num){
            num = mp[i];
            res = i;
        }
    }
    cout<<res<<endl;
    return 0;
}