#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs1(ll v, ll p, ll depth, vector<vector<ll>>& g, vector<ll>& sub, vector<ll>& ans){
    ans[1] += depth;
    sub[v] = 1;
    for (ll u : g[v]) {
        if (u == p) continue;
        dfs1(u, v, depth + 1, g, sub, ans);
        sub[v] += sub[u];
    }
}

void dfs2(ll v, ll p, vector<vector<ll>>& g, vector<ll>& sub, vector<ll>& ans, ll n) {
    for (ll u : g[v]) {
        if (u == p) continue;
        ans[u] = ans[v] + n - 2 * sub[u];
        dfs2(u, v, g, sub, ans, n);
    }
}

int main() {ll n;
    cin >> n;
    vector<vector<ll>> g(n + 1);
    vector<ll> sub(n + 1, 0);
    vector<ll> ans(n + 1, 0);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1, 0, 0, g, sub, ans);
    dfs2(1, 0, g, sub, ans, n);
    for (ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}