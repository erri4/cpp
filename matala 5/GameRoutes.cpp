#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1000000007;


int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);
    vector<ll> indeg(n + 1, 0);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    queue<ll> q;

    for (ll i = 1; i <= n; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }

    vector<ll> dp(n + 1, 0);
    dp[1] = 1;

    while (!q.empty()) {
        ll v = q.front();
        q.pop();

        for (ll u : adj[v]) {
            dp[u] = (dp[u] + dp[v]) % MOD;

            indeg[u]--;
            if (indeg[u] == 0)
                q.push(u);
        }
    }

    cout << dp[n];
    return 0;
}