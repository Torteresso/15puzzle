#include "Board.h"

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
