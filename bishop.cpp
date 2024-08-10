#include "bishop.hpp"

#include <vector>
#include <string>

typedef std::vector<std::string> td_matrix;

Bishop::Bishop() : Piece(D_WHITE, 7, 2) {}

Bishop::Bishop(bool color, int row, int col) : Piece(color, row, col) {}

Bishop::~Bishop() {};

bool Bishop::validateMove(int row, int col, const td_matrix& board) const
{
	if (std::abs(row - _row) != std::abs(col - _col))
		return false;

	int rowDirection = (row > _row) ? 1 : -1;
	int colDirection = (col > _col) ? 1 : -1;

	int currentRow = _row + rowDirection;
	int currentCol = _col + colDirection;

	while (currentRow != row && currentCol != col)
	{
		if (board[currentRow][currentCol] != WHITE_AREA && board[currentRow][currentCol] != BLACK_AREA)
			return false;
		currentRow += rowDirection;
		currentCol += colDirection;
	}

	return true;
}
