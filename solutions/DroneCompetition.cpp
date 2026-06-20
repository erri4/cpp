#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool comparefirst(pair<ll, ll> a, pair<ll, ll> b){
    return a.first > b.first;
}

bool comparesecond(pair<ll, ll> a, pair<ll, ll> b){
    return a.second > b.second;
}

ll area(vector<pair<ll, ll>> points){
    ll maxx = points[0].first; ll maxy = points[0].second; ll minx = points[0].first; ll miny = points[0].second;
    for (pair<ll, ll> point : points){
        maxx = max(maxx, point.first);
        minx = min(minx, point.first);
        maxy = max(maxy, point.second);
        miny = min(miny, point.second);
    }
    return (maxx - minx) * (maxy - miny);
}

template<typename T>
pair<vector<T>, vector<T>> slicev(vector<T> arr, ll idx){
    pair<vector<T>, vector<T>> res = {{}, {}};
    for (ll i = 0; i <= idx; i++){
        res.first.push_back(arr[i]);
    }
    for (ll i = idx + 1; i < arr.size(); i++){
        res.second.push_back(arr[i]);
    }
    return res;
}

ll checkx(vector<pair<ll, ll>> points){
    sort(points.begin(), points.end(), comparefirst);
    ll orig = area(points);
    ll maxd = 0;
    ll carea;
    for (ll i = 1; i < points.size() - 1; i++){
        auto parts = slicev(points, i);
        carea = area(parts.first) + area(parts.second);
        maxd = max(maxd, orig - carea);
    }
    return maxd;
}

ll checky(vector<pair<ll, ll>> points){
    sort(points.begin(), points.end(), comparesecond);
    ll orig = area(points);
    ll maxd = 0;
    ll carea;
    for (ll i = 1; i < points.size() - 1; i++){
        auto parts = slicev(points, i);
        carea = area(parts.first) + area(parts.second);
        maxd = max(maxd, orig - carea);
    }
    return maxd;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> points(n);
    for (ll i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
    }

    cout << max(checkx(points), checky(points));

    return 0;
}