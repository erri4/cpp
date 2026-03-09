#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> parent(n);
    vector<ll> deg(n, 0);
    vector<ll> res(n, 0);

    for (ll i = 1; i < n; i++) {
        cin >> parent[i];
        parent[i]--;
        deg[parent[i]]++;
    }

    queue<ll> q;

    for (ll i = 0; i < n; i++) {
        if (deg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        ll v = q.front();
        q.pop();

        if (v == 0) continue;

        ll p = parent[v];
        res[p] += res[v] + 1;

        deg[p]--;
        if (deg[p] == 0) {
            q.push(p);
        }
    }

    for (ll x : res){
        cout << x << " ";
    }
}