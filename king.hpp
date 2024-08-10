#ifndef __KING_HPP__
#define __KING_HPP__

#include "piece.hpp"

class King : public Piece
{
	public:
		King();
		King(bool color, char row, int col);
		~King() override;

	public:
		bool validateMove(int row, int col, const td_matrix& board) const override;
};

#endif //__KING_HPP__
