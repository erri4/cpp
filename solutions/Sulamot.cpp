#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n; ll s;
    cin >> n >> s;
    vector<pair<ll, ll>> sulamot(n);
    for (ll i = 0; i < n; i++) cin >> sulamot[i].first >> sulamot[i].second;
    //cout << sulamot[0].second - s + n - 1; // \forall i,j h_i=h_j\\ \forall i,j h_i=h_j ,k_i=k_j
    sulamot[0].first *= sulamot[0].second * sulamot[1].second;
    sulamot[1].first *= sulamot[0].second * sulamot[1].second;
    bool passed = false;
    ll mn = 1e18;
    ll sm = 0;
    bool top = false;
    for (ll i = 1; i <= sulamot[1].second; i++){
        if (i * (sulamot[1]).first / sulamot[1].second == sulamot[0].first) top == true;
    }
    while (s <= sulamot[0].second){
        for (ll i = 1; i <= sulamot[1].second; i++){
            if (i * (sulamot[1].first / sulamot[1].second) == s * (sulamot[0].first / sulamot[0].second)){
                if ((sulamot[1].second - i < sulamot[0].second - s && top) && sulamot[1].second - i + sm < mn){
                    passed = true;
                    mn = sulamot[1].second - i + sm + 1;
                    break;
                }
            }
        }
        s++;
        sm++;
    }
    if (passed) cout << mn;
    if (!passed) cout << -1;
    return 0;
}