//差分数组， 或者扫描线
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200010;
typedef long long LL;
LL b[N];
int n, w;

int main(){
    cin>>n>>w;
    for(int i=0;i<n;i++) {
        int st, ed, c;
        scanf("%d%d%d", &st, &ed, &c);
        b[st] += c, b[ed] -= c;
    }
    for(int i=1;i<n;i++) b[i] += b[i-1];
    bool flag = true;
    for(int i=0;i<n;i++) if(b[i] > w){
        flag = false;
        break;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}