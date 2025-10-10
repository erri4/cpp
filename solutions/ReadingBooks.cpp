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

ll ReadingBooks(vector<ll> books){
    ll sum = 0;
    ll max = books[0];
    for (ll book : books){
        sum += book;
        max = std::max(max, book);
    }
    return std::max(sum, 2 * max);
}

int main(){
    ll n;
    input(n);
    vector<ll> books;
    for (ll i = 0; i < n; i++){
        ll book;
        input(book);
        books.push_back(book);
    }
    print(ReadingBooks(books));
    return 0;
}