#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

typedef long long LL;

int main(){
    LL n;
    cin>>n;
    LL res = 1;
    for(int i=1;i<=11;i++){
        res = res * (n - i) / i;
    }
    cout<<res<<endl;
    return 0;
}