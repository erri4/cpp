#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> dijkstra(ll n, vector<vector<pair<ll, ll>>> edges, ll src){
	vector<ll> dist(n, 1e18);
    dist[src] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; // {w, node}
    pq.push({0, src});

    pair<ll, ll> top;
    while (!pq.empty()){
        top = pq.top();
        pq.pop();
        if (top.first > dist[top.second]) continue;
        for (pair<ll, ll> edge : edges[top.second]){
            if (dist[edge.second] > dist[top.second] + edge.first || dist[edge.second] == 1e18){
                dist[edge.second] = dist[top.second] + edge.first;
                pq.push({dist[edge.second], edge.second});
            }
        }
    }
    return dist;
}

int main(){
    ll n; ll m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> graph(n + 1, vector<pair<ll, ll>>()); // graph[i]={{w, node with edge to i}, ...}
    ll a; ll b; ll c;
    for (ll i = 0; i < m; i++){
        cin >> a >> b >> c;
        graph[a].push_back({c, b});
    }
    vector<ll> res = dijkstra(n + 1, graph, 1);
    for (ll d : res){
        if (d != 1e18) cout << d << ' ';
    }
    return 0;
}