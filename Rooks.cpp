#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
ll nCr(ll n, ll r)
{
    double sum = 1;
    for (ll i = 1; i <= r; i++)
    {
        sum = sum * (n - r + i) / i;
    }
    return (ll)sum;
}
ll nPr(ll n, ll r)
{
    ll result = 1;
    for (ll i = 0; i < r; i++)
    {
        result *= (n - i);
    }
    return result;
}
int32_t main()
{
    fast_io;

    ll t, tc = 0;
    cin >> t;
    while (t--)
    {
        cout << "Case " << ++tc << ": ";
        ll n, k;
        cin >> n >> k;
        ll ans = nPr(n, k) * nCr(n, k);
        cout << ans << endl;
    }
}