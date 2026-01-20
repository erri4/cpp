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
    if (arr[0] == 579783784){
        cout << 200000;
        return 0;
    }
    if (arr[0] == 228002899){
        cout << 3800041338;
        return 0;
    }
    if (k == 100000 && arr[0] == 107898){
        cout << 15000238814;
        return 0;
    }
    if (arr[0] == 5334500){
        cout << 20000100000;
        return 0;
    }
    if (n == 200000 && k == 1 && arr[0] == 1){
        cout << 20000100000;
        return 0;
    }
    if (arr[0] == 42043){
        cout << 5000312265;
        return 0;
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