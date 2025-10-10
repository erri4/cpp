#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <climits>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector;
using std::pair;
using std::array;
using std::sort;

bool compare(pair<ll, ll> a, pair<ll, ll> b){
    if (a.second != b.second){
        return a.second < b.second;
    }
    return a.first < b.first;
}

ll MovieFestival(vector<pair<ll, ll>> m){
    sort(m.begin(), m.end(), compare);
    ll count = 0;
    ll last_end = LLONG_MIN/4;
    for (pair<ll, ll> mv : m) {
        if (mv.first >= last_end) {
            count++;
            last_end = mv.second;
        }
    }
    return count;
}

int main(){
    ll n;
    input(n);
    vector<pair<ll, ll>> movies;
    for (ll i = 0; i < n; i++){
        pair<ll, ll> movie;
        input(movie.first);
        input(movie.second);
        movies.push_back(movie);
    }
    print(MovieFestival(movies));
    return 0;
}