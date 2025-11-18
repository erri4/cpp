#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector;
using std::pair;
using std::array;
using std::sort;
using std::max;

vector<vector<ll>> dp;
// dp[x][y] = number of ways to get to target from (x, y)

ll GridPathsI(vector<vector<bool>> map){
    dp[map.size()] = {};
}

int main(){
    ll n;
    input(n);
    vector<str> tmp;
    for (ll i = 0; i < n; i++){
        input(tmp[i]);
    }
    vector<bool> tmp2 = {};
    vector<vector<bool>> map(n, tmp2);
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < tmp[i].size(); j++){
            if (tmp[i][j] == '*'){
                map[i].push_back(true);
            }
            else {
                map[i].push_back(false);
            }
        }
    }
    print(GridPathsI(map));
    return 0;
}