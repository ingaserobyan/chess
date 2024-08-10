#include "chess.hpp"

#include <utility>

Chess::Chess(const std::string& path) : Board(path)
{
	validateMap();
	checkAreas();
	setPieces();
	if (_counter._blackKing != 1 || _counter._whiteKing != 1)
	{
		std::cerr << "Wrong number of kings" << std::endl;
		exit(1);
	}
}

bool	Chess::validateMap() const
{
	if(_board.size() != 8)
	{
		std::cerr << "Not valid map size" << std::endl;
		exit (1);
	}
	for(auto line : _board)
	{
		if (line.size() != 8)
		{
			std::cerr << "Not valid map size" << std::endl;
			exit (1);
		}
	}
	return (checkInside());
}

bool	Chess::checkInside() const
{
	for (auto line : _board)
	{
		for (auto c : line)
		{
			if (!isAllowedElement(c))
			{
				std::cerr << "Not allowed elements inside" << std::endl;
				exit (1);
			}
		}
	}
}

bool	Chess::isAllowedElement(char c) const
{
	return(c == WHITE_AREA || c == BLACK_AREA || c == WHITE_KING || c == WHITE_QUEEN ||
			c == WHITE_KNIGHT || c == WHITE_BISHOP || c == WHITE_ROOK || c == BLACK_KING);
}

void	Chess::show() const
{
	int i = 8;
	for (auto line : _board)
	{
		std::cout << i << " ";
		for (auto c : line)
		{
			if (c == WHITE_AREA)
				std::cout << "    ";
			if (c == BLACK_AREA)
				std::cout << "||||";
			if (c == WHITE_KING)
				std::cout << " wK ";
			if (c == WHITE_QUEEN)
				std::cout << " wQ ";
			if (c == WHITE_KNIGHT)
				std::cout << " wN ";
			if (c == WHITE_BISHOP)
				std::cout << " wB ";
			if (c == WHITE_ROOK)
				std::cout << " wR ";
			if (c == BLACK_KING)
				std::cout << " bk ";
		}
		std::cout << std::endl;
		--i;
	}
	std::cout << "    A   B   C   D   E   F   G    H " << std::endl;
	std::cout << std::endl;
}

bool	Chess::checkAreas() const
{
	for (int i = 0; i < _board.size(); ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			char	expected_color;

			if (i % 2 == 0)
			{
				if (j % 2 == 0)
					expected_color = WHITE_AREA;
				else
					expected_color = BLACK_AREA;
			}
			else
			{
				if (j % 2 == 0)
					expected_color = BLACK_AREA;
				else
					expected_color = WHITE_AREA;
			}

			if (_board[i][j] != expected_color && _board[i][j] != WHITE_ROOK
				&& _board[i][j] != WHITE_QUEEN && _board[i][j] != WHITE_KNIGHT
				&& _board[i][j] != WHITE_KING && _board[i][j] != WHITE_BISHOP
				&& _board[i][j] != BLACK_KING)
			{
				std::cerr << "Wrong area" << std::endl;
				exit (1);
			}
		}
	}
	return true;
}

