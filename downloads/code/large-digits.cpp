#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int sum(int x){
    int s = 0;
    while(x){
        s += x%10;
        x/=10;
    }
    return s;
}
int main(){
    int a, b;
    cin>>a>>b;
    int sa = sum(a), sb = sum(b);
    if(sa!=sb) cout<<max(sa, sb)<<endl;
    else cout<<sa<<endl;
    return 0;
}