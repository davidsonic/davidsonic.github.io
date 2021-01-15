#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

const int N = 300010;
int s[N], a[N];
int n;

int lowbit(int x){
    return x & -x;
}

void modify(int x, int v){
    for(int i=x;i<=n;i+=lowbit(i)){
        s[i] ^= v;
    }
}

int sum(int x){
    int res = 0;
    for(int i=x;i;i-=lowbit(i)){
        res ^= s[i];
    }
    return res;
}

int main(){
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d", &x);
        a[i] = a[i-1] ^ x;
    }
    for(int i=1;i<=n;i++) {
        s[i] = a[i] ^ a[i-lowbit(i)];
    }

    while(q--){
        int t, x, v;
        scanf("%d%d%d", &t, &x, &v);
        if(t==1) modify(x, v);
        else printf("%d\n", sum(v) ^ sum(x-1));
    }
    return 0;
}