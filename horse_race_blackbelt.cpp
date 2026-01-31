// Steven Houser
// Lab 4 - Procedural Horse Race (Blackbelt Version)
// 01/30/26

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

const int NUM_HORSES = 5;
const int TRACK_LENGTH = 15;

// Horse names for display
const std::string HORSE_NAMES[NUM_HORSES] = {"Thunder", "Lightning", "Storm", "Blaze", "Shadow"};

// Function prototypes
void advance(int horseNum, int* horses);
void printLane(int horseNum, int* horses);
bool isWinner(int horseNum, int* horses);

int main() {
    // Set up randomization (only need to seed once)
    srand(time(NULL));

    // Main loop for playing again
    int playAgain = 1;

    while (playAgain) {
        // Initialize horses array - all start at position 0
        int horses[NUM_HORSES] = {0, 0, 0, 0, 0};

        // Display horse names
        std::cout << "Today's Racers:" << std::endl;
        for (int i = 0; i < NUM_HORSES; i++) {
            std::cout << i << " - " << HORSE_NAMES[i] << std::endl;
        }
        std::cout << std::endl;

        // Race loop
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

        // Ask to play again
        std::cout << std::endl;
        std::cout << "Would you like to race again? (1 for yes, 0 for no): ";
        std::cin >> playAgain;
        std::cin.ignore();
        std::cout << std::endl;
    }

    std::cout << "Thanks for playing!" << std::endl;

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
        std::cout << HORSE_NAMES[horseNum] << " (Horse " << horseNum << ") WINS!!!" << std::endl;
        return true;
    }
    return false;
}
