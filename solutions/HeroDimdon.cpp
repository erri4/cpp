#include <iostream>
#include <vector>
#include <algorithm>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using std::vector;
using std::sort;

ll HeroDimdon(vector<ll> s){
    sort(s.begin(), s.end()); // O(nlogn)
    ll i = 0;
    ll j = s.size() - 1;
    ll sum = 0;
    while (i < j){ // O(n)
        if (s[i] + s[j] > sum){
            sum = s[i] + s[j];
        }
        i++;
        j--;
    }
    if (s[i] + s[j] > sum){
        sum = s[i] + s[j];
    }
    return sum;
}

int main(){
    //std::cin.tie(0);
    //std::ios_base::sync_with_stdio(0);
    ll n;
    input(n);
    vector<ll> students;
    for (ll i = 0; i < n; i++){
        ll a;
        input(a);
        ll student;
        input(student);
        for (ll j = 0; j < a; j++){
            students.push_back(student);
        }
    }
    print(HeroDimdon(students));
    return 0;
}

// im stupid so this is WorkingTogether