#include "board.h"
#include <cassert>
#include "error.h"
#include "direction.h"
#include "point.h"

namespace UserInput
{
    char getUserInput()
    {
        char c{};
        std::cin >> c;
        return c;
    }
    bool isValidCommand(const char input)
    {
        if (ErrorInput::clearFailedExtraction() || ErrorInput::hasUnextractedInput())
        {
            ErrorInput::ignoreLine();
            return false;
        }

        switch (input)
        {
        case 'z':
        case 's':
        case 'q':
        case 'd':
        case 'l':
            return true;
        default:
            return false;
        }
    }

    char getCommandFromUser()
    {
        char input{};
        do 
        {
            input = getUserInput();

        } while (!isValidCommand(input));

        return input;
    }

    Direction commandToDirection(const char command)
    {
        assert(isValidCommand(command));

        return Direction(command);
    }
 }


int main()
{

	Board board{};
    board.randomize();
    std::cout << board;

    while (true)
    {
        std::cout << "Enter a command : ";
        char input{ UserInput::getCommandFromUser() };

        if (input == 'l')
        {
            std::cout << "\n\nBye !\n\n";
            break;
        }
        Direction dir{ UserInput::commandToDirection(input) };

        if (board.moveTile(dir)) std::cout << board;

        if (board.isSolved())
        {
            std::cout << "\n\nYou won !\n\n";
            break;
        }
    }

    return 0;
}