void	Chess::setPieces()
{
	for (int i = 0; i < _board.size(); ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (_board[i][j] == BLACK_KING)
            {
                _counter._blackKing++;
				if (_counter._blackKing != 1)
				{
					std::cerr << "Too many kings" << std::endl;
					exit(1);
				}

                if ((i > 0 && _board[i - 1][j] == WHITE_KING) ||
                    (i < 7 && _board[i + 1][j] == WHITE_KING) ||
                    (j > 0 && _board[i][j - 1] == WHITE_KING) ||
                    (j < 7 && _board[i][j + 1] == WHITE_KING) ||
                    (i > 0 && j > 0 && _board[i - 1][j - 1] == WHITE_KING) ||
                    (i > 0 && j < 7 && _board[i - 1][j + 1] == WHITE_KING) ||
                    (i < 7 && j > 0 && _board[i + 1][j - 1] == WHITE_KING) ||
                    (i < 7 && j < 7 && _board[i + 1][j + 1] == WHITE_KING))
                {
                    std::cerr << "Black king is adjacent to white king" << std::endl;
                    exit(1);
                }
				_pieces.emplace(BLACK_KING, std::make_unique<King>(D_BLACK, i, j));
            }

            if (_board[i][j] == WHITE_KING)
            {
                _counter._whiteKing++;
				if (_counter._whiteKing != 1)
				{
					std::cerr << "Too many kings" << std::endl;
					exit(1);
				}

                if ((i > 0 && _board[i - 1][j] == BLACK_KING) ||
                    (i < 7 && _board[i + 1][j] == BLACK_KING) ||
                    (j > 0 && _board[i][j - 1] == BLACK_KING) ||
                    (j < 7 && _board[i][j + 1] == BLACK_KING) ||
                    (i > 0 && j > 0 && _board[i - 1][j - 1] == BLACK_KING) ||
                    (i > 0 && j < 7 && _board[i - 1][j + 1] == BLACK_KING) ||
                    (i < 7 && j > 0 && _board[i + 1][j - 1] == BLACK_KING) ||
                    (i < 7 && j < 7 && _board[i + 1][j + 1] == BLACK_KING))
                {
                    std::cerr << "White king is adjacent to black king" << std::endl;
                    exit(1);
                }
				_pieces.emplace(WHITE_KING, std::make_unique<King>(D_WHITE, i, j));
            }

			if (_board[i][j] == WHITE_QUEEN)
			{
				_counter._whiteQueen++;
				if(_counter._whiteQueen != 1)
				{
					std::cerr << "Wrong number of Queens" << std::endl;
					exit(1);
				}
				_pieces.emplace(WHITE_QUEEN, std::make_unique<Queen>(D_WHITE, i, j));
			}

			if (_board[i][j] == WHITE_ROOK)
			{
				_counter._whiteRook++;
				if(_counter._whiteRook < 1 && _counter._whiteRook > 2)
				{
					std::cerr << "Wrong number of Rooks" << std::endl;
					exit(1);
				}
				_pieces.emplace(WHITE_ROOK, std::make_unique<Rook>(D_WHITE, i, j));
			}

			if (_board[i][j] == WHITE_KNIGHT)
			{
				_counter._whiteKnight++;
				if(_counter._whiteKnight < 1 && _counter._whiteKnight > 2)
				{
					std::cerr << "Wrong number of Knights" << std::endl;
					exit(1);
				}
				_pieces.emplace(WHITE_KNIGHT, std::make_unique<Knight>(D_WHITE, i, j));
			}

			if (_board[i][j] == WHITE_BISHOP)
			{
				_counter._whiteBishop++;
				if(_counter._whiteBishop< 1 && _counter._whiteBishop > 2)
				{
					std::cerr << "Wrong number of Bishops" << std::endl;
					exit(1);
				}
				_pieces.emplace(WHITE_BISHOP, std::make_unique<Bishop>(D_WHITE, i, j));
			}
    	}
	}
}

// the logic

bool	Chess::attackBK()
{
	auto bk_it = _pieces.find(BLACK_KING);
	auto wk_it = _pieces.find(WHITE_KING);
	auto wq_it = _pieces.find(WHITE_QUEEN);
	auto wn_it = _pieces.find(WHITE_KNIGHT);
	auto wr_it = _pieces.find(WHITE_ROOK);
	auto wb_it = _pieces.find(WHITE_BISHOP);

	Piece* bk_tmp = (bk_it != _pieces.end()) ? bk_it->second.get() : nullptr;
	Piece* wk_tmp = (wk_it != _pieces.end()) ? wk_it->second.get() : nullptr;
	Piece* wq_tmp = (wq_it != _pieces.end()) ? wq_it->second.get() : nullptr;
	Piece* wn_tmp = (wn_it != _pieces.end()) ? wn_it->second.get() : nullptr;
	Piece* wr_tmp = (wr_it != _pieces.end()) ? wr_it->second.get() : nullptr;
	Piece* wb_tmp = (wb_it != _pieces.end()) ? wb_it->second.get() : nullptr;

	return (bk_tmp && ((wq_tmp && wq_tmp->validateMove(bk_tmp->getRow(), bk_tmp->getCol(), _board))
		|| (wn_tmp && wn_tmp->validateMove(bk_tmp->getRow(), bk_tmp->getCol(), _board))
		|| (wr_tmp && wr_tmp->validateMove(bk_tmp->getRow(), bk_tmp->getCol(), _board))
		|| (wb_tmp && wb_tmp->validateMove(bk_tmp->getRow(), bk_tmp->getCol(), _board))
		|| (wk_tmp && wk_tmp->validateMove(bk_tmp->getRow(), bk_tmp->getCol(), _board))));
}

