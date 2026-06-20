#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mindef(ll a, ll b){
    if (a == -1) return b;
    if (b == -1) return a;
    return min(a, b);
}

int main(){
    ll n;
    cin >> n;
    vector<vector<ll>> grid(n, vector<ll>(n, -1));
    grid[0][0] = 0;
    ll affected = 1;
    queue<pair<ll, ll>> q;
    q.push({0, 0});
    while (!q.empty()){
        auto curr = q.front();
        if (min(curr.first + 2, curr.second + 1) >= 0 && n > max(curr.first + 2, curr.second + 1)){
            if (grid[curr.first + 2][curr.second + 1] != mindef(grid[curr.first + 2][curr.second + 1], grid[curr.first][curr.second] + 1)) q.push({curr.first + 2, curr.second + 1});
            grid[curr.first + 2][curr.second + 1] = mindef(grid[curr.first + 2][curr.second + 1], grid[curr.first][curr.second] + 1);
        }
        if (min(curr.first - 2, curr.second - 1) >= 0 && n > max(curr.first - 2, curr.second - 1)){
            if (grid[curr.first - 2][curr.second - 1] != mindef(grid[curr.first - 2][curr.second - 1], grid[curr.first][curr.second] + 1)) q.push({curr.first - 2, curr.second - 1});
            grid[curr.first - 2][curr.second - 1] = mindef(grid[curr.first - 2][curr.second - 1], grid[curr.first][curr.second] + 1);
        }
        if (min(curr.first - 2, curr.second + 1) >= 0 && n > max(curr.first - 2, curr.second + 1)){
            if (grid[curr.first - 2][curr.second + 1] != mindef(grid[curr.first - 2][curr.second + 1], grid[curr.first][curr.second] + 1)) q.push({curr.first - 2, curr.second + 1});
            grid[curr.first - 2][curr.second + 1] = mindef(grid[curr.first - 2][curr.second + 1], grid[curr.first][curr.second] + 1);
        }
        if (min(curr.first + 2, curr.second - 1) >= 0 && n > max(curr.first + 2, curr.second - 1)){
            if (grid[curr.first + 2][curr.second - 1] != mindef(grid[curr.first + 2][curr.second - 1], grid[curr.first][curr.second] + 1)) q.push({curr.first + 2, curr.second - 1});
            grid[curr.first + 2][curr.second - 1] = mindef(grid[curr.first + 2][curr.second - 1], grid[curr.first][curr.second] + 1);
        }
        if (min(curr.first + 1, curr.second + 2) >= 0 && n > max(curr.first + 1, curr.second + 2)){
            if (grid[curr.first + 1][curr.second + 2] != mindef(grid[curr.first + 1][curr.second + 2], grid[curr.first][curr.second] + 1)) q.push({curr.first + 1, curr.second + 2});
            grid[curr.first + 1][curr.second + 2] = mindef(grid[curr.first + 1][curr.second + 2], grid[curr.first][curr.second] + 1);
        }
        if (min(curr.first - 1, curr.second - 2) >= 0 && n > max(curr.first - 1, curr.second - 2)){
            if (grid[curr.first - 1][curr.second - 2] != mindef(grid[curr.first - 1][curr.second - 2], grid[curr.first][curr.second] + 1)) q.push({curr.first - 1, curr.second - 2});
            grid[curr.first - 1][curr.second - 2] = mindef(grid[curr.first - 1][curr.second - 2], grid[curr.first][curr.second] + 1);
        }
        if (min(curr.first - 1, curr.second + 2) >= 0 && n > max(curr.first - 1, curr.second + 2)){
            if (grid[curr.first - 1][curr.second + 2] != mindef(grid[curr.first - 1][curr.second + 2], grid[curr.first][curr.second] + 1)) q.push({curr.first - 1, curr.second + 2});
            grid[curr.first - 1][curr.second + 2] = mindef(grid[curr.first - 1][curr.second + 2], grid[curr.first][curr.second] + 1);
        }
        if (min(curr.first + 1, curr.second - 2) >= 0 && n > max(curr.first + 1, curr.second - 2)){
            if (grid[curr.first + 1][curr.second - 2] != mindef(grid[curr.first + 1][curr.second - 2], grid[curr.first][curr.second] + 1)) q.push({curr.first + 1, curr.second - 2});
            grid[curr.first + 1][curr.second - 2] = mindef(grid[curr.first + 1][curr.second - 2], grid[curr.first][curr.second] + 1);
        }
        q.pop();
    }
    for (auto row : grid){
        for (ll box : row) cout << box << ' ';
        cout << '\n';
    }
    return 0;
}