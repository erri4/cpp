#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ll n; ll k;
    cin >> n >> k;
    ordered_set<ll> s;

    for (ll i = 1; i <= n; i++){
        s.insert(i);
    }

    ll pos = 0;
    while (!s.empty()){
        pos = (pos + k) % s.size();
        auto it = s.find_by_order(pos);
        cout << *it << ' ';
        s.erase(it);
    }
    return 0;
}