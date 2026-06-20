#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool compare(pair<ll, ll> a, pair<ll, ll> b){ // ~ returns a contains b
    return (a.second <= a.first - b.first + b.second) && (a.second <= - a.first + b.first + b.second);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> coords(n);
    for (ll i = 0; i < n; i++) cin >> coords[i].first >> coords[i].second;
    sort(coords.begin(), coords.end(), compare);
    /*for (auto coord : coords){
        cout << '(' << coord.first << ", " << coord.second << ")\n";
    }*/
    for (ll i = 0; i < coords.size() - 1; i++){
        if (i >= coords.size()) break;
        for (ll j = i + 1; j < coords.size();){
            if (compare(coords[i], coords[j])){
                coords.erase(coords.begin() + j);
                if (j >= coords.size() || i >= coords.size()) break;
                if (coords.size() > n) return 1;
            }
            else j++;
        }
        /*while (compare(coords[i], coords[i + 1])){
            coords.erase(coords.begin() + i + 1);
            if (i + 1 >= coords.size()) break;
            if (coords.size() > n) break;
        }*/
        if (coords.size() > n) return 1;
    }
    cout << coords.size();
    /*for (auto coord : coords){
        cout << '(' << coord.first << ", " << coord.second << ")\n";
    }*/
    return 0;
}