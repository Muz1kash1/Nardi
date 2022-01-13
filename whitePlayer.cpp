#include "WhitePlayer.h"
#include "board.hpp"

std::string WhitePlayer::makeMove(Board& board, int cell, int end_cell) {
	return board.white_move(end_cell, cell);
}
ColorEnum WhitePlayer::getColor() {
	return White;
}