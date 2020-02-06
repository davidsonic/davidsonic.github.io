#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 100010;

int n, m;
int A[N];
int C[N];
int pre[N];
int ans[N];

struct Node{
    int x, id, flag;
};

vector<Node>query[N];

void add(int x, int a){
    while(x<=n){
        C[x] += a;
        x += x&-x;
    }
}

int sum(int x){
    int res = 0;
    while(x){
        res+= C[x];
        x-= x&-x;
    }
    return res;
}


void init(){
    for(int i=1;i<=n;i++) pre[i] = pre[i-1] + A[i];
    for(int i=1;i<=n;i++)
        C[i] = pre[i] - pre[i-(i&-i)];
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++){
        scanf("%d", &A[i]);
    }

    for(int i=1;i<=m;i++){
        int L, R, x;
        scanf("%d%d%d", &L, &R, &x);
        query[R].push_back((Node){x, i, 1});
        query[L-1].push_back((Node){x, i, -1});
    }

//    for(int i=1;i<=n;i++) add(A[i], 1);  wrong
//  下标有序，按序点亮二进制值， 权值树状数组
    for(int i=1;i<=n;i++){
        add(A[i], 1);
        for(int j=0;j<query[i].size();j++){
            ans[query[i][j].id] += query[i][j].flag * sum(query[i][j].x);
        }
    }

//    离线回答询问,
    for(int i=1;i<=m;i++)
        printf("%d\n", ans[i]);
    return 0;
}