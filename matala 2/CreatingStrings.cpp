#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using str = std::string;
using std::vector;

vector<str> CreatingStrings(str s) {
    std::sort(s.begin(), s.end());
    vector<str> results;
    results.push_back(s);
    while (std::next_permutation(s.begin(), s.end())){
        results.push_back(s);
    }
    return results;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    str s;
    input(s);

    auto results = CreatingStrings(s);
    print(results.size());
    for (auto &r : results)
        print(r);

    return 0;
}
