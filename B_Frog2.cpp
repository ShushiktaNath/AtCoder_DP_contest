// Author : Shushikta Nath Puspa
//  Problem: https://atcoder.jp/contests/dp/tasks/dp_b
//  Time: O(nk), Space : O(n)

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll inf = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> h(n), dp(n, inf);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = min(i, k); j >= 1; j--)
        {
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }

    cout << dp[n - 1] << '\n';
}