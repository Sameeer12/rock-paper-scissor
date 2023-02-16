#include "Player.hpp"
#include <iostream>

#ifndef HUMAN_PLAYER
#define HUMAN_PLAYER

// class to represent Human player
class HumanPlayer : public Player
{
public:
    // to get the input(which is actually a random number) of computer in the game
    void getInput()
    {
        int input;
        std::cout << '\n'
                  << "Enter Your Choice:\n\n"
                     " 0 for Rock\n"
                     " 1 for Paper\n"
                     " 2 for Scissor!!\n\n"
                     "userInput: ";

        while (!(std::cin >> input) || input < 0 || input > 2)
        {
            std::cout << "\n\n"
                      << "Sorry!! Please enter a Valid Input:\n\n"
                         " 0 for Rock\n"
                         " 1 for Paper\n"
                         " 2 for Scissor!!\n\n"
                         "userInput: ";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        setMoveChoice(findMove(input));
    }
};

#endif
