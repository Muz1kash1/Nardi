#pragma once
#include "field.hpp"
#include <string>
#include "color.h"

extern const int field_amount;

class Board {
	Field play_fields[24]; // наши 24 поля
	int whites_at_home; // белые нарды в доме
	int blacks_at_home; // черные нарды в доме

	int whites_leaved; // белые нарды покинувшие доску
	int blacks_leaved; // черные нарды покинувшие доску


	void increment_cell(int cell, ColorEnum color);
	void decrement_cell(int cell);

public:
	void init();
	std::string checkmove(int cell, int step, ColorEnum moving_color);
	std::string to_check_win();
	void draw_map();
};
