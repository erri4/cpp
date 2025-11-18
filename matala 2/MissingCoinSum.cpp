#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<long long> coins(n);
 
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
 
    sort(coins.begin(), coins.end());  // Sort coins in ascending order
 
    long long smallest_unreachable = 1;  // The smallest sum we can't form yet
 
    for (long long coin : coins) {
        if (coin > smallest_unreachable) {
            break;  // Found a gap, smallest_unreachable is our answer
        }
        smallest_unreachable += coin;  // Extend the range of reachable sums
    }
 
    cout << smallest_unreachable << endl;
    return 0;
}