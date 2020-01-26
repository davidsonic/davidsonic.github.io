#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 1010;
int n, m;
bool st[N];
int main()
{
    cin >> m >> n;
    int res = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!st[x])
        {
            res++;
            if (q.size() == m)
            {
                st[q.front()] = false;
                q.pop();
            }
            q.push(x);
            st[x] = true;
        }
    }
    cout << res << endl;
    return 0;
}