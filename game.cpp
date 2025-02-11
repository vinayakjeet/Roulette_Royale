#include "game.h"

Game::Game() : rng(std::random_device{}()) {
    wheel_numbers = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 
                     16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};

    color_map = {{0, "Green"}, {32, "Red"}, {15, "Black"}, {19, "Red"}, {4, "Black"}, {21, "Red"}, 
                 {2, "Black"}, {25, "Red"}, {17, "Black"}, {34, "Red"}, {6, "Black"}, {27, "Red"}, 
                 {13, "Black"}, {36, "Red"}, {11, "Black"}, {30, "Red"}, {8, "Black"}, {23, "Red"}, 
                 {10, "Black"}, {5, "Red"}, {24, "Black"}, {16, "Red"}, {33, "Black"}, {1, "Red"}, 
                 {20, "Black"}, {14, "Red"}, {31, "Black"}, {9, "Red"}, {22, "Black"}, {18, "Red"}, 
                 {29, "Black"}, {7, "Red"}, {28, "Black"}, {12, "Red"}, {35, "Black"}, {3, "Red"}, 
                 {26, "Black"}};

    player = std::make_unique<Player>();
}

void Game::initialize() {
    std::cout << "Initializing game...\n";
    std::cout << "Enter your starting balance: ";
    int balance;
    std::cin >> balance;
    player->setBalance(balance);
}

void Game::start() {
    while (true) {
        std::cout << "\nCurrent Balance: $" << player->getBalance() << "\n";
        std::cout << "Enter bet type (1: Number, 2: Color, 3: Exit): ";
        int betType, betAmount;
        std::cin >> betType;

        if (betType == 3) break;

        std::cout << "Enter bet amount: ";
        std::cin >> betAmount;

        if (betAmount > player->getBalance()) {
            std::cout << "Insufficient balance! Try again.\n";
            continue;
        }

        processBet(betType, betAmount);
    }
}

void Game::spinWheel() {
    std::uniform_int_distribution<int> dist(0, wheel_numbers.size() - 1);
    int spinResult = wheel_numbers[dist(rng)];
    std::cout << "Roulette spins... The number is " << spinResult << " (" << color_map[spinResult] << ")\n";
}

void Game::processBet(int betType, int betAmount) {
    spinWheel();
    // Betting logic to be implemented in the next step
}
