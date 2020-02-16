#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 400010;
struct node{
    int mp[3][3];
    int x, y;
    int step;
    int h;
}Q[N], now;

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


int bfs(){
    int L = 0, R = -1;
    now.step = 0;
    Q[++R] = now;
    int h;
    st[h = Hash(now.mp)] = 1;
    if(h==0) return 0;
    while(L<=R){
        now = Q[L++];
        for(int i=0;i<4;i++){
            if (check(now.x + rx[i], now.y + ry[i])){
                swap(now.mp[now.x + rx[i]][now.y + ry[i]], now.mp[now.x][now.y]);
                now.x += rx[i], now.y += ry[i];
                now.step ++;
                int h = Hash(now.mp);
                if(h==0) return now.step;
                if(!st[h]){
                    st[h] = 1;
                    Q[++R] = now;
                }
                now.x -= rx[i], now.y -= ry[i], now.step--;
                swap(now.mp[now.x + rx[i]][now.y + ry[i]], now.mp[now.x][now.y]);
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