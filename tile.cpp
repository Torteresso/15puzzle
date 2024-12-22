#include "tile.h"

bool Tile::isEmpty() const
{
	return m_num == 0;
}


std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	if (tile.getNum() > 9) // if two digit number
        out << " " << tile.getNum() << " ";
    else if (tile.getNum() > 0) // if one digit number
        out << "  " << tile.getNum() << " ";
    else if (tile.getNum() == 0) // if empty spot
        out << "    ";
    return out;	
}
