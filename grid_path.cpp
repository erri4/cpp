#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <array>


namespace defaultns{
	using str = std::string;

	void print(str data){
		std::cout << data << '\n';
	}

	void print(int data){
		std::cout << data << '\n';
	}

	void print(char data){
		std::cout << data << '\n';
	}

    void print(std::vector<char> data){
        std::cout << '[';
        for (int c = 0; c < data.size() -1; c++){
            std::cout << "'" << data[c] << "', ";
        }
        std::cout << "'" << data[data.size() - 1] << "']" << '\n';
    }

    void print(std::vector<int> data){
        std::cout << '[';
        for (int c = 0; c < data.size() -1; c++){
            std::cout << data[c] << ", ";
        }
        std::cout << data[data.size() - 1] << "]" << '\n';
    }

    void print(std::vector<str> data){
        std::cout << '[';
        for (int c = 0; c < data.size() -1; c++){
            std::cout << "'" << data[c] << "', ";
        }
        std::cout << "'" << data[data.size() - 1] << "']" << '\n';
    }

    void print(std::vector<std::array<int, 2>> data){
        if (data.size()){
            std::cout << '[';
            for (int i = 0; i < data.size() - 1; i++){
                std::cout << '[';
                for (int c = 0; c < data[i].size() -1; c++){
                    std::cout << data[i][c] << ", ";
                }
                std::cout << data[i][data[i].size() - 1] << "], " << '\n';
            }
            std::cout << "[" << data[data.size() - 1][0] << ", " << data[data.size() - 1][1] << "]]" << '\n';
        }
    }
}
using namespace defaultns;

int counter = 0;
std::map<char, int> xvectors = {
    {'L', -1},
    {'R', 1},
    {'U', 0},
    {'D', 0}
};
std::map<char, int> yvectors = {
    {'L', 0},
    {'R', 0},
    {'U', 1},
    {'D', -1}
};
std::array<int, 2> start = {0, 6};
std::vector<std::array<int, 2>> visited = {start};

std::vector<char> get_opt(int x, int y, char letter){
    std::vector<char> result;

    if (letter != '?'){
        result.push_back(letter);
    }
    else{
        if (x > 0){
            std::array<int, 2> newp = {x + xvectors.at('L'), y};
            bool isvisited = std::find(std::begin(visited), std::end(visited), newp) != std::end(visited);
            if (!isvisited){
                result.push_back('L');
            }
        }
        if (x < 6){
            std::array<int, 2> newp = {x + xvectors.at('R'), y};
            bool isvisited = std::find(std::begin(visited), std::end(visited), newp) != std::end(visited);
            if (!isvisited){
                result.push_back('R');
            }
        }
        if (y < 6){
            std::array<int, 2> newp = {x, y + yvectors.at('U')};
            bool isvisited = std::find(std::begin(visited), std::end(visited), newp) != std::end(visited);
            if (!isvisited){
                result.push_back('U');
            }
        }
        if (y > 0){
            std::array<int, 2> newp = {x, y + yvectors.at('D')};
            bool isvisited = std::find(std::begin(visited), std::end(visited), newp) != std::end(visited);
            if (!isvisited){
                result.push_back('D');
            }
        }
    }
    return result;
}

void count_paths(str pth, int x = 0, int y = 6, int pos = 0){
    if (pos == 48 && x == 0 && y == 0){
        counter++;
        visited.pop_back();
        return;
    }
    std::vector<char> options = get_opt(x, y, pth[pos]);
    if (options.size() == 0 || x > 6 || y > 6 || x < 0 || y < 0){
        visited.pop_back();
        return;
    }


    for (int c = 0; c < options.size(); c++){
        int newx = x + xvectors.at(options[c]);
        int newy = y + yvectors.at(options[c]);
        std::array<int, 2> newp = {newx, newy};
        visited.push_back(newp);
        count_paths(pth, newx, newy, pos + 1);
    }
}


int main(){
    str path = "??????R??????U??????????????????????????LD????D?";
    //std::cin >> path;

    count_paths(path);
    print(counter);
    return 0;
}
