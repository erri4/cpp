#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n;
    input(n);
    std::vector<std::array<ll, 3>> customers(n);
    
    for (ll i = 0; i < n; ++i) {
        input(customers[i][0]) >> customers[i][1];
        customers[i][2] = i;
    }

    sort(customers.begin(), customers.end());

    std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, std::greater<>> pq;

    std::vector<ll> room_assignment(n);
    ll next_room_number = 0;

    for (auto [a, b, idx] : customers) {
        if (!pq.empty() && pq.top().first < a) {
            auto [dep, room] = pq.top();
            pq.pop();
            room_assignment[idx] = room;
            pq.push({b, room});
        } else {
            ++next_room_number;
            int room = next_room_number;
            room_assignment[idx] = room;
            pq.push({b, room});
        }
    }

    print(next_room_number);
    for (ll i = 0; i < n; ++i) {
        std::cout << room_assignment[i] << " ";
    }
    print("");

    return 0;
}
