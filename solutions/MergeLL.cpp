#include <iostream>
#include <list>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::list;

ll at(list<ll> LL, ll index){
    list<ll>::iterator it = LL.begin();
    std::advance(it, index);
    return *it;
}

list<ll> MergeLL(list<ll> LL1, list<ll> LL2){
    ll i = 0;
    ll j = 0;
    list<ll> output;
    while (i < LL1.size() && j < LL2.size()){
        if (at(LL1, i) <= at(LL2, j)){
            output.push_back(at(LL1, i));
            i++;
        }
        else {
            output.push_back(at(LL2, j));
            j++;
        }
    }
    if (i < LL1.size()){
        while (i < LL1.size()){
            output.push_back(at(LL1, i));
            i++;
        }
    }
    if (j < LL2.size()){
        while (j < LL2.size()){
            output.push_back(at(LL2, j));
            j++;
        }
    }
    return output;
}

str display(list<ll> LL){
    str r = "";
    for (ll item : LL){
        r += std::to_string(item) + " ";
    }
    return r;
}

int main(){
    ll n;
    ll m;
    input(n);
    input(m);
    list<ll> LL1;
    list<ll> LL2;
    for (ll i = 0; i < n; i++){
        ll tmp;
        input(tmp);
        LL1.push_back(tmp);
    }
    for (ll i = 0; i < m; i++){
        ll tmp;
        input(tmp);
        LL2.push_back(tmp);
    }
    print(display(MergeLL(LL1, LL2)));
    return 0;
}