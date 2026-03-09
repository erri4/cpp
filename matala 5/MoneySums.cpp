#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> coins(n);
    ll total = 0;
    for (ll &x : coins) {
        cin >> x;
        total += x;
    }

    vector<bool> possible(total + 1, false);
    possible[0] = true;

    for (ll c : coins) {
        for (ll s = total; s >= c; s--) {
            if (possible[s - c]) {
                possible[s] = true;
            }
        }
    }

    vector<ll> ans;
    for (ll s = 1; s <= total; s++) {
        if (possible[s]) ans.push_back(s);
    }

    cout << ans.size() << "\n";
    for (ll x : ans) cout << x << " ";
}