#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 10*10*10*10*10*10*10*10*10+7;

int main(){
    ll n; ll m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<ll> dp(n, 1);
    if (arr[0] == 0){
        if (arr[1] == 1 || arr[1] == m){
            dp[0] = 2;
        }
        else {
            dp[0] = 3;
        }
    }
    for (ll i = 1; i < n - 1; i++){
        if (arr[i] == 0){
            if (arr[i+1] != 0 && arr[i-1] != 0){
                if (arr[i+1] - arr[i-1] == 0){
                    dp[i] = 3;
                    if (arr[i+1] == 1 || arr[i+1] == m){
                        dp[i] = 2;
                    }
                }
                if (arr[i+1] - arr[i-1] == 1){
                    dp[i] = 2;
                }
                if (arr[i+1] - arr[i-1] == -1){
                    dp[i] = 2;
                }
            }
        }
    }
    ll res = 1;
    for (ll num : dp){
        res *= num;
    }
    res %= MOD;
    cout << res;
    return 0;
}
