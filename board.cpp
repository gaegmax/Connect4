#include "board.h"

Board::Board() {
}

Board::Board(const string &fen) {
}

void Board::printBoard_as_FENstring(ostream &os) const {
}

void Board::prettyPrintBoard(ostream &os) const {
	os << endl;
    for (int row = NUM_ROWS - 1; row >= 0; row--)  {
        os << "     +---+---+---+---+---+---+---+"
           << endl
           << "    ";
        
        for (int col = 0; col < NUM_COLS; col++)   {
            os << " | " ;
            if ( data[row][col] == Player1)
                os <<  PLAYER1_TOKEN;
            else if (data[row][col] == Player2)
                os << PLAYER2_TOKEN;
            else
                os << EMPTY_TOKEN;
        }
        os << " |" << endl;
    }
    os << "     +---+---+---+---+---+---+---+" << endl
       <<"  col  1   2   3   4   5   6   7" << endl;
    return;
}

int Board::toMove() const {
    return 1;
}

Result Board::makeMove(int col) {
    return NoResult;
}

int Board::getFirstFreeRow(int col) const {
    return NUM_ROWS;
}

PieceType Board::updateToMove() {
    return Player1;
}

bool Board::isBoardFull() const {
    return false;
}

bool Board::inBounds(int row, int col) const {
    return false;
}

