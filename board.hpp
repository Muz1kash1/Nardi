#pragma once
#include "field.hpp"
#include <string>
#include "color.h"
#include "homes.h"
#include "leaved.h"
#include "Iplayer.h"
extern const int field_amount;

class Board{
	Field play_fields[24]; // наши 24 поля
	Homes homes;
	Leaved leaved;

	void increment_cell(int cell, ColorEnum color);
	void decrement_cell(int cell);

public:
	void init();

	std::string white_move(int end_cell, int cell);
	std::string black_move(int end_cell, int cell);

	std::string checkmove(int cell, int step, Iplayer* player);
	std::string to_check_win();
	void draw_map();
};
