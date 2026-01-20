#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
 
    vector<int> dp(x + 1, 0);
    dp[0] = 1;  // Base case: 1 way to make sum 0
 
    for (int j = 1; j <= x; j++) {  // Iterate over sums first
        for (int c : coins) {  // Then iterate over coins
            if (j >= c) {
                dp[j] = (dp[j] + dp[j - c]) % MOD;
            }
        }
    }
 
    cout << dp[x] << endl;
    return 0;
}