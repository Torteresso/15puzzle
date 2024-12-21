#include "tile.h"

bool Tile::isEmpty() const
{
	return m_num == 0;
}


std::ostream& operator<<(std::ostream& out, const Tile& t)
{
	out << ' ';
	if (t.m_num < 10) out << ' ';

	out << t.m_num << ' ';

	return out;
}
