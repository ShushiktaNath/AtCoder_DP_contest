// Author : Shushikta Nath Puspa
//  Problem: https://atcoder.jp/contests/dp/tasks/dp_h
//  Time: O(r*c), space : O(c)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    vector<string> grid(r);
    vector<ll> dp(c, 0);

    for (int i = 0; i < r; i++)
        cin >> grid[i];

    dp[0] = 1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == '#')
            {
                dp[j] = 0;
            }
            else if (j != 0)
            {
                dp[j] = (dp[j] + dp[j - 1]) % mod;
            }
        }
    }

    cout << dp[c - 1] << '\n';

    return 0;
}