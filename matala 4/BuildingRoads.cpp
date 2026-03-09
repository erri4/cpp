#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, false);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> reps;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            reps.push_back(i);
            dfs(i);
        }
    }

    cout << reps.size() - 1 << "\n";
    for(int i = 1; i < (int)reps.size(); i++){
        cout << reps[i - 1] << " " << reps[i] << "\n";
    }

    return 0;
}
