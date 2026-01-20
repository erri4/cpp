#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;  // Large value to indicate an unreachable sum
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
 
    vector<int> dp(x + 1, INF);  // Initialize dp array with large values
    dp[0] = 0;  // Base case: 0 coins needed for sum 0
 
    for (int c : coins) {
        for (int j = c; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - c] + 1);
        }
    }
 
    cout << (dp[x] == INF ? -1 : dp[x]) << endl;
    return 0;
}
