#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename _T1, typename _T2, typename _T3>
struct triplet{
    _T1 first;
    _T2 second;
    _T3 third;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll asaad = 0;
    ll maya = 0;
    ll m;
    ll n;
    vector<triplet<ll, ll, ll>> missions(m);
    cin >> n >> m;
    for (ll i = 0; i < m; i++){
        cin >> missions[i].first >> missions[i].second;
        cin >> missions[i].third;
    }

    if (asaad > maya){
        printf("ASAAD");
    }
    else if (asaad < maya){
        printf("MAYA");
    }
    else {
        printf("TIE");
    }

    return 0;
}