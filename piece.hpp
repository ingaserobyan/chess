#ifndef __PIECE_HPP__
#define __PIECE_HPP__


#ifndef D_WHITE
# define D_WHITE true
#endif // D_WHITE

#ifndef D_BLACK
# define D_BLACK false
#endif // D_BLACK

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

#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> td_matrix;

class Piece
{
	public:
		Piece(bool color, int row, int col);
		virtual ~Piece();

	public:
		bool 	getColor() const;
		int		getRow() const;
		int 	getCol() const;
		void	setRow(int row);
		void	setCol(int col);

	public:
		virtual bool validateMove(int row, int col, const td_matrix& board) const = 0;

	protected:
		bool	validCoordinates(const int& row, const int& col);

	protected:
		bool	_color;
		int		_row;
		int		_col;
};


#endif // __PIECE_HPP__
