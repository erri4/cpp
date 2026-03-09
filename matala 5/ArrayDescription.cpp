#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int dp[2][105];

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int &v : x) cin >> v;

    if (x[0] == 0) {
        for (int v = 1; v <= m; v++) dp[0][v] = 1;
    } else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        int cur = i % 2;
        int prev = 1 - cur;

        for (int v = 1; v <= m; v++) dp[cur][v] = 0;

        for (int v = 1; v <= m; v++) {
            if (x[i] != 0 && x[i] != v) continue;

            int val = dp[prev][v];
            if (v > 1) val = (val + dp[prev][v-1]) % MOD;
            if (v < m) val = (val + dp[prev][v+1]) % MOD;

            dp[cur][v] = val;
        }
    }

    int last = (n-1) % 2;

    int ans = 0;
    for (int v = 1; v <= m; v++) {
        ans = (ans + dp[last][v]) % MOD;
    }

    cout << ans;
}