#include "board.hpp"

const int board_size  = 24;
const int figures_amount = 15;

const int white_verge = 24;
const int black_verge = 12;

bool at_black_home(int x) {
	return 6 <= x && x <= 11;
}

bool at_white_home(int x) {
	return 18 <= x;
}

std::string Board::checkmove(int cell, int step, Field::ColorEnum moving_color) {
	int end_cell = cell+step;
	Field::ColorEnum color = play_fields[cell].color;
	if (color != moving_color) {
		return "ќшибка: цвет фигур в €чейке не соответствует цвету игрока (или €чейка пуста)";
	}
	switch (color) {
	case Field::White:
		if (end_cell >= white_verge) {
			if (whites_at_home != figures_amount) {
				return "ќшибка: выход белых из дома до переноса всех фигур в него";
			}
			else {
				decrement_cell(cell);
				whites_leaved++;
			}
		}
		else {
			if (play_fields[end_cell].color == Field::Black) {
				return "ќшибка: ход белых к черным";
			}
			end_cell %= board_size;
			decrement_cell(cell);
			if (!at_white_home(cell) && at_white_home(end_cell))
				whites_at_home++;
			increment_cell(end_cell, color);
		}
		break;
	case Field::Black:
		if (cell < black_verge && end_cell >= black_verge) {
			if (blacks_at_home != figures_amount) {
				return "ќшибка: выход чЄрных из дома до переноса всех фигур в него";
			}
			else {
				decrement_cell(cell);
				blacks_leaved++;
			}
		}
		else {
			if (play_fields[end_cell].color == Field::White) {
				return "ќшибка: ход черных к белым";
			}
			end_cell %= board_size;
			decrement_cell(cell);
			if (!at_black_home(cell) && at_black_home(end_cell))
				blacks_at_home++;
			increment_cell(end_cell, color);
		}
		break;
	}
	return "";
}