#include <iostream>

using str = std::string;
using ll = long long;

int main(){
    str letter;
    ll number;
    std::cin >> letter >> number;
    for (ll i = 0; i < number; ++i){
        std::cout << letter;
    }
    return 0;
}