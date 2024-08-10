#include "piece.hpp"

Piece::Piece(bool color, int row, int col) : _color(color)
{
	if(!validCoordinates(row, col))
		exit (1);
	_row  = row;
	_col = col;
}

Piece::~Piece() {}

bool Piece::getColor() const {return _color;}

int	Piece::getRow() const {return _row;}

int Piece::getCol() const {return _col;}

bool	Piece::validCoordinates(const int& row, const int& col)
{
	if(row < 0 || row > 7)
	{
		std::cerr << "Not valid Coordinate" << std::endl;
		return false;
	}
	if (col < 0 && col > 7)
	{
		std::cerr << "Not valid Coordinate" << std::endl;
		return false;
	}
	return true;
}

void	Piece::setRow(int row)
{
	_row = row;
}

void	Piece::setCol(int col)
{
	_col = col;
}
