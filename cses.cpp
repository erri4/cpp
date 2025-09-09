#include <iostream>
#include <vector>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> *var)

typedef std::string str;
typedef long long ll;
using std::vector;
 
ll factsum(ll n){
    return (n * (n + 1)) / 2;
}

std::pair<vector<ll>, vector<ll>> findsum(ll n, ll sum){
    vector<ll> r;
    vector<ll> others;
    ll counter = n;
    while (counter > 0){
        if (sum - counter >= 0 && sum != 0){
            sum -= counter;
            r.push_back(counter);
        }
        else {
            others.push_back(counter);
        }
        counter--;
    }
    return {r, others};
}

std::pair<vector<ll>, vector<ll>> TwoSets(ll n){
    ll sum = factsum(n);
    if (sum % 2 == 1) return {{}, {}};
    auto sumv = findsum(n, sum / 2);
    vector<ll> rnums = sumv.second;

    std::pair<vector<ll>, vector<ll>> r;
    r.first = sumv.first;
    r.second = rnums;
    return r;
}
 
 
int main(){
    ll n;
 
    input(&n);
    auto r = TwoSets(n);
    if (r.first.size() == 0){
        print("NO");
    }
    else {
        print("YES");
        print(r.first.size());
        for (ll i : r.first){
            std::cout << i << ' ';
        }
        print("");
        print(r.second.size());
        for (ll i : r.second){
            std::cout << i << ' ';
        }
    }
    return 0;
}
