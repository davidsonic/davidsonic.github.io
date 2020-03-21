#include <iostream>
#include <cstring>
using namespace std;

const int N = 100000;

int sum[N+10];

int lowbit(int x){
    return x &-x;
}

void add(int x, int d){
    for(int i=x;i<=N;i+=lowbit(i))
        sum[i] +=d;
}

int query(int x){
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans += sum[i];
    }
    return ans;
}


int main(){
    int m, t, e, a, k;
    while(~scanf("%d", &m)){
        memset(sum, 0, sizeof sum);
        while(m--){
            scanf("%d", &t);
            if(t==0){
                scanf("%d", &e);
                add(e, 1);
            }else if(t==1){
                scanf("%d", &e);
                if(!(query(e) - query(e-1))) printf("No Elment!\n");
                else add(e, -1);
            }
            else{
                scanf("%d%d", &a, &k);
                int v = query(a)+ k;
                int l = 0, r = N;
                while(l<r){
                    int mid = l+r>>1;
                    if(query(mid)>=v) r = mid;
                    else l = mid+1;
                }
                if(r==0 || r==N) printf("Not Find!\n");
                else printf("%d\n", r);
            }
        }
    }
    return 0;
}