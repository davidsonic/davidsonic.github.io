#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int N = 400010;
struct node{
    int mp[3][3];
    int x, y;
    int step, h;
    bool operator < (const node&A) const {
        return step+h > A.step + A.h;
    }
}now;

priority_queue<node> Q;
int F[10];

// 康拓展开
int Hash(int A[3][3]){
    int res = 0;
    char s[10]; int k=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) s[k++] = A[i][j];

    int t = 0;
    for(int i=0;i<k;i++){
        t = s[i];
        for(int j=0;j<i;j++)
            if(s[j] < s[i]) t--;
        res += (t-1) * F[8-i];
    }
    return res;
}

int st[N];
int rx[] = {0, -1, 0, 1};
int ry[] = {-1, 0, 1, 0};

bool check(int x, int y){
    return x>=0 && x <3 && y>=0 && y<3;
}

int H(int A[3][3]){
    int res = 0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(A[i][j] == 9) continue;
            int x = (A[i][j] - 1) /3;
            int y = (A[i][j] - 1) %3;
            res += abs(i-x) + abs(j-y);
        }
    return res;
}


int bfs(){
    now.step = 0; now.h = H(now.mp);
    Q.push(now);
    int h = Hash(now.mp);
    if(h==0) return 0;
    while(!Q.empty()){
        now = Q.top(); Q.pop();
        int h = Hash(now.mp);
        if(h==0) return now.step;  //弹出来时最优
        if(st[h]) continue;  //类比dijstra
        st[h] = 1;
        for(int i=0;i<4;i++){
            if (check(now.x + rx[i], now.y + ry[i])){
                swap(now.mp[now.x + rx[i]][now.y + ry[i]], now.mp[now.x][now.y]);
                now.x += rx[i], now.y += ry[i]; now.step ++; now.h = H(now.mp);
                Q.push(now); // no if before entering priority_queue
                now.x -= rx[i], now.y -= ry[i], now.step--;
                swap(now.mp[now.x + rx[i]][now.y + ry[i]], now.mp[now.x][now.y]); now.h = H(now.mp);
            }
        }
    }
    return -1;
}


int main(){
    F[0] = 1;
    for(int i=1;i<10;i++) F[i] = F[i-1] * i;

    char s[10];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++) {
            scanf("%s", s);
            if (s[0] == 'x') {
                now.x = i, now.y = j;
                s[0] = '9';
            }
            now.mp[i][j] = s[0] - '0';
        }

    printf("%d\n", bfs());
    return 0;
}