#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1000010;
int a[N];

int q[N];
int ans[N];
int tt=0, rr = -1;

int n, k;

int main(){
    scanf("%d%d", &n, &k);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=n;i++){
        while(tt<=rr && a[q[rr]]>=a[i]) rr--;
        q[++rr] = i;
        while(tt<=rr && i-q[tt]>=k) tt++;
        ans[i] = q[tt];
    }

    for(int i=k;i<=n;i++) printf("%d ", a[ans[i]]);
    puts("");

    tt =0, rr = -1;
    for(int i=1;i<=n;i++){
        while(tt<=rr && a[q[rr]]<=a[i]) rr--;
        q[++rr] = i;
        while(tt<=rr && i-q[tt]>=k) tt++;
        ans[i] = q[tt];
    }

    for(int i=k;i<=n;i++) printf("%d ", a[ans[i]]);
    puts("");
    return 0;
}



