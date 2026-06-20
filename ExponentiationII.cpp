#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

vector<ll> bin(ll n){
    if (n == 0) return {0};

    vector<ll> binary;
    while (n > 0) {
        ll remainder = n % 2;
        binary.push_back(remainder);
        n /= 2;
    }
    
    return binary;
}

ll pow(ll a, ll b, ll mod){ // a^b // O(logb)
    ll c = 1; vector<ll> binb; vector<ll> binc;
    a %= mod;
    binb = bin(b);
    for (ll j = 0; j < binb.size(); j++){
        if (j == 0) binc.push_back(a);
        else binc.push_back((binc[j - 1] * binc[j - 1]) % mod);
    }
    for (ll j = 0; j < binc.size(); j++){
        if (binb[j]){
            c *= binc[j];
            c %= mod;
        }
    }
    return c;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> res;
    ll a; ll b; ll c;
    for (ll i = 0; i < n; i++){
        cin >> a >> b >> c;
        res.push_back(pow(a, pow(b, c, MOD - 1), MOD));
    }
    for (ll i : res) cout << i << '\n';
    return 0;
}