#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;

int main(){
    ll n;
    cin >> n;
    vector<ll> pos(n + 1);
    for(ll i = 1; i <= n; i++){
        ll x;
        cin >> x;
        pos[x] = i;
    }
    ll rounds = 1;
    for(ll i = 2; i <= n; i++){
        if(pos[i] < pos[i - 1]){
        rounds++;
        }
    }
    cout << rounds;
    return 0;
}