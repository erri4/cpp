#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

class Qsqrt5{
    public:
    ll a;
    ll b;

    Qsqrt5(ll f, ll s){
        a = f;
        b = s;
    }

    Qsqrt5 operator*(Qsqrt5 other){
        return Qsqrt5((a * other.a + 5 * (b * other.b)) % MOD, (a * other.b + b * other.a) % MOD);
    }

    Qsqrt5 operator-(Qsqrt5 other){
        return Qsqrt5((a - other.a + MOD) % MOD, (b - other.b + MOD) % MOD);
    }

    bool operator==(Qsqrt5 other){
        return a == other.a && b == other.b;
    }
};

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

Qsqrt5 fpow(Qsqrt5 a, ll b){ // a^b // O(logb)
    Qsqrt5 c = Qsqrt5(1, 0);
    vector<ll> binb; vector<Qsqrt5> binc;
    binb = bin(b);
    for (ll j = 0; j < binb.size(); j++){
        if (j == 0) binc.push_back(a);
        else binc.push_back(binc[j - 1] * binc[j - 1]);
    }
    for (ll j = 0; j < binc.size(); j++){
        if (binb[j]){
            c = c * binc[j];
        }
    }
    return c;
}

ll fpow(ll a, ll b){ // a^b // O(logb)
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

ll fib(ll n){ // maximum is n=88
    auto phi = Qsqrt5(1, 1);
    auto psi = Qsqrt5(1, -1);
    return (fpow(phi, n) - fpow(psi, n)).b * fpow(fpow(2LL, n), MOD - 2) % MOD;
}

int main(){
    ll n;
    cin >> n;
    cout << fib(n);
    return 0;
}