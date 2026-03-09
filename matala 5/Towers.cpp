#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> tops;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;

        auto it = upper_bound(tops.begin(), tops.end(), x);

        if (it == tops.end())
            tops.push_back(x);
        else
            *it = x;
    }

    cout << tops.size();
}