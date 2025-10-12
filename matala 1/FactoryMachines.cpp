#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <climits>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector;
using std::pair;
using std::array;
using std::sort;
using std::max;

ll FactoryMachines(vector<ll> machines, ll t, ll min){
    ll left = 0;
    ll right = min * t;

    while (left < right) {
        ll mid = left + (right - left) / 2;
        __int128 produced = 0;
        for (ll i = 0; i < machines.size(); i++) {
            produced += mid / machines[i];
            if (produced >= t) break;
        }
        if (produced >= t) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main(){
    ll n, t;
    input(n);
    input(t);
    vector<ll> machines;
    ll min = LLONG_MAX;
    for (ll i = 0; i < n; i++){
        ll machine;
        input(machine);
        min = std::min(min, machine);
        machines.push_back(machine);
    }
    print(FactoryMachines(machines, t, min));
    return 0;
}