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
 
 
int main(){
    ll sum = factsum(7) / 2 - 7;
    int isbig = sum < 7;
    print(isbig);
    return 0;
}
