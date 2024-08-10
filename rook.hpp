#ifndef __ROOK_HPP__
#define __ROOK_HPP__

#include "piece.hpp"

class Rook : public Piece
{
	public:
		Rook();
		Rook(bool, int, int);
		~Rook() override;

	public:
		bool validateMove(int row, int col, const td_matrix& board) const override;
};

#endif // __ROOK_HPP__
