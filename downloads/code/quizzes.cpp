#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, x;
    string s;
    cin>>n>>x;
    cin>>s;
    for(auto c: s){
        if(c=='o') x +=1;
        else x = max(0, x-1);
    }
    cout<<x<<endl;
    return 0;
}