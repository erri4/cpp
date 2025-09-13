#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>

using str = std::string;
using std::floor;

namespace loaders {
    void spin(std::chrono::duration<double> framerate = std::chrono::milliseconds(200));

    str barline(int percent, int dashes = 25, bool percentview = true);

    void loadbarview(std::chrono::duration<double> framerate = std::chrono::milliseconds(200), int dashes = 25);

    void loadbarnview(std::chrono::duration<double> framerate = std::chrono::milliseconds(200), int dashes = 25);
}