#include <bits/stdc++.h>
using namespace std;

multiset<long long> low, high;

void balance() {
    while (low.size() > high.size() + 1) {
        auto it = prev(low.end());
        high.insert(*it);
        low.erase(it);
    }
    while (low.size() < high.size()) {
        auto it = high.begin();
        low.insert(*it);
        high.erase(it);
    }
}

void add(long long x) {
    if (low.empty() || x <= *prev(low.end()))
        low.insert(x);
    else
        high.insert(x);
    balance();
}

void remove(long long x) {
    if (low.find(x) != low.end())
        low.erase(low.find(x));
    else
        high.erase(high.find(x));
    balance();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < k; i++)
        add(a[i]);

    cout << *prev(low.end());

    for (int i = k; i < n; i++) {
        remove(a[i - k]);
        add(a[i]);
        cout << " " << *prev(low.end());
    }
    cout << "\n";
}
