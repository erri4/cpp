#include <iostream>
#include <vector>
#include <algorithm>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)
#define WithASmile // With A Smile

using ll = long long;
using std::vector;
using std::pair;
using std::sort;
using std::max;

vector<vector<ll>> dp;

void print2D(vector<vector<ll>> vect){
    for (vector<ll> row : vect){
        for (ll item : row){
            std::cout << item << " ";
        }
        print("");
    }
}

ll WorkingTogether(vector<ll> b, ll k, ll sum = 0, ll size = 0){
    if (dp[sum][size] != -1){
        return dp[sum][size];
    }
    if (size == b.size() && sum % k != 0){
        return 1;
    }
    if (size == b.size() && sum % k == 0){
        return 0;
    }
    dp[sum][size] = WorkingTogether(b, k, sum, size + 1) + WorkingTogether(b, k, sum + b[size], size + 1);
    return dp[sum][size];
}

int main(){
    //std::cin.tie(0);
    //std::ios_base::sync_with_stdio(0);
    ll n;
    input(n);
    ll k;
    input(k);
    vector<ll> boxes(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++){
        input(boxes[i]);
    }
    for (ll b : boxes){
        sum += b;
    }
    vector<ll> tmp(boxes.size() + 1, -1);
    vector<vector<ll>> dp(sum, tmp);
    for (ll i = 0; i < sum; i++){
        dp[i][boxes.size()] = !(i % k == 0);
    }
    print(WorkingTogether(boxes, k));
    return 0;
}

// im stupid so this is HeroDimdon