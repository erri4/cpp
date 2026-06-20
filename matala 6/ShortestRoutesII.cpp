#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; ll m; ll q;
    cin >> n >> m >> q;
    vector<vector<ll>> graph(n + 1, vector<ll>(n + 1, -1));
    ll x; ll y; ll c;
    for (ll i = 0; i < m; i++){
        cin >> x >> y >> c;
        if (graph[x][y] == -1) graph[x][y] = c;
        else graph[x][y] = min(graph[x][y], c);
        if (graph[y][x] == -1) graph[y][x] = c;
        else graph[y][x] = min(graph[y][x], c);
    }
    for (ll i = 0; i < n + 1; i++) graph[i][i] = 0;
    vector<pair<ll, ll>> queries(q);
    for (ll i = 0; i < q; i++) cin >> queries[i].first >> queries[i].second;
    
    for (ll k = 0; k < n + 1; k++){
        for (ll i = 0; i < n + 1; i++){
            for (ll j = 0; j < n + 1; j++){
                if (graph[i][k] != -1 && graph[k][j]!= -1){
                    if (graph[i][j] > -1) graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    else graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    for (auto query : queries) cout << graph[query.first][query.second] << '\n';
    return 0;
}