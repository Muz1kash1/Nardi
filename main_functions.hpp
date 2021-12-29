#pragma once
#include "board.hpp"


int roll_cube();
void print_annotation(int* cubes, Field::ColorEnum current_turn);
std::string make_step(int cube, Field::ColorEnum current_turn, Board& board);
void simple_step(Board& board, int* cubes, Field::ColorEnum current_turn, std::string& winner);
void double_cubes_step(Board& board, int* cubes, Field::ColorEnum current_turn, std::string& winner);
Field::ColorEnum flip_turn(Field::ColorEnum current);