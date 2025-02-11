#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <memory>
#include <thread>
#include <chrono>
#include "player.h"

class Game {
private:
    std::vector<int> wheel_numbers;
    std::map<int, std::string> color_map;
    std::mt19937 rng;
    std::unique_ptr<Player> player;

    void spinWheel();
    void processBet(int betType, int betAmount);

public:
    Game();
    void initialize();
    void start();
};

#endif
