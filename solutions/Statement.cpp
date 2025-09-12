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
using std::pow;


typedef array<ll, 10> polynom;

ll f(ll x, polynom pol){
    ll r = 0;
    for (int i = 0; i < 10; i++){
        r += pol[i]*pow(x, i);
    }
    return r;
}

void printf(polynom f){
    str func = std::to_string(f[0]);
    if (f[1] != 0){
        func += "+";
    }
    for (int i = 1; i < 10; i++){
        if (f[i] != 0){
            func += std::to_string(f[i]) + "*x^" + std::to_string(i);
        }
        if (i + 1 < 10 && f[i + 1] != 0){
            func += "+";
        }
    }
    print(func);
}

polynom derivative(polynom pol){
    polynom r;
    for (int i = 0; i < 9; i++){
        r[i] = (i + 1)*pol[i + 1];
    }
    r[9] = 0;
    return r;
}

ll solve_linear(ll m, ll b){
    return -b/m;
}

ll Statement(ll n, polynom pol){
    pol[0] -= n;
    ll x = 0;
    while (f(x, pol) != 0){
        polynom d = derivative(pol);
        ll m = f(x, d);
        ll b = f(x, pol) - m * x;
        x = solve_linear(m, b);
    }
    return x;
}

int main(){
    ll n;
    input(n);
    polynom poly;
    for (int i = 0; i < 10; i++){
        input(poly[i]);
    }
    print(Statement(n, poly));
    return 0;
}