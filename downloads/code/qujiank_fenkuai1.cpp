#include<bits/stdc++.h>
#define M 30005
using namespace std;
int A[M],B[M],S,num[M];
int get(int L,int R,int x){//在[L,R]范围内找<=x的个数
    int kl=L/S,kr=R/S,cnt=0;
    if(kl==kr){
        for(int i=L;i<=R;i++)
            cnt+=A[i]<=x;
    }else{
        for(int i=L;i<(kl+1)*S;i++)cnt+=A[i]<=x;
        for(int i=kl+1;i<kr;i++)cnt+=upper_bound(B+i*S,B+i*S+S,x)-(B+i*S);
        for(int i=kr*S;i<=R;i++)cnt+=A[i]<=x;
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
        num[i]=B[i]=A[i];
    }
    S=sqrt(n*log(n)/log(2));
    for(int i=S;i+S-1<=n;i+=S)sort(B+i,B+i+S); //第一个区间不排序
    sort(num+1,num+n+1);
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int L=1,R=n,res;
        while(L<=R){
            int mid=(L+R)>>1;
            int tmp=get(a,b,num[mid]);
            if(tmp>=c){
                res=num[mid];
                R=mid-1;
            }else L=mid+1;
        }
        printf("%d\n",res);
    }
    return 0;
}