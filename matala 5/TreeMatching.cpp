#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll v, ll p, vector<vector<ll>>& g, vector<vector<ll>>& dp) {
    ll base = 0;
    for (ll u : g[v]) {
        if (u == p) continue;
        dfs(u, v, g, dp);
        base += max(dp[u][0], dp[u][1]);
    }
    dp[v][0] = base;
    for (ll u : g[v]) {
        if (u == p) continue;
        ll cand = base - max(dp[u][0], dp[u][1]) + dp[u][0] + 1;
        dp[v][1] = max(dp[v][1], cand);
    }
}

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0, g, dp);
    cout << max(dp[1][0], dp[1][1]);
    return 0;
}