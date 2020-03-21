#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 15010;

int n;
vector<pair<int,int> > coords;

bool cmp(const pair<int,int>&p1, const pair<int,int>&p2){
    if(p1.second!=p2.second){
        return p1.second<p2.second;
    }else return p1.first<p2.first;
}

const int M = 32001;
int c[M+2];
int lowbit(int x){
    return x & -x;
}

int ans[N];

void add(int x, int d){
    for(int i=x;i<=M;i+=lowbit(i)){
        c[i] += d;
    }
}

int query(int x){
    int ans = 0;
    for(int i=x;i>0;i-=lowbit(i)){
        ans += c[i];
    }
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int x, y;
        scanf("%d%d", &x, &y);
        coords.push_back(make_pair(x, y));
    }
    sort(coords.begin(), coords.end(), cmp);

    // bit_tree can't deal with zero
    for(int i=0;i<coords.size();i++) {
        add(coords[i].first + 1, 1);
        ans[query(coords[i].first+1) ]++;
    }

    for(int i=1;i<=n;i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}