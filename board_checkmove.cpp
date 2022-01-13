#include "board.hpp"

const int board_size  = 24;
const int figures_amount = 15;

const int white_verge = 24;
const int black_verge = 12;

bool at_black_home(int x) {
	return 6 <= x && x <= 11;
} // в доме ли черна€ нарда

bool at_white_home(int x) {
	return 18 <= x;
} // в доме ли бела€ нарда

std::string Board::checkmove(int cell, int step, ColorEnum moving_color) {
	int end_cell = cell+step;
	ColorEnum color = play_fields[cell].color;
	if (color != moving_color) {
		return "ќшибка: цвет фигур в €чейке не соответствует цвету игрока (или €чейка пуста)";
	}
	switch (color) {
	case ColorEnum{White}:
		if (end_cell >= white_verge) {
			if (whites_at_home != figures_amount) {
				return "ќшибка: выход белых из дома до переноса всех фигур в него";
			}
			else {
				decrement_cell(cell);
				whites_leaved++; // нарда ушла с доски
			}
		}
		else {
			if (play_fields[end_cell].color == ColorEnum{Black}) {
				return "ќшибка: ход белых к черным";
			}
			end_cell %= board_size;
			decrement_cell(cell);
			if (!at_white_home(cell) && at_white_home(end_cell))
				whites_at_home++; // нарда попала в дом
			increment_cell(end_cell, color); // нарда переместилась
		}
		break;
	case ColorEnum{ Black }:
		if (cell < black_verge && end_cell >= black_verge) {
			if (blacks_at_home != figures_amount) {
				return "ќшибка: выход черных из дома до переноса всех фигур в него";
			}
			else {
				decrement_cell(cell);
				blacks_leaved++; // нарда ушла с доски
			}
		}
		else {
			if (play_fields[end_cell].color == ColorEnum{White}) {
				return "ќшибка: ход черных к белым";
			}
			end_cell %= board_size;
			decrement_cell(cell);
			if (!at_black_home(cell) && at_black_home(end_cell))
				blacks_at_home++; // нарда попала в дом
			increment_cell(end_cell, color); // нарда переместилась
		}
		break;
	}
	return "";
}