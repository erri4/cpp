#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }

    vector<int> freq(vals.size(), 0);
    int distinct = 0;

    for (int i = 0; i < k; i++) {
        if (++freq[a[i]] == 1)
            distinct++;
    }

    cout << distinct;

    for (int i = k; i < n; i++) {
        if (--freq[a[i - k]] == 0)
            distinct--;
        if (++freq[a[i]] == 1)
            distinct++;
        cout << " " << distinct;
    }

    return 0;
}
