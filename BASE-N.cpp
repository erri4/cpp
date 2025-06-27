#include <iostream>
#include <algorithm>


int charToValue(char c) {
    if (isdigit(c)) return c - '0';
    if (isalpha(c)) return toupper(c) - 'A' + 10;
    throw std::invalid_argument("Invalid character in input.");
}


char valueToChar(int val) {
    if (val < 10) return '0' + val;
    return 'A' + val - 10;
}

std::string fromDecimal(int decimal, int baseTo) {
    if (decimal == 0) return "0";
    std::string result;
    while (decimal > 0) {
        result += valueToChar(decimal % baseTo);
        decimal /= baseTo;
    }
    std::reverse(result.begin(), result.end());
    return result;
}


std::string basetobase(std::string number, int baseFrom, int baseTo) {
    int decimal = 0;
    for (char c : number) {
        int digit = charToValue(c);
        if (digit >= baseFrom) {
            throw std::invalid_argument("Digit out of range for base.");
        }
        decimal = decimal * baseFrom + digit;
    }
    return fromDecimal(decimal, baseTo);
}


int main(){
    int basefrom, baseto;
    std::string number;
    std::cin >> basefrom;
    std::cin >> baseto;
    std::cin >> number;
    std::cout << basetobase(number, basefrom, baseto) << '\n';

    system("pause");
    return 0;
}