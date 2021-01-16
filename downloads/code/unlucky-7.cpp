#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

bool to_oct(int x){
    string s;
    while(x) {
        s = to_string(x % 8) + s;
        x /= 8;
    }
    for(int j=0;j<s.size();j++)
        if(s[j]=='7') return true;
    return false;
}

bool to_dec(int x){
    string s = to_string(x);
    for(int j=0;j<s.size();j++)
        if(s[j]=='7') return true;
    return false;
}

int main(){
    int n;
    cin>>n;
    int s = 0;
    for(int i=1;i<=n;i++){
        if(to_dec(i) || to_oct(i)) s++;
    }
    cout<<n-s<<endl;
    return 0;
}