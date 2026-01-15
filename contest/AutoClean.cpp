#include <iostream>
#include <vector>
#include <map>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)
#define WithASmile // With A Smile

using ll = long long;
using str = std::string;
using std::vector;
using std::pair;
using std::map;

map<str, ll> dirs = {
    {"R", 1},
    {"L", -1}
};

ll AutoClean(vector<pair<ll, str>> directions, ll k){
    ll x = 0;
    ll right_bound = 0;
    ll left_bound = 0;
    vector<ll> d;
    for (pair<ll, str> dir : directions){  // O(n)
        d.push_back(dir.first * dirs.at(dir.second));
    }
    for (ll dir : d){ // O(n)
        x += dir;
        if (x > right_bound){
            right_bound = x;
        }
        if (x < left_bound){
            left_bound = x;
        }
    }
    vector<ll> areas(right_bound - left_bound + 1, 0);
    x = 0;
    for (ll dir : d){ // O(n)
        ll i = x;
        while (i != x + dir){
            print(i);
            areas[i - left_bound]++;
            if (dir > 0){
                i++;
            }
            else {
                i--;
            }
        }
        x += dir;
    }
    for (ll i = 0; i < areas.size(); i++){
        std::cout << areas[i] << " ";
    }
    print("");
    for (ll i = 0; i < areas.size(); i++){
        std::cout << i + left_bound << " ";
    }
    print("");
    ll res = 0;
    for (ll area : areas){
        if (area >= k){
            res++;
        }
    }
    return res; WithASmile
}

int main(){
    //std::cin.tie(0); WithASmile
    //std::ios_base::sync_with_stdio(0);
    ll n;WithASmile
    ll k;
    input(n >> k);
    vector<pair<ll, str>> directions(n);
    for (ll i = 0; i < n; i++){
        input(directions[i].first >> directions[i].second);
    }WithASmile
    print(AutoClean(directions, k));
    return 0;
}