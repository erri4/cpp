#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n; ll m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n + 1);
    ll a; ll b; ll c;
    for (ll i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<vector<ll>> dist(n + 1, vector<ll>(2, 1e18));
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;

    dist[1][0] = 0;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [d, u, used] = pq.top();
        pq.pop();

        if (d != dist[u][used]) continue;

        for (auto [v, w] : adj[u]) {

            if (dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }

            if (!used) {
                ll nd = d + w / 2;

                if (dist[v][1] > nd) {
                    dist[v][1] = nd;
                    pq.push({nd, v, 1});
                }
            }
        }
    }
    cout << dist[n][1] << '\n';

    return 0;
}