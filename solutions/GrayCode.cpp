#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> GrayCode(int n){
    if (n == 1){
        return {{0}, {1}};
    }
    auto prev = GrayCode(n - 1);
    vector<vector<int>> res0 = prev;
    vector<vector<int>> res1 = prev;
    vector<vector<int>> res;
    for (int i = 0; i < prev.size(); i++){
        res0[i].push_back(0);
        res.push_back(res0[i]);
        res1[i].push_back(1);
    }
    for (int i = res1.size() - 1; i >= 0; i--){
        res.push_back(res1[i]);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    for (vector<int> code : GrayCode(n)){
        for (int c : code) cout << c;
        cout << '\n';
    }
    return 0;
}