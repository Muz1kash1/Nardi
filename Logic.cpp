#include "Logic.h"

void Make_move(list& current_pos, int movestep, Fishka* fi, Player turn) {
	
	
	list* temp_p = current_pos.ptr;
	if (check_if_can_move_to_cell(turn, temp_p) != false)
	{
		current_pos.field.delete_fishka();
		for (size_t i = 0; i < movestep - 1; i++)
		{
			MovePtr(temp_p);
		}
		temp_p->field.add_fishka(fi);
	}

	

}
bool check_if_can_move_to_cell(Player turn, list* estimated_cell) {
	for (size_t i = 0; i < estimated_cell->field.get_fishki().size(); i++)
	{
		if (estimated_cell->field.get_fishki()[i]->color != turn.color) {
			return false;
		}
		else
			return true;
	}

}

void draw_board(Board* ourboard) {
	char* draw_mas[12][15];
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 12; j++)
		{

		}
	}
}