#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N = 1010;
int a[N], tmp[N];
int n;

int merge_sort(int L, int R){
    if(L>=R) return 0;
    int mid = L+R>>1;
    int res = merge_sort(L, mid) + merge_sort(mid+1, R);
    int l = L, r=mid+1, k = 0;
    while(l<=mid && r<=R){
        if(a[l]<=a[r]) tmp[k++] = a[l++];
        else {
            tmp[k++] = a[r++];
            res += mid-l+1;
        }
    }
    while(l<=mid) tmp[k++] = a[l++];
    while(r<=R) tmp[k++] = a[r++];
    for(int i=L, j=0; i<=R; i++, j++) a[i] = tmp[j];
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        memset(a, 0, sizeof a);
        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        int res = merge_sort(0, n-1);
        printf("Scenario #%d:\n%d\n\n", i, res);
    }
    return 0;
}