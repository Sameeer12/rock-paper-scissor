#include <unordered_map>
#include <string>

#ifndef PLAYER_CHARACTER
#define PLAYER_CHARACTER

// Abstract class to define player character
class Player
{
public:
    enum MoveOptions
    {
        Rock = 0,
        Paper = 1,
        Scissors = 2
    };

    // function which returns the type of move according the int n
    MoveOptions findMove(const int n)
    {
        return MoveOptions(n);
    }

    MoveOptions getMoveChoice() const
    {
        return moveChoice;
    }

    void setMoveChoice(const MoveOptions &input)
    {
        moveChoice = input;
    }

    std::string getChoiceName()
    {
        return moveOptionMap[moveChoice];
    }

    bool operator<(const Player &rhs) const
    {
        MoveOptions leftChoice = this->getMoveChoice();
        MoveOptions rightChoice = rhs.getMoveChoice();

        if (rightChoice == Rock && leftChoice == Scissors || leftChoice < rightChoice)
        {
            return true;
        }

        return false;
    }

    bool operator==(const Player &rhs) const
    {
        if (this->getMoveChoice() == rhs.getMoveChoice())
        {
            return true;
        }

        return false;
    }
    virtual void getInput(){};

private:
    MoveOptions moveChoice;

    // to map the enum values and print in string form
    std::unordered_map<int, std::string> moveOptionMap{
        {0, "Rock"}, {1, "Paper"}, {2, "Scissors"}};
};

#endif