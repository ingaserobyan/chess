#include "queen.hpp"

#include <vector>
#include <string>

typedef std::vector<std::string> td_matrix;

Queen::Queen() : Piece(D_WHITE, 7, 3) {}

Queen::Queen(bool color, int row, int col) : Piece(color, row, col) {}

Queen::~Queen() {};

bool Queen::validateMove(int row, int col, const td_matrix& board) const
{
	if (row == _row)
	{
		if (col > _col)
		{
			for (int i = _col + 1; i < col; ++i)
			{
				if (board[_row][i] != WHITE_AREA && board[_row][i] != BLACK_AREA)
					return false;
			}
		}
		else
		{
			for (int i = _col - 1; i > col; --i)
			{
				if (board[_row][i] != WHITE_AREA && board[_row][i] != BLACK_AREA)
					return false;
			}
		}
		return true;
	}

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

	if (std::abs(row - _row) == std::abs(col - _col))
	{
		int rowDirection = (row > _row) ? 1 : -1;
		int colDirection = (col > _col) ? 1 : -1;

		int i = _row + rowDirection;
		int j = _col + colDirection;

		while (i != row && j != col)
		{
			if (board[i][j] != WHITE_AREA && board[i][j] != BLACK_AREA)
				return false;
			i += rowDirection;
			j += colDirection;
		}
		return true;
	}

	return false;
}

