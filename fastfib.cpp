#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    a = abs(a);
    b = abs(b);
    ll tmp;
    if (b > a){
        tmp = a;
        a = b;
        b = tmp;
    }
    while (b != 0){
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

class Rational{
    public:
    ll p;
    ll q;
    Rational(ll a, ll b){ // a/b
        if (b == 0){
            throw invalid_argument("division by zero");
        }
        if (b < 0){
            b = -b;
            a = -a;
        }
        ll gcdab = gcd(a, b);
        p = a / gcdab;
        q = b / gcdab;
    }

    Rational operator-(Rational other){
        return Rational(p*other.q - other.p*q, q*other.q);
    }

    Rational operator+(Rational other){
        return Rational(p*other.q + other.p*q, q*other.q);
    }

    Rational operator*(Rational other){
        return Rational(p*other.p, q*other.q);
    }

    bool operator==(Rational other){
        return p == other.p && q == other.q;
    }
};

class Qsqrt5{
    public:
    Rational a;
    Rational b;

    Qsqrt5(Rational f, Rational s) : a(f), b(s){}

    Qsqrt5 operator*(Qsqrt5 other){
        return Qsqrt5(a * other.a + Rational(5, 1) * (b * other.b), a * other.b + b * other.a);
    }

    Qsqrt5 operator-(Qsqrt5 other){
        return Qsqrt5(a - other.a, b - other.b);
    }

    bool operator==(Qsqrt5 other){
        return a == other.a and b == other.b;
    }
};

vector<ll> bin(ll n){
    if (n == 0) return {0};

    vector<ll> binary;
    while (n > 0) {
        ll remainder = n % 2;
        binary.push_back(remainder);
        n /= 2;
    }
    
    return binary;
}

Qsqrt5 fpow(Qsqrt5 a, ll b){ // a^b // O(logb)
    Qsqrt5 c = Qsqrt5(Rational(1, 1), Rational(0, 1));
    vector<ll> binb; vector<Qsqrt5> binc;
    binb = bin(b);
    for (ll j = 0; j < binb.size(); j++){
        if (j == 0) binc.push_back(a);
        else binc.push_back(binc[j - 1] * binc[j - 1]);
    }
    for (ll j = 0; j < binc.size(); j++){
        if (binb[j]){
            c = c * binc[j];
        }
    }
    return c;
}

ll fib(ll n){
    auto phi = Qsqrt5(Rational(1, 2), Rational(1, 2));
    auto psi = Qsqrt5(Rational(1, 2), Rational(-1, 2));
    return (fpow(phi, n) - fpow(psi, n)).b.p;
}

int main(){
    cout << fib(88); // maximum without ll overflow
    return 0;
}