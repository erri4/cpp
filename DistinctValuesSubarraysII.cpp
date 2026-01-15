#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll s = k*(2*n - k + 1)/2;
    for (ll f = 0; f < n - k; f++){
        for (ll i = 0; i < n - k - f; i++){
            set<ll> seen;
            for (ll j = i; j < i + k + f + 1; j++){
                seen.insert(arr[j]);
                if (seen.size() > k) break;
            }
            if (seen.size() <= k) s++;
        }
    }
    cout << s;
    return 0;
}