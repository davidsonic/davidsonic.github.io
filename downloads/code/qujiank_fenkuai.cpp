#include<bits/stdc++.h>
#define M 30005
using namespace std;
int A[M],B[M],S,num[M];
int sum[180][M];
int get(int L,int R,int x){//在[L,R]范围内找<=x的个数
    int kl=L/S,kr=R/S,cnt=0;
    if(kl==kr){
        for(int i=L;i<=R;i++)
            cnt+=A[i]<=num[x];
    }else{
        for(int i=L;i<(kl+1)*S;i++)cnt+=A[i]<=num[x];
        for(int i=kl+1;i<kr;i++)cnt+=sum[i][x];
        for(int i=kr*S;i<=R;i++)cnt+=A[i]<=num[x];
    }
    return cnt;
}
int main(){

    freopen("kth.in","r",stdin);
    freopen("my.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
        num[i-1]=B[i]=A[i];
    }
    S=sqrt(n);
    sort(num,num+n);
    int v=unique(num,num+n)-num;
    for(int i=1;i<=n;i++){
        int k=lower_bound(num,num+v,A[i])-num;
        sum[i/S][k]++;
    }
    for(int i=1;i<=n/S;i++)//预处理每个块的前缀和
        for(int j=1;j<v;j++)sum[i][j]+=sum[i][j-1];

    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int L=0,R=v-1,res;
        while(L<=R){
            int mid=(L+R)>>1;
            int tmp=get(a,b,mid);
            if(tmp>=c){
                res=mid;R=mid-1;
            }else L=mid+1;
        }
        printf("%d\n",num[res]);
    }
    return 0;
}