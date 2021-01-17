#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<string> str(n);
    for(auto &s: str) cin>>s;
    unordered_set<string> st(str.begin(), str.end());
    for(auto s: str){
        if(st.count('!' + s)) {
            cout << s << endl;
            return 0;
        }
    }
    cout<<"satisfiable"<<endl;
    return 0;
}
