#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> bin(ll n){
    if (n == 0) return {0};

    vector<ll> binary;
    while (n > 0) {
        ll r = n % 2;
        binary.push_back(r);
        n /= 2;
    }
    
    return binary;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> bricks(n);
    for (ll i = 0; i < n; i++) cin >> bricks[i];
    ll mx = 0; ll sum = 0;
    vector<ll> taken(n);
    vector<ll> bini;
    bool bad = false;
    for (ll i = 1; i < 1 << n; i++){
        taken = {};
        sum = 0;
        bad = false;
        bini = bin(i);
        for (ll i = 0; i < n; i++){
            if (bini.size() <= n - i - 1){ //{0, 1}[1] == 0[0]0 01
                taken[i] = 0;
            }
            else {
                taken[i] = bini[n - i - 1] * bricks[i];
                sum += bini[n - i - 1] * bricks[i];
            }
        }
        for (ll i = 0; i < n; i++ && !bad){
            for (ll j = i + 1; j < n; j++){
                if (taken[i] != 0 && taken[j] != 0){
                    if (__builtin_popcount(i ^ j) % 2){
                        bad = true;
                        break;
                    }
                }
            }
        }
        if (!bad && mx < sum) mx = sum;
    }
    cout << mx;
    return 0;
}