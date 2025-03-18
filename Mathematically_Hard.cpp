#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define pi acos(-1.0)
#define pb push_back
#define sqrt(x) sqrtl(x)
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
unsigned int phi[5000002];   // need to use 'int', otherwise memory limit
unsigned ll prephi[5000002]; // need to use 'unsigned', otherwise wrong
void phi_1_to_n(int n)
{
    for (int i = 0; i <= n; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }

    for (ll i = 2; i <= n; i++) // converting to unsigned ll 
    {
        prephi[i] = ((unsigned ll)phi[i] * (unsigned ll)phi[i]) + prephi[i - 1];
    }
}
int32_t main()
{
    fast_io;

    phi_1_to_n(5000000);

    ll t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        int a, b;
        cin >> a >> b;
        unsigned ll ans = prephi[b] - prephi[a - 1];
        cout << ans << endl;
    }
}