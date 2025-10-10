#include <fstream>
#include <iostream>
#include <windows.h>

using str = std::string;

void copyToClipboard(const str& s) {
    OpenClipboard(nullptr);
    EmptyClipboard();
    HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, s.size() + 1);
    if (!hg) {
        CloseClipboard();
        return;
    }
    memcpy(GlobalLock(hg), s.c_str(), s.size() + 1);
    GlobalUnlock(hg);
    SetClipboardData(CF_TEXT, hg);
    CloseClipboard();
    GlobalFree(hg);
}

#define print(data) (std::cout << data)

int main(int argc, char *argv[]){
    str helpstr = R"(Usage: newcpp filename

  Create a new c++ file from hardcoded template.

positional arguments:
  filename                  Name of the new c++ file.

Options:
  -h, --help                Show this message and exit.
)";
if (argc == 1){
    print(helpstr);
    return 0;
}
if (static_cast<str>(argv[1]) == static_cast<str>("-h") || static_cast<str>(argv[1]) == static_cast<str>("--help")){
    print(helpstr);
    return 0;
}
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
using std::max;

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
    copyToClipboard("rm .\\" + static_cast<str>(argv[1]) + ".exe; c++ -o " + static_cast<str>(argv[1]) + " .\\" + static_cast<str>(argv[1]) + ".cpp; .\\" + static_cast<str>(argv[1]) + ".exe");
    return 0;
}