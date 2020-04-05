#include<bits/stdc++.h>
using namespace std;
int A[2005];
int solve() {
    int n;
    cin>>n;
    int s=0;
    for(int i=1; i<=n; i++) {
        cin>>A[i];
        s+=A[i];
    }
    for(int i=1; i<=n; i++)
        printf("%.2f ",(s-A[i])/2.0);
    puts("");
    return 0;
}
int main() {
    solve();
    return 0;
}