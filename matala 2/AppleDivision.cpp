#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
 
    long long totalWeight = 0;
    for (int w : weights) {
        totalWeight += w;
    }
 
    long long minDifference = totalWeight; // Initialize with a large value
    int subsets = 1 << n; // Total subsets = 2^n
 
    for (int mask = 0; mask < subsets; mask++) {
        long long group1Weight = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                group1Weight += weights[i];
            }
        }
        long long group2Weight = totalWeight - group1Weight;
        long long currentDifference = abs(group1Weight - group2Weight);
        minDifference = min(minDifference, currentDifference);
    }
 
    cout << minDifference << endl;
    return 0;
}