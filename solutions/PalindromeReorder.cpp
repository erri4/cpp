#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string text;
    cin >> text;
    vector<int> chars(text.begin(), text.end());
    vector<ll> letters(26, 0);
    for (ll i = 0; i < chars.size(); i++){
        chars[i] = chars[i] - 'A';
    }
    for (int c : chars){
        letters[c]++;
    }
    vector<char> res;
    stack<pair<int, int>> s;
    int middle = -1;
    for (ll i = 0; i < 26; i++){
        if (letters[i] % 2 == 0){
            s.push({i, (letters[i]) / 2});
            for (ll j = 0; j < letters[i] / 2; j++) res.push_back(i + 'A');
        }
        else {
            if (middle != -1){
                cout << "NO SOLUTION";
                return 0;
            }
            middle = i;
            s.push({i, (letters[i] - 1) / 2});
            for (ll j = 0; j < (letters[i] - 1) / 2; j++) res.push_back(i + 'A');
        }
    }
    if (middle != -1){
        res.push_back(middle + 'A');
    }
    while (!s.empty()){
        for (ll j = 0; j < s.top().second; j++) res.push_back(s.top().first + 'A');
        s.pop();
    }
    for (char c : res) cout << c;
    return 0;
}