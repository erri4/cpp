#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> values[i];
    }
    
    std::sort(values.begin(), values.end());
    auto last = std::unique(values.begin(), values.end());
    int distinct_count = std::distance(values.begin(), last);
    
    std::cout << distinct_count << std::endl;
    
    return 0;
}