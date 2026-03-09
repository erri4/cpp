#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> movies(n);
    for(ll i = 0; i < n; i++){
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(), movies.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });

    multiset<ll> ends;
    ll ans = 0;

    for(auto &m : movies){
        ll start = m.first;
        ll end = m.second;

        auto it = ends.upper_bound(start);
        if(it != ends.begin()){
            --it;
            ends.erase(it);
            ends.insert(end);
            ans++;
        } else if((ll)ends.size() < k){
            ends.insert(end);
            ans++;
        }
    }

    cout << ans;
    return 0;
}
