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

typedef long long LL;
typedef pair<int,int> PII;
int h, w;
int n, m;
const int N = 1510;
int g[N][N];


int main(){
    cin>>h>>w>>n>>m;
    for(int i=0;i<n;i++){
        int a, b;
        scanf("%d%d", &a,&b);
        g[a][b] = 1;
    }
    for(int i=0;i<m;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = -1;
    }
    int res = 0;
    for(int i=1;i<=h;i++){
        bool flag = false;
        for(int j=1;j<=w;j++){
            if(g[i][j]==-1) flag = false;
            else if(g[i][j]==1) flag = true;
            else if(flag) g[i][j] = 2;
        }
        flag = false;
        for(int j=w;j>=1;j--){
            if(g[i][j]==-1) flag = false;
            else if(g[i][j]==1) flag = true;
            else if(flag) g[i][j] = 2;
        }
    }
    for(int j=1;j<=w;j++){
        bool flag = false;
        for(int i=1;i<=h;i++){
            if(g[i][j]==-1) flag = false;
            if(g[i][j]==1) flag = true;
            else if(flag) g[i][j] = 2;
        }
        flag = false;
        for(int i=h;i>=1;i--){
            if(g[i][j]==-1) flag = false;
            if(g[i][j]==1) flag = true;
            else if(flag) g[i][j] = 2;
        }
    }
    for(int i=1;i<=h;i++)
        for(int j=1;j<=w;j++)
            res += g[i][j] > 0;
    cout<<res<<endl;
    return 0;
}