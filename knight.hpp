#ifndef __KNIGHT_HPP__
#define __KNIGHT_HPP__

#include "piece.hpp"

class Knight : public Piece
{
	public:
		Knight();
		Knight(bool, int, int);
		~Knight();

	private:
		bool validateMove(int row, int col, const td_matrix& board) const override;
};

#endif // __KNIGHT_HPP__
