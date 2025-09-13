#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>

#define print(data) (std::cout << data << '\n')
#define println(data) (std::cout << data)
#define input(var) (std::cin >> var)

using ll = long long;
using str = std::string;
using std::vector;
using std::pair;
using std::floor;

void spin(std::chrono::duration<double> framerate = std::chrono::milliseconds(200)){
    char cycle[4] = {'/', '-', '\\', '|'};
    int i = 0;
    while (true){
        println(cycle[i]);
        std::this_thread::sleep_for(framerate);
        println("\b \b");
        i++;
        i %= 4;
    }
}

str barline(int percent, int dashes = 25, bool percentview = true){
    int bars = floor(percent / (100 / dashes));
    int spaces = dashes - bars;
    str line = "\r[";
    const int percentageview = floor(dashes / 2) - 1;
    for (int i = 0; i < bars; i++){
        if (percentview){
            if (i == percentageview){
                line += std::to_string(percent)[0];
                continue;
            }
            if (i == percentageview + 1){
                if (std::to_string(percent).size() > 1){
                    line += std::to_string(percent)[1];
                    continue;
                }
                line += "%";
                continue;
            }
            if (i == percentageview + 2){
                if (std::to_string(percent).size() > 2){
                    line += std::to_string(percent)[2];
                    continue;
                }
                if (std::to_string(percent).size() > 1){
                    line += "%";
                    continue;
                }
            }
            if (i == percentageview + 3){
                if (std::to_string(percent).size() > 2){
                    line += "%";
                    continue;
                }
            }
        }
        line += "-";
    }
    for (int i = 0; i < spaces; i++){
        if (percentview){
            if (i + bars == percentageview){
                line += std::to_string(percent)[0];
                continue;
            }
            if (i + bars == percentageview + 1){
                if (std::to_string(percent).size() > 1){
                    line += std::to_string(percent)[1];
                    continue;
                }
                line += "%";
                continue;
            }
            if (i + bars == percentageview + 2){
                if (std::to_string(percent).size() > 2){
                    line += std::to_string(percent)[2];
                    continue;
                }
                if (std::to_string(percent).size() > 1){
                    line += "%";
                    continue;
                }
            }
            if (i + bars == percentageview + 3){
                if (std::to_string(percent).size() > 2){
                    line += "%";
                    continue;
                }
            }
        }
        line += " ";
    }
    line += "]";
    return line;
}

void loadbarview(std::chrono::duration<double> framerate = std::chrono::milliseconds(200), int dashes = 25){
    for (int percent = 0; percent <= 100; percent++){
        auto line = barline(percent, dashes);
        println(line);
        std::this_thread::sleep_for(framerate);
    }
}

void loadbarnview(std::chrono::duration<double> framerate = std::chrono::milliseconds(200), int dashes = 25){
    int bars = 0;
    for (int percent = 0; percent <= 100; percent++){
        if (bars != floor(percent / (100 / dashes))){
            bars = floor(percent / (100 / dashes));
            auto line = barline(percent, dashes, false);
            println(line);
        }
        std::this_thread::sleep_for(framerate);
    }
}

int main(){
    loadbarview();
    return 0;
}