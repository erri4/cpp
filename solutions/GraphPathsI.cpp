#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

vector<vector<ll>> multiply(const vector<vector<ll>>& A, const vector<vector<ll>>& B, ll n) {
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        for (ll k = 0; k < n; k++) {
            if (A[i][k] == 0) continue;
            for (ll j = 0; j < n; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll k, ll n) {
    vector<vector<ll>> res(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    
    while (k > 0) {
        if (k & 1) {
            res = multiply(res, A, n);
        }
        A = multiply(A, A, n);
        k >>= 1;
    }
    return res;
}

int main() {
    ll n, m;
    ll k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<vector<ll>> graph(n, vector<ll>(n, 0));
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        u--; v--;
        graph[u][v]++;
    }
    vector<vector<ll>> result = power(graph, k, n);
    cout << result[0][n - 1];
    return 0;
}