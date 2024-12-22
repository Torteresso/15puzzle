#include "direction.h"
#include <iostream>

Direction Direction::operator-() const
{
	switch (m_type)
	{
	case up:    return Direction{ down };
	case down:  return Direction{ up };
	case left:  return Direction{ right };
	case right: return Direction{ left };
	default:    return Direction();
	}	
}

std::ostream& operator<<(std::ostream& out, const Direction& d)
{
	switch (d.getType())
	{
	case Direction::left:
		out << "left";
		return out;
	case Direction::down:
		out << "down";
		return out;
	case Direction::right:
		out << "right";
		return out;
	case Direction::up:
		out << "up";
		return out;
	default:
		out << "unknown";
		return out;
	}
}
