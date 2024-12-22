#include "board.h"
#include "point.h"

std::ostream& operator<<(std::ostream& out, const Board& board)
{
	for (int i{}; i < Config::g_consoleLines; i++)
	{
		out << "\n";
	}

	for (const auto& row : board.m_grid)
	{
		for (const auto& tile : row)
		{
			out << tile;
		}
		out << "\n";
	}

	return out;
}

bool Board::moveTile(const Direction& dir)
{
	const Point& emptyTilePoint = emptyTileAsPoint();
	const Point& adjacentPoint = emptyTilePoint.getAdjacentPoint(-dir);

	if (pointInGrid(adjacentPoint))
	{
		Tile& emptyTile = getTileFromPoint(emptyTilePoint);
		Tile& adjacentTile = getTileFromPoint(adjacentPoint);

		std::swap(emptyTile, adjacentTile);

		return true;
	}	

	return false;
}

Tile& Board::getTileFromPoint(const Point& p)
{
	return m_grid[static_cast<std::size_t>(p.y)][static_cast<std::size_t>(p.x)];
}

const Point Board::emptyTileAsPoint() const
{	for (std::size_t row{}; row < Config::gridSize; row++)
	{
		for (std::size_t col{}; col < Config::gridSize; col++)
		{
			if (m_grid[row][col].isEmpty()) return Point(static_cast<int>(col), static_cast<int>(row));
		}
	}

	//ERROR
	return Point(-1, -1);
}

bool Board::pointInGrid(const Point& p) const
{
	return (p.x >= 0 && p.x < Config::gridSize && p.y >= 0 && p.y < Config::gridSize);
}

bool Board::isSolved() const
{
	int num{1};
	for (std::size_t row{}; row < Config::gridSize; row++)
	{
		for (std::size_t col{}; col < Config::gridSize; col++)
		{
			if (num != m_grid[row][col].getNum()) return false;
			++num;
			if (num >= Config::gridSize * Config::gridSize) num = 0;
		}
	}

	return true;
}

void Board::randomize()
{
	for (int i{}; i < Config::howMuchRandom; i++)
	{
		moveTile(Direction::generateRandom());
	}
}
