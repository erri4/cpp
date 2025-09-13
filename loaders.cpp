#include "loaders.h"

#define println(data) (std::cout << data)

using str = std::string;
using std::floor;

void loaders::spin(std::chrono::duration<double> framerate){
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

str loaders::barline(int percent, int dashes, bool percentview){
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

void loaders::loadbarview(std::chrono::duration<double> framerate, int dashes){
    for (int percent = 0; percent <= 100; percent++){
        auto line = barline(percent, dashes);
        println(line);
        std::this_thread::sleep_for(framerate);
    }
}

void loaders::loadbarnview(std::chrono::duration<double> framerate, int dashes){
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
