#ifndef __QUEEN_HPP__
#define __QUEEN_HPP__

#include "piece.hpp"

class Queen : public Piece
{
	public:
		Queen();
		Queen(bool color, int row, int col);
		~Queen() override;

	public:
		bool validateMove(int row, int col, const td_matrix& board) const override;
};

#endif //__QUEEN_HPP__
