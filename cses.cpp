#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;
using std::cout;
using std::cin;

struct Project {
    long long start, end, reward;
};

bool compareByEnd(const Project& a, const Project& b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<Project> projects(n);
    for (int i = 0; i < n; ++i) {
        cin >> projects[i].start >> projects[i].end >> projects[i].reward;
    }

    sort(projects.begin(), projects.end(), compareByEnd);

    vector<long long> ends;
    for (auto& p : projects) {
        ends.push_back(p.end);
    }

    vector<long long> dp(n);

    for (int i = 0; i < n; ++i) {
        int j = lower_bound(ends.begin(), ends.end(), projects[i].start) - ends.begin() - 1;

        long long bestBefore = (j >= 0 ? dp[j] : 0);
        dp[i] = max((i > 0 ? dp[i - 1] : 0), bestBefore + projects[i].reward);
    }

    cout << dp[n - 1] << "\n";

    return 0;
}
