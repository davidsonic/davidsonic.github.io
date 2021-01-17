#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

const int N = 1010;
int x[N], y[N];
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>x[i]>>y[i];
    }

    int res = 0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            double t = (double)(y[j] - y[i])/ (x[j] - x[i]);
            if(t>=-1 && t<=1) res++;
        }
    cout<<res<<endl;
    return 0;

}