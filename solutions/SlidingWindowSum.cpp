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
using std::max;

vector<ll> dp = {0};

ll xi(ll i, ll a, ll b, ll c, ll x){
    if (i == 1){
        if (dp.size() == 1){
            dp.push_back(x);
        }
        return x;
    }
    if (dp.size() > i){
        return dp[i];
    }
    dp.push_back((a*xi(i - 1, a, b, c, x) + b) % c);
    return dp[i];
}

ll SlidingWindowSum(ll n, ll k, ll x, ll a, ll b, ll c){
    ll r = 0;
    ll sum = 0;
    vector<ll> window;
    for (ll i = 1; i <= k; i++){
        ll x_i = xi(i, a, b, c, x);
        sum += x_i;
    }
    ll i = 1;
    while (i + k - 1 <= n){
        r ^= sum;
        ll x_i = xi(i + 1, a, b, c, x);
        ll x_ik = xi(i + k, a, b, c, x);
        sum -= x_i;
        sum += x_ik;
        i++;
    }
    return r;
}

int main(){
    ll n, k, x, a, b, c;
    input(n >> k >> x >> a >> b >> c);
    print(SlidingWindowSum(n, k, x, a, b, c));
    return 0;
}