#pragma once
#include "color.h"
#include <string>

class Board;

class Iplayer{
public:
	virtual std::string makeMove(Board& board, int cell, int end_cell) = 0;
	virtual ColorEnum getColor() = 0;
};

