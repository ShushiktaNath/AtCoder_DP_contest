// Author : Shushikta Nath Puspa
//  Problem: https://atcoder.jp/contests/dp/tasks/dp_a
//  Time: O(n), Space : O(1)

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> h(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    int a = 0, b = abs(h[1] - h[0]), c = 0;

    for (int i = 2; i < n; i++)
    {
        c = min(a + abs(h[i] - h[i - 2]), b + abs(h[i] - h[i - 1]));
        a = b;
        b = c;
    }

    cout << b << '\n';

    return 0;
}