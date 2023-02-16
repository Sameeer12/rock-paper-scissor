#include <iostream>
#include <unordered_map>
#include "CpuPlayer.hpp"
#include "HumanPlayer.hpp"
#include "Log.hpp"

class Game
{
public:
    Game()
    {
        one = new HumanPlayer();
        Logger::log_debug("Human entered the game.");

        two = new CpuPlayer();
        Logger::log_debug("Machine entered the game.");
    }

    ~Game()
    {
        delete one;
        delete two;
    }

    // to initiate the rock paper scissor game
    void startGame()
    {
        two->getInput(); // get computer input
        one->getInput(); // get user input

        Logger::log_debug("Got CPU input: " + two->getChoiceName());
        Logger::log_debug("Got User input: " + one->getChoiceName());

        int result = getWinner(*one, *two);
        printResults(result);
    }

private:
    // helper method to compare player choices
    int compareInputs(const Player one, const Player two)
    {
        if (one == two)
        {
            Logger::log_debug("It's a tie!");
            return 0;
        }

        if (two < one)
        {
            Logger::log_debug("Human won!");
            return 1;
        }

        Logger::log_debug("Machine won!");
        return -1;
    }

    // to find the winner of the game according to the moves of computer and user
    // declaring the user on the basis of getWinner return value.
    // if result=-1 then computer is the winner.
    // if result=1 then user is the winner.
    // if result=0 then it's a ties.
    int getWinner(const Player one, const Player two)
    {
        return compareInputs(one, two);
    }

    // helper method to pretty print the results
    void printResults(int result)
    {
        switch (result)
        {
        case -1:
            std::cout << '\n'
                      << "As " << two->getChoiceName() << " beats " << one->getChoiceName() << "\n\n"
                      << R"( _____ ______  _   _    _    _                _ )"
                         "\n"
                         R"(/  __ \| ___ \| | | |  | |  | |              | |)"
                         "\n"
                         R"(| /  \/| |_/ /| | | |  | |  | |  ___   _ __  | |)"
                         "\n"
                         R"(| |    |  __/ | | | |  | |/\| | / _ \ | '_ \ | |)"
                         "\n"
                         R"(| \__/\| |    | |_| |  \  /\  /| (_) || | | ||_|)"
                         "\n"
                         R"( \____/\_|     \___/    \/  \/  \___/ |_| |_|(_))"
                         "\n"
                         "\n";

            break;
        case 1:
            std::cout << '\n'
                      << "As " << one->getChoiceName() << " beats " << two->getChoiceName() << "\n\n"
                      << R"(__   __                 _    _                _ )"
                         "\n"
                         R"(\ \ / /                | |  | |              | |)"
                         "\n"
                         R"( \ V /   ___   _   _   | |  | |  ___   _ __  | |)"
                         "\n"
                         R"(  \ /   / _ \ | | | |  | |/\| | / _ \ | '_ \ | |)"
                         "\n"
                         R"(  | |  | (_) || |_| |  \  /\  /| (_) || | | ||_|)"
                         "\n"
                         R"(  \_/   \___/  \__,_|   \/  \/  \___/ |_| |_|(_))"
                         "\n"
                         "\n";

            break;
        case 0:
            std::cout << '\n'
                      << "You both chose " << one->getChoiceName() << "\n\n"
                      << R"( _____  _    _                  _____  _        _ )"
                         "\n"
                         R"(|_   _|| |  ( )                |_   _|(_)      | |)"
                         "\n"
                         R"(  | |  | |_ |/  ___     __ _     | |   _   ___ | |)"
                         "\n"
                         R"(  | |  | __|   / __|   / _` |    | |  | | / _ \| |)"
                         "\n"
                         R"( _| |_ | |_    \__ \  | (_| |    | |  | ||  __/|_|)"
                         "\n"
                         R"( \___/  \__|   |___/   \__,_|    \_/  |_| \___|(_))"
                         "\n"
                         "\n";

            break;
        }
    }

    Player *one;
    Player *two;
};
