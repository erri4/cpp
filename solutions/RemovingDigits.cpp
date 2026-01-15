#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using str = string;


int main(){
    str num;
    cin >> num;
    ll number = stoi(num);
    ll i = 0;
    while (number != 0){
        int max = -1;
        for (char digit : num){
            int numeric = digit - '0';
            if (numeric > max){
                max = numeric;
            }
        }
        number = number - max;
        num = to_string(number);
        i++;
    }
    cout << i;
    return 0;
}