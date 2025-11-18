#include <iostream>
#include <vector>
#include <algorithm>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using std::vector;

bool canDivide(const vector<ll> &a, ll maxSum, int k) {
    ll count = 1;
    ll currentSum = 0;
    for (ll x : a) {
        if (x > maxSum) return false;
        if (currentSum + x > maxSum) {
            count++;
            currentSum = x;
        }
        else {
            currentSum += x;
        }
    }
    return count <= k;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n;
    ll k;
    input(n);
    input(k);
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i){
        input(a[i]);
    }

    ll low = *std::max_element(a.begin(), a.end());
    ll high = 0;
    for (ll x : a) high += x;

    ll ans = high;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (canDivide(a, mid, k)) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    print(ans);
    return 0;
}
