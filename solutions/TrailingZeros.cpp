#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    ll i2 = n;
    ll i5 = n;
    ll s2 = 0;
    ll s5 = 0;
    while (i2 > 0){
        s2 += i2 % 2;
        i2 /= 2;
    }
    while (i5 > 0){
        s5 += i5 % 5;
        i5 /= 5;
    }
    cout << min(n - s2, (n - s5) / 4);
    return 0;
}