#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    queue<ll> jews;
    for (ll i = 1; i <= n; i++) jews.push(i);
    bool s = false;
    ll jew;
    while (!jews.empty()){
        jew = jews.front();
        jews.pop();
        if (s) {cout << jew << ' ';}
        else jews.push(jew);
        s = !s;
    }
    return 0;
}