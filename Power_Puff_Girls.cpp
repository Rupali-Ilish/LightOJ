#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// starting from h and getting all distance
// max distance of a,b,c is the answer

ll n, m, srci, srcj;
char a[30][30];
ll vis[30][30];
ll dis[30][30];

vector<pair<ll, ll>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(ll i, ll j)
{
    if (i < 0 or i >= n or j < 0 or j >= m or a[i][j] == '#' or a[i][j]=='m')
        return false;
    return true;
}

void bfs(ll srci, ll srcj)
{
    queue<pair<ll, ll>> q;
    q.push({srci, srcj});
    vis[srci][srcj] = true;
    dis[srci][srcj] = 0;
    while (!q.empty())
    {
        pair<ll, ll> par = q.front();
        q.pop();
        for (ll i = 0; i < 4; i++)
        {
            ll childi = par.first + d[i].first;
            ll childj = par.second + d[i].second;
            if (valid(childi, childj) and vis[childi][childj] == false)
            {
                q.push({childi, childj});
                vis[childi][childj] = true;
                dis[childi][childj] = dis[par.first][par.second] + 1;
            }
        }
    }
}

void khali()
{
    for (ll i = 0; i < 30; i++)
    {
        for (ll j = 0; j < 30; j++)
        {
            a[i][j] = ' ';
            vis[i][j] = false;
            dis[i][j] = -1;
        }
    }
}

int32_t main()
{
    fast_io;

    ll t, tc = 0;
    cin >> t;
    while (t--)
    {
        khali();
        cout << "Case " << ++tc << ": ";

        cin >> n >> m;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'h')
                {
                    srci = i;
                    srcj = j;
                }
            }
        }

        bfs(srci, srcj);

        ll ans = -1;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (a[i][j] == 'a' or a[i][j] == 'b' or a[i][j] == 'c')
                {
                    ans = max(ans, dis[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
}