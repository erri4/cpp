#include <bits/stdc++.h>
using namespace std;
using ll = long long;

std::vector<ll> bfs(ll start, ll n, vector<vector<ll>> adj) {
    vector<ll> dist(n + 1, -1);
    queue<ll> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        ll v = q.front();
        q.pop();

        for (ll u : adj[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    return dist;
}

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> d = bfs(1, n, adj);
    ll A = max_element(d.begin() + 1, d.end()) - d.begin();

    vector<ll> distA = bfs(A, n, adj);
    ll B = max_element(distA.begin() + 1, distA.end()) - distA.begin();

    vector<ll> distB = bfs(B, n, adj);

    for (ll i = 1; i <= n; i++){
        cout << max(distA[i], distB[i]) << " ";
    }
    return 0;
}