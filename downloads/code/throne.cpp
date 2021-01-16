#include <iostream>

using namespace std;

typedef long long ll;

int exgcd(int a, int b, ll &x, ll &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d= exgcd(b, a % b, y, x);
    y -= a/b  * (ll)x;
    return d;
}

int main() {
    int t;
    cin>>t;

    while (t--) {
        ll n,s,k;
        cin>>n>>s>>k;
        ll x, y;
        s = n-s;
        int g=exgcd(k, n, x, y);
        if (s%g!=0) {
            cout<<"-1\n";
            continue;
        }

        x = (ll)x * (s/g);
        x = (x%(n/g) + n/g) % (n/g);
        cout<<x<<endl;
    }

    return 0;
}