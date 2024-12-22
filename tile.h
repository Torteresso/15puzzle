#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
public:
	Tile() = default;
	explicit Tile(int n) : m_num {n} {}

	bool isEmpty() const;

	int getNum() const { return m_num; }


private:
	int m_num{0};

};


std::ostream& operator<<(std::ostream& out, const Tile& tile);

#endif