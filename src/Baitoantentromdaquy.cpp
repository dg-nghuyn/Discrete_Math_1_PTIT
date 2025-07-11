/*
n la so luong da quy
loai thu i co khoi luong wi, gia tri vi
trong tai la W (Weight)
*/

#include <bits/stdc++.h>

using namespace std;

void enter(int &n, int &W, vector < pair < int, int > > gems)
{
    cin >> n >> W;

    gems.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> gems[i].first >> gems[i].second;
}

void trace_back(int n, int W, vector < int > &dp, vector < pair < int, int > > &gems)
{
    vector < int > chosen_times(n + 1, 0);
    while (W != 0)
    {
        for (int i = 1; i <= n; ++i)
            if (dp[W] == dp[W - gems[i].first] + gems[i].second)
            {
                W -= gems[i].first;
                ++chosen_times[i];
                break;
            }
    }

    for (int e: chosen_times)
        cout << e << ' ';
}

void solution(int n, int W, vector < pair < int, int > > gems)
{
    vector < int > dp(W + 1, 0);
    for (int i = 0; i <= W; ++i)
        for (int j = 1; j <= n; ++j)
            if (i >= gems[j].first)
                dp[i] = max(dp[i], dp[i - gems[j].first] + gems[j].second);

    cout << dp[W] << endl;
    trace_back(n, W, dp, gems);
}

main()
{
    int n, W;
    vector < pair < int, int > > gems;

    enter(n, W, gems);
    solution(n, W, gems);
}
