#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin >> t;
    vector<ll> nums(t);
    ll mx = 0;
    for (ll i = 0; i < t; i++){
        cin >> nums[i];
        if (nums[i] > mx) mx = nums[i];
    }
    vector<ll> sieve(mx + 1, 0);
    for (ll i = 2; i <= mx; i++){
        sieve[i] = i;
    }
    
    return 0;
}