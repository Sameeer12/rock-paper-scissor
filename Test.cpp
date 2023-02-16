#include <iostream>
#include "CpuPlayer.hpp"
#include "HumanPlayer.hpp"

// If parameter is not true, test fails
// This check function would be provided by the test framework
#define ASSERT_TRUE(x)                                                                \
    {                                                                                 \
        if (!(x))                                                                     \
            std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; \
    }

bool testCpuInputBetweenRange()
{
    CpuPlayer c;

    c.getInput();

    if (c.getMoveChoice() >= 0 && c.getMoveChoice() <= 2)
    {
        return true;
    }

    return false;
}

bool testInvalidUserInput()
{
    HumanPlayer h;

    freopen("test_input.txt", "r", stdin);
    h.getInput();

    if (h.getMoveChoice() >= 0 && h.getMoveChoice() <= 2)
    {
        return true;
    }

    return false;
}

bool testRockBeatsScissors()
{
    CpuPlayer c;
    HumanPlayer h;

    c.setMoveChoice(Player::MoveOptions::Scissors);
    h.setMoveChoice(Player::MoveOptions::Rock);

    return c < h;
}

bool testPaperBeatsRock()
{
    CpuPlayer c;
    HumanPlayer h;

    c.setMoveChoice(Player::MoveOptions::Rock);
    h.setMoveChoice(Player::MoveOptions::Paper);

    return c < h;
}

bool testScissorsBeatsPaper()
{
    CpuPlayer c;
    HumanPlayer h;

    c.setMoveChoice(Player::MoveOptions::Paper);
    h.setMoveChoice(Player::MoveOptions::Scissors);

    return c < h;
}

void testSuite()
{
    ASSERT_TRUE(testCpuInputBetweenRange());
    ASSERT_TRUE(testInvalidUserInput());
    ASSERT_TRUE(testRockBeatsScissors());
    ASSERT_TRUE(testPaperBeatsRock());
    ASSERT_TRUE(testScissorsBeatsPaper());
}

int main(void)
{
    testSuite();
}
