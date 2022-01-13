#include "board.hpp"
#include "Nard_factory.h"
const int field_amount = 24;

const int white_start = 0; // голова белых
const int black_start = 12; // голова  черных
const int start_amount = 15; // количество нард на старте у каждого игрока

void Board::init() {
	Nard_factory nard_factory;
	whites_at_home = 0;
	blacks_at_home = 0;
	play_fields[white_start].Nards_in_field.resize(15);
	play_fields[black_start].Nards_in_field.resize(15);
	whites_leaved = 0;
	blacks_leaved = 0;

	for (int i = 0; i < start_amount; i++) {
		play_fields[white_start].Nards_in_field[i] = nard_factory.create_nard(White);
		play_fields[black_start].Nards_in_field[i] = nard_factory.create_nard(Black);
	}
} // инициализация доски