bool	Chess::analyse()
{
	if (this->attackBK())
	{
		if (bkEscape())
			return false;
		else
			return true;
	}

	return false;
}

static bool	isBlackSquare(int row, int col)
{
    return ((row + col) & 1);
}

bool Chess::bkEscape()
{
	auto	bk_it = _pieces.find(BLACK_KING);
	Piece	*bk_tmp = (bk_it != _pieces.end()) ? bk_it->second.get() : nullptr;

	if (!bk_tmp)
	{
		std::cerr << "No black King on board" << std::endl;
		exit(1);
	}
	int row = bk_tmp->getRow();
	int col = bk_tmp->getCol();
	std::vector<std::pair<int, int>> possibleMoves = {
		{row - 1, col},
		{row + 1, col},
		{row, col + 1},
		{row, col - 1},
		{row - 1, col - 1},
		{row - 1, col + 1},
		{row + 1, col - 1},
		{row + 1, col + 1}
	};

	for (const auto& move : possibleMoves)
	{

		int newRow = move.first;
		int newCol = move.second;

		if (newRow < 0 || newRow >= _board.size() || newCol < 0 || newCol >= _board[0].size())
			continue;

		char original = _board[bk_tmp->getRow()][bk_tmp->getCol()];
		char newPositionContent = _board[newRow][newCol];

		if (isBlackSquare(bk_tmp->getRow(), bk_tmp->getCol()))
			_board[bk_tmp->getRow()][bk_tmp->getCol()] = BLACK_AREA;
		else
			_board[bk_tmp->getRow()][bk_tmp->getCol()] = WHITE_AREA;
		_board[newRow][newCol] = BLACK_KING;

		bk_tmp->setRow(newRow);
		bk_tmp->setCol(newCol);

		bool underCheck = false;

		if (this->attackBK())
			underCheck = true;

		if (!underCheck)
			return true;

		bk_tmp->setRow(row);
		bk_tmp->setCol(col);

		_board[bk_tmp->getRow()][bk_tmp->getCol()] = original;
		_board[newRow][newCol] = newPositionContent;
	}

	return false;
}


