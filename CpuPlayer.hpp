#include "Player.hpp"

#ifndef CPU_PLAYER
#define CPU_PLAYER

// class to represent CPU player
class CpuPlayer : public Player
{
public:
    // to get the input(which is actually a random number) of computer in the game
    void getInput()
    {
        srand(time(NULL));
        setMoveChoice(findMove(rand() % 3));
    }
};

#endif
