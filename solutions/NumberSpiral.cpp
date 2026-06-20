#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin >> t;
    vector<pair<ll, ll>> tests(t);
    for (ll i = 0; i < t; i++) cin >> tests[i].first >> tests[i].second;
    for (pair<ll, ll> c : tests){
        if (c.second >= c.first){
            if (c.second % 2 == 1) cout << c.second * c.second - c.first + 1 << '\n';
            if (c.second % 2 == 0) cout << (c.second - 1) * (c.second - 1) + 1 + c.first - 1 << '\n';
        }
        else {
            if (c.first % 2 == 1) cout << (c.first - 1) * (c.first - 1) + 1 + c.second - 1 << '\n';
            if (c.first % 2 == 0) cout << c.first * c.first - c.second + 1 << '\n';
        }
    }
    return 0;
}