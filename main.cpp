#include <iostream>
#include "dreidel.h"
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <cerrno>
int main(int argc, char* argv[]) {
    int totalPlayers = 0;
    int totalMoney = 0;
    int wallet = 0; // money per player
    int opt;
    char* endptr; // for error checking in strtol

    while ((opt = getopt(argc, argv, "p:m:w:h")) != -1) {
        switch (opt) {
            case 'p':
                errno = 0; // reset errno before the call
                totalPlayers = std::strtol(optarg, &endptr, 10);
                // Check for errors: no conversion performed or non-integer value passed
                if (endptr == optarg || *endptr != '\0' || errno != 0 || totalPlayers <= 0) {
                    std::cerr << "Invalid number of players. Must be a positive integer." << std::endl;
                    return 1;
                }
                break;
            case 'm':
                errno = 0;
                totalMoney = std::strtol(optarg, &endptr, 10);
                if (endptr == optarg || *endptr != '\0' || errno != 0 || totalMoney <= 0) {
                    std::cerr << "Invalid total money amount. Must be a positive integer." << std::endl;
                    return 1;
                }
                break;
            case 'w':
                errno = 0;
                wallet = std::strtol(optarg, &endptr, 10);
                if (endptr == optarg || *endptr != '\0' || errno != 0 || wallet <= 0) {
                    std::cerr << "Invalid wallet amount. Must be a positive integer." << std::endl;
                    return 1;
                }
                break;
            case 'h':
                std::cout << "Usage: dreidel [-p <players>] [-m <money>] [-w <wallet>]" << std::endl;
                return 0;
            default:
                std::cout << "Usage: dreidel [-p <players>] [-m <money>] [-w <wallet>]" << std::endl;
                return 1;
        }
    }

    // game logic will go here

    return 0;
}
