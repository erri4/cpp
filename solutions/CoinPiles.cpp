#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll t;
    cin >> t;
    ll a; ll b;
    vector<string> res;
    for (ll i = 0; i < t; i++){
        cin >> a >> b;
        if ((a + b) % 3 == 0 && max(a, b) <= 2 * min(a,b)) res.push_back("YES");
        else res.push_back("NO");
    }
    for (string r : res){
        cout << r << '\n';
    }
    return 0;
}