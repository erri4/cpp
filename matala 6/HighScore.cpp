#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dfs(vector<vector<ll>> graph /* now 1->0 */, ll src, ll bad){
    queue<vector<ll>> q;
    vector<bool> visited(graph.size(), false);
    for (ll i = 0; i < graph.size(); i++){
        if (graph[i][1] == src){
            q.push(graph[i]);
            visited[i] = true;
        }
    }
    while (!q.empty()){
        if (q.front()[0] == bad) return true;
        for (ll i = 0; i < graph.size(); i++){
            if (graph[i][1] == q.front()[0] && !visited[i]){
                q.push(graph[i]);
                visited[i] = true;
            }
        }
        q.pop();
    }
    return false;
}

ll bellman_ford(ll n, vector<vector<ll>> edges, ll src){
	vector<ll> dist(n, 1e8);
	dist[src] = 0;
    
	for (ll i = 0; i < n; i++){
		for (vector<ll> edge : edges){
			ll u = edge[0];
			ll v = edge[1];
			ll wt = edge[2];
			if (dist[u] != 1e8 && (dist[u] + wt < dist[v] || dist[v] == 1e8)){
                if (i == n - 1){
                    if (dfs(edges, n - 1, u)) return 1;
                }
                dist[v] = dist[u] + wt;
            }
		}
	}

    return dist[n - 1];
}

int main(){
    ll n; ll m;
    cin >> n >> m;

    vector<vector<ll>> graph(m, vector<ll>(3)); // 0 -> 1, w=2
    for (ll i = 0; i < m; i++){
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
        graph[i][2] *= -1;
    }
    cout << -bellman_ford(n + 1, graph, 1);
    return 0; 
}