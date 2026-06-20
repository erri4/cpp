#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    stack<ll> s;
    for (ll i = 0; i < n; i++){
        if (s.empty()) cout << "0 ";
        else {
            while (!s.empty() && arr[i] <= arr[s.top()]){
                s.pop();
            }
            if (s.empty()) cout << "0 ";
            else cout << s.top() + 1 << ' ';
        }
        s.push(i);
    }
    return 0;
}