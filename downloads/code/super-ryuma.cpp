#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;
    bool flag = false;
    if(r1==r2 && c1==c2) cout<<0<<endl;
    else if(r1-c1==r2-c2 || r1+c1==r2+c2 || abs(r1-r2) + abs(c1-c2)<=3) cout<<1<<endl;
    else if((r1 + c1 + r2 - c2)%2==0) cout<<2<<endl;
    else{
        for(int i=-3;i<=3;i++)
            for(int j=-3;j<=3;j++){
                if(abs(i) + abs(j) > 3) continue;
                int r = r1 + i, c = c1 + j;
                if(r-c==r2-c2 || r+c == r2 + c2 || abs(r-r2) + abs(c -c2) <=3){
                    cout<<2<<endl;
                    return 0;
                }
            }
        cout<<3<<endl;
    }
    return 0;
}