#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    ll cnt = 0;
    map<ll, ll> present;
    ll left = 0;

    for (ll right = 0; right < n; right++){
        if (present.count(arr[right])){
            left = max(present[arr[right]] + 1, left);
        }
        else if (present[arr[right]] < left){}
        cnt += right - left + 1;
        present[arr[right]] = right;
    }
    cout << cnt;
    return 0;
}