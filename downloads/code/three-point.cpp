#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    int x, y;
    cin>>x>>y;
    if(abs(x-y)<3) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;

}