int Board::piecesInDirection(int row, int col, int dRow, int dCol) const {
	int count = 0;
    
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            
            // Check Player 1
            if (data[row][col] == Player1) {
                
                // Check vertical
                if (((data[row + abs(dRow)][col] == Player1) && inBounds(row + 1, col))) {
                    if ((data[row + abs(dRow) + 1][col] == Player1) && inBounds(row + 2, col)){
                        if ((data[row + abs(dRow) + 2][col] == Player1) && inBounds(row + 3, col)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                
                // Check right horizontal
                if (((data[row][col + abs(dCol)] == Player1) && inBounds(row, col + 1))) {
                    if ((data[row][col + abs(dCol) + 1] == Player1) && inBounds(row, col + 2)){
                        if ((data[row][col + abs(dCol) + 2] == Player1) && inBounds(row, col + 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check left horizontal
                if (((data[row][col - abs(dCol)] == Player1) && inBounds(row, col - 1))) {
                    if ((data[row][col - abs(dCol) - 1] == Player1) && inBounds(row, abs(col) - 2)){
                        if ((data[row][col - abs(dCol) - 2] == Player1) && inBounds(row, col - 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check middle horizontal
                if (((data[row][col - abs(dCol)] == Player1) && (data[row][col + abs(dCol)] == Player1) && inBounds(row, col - 1) && inBounds(row, col +1))) {
                    if (((data[row][col - abs(dCol) - 1] == Player1) && inBounds(row, col - 2)) || ((data[row][col + abs(dCol) + 1] == Player1) && (inBounds(row, col + abs(dCol) + 1)))) {
                            count = 3;
                            return count;
                    }
                }
                // Check right diagonal up
                if (((data[row - abs(dRow)][col + abs(dCol)] == Player1) && inBounds(row - 1, col + 1))) {
                    if ((data[row - abs(dRow) - 1][col + abs(dCol) + 1] == Player1) && inBounds(row - 2, col + 2)){
                        if ((data[row - abs(dRow) - 2][col + abs(dCol) + 2] == Player1) && inBounds(row - 3, col + 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check right diagonal down
                if (((data[row + abs(dRow)][col - abs(dCol)] == Player1) && inBounds(row + 1, col - 1))) {
                    if ((data[row + abs(dRow) + 1][col - abs(dCol) - 1] == Player1) && inBounds(row + 2, col - 2)){
                        if ((data[row + abs(dRow) + 2][col - abs(dCol) - 2] == Player1) && inBounds(row + 3, col - 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check right diagonal middle
                if (((data[row - abs(dRow)][col + abs(dCol)] == Player1) && (data[row + abs(dRow)][col - abs(dCol)] == Player1) && inBounds(row - 1, col + 1) && inBounds(row + 1, col - 1))) {
                    if (((data[row - abs(dRow) - 1][col + abs(dCol) + 1] == Player1) && inBounds(row - 2, col + 2)) || ((data[row + abs(dRow) + 1][col - abs(dCol) - 1] == Player1) && (inBounds(row + 2, col - 2)))) {
                        count = 3;
                        return count;
                    }
                }
                // Check left diagonal up
                if (((data[row - abs(dRow)][col - abs(dCol)] == Player1) && inBounds(row - 1, col - 1))) {
                    if ((data[row - abs(dRow) - 1][col - abs(dCol) - 1] == Player1) && inBounds(row - 2, col - 2)){
                        if ((data[row - abs(dRow) - 2][col - abs(dCol) - 2] == Player1) && inBounds(row - 3, col - 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check left diagonal down
                if (((data[row + abs(dRow)][col + abs(dCol)] == Player1) && inBounds(row + 1, col + 1))) {
                    if ((data[row + abs(dRow) + 1][col + abs(dCol) + 1] == Player1) && inBounds(row + 2, col + 2)){
                        if ((data[row + abs(dRow) + 2][col + abs(dCol) + 2] == Player1) && inBounds(row + 3, col + 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }

                // Check left diagonal middle
                if (((data[row - abs(dRow)][col - abs(dCol)] == Player1) && (data[row + abs(dRow)][col + abs(dCol)] == Player1) && inBounds(row - 1, col - 1) && inBounds(row + 1, col +1))) {
                    if (((data[row - abs(dRow) - 1][col - abs(dCol) - 1] == Player1) && inBounds(row - 2, col - 2)) || ((data[row + abs(dRow) + 1][col + abs(dCol) + 1] == Player1) && (inBounds(row + 2, col + 2)))) {
                        count = 3;
                        return count;
                    }
                }
            }
            // Check Player 2
            if (data[row][col] == Player2) {
                
                // Check vertical
                if (((data[row + abs(dRow)][col] == Player2) && inBounds(row + 1, col))) {
                    if ((data[row + abs(dRow) + 1][col] == Player2) && inBounds(row + 2, col)){
                        if ((data[row + abs(dRow) + 2][col] == Player2) && inBounds(row + 3, col)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                
                // Check right horizontal
                if (((data[row][col + abs(dCol)] == Player2) && inBounds(row, col + 1))) {
                    if ((data[row][col + abs(dCol) + 1] == Player2) && inBounds(row, col + 2)){
                        if ((data[row][col + abs(dCol) + 2] == Player2) && inBounds(row, col + 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check left horizontal
                if (((data[row][col - abs(dCol)] == Player2) && inBounds(row, col - 1))) {
                    if ((data[row][col - abs(dCol) - 1] == Player2) && inBounds(row, abs(col) - 2)){
                        if ((data[row][col - abs(dCol) - 2] == Player2) && inBounds(row, col - 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check middle horizontal
                if (((data[row][col - abs(dCol)] == Player2) && (data[row][col + abs(dCol)] == Player2) && inBounds(row, col - 1) && inBounds(row, col +1))) {
                    if (((data[row][col - abs(dCol) - 1] == Player2) && inBounds(row, col - 2)) || ((data[row][col + abs(dCol) + 1] == Player2) && (inBounds(row, col + abs(dCol) + 1)))) {
                        count = 3;
                        return count;
                    }
                }
                // Check right diagonal up
                if (((data[row - abs(dRow)][col + abs(dCol)] == Player2) && inBounds(row - 1, col + 1))) {
                    if ((data[row - abs(dRow) - 1][col + abs(dCol) + 1] == Player2) && inBounds(row - 2, col + 2)){
                        if ((data[row - abs(dRow) - 2][col + abs(dCol) + 2] == Player2) && inBounds(row - 3, col + 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check right diagonal down
                if (((data[row + abs(dRow)][col - abs(dCol)] == Player2) && inBounds(row + 1, col - 1))) {
                    if ((data[row + abs(dRow) + 1][col - abs(dCol) - 1] == Player2) && inBounds(row + 2, col - 2)){
                        if ((data[row + abs(dRow) + 2][col - abs(dCol) - 2] == Player2) && inBounds(row + 3, col - 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check right diagonal middle
                if (((data[row - abs(dRow)][col + abs(dCol)] == Player2) && (data[row + abs(dRow)][col - abs(dCol)] == Player2) && inBounds(row - 1, col + 1) && inBounds(row + 1, col - 1))) {
                    if (((data[row - abs(dRow) - 1][col + abs(dCol) + 1] == Player2) && inBounds(row - 2, col + 2)) || ((data[row + abs(dRow) + 1][col - abs(dCol) - 1] == Player2) && (inBounds(row + 2, col - 2)))) {
                        count = 3;
                        return count;
                    }
                }
                // Check left diagonal up
                if (((data[row - abs(dRow)][col - abs(dCol)] == Player1) && inBounds(row - 1, col - 1))) {
                    if ((data[row - abs(dRow) - 1][col - abs(dCol) - 1] == Player2) && inBounds(row - 2, col - 2)){
                        if ((data[row - abs(dRow) - 2][col - abs(dCol) - 2] == Player2) && inBounds(row - 3, col - 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                // Check left diagonal down
                if (((data[row + abs(dRow)][col + abs(dCol)] == Player2) && inBounds(row + 1, col + 1))) {
                    if ((data[row + abs(dRow) + 1][col + abs(dCol) + 1] == Player2) && inBounds(row + 2, col + 2)){
                        if ((data[row + abs(dRow) + 2][col + abs(dCol) + 2] == Player2) && inBounds(row + 3, col + 3)) {
                            count = 3;
                            return count;
                        }
                    }
                }
                
                // Check left diagonal middle
                if (((data[row - abs(dRow)][col - abs(dCol)] == Player2) && (data[row + abs(dRow)][col + abs(dCol)] == Player2) && inBounds(row - 1, col - 1) && inBounds(row + 1, col +1))) {
                    if (((data[row - abs(dRow) - 1][col - abs(dCol) - 1] == Player2) && inBounds(row - 2, col - 2)) || ((data[row + abs(dRow) + 1][col + abs(dCol) + 1] == Player2) && (inBounds(row + 2, col + 2)))) {
                        count = 3;
                        return count;
                    }
                }
            }
        }
    }
    return 0;
}

}

bool Board::isWin(int row, int col) const {
    return false;
}
