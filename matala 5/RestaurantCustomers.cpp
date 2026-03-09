#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    return a.first > b.first;
}

int main(){
    ll n;
    cin >> n;
    vector<pair<ll, ll>> times(2*n);
    ll arrive; ll leave;
    for (ll i = 0; i < n; i++){
        cin >> arrive >> leave;
        times.push_back({arrive, 1});
        times.push_back({leave, -1});
    }
    sort(times.begin(), times.end());
    ll max = 0;
    ll curr = 0;
    for (pair<ll, ll> event : times){
        curr += event.second;
        if (curr > max) max = curr;
    }
    cout << max;
    return 0;
}