#include "board.h"
#include "error.h"

namespace UserInput
{
    char getUserInput()
    {
        char c{};
        std::cin >> c;
        return c;
    }
    bool handleInput(const char input)
    {
        if (ErrorInput::hasUnextractedInput() || ErrorInput::hasUnextractedInput())
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
            std::cout << "Valid command : " << input;
            return true;
        default:
            return false;
        }
    }
 }


int main()
{
	Board board{};
    std::cout << board;

    return 0;
}