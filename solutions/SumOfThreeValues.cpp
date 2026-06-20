#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n; ll x;
    cin >> n >> x;
    vector<pair<ll, ll>> arr(n);
    for (ll i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    for (ll i = 0; i < n; i++) {
        ll l = i + 1;
        ll r = n - 1;
        while (l < r) {
            ll s = arr[i].first + arr[l].first + arr[r].first;
            if (s == x) {
                cout << arr[i].second + 1 << ' ' << arr[l].second + 1 << ' ' << arr[r].second + 1;
                return 0;
            }
            if (s < x) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}