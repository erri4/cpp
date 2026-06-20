#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string str;
    cin >> str;
    vector<int> chars(str.begin(), str.end());
    sort(chars.begin(), chars.end());
    set<vector<int>> s;
    do {
        s.insert(chars);
    } while (next_permutation(chars.begin(), chars.end()));
    cout << s.size() << '\n';
    for (auto x : s){
        for (char i : x) cout << i;
        cout << '\n';
    }
    return 0;
}