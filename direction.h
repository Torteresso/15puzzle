#ifndef DIRECTION_H
#define DIRECTION_H

#include <array>
#include <string_view>
#include "random.h"

class Direction
{
public:
	enum Type
	{
		up,
		right,
		down,
		left,
		unknown,
	};

	static Direction generateRandom() { return Direction(static_cast<Type>(Random::get(0, 3))); }

	Direction() = default;
	Direction(Type t) : m_type{t} {}
	Direction(const char command)
	{
		switch (command)
		{
		case 'z':
			m_type = up;
			break;
		case 'd':
			m_type = right;
			break;
		case 's':
			m_type = down;
			break;
		case 'q':
			m_type = left;
			break;
		default:
			m_type = unknown;
		}
	}

	Type getType() const { return m_type; }

	Direction operator-() const;

private:
	Type m_type{unknown};
};


std::ostream& operator<<(std::ostream& out, const Direction& d);


#endif