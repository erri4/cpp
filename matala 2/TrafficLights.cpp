#include <iostream>
#include <vector>
#include <set>

#define print(data) (std::cout << data << ' ')
#define input(var) (std::cin >> var)

using ll = long long;
using std::vector;
using std::set;
using std::multiset;

vector<ll> TrafficLights(ll x, ll n, const vector<ll>& pos) {
    set<ll> lights = {0, x};
    multiset<ll> segments = {x};
    vector<ll> results;

    for (ll p : pos) {
        auto it = lights.upper_bound(p);
        ll j = *it;
        ll i = *std::prev(it);

        segments.erase(segments.find(j - i));

        segments.insert(p - i);
        segments.insert(j - p);

        lights.insert(p);

        results.push_back(*segments.rbegin());
    }

    return results;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll x;
    ll n;
    input(x); input(n);
    vector<ll> pos(n);
    for (ll i = 0; i < n; ++i){
        input(pos[i]);
    }

    auto ans = TrafficLights(x, n, pos);
    for (ll v : ans){
        print(v);
    }
    return 0;
}
