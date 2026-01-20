#include <bits/stdc++.h>
using ll = long long;

using namespace std;

int main(){
    ll m;
    ll n;
    cin >> n >> m;
    vector<ll> courses(n, 0);
    vector<vector<ll>> requirements(m);
    for (ll i = 0; i < m; i++){
        ll pos;
        ll to;
        cin >> pos >> to;
        requirements[pos - 1].push_back(to - 1);
        courses[to - 1]++;
    }
    bool nonzero = true;
    for (ll degree : courses){
        if (degree == 0){
            nonzero = false;
        }
    }
    if (nonzero){
        printf("IMPOSSIBLE");
        return 0;
    }
    queue<ll> starts;
    for (ll i = 0; i < n; i++){
        if (courses[i] == 0){
            starts.push(i);
        }
    }
    vector<ll> couter;
    while(!starts.empty()){
        auto start = starts.front();
        starts.pop();
        couter.push_back(start);
        for (ll req : requirements[start]){
            courses[req]--;
            if (courses[req] == 0){
                starts.push(req);
            }
        }
        requirements[start] = {};
    }
    if (couter.size() < n){
        printf("IMPOSSIBLE");
        return 0;
    }
    for (ll res : couter){
        cout << res + 1 << " ";
    }
    return 0;
}