#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

typedef long long LL;

int main(){
    LL N, C;
    cin>>N>>C;
    vector<pair<LL,LL>> event;
    for(int i=0; i<N;i++){
        LL a, b, c;
        cin>>a>>b>>c;
        event.push_back({a-1, c});
        event.push_back({b, -c});
    }

    sort(event.begin(), event.end());
    LL ans = 0, fee = 0, t = 0;
    for(auto [x, y]: event){
        if(x!=t){
            ans += min(C, fee) * (x-t);
            t = x;
        }
        fee += y;
    }
    cout<<ans<<endl;
    return 0;
}