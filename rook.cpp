#include "rook.hpp"

#include <vector>
#include <string>

typedef std::vector<std::string> td_matrix;

Rook::Rook( ) : Piece(D_WHITE, 7, 0) {}

Rook::Rook(bool color, int row, int col) : Piece(color, row, col) {}

Rook::~Rook() {}

bool Rook::validateMove(int row, int col, const td_matrix& board) const
{
	if (col == _col)
	{
		if (row > _row)
		{
			for (int i = _row + 1; i < row; ++i)
			{
				if (board[i][col] != WHITE_AREA && board[i][col] != BLACK_AREA)
					return false;
			}
		}
		else
		{
			for (int i = _row - 1; i > row; --i)
			{
				if (board[i][col] != WHITE_AREA && board[i][col] != BLACK_AREA)
					return false;
			}
		}
		return true;
	}

	if (row == _row)
	{
		if (col > _col)
		{
			for (int i = _col + 1; i < col; ++i)
			{
				if (board[row][i] != WHITE_AREA && board[row][i] != BLACK_AREA)
					return false;
			}
		}
		else
		{
			for (int i = _col - 1; i > col; --i)
			{
				if (board[row][i] != WHITE_AREA && board[row][i] != BLACK_AREA)
					return false;
			}
		}
		return true;
	}

	return false;
}
