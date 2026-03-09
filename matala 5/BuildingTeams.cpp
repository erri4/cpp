#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n + 1);

    for (ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<ll> team(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        if (team[i]) continue;

        queue<ll> q;
        q.push(i);
        team[i] = 1;

        while (!q.empty()) {
            ll u = q.front();
            q.pop();

            for (ll v : adj[u]) {
                if (!team[v]) {
                    team[v] = 3 - team[u];
                    q.push(v);
                } 
                else if (team[v] == team[u]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }
    for (ll i = 1; i <= n; i++){
        cout << team[i] << " ";
    }
    return 0;
}