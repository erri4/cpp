#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> comp(vector<int> a, vector<int> b){ // min(a, b)
    if (a.size() > b.size()) return b;
    if (a.size() < b.size()) return a;
    for (ll i = 0; i < a.size(); i++){
        if (a[i] > b[i]) return b;
        if (a[i] < b[i]) return a;
    }
    return a;
}

int main(){
    ll n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));
    string row; vector<char> rowv;
    for (ll i = 0; i < n; i++){
        cin >> row;
        rowv = vector<char>(row.begin(), row.end());
        grid[i] = vector<int>(rowv.begin(), rowv.end());
    }
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < n; j++){
            if (j == 0 && i == 0){}
            else if (i == 0){
                dp[i][j] = dp[i][j - 1];
            }
            else {
                if (j != 0) dp[i][j] = comp(dp[i][j - 1], dp[i - 1][j]);
                else dp[i][j] = dp[i - 1][j];
            }
            dp[i][j].push_back(grid[i][j]);
        }
    }
    for (char c : dp[n - 1][n - 1]) cout << c;
    return 0;
}