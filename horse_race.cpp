// Steven Houser
// Lab 4 - Procedural Horse Race
// 01/30/26

#include <iostream>
#include <cstdlib>
#include <ctime>

const int NUM_HORSES = 5;
const int TRACK_LENGTH = 15;

// Function prototypes
void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);

int main() {
    // Set up randomization
    srand(time(NULL));

    // Initialize horses array - all start at position 0
    int horses[NUM_HORSES] = {0, 0, 0, 0, 0};

    // Main game loop
    bool keepGoing = true;

    while (keepGoing) {
        // Process each horse for this turn (advance all, then display all)
        for (int i = 0; i < NUM_HORSES; i++) {
            advance(i, horses);
            printLane(i, horses);
        }

        // Check for winner after the turn (matches lab pseudocode)
        bool foundWinner = false;
        for (int i = 0; i < NUM_HORSES; i++) {
            if (isWinner(i, horses)) foundWinner = true;
        }
        if (foundWinner) keepGoing = false;

        // If no winner, prompt for next turn
        if (keepGoing) {
            std::cout << "Press enter for another turn" << std::endl;
            std::cin.get();
        }
    }

    return 0;
}

// Move horse based on coin flip
void advance(int horseNum, int* horses) {
    int coin = rand() % 2;
    horses[horseNum] += coin;
}

// Print horse's lane showing position on track
void printLane(int horseNum, int* horses) {
    for (int i = 0; i < TRACK_LENGTH; i++) {
        if (i == horses[horseNum]) {
            std::cout << horseNum;
        } else {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

// Check if horse crossed finish line
bool isWinner(int horseNum, int* horses) {
    if (horses[horseNum] >= TRACK_LENGTH - 1) {
        std::cout << "Horse " << horseNum << " WINS!!!" << std::endl;
        return true;
    }
    return false;
}
