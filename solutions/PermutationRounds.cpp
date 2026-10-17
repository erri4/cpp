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

ll lcm(vector<ll>& arr) {
    if (arr.empty()) return 0;

    ll M = *max_element(arr.begin(), arr.end());
    vector<ll> spf(M + 1);
    vector<ll> primes;
    for (ll i = 2; i <= M; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (ll p : primes) {
            if (p > spf[i] || i * p > M) break;
            spf[i * p] = p;
        }
    }

    vector<ll> max_power(M + 1, 0);
    for (ll num : arr){
        ll temp = num;
        while (temp > 1){
            ll p = spf[temp];
            ll count = 0;
            while (temp % p == 0){
                count++;
                temp /= p;
            }
            max_power[p] = max(max_power[p], count);
        }
    }
    ll lcm = 1;
    for (ll p = 2; p <= M; p++){
        if (max_power[p] > 0){
            lcm = (lcm * power(p, max_power[p])) % MOD;
        }
    }

    return lcm;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> perm(n);
    for (ll i = 0; i < n; i++) cin >> perm[i];
    vector<bool> visited(n, false);
    vector<ll> lens;

    for (ll i = 0; i < n; i++){
        if (!visited[i]){
            ll len = 0;
            ll curr = i;
            while (!visited[curr]){
                visited[curr] = true;
                curr = perm[curr] - 1;
                len++;
            }
            
            lens.push_back(len);
        }
    }
    cout << lcm(lens);
    return 0;
}