bool Chess::putBkInCheck()
{
	auto bk_it = _pieces.find(BLACK_KING);
	auto wk_it = _pieces.find(WHITE_KING);
	auto wq_it = _pieces.find(WHITE_QUEEN);
	auto wn_it = _pieces.find(WHITE_KNIGHT);
	auto wr_it = _pieces.find(WHITE_ROOK);
	auto wb_it = _pieces.find(WHITE_BISHOP);

	Piece* bk_tmp = (bk_it != _pieces.end()) ? bk_it->second.get() : nullptr;
	Piece* wk_tmp = (wk_it != _pieces.end()) ? wk_it->second.get() : nullptr;
	Piece* wq_tmp = (wq_it != _pieces.end()) ? wq_it->second.get() : nullptr;
	Piece* wn_tmp = (wn_it != _pieces.end()) ? wn_it->second.get() : nullptr;
	Piece* wr_tmp = (wr_it != _pieces.end()) ? wr_it->second.get() : nullptr;
	Piece* wb_tmp = (wb_it != _pieces.end()) ? wb_it->second.get() : nullptr;


	for (int i = 0; i < _board.size(); ++i)
	{
		for (int j = 0; j < _board[i].size(); ++j)
		{
			if (wq_tmp && wq_tmp->validateMove(i, j, _board) && (_board[i][j] == WHITE_AREA || _board[i][j] == BLACK_AREA) )
			{
				char original = _board[wq_tmp->getRow()][wq_tmp->getCol()];
				char newPositionContent = _board[i][j];

				int row = wq_tmp->getRow();
				int col = wq_tmp->getCol();

				if (isBlackSquare(wq_tmp->getRow(), wq_tmp->getCol()))
					_board[wq_tmp->getRow()][wq_tmp->getCol()] = BLACK_AREA;
				else
					_board[wq_tmp->getRow()][wq_tmp->getCol()] = WHITE_AREA;

				_board[i][j] = WHITE_QUEEN;

				wq_tmp->setRow(i);
				wq_tmp->setCol(j);

				if(this->attackBK())
				{
					return true;
				}
				wq_tmp->setRow(row);
				wq_tmp->setCol(col);

				_board[wq_tmp->getRow()][wq_tmp->getCol()] = original;
				_board[i][j] = newPositionContent;
			}

			if (wn_tmp && wn_tmp->validateMove(i, j, _board) && (_board[i][j] == WHITE_AREA || _board[i][j] == BLACK_AREA) )
			{
				char original = _board[wn_tmp->getRow()][wn_tmp->getCol()];
				char newPositionContent = _board[i][j];

				int row = wn_tmp->getRow();
				int col = wn_tmp->getCol();

				if (isBlackSquare(wn_tmp->getRow(), wn_tmp->getCol()))
					_board[wn_tmp->getRow()][wn_tmp->getCol()] = BLACK_AREA;
				else
					_board[wn_tmp->getRow()][wn_tmp->getCol()] = WHITE_AREA;

				_board[i][j] = WHITE_KNIGHT;

				wn_tmp->setRow(i);
				wn_tmp->setCol(j);

				if(this->attackBK())
				{
					return true;
				}
				wn_tmp->setRow(row);
				wn_tmp->setCol(col);

				_board[wn_tmp->getRow()][wn_tmp->getCol()] = original;
				_board[i][j] = newPositionContent;
			}


			if (wr_tmp && wr_tmp->validateMove(i, j, _board) && (_board[i][j] == WHITE_AREA || _board[i][j] == BLACK_AREA) )
			{
				char original = _board[wr_tmp->getRow()][wr_tmp->getCol()];
				char newPositionContent = _board[i][j];

				int row = wr_tmp->getRow();
				int col = wr_tmp->getCol();

				if (isBlackSquare(wr_tmp->getRow(), wr_tmp->getCol()))
					_board[wr_tmp->getRow()][wr_tmp->getCol()] = BLACK_AREA;
				else
					_board[wr_tmp->getRow()][wr_tmp->getCol()] = WHITE_AREA;

				_board[i][j] = WHITE_ROOK;

				wr_tmp->setRow(i);
				wr_tmp->setCol(j);

				if(this->attackBK())
				{
					return true;
				}
				wr_tmp->setRow(row);
				wr_tmp->setCol(col);

				_board[wr_tmp->getRow()][wr_tmp->getCol()] = original;
				_board[i][j] = newPositionContent;
			}


			if (wb_tmp && wb_tmp->validateMove(i, j, _board) && (_board[i][j] == WHITE_AREA || _board[i][j] == BLACK_AREA) )
			{
				char original = _board[wb_tmp->getRow()][wb_tmp->getCol()];
				char newPositionContent = _board[i][j];

				int row = wb_tmp->getRow();
				int col = wb_tmp->getCol();

				if (isBlackSquare(wb_tmp->getRow(), wb_tmp->getCol()))
					_board[wb_tmp->getRow()][wb_tmp->getCol()] = BLACK_AREA;
				else
					_board[wb_tmp->getRow()][wb_tmp->getCol()] = WHITE_AREA;

				_board[i][j] = WHITE_BISHOP;

				wb_tmp->setRow(i);
				wb_tmp->setCol(j);

				if(this->attackBK())
				{
					return true;
				}
				wb_tmp->setRow(row);
				wb_tmp->setCol(col);

				_board[wb_tmp->getRow()][wb_tmp->getCol()] = original;
				_board[i][j] = newPositionContent;
			}
		}
	}
	return false;
}

