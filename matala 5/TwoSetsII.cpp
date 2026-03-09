#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9+7;
const ll INV2 = 500000004;

int main() {
    ll n;
    cin >> n;

    long long S = 1LL * n * (n + 1) / 2;

    if (S % 2) {
        cout << 0 << "\n";
        return 0;
    }

    ll target = S / 2;

    vector<ll> dp(target + 1, 0);
    dp[0] = 1;

    for (ll i = 1; i <= n; i++) {
        for (ll s = target; s >= i; s--) {
            dp[s] = (dp[s] + dp[s - i]) % MOD;
        }
    }

    long long ans = dp[target];
    ans = ans * INV2 % MOD;

    cout << ans << "\n";
}