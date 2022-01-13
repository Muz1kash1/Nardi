#include "board.hpp"

#include"Nard_factory.h"

void Board::increment_cell(int cell, ColorEnum color) {
	Nard_factory temp_factory;
		play_fields[cell].Nards_in_field.push_back(temp_factory.create_nard(color));	
} // увеличить количество нард в €чейке

void Board::decrement_cell(int cell) {
	if (play_fields[cell].Nards_in_field.size() != 0) {
			play_fields[cell].Nards_in_field.pop_back();
		}
		
} 