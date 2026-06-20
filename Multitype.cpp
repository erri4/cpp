#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T0, typename T1>
class multitype{
    public:
        template<typename T>
        multitype(T val){
            if (is_same_v<T, T1>){
                var1 = val;
                _tp = true;
            }
            if (is_same_v<T, T0>){
                var0 = val;
                _tp = false;
            }
        }

        template<typename T>
        bool holds_alternative(){
            if (_tp) return is_same_v<T, T1>;
            return is_same_v<T, T0>;
        }

        template<typename T>
        T get(){
            if (holds_alternative<T>()){
                if (_tp) return var1;
                return var0;
            }
        }
    private:
        T0 var0;
        T1 var1;
        bool _tp = false;
};

int main(){
    multitype<string, ll> v("764");
    cout << v.holds_alternative<ll>() << '\n';
    cout << v.holds_alternative<string>() << '\n';
    if (v.holds_alternative<ll>()){
        cout << v.get<ll>() << " ll\n";
    }
    if (v.holds_alternative<string>()){
        cout << v.get<string>() << " string\n";
    }
    return 0;
}