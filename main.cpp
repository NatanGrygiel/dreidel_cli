
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <limits>

// Function to prompt for a positive integer value
int promptForPositiveInt(const std::string& prompt) {
    int value = 0;
    char* endptr;
    std::string input;
    bool validInput = false; // Flag to track if the input is valid

    while (!validInput) {
        std::cout << prompt; // Display the prompt initially and after processing invalid input
        std::getline(std::cin, input); // Use getline to read the whole line
        errno = 0; // Reset errno before the call
        value = std::strtol(input.c_str(), &endptr, 10);

        // Check for errors: no conversion performed, non-integer value passed, or non-positive value
        if (endptr == input.c_str() || *endptr != '\0' || errno != 0 || value <= 0) {
            std::cerr << "Invalid input, please enter a positive integer.\n\n"; // Display error message and two newlines
            // Do not break; loop will continue, prompting the user again
        } else {
            validInput = true; // Set the flag to true to exit the loop
        }
    }
    return value;
}


int main(int argc, char* argv[]) {
    int totalPlayers = 0;
    int totalMoney = 0;
    int wallet = 0; // Money per player
    int opt;
    char* endptr; // For error checking in strtol

    while ((opt = getopt(argc, argv, "p:m:w:h")) != -1) {
        switch (opt) {
            case 'p':
                errno = 0; // Reset errno before the call
                totalPlayers = std::strtol(optarg, &endptr, 10);
                if (endptr == optarg || *endptr != '\0' || errno != 0 || totalPlayers <= 0) {
                    std::cerr << "Invalid number of players. Must be a positive integer.\n";
                    return 1;
                }
                break;
            case 'm':
                errno = 0;
                totalMoney = std::strtol(optarg, &endptr, 10);
                if (endptr == optarg || *endptr != '\0' || errno != 0 || totalMoney <= 0) {
                    std::cerr << "Invalid total money amount. Must be a positive integer.\n";
                    return 1;
                }
                break;
            case 'w':
                errno = 0;
                wallet = std::strtol(optarg, &endptr, 10);
                if (endptr == optarg || *endptr != '\0' || errno != 0 || wallet <= 0) {
                    std::cerr << "Invalid wallet amount. Must be a positive integer.\n";
                    return 1;
                }
                break;
            case 'h':
            default:
                std::cout << "Usage: dreidel [-p <players>] [-m <money>] [-w <wallet>]\n";
                return 1;
        }
    }

    // Prompt for missing variables
    if (totalPlayers <= 0) {
        totalPlayers = promptForPositiveInt("Enter the number of players: ");
    }
    if (totalMoney <= 0) {
        totalMoney = promptForPositiveInt("Enter the total money: ");
    }
    if (wallet <= 0) {
        wallet = promptForPositiveInt("Enter the money per player (wallet): ");
    }

    // Your game initialization and logic here

    return 0;
}
