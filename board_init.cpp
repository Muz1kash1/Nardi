#include "board.hpp"

const int field_amount = 24;

const int white_start = 0;
const int black_start = 12;
const int start_amount = 15;

void Board::init() {
	for (int i = 0; i < field_amount; i++)
		play_fields[i] = {0, Field::None};
	whites_at_home = 0;
	blacks_at_home = 0;

	whites_leaved = 0;
	blacks_leaved = 0;

	play_fields[white_start] = {start_amount, Field::White};
	play_fields[black_start] = {start_amount, Field::Black};
}
