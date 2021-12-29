#include "board.hpp"

void Board::increment_cell(int cell, Field::ColorEnum color) {
	if(play_fields[cell].amount++ == 0)
		play_fields[cell].color = color;
}
void Board::decrement_cell(int cell) {
	if(--play_fields[cell].amount == 0)
		play_fields[cell].color = Field::None;
}