#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, q;
const int N = 200010;
int p[N];

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin>>n>>q;
    vector<map<int,int>> cnt(n+1);
    for(int i=1;i<=n;i++) {
        int c;
        scanf("%d", &c);
        p[i] = i;
        cnt[i][c] = 1;
    }

    while(q--){
        int x, a, b;
        scanf("%d%d%d", &x, &a, &b);
        if(x==1){
            int fa = find(a), fb = find(b);
            if(fa!=fb){
                if(cnt[fa].size() > cnt[fb].size()) swap(fa, fb);
                p[fa] = fb;
                for(auto [k,v]: cnt[fa]) cnt[fb][k] += v;
            }
        }else{
            int fa = find(a);
            printf("%d\n", cnt[fa][b]);
        }
    }
    return 0;
}