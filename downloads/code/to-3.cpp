#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
using namespace std;


int main(){
    long long  n;
    cin>>n;
    unordered_map<int,int> mp;
    int k =0, s = 0;
    while(n){
        int c = n%10;
        mp[c%3] ++;
        s += c;
        n/=10;
        k++;
    }
    if(s%3==0) cout<<0<<endl;
    else if(s%3==1) {
        int res = k+1;
        if(mp[1]>=1 && k>1) res = 1;
        if(mp[2]>=2 && k>2) res = min(res, 2);
        if(res==k+1) res = -1;
        cout<<res<<endl;
    }else{
        int res = k+1;
        if(mp[2]>=1 && k>1) res = 1;
        if(mp[1]>=2 && k>2) res = min(res, 2);
        if(res==k+1) res = -1;
        cout<<res<<endl;
    }
    return 0;

}