#pragma once
#include "Iplayer.h"
class BlackPlayer : public Iplayer {
	std::string makeMove(Board& board, int cell, int end_cell);
	ColorEnum getColor();
};

