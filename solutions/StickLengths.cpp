#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    
    std::sort(p.begin(), p.end());
    int median = p[n / 2];
    
    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
        total_cost += std::abs(p[i] - median);
    }
    
    std::cout << total_cost << std::endl;
    return 0;
}