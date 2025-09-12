#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>

#define print(data) (std::cout << data << '\n')
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector;
using std::pair;
using std::array;
using std::sort;

int main(int argc, char *argv[]){
    str filept1 = R"delimiter(#include <iostream>
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

void )delimiter";
    str filept2 = R"delimiter((){}

int main(){

    return 0;
})delimiter";
    std::ofstream outfile (static_cast<str>(argv[1]) + ".cpp");

    outfile << filept1 << argv[1] << filept2;

    outfile.close();
    std::ofstream exe (static_cast<str>(argv[1]) + ".exe");
    exe.close();
    return 0;
}