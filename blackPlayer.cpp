#include "BlackPlayer.h"
#include "board.hpp"

std::string BlackPlayer::makeMove(Board& board, int cell, int end_cell){
	return board.black_move(end_cell, cell);
}
ColorEnum BlackPlayer::getColor(){
	return Black;
}