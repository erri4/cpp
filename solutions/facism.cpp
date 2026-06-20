#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; ll d; ll k;
    cin >> n >> d >> k;
    vector<ll> houses(n);
    for (ll i = 0; i < n; i++) cin >> houses[i];
    ll sum = houses[0] * houses[0] + houses[n - 1] * houses[n - 1];
    if (d > n - 2){
        for (ll i = 1; i < n - 1; i++) sum += min(houses[i] * houses[i], k);
    }
    else {
        ll minh = -1;
        for (ll i = 1; i < n - 1; i++){
            if (d != 1){
                if (minh != -1){
                    if (minh > houses[i]) minh = houses[i];
                    sum += min(houses[i] * houses[i], k);
                }
                else {
                    minh = houses[i];
                    sum += min(houses[i] * houses[i], k);
                }
            }
            else sum += houses[i] * houses[i];
        }
        if (d != 1) sum -= 3;
        if (d != 1) sum += minh * minh;
    }
    cout << sum;
    return 0;
}