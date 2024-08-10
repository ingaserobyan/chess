#include "knight.hpp"

#include <vector>
#include <string>

typedef std::vector<std::string> td_matrix;

Knight::Knight() : Piece(D_WHITE, 7, 1) {}

Knight::Knight(bool color, int row, int col) : Piece(color, row, col) {}

Knight::~Knight() {}

bool Knight::validateMove(int row, int col, const td_matrix& board) const
{
    int rowDiffs[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int colDiffs[] = {1, -1, 1, -1, 2, -2, 2, -2};

    for (int i = 0; i < 8; ++i) {
        if ((_row - row) == rowDiffs[i] && (_col - col) == colDiffs[i])
            return true;
    }
    return false;
}
