#include <iostream>
#include <vector>
#include <algorithm>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector;
using std::pair;
using std::sort;

bool reverse(ll a, ll b){
    return a > b;
}

ll SportCheat(vector<ll> a, vector<ll> p){
    vector<ll> dp(p.size(), 0); // dp[i]: number of times player i (with index i in p) runned
    for (ll i = 0; i < p.size(); i++){
        dp[p[i]]++; // O(N)
    }
    sort(dp.begin(), dp.end()); // O(Nlog(N))
    sort(a.begin(), a.end(), reverse); // O(Nlog(N))
    ll eggs = 0;
    for (ll i = 0; i < dp.size(); i++){
        eggs += dp[i] * a[i];
    }
    return eggs;
}

int main(){
    ll n;
    input(n);
    vector<ll> a;
    vector<ll> p;
    for (ll i = 0; i < n; i++){
        ll a_i;
        input(a_i);
        a.push_back(a_i);
    }
    for (ll i = 0; i < n; i++){
        ll p_i;
        input(p_i);
        p.push_back(p_i);
    }
    print(SportCheat(a, p));
    return 0;
}