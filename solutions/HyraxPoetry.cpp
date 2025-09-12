#include <iostream>
#include <vector>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector;

ll HyraxPoetry(str song, str father){ //O(n)
    ll heard = 0;
    ll i = 0;
    while (i < father.size()){
        for (char c : song){
            if (c == father[i]){
                ++i;
            }
        }
        ++heard;
    }
    return heard;
}

int main(){
    str song;
    str father_heard;
    input(song);
    input(father_heard);
    print(HyraxPoetry(song, father_heard));
    return 0;
}