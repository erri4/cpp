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

ll Apartments(vector<ll> n, vector<ll> m, ll k){
    sort(n.begin(), n.end());
    sort(m.begin(), m.end());

    ll i = 0, j = 0, r = 0;

    while (i < n.size() && j < m.size()) {
        if (m[j] < n[i] - k) {
            j++;
        } else if (m[j] > n[i] + k) {
            i++;
        } else {
            r++;
            i++;
            j++;
        }
    }
    return r;
}

int main(){
    ll k, m, n;
    input(n);
    input(m);
    input(k);
    vector<ll> ppl(n);
    vector<ll> apartments(m);
    for (ll i = 0; i < n; i++){
        input(ppl[i]);
    }
    for (ll i = 0; i < m; i++){
        input(apartments[i]);
    }
    print(Apartments(ppl, apartments, k));
    return 0;
}
