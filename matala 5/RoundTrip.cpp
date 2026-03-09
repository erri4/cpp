#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs(vector<vector<ll>> &adj, vector<ll> &parent, vector<bool> &vis, vector<ll> &cycle, ll v, ll p) {
    vis[v] = true;
    parent[v] = p;

    for (ll u : adj[v]) {
        if (u == p) continue;

        if (vis[u]) {
            cycle.push_back(u);
            ll cur = v;
            while (cur != u) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(u);
            return true;
        }

        if (dfs(adj, parent, vis, cycle, u, v)) return true;
    }

    return false;
}

int main() {
    ll n, m;
    vector<vector<ll>> adj;
    vector<ll> parent;
    vector<bool> vis;
    vector<ll> cycle;
    cin >> n >> m;

    adj.resize(n + 1);
    parent.resize(n + 1);
    vis.resize(n + 1, false);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (ll i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(adj, parent, vis, cycle, i, -1)) {
                cout << cycle.size() << "\n";
                for (ll x : cycle) cout << x << " ";
                cout << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}