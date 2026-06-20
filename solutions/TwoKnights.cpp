#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    for (ll k = 1; k <= n; k++){
        cout << ((k*k)*(k*k-1))/2-4*(k-1)*(k-2) << '\n';
    }
    return 0;
}