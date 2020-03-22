#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

const int N = 1010;
int a, b, n;
typedef long long ll;
ll c[N];
vector<pair<int,int> > p;

bool cmp(const pair<int,int> & p1, const pair<int,int> &p2){
    if(p1.second != p2.second) return p1.second>p2.second;
    else return p1.first< p2.first;
}

int lowbit(int x){
    return x & -x;
}

void add(int x){
    for(int i=x;i<=N;i+=lowbit(i))
        c[i] += 1;
}

ll query(int x){
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i))
        ans += c[i];
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        memset(c, 0, sizeof c);
        scanf("%d%d%d", &a, &b, &n);
        int x, y;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x, &y);
            p.push_back({x, y});
        }
        sort(p.begin(), p.end(), cmp);
        for(int i=0;i<p.size();i++) printf("%d %d\n" ,p[i].first, p[i].second);
        ll ans = 0;
        for(int i=0;i<p.size();i++){
            x = p[i].first, y = p[i].second;
            ans += query(x-1);
            add(x);
        }
        printf("Test case %d: %lld\n", t,ans);
    }
    return 0;
}