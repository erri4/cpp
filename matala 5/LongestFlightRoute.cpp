#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    for (ll i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);

    vector<ll> topo;

    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        topo.push_back(v);

        for (ll u : adj[v]) {
            indeg[u]--;
            if (indeg[u] == 0)
                q.push(u);
        }
    }

    vector<ll> dp(n + 1, -1);
    vector<ll> parent(n + 1, -1);

    dp[1] = 1;

    for (ll v : topo) {
        if (dp[v] == -1) continue;

        for (ll u : adj[v]) {
            if (dp[v] + 1 > dp[u]) {
                dp[u] = dp[v] + 1;
                parent[u] = v;
            }
        }
    }

    if (dp[n] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    vector<ll> path;
    ll cur = n;

    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (ll x : path){
        cout << x << " ";
    }
    return 0;
}