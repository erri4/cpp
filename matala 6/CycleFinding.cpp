#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void bellman_ford(ll n, vector<vector<ll>> edges, ll src){
	vector<ll> dist(n + 1, 0);
    vector<ll> parent(n + 1, -1);

    ll x = -1;

    for (ll i = 1; i <= n; i++) {
        x = -1;
        for (auto &e : edges) {
            ll u = e[0], v = e[1], w = e[2];
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO";
        return;
    }
    for (ll i = 0; i < n; i++) {
        x = parent[x];
    }

    vector<ll> cycle;
    ll cur = x;
    cycle.push_back(cur);
    cur = parent[cur];
    while (cur != x){
        cycle.push_back(cur);
        cur = parent[cur];
    }

    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (ll v : cycle) cout << v << " ";
}

int main(){
    ll n; ll m;
    cin >> n >> m;

    vector<vector<ll>> graph(m, vector<ll>(3)); // 0 -> 1, w=2
    for (ll i = 0; i < m; i++){
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
        if (graph[i][0] == graph[i][1] && graph[i][2] < 0){
            cout << "YES\n" << graph[i][0] << ' ' << graph[i][0];
            return 0;
        }
    }
    bellman_ford(n + 1, graph, 1);
    return 0; 
}