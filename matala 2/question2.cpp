#include <iostream>
#include <stack>
#include <map>

#define print(data) (std::cout << data << '\n')
using str = std::string;
using std::stack;
using std::map;

map<char, char> parentheses = {
    {']', '['},
    {')', '('},
    {'>', '<'},
    {'}', '{'},
};
map<char, int> openers = {{'[', 1}, {'(', 1}, {'<', 1}, {'{', 1}};

bool question2(str string){
    stack<char> stck;
    for (char c : string){
        if (openers[c]){
            stck.push(c);
        }
        if (parentheses[c]){
            if (stck.top() == parentheses[c]){
                stck.pop();
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main(){
    print(question2("((<<>[>]))"));
    return 0;
}