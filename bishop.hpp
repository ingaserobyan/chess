#ifndef __BISHOP_HPP__
#define __BISHOP_HPP__

#include "piece.hpp"

class Bishop : public Piece
{
	public:
		Bishop();
		Bishop(bool, int, int);
		~Bishop() override;

	public:
		bool validateMove(int row, int vol, const td_matrix& board) const override;
};

#endif //__BISHOP_HPP__
