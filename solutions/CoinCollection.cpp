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

template<typename T1, typename T2, typename T3>
struct trio{
    T1 first;
    T2 second;
    T3 third;
};


ll CoinCollection(vector<ll> numbers){
    ll max = 0;
    for (ll i = 0; i < numbers.size(); i++){
        ll sum = 0;
        for (ll j = i; j < numbers.size(); j++){
            sum += numbers[j];
            if (sum % 7 == 0 && sum != 0 && j - i + 1 > max){
                max = j - i + 1;
            }
        }
    }
    return max;
}

int main(){
    ll n;
    input(n);
    vector<ll> nums;
    for (ll i = 0; i < n; i++){
        ll num;
        input(num);
        nums.push_back(num);
    }
    print(CoinCollection(nums));
    return 0;
}