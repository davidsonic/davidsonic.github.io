#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

const int N = 100010;
int a[N], b[N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    for(int i=0;i<n;i++) scanf("%d", &b[i]);
    int res = 0;
    for(int i=0;i<n;i++) res += a[i] * b[i];
    if(res==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}