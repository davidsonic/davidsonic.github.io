#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#define M 40
using namespace std;
vector<int>R[M];
int A[M],B[M],n,ans;
void check(int &a,int b){
    if(a==-1||a>b)a=b;
}
void solve(int sum,int c){//c表示小A在右边需要的礼物数
    int id=lower_bound(R[c].begin(),R[c].end(),sum)-R[c].begin();
    if(id!=(int)R[c].size())
        check(ans,abs(sum-R[c][id]));
    if(id>0)
        check(ans,abs(sum-R[c][id-1]));
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
    for(i=0;i<n;i++)
        scanf("%d",&B[i]);
    int m=n/2;
    for(i=0;i<=n;i++)R[i].clear();
    for(i=0;i<(1<<(n-m));i++){//预处理右半部分
        int sum=0,c=0;
        for(j=0;j<n-m;j++){
            if(i&(1<<j)){
                sum-=A[m+j],c++;
            }else sum+=B[m+j];
        }
        R[c].push_back(sum);//sumB-sumA
    }
    for(i=0;i<=n-m;i++)sort(R[i].begin(),R[i].end());//每个个数对应的vector排序
    ans=-1;
    for(i=0;i<(1<<m);i++){//枚举左边分配情况
        int L=0,c=0;
        for(j=0;j<m;j++)
            if(i&(1<<j)){//sumA-sumB
                L+=A[j],c++;
            }else L-=B[j];
        if(n&1)solve(L,n/2+1-c);
        solve(L,n/2-c);
    }
    printf("%d\n",ans);
    return 0;
}