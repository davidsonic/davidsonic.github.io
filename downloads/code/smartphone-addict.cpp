#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

int main(){
    int N, m, t;
    cin>>N>>m>>t;
    int n = N;
    int a, b;
    int pre = 0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        n -= (a - pre);
        if(n<=0) {cout<<"No"<<endl;  return 0;}
        n += (b-a);
        n = min(n, N);
        pre = b;
    }
    n -= (t - pre);
    if (n <= 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}