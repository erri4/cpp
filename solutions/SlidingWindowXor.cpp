#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; ll k;
    cin >> n >> k;
    ll x; ll a; ll b; ll c;
    cin >> x >> a >> b >> c;
    ll w_xor = 0;
    ll xr = 0;
    ll x_n = x;
    for (ll i = 0; i < k; i++){
        w_xor ^= x_n;
        x_n = a * x_n + b;
        x_n %= c;
    }
    xr ^= w_xor;
    for (ll i = k; i < n; i++){
        w_xor ^= x;
        x = a * x + b;
        x %= c;
        w_xor ^= x_n;
        xr ^= w_xor;
        x_n = a * x_n + b;
        x_n %= c;
    }
    cout << xr;
}