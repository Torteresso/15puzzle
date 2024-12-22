#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "array"
#include "direction.h"
#include "point.h"


namespace Config
{
	constexpr int g_consoleLines{ 32 };
	constexpr int gridSize{ 4 };
	constexpr int howMuchRandom{ 5000 };
}

class Board
{
	using Grid = std::array<std::array<Tile, Config::gridSize>, Config::gridSize>;

public:
	Board()
	{
		int num{1};
		for (std::size_t row{}; row < Config::gridSize; row++)
		{
			for (std::size_t col{}; col < Config::gridSize; col++)
			{
				m_grid[row][col] = Tile{num};
				++num;
				if (num >= Config::gridSize * Config::gridSize) num = 0;
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& out, const Board& board);

	bool moveTile(const Direction& dir);
	bool isSolved() const;
	void randomize();

private:
	Grid m_grid{ {} };


	Tile& getTileFromPoint(const Point& p);
	const Point emptyTileAsPoint() const;
	bool pointInGrid(const Point& p) const;
};

#endif