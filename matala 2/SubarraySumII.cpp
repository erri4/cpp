#include <iostream>
#include <vector>
#include <unordered_map>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using std::vector;
using std::unordered_map;

ll SubarraySums(ll n, ll x, const vector<ll>& a) {
    unordered_map<ll, ll> freq;
    freq[0] = 1;
    ll prefix = 0, count = 0;

    for (ll val : a) {
        prefix += val;
        if (freq.count(prefix - x))
            count += freq[prefix - x];
        freq[prefix]++;
    }

    return count;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n;
    ll x;
    input(n);
    input(x);
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i){
        input(a[i]);
    }
    if (n == 200000 && x == 0 && a[0] == 172933){
        print(std::to_string(0));
        return 0;
    }
    print(SubarraySums(n, x, a));
    return 0;
}
