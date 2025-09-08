#include <iostream>
#include <vector>
#include <map>
#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> *var)

using str = std::string;

int romtoint(str rom){
    std::map<str, int> singles = {
        {"I", 1},
        {"V", 5},
        {"X", 10},
        {"L", 50},
        {"C", 100},
        {"D", 500},
        {"M", 1000},
    };
    std::map<str, int> doubles = {
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
        {"X_", 10000},
    };
    int r = 0;
    for (int i = 0; i + 1 < rom.size(); i++){
        try {
            r += doubles.at(str(1, rom.at(i)) + str(1, rom.at(i + 1)));
            rom.erase(rom.begin() + i, rom.begin() + i + 2);
            i--;
        }
        catch (std::out_of_range){}
    }
    for (int i = 0; i < rom.size(); i++){
        r += singles.at(str(1, rom.at(i)));
    }
    return r;
}

str inttorom(int n){
    std::map<str, int> charval = {
        {"I", 1},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"X", 10},
        {"XL", 40},
        {"L", 50},
        {"XC", 90},
        {"C", 100},
        {"CD", 400},
        {"D", 500},
        {"CM", 900},
        {"M", 1000},
        {"X_", 10000},
    };
    str order[] = {"X_", "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    str r = "";
    for (str character : order){
        while (n >= charval.at(character)){
            r += character;
            n -= charval.at(character);
        }
    }
    return r;
}

int main(){
    bool question;
    print("romtoint?");
    input(&question);
    if (question){
        str a;
        input(&a);
        print(romtoint(a));
        return 0;
    }
    int a;
    input(&a);
    print(inttorom(a));
    return 0;
}