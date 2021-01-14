#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 100;
double ret[maxn][maxn][maxn];

double dfs(vector<int>&coins){
    if(coins[1]==0) return 100.0 - coins[0];
    if(coins[0]==100 || coins[1] ==100 || coins[2]==100) return 0.0;
    double &ans = ret[coins[0]][coins[1]][coins[2]];
    if(ans>=0) return ans;
    int s = 0;
    for(auto c: coins) s += c;
    double res = 0;
    for(int i=0;i<3;i++){
        vector<int>nxt(coins);
        nxt[i] ++;
        res += (double)coins[i] / s * (1+dfs(nxt));
    }
    return ans = res;
}

int main(){
    vector<int> coins(3);
    for(int i=0;i<3;i++) cin>>coins[i];
    sort(coins.rbegin(), coins.rend());
    memset(ret, -1, sizeof ret);
    printf("%.12f\n", dfs(coins));
    return 0;
}