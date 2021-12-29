#pragma once
#include "field.hpp"
#include <string>


extern const int field_amount;

class Board {
	Field play_fields[24];
	int whites_at_home;
	int blacks_at_home;

	int whites_leaved;
	int blacks_leaved;


	void increment_cell(int cell, Field::ColorEnum color);
	void decrement_cell(int cell);

public:
	void init();
	std::string checkmove(int cell, int step, Field::ColorEnum moving_color);
	std::string to_check_win();
	void draw_map();
};
