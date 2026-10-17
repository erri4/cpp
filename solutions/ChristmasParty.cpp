#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll pow2(ll n){
    if (n % 2) return -1;
    return 1;
}

int main(){
    ll n;
    cin >> n;
    ll D = 1;
    for (ll i = 1; i <= n; i++) D = (i * D + pow2(i)) % MOD;
    cout << D;
    return 0;
}