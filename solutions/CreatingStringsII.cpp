#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

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
    if (a == 0 || a == 1 || b == 1) return a;
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
    string str;
    cin >> str;
    vector<int> chars(str.begin(), str.end());
    vector<ll> diff(124);
    vector<ll> fact;
    fact.push_back(1);
    sort(chars.begin(), chars.end());
    for (ll i = 0; i < chars.size(); i++){
        fact.push_back((fact[fact.size() - 1] * fact.size()) % MOD);
        diff[chars[i]]++;
    }
    ll s = fact[chars.size()];
    for (ll i = 0; i < diff.size(); i++){
        s *= pow(fact[diff[i]], MOD - 2, MOD);
        s %= MOD;
    }
    cout << s;
    return 0;
}