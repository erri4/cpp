#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <unordered_set>
#include <chrono>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector;
using std::pair;
using std::array;
using std::sort;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll Playlist(vector<ll> s){
    ll r = 0;
    std::unordered_set<ll, custom_hash> seen;
    ll j = 0;
    for (ll i = 0; i < s.size(); i++){
        while (seen.count(s[i])) {
            seen.erase(s[j]);
            j++;
        }
        seen.insert(s[i]);
        r = std::max(r, i - j + 1);
    }
    return r;
}

int main(){
    ll n;
    input(n);
    vector<ll> songs;
    for (ll i = 0; i < n; i++){
        ll song;
        input(song);
        songs.push_back(song);
    }
    print(Playlist(songs));
    return 0;
}