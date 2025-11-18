#include <iostream>
#include <vector>
#include <algorithm>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using std::vector;
using std::pair;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n;
    input(n);
    vector<pair<ll, ll>> tasks(n);
    for (ll i = 0; i < n; ++i){
        input(tasks[i].first), input(tasks[i].second);
    }

    std::sort(tasks.begin(), tasks.end());

    ll time = 0, reward = 0;
    for (auto [a, d] : tasks) {
        time += a;
        reward += d - time;
    }

    print(reward);
    return 0;
}
