#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "piece.hpp"

#include <string>
#include <vector>

typedef std::vector<std::string> td_matrix;

class Board
{
	public:
		Board(const std::string& path);
		virtual ~Board() = default;

	public:
		virtual	bool	validateMap() const = 0;
		virtual void	show() const = 0;

	protected:
		td_matrix _board;
};

#endif // __BOARD_HPP__

