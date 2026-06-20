#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; ll k;
    cin >> n >> k;
    ll x; ll a; ll b; ll c;
    cin >> x >> a >> b >> c;
    vector<ll> window(k);
    ll sum = 0;
    for (ll i = 0; i < k; i++){
        window[i] = x;
        sum += x;
        x = (a * x + b) % c;
    }
    ll result = sum;
    ll idx = 0;
    for (ll i = k; i < n; i++){
        sum -= window[idx];
        window[idx] = x;
        sum += x;
        result ^= sum;
        idx = (idx + 1) % k;
        x = (a * x + b) % c;
    }
    cout << result << '\n';
    return 0;
}