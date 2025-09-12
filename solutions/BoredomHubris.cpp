#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector;
using std::pair;
using std::array;
using std::sort;

ll BoredomHubris(vector<ll> s){
    ll sum = 0;
    for (ll i = 0; i < s.size(); i++){
        ll min = s[i];
        for (ll j = i; j < s.size(); j++){
            if (s[j] < min){
                min = s[j];
            }
            sum += min;
        }
    }
    return sum;
}

int main(){
    ll n;
    input(n);
    vector<ll> set;
    for (ll i = 0; i < n; i++){
        ll item;
        input(item);
        set.push_back(item);
    }
    print(BoredomHubris(set));
    return 0;
}