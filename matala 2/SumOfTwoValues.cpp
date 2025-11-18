#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    int n, x;
    std::cin >> n >> x;
    
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i].first;
        a[i].second = i + 1; // Store original index (1-based)
    }
    
    std::sort(a.begin(), a.end()); // Sort by value
    
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = a[left].first + a[right].first;
        if (sum == x) {
            std::cout << a[left].second << " " << a[right].second << std::endl;
            return 0;
        } else if (sum < x) {
            ++left;
        } else {
            --right;
        }
    }
    
    std::cout << "IMPOSSIBLE" << std::endl;
    return 0;
}