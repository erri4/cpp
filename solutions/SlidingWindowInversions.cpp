#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; ll k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    vector<ll> dp(n, 0);
    for (ll i = 1; i < n; i++){
        if (arr[i] < arr[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = dp[i - 1];
    }
    ll w;
    for (ll i = 0; i < n - k + 1; i++){
        w = dp[i + k - 1] - dp[i];
        if (k == 1) w = 0;
        cout << w << ' ';
    }
    return 0;
}