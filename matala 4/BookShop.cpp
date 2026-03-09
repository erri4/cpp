#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x;
    cin >> n >> x;
    vector<ll> h(n), s(n);
    for(ll i = 0; i < n; i++){
        cin >> h[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<ll> dp(x + 1, 0);

    for(ll i = 0; i < n; i++){
        for(ll j = x; j >= h[i]; j--){
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }

    cout << dp[x];
    return 0;
}
