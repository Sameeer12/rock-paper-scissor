#include "Game.cpp"
#include "Log.hpp"

// driver function
int main()
{
    Logger::startLog("logfile.txt");

    char c;
    Game rps = Game();
    int sessions = 0;

    do
    {
        ++sessions;
        Logger::log_info("Starting Game of Rock, Paper, Scissors! Session " + std::to_string(sessions));
        rps.startGame();
        std::cout << '\n'
                  << "Press s to start the game again\n"
                     "           OR\n"
                     "Press any button to QUIT!\n\n"
                     "userInput: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while ((std::cin >> c) && c == 's');

    Logger::log_info("Sessions played: " + std::to_string(sessions));

    std::cout << "\nThanks for playing! BYE!\n\n";
}