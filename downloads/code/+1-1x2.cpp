#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;
#define x first
#define y second
typedef long long LL;
typedef pair<LL, LL> PLL;

int main(){
    LL x, y;
    cin>>x>>y;
    if(x>=y) cout<<x-y<<endl;
    else{
        unordered_set<LL>s;
        LL ans = y - x;
        queue<PLL>q;
        q.push({y, 0});
        s.insert(y);
        while(q.size()){
            auto t = q.front(); q.pop();
            if(t.y >= ans) break;
            ans = min(ans, t.y+ abs(t.x - x));
            if (t.x <= x) continue; // not break; can no longer apply //2.
            if(t.x %2 ==0){
                if(!s.count(t.x/2)) {
                    s.insert(t.x/2);
                    q.push({t.x/2, t.y + 1});
                }
            }
            else {
                if(!s.count(t.x + 1)){
                    s.insert(t.x + 1);
                    q.push({t.x + 1, t.y + 1});
                }
                if(!s.count(t.x - 1)){
                    s.insert(t.x - 1);
                    q.push({t.x - 1, t.y + 1});
                }
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}