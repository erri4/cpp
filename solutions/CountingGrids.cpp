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

ll power(ll a, ll b){ // a^b // O(logb)
    ll c = 1;
    vector<ll> binb; vector<ll> binc;
    binb = bin(b);
    for (ll j = 0; j < binb.size(); j++){
        if (j == 0) binc.push_back(a);
        else binc.push_back((binc[j - 1] * binc[j - 1]) % MOD);
    }
    for (ll j = 0; j < binc.size(); j++){
        if (binb[j]){
            c *= binc[j];
            c %= MOD;
        }
    }
    return c;
}

ll inv(ll n) {
    return power(n, MOD - 2);
}

int main(){
    ll n;
    cin >> n;
    if (n % 2 == 0){
        ll T1 = power(2, n * n);
        ll T2 = power(2, (n * n) / 2);
        ll T4 = power(2, (n * n) / 4);
        cout << (T2-T4)/2 + T4 + (T1-T2)/4;
    }
    else{
        ll T1 = power(2, n * n);
        ll T2 = power(2, (n * n + 1) / 2);
        ll T4 = power(2, (n * n + 7) / 4);
        cout << (T1+T2+T4) * inv(4) % MOD;
    }
    return 0;
}