#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, capacity;
    cin >> n >> capacity;

    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(capacity + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {

            ll skip = dp[i - 1][j];

            ll take = 0;
            if (v[i - 1].first <= j)
            {
                take = v[i - 1].second + dp[i - 1][j - v[i - 1].first];
            }

            dp[i][j] = max(take, skip);
        }
    }

    cout << dp[n][capacity] << '\n';

    return 0;
}