#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
private:
	int m_num{0};

public:
	explicit Tile(int n) : m_num {n} {}

	bool isEmpty() const;

	int getNum() const { return m_num; }
	
	friend std::ostream& operator<<(std::ostream& out, const Tile& t);
};

#endif