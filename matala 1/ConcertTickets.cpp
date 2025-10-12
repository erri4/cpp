#include <iostream>
#include <vector>
#include <set>
 
int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::multiset<int> tickets;
    for (int i = 0; i < n; ++i) {
        int price;
        std::cin >> price;
        tickets.insert(price);
    }
    
    for (int i = 0; i < m; ++i) {
        int max_price;
        std::cin >> max_price;
        
        auto it = tickets.upper_bound(max_price);
        
        if (it == tickets.begin()) {
            std::cout << -1 << "\n";
        } else {
            --it;
            std::cout << *it << "\n";
            tickets.erase(it);
        }
    }
    
    return 0;
}