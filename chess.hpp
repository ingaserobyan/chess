#ifndef __CHESS_H__
#define __CHESS_H__

#include <map>
#include <memory>

#include "board.hpp"
#include "piece.hpp"

#include "king.hpp"
#include "knight.hpp"
#include "queen.hpp"
#include "bishop.hpp"
#include "rook.hpp"

/*
	The black pieces are indicated as
	L O W E R C A S E.

	The white pieces are indicated as
	U P P E R C A S E.

	The black areas are 1.

	The white areas are 0.
*/

#ifndef WHITE_KING
# define WHITE_KING 'K'
#endif // WHITE_KING

#ifndef WHITE_QUEEN
# define WHITE_QUEEN 'Q'
#endif // WHITE_QUEEN

#ifndef WHITE_KNIGHT
# define WHITE_KNIGHT 'N'
#endif // WHITE_KNIGHT

#ifndef WHITE_ROOK
# define WHITE_ROOK 'R'
#endif // WHITE_ROOK

#ifndef WHITE_BISHOP
# define WHITE_BISHOP 'B'
#endif // WHITE_BISHOP

#ifndef BLACK_KING
# define BLACK_KING 'k'
#endif // BLACK_KING

#ifndef BLACK_AREA
# define BLACK_AREA '1'
#endif // BLACK_AREA

#ifndef WHITE_AREA
# define WHITE_AREA '0'
#endif // WHITE_AREA

typedef std::map<char, std::unique_ptr<Piece>> td_pieces;

class Chess : public Board
{
	private:
		struct PieceCunter
		{
			int	_blackKing = 0;
			int	_whiteKing = 0;
			int	_whiteQueen = 0;
			int	_whiteBishop = 0;
			int	_whiteKnight = 0;
			int	_whiteRook = 0;
		};

	public:
		Chess(const std::string& path);

	public:
		bool	validateMap() const override;
		void	show() const override;
		bool	analyse();
		bool	putBkInCheck();

	private:
		bool	checkInside() const;
		bool	isAllowedElement(char c) const;
		bool	checkAreas() const;
		void	setPieces();
		bool	attackBK();
		bool	bkEscape();
	private:
		td_pieces		_pieces;
		PieceCunter		_counter;
};


#endif // __CHESS_H__
