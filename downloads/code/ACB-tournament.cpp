#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

typedef pair<int,int> PII;
#define x first
#define y second

int main(){
    int n;
    cin>>n;
    vector<PII>v(1<<n);
    for(int i=0;i<1<<n;i++) {
        int t;
        cin>>t;
        v[i] = {t, i+1};
    }
    for(int i=0;i<n-1;i++){
        int k = 0;
        for(int j=0;2*j+1<v.size();j++){
            auto t1 = v[2*j], t2 = v[2*j+1];
            if(t1.x > t2.x) v[k++] = t1;
            else v[k++] = t2;
        }
        v.resize(k);
    }
    if(v[0].x < v[1].x) cout<<v[0].y<<endl;
    else cout<<v[1].y<<endl;
    return 0;
}