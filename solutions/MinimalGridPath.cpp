#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    string row; vector<char> rowv;
    for (ll i = 0; i < n; i++){
        cin >> row;
        rowv = vector<char>(row.begin(), row.end());
        grid[i] = vector<int>(rowv.begin(), rowv.end());
    }
    vector<int> path;
    pair<ll, ll> pos = {0, 0};
    path.push_back(grid[pos.first][pos.second]);
    while (pos != pair<ll, ll>(n - 1, n - 1)){
        cout << pos.first << ' ' << pos.second << ' ' << (char)grid[pos.first][pos.second] << '\n';
        if (pos.first == n - 1) pos.second++;
        else if (pos.second == n - 1) pos.first++;
        else if (grid[pos.first][pos.second + 1] > grid[pos.first + 1][pos.second]) pos.first++;
        else pos.second++;
        path.push_back(grid[pos.first][pos.second]);
    }
    for (char c : path) cout << c;
    return 0;
}