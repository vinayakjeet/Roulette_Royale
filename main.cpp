#include <iostream>
#include <memory>
#include "game.h"

int main() {
    std::cout << "🚀 Welcome to Roulette Royale! 🚀\n";
    
    std::unique_ptr<Game> game = std::make_unique<Game>();
    game->initialize();
    game->start();

    return 0;
}
