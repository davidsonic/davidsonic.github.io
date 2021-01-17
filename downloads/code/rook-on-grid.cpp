#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5 + 10;
int r[N], c[N];
typedef long long LL;

int tr[N];
int h, w;

int lowbit(int x){
    return x & -x;
}

void add(int x, int v){
    for(int i=x;i<=h;i+=lowbit(i)) {
        tr[i] += v;
    }
}

int sum(int x){
    int res =0;
    for(int i=x;i;i-=lowbit(i)){
        res += tr[i];
    }
    return res;
}

int main(){
    int m;
    cin>>h>>w>>m;
    for(int i=1;i<=h;i++) r[i] = w+1;
    for(int j=1;j<=w;j++) c[j] = h+1;
    while(m--){
        int x,y;
        scanf("%d%d", &x, &y);
        r[x] = min(r[x], y);
        c[y] = min(c[y], x);
    }
    LL res = 0;
    bool flag = 0;
    for(int i=1;i<=h;i++) {
        if(flag) {r[i] = 1; continue;}
        if(r[i]==1) {flag = 1; continue;}
        res += r[i] - 1;
    }
    vector<int> v[w+2];
    for(int i=1;i<=h;i++) v[r[i]].push_back(i);

    for(int j=1;j<=w;j++){
        if(c[j]==1) break; //important
        res += sum(c[j] -1);
        for(int i: v[j]) add(i, 1);
    }
    printf("%lld\n", res);
    return 0;
}