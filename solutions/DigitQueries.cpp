#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> bin(ll n){
    if (n == 0) return {0};
    vector<ll> r;
    ll x = n;
    while (x > 0){
        r.push_back(x % 2);
        x /= 2;
    }
    return r;
}

vector<ll> dec(ll n){
    if (n == 0) return {0};
    vector<ll> tmp;
    ll x = n;
    while (x > 0){
        tmp.push_back(x % 10);
        x /= 10;
    }
    vector<ll> r(tmp.size());
    for (ll i = 0; i < tmp.size(); i++) r[i] = tmp[tmp.size() - i - 1];
    return r;
}

ll fpow(ll n, ll p){
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (p == 0) return 1;
    if (p == 1) return n;
    auto b = bin(p);
    vector<ll> squares(b.size(), 0);
    squares[0] = n;
    for (ll i = 1; i < b.size(); i++){
        squares[i] = squares[i - 1] * squares[i - 1];
    }
    ll sum = 1;
    for (ll i = 0; i < squares.size(); i++) sum *= (b[i] ? squares[i] : 1);
    return sum;
}

int main(){
    ll q; ll k;
    cin >> q;
    vector<ll> queries(q);
    for (ll i = 0; i < q; i++) cin >> queries[i];
    ll low; ll mod; ll s; ll dig; ll x;
    /* 0 1234567891011121314151617181920...
         ^        ^
         |        |
         1        10
    9*1, 90*2, 900*3
    */
    for (ll q : queries){
        if (q < 10){
            cout << q << '\n';
            continue;
        }
        low = 1;
        dig = 1;
        mod = q - 1;
        x = 9*dig*fpow(10, dig - 1);
        while (low + x <= q){
            low += x;
            mod -= x;
            dig++;
            x = 9*dig*fpow(10, dig - 1);
        }
        s = fpow(10, dig - 1) + ((q - low) / dig);
        cout << dec(s)[mod % dig] << '\n';
    }
    return 0;
}