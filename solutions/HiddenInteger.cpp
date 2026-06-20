#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll u = 1e9;
    ll l = 0;
    string feedback;
    for (ll i = 0; i < 30; i++){
        cout << "? " << (u + l) /2 << '\n';
        cin >> feedback;
        if (feedback == "YES"){
            l = (u + l) / 2;
        }
        if (feedback == "NO"){
            u = (u + l) / 2;
        }
    }
    cout << "! " << (u + l) / 2 + 1 << '\n';
    return 0;
}