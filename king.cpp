#include "king.hpp"

#include <vector>
#include <string>

typedef std::vector<std::string> td_matrix;

King::King() : Piece(D_WHITE, 7, 4) {}

King::King(bool color, char row, int col) : Piece(color, row, col) {}

King::~King() {};

bool King::validateMove(int row, int col, const td_matrix& board) const
{
	return(std::abs(row - _row) <= 1 && std::abs(col - _col) <= 1);
}

