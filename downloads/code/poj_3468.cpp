#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll N,tree1[100001],tree2[100001];
ll a[100001];
int lowbit(int x)
{
    return (x&(-x));
}
 void update(ll x ,ll val)
{
    ll i;
    for( i = x ; i <= N;i+=lowbit(i) )
    {
        tree1[i]+=val;
        tree2[i]+=x*val;
    }
}
ll query(ll x)
{
    ll i;
    ll sum=0;
    for( i = x ; i > 0 ;i-=lowbit(i))
    {
        sum+=(x+1)*tree1[i]-tree2[i];
    }
    return sum;
}
int main()
{
    ll  Q , i , A ,B , C;
    string s;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    a[0]=0;
    for ( i = 1 ;i <= N ; i++)
    {
         cin >> a[i];
         update(i ,a[i]-a[i-1]);
    }
    for ( i = 1 ; i <= Q ; i ++)
    {
        cin >> s;
        if(s[0]=='Q')
        {
            cin >> A >> B ;
            cout << query (B)- query(A-1)<<endl;
        }
        else
        {
            cin >> A >> B >> C;
            update(A , C);
            update(B+1 ,-C );
        }
    }
}