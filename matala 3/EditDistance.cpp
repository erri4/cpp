#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<int> prev(m + 1), cur(m + 1);

    for (int j = 0; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++) {
        cur[0] = i;

        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                cur[j] = prev[j - 1];
            } else {
                cur[j] = 1 + min({
                    prev[j],
                    cur[j - 1],
                    prev[j - 1]
                });
            }
        }
        swap(prev, cur);
    }

    cout << prev[m];
    return 0;
}
