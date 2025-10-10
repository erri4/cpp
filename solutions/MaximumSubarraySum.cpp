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

ll MaximumSubarraySum(vector<ll> arr){
    ll sum = arr[0];
    ll max = arr[0];
    for (ll i = 1; i < arr.size(); i++){
        sum = std::max(arr[i], sum + arr[i]);
        max = std::max(max, sum);
    }
    return max;
}

int main(){
    ll n;
    input(n);
    vector<ll> arr;
    for (ll i = 0; i < n; i++){
        ll item;
        input(item);
        arr.push_back(item);
    }
    print(MaximumSubarraySum(arr));
    return 0;
}