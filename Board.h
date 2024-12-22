#ifndef BOARD_H
#define BOARD_H

#include "tile.h"
#include "array"


namespace Config
{
	constexpr int g_consoleLines{ 30 };
	constexpr int gridSize{ 4 };
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

private:
	Grid m_grid{ {} };
};

